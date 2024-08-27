// Include necessary headers
#include <stdint.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "esp_timer.h"

// GPIO Input Pins
#define GPIO_INPUT_DIT 10
#define GPIO_INPUT_DAH 11

// Debounce time in milliseconds
#define DEBOUNCE_TIME_MS 3

// Global variables to track time and queue
static int64_t press_start_time = 0;
static QueueHandle_t gpio_evt_queue = nullptr;
static const char* TAG = "rvkeyer";

// ISR Handler
static void IRAM_ATTR gpio_isr_handler(void* arg) {
    uint32_t gpio_num = (uint32_t)arg;
    xQueueSendFromISR(gpio_evt_queue, &gpio_num, nullptr);
}

void app_main() {
    // Configure GPIOs for input with pull-up resistors
    gpio_config_t io_conf = {};
    io_conf.intr_type = GPIO_INTR_ANYEDGE; // Interrupt on both rising and falling edges
    io_conf.mode = GPIO_MODE_INPUT;
    io_conf.pin_bit_mask = (1ULL << GPIO_INPUT_DIT) | (1ULL << GPIO_INPUT_DAH);
    io_conf.pull_up_en = GPIO_PULLUP_ENABLE;
    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    gpio_config(&io_conf);

    // Create queue to handle GPIO events
    gpio_evt_queue = xQueueCreate(10, sizeof(uint32_t));
    gpio_install_isr_service(0);
    gpio_isr_handler_add(static_cast<gpio_num_t>(GPIO_INPUT_DIT), gpio_isr_handler, (void*)GPIO_INPUT_DIT);
    gpio_isr_handler_add(static_cast<gpio_num_t>(GPIO_INPUT_DAH), gpio_isr_handler, (void*)GPIO_INPUT_DAH);

    // Task to handle GPIO events
    xTaskCreate([](void* arg) {
        uint32_t io_num;
        for(;;) {
            if(xQueueReceive(gpio_evt_queue, &io_num, portMAX_DELAY)) {
                int64_t current_time = esp_timer_get_time();
                int64_t press_duration_ms = 0;

                // Handle the rising or falling edge
                if (gpio_get_level((gpio_num_t)io_num) == 0) {
                    // Button press detected (falling edge)
                    press_start_time = current_time;
                } else {
                    // Button release detected (rising edge)
                    press_duration_ms = (current_time - press_start_time) / 1000; // Convert to ms
                    if (press_duration_ms >= DEBOUNCE_TIME_MS) {
                        ESP_LOGI(TAG, "GPIO[%lu] pressed for %lld ms", io_num, press_duration_ms);
                    }
                }
            }
        }
    }, "gpio_task", 2048, nullptr, 10, nullptr);
}
