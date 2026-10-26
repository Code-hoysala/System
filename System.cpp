#include "system.h"

SystemBridge::SystemBridge(unsigned long baudRate) {
    _baudRate = baudRate;
    _index = 0;
}

void SystemBridge::begin() {
    Serial.begin(_baudRate);
    memset(_buffer, 0, SYSTEM_BUFFER_SIZE);
}

bool SystemBridge::available() {
    while (Serial.available() > 0) {
        char c = Serial.read();
        if (c == '\n' || c == '\r') {
            if (_index > 0) {
                _buffer[_index] = '\0';
                _index = 0;
                return true;
            }
        } else if (_index < SYSTEM_BUFFER_SIZE - 1) {
            _buffer[_index++] = c;
            _buffer[_index] = '\0';
        }
    }
    return false;
}

String SystemBridge::readCommand() {
    return String(_buffer);
}

void SystemBridge::sendResponse(const char* response) {
    Serial.print("[Arduino] ");
    Serial.println(response);
}

void SystemBridge::sendCommand(const char* cmd) {
    Serial.print("[CMD_EXEC] ");
    Serial.println(cmd);
}
