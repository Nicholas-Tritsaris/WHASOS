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
This is not associated with Microsoft or Products of Windows.

---

## SEALED ARCHIVE — AUTHORIZED PERSONNEL ONLY
TOP SECRET — Access requires Level 4 clearance and dual‑factor authorization.  
Viewing, copying, or transmitting any portion of this archive without explicit authorization is prohibited and will be logged.

---

### ███ SEALED INDEX ███
- /sealed/ANOMALY_REGISTRY.md — ███████████████████████████████  
- /sealed/OP_PROTOCOLS/ — ███████████████████████████████  
- /sealed/KEYVAULT/ — ███████████████████████████████  
- /sealed/LOGS/2026-02-28/ — ███████████████████████████████

---

### ███ SEALED ENTRY: ANOMALY 0xA7F3 ███
Designation: ███████████  
Containment Class: █████ / █████ / █████  
Summary: █████████████████████████████████████████████████████████████████████████████████  
Observed Effects: ████████████████████████████████████████████████████████████████  
Containment Protocol (redacted):  
- Step 1: █████████████████████████████  
- Step 2: █████████████████████████████  
- Emergency Escalation: █████████████████████████████

---

### ███ SEALED ENTRY: OPERATIONAL KEYS ███
Key Vault Index: KV-██-2026-02-28  
Active Compartment Keys (placeholders):  
- COMP-A — XXXX-████-XXXX-████ (access: Level 3+)  
- COMP-B — YYYY-████-YYYY-████ (access: Level 4+)  
- COMP-C — ZZZZ-████-ZZZZ-████ (access: Level 5; dual sign required)

Key Handling Notes:  
- Keys are stored in hardware HSM emulation; export is prohibited.  
- All key usage must be recorded in sealed/KEYVAULT/USAGE_LOGS.md and signed by two authorized operators.

---

### ███ SEALED ENTRY: INCIDENT LOG (EXCERPT) ███
[2026-02-28T20:52:03-05:00] [REDACTED] — Anomaly detection triggered on node: ███-NODE-17  
[2026-02-28T20:53:11-05:00] [REDACTED] — Containment protocol initiated; network partition applied  
[2026-02-28T20:54:02-05:00] [REDACTED] — Operator authentication failure; escalation to Level 4  
[2026-02-28T20:55:12-05:00] [REDACTED] — Evidence snapshot stored in sealed/LOGS/2026-02-28/

---

### ███ SEALED ENTRY: ENCRYPTED BLOB (SAMPLE) ███
Blob ID: BLOB-7F-20260228  
Cipher: AES-256-GCM (metadata redacted)  
Payload (base64 placeholder): U2VhbGVkQmxvYl9QbGFjZWhvbGRlcj0gW1JFREFDVEVEXQ==  
Notes: Decryption requires COMP-C and dual operator signature.

---

### ███ SEALED ENTRY: REDACTION ENGINE RULES ███
- Documents marked [REDACTED] must be redacted at the paragraph and metadata level.  
- Automated redaction engine applies pattern rules: PII, geo-coordinates, operational keys, and containment vectors.  
- Redaction audit trail is immutable and stored in sealed/REDACTION_AUDIT.log.

---

### ███ SEALED ENTRY: EMERGENCY PROTOCOL SUMMARY ███
- Trigger Conditions: Any unauthorized access attempt to /sealed/ or repeated failed authentications beyond threshold.  
- Immediate Actions: Network isolation; session token invalidation; alert to Level 5 operators.  
- Recovery: Recovery requires signed approval from two Level 5 operators and a validated integrity check of KERNEL_DESIGN.md.

---

### ███ SEALED MEMO: INTERNAL AUTHORIZATION TEMPLATE ███
AUTHORIZATION: [TOP SECRET]  
APPROVED_BY: [REDACTED]  
SIGNATURES_REQUIRED: 2  
CLEARANCE_MINIMUM: LEVEL_4  
VALID_UNTIL: [REDACTED]  
NOTES: All approvals must be recorded in sealed/AUTH_LOGS.md

---

## SEALING & REDACTION LEGEND

- █████ — Full redaction (sensitive content removed)  
- [REDACTED] — Inline redaction marker (metadata removed)  
- COMP-* — Compartment identifiers (access controlled)  
- BLOB-* — Encrypted payload identifiers

---

END OF SEALED ARCHIVE

---

END OF FILE

Which clearance level should the sealed appendix be restricted to?
