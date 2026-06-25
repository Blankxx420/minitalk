# Minitalk - @42

<p align="center">
  <img src="https://img.shields.io/badge/Score-125%2F100-success?style=for-the-badge&logo=42" alt="Score 42">
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c" alt="Language C">
</p>

## 📝 Overview

**Minitalk** is a 42 School project designed to create a small data transmission program using **UNIX signals**. The purpose of this project is to build a client-server architecture where the client can send a string of characters to the server, which then decodes and displays it in real-time.

The core challenge revolves around bitwise operations, process synchronization, and inter-process communication (IPC) using only two basic signals: `SIGUSR1` and `SIGUSR2`.

## 🌟 Features & Bonus Included

* **Bit-by-Bit Transmission:** Characters are broken down into 8 bits and sent sequentially across processes.
* **Fast & Reliable:** Optimized signal handling to ensure no data corruption or lost bits during transmission.
* **✨ Bonus Part (Acknowledgments):** The server sends a confirmation signal back to the client for every received bit/character, and a final acknowledgment once the entire string has been fully printed.
* **✨ Unicode Support:** Full support for UTF-8 characters (emojis, accents, non-Latin alphabets).

## 📐 How it Works

Because UNIX signals are volatile and asynchronous, the communication follows a strict protocol:
1. The **Server** starts up and displays its unique **PID** (Process ID).
2. The **Client** takes the Server's PID and the string to send as arguments.
3. The Client loops through every character, converts it to bits, and sends:
   * `SIGUSR1` to represent a `0`
   * `SIGUSR2` to represent a `1`
4. The **Server** catches the signals, reconstructs the bytes, and prints the message once a null-terminator `\0` is reached.

## 🚀 Installation & Usage

### Compilation
To compile both the `server` and `client` binaries, run the following command at the root of the repository:

```bash
make
