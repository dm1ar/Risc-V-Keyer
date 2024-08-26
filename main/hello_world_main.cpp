#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <iostream>
#include <sstream>
#include "esp_log.h"
#include "esp_system.h"

// Define a logging tag
static const char *TAG = "HelloWorldTask";

// HelloWorldTask class
class HelloWorldTask {
public:
    HelloWorldTask(const std::string &taskName, uint32_t stackSize, UBaseType_t priority)
        : m_taskName(taskName), m_stackSize(stackSize), m_priority(priority), m_taskHandle(nullptr) {
        // Create the FreeRTOS task
        xTaskCreate(
            taskFunctionWrapper,
            m_taskName.c_str(),
            m_stackSize,
            this, // Pass the current instance as the task parameter
            m_priority,
            &m_taskHandle
        );
    }

    // Static wrapper function to call the actual task function
    static void taskFunctionWrapper(void *pvParameters) {
        static_cast<HelloWorldTask *>(pvParameters)->taskFunction();
    }

    // The actual task function
    void taskFunction() {
        while (true) {
            displayMessage();
            vTaskDelay(pdMS_TO_TICKS(2000)); // Delay for 2 seconds
        }
    }

private:
    // Function to display the message with a timestamp
    void displayMessage() const {
        // Get the current time in milliseconds
        uint32_t currentTime = esp_log_timestamp();

        // Format the message
        std::ostringstream oss;
        oss << "Hello World - Timestamp: " << currentTime << " ms";

        // Log the message to the serial output
        ESP_LOGI(TAG, "%s", oss.str().c_str());
    }

private:
    std::string m_taskName;   // Task name
    uint32_t m_stackSize;     // Stack size
    UBaseType_t m_priority;   // Task priority
    TaskHandle_t m_taskHandle; // Task handle
};

// Main entry point
extern "C" void app_main() {
    // Instantiate the HelloWorldTask object
    HelloWorldTask helloWorldTask("HelloWorldTask", 2048, tskIDLE_PRIORITY + 1);

    // app_main does not return and the tasks run indefinitely.
}

