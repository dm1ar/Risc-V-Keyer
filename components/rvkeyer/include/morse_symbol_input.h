#ifndef MORSE_SYMBOL_INPUT_H
#define MORSE_SYMBOL_INPUT_H

#include "log_handler.h"

class MorseSymbolInput {
public:
    MorseSymbolInput(LogHandler* handler);
    void readGPIOKeyer();
    void readWebSocketMessage();
    void readKeyboardUSB();
    void processPaddleMode(int mode);

private:
    LogHandler* logHandler;
};

#endif // MORSE_SYMBOL_INPUT_H
