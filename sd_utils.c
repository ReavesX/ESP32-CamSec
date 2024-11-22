#include "sd_utils.h"
#include "esp_log.h"
#include "esp_vfs_fat.h"
#include "sdmmc_card.h"
#include "sdmmc_host.h"

static const char *TAG = "sd_utils";


esp_err_t init_sd_card(void){
    esp_vfs_fat_sdmmc_mount_config_t mount_config = 
        {
        .format_if_mount_failed = true,
        .max_files = 10,
        .allocation_unit_size  = 16 * 102
        };
    
    sdmmc_card_t card;
    sdmmc_host_t host = SDMMC_HOST_DEFAULT();
    sdmmc_slot_config_t slot_config = SDMMC_SLOT_CONFIG_DEFAULT();

    
    esp_err_t ret = esp_vfs_fat_sdmmc_mount("/sdcard", &host, &slot_config, &mount_config, &card);
    if (ret != ESP_OK) 
    {
        ESP_LOGE(TAG, "Failed to mount filesystem (%s)", esp_err_to_name(ret));
        return ret;
    }
    
     return ESP_OK;

    }

esp_err_t save_to_sd(const char *path, uint8_t *data, size_t len) {
    FILE *file = fopen(path, "wb");
    if (!file) {
        ESP_LOGE(TAG, "Failed to open file for writing");
        return ESP_FAIL;
    }

    fwrite(data, 1, len, file);
    fclose(file);
    return ESP_OK;
}