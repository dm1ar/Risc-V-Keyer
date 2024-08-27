#include "morse_symbol_input.h"

MorseSymbolInput::MorseSymbolInput(LogHandler* handler) : logHandler(handler) {}

void MorseSymbolInput::readGPIOKeyer() {
    logHandler->log(LogLevel::info, "GPIO keyer read (stub)");
}

void MorseSymbolInput::readWebSocketMessage() {
    logHandler->log(LogLevel::info, "WebSocket message read (stub)");
}

void MorseSymbolInput::readKeyboardUSB() {
    logHandler->log(LogLevel::info, "Keyboard USB input read (stub)");
}

void MorseSymbolInput::processPaddleMode(int mode) {
    logHandler->log(LogLevel::info, "Paddle mode processed (stub)");
}
