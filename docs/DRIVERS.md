# WHAOS Drivers (VirtualBox-Oriented)

## Supported VirtualBox Devices

| VirtualBox Device     | Linux Driver      | Module   | Notes                        |
|-----------------------|-------------------|----------|------------------------------|
| Storage (IDE)         | ata_piix          | (built-in) | Default IDE controller    |
| Storage (SATA/AHCI)   | ahci              | (built-in) | Recommended for SATA      |
| Graphics (VMSVGA)     | vmwgfx            | drm_vmwgfx | Best performance         |
| Graphics (VBoxSVGA)   | vboxvideo         | vboxvideo  | Guest Additions           |
| Graphics (VESA)       | vesafb            | (built-in) | Fallback, no acceleration |
| Keyboard              | atkbd             | (built-in) | PS/2 keyboard             |
| Mouse                 | psmouse           | (built-in) | PS/2 mouse                |
| Network (Intel 82540EM)| e1000            | e1000      | Intel PRO/1000            |

## Kernel Configuration for Drivers

Ensure these are enabled in `.config`:

```
# Storage
CONFIG_ATA_PIIX=y
CONFIG_SATA_AHCI=y
CONFIG_BLK_DEV_SD=y

# Graphics
CONFIG_DRM_VMWGFX=y
CONFIG_FB_VESA=y

# Input
CONFIG_INPUT_KEYBOARD=y
CONFIG_INPUT_MOUSE=y
CONFIG_KEYBOARD_ATKBD=y
CONFIG_MOUSE_PS2=y

# Network
CONFIG_E1000=y
```

## Driver Loading (if modular)

```bash
modprobe e1000
modprobe drm
modprobe vmwgfx
```

## WHAOS Driver Registry (Concept)

For a custom kernel, a driver registry could look like:

```c
/* Pseudocode: driver registration */
struct whaos_driver {
    const char *name;
    int (*probe)(struct device *);
    void (*remove)(struct device *);
};

whaos_register_driver(&e1000_driver);
whaos_register_driver(&vmwgfx_driver);
```
