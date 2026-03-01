#!/bin/bash
# WHAOS ISO Build Pipeline
# Build host: Ubuntu 24.04 LTS
# Output: whacos-1.0-amd64.iso
# GPL-2.0

set -e
WHAOS_VERSION="${1:-1.0}"
ARCH="amd64"
OUTPUT_DIR="$(pwd)/output"
ISO_NAME="whacos-${WHAOS_VERSION}-${ARCH}.iso"
BUILD_ROOT="$OUTPUT_DIR/iso_root"

# Dependencies
install_deps() {
    sudo apt-get update
    sudo apt-get install -y \
        debootstrap xorriso grub-pc-bin grub-efi-amd64-bin \
        squashfs-tools rsync wget
}

# Project root (parent of scripts/)
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$(cd "$SCRIPT_DIR/.." && pwd)"

# Create minimal root with debootstrap (example: Debian-based)
bootstrap_root() {
    mkdir -p "$OUTPUT_DIR" "$BUILD_ROOT"
    sudo debootstrap --arch=amd64 bookworm "$BUILD_ROOT" http://deb.debian.org/debian/
}

# Copy WHAOS customizations
install_whacos() {
    # Kernel, initramfs, GRUB
    sudo mkdir -p "$BUILD_ROOT/boot/grub"
    [ -d "$PROJECT_ROOT/boot/grub" ] && sudo cp -r "$PROJECT_ROOT/boot/grub/"* "$BUILD_ROOT/boot/grub/" || true
    
    # WHAOS config
    sudo mkdir -p "$BUILD_ROOT/etc/whaos"
    echo "WHAOS $WHAOS_VERSION" | sudo tee "$BUILD_ROOT/etc/whaos/version"
    
    # Init
    [ -f "$PROJECT_ROOT/src/init/whad" ] && sudo cp "$PROJECT_ROOT/src/init/whad" "$BUILD_ROOT/sbin/" || true
    sudo ln -sf whad "$BUILD_ROOT/sbin/init" 2>/dev/null || true
}

# Build ISO with GRUB
build_iso() {
    mkdir -p "$OUTPUT_DIR/iso"
    
    # Copy root to iso/
    sudo cp -a "$BUILD_ROOT"/* "$OUTPUT_DIR/iso/" 2>/dev/null || true
    
    # Create GRUB EFI image
    grub-mkstandalone -o "$OUTPUT_DIR/iso/boot/grub/efi.img" \
        -O x86_64-efi \
        --locales= \
        --fonts= \
        "boot/grub/grub.cfg=$OUTPUT_DIR/iso/boot/grub/grub.cfg"
    
    # Create ISO with xorriso
    xorriso -as mkisofs \
        -iso-level 3 \
        -full-iso9660-filenames \
        -volid "WHAOS_${WHAOS_VERSION}" \
        -eltorito-boot boot/grub/efi.img \
        -no-emul-boot \
        -eltorito-catalog boot.cat \
        -output "$OUTPUT_DIR/$ISO_NAME" \
        "$OUTPUT_DIR/iso"
    
    echo "Built: $OUTPUT_DIR/$ISO_NAME"
}

# Full build
full_build() {
    install_deps
    bootstrap_root
    install_whacos
    build_iso
}

full_build "$@"
