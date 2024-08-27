#include "esp32_init.h"

ESP32Init::ESP32Init(LogHandler* handler) : logHandler(handler) {}

void ESP32Init::initGPIO() {
    logHandler->log(LogLevel::info, "GPIO initialized (stub)");
}

void ESP32Init::initWiFi() {
    logHandler->log(LogLevel::info, "WiFi initialized (stub)");
}

void ESP32Init::initBluetooth() {
    logHandler->log(LogLevel::info, "Bluetooth initialized (stub)");
}

void ESP32Init::initNetSocket() {
    logHandler->log(LogLevel::info, "NetSocket initialized (stub)");
}

void ESP32Init::initWatchDogTimer() {
    logHandler->log(LogLevel::info, "WatchDog Timer initialized (stub)");
}
