# WHAOS Keyboard and Mouse Support

## Overview

WHAOS supports keyboard and mouse input at two levels: **kernel/driver** (hardware) and **desktop** (GUI).

---

## 1. Kernel / Driver Level (VirtualBox)

### Keyboard (PS/2)

| Component | Driver   | Notes                    |
|-----------|----------|--------------------------|
| PS/2 Keyboard | atkbd  | Linux built-in, CONFIG_KEYBOARD_ATKBD=y |
| Evdev     | evdev   | Exposes input to userspace via /dev/input/event* |

### Mouse (PS/2)

| Component | Driver   | Notes                    |
|-----------|----------|--------------------------|
| PS/2 Mouse | psmouse | Linux built-in, CONFIG_MOUSE_PS2=y |
| Evdev     | evdev   | Exposes input to userspace |

### Kernel Configuration

```
CONFIG_INPUT=y
CONFIG_INPUT_EVDEV=y
CONFIG_INPUT_KEYBOARD=y
CONFIG_INPUT_MOUSE=y
CONFIG_KEYBOARD_ATKBD=y
CONFIG_MOUSE_PS2=y
```

### VirtualBox Notes

- Default VirtualBox VM uses **PS/2** keyboard and mouse
- Input is captured when the VM window has focus
- **Right Ctrl** releases mouse cursor (Host Key)
- Tablet/absolute pointing optional for precise positioning

---

## 2. Desktop Level (X11 / GTK)

### Input Stack

```
/dev/input/event0,1,... → X11 (evdev) → GTK (GDK) → WHAOS Panel / Apps
```

### WHAOS Panel – Keyboard Support

| Key        | Action              |
|------------|---------------------|
| Super L/R  | Toggle Start menu   |
| (future)   | Alt+Tab, Win+E, etc.|

### WHAOS Panel – Mouse Support

| Action       | Target        | Result                     |
|--------------|---------------|----------------------------|
| Left click   | Start button  | Open/close Start menu      |
| Left click   | Start menu item | Launch app, close menu   |
| Right click  | Clock         | Context menu (Adjust date/time) |
| Hover        | Start button  | Visual feedback (CSS hover) |
| Button press/release | Panel | Event masks for future use |

### GTK Event Masks (Panel)

- `GDK_BUTTON_PRESS_MASK`, `GDK_BUTTON_RELEASE_MASK` – mouse clicks
- `GDK_ENTER_NOTIFY_MASK`, `GDK_LEAVE_NOTIFY_MASK` – hover
- `GDK_KEY_PRESS_MASK`, `GDK_KEY_RELEASE_MASK` – keyboard (on main window)

---

## 3. Future Enhancements

- **Global key grab** (XGrabKey) for Super key when panel lacks focus
- **Alt+Tab** – window switching
- **Win+E** – open WHAOS File Explorer
- **Mouse wheel** – scroll in Start menu, volume in tray
- **Drag and drop** – taskbar reordering
