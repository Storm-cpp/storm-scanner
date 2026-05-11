# 🛰️ Storm Port Scanner v1.0

<p align="center">
  <img src="https://img.shields.io/badge/Security-Audit_Tool-red?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white" />
  <img src="https://img.shields.io/badge/OS-Linux-f05032?style=for-the-badge&logo=linux&logoColor=white" />
  <img src="https://img.shields.io/badge/Verified-GPG-blueviolet?style=for-the-badge" />
</p>

## 🛡️ Overview
**Storm Port Scanner** is a high-performance network security utility written in C++. It leverages low-level socket programming to perform rapid security audits on local or remote hosts. This tool is designed for security researchers and system administrators to identify exposed services and potential attack vectors.

> [!IMPORTANT]
> **Identity Verification:** All commits in this repository are cryptographically signed using GPG to ensure code integrity.

## ☣️ Key Features
- **Raw Socket Integration:** Direct communication with the networking stack via `sys/socket.h`.
- **Customizable Scan:** Easily modify the target ports for specialized audits.
- **Optimized Timeouts:** Implemented connection timeouts to prevent hanging on filtered ports.
- **Zero Dependencies:** Compiles with standard C++ libraries, ensuring portability across Linux distributions.

---

## 🚀 Installation & Setup

Follow these steps to deploy the scanner on your environment (Optimized for **Arch Linux**).

### 1. Prerequisites
Ensure you have the GNU Compiler Collection (**GCC**) installed:
```bash
sudo pacman -S gcc make git


2. Clone the Repository
Clone via SSH for a secure connection:

Bash
git clone git@github.com:Storm-cpp/storm-scanner.git
cd storm-scanner


3. Compilation
Build the binary using g++ with the following flags:

Bash
g++ -O3 port_scanner.cpp -o storm-scanner


4. Running the Audit
Execute the compiled binary:

Bash
./storm-scanner
