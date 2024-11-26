#ifndef UART_UTILS_H
#define UART_UTILS_H

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


void uart_init(void);

static void rx_task(void *arg); /* Task To be completed 
                                when received uart instructions
                                */


#endif // UART_UTILS_H