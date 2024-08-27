/*
 * LogHandler - Handles logging for RVKeyer using FreeRTOS queues
 * 
 * Author: Dr. Axel Richter, DM1AR
 * Date: 2024-08-22
 * License: MIT
 *
 * Description:
 * This header file defines the LogHandler class, which manages logging
 * using FreeRTOS queues for inter-task communication.
 */

#ifndef LOG_HANDLER_H
#define LOG_HANDLER_H

#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
#include "freertos/task.h"

enum class LogLevel {
    verbose,
    info,
    warning,
    error,
    fatal
};

struct LogMessage {
    LogLevel level;
    const char* message;
};

class LogHandler {
public:
    LogHandler();
    void log(LogLevel level, const char* message);
    static void logTask(void* pvParameters);

private:
    QueueHandle_t logQueue;
};

#endif // LOG_HANDLER_H
