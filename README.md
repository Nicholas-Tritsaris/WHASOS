---
created: 2026-02-28T20:55:45-05:00
modified: 2026-03-2T09:31:50-09:31
---

# WHASOS  
### Work Health and Safety Operating System  
> INTERNAL CLASSIFIED SYSTEM  
> Unauthorized access is prohibited.

---

## ███████████████████████████████
## SYSTEM OVERVIEW
## ███████████████████████████████

**WHASOS (Work Health and Safety Operating System)** is a secure, classified‑grade operating system project designed for integration into a high‑security game environment.

WHASOS combines:

- Workplace Health & Safety compliance infrastructure  
- Government‑grade access control systems  
- SCP‑style anomaly containment documentation  
- Intelligence‑agency‑inspired secure operating architecture  

This system is designed to function as a **real, modular operating system**, while maintaining immersive classified‑world aesthetics.

---

## ACCESS WARNING

This system simulates restricted federal infrastructure.

Any unauthorized access attempts within the game environment may trigger:

- System lockdown  
- Activity logging  
- Account suspension  
- Simulated prosecution notices  
- Clearance revocation  

All activity is logged and audited.

---

## CORE OBJECTIVES

- Build a functional operating system architecture  
- Implement multi‑tier clearance authentication  
- Create SCP‑style secure documentation systems  
- Integrate WHS compliance monitoring modules  
- Provide immersive classified UI/UX  

---

## PRIMARY MODULES

### 🔐 Clearance Control Subsystem
- Multi‑level authorization  
- Role‑based access restrictions  
- Redaction enforcement  
- Session auditing  

### 📁 Secure Containment Database
- SCP‑style object registry  
- Classification levels (SAFE / EUCLID / KETER equivalents)  
- Incident reporting  
- Document redaction engine  

### ⚠ Workplace Hazard System
- Risk assessment tools  
- Hazard reporting  
- Compliance violations tracking  
- Escalation engine  

### 🛡 Security Enforcement Layer
- Intrusion detection  
- Access attempt logging  
- Automatic lockout protocols  
- Tamper detection  

---

## SYSTEM DESIGN PHILOSOPHY

WHASOS is engineered around:

- Zero‑trust architecture  
- Principle of least privilege  
- Compartmentalized access domains  
- Immutable audit logging  
- Modular extensibility  

---

## ARCHITECTURE SUMMARY

WHASOS is structured in layered form:

1. Kernel Layer (core system control)  
2. System Services Layer  
3. Security & Authentication Layer  
4. Application Layer (WHS + SCP modules)  
5. User Interface Layer  

Full technical details are documented in:

> KERNEL_DESIGN.md

---

## PROJECT STATUS

DEVELOPMENT PHASE: ALPHA  
Security architecture defined  
Kernel structure under development  
Core modules in planning stage

---

## ROADMAP

- Custom secure boot environment  
- Role‑based UI rendering  
- Multiplayer secure terminal network  
- Encrypted internal messaging layer  
- AI‑powered anomaly analysis  
- Modular update system

---

## DISCLAIMER

WHASOS is a fictional classified system created for game integration and operating system development experimentation.  
Any references to intelligence agencies or prosecution are purely thematic.

---

## AUTHOR

Nicholas Tritsaris  
GitHub: https://github.com/Nicholas-Tritsaris

---

# WHAOS  
A 64‑bit operating system for x86‑64 (AMD64) with a Windows 7–like desktop experience.  
Runs in VirtualBox and uses original branding — no proprietary Windows code or assets.

---

## Quick Start

1. Build C components with Visual Studio 2022 (see docs/BUILD_VS2022.md):  
   - Open folder (CMake) or WHAOS.sln (Solution)  
   - Requires: Linux Development with C++, WSL or remote Linux  
   - Builds: whad (init), whaos-panel (taskbar)

2. Build the ISO (on Ubuntu 24.04):
   ./scripts/build_iso.sh 1.0

3. Create a VirtualBox VM (see docs/VIRTUALBOX.md)

4. Attach output/whacos-1.0-amd64.iso and boot

5. Install or run live

---

## Documentation

Document | Contents
--- | ---
ARCHITECTURE.md | Full architecture overview
HOWTOBUILD.md | Complete build guide
ASSUMPTIONS.md | Build environment, approach, legal
FILESYSTEM.md | Partitioning, root layout
USERS_AND_SECURITY.md | Users, groups, permissions
CORE_APPS.md | File Explorer, Control Center, etc.
INPUT.md | Keyboard and mouse support
VIRTUALBOX.md | VM configuration, first boot

---

## Build Instructions (Step-by-Step)

### Prerequisites

- Ubuntu 24.04 LTS (or Debian 12 / Fedora 40)  
- sudo/root access  
- ~10 GB free disk space

### 1. Install dependencies

sudo apt-get update  
sudo apt-get install -y debootstrap xorriso grub-pc-bin grub-efi-amd64-bin squashfs-tools rsync wget build-essential

### 2. Bootstrap root filesystem

sudo debootstrap --arch=amd64 bookworm output/iso_root http://deb.debian.org/debian/

### 3. Add WHAOS components

- Copy kernel (vmlinuz-whacos) and initramfs to output/iso_root/boot/  
- Copy GRUB config to output/iso_root/boot/grub/  
- Build whad (init) and install to output/iso_root/sbin/

### 4. Build ISO

./scripts/build_iso.sh 1.0

### 5. Test in VirtualBox

1. Create VM (Linux 64-bit, 2 GB RAM, 20 GB disk)  
2. Attach output/whacos-1.0-amd64.iso as optical drive  
3. Boot and install

---

## Project Structure

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

---

## License

GPL-2.0 / MIT / BSD where applicable. No proprietary Windows assets.
---
created: 2026-02-28T20:55:45-05:00
modified: 2026-02-28T20:55:50-05:00
---

# WHASOS
### Work Health and Safety Operating System
> INTERNAL CLASSIFIED SYSTEM  
> Unauthorized access is prohibited.

---

## ███████████████████████████████
## SYSTEM OVERVIEW
## ███████████████████████████████

**WHASOS (Work Health and Safety Operating System)** is a secure, classified-grade operating system project designed for integration into a high-security game environment.

WHASOS combines:

- Workplace Health & Safety compliance infrastructure
- Government-grade access control systems
- SCP-style anomaly containment documentation
- Intelligence agency–inspired secure operating architecture

This system is designed to function as a **real, modular operating system**, while maintaining immersive classified-world aesthetics.

---

## ACCESS WARNING

This system simulates restricted federal infrastructure.

Any unauthorized access attempts within the game environment may trigger:

- System lockdown
- Activity logging
- Account suspension
- Simulated prosecution notices
- Clearance revocation

All activity is logged and audited.

---

## CORE OBJECTIVES

- Build a functional operating system architecture
- Implement multi-tier clearance authentication
- Create SCP-style secure documentation systems
- Integrate WHS compliance monitoring modules
- Provide immersive classified UI/UX

---

## PRIMARY MODULES

### 🔐 Clearance Control Subsystem
- Multi-level authorization
- Role-based access restrictions
- Redaction enforcement
- Session auditing

### 📁 Secure Containment Database
- SCP-style object registry
- Classification levels (SAFE / EUCLID / KETER equivalent)
- Incident reporting
- Document redaction engine

### ⚠ Workplace Hazard System
- Risk assessment tools
- Hazard reporting
- Compliance violations tracking
- Escalation engine

### 🛡 Security Enforcement Layer
- Intrusion detection
- Access attempt logging
- Automatic lockout protocols
- Tamper detection

---

## SYSTEM DESIGN PHILOSOPHY

WHASOS is engineered around:

- Zero-trust architecture
- Principle of least privilege
- Compartmentalized access domains
- Immutable audit logging
- Modular extensibility

---

## ARCHITECTURE SUMMARY

WHASOS is structured in layered form:

1. Kernel Layer (core system control)
2. System Services Layer
3. Security & Authentication Layer
4. Application Layer (WHS + SCP modules)
5. User Interface Layer

Full technical details are documented in:

> `KERNEL_DESIGN.md`

---

## PROJECT STATUS

> DEVELOPMENT PHASE: ALPHA  
> Security architecture defined  
> Kernel structure under development  
> Core modules in planning stage  

---

## ROADMAP

- Custom secure boot environment
- Role-based UI rendering
- Multiplayer secure terminal network
- Encrypted internal messaging layer
- AI-powered anomaly analysis
- Modular update system

---

## DISCLAIMER

WHASOS is a fictional classified system created for game integration and operating system development experimentation.

Any references to intelligence agencies or prosecution are purely thematic.

---

## AUTHOR

Nicholas Tritsaris  
GitHub: https://github.com/Nicholas-Tritsaris

---

> END OF FILE

// No merge conflicts detected in this file. README appears clean and well-formatted. 
// If you expected a merge conflict here, please provide the conflicting sections so they may be resolved.

