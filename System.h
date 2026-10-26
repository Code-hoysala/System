#ifndef SYSTEM_CMD_H
#define SYSTEM_CMD_H

#include <Arduino.h>

#define SYSTEM_BUFFER_SIZE 64

class SystemBridge {
public:
    SystemBridge(unsigned long baudRate = 9600);
    
    void begin();
    bool available();
    String readCommand();
    
    // Send feedback or formatted commands back to host terminal
    void sendResponse(const char* response);
    void sendCommand(const char* cmd);

private:
    unsigned long _baudRate;
    char _buffer[SYSTEM_BUFFER_SIZE];
    uint8_t _index;
};

#endif
