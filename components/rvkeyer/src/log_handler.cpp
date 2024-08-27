/*
 * LogHandler - Handles logging for RVKeyer using FreeRTOS queues
 * 
 * Author: Dr. Axel Richter, DM1AR
 * Date: 2024-08-22
 * License: MIT
 *
 * Description:
 * This source file implements the LogHandler class, managing logging
 * using FreeRTOS queues for inter-task communication.
 */

#include "log_handler.h"
#include <iostream>

LogHandler::LogHandler() {
    // Create a queue to hold log messages
    logQueue = xQueueCreate(25, sizeof(LogMessage));  // 25 messages max, each of size LogMessage

    // Create a task to process log messages
    xTaskCreate(LogHandler::logTask, "LogTask", 2048, this, 1, nullptr);
}

void LogHandler::log(LogLevel level, const char* message) {
    LogMessage logMessage;
    logMessage.level = level;
    logMessage.message = message;

    // Send the log message to the queue
    if (xQueueSend(logQueue, &logMessage, 0) != pdPASS) {
        // Handle the case where the queue is full (e.g., by dropping the message)
    }
}

void LogHandler::logTask(void* pvParameters) {
    LogHandler* logHandler = static_cast<LogHandler*>(pvParameters);
    LogMessage logMessage;

    while (true) {
        // Wait for a log message to be received
        if (xQueueReceive(logHandler->logQueue, &logMessage, portMAX_DELAY) == pdPASS) {
            switch (logMessage.level) {
                case LogLevel::verbose:
                    std::cout << "[verbose] " << logMessage.message << std::endl;
                    break;
                case LogLevel::info:
                    std::cout << "[info] " << logMessage.message << std::endl;
                    break;
                case LogLevel::warning:
                    std::cout << "[warning] " << logMessage.message << std::endl;
                    break;
                case LogLevel::error:
                    std::cout << "[error] " << logMessage.message << std::endl;
                    break;
                case LogLevel::fatal:
                    std::cout << "[fatal] " << logMessage.message << std::endl;
                    break;
                default:
                    // Handle unexpected log levels
                    break;
            }
        }
    }
}
