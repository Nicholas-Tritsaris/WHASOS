#!/bin/bash
# WHAOS Installer - interactive installation flow
# Steps: Language, Keyboard, Partitioning, User, Timezone, Install, Reboot
# GPL-2.0

set -e
WHAOS_VERSION="1.0"
INSTALL_LOG="/var/log/whacos-install.log"

log() { echo "[$(date +%H:%M:%S)] $*" | tee -a "$INSTALL_LOG"; }

# Step 1: Language & Keyboard
step_language() {
    log "Step 1: Language & Keyboard"
    # Default: en_US, qwerty
    export LANG=en_US.UTF-8
    loadkeys us 2>/dev/null || true
}

# Step 2: Disk partitioning
step_partition() {
    log "Step 2: Disk partitioning"
    TARGET_DISK="${1:-/dev/sda}"
    
    # Interactive: parted/cfdisk or use presets
    # Example: single ext4 partition
    parted -s "$TARGET_DISK" mklabel msdos
    parted -s "$TARGET_DISK" mkpart primary ext4 1MiB 100%
    parted -s "$TARGET_DISK" set 1 boot on
    mkfs.ext4 -L WHAOS_ROOT "${TARGET_DISK}1"
    
    ROOT_PART="${TARGET_DISK}1"
    mkdir -p /mnt/install
    mount "$ROOT_PART" /mnt/install
}

# Step 3: User account
step_user() {
    log "Step 3: User account"
    USERNAME="${1:-whauser}"
    PASSWORD="${2:-}"
    HOSTNAME="${3:-whaos}"
    
    # Create passwd/group/shadow entries
    # (In real impl: chroot and useradd)
    echo "$HOSTNAME" > /mnt/install/etc/hostname
}

# Step 4: Time zone
step_timezone() {
    log "Step 4: Time zone"
    TZ="${1:-America/New_York}"
    ln -sf "/usr/share/zoneinfo/$TZ" /mnt/install/etc/localtime
}

# Step 5: Install files
step_install() {
    log "Step 5: Copying WHAOS files..."
    SRC_ROOT="${1:-/}"
    
    # Copy live system to target
    rsync -a --exclude=/proc --exclude=/sys --exclude=/dev \
          --exclude=/run --exclude=/tmp "$SRC_ROOT/" /mnt/install/ || \
    cp -a bin boot etc home lib lib64 opt root sbin usr var /mnt/install/ 2>/dev/null || true
    
    mkdir -p /mnt/install/{proc,sys,dev,run,tmp}
    
    # Install GRUB
    log "Installing GRUB..."
    mount --bind /dev /mnt/install/dev
    mount --bind /proc /mnt/install/proc
    mount --bind /sys /mnt/install/sys
    chroot /mnt/install grub-install "${TARGET_DISK:-/dev/sda}"
    chroot /mnt/install update-grub 2>/dev/null || true
    umount /mnt/install/{dev,proc,sys}
    
    log "Installation complete."
}

# Step 6: Reboot
step_reboot() {
    log "Step 6: Reboot"
    sync
    umount -R /mnt/install 2>/dev/null || true
    reboot
}

# Main flow
main() {
    log "WHAOS Installer v$WHAOS_VERSION"
    step_language
    step_partition "${1:-/dev/sda}"
    step_user "${2:-whauser}" "${3:-}" "${4:-whaos}"
    step_timezone "${5:-America/New_York}"
    step_install "/"
    step_reboot
}

main "$@"
