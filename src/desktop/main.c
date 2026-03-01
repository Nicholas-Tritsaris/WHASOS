/*
 * WHAOS Panel - Standalone entry point
 * Creates taskbar window for WHAOS Desktop
 * Keyboard: Super key opens Start menu
 * Mouse: full support via GTK
 * Requires: GTK3
 * GPL-2.0
 */

#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>

/* Forward declare - implemented in whaos_panel.c */
extern GtkWidget *whaos_panel_create(void);
extern void whaos_panel_toggle_start_menu(void);

static void on_window_destroy(GtkWidget *w, gpointer data) {
    (void)w;
    (void)data;
    gtk_main_quit();
}

static gboolean on_key_press(GtkWidget *w, GdkEventKey *ev, gpointer data) {
    (void)w;
    (void)data;
    /* Super/Win key opens Start menu (GDK_Super_L = 0xFFEB, GDK_Super_R = 0xFFEC) */
    if (ev->keyval == GDK_KEY_Super_L || ev->keyval == GDK_KEY_Super_R) {
        whaos_panel_toggle_start_menu();
        return TRUE; /* handled */
    }
    return FALSE;
}

int main(int argc, char **argv) {
    GtkWidget *window;
    GtkWidget *panel;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "WHAOS Panel");
    gtk_window_set_default_size(GTK_WINDOW(window), 1024, 32);
    gtk_window_set_resizable(GTK_WINDOW(window), TRUE);
    gtk_window_set_decorated(GTK_WINDOW(window), FALSE);
    gtk_window_move(GTK_WINDOW(window), 0, 0);
    g_signal_connect(window, "destroy", G_CALLBACK(on_window_destroy), NULL);

    /* Keyboard: Super key opens Start menu */
    gtk_widget_add_events(window, GDK_KEY_PRESS_MASK | GDK_KEY_RELEASE_MASK);
    g_signal_connect(window, "key-press-event", G_CALLBACK(on_key_press), NULL);
    gtk_widget_set_can_focus(window, TRUE);

    panel = whaos_panel_create();
    gtk_container_add(GTK_CONTAINER(window), panel);

    gtk_widget_show_all(window);
    gtk_widget_grab_focus(window);

    gtk_main();
    return 0;
}
