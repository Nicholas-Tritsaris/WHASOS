# WHAOS VirtualBox Configuration

## Recommended VM Settings

| Setting        | Value                     |
|----------------|---------------------------|
| **Type**       | Linux                     |
| **Version**    | Linux 2.6 / 3.x / 4.x / 5.x (64-bit) |
| **RAM**        | 2048 MB (minimum 1024 MB) |
| **CPU**        | 2 cores                   |
| **Disk**       | 20 GB VDI (dynamically allocated) |
| **Network**    | NAT or Bridged Adapter    |
| **Graphics**   | VMSVGA, 128 MB VRAM       |
| **EFI**        | Optional (enable for UEFI boot) |

## Creating the VM

### Using GUI

1. **New** → Name: WHAOS, Type: Linux, Version: Linux 2.6 / 3.x / 4.x / 5.x (64-bit)
2. **Memory**: 2048 MB
3. **Create virtual hard disk** → VDI → Dynamically allocated → 20 GB
4. **Settings** → Storage → Controller: IDE → Add Optical Drive → Choose disk → Select `whacos-1.0-amd64.iso`
5. **Settings** → Display → Graphics Controller: VMSVGA, Video Memory: 128 MB
6. **Settings** → System → Enable EFI (optional)
7. **Start** the VM

### Using VBoxManage (CLI)

```bash
VBoxManage createvm --name "WHAOS" --ostype "Linux_64" --register
VBoxManage modifyvm "WHAOS" --memory 2048 --cpus 2 --vram 128
VBoxManage modifyvm "WHAOS" --graphicscontroller vmsvga
VBoxManage createhd --filename "WHAOS.vdi" --size 20480
VBoxManage storagectl "WHAOS" --name "SATA" --add sata --controller IntelAhci
VBoxManage storageattach "WHAOS" --storagectl "SATA" --port 0 --type hdd --medium "WHAOS.vdi"
VBoxManage storagectl "WHAOS" --name "IDE" --add ide
VBoxManage storageattach "WHAOS" --storagectl "IDE" --port 1 --device 0 --type dvddrive --medium "whacos-1.0-amd64.iso"
VBoxManage modifyvm "WHAOS" --boot1 dvd --boot2 disk --boot3 none
VBoxManage startvm "WHAOS"
```

## First Boot & Installation

1. **Boot from ISO** – VM starts from WHAOS installer/live image
2. **Live mode** – Boot into live WHAOS (no install)
3. **Install mode** – Select "WHAOS Install" from GRUB menu
4. **Follow installer** – Language → Keyboard → Partition → User → Timezone → Install
5. **Reboot** – Eject ISO (or change boot order) so VM boots from disk
6. **First login** – Use the account created during install

## Ejecting the ISO After Install

### GUI
Settings → Storage → Optical Drive → Remove disk from virtual drive

### CLI
```bash
VBoxManage storageattach "WHAOS" --storagectl "IDE" --port 1 --device 0 --medium none
VBoxManage modifyvm "WHAOS" --boot1 disk --boot2 none
```

## Troubleshooting

| Issue              | Solution                                      |
|--------------------|-----------------------------------------------|
| No 64-bit option   | Enable VT-x/AMD-V in BIOS                     |
| Black screen       | Try VBoxSVGA or VESA; check kernel logs       |
| No network         | Use NAT or Bridged; ensure e1000 driver       |
| Slow graphics      | Install VirtualBox Guest Additions (if available) |
