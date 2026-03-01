# Building WHAOS with Visual Studio 2022

WHAOS C components are built for **Linux** (WHAOS target). Use one of these methods in VS2022.

---

## Method 1: CMake (recommended)

VS2022 builds via **WSL** or a **remote Linux connection**.

### Setup

1. Install **Visual Studio 2022** with:
   - Workload: **Linux development with C++**
   - Component: **C++ CMake tools for Windows**

2. Install **WSL2** (optional but easiest):
   ```powershell
   wsl --install
   ```
   In WSL (Ubuntu): `sudo apt install build-essential cmake ninja-build libgtk-3-dev pkg-config`

### Open and build

1. **File → Open → Folder** → select the WHAOS folder  
2. VS2022 will detect `CMakeLists.txt`  
3. Select **Linux** (or WSL) as the connection target  
4. Choose **linux-debug** or **linux-release** preset  
5. **Build → Build All** (Ctrl+Shift+B)

Output:

- `build/linux-debug/output/whad/whad`
- `build/linux-debug/output/whaos-panel/whaos-panel`

---

## Method 2: Solution (.sln)

For **Linux development with C++**, the `.sln` uses Linux platform configuration.

### Setup

1. Install the **Linux development with C++** workload  
2. Configure a Linux connection: **Tools → Options → Cross Platform → Connection Manager**  
3. Add WSL or a remote Linux machine  
4. On Linux: `sudo apt install build-essential libgtk-3-dev`

### Open and build

1. **File → Open → Project/Solution** → select `WHAOS.sln`  
2. Set platform to **Linux**  
3. Set configuration to **Debug** or **Release**  
4. **Build → Build Solution** (F7)

Output:

- `output/whad/Debug/whad` or `output/whad/Release/whad`
- `output/whaos-panel/Debug/whaos-panel` or `output/whaos-panel/Release/whaos-panel`

---

## Project structure

| Project    | Source             | Description              |
|-----------|--------------------|--------------------------|
| **whad**  | `src/init/whad.c`  | WHAOS init (PID 1)       |
| **whaos-panel** | `src/desktop/main.c`, `src/desktop/whaos_panel.c` | WHAOS taskbar (GTK3) |

---

## Notes

- Targets **Linux x86-64** only (WHAOS runs on Linux).  
- **whad** needs no extra deps.  
- **whaos-panel** needs GTK3 (`libgtk-3-dev`) on Linux.  
- If build fails for whaos-panel with include errors, run on Linux:
  ```bash
  pkg-config --cflags gtk+-3.0
  pkg-config --libs gtk+-3.0
  ```
  and adjust include/library paths in the project if required.
