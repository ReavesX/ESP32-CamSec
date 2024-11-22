#ifndef SD_UTILS_H
#define SD_UTILS_H

#include "esp_log.h"
#include "esp_err.h"
#include "driver/gpio.h"
#include "driver/sdmmc.h"
#include "camera_utils.h" // If you're using camera types here

esp_err_t init_sd_card(void);
void save_image_to_sd(camera_fb_t *pic);

#endif // SD_UTILS_H