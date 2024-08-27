#ifndef MORSE_OUTPUT_H
#define MORSE_OUTPUT_H

#include "log_handler.h"

class MorseOutput {
public:
    MorseOutput(LogHandler* handler);
    void outputAnalogGPIO();
    void outputKeyerGPIO();
    void outputWebSocket();
    void setVolume(float volume);

private:
    LogHandler* logHandler;
};

#endif // MORSE_OUTPUT_H
