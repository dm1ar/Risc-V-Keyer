#include "watch_dog_timer.h"

WatchDogTimer::WatchDogTimer(LogHandler* handler) : logHandler(handler) {}

void WatchDogTimer::startTimer() {
    logHandler->log(LogLevel::info, "WatchDog timer started (stub)");
}

void WatchDogTimer::resetTimer() {
    logHandler->log(LogLevel::info, "WatchDog timer reset (stub)");
}

void WatchDogTimer::checkTaskHealth() {
    logHandler->log(LogLevel::info, "Task health checked (stub)");
}
