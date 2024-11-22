#include "camera.h"
#include <esp_log.h>
#include <driver/uart.h>


static const char* TAG = "camera"; // immutable (unchangeable) object representing the camera


static camera_config_t camera_config = {

    // Pins for camera functions
    .pin_pwdn = CAM_PIN_PWDN,
    .pin_reset = CAM_PIN_RESET,
    .pin_xclk = CAM_PIN_XCLK,
    .pin_sscb_sda = CAM_PIN_SIOD,
    .pin_sscb_scl = CAM_PIN_SIOC,
    

    // data pins 
    .pin_d7 = CAM_PIN_D7,
    .pin_d6 = CAM_PIN_D6,
    .pin_d5 = CAM_PIN_D5,
    .pin_d4 = CAM_PIN_D4,
    .pin_d3 = CAM_PIN_D3,
    .pin_d2 = CAM_PIN_D2,
    .pin_d1 = CAM_PIN_D1,
    .pin_d0 = CAM_PIN_D0,
    .pin_vsync = CAM_PIN_VSYNC,
    .pin_href = CAM_PIN_HREF,
    .pin_pclk = CAM_PIN_PCLK,

    // settings for the clock
    .xclk_freq_hz = 20000000,           // 20MHz XCLK 
    .ledc_timer = LEDC_TIMER_0,
    .ledc_channel = LEDC_CHANNEL_0,



    // settings for the camera's picture. 
    .pixel_format = PIXFORMAT_JPEG,     // JPEG format
    .frame_size = FRAMESIZE_VGA,        // VGA (640x480)
    .jpeg_quality = 12,                 // 0-63 lower means higher quality
    .fb_count = 2                       // Number of frame buffers to allocate
};