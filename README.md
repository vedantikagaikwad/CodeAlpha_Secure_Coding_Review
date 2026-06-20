# CodeAlpha_Secure_Coding_Review

## 1. Project Overview & Scope
* **Language Audited:** C  
* **Target Issue:** Memory safety and boundary checking flaws.  
* **Objective:** Perform a manual code review and static analysis on a sample login validation script to uncover vulnerabilities, document threats, and implement secure coding remedies.



## 2. Code Review & Vulnerability Assessment

### Identified Vulnerability
During the security assessment of `vulnerable_code.c`, a critical vulnerability was identified at the user input interface: `gets(password);`.

* **Vulnerability Class:** Buffer Overflow (CWE-120: Buffer Copy without Checking Size of Input)
* **Severity:** 🔴 **Critical**
* **Technical Details:** The application allocates a fixed buffer space of 10 bytes (`char password[10];`). The function `gets()` reads input streaming from standard input until a newline character is pressed, entirely failing to validate the input size against the designated buffer boundary.
* **Potential Threat/Impact:** If an attacker enters an input longer than 9 characters, the surplus data spills into adjacent memory spaces on the stack. This can overwrite the stack frame's return address, corrupt control flow, crash the application (Denial of Service), or open pathways for execution of arbitrary malicious payloads.

---

## 3. Tool & Manual Inspection Output
Running standard static analyzer patterns checks flags the following alert:
> **Warning (High Severity):** Function `gets()` is unsafe, deprecated, and completely missing boundary controls. Replace immediately with size-bounded input constraints.

---

## 4. Secure Remediation & Mitigations

### Implemented Fix
The codebase has been refactored in `remediated_code.c` to handle inputs safely. 

1. **Replaced `gets()` with `fgets()`:** `fgets(password, sizeof(password), stdin)` mandates that the application reads a maximum volume matching the exact limit of the array, neutralizing buffer overruns completely.
2. **Defensive Input Handling:** Built dynamic tracking utilizing `sizeof()` parameters so that memory parameters adapt safely without risky hardcoded values.

---

## 5. Summary of Repository Deliverables
* `vulnerable_code.c` - Source code illustrating the active memory boundary risk.
* `remediated_code.c` - Patched source code enforcing secure bounded arrays.
* `README.md` - Complete documentation analysis.
