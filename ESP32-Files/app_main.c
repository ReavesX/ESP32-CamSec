#include "esp_log.h"
#include "camera_utils.h"
#include "sd_utils.h"

static const char *TAG = "main";

void set_time_manually() {
    struct timeval tv;
    tv.tv_sec = 1701004200; // Example: 2024-11-26 14:30:00 UTC
    tv.tv_usec = 0;
    settimeofday(&tv, NULL);
    ESP_LOGI(TAG, "Time manually set");
}

void app_main() {
    uint8_t data[128];  // Buffer to store received data

    while (1) {
        // Initialize Camera
        if (init_camera() != ESP_OK) {
            ESP_LOGE(TAG, "Failed to initialize camera");
            return;
        }
        
        // Initialize SD card
        if (init_sd_card() != ESP_OK) {
            ESP_LOGE(TAG, "Failed to initialize SD card");
            return;
        }

        // Set the system time manually (offline scenario)
        set_time_manually();

        // Receive data and process it
        int len = uart_receive(data, sizeof(data), 100);  // 100ms timeout
        
        if (len == 0) {
            ESP_LOGI("UART", "No data received within timeout.");}
        
        elif (len == 5 ){
            // Capture a frame
            camera_fb_t *frame = snap_picture();
            if (!frame) {
                ESP_LOGE(TAG, "Failed to capture frame");
                    return;
            }

            // Save the frame to SD card
            if (save_to_sd(frame) != ESP_OK) {
                    ESP_LOGE(TAG, "Failed to save frame to SD card");
            }

            // Return the frame buffer
            release_picture(frame);
            ESP_LOGI(TAG, "Application completed successfully"); }


            vTaskDelay(100 / portTICK_PERIOD_MS);  // Delay to prevent CPU overload
        }

    


   
}