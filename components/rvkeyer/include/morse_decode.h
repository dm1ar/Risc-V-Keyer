#ifndef MORSE_DECODE_H
#define MORSE_DECODE_H

#include "log_handler.h"

class MorseDecode {
public:
    MorseDecode(LogHandler* handler);
    void decodeMessage(const char* input);
    void replayMessage();

private:
    LogHandler* logHandler;
};

#endif // MORSE_DECODE_H
