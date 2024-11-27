#include "esp_log.h"
#include "camera_utils.h"
#include "sd_utils.h"
#include "uart_utils.h"  // Ensure this is included for UART functionality

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
    bool capture_enabled = false;  // State to track if capture is active

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

    ESP_LOGI(TAG, "Initialization complete. Entering main loop.");

    while (1) {
        // Receive data over UART
        int len = uart_receive(data, sizeof(data), 100);  // 100ms timeout

        if (len > 0) {
            data[len] = '\0';  // Null-terminate the received data for string comparison

            if (strcmp((char *)data, "START") == 0) {
                capture_enabled = true;
                ESP_LOGI(TAG, "Received 'START' command. Capturing enabled.");
            } else if (strcmp((char *)data, "STOP") == 0) {
                capture_enabled = false;
                ESP_LOGI(TAG, "Received 'STOP' command. Capturing disabled.");
            } else {
                ESP_LOGW(TAG, "Unexpected command received: %s", (char *)data);
            }
        }

        // If capturing is enabled, capture and save frames
        if (capture_enabled) {
            ESP_LOGI(TAG, "Capturing frame...");

            // Capture a frame
            camera_fb_t *frame = snap_picture();
            if (!frame) {
                ESP_LOGE(TAG, "Failed to capture frame");
                continue;  // Retry in the next loop iteration
            }

            // Save the frame to SD card
            if (save_to_sd(frame) == ESP_OK) {
                ESP_LOGI(TAG, "Frame saved successfully to SD card.");
            } else {
                ESP_LOGE(TAG, "Failed to save frame to SD card.");
            }

            // Return the frame buffer
            release_picture(frame);

            // Add a delay to prevent capturing too frequently
            vTaskDelay(1000 / portTICK_PERIOD_MS);  // 1-second delay
        } else {
            // If not capturing, just add a small delay to avoid busy-looping
            vTaskDelay(100 / portTICK_PERIOD_MS);
        }
    }
}
