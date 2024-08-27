#ifndef WATCH_DOG_TIMER_H
#define WATCH_DOG_TIMER_H

#include "log_handler.h"

class WatchDogTimer {
public:
    WatchDogTimer(LogHandler* handler);
    void startTimer();
    void resetTimer();
    void
