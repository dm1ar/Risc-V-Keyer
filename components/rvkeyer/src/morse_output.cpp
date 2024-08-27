#include "morse_output.h"

MorseOutput::MorseOutput(LogHandler* handler) : logHandler(handler) {}

void MorseOutput::outputAnalogGPIO() {
    logHandler->log(LogLevel::info, "Analog GPIO output (stub)");
}

void MorseOutput::outputKeyerGPIO() {
    logHandler->log(LogLevel::info, "Keyer GPIO output (stub)");
}

void MorseOutput::outputWebSocket() {
    logHandler->log(LogLevel::info, "WebSocket output (stub)");
}

void MorseOutput::setVolume(float volume) {
    logHandler->log(LogLevel::info, "Volume set (stub)");
}
