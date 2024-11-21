#ifndef ESP32_CAMERA_H
#define ESP32_CAMERA_H  


#include <esp_camera.h>
#include <esp_err.h>


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



esp_err_t init_camera(void); // Initializes the ESP32 Camera with default config. -- "ESP_OK" on success and "ESP_FAIl" on fail

camera_fb_t* snap_picture(void); // this function will capture a single photo -- returns pointer to the frame buffer or null on failure.

void release_picture(camera_fb_t* fb); // releases the frame buffer so it can be viewed. -- fb points to the frame to frame buffer

#endif


