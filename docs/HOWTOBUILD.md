# WHAOS How to Build

Complete step-by-step guide to building WHAOS from source.

---

## Prerequisites

### Build host options

| Host | Use case |
|------|----------|
| **Ubuntu 24.04 LTS** | ISO build, Linux native build |
| **Windows + WSL2** | VS2022 build for Linux target |
| **Debian 12 / Fedora 40** | Alternative Linux hosts |

### Required tools

- **gcc 12+**, binutils, GNU Make
- **CMake 3.20+**
- **sudo/root** (for chroot, ISO creation)
- ~10 GB free disk space

---

## 1. Build C components

### Option A: Visual Studio 2022 (Windows + WSL)

1. Install **Visual Studio 2022** with:
   - Workload: **Linux development with C++**
   - Component: **C++ CMake tools for Windows**

2. Install **WSL2**:
   ```powershell
   wsl --install
   ```

3. In WSL (Ubuntu):
   ```bash
   sudo apt update
   sudo apt install build-essential cmake ninja-build libgtk-3-dev pkg-config
   ```

4. Open WHAOS in VS2022:
   - **File → Open → Folder** → select WHAOS
   - Or **File → Open → Project** → select `WHAOS.sln`

5. Select **Linux** (or WSL) as build target, then **Build → Build All**

**Output**: `output/whad/whad`, `output/whaos-panel/whaos-panel`

### Option B: Linux native (make)

```bash
cd WHAOS
make init
make desktop   # optional, requires libgtk-3-dev
```

### Option C: CMake (Linux)

```bash
cd WHAOS
mkdir build && cd build
cmake ..
make
```

---

## 2. Build the ISO (Linux only)

Requires Ubuntu 24.04 or Debian 12.

### Install dependencies

```bash
sudo apt-get update
sudo apt-get install -y debootstrap xorriso grub-pc-bin grub-efi-amd64-bin \
  squashfs-tools rsync wget build-essential
```

### Run build script

```bash
./scripts/build_iso.sh 1.0
```

**Output**: `output/whacos-1.0-amd64.iso`

### Manual steps (if script fails)

1. Bootstrap root: `sudo debootstrap --arch=amd64 bookworm output/iso_root http://deb.debian.org/debian/`
2. Copy kernel, initramfs, GRUB config to `output/iso_root/boot/`
3. Copy built `whad` to `output/iso_root/sbin/init`
4. Build ISO with xorriso (see `scripts/build_iso.sh`)

---

## 3. Test in VirtualBox

1. Create VM: Linux 64-bit, 2 GB RAM, 20 GB disk
2. Attach `output/whacos-1.0-amd64.iso` as optical drive
3. Boot from CD
4. Install or run live

See [VIRTUALBOX.md](VIRTUALBOX.md) for full VM setup.

---

## Project structure

```
WHAOS/
├── boot/grub/          # GRUB config
├── docs/               # Documentation
├── scripts/            # Build scripts (build_iso.sh)
├── src/
│   ├── desktop/        # whaos-panel (main.c, whaos_panel.c)
│   ├── init/           # whad (whad.c)
│   ├── installer/      # whaos_installer.sh
│   └── kernel/         # Kernel build config
├── whad/               # VS project for whad
├── whaos-panel/        # VS project for whaos-panel
├── CMakeLists.txt      # CMake build
├── WHAOS.sln           # VS solution
└── output/             # Build output
```
