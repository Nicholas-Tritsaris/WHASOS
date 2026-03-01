/*
 * WHAOS Daemon Manager (whad)
 * PID 1 init process - spawns essential services and user sessions
 * GPL-2.0
 */

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/reboot.h>
#include <string.h>

#define WHAOS_VERSION "1.0"
#define INIT_SCRIPT "/etc/whad/rc.conf"

/* Run a command; returns PID or -1 on error */
static pid_t spawn(const char *path, char *const argv[]) {
    pid_t pid = fork();
    if (pid < 0) return -1;
    if (pid == 0) {
        execv(path, argv);
        _exit(127);
    }
    return pid;
}

/* Run shell command */
static int run(const char *cmd) {
    int st;
    pid_t p = fork();
    if (p < 0) return -1;
    if (p == 0) {
        execl("/bin/sh", "sh", "-c", cmd, NULL);
        _exit(127);
    }
    waitpid(p, &st, 0);
    return WIFEXITED(st) ? WEXITSTATUS(st) : -1;
}

static void reap_children(void) {
    while (waitpid(-1, NULL, WNOHANG) > 0) ;
}

int main(int argc, char **argv) {
    printf("[whad] WHAOS Daemon Manager v%s starting\n", WHAOS_VERSION);

    /* Basic setup */
    run("mount -t proc none /proc");
    run("mount -t sysfs none /sys");
    run("mount -t devtmpfs none /dev");
    run("mkdir -p /dev/pts");
    run("mount -t devpts none /dev/pts");

    /* udev or mdev */
    run("mdev -s 2>/dev/null || udevd --daemon");

    signal(SIGCHLD, (void (*)(int))reap_children);

    /* Run init script if present */
    if (access(INIT_SCRIPT, R_OK) == 0) {
        run(INIT_SCRIPT);
    } else {
        /* Minimal defaults */
        run("hostname whaos");
        run("ifconfig lo 127.0.0.1 up");
    }

    /* Start getty for console */
    spawn("/sbin/getty", (char *const[]){ "getty", "-n", "-l", "/bin/login",
        "tty1", "linux", NULL });

    /* Reap zombies and handle poweroff/reboot */
    for (;;) {
        pid_t p = wait(NULL);
        if (p < 0) continue;
        /* Optional: handle init requests via /dev/initctl */
    }
}
