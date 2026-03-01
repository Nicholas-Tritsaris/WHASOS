# WHAOS User-Space and Security

## Process Model

- **init (PID 1)**: whad (WHAOS Daemon Manager)
- Unix-style process hierarchy: init → getty → login → shell → X/Wayland → desktop
- Signals: SIGHUP, SIGINT, SIGTERM, SIGKILL as per POSIX

## Users and Groups

### Default users

| User    | UID | GID | Home      | Shell      |
|---------|-----|-----|-----------|------------|
| root    | 0   | 0   | /root     | /bin/bash  |
| whauser | 1000| 1000| /home/whauser | /bin/bash |

### Default groups

| Group   | GID | Members   |
|---------|-----|-----------|
| root    | 0   | root      |
| wheel   | 10  | root      |
| users   | 100 | whauser   |
| audio   | 29  | whauser   |
| video   | 44  | whauser   |

### passwd example

```
root:x:0:0:root:/root:/bin/bash
whauser:x:1000:1000:WHAOS User:/home/whauser:/bin/bash
```

### group example

```
root:x:0:
wheel:x:10:root
users:x:100:whauser
audio:x:29:whauser
video:x:44:whauser
```

## Permissions

- Standard Unix: rwxrwxrwx (owner, group, others)
- setuid/setgid for privileged binaries (passwd, ping, etc.)
- Optional: POSIX ACLs, capabilities for fine-grained control

## Service System (whad)

- Script-based: `/etc/whad/rc.conf`
- Services: udev/mdev, dbus, X11/Wayland, display manager, desktop
- Order: fs → networking → dbus → X → display-manager → desktop
