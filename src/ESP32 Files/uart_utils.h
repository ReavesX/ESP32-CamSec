#ifndef UART_UTILS_H
#define UART_UTILS_H

#include "esp_err.h"
#include "driver/uart.h"
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// UART Pins
#define UART_PIN_TXD    1   // Transmit pin for UART
#define UART_PIN_RXD    3   // Receive pin for UART

// Other Common Pins
#define LED_PIN         33  // Onboard LED (built-in flash LED)
#define LED_FLASH_PIN   4   // External LED Flash (optional)

// Camera pins for ESP32-CAM (if applicable)
#define CAM_PIN_PWDN    32  // Power down pin
#define CAM_PIN_RESET   -1  // Software reset pin
#define CAM_PIN_XCLK     0  // XCLK pin for camera
#define CAM_PIN_SIOD    26  // SDA pin for camera
#define CAM_PIN_SIOC    27  // SCL pin for camera
#define CAM_PIN_D7      35  // Camera data pin D7
#define CAM_PIN_D6      34  // Camera data pin D6
#define CAM_PIN_D5      39  // Camera data pin D5
#define CAM_PIN_D4      36  // Camera data pin D4
#define CAM_PIN_D3      21  // Camera data pin D3
#define CAM_PIN_D2      19  // Camera data pin D2
#define CAM_PIN_D1      18  // Camera data pin D1
#define CAM_PIN_D0       5  // Camera data pin D0
#define CAM_PIN_VSYNC   25  // Camera VSYNC pin
#define CAM_PIN_HREF    23  // Camera HREF pin
#define CAM_PIN_PCLK    22  // Camera PCLK pin

// UART Functions
void init_uart(void);  // Initialize UART settings
void uart_receive(void);  // Task to read and process data from UART

#endif // UART_UTILS_H
