#ifndef ESP32_INIT_H
#define ESP32_INIT_H

#include "log_handler.h"

class ESP32Init {
public:
    void initGPIO();
    void initWiFi();
    void initBluetooth();
    void initNetSocket();
    void initWatchDogTimer();

private:
    LogHandler* logHandler;
};

#endif // ESP32_INIT_H
