#ifndef ESP32_CAMERA_H
#define ESP32_CAMERA_H  


#include <esp_camera.h>
#include <esp_err.h>


esp_err_t init_camera(void); // Initializes the ESP32 Camera with default config. -- "ESP_OK" on success and "ESP_FAIl" on fail

camera_fb_t* snap_picture(void); // this function will capture a single photo -- returns pointer ot the frame buffer or null on failure.

void release_picture(camera_fb_t* fb); // releases the frame buffer so it can be viewed.

#endif


