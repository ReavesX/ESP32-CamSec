#include "camera_utils.c"
#include "sd_utils.h"
#include "esp_log.h"
#include "esp_system.h"


void app_main() {
    // Set the time manually for offline scenarios
    set_time_manually();

    // Initialize the SD card
    if (init_sd_card() != ESP_OK) {
        ESP_LOGE(TAG, "SD card initialization failed");
        return;
    }

    // Camera configuration
    camera_config_t config = {
        .pin_pwdn = -1,
        .pin_reset = -1,
        .pin_xclk = 0,
        .pin_sscb_sda = 26,
        .pin_sscb_scl = 27,
        .pin_d7 = 35,
        .pin_d6 = 34,
        .pin_d5 = 39,
        .pin_d4 = 36,
        .pin_d3 = 21,
        .pin_d2 = 19,
        .pin_d1 = 18,
        .pin_d0 = 5,
        .pin_vsync = 25,
        .pin_href = 23,
        .pin_pclk = 22,
        .xclk_freq_hz = 20000000,
        .ledc_timer = LEDC_TIMER_0,
        .ledc_channel = LEDC_CHANNEL_0,
        .pixel_format = PIXFORMAT_JPEG, // JPEG output
        .frame_size = FRAMESIZE_UXGA,   // Set desired frame size
        .jpeg_quality = 10,            // Quality (lower = better)
        .fb_count = 2                  // Frame buffers
    };

    // Initialize the camera
    if (esp_camera_init(&config) != ESP_OK) {
        ESP_LOGE(TAG, "Camera initialization failed");
        return;
    }

    // Capture a frame
    camera_fb_t *frame = esp_camera_fb_get();
    if (!frame) {
        ESP_LOGE(TAG, "Failed to capture frame");
        return;
    }

    // Save the frame to the SD card
    if (save_frame_to_sd(frame) != ESP_OK) {
        ESP_LOGE(TAG, "Failed to save frame");
    }

    // Free the frame buffer
    esp_camera_fb_return(frame);

    ESP_LOGI(TAG, "Done!");
}