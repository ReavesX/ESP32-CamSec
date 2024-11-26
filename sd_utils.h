#ifndef SD_UTILS_H
#define SD_UTILS_H

#include "esp_err.h"
#include "esp_camera.h" // Include for camera_fb_t

// Initialize the SD card
esp_err_t init_sd_card(void);

// Save raw data to the SD card with a specified path
esp_err_t save_to_sd(const char *path, uint8_t *data, size_t len);

// Save a camera frame buffer to the SD card
esp_err_t save_frame_to_sd(camera_fb_t *frame);

#endif // SD_UTILS_H