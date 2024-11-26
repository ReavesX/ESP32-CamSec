#include "sd_utils.h"
#include "esp_camera.h"
#include "esp_log.h"
#include "esp_vfs_fat.h"
#include "sdmmc_card.h"
#include "sdmmc_host.h"
#include <time.h>
#include <stdio.h>
#include <sys/time.h>

static const char *TAG = "camera_sd_utils";

// Manually set the current time (e.g., 2024-11-26 14:30:00 UTC)
void set_time_manually() {
    struct timeval tv;
    tv.tv_sec = 1701004200; // Replace with desired epoch timestamp
    tv.tv_usec = 0;
    settimeofday(&tv, NULL);
    ESP_LOGI(TAG, "Time manually set to: 2024-11-26 14:30:00 UTC");
}

// Initialize the SD card
esp_err_t init_sd_card(void) {
    esp_vfs_fat_sdmmc_mount_config_t mount_config = {
        .format_if_mount_failed = true,
        .max_files = 10,
        .allocation_unit_size = 16 * 1024
    };

    sdmmc_card_t *card;
    sdmmc_host_t host = SDMMC_HOST_DEFAULT();
    sdmmc_slot_config_t slot_config = SDMMC_SLOT_CONFIG_DEFAULT();

    esp_err_t ret = esp_vfs_fat_sdmmc_mount("/sdcard", &host, &slot_config, &mount_config, &card);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Failed to mount filesystem (%s)", esp_err_to_name(ret));
        return ret;
    }

    ESP_LOGI(TAG, "SD card mounted successfully");
    return ESP_OK;
}

void generate_filename(char *buffer, size_t buffer_len) {
    time_t now = time(NULL);
    struct tm timeinfo;
    localtime_r(&now, &timeinfo);

    snprintf(buffer, buffer_len, "/sdcard/%02d-%02d-%02d-%02d.jpeg",
            timeinfo.tm_mon + 1,
            timeinfo.tm_mday,
            timeinfo.tm_hour, 
            timeinfo.tm_sec);
}


// Save a camera frame buffer to the SD card
esp_err_t save_to_sd(camera_fb_t *frame) {
    if (!frame) {
        ESP_LOGE(TAG, "Null frame buffer");
        return ESP_FAIL;
    }

    char filename[32]; // Buffer to hold the filename
    generate_filename(filename, sizeof(filename));

    FILE *file = fopen(filename, "wb");
    if (!file) {
        ESP_LOGE(TAG, "Failed to open file for writing");
        return ESP_FAIL;
    }

    fwrite(frame->buf, 1, frame->len, file); // Write the frame buffer to the file
    fclose(file);

    ESP_LOGI(TAG, "Frame saved: %s", filename);
    return ESP_OK;
}