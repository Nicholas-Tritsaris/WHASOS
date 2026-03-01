# WHAOS Architecture Document

## Overview

**WHAOS** is a 64-bit operating system for x86-64 (AMD64), designed to run in VirtualBox with a Windows 7–like desktop experience. It uses original branding, icons, fonts, and assets—no proprietary Windows code or assets.

---

## 1. Boot and Kernel Architecture

### 1.1 Boot Process Flow

```
[BIOS/UEFI] → [Boot Sector / EFI Bootloader] → [GRUB2] → [WHAOS Kernel] → [init/whad]
```

### 1.2 Bootloader Choice: GRUB2

- **GRUB2** is used for both BIOS and UEFI modes
- Loads the WHAOS kernel (`vmlinuz-whacos`) and initramfs
- Passes kernel command line (root device, init path, etc.)

### 1.3 Kernel Architecture: Hybrid Monolithic

| Layer       | Components                                              |
|------------|----------------------------------------------------------|
| **Process**| Scheduler, fork/exec, signals, namespaces                |
| **Memory** | Virtual memory, paging, mmap, OOM killer                 |
| **IPC**    | Pipes, FIFOs, sockets, shared memory                     |
| **Drivers**| Storage (IDE/AHCI), VGA/VMSVGA, PS/2, Intel PRO/1000    |
| **FS**     | VFS, ext4, tmpfs, procfs, sysfs                          |
| **Syscall**| Linux-compatible syscall table (for toolchain reuse)     |

**Kernel approach**: Use Linux kernel as base (GPL) and customize for WHAOS branding, or build a minimal kernel (e.g., custom or based on ToaruOS/SerenityOS concepts). For fastest path: **Linux kernel with WHAOS userland**.

### 1.4 System Call Interface

For portability and toolchain compatibility, WHAOS targets a **Linux ABI subset**:

- File I/O: open, read, write, close, mmap
- Process: fork, execve, waitpid, exit
- Memory: brk, mmap, munmap
- IPC: pipe, socket
- Signals: kill, sigaction

---

## 2. Driver Model (VirtualBox-Oriented)

### 2.1 Supported VirtualBox Devices

| Device           | Driver Type | Notes                    |
|------------------|-------------|--------------------------|
| Storage          | IDE, AHCI   | SATA via ahci driver     |
| Graphics         | VMSVGA      | VBox VMSVGA display      |
| Input            | PS/2        | Keyboard + mouse         |
| Network          | Intel 82540EM (e1000) | VirtIO-Net optional |
| USB              | OHCI/EHCI   | Optional, later phase    |

### 2.2 Driver Loading

- Kernel modules (if using Linux): `modprobe e1000`, `modprobe vboxguest` (optional)
- WHAOS driver registry: drivers register with `/sys/bus/` or equivalent

---

## 3. File System and Storage

### 3.1 Root Filesystem Choice: **ext4**

- Well-supported by Linux
- Journaling, large file support, good performance
- Tools: `mkfs.ext4`, `e2fsprogs`

### 3.2 Partition Layout (VirtualBox Disk)

```
/dev/sda1  - EFI System Partition (FAT32, 512 MiB) - optional for UEFI
/dev/sda2  - WHAOS root (ext4, rest of disk)
```

### 3.3 Root Filesystem Layout

```
/
├── bin/           # Essential user binaries
├── boot/          # Kernel, initramfs, GRUB
├── dev/           # Device nodes
├── etc/           # Configuration
│   ├── whaos/     # WHAOS-specific config
│   ├── X11/       # X config
│   └── ...
├── home/          # User home directories
├── lib/           # Shared libraries
├── lib64/         # 64-bit libs
├── mnt/           # Mount points
├── opt/           # Optional software
├── proc/          # procfs
├── root/          # root home
├── run/           # Runtime data
├── sbin/          # System binaries
├── srv/           # Service data
├── sys/           # sysfs
├── tmp/           # Temporary files
├── usr/           # User software
│   ├── bin/
│   ├── lib/
│   ├── share/
│   └── ...
└── var/           # Variable data
    ├── log/
    └── ...
```

---

## 4. User-Space and Security

### 4.1 Process Model

- **init**: `whad` (WHAOS Daemon Manager) or systemd/sysvinit-style
- Processes: Unix-style PID, UID, GID
- Session: login → shell → desktop session

### 4.2 Users and Groups

- `root` (UID 0), `whauser` (UID 1000), etc.
- Groups: `root`, `users`, `wheel`, `audio`, `video`

### 4.3 Permissions

- Unix permissions: rwxrwxrwx
- Optional: POSIX ACLs, capability-based security

### 4.4 Service System

- **whad**: WHAOS init/daemon manager
- Starts: udev, dbus, X11/Wayland, display manager, desktop

---

## 5. Graphical User Interface (WHAOS Desktop)

### 5.1 Stack

| Layer       | Technology                         |
|------------|-------------------------------------|
| Display    | X11 (Xorg) or Wayland              |
| Compositor | picom (X11) or Weston (Wayland)    |
| Desktop    | WHAOS Desktop Environment (custom) |
| Toolkit    | GTK3/4 or Qt5 (for apps)           |

### 5.2 WHAOS Desktop Environment

- **WHAOS Start Menu**: Left-corner button, Super key, programs list, shutdown/restart
- **WHAOS Taskbar**: Bottom bar, task buttons, system tray
- **WHAOS System Tray**: Clock, volume, network, notifications
- **WHAOS Window Decorations**: Title bar, minimize/maximize/close, glass-like theme

### 5.3 Theme (Windows 7–Inspired, Original)

- Glass-like transparency (Aero-style, using compositor)
- Soft gradients, rounded corners
- Color palette: WHAOS blue accent (#0078D4), dark taskbar
- Original icons and fonts (e.g., Fira Sans, Noto Sans)

---

## 6. Core WHAOS Applications

| App               | Purpose                    | Tech          |
|-------------------|----------------------------|---------------|
| WHAOS File Explorer | File manager             | GTK/PCManFM   |
| WHAOS Control Center | Settings, appearance   | GTK           |
| WHAOS Text Editor | Plain text editing        | gedit/Geany   |
| WHAOS Terminal    | CLI shell                  | GNOME Terminal/lxterminal |
| WHAOS Task Monitor| Process viewer             | GNOME System Monitor |

---

## 7. Installer Flow

1. **Language & Keyboard** – Select language, keyboard layout
2. **Disk Partitioning** – Create/extend partitions, format ext4
3. **User Account** – Username, password, hostname
4. **Time Zone & Clock** – Region, NTP
5. **Install** – Copy files, configure GRUB, write MBR/GPT
6. **Reboot** – Eject ISO, boot from disk

---

## 8. ISO Build Pipeline

- Build host: **Ubuntu 24.04 LTS** (or similar)
- Tools: `debootstrap`, `xorriso`, `grub-pc`, `grub-efi-amd64`
- Output: `whacos-1.0-amd64.iso`

---

## 9. VirtualBox Configuration

- Type: **Linux 2.6 / 3.x / 4.x / 5.x 64-bit**
- RAM: 2048 MB minimum
- Disk: 20 GB VDI
- Network: NAT or Bridged
- Display: VMSVGA, 128 MB VRAM
- Enable EFI if using UEFI boot
