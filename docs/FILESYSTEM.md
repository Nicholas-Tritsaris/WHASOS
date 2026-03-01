# WHAOS File System and Storage

## Partitioning for VirtualBox

### Disk layout (GPT)

| Partition | Size   | Type        | Mount | Notes                    |
|-----------|--------|-------------|-------|--------------------------|
| /dev/sda1 | 512 MiB| EFI System  | /boot/efi | UEFI bootloader       |
| /dev/sda2 | rest   | Linux LVM/ext4 | / | Root filesystem         |

### MBR layout (legacy BIOS)

| Partition | Size   | Type  | Mount | Notes                    |
|-----------|--------|-------|-------|--------------------------|
| /dev/sda1 | rest   | Linux | /     | Root filesystem          |

### Formatting commands

```bash
# GPT + EFI + ext4
parted -s /dev/sda mklabel gpt
parted -s /dev/sda mkpart primary fat32 1MiB 513MiB
parted -s /dev/sda set 1 esp on
parted -s /dev/sda mkpart primary ext4 513MiB 100%
mkfs.vfat -F 32 -n EFI /dev/sda1
mkfs.ext4 -L WHAOS_ROOT /dev/sda2
```

```bash
# Legacy MBR
parted -s /dev/sda mklabel msdos
parted -s /dev/sda mkpart primary ext4 1MiB 100%
mkfs.ext4 -L WHAOS_ROOT /dev/sda1
```

## Root Filesystem Layout

```
/
├── bin/
│   ├── sh -> busybox
│   ├── bash
│   ├── cat, cp, ls, mkdir, rm, ...
│   └── ...
├── boot/
│   ├── grub/
│   │   └── grub.cfg
│   ├── vmlinuz-whacos
│   └── initramfs-whacos.img
├── dev/           # devtmpfs
├── etc/
│   ├── fstab
│   ├── hostname
│   ├── passwd
│   ├── group
│   ├── shadow
│   ├── whaos/
│   │   ├── desktop.conf
│   │   └── theme.conf
│   ├── whad/
│   │   └── rc.conf
│   ├── X11/
│   │   └── xorg.conf
│   └── ...
├── home/
│   └── whauser/
├── lib/
│   └── ...
├── lib64/
│   └── ...
├── mnt/
├── opt/
├── proc/          # procfs
├── root/
├── run/
├── sbin/
│   ├── init -> /sbin/whad
│   └── ...
├── srv/
├── sys/           # sysfs
├── tmp/
├── usr/
│   ├── bin/
│   ├── lib/
│   ├── share/
│   │   ├── whaos/
│   │   │   ├── icons/
│   │   │   └── themes/
│   │   └── ...
│   └── ...
└── var/
    ├── log/
    └── ...
```
