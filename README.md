# WHAOS

**WHAOS** is a 64-bit operating system for x86-64 (AMD64) with a Windows 7–like desktop experience. It is designed to run in VirtualBox and uses original branding—no proprietary Windows code or assets.

## Quick Start

1. **Build C components with Visual Studio 2022** (see [docs/BUILD_VS2022.md](docs/BUILD_VS2022.md)):
   - Open folder (CMake) or `WHAOS.sln` (Solution)
   - Requires: Linux Development with C++, WSL or remote Linux
   - Builds: `whad` (init), `whaos-panel` (taskbar)

2. **Build the ISO** (on Ubuntu 24.04):
   ```bash
   ./scripts/build_iso.sh 1.0
   ```
2. **Create a VirtualBox VM** (see [docs/VIRTUALBOX.md](docs/VIRTUALBOX.md))
3. **Attach** `output/whacos-1.0-amd64.iso` and boot
4. **Install** or run live

## Documentation

| Document | Contents |
|----------|----------|
| [ARCHITECTURE.md](docs/ARCHITECTURE.md) | Full architecture overview |
| [HOWTOBUILD.md](docs/HOWTOBUILD.md) | Complete build guide |
| [ASSUMPTIONS.md](docs/ASSUMPTIONS.md) | Build environment, approach, legal |
| [FILESYSTEM.md](docs/FILESYSTEM.md) | Partitioning, root layout |
| [USERS_AND_SECURITY.md](docs/USERS_AND_SECURITY.md) | Users, groups, permissions |
| [CORE_APPS.md](docs/CORE_APPS.md) | File Explorer, Control Center, etc. |
| [INPUT.md](docs/INPUT.md) | Keyboard and mouse support |
| [VIRTUALBOX.md](docs/VIRTUALBOX.md) | VM configuration, first boot |

## Build Instructions (Step-by-Step)

### Prerequisites

- Ubuntu 24.04 LTS (or Debian 12 / Fedora 40)
- sudo/root access
- ~10 GB free disk space

### 1. Install dependencies

```bash
sudo apt-get update
sudo apt-get install -y debootstrap xorriso grub-pc-bin grub-efi-amd64-bin \
  squashfs-tools rsync wget build-essential
```

### 2. Bootstrap root filesystem

```bash
sudo debootstrap --arch=amd64 bookworm output/iso_root http://deb.debian.org/debian/
```

### 3. Add WHAOS components

- Copy kernel (`vmlinuz-whacos`) and initramfs to `output/iso_root/boot/`
- Copy GRUB config to `output/iso_root/boot/grub/`
- Build `whad` (init) and install to `output/iso_root/sbin/`

### 4. Build ISO

```bash
./scripts/build_iso.sh 1.0
```

### 5. Test in VirtualBox

1. Create VM (Linux 64-bit, 2 GB RAM, 20 GB disk)
2. Attach `output/whacos-1.0-amd64.iso` as optical drive
3. Boot and install

## Project Structure

```
WHAOS/
├── boot/grub/          # GRUB config
├── docs/               # Architecture and design docs
├── scripts/            # Build scripts
├── src/
│   ├── desktop/        # WHAOS Panel, theme
│   ├── init/           # whad (init)
│   ├── installer/      # Installer script
│   └── kernel/         # Kernel build config
└── output/             # Build output (ISO)
```

## License

GPL-2.0 / MIT / BSD where applicable. No proprietary Windows assets.
