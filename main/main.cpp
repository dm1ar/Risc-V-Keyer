#include "rvkeyer.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// Task Handles
TaskHandle_t keyingTaskHandle = NULL;
TaskHandle_t morseInputTaskHandle = NULL;
TaskHandle_t morseOutputTaskHandle = NULL;

// Task Functions
void keyingTask(void *pvParameters) {
    RVKeyer *keyer = static_cast<RVKeyer *>(pvParameters);
    keyer->startKeying();
    vTaskDelete(NULL);  // Delete task when finished
}

void morseInputTask(void *pvParameters) {
    RVKeyer *keyer = static_cast<RVKeyer *>(pvParameters);
    keyer->handleMorseInput();
    vTaskDelete(NULL);  // Delete task when finished
}

void morseOutputTask(void *pvParameters) {
    RVKeyer *keyer = static_cast<RVKeyer *>(pvParameters);
    keyer->processMorseOutput();
    vTaskDelete(NULL);  // Delete task when finished
}

extern "C" void app_main() {
    // Initialize RVKeyer
    RVKeyer keyer;
    keyer.initializeSystem();

    // Create FreeRTOS tasks for keying, input, and output
    xTaskCreate(&keyingTask, "Keying Task", 2048, &keyer, 5, &keyingTaskHandle);
    xTaskCreate(&morseInputTask, "Morse Input Task", 2048, &keyer, 5, &morseInputTaskHandle);
    xTaskCreate(&morseOutputTask, "Morse Output Task", 2048, &keyer, 5, &morseOutputTaskHandle);

    // Start the FreeRTOS scheduler (tasks will run immediately)
    vTaskStartScheduler();
}
