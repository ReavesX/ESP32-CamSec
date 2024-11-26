#ifndef SD_UTILS_H
#define SD_UTILS_H

#include "esp_err.h"
#include "esp_camera.h" // Include for camera_fb_t

// UART Pins
#define UART_PIN_TXD    1
#define UART_PIN_RXD    3

// Other Common Pins
#define LED_PIN         33  // Onboard LED (built-in flash LED)
#define LED_FLASH_PIN   4   // External LED Flash (optional)

// Camera pins for ESP32-CAM
#define CAM_PIN_PWDN    32  // Power down
#define CAM_PIN_RESET   -1  // Software reset
#define CAM_PIN_XCLK     0
#define CAM_PIN_SIOD    26  // SDA
#define CAM_PIN_SIOC    27  // SCL
#define CAM_PIN_D7      35
#define CAM_PIN_D6      34
#define CAM_PIN_D5      39
#define CAM_PIN_D4      36
#define CAM_PIN_D3      21
#define CAM_PIN_D2      19
#define CAM_PIN_D1      18
#define CAM_PIN_D0       5
#define CAM_PIN_VSYNC   25
#define CAM_PIN_HREF    23
#define CAM_PIN_PCLK    22


// Initialize the SD card
esp_err_t init_sd_card(void);

// Save a camera frame buffer to the SD card
esp_err_t save_to_sd(camera_fb_t *frame);

#endif // SD_UTILS_H