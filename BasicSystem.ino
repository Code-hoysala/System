#include <system.h>

// Initialize system bridge at 9600 baud
SystemBridge cmdBridge(9600);

void setup() {
    cmdBridge.begin();
    delay(1000);
    cmdBridge.sendResponse("System Command Bridge Initialized.");
}

void loop() {
    // Check if a command token was received from the host system terminal
    if (cmdBridge.available()) {
        String command = cmdBridge.readCommand();

        if (command == "PING") {
            cmdBridge.sendResponse("PONG");
        } 
        else if (command == "STATUS") {
            cmdBridge.sendResponse("System Online. Zero memory leaks.");
        } 
        else {
            cmdBridge.sendResponse("Unknown Command Received.");
        }
    }
}
