# system

`system` is a lightweight, non-blocking Arduino library that establishes a reliable communication bridge between microcontrollers and host system environments (such as Windows Command Prompt or PowerShell via Serial).

## Features
- **Serial Token Parser:** Safely reads and buffers incoming newline-terminated strings without blocking core loop operations.
- **Host Feedback API:** Standardized response wrappers (`sendResponse` and `sendCommand`) for logging and bidirectional terminal sync.
- **Zero Memory Overhead:** Built entirely with static buffers (`malloc`-free), perfectly optimized for resource-constrained AVR and ARM microcontrollers.

---

## Hardware & System Requirements
- **Microcontroller:** Arduino Uno, Mega, or any USB-serial capable board.
- **Host Environment:** Windows CMD / PowerShell communicating over the designated Serial COM port.

---

## Quick Start Example

```cpp
#include <system.h>

SystemBridge cmdBridge(9600);

void setup() {
    cmdBridge.begin();
    cmdBridge.sendResponse("Bridge Ready.");
}

void loop() {
    if (cmdBridge.available()) {
        String incoming = cmdBridge.readCommand();
        if (incoming == "TOGGLE") {
            // Perform action
            cmdBridge.sendResponse("Action Executed!");
        }
    }
}
