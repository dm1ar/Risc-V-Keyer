/*
 * RVKeyer - A Morse Code Keyer System for ESP32
 * 
 * Author: Dr. Axel Richter, DM1AR
 * Date: 2024-08-22
 * License: MIT
 *
 * Description:
 * This header file defines the RVKeyer class, which manages the
 * overall system initialization, keying, Morse code input/output,
 * decoding, and parameter management for the Morse code keyer.
 */

#ifndef RVKEYER_H
#define RVKEYER_H

#include "esp32_init.h"
#include "morse_symbol_input.h"
#include "morse_output.h"
#include "morse_decode.h"
#include "dynset.h"
#include "shutdown.h"
#include "log_handler.h"
#include "watch_dog_timer.h"

class RVKeyer {
public:
    void initializeSystem();
    void startKeying();
    void handleMorseInput();
    void processMorseOutput();
    void shutdownSystem();
    void decodeMorse();
    void dynamicallySetParameters();

private:
    ESP32Init esp32Init;
    MorseSymbolInput morseSymbolInput;
    MorseOutput morseOutput;
    MorseDecode morseDecode;
    DynSet dynSet;
    Shutdown shutdown;
    LogHandler logHandler;
    WatchDogTimer watchDogTimer;
};

#endif // RVKEYER_H
