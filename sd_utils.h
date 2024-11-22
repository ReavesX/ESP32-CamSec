#ifndef SD_UTILS_H
#define SD_UTILS_H

#include "esp_err.h"

esp_err_t init_sd_card(void);
esp_err_t save_to_sd(const char *path, uint8_t *data, size_t len);

#endif // SD_UTILS_H
