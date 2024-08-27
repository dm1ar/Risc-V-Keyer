#include "morse_decode.h"

MorseDecode::MorseDecode(LogHandler* handler) : logHandler(handler) {}

void MorseDecode::decodeMessage(const char* input) {
    logHandler->log(LogLevel::info, "Morse message decoded (stub)");
}

void MorseDecode::replayMessage() {
    logHandler->log(LogLevel::info, "Morse message replayed (stub)");
}
