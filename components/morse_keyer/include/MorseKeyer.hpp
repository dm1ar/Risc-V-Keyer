// File: MorseKeyer.hpp
// Author: Dr. Axel Richter
// Date of Creation: 2024-08-26
// License: MIT License

#ifndef MORSE_KEYER_HPP
#define MORSE_KEYER_HPP

#include <cstdint>
#include <string>

/**
 * @class MorseKeyer
 * @brief Handles Morse code keying logic, including timing and keyer configuration.
 */
class MorseKeyer {
public:
    /**
     * @brief Constructor for MorseKeyer.
     * Initializes the keyer with default settings.
     */
    MorseKeyer();

    /**
     * @brief Initializes the keyer hardware and software settings.
     */
    void initialize();

    /**
     * @brief Sends Morse code based on the input string.
     * @param text The text to be converted to Morse code.
     */
    void sendMorse(const std::string& text);

    /**
     * @brief Sets the speed of the Morse keyer in words per minute.
     * @param wpm Words per minute.
     */
    void setWPM(uint8_t wpm);

private:
    uint8_t wpm_;  ///< Words per minute setting for the keyer.

    /**
     * @brief Handles the transmission of a dot in Morse code.
     */
    void dot();

    /**
     * @brief Handles the transmission of a dash in Morse code.
     */
    void dash();

    /**
     * @brief Handles the space between Morse code elements.
     */
    void space();
};

#endif // MORSE_KEYER_HPP
