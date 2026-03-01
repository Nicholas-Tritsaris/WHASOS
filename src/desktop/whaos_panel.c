/*
 * WHAOS Panel - Taskbar with Start Menu, task buttons, system tray
 * Windows 7-inspired layout, original WHAOS branding
 * Keyboard: Super key opens Start menu
 * Mouse: left/right click, hover on Start button and tray
 * Requires: GTK3
 * GPL-2.0
 */

#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <gdk/gdkkeysyms.h>
#include <string.h>
#include <time.h>

#define PANEL_HEIGHT 32
#define START_BUTTON_WIDTH 80
#define WHAOS_ACCENT "#0078D4"
#define PANEL_BG "rgba(40, 44, 52, 0.85)"

static GtkWidget *clock_label;     /* Event box (container) */
static GtkWidget *clock_label_text; /* Actual label for update_clock */
static GtkWidget *start_button;
static GtkWidget *start_popover;

static void update_clock(gpointer data) {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char buf[64];
    strftime(buf, sizeof(buf), "%H:%M  %a %d %b", tm);
    if (clock_label_text)
        gtk_label_set_text(GTK_LABEL(clock_label_text), buf);
}

static void on_start_clicked(GtkButton *btn, gpointer data) {
    (void)btn;
    (void)data;
    if (start_popover && gtk_widget_get_visible(start_popover))
        gtk_popover_popdown(GTK_POPOVER(start_popover));
    else if (start_popover)
        gtk_popover_popup(GTK_POPOVER(start_popover));
}

static void on_menu_item_activated(GtkWidget *item, gpointer label) {
    (void)item;
    g_print("Launch: %s\n", (const char *)label);
    if (start_popover)
        gtk_popover_popdown(GTK_POPOVER(start_popover));
}

static void on_clock_button_press(GtkWidget *w, GdkEventButton *ev, gpointer data) {
    (void)w;
    (void)data;
    if (ev->button == GDK_BUTTON_SECONDARY && ev->type == GDK_BUTTON_PRESS) {
        GtkWidget *menu = gtk_menu_new();
        GtkWidget *mi = gtk_menu_item_new_with_label("Adjust date/time...");
        g_signal_connect(mi, "activate", G_CALLBACK(on_menu_item_activated), (gpointer)"date-time");
        gtk_menu_shell_append(GTK_MENU_SHELL(menu), mi);
        gtk_widget_show_all(menu);
        gtk_menu_popup_at_pointer(GTK_MENU(menu), (GdkEvent *)ev);
    }
}

/* Public: toggle Start menu (called from main on Super key) */
void whaos_panel_toggle_start_menu(void) {
    if (!start_popover) return;
    if (gtk_widget_get_visible(start_popover))
        gtk_popover_popdown(GTK_POPOVER(start_popover));
    else
        gtk_popover_popup(GTK_POPOVER(start_popover));
}

static void on_shutdown_clicked(GtkButton *btn, gpointer data) {
    (void)btn;
    (void)data;
    /* TODO: show shutdown/restart dialog */
    g_print("WHAOS Shutdown\n");
}

GtkWidget *whaos_panel_create(void) {
    GtkWidget *panel, *hbox, *separator;
    GtkCssProvider *css;
    GError *err = NULL;

    panel = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_widget_set_size_request(panel, -1, PANEL_HEIGHT);
    gtk_widget_set_halign(panel, GTK_ALIGN_FILL);
    gtk_widget_set_hexpand(panel, TRUE);

    /* Panel styling - glass-like, dark */
    css = gtk_css_provider_new();
    gtk_css_provider_load_from_data(css,
        "panel { background: " PANEL_BG "; border-top: 1px solid rgba(255,255,255,0.1); }"
        "start-btn { background: " WHAOS_ACCENT "; color: white; border-radius: 0; }"
        "start-btn:hover { background: #1084D8; }",
        -1, &err);
    if (err) {
        g_warning("CSS load: %s", err->message);
        g_clear_error(&err);
    }
    gtk_style_context_add_provider_for_screen(gdk_screen_get_default(),
        GTK_STYLE_PROVIDER(css), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

    /* Start button - mouse click, hover support via GTK defaults */
    start_button = gtk_button_new_with_label("WHAOS");
    gtk_widget_set_size_request(start_button, START_BUTTON_WIDTH, -1);
    gtk_widget_set_halign(start_button, GTK_ALIGN_START);
    gtk_widget_add_events(start_button, GDK_BUTTON_PRESS_MASK | GDK_BUTTON_RELEASE_MASK | GDK_ENTER_NOTIFY_MASK | GDK_LEAVE_NOTIFY_MASK);
    g_signal_connect(start_button, "clicked", G_CALLBACK(on_start_clicked), NULL);
    gtk_box_pack_start(GTK_BOX(panel), start_button, FALSE, FALSE, 0);

    /* Start menu popover */
    start_popover = gtk_popover_new(start_button);
    GtkWidget *menu_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 4);
    gtk_container_set_border_width(GTK_CONTAINER(menu_box), 8);
    const char *entries[] = { "WHAOS File Explorer", "WHAOS Terminal", "WHAOS Text Editor", "WHAOS Control Center", "WHAOS Task Monitor", NULL };
    int i;
    for (i = 0; entries[i]; i++) {
        GtkWidget *btn = gtk_button_new_with_label(entries[i]);
        gtk_widget_set_halign(btn, GTK_ALIGN_FILL);
        g_signal_connect(btn, "clicked", G_CALLBACK(on_menu_item_activated), (gpointer)entries[i]);
        gtk_container_add(GTK_CONTAINER(menu_box), btn);
    }
    gtk_container_add(GTK_CONTAINER(start_popover), menu_box);

    separator = gtk_separator_new(GTK_ORIENTATION_VERTICAL);
    gtk_box_pack_start(GTK_BOX(panel), separator, FALSE, FALSE, 2);

    /* Task area - placeholder, populated by window manager */
    hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 4);
    gtk_box_pack_start(GTK_BOX(panel), hbox, TRUE, TRUE, 4);

    /* Spacer */
    gtk_box_pack_start(GTK_BOX(panel), gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0), TRUE, TRUE, 0);

    /* System tray - clock with right-click context menu */
    clock_label = gtk_event_box_new();
    clock_label_text = gtk_label_new("");
    gtk_label_set_markup(GTK_LABEL(clock_label_text), "<span foreground='white'>00:00  Mon 01 Jan</span>");
    gtk_container_add(GTK_CONTAINER(clock_label), clock_label_text);
    gtk_widget_add_events(clock_label, GDK_BUTTON_PRESS_MASK | GDK_BUTTON_RELEASE_MASK);
    g_signal_connect(clock_label, "button-press-event", G_CALLBACK(on_clock_button_press), NULL);
    gtk_box_pack_end(GTK_BOX(panel), clock_label, FALSE, FALSE, 8);

    /* Tray icons would go here */
    update_clock(NULL);
    g_timeout_add_seconds(1, (GSourceFunc)update_clock, NULL);

    return panel;
}
