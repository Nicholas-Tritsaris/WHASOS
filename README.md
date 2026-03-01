--- 
created: 2026-02-28T20:55:45-05:00
modified: 2026-03-02T09:31:50-09:31
---

---

# WHAOS
A 64‑bit operating system for x86‑64 (AMD64) with a Windows 7–like desktop experience. Runs in VirtualBox; no proprietary Windows assets.
### Work Health and Safety Operating System
> INTERNAL CLASSIFIED SYSTEM
> Unauthorized access is prohibited.

## Quick Start (summary)

1. Build C components with Visual Studio 2022 (see docs/BUILD_VS2022.md).
2. Build ISO on Ubuntu 24.04: `./scripts/build_iso.sh 1.0`
3. Create VirtualBox VM and attach `output/whacos-1.0-amd64.iso`
4. Boot and install or run live.

## Documentation index

ARCHITECTURE.md; HOWTOBUILD.md; ASSUMPTIONS.md; FILESYSTEM.md; USERS_AND_SECURITY.md; CORE_APPS.md; INPUT.md; VIRTUALBOX.md

## Build prerequisites (summary)

- Ubuntu 24.04 LTS (or Debian 12 / Fedora 40)
- sudo/root access
- ~10 GB free disk space
- Install dependencies: `debootstrap xorriso grub-pc-bin grub-efi-amd64-bin squashfs-tools rsync wget build-essential`

## Project structure (summary)

WHAOS/
├── boot/grub/
├── docs/
├── scripts/
├── src/
│   ├── desktop/
│   ├── init/
│   ├── installer/
│   └── kernel/
└── output/

## SYSTEM OVERVIEW

WHASOS (Work Health and Safety Operating System) is a secure, classified‑grade operating system project designed for integration into a high‑security game environment.

WHASOS combines:
- Workplace Health & Safety compliance infrastructure
- Government‑grade access control systems
- SCP‑style anomaly containment documentation
- Intelligence‑agency‑inspired secure operating architecture

## ACCESS WARNING

This system simulates restricted federal infrastructure. Unauthorized access attempts may trigger system lockdown, activity logging, account suspension, simulated prosecution notices, and clearance revocation. All activity is logged and audited.

## CORE OBJECTIVES

- Build a functional operating system architecture
- Implement multi‑tier clearance authentication
- Create SCP‑style secure documentation systems
- Integrate WHS compliance monitoring modules
- Provide immersive classified UI/UX

## PRIMARY MODULES

- **Clearance Control Subsystem** — Multi‑level authorization; role‑based access; redaction enforcement; session auditing.
- **Secure Containment Database** — SCP‑style registry; classification levels (SAFE / EUCLID / KETER equivalents); incident reporting; redaction engine.
- **Workplace Hazard System** — Risk assessment; hazard reporting; compliance tracking; escalation engine.
- **Security Enforcement Layer** — Intrusion detection; access logging; automatic lockout; tamper detection.

## SYSTEM DESIGN PHILOSOPHY

Engineered around zero‑trust, least privilege, compartmentalized domains, immutable audit logging, and modular extensibility.

## ARCHITECTURE SUMMARY

Layered structure:
1. Kernel Layer
2. System Services Layer
3. Security & Authentication Layer
4. Application Layer (WHS + SCP modules)
5. User Interface Layer

Full technical details: KERNEL_DESIGN.md

## PROJECT STATUS

DEVELOPMENT PHASE: ALPHA — Security architecture defined; kernel structure under development; core modules in planning.

## ROADMAP

- Secure boot environment
- Role‑based UI rendering
- Multiplayer secure terminal network
- Encrypted internal messaging
- AI‑powered anomaly analysis
- Modular update system

## DISCLAIMER

WHASOS is fictional for game integration and experimentation. References to agencies or prosecution are thematic.

## AUTHOR

Nicholas Tritsaris
GitHub: https://github.com/Nicholas-Tritsaris

## License

GPL-2.0 / MIT / BSD where applicable. Not associated with Microsoft.

---

## SEALED ARCHIVE — AUTHORIZED PERSONNEL ONLY

TOP SECRET — Access requires Level 4 clearance and dual‑factor authorization. Viewing, copying, or transmitting any portion of this archive without explicit authorization is prohibited and will be logged.

### SEALED INDEX
- /sealed/ANOMALY_REGISTRY.md
- /sealed/OP_PROTOCOLS/
- /sealed/KEYVAULT/
- /sealed/LOGS/2026-02-28/

### SEALED ENTRY: ANOMALY 0xA7F3
Designation: ███████████
Containment Class: █████ / █████ / █████
Summary: █████████████████████████████████████████████████████████████████████████████████
Observed Effects: ████████████████████████████████████████████████████████████████
Containment Protocol (redacted):
- Step 1: █████████████████████████████
- Step 2: █████████████████████████████
- Emergency Escalation: █████████████████████████████

### SEALED ENTRY: OPERATIONAL KEYS
Key Vault Index: KV-██-2026-02-28
Active Compartment Keys (placeholders):
- COMP-A — XXXX-████-XXXX-████ (access: Level 3+)
- COMP-B — YYYY-████-YYYY-████ (access: Level 4+)
- COMP-C — ZZZZ-████-ZZZZ-████ (access: Level 5; dual sign required)

Key Handling Notes:
- Keys stored in HSM emulation; export prohibited.
- All key usage recorded in sealed/KEYVAULT/USAGE_LOGS.md and signed by two authorized operators.

### SEALED ENTRY: INCIDENT LOG (EXCERPT)
[2026-02-28T20:52:03-05:00] [REDACTED] — Anomaly detection triggered on node: ███-NODE-17
[2026-02-28T20:53:11-05:00] [REDACTED] — Containment protocol initiated; network partition applied
[2026-02-28T20:54:02-05:00] [REDACTED] — Operator authentication failure; escalation to Level 4
[2026-02-28T20:55:12-05:00] [REDACTED] — Evidence snapshot stored in sealed/LOGS/2026-02-28/

### SEALED ENTRY: ENCRYPTED BLOB (SAMPLE)
Blob ID: BLOB-7F-20260228
Cipher: AES-256-GCM (metadata redacted)
Payload (base64 placeholder): U2VhbGVkQmxvYl9QbGFjZWhvbGRlcj0gW1JFREFDVEVEXQ==
Notes: Decryption requires COMP-C and dual operator signature.

### SEALED ENTRY: REDACTION ENGINE RULES
- Documents marked [REDACTED] must be redacted at paragraph and metadata level.
- Automated redaction engine applies pattern rules: PII, geo-coordinates, operational keys, containment vectors.
- Redaction audit trail is immutable and stored in sealed/REDACTION_AUDIT.log.

### SEALED ENTRY: EMERGENCY PROTOCOL SUMMARY
- Trigger Conditions: Unauthorized access to /sealed/ or repeated failed authentications.
- Immediate Actions: Network isolation; session token invalidation; alert to Level 5 operators.
- Recovery: Requires signed approval from two Level 5 operators and validated integrity check of KERNEL_DESIGN.md.

### SEALED MEMO: INTERNAL AUTHORIZATION TEMPLATE
AUTHORIZATION: [TOP SECRET]
APPROVED_BY: [REDACTED]
SIGNATURES_REQUIRED: 2
CLEARANCE_MINIMUM: LEVEL_4
VALID_UNTIL: [REDACTED]
NOTES: All approvals must be recorded in sealed/AUTH_LOGS.md

## SEALING & REDACTION LEGEND
- █████ — Full redaction
- [REDACTED] — Inline redaction marker
- COMP-* — Compartment identifiers
- BLOB-* — Encrypted payload identifiers

END OF SEALED ARCHIVE

END OF FILE
