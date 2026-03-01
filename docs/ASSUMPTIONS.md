# WHAOS Assumptions

## Build Environment

- **Build host**: Ubuntu 24.04 LTS (or Debian 12, Fedora 40)
- **Architecture**: x86-64 only (no ARM/other)
- **Toolchain**: gcc 12+, binutils, GNU Make, CMake 3.20+
- **Root/sudo**: Required for chroot, loop mounts, ISO creation

## Implementation Approach

1. **Path A (Faster)**: Use Linux kernel + minimal userspace (BusyBox, Alpine/musl) + X11 + custom WHAOS desktop. ISO built with live-build or debootstrap.

2. **Path B (From scratch)**: Custom kernel (ToaruOS, SerenityOS, or new) + custom userspace. Significantly more effort.

For this spec, **Path A** is assumed unless otherwise noted.

## VirtualBox

- VirtualBox 7.x (or 6.1+)
- Guest Additions optional but recommended
- No VMware/other hypervisor in scope for v1

## Legal

- All code: GPL-2/3, MIT, or BSD
- All assets: CC0, MIT, or original
- No Windows trademarks, icons, or code

## Network

- Basic networking: DHCP, TCP/IP
- No Wi-Fi in v1 (VirtualBox uses wired emulation)
