#include <esp_log.h>
#include <esp_system.h>
#include <nvs_flash.h>
#include <sys/param.h>
#include <string.h>
#include <driver/uart.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// support IDF 5.x
#ifndef portTICK_RATE_MS
#define portTICK_RATE_MS portTICK_PERIOD_MS
#endif

#include "esp_camera.h"

#define BOARD_ESP32_AITHINKER 1

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
    .xclk_freq_hz = 10000000,           // 10MHz XCLK for double fps according to example found.
    .ledc_timer = LEDC_TIMER_0,
    .ledc_channel = LEDC_CHANNEL_0,



    // settings for the camera's picture. 
    .pixel_format = PIXFORMAT_JPEG,     // JPEG format

    .frame_size = FRAMESIZE_VGA,        /*QQVGA-UXGA, For ESP32, do not use sizes above QVGA when not JPEG. 
                                          The performance of the ESP32-S series has improved a lot, 
                                          but JPEG mode always gives better frame rates.
                                        QVGA = 320x240
                                        VGA = 640x480   
                                                                                                        */
                                                                                                    

                /*
                 ov2640 with esp32 will give you 12.5 fps in regular hd 1280x720 or same rate as uxga 1600x1200,
                 and with vga 640x480 you will get the 25fps. All of that can be written to a basic sd card at that speed as a avi. 
                 There is no full hd 1920x1980 on ov2640.

                boards like the: Realtek AMB82 can supposeably process 60fps 1080p but are expensive.
                
                
                for this case however 640x480 is perfectly fine as it gives enough quality 
                to see people damaging car at a decent fps (similar to movies are produced in)
                

                source: "some random guy on reddit"
                https://www.reddit.com/r/esp32/comments/usjga4/whats_the_best_camera_resolution_and_framerate/
                */


    .jpeg_quality = 12,                 // 0-63 lower means higher quality
    .fb_count = 2                       // Number of frame buffers to allocate
};


static const char* TAG = "camera"; // immutable (unchangeable) object representing the camera


// static function that initializes the camera. value should not change due to static keyword
static esp_err_t init_camera(void)
{
    //initialize the camera
    esp_err_t err = esp_camera_init(&camera_config); // 

    if (err != ESP_OK) // if the value of err is not "esp ok" throw error in log
    {
        ESP_LOGE(TAG, "Camera Init Failed");
        return err;
    }

    return ESP_OK;  // return esp_ok if initialized
}


// Snap picture
camera_fb_t* snap_picture(void) {
    ESP_LOGI(TAG, "Taking picture...");

    camera_fb_t *pic = esp_camera_fb_get();
    
    if (!pic) {
        ESP_LOGE(TAG, "Camera capture failed");
        return NULL;
    }
    
    ESP_LOGI(TAG, "Picture taken!");
    
    return pic;
}



// Release picture
void release_picture(camera_fb_t* fb) {
    if (fb) {
        esp_camera_fb_return(fb);
    }
}


// espressif's framework uses app_main() instead of main() as the main()

void app_main(void) {
#if BOARD_ESP32_AITHINKER
    if (ESP_OK != init_camera()) {
        ESP_LOGE(TAG, "Camera initialization failed!");
        return;
    }

    while (1) {
        camera_fb_t *pic = snap_picture();
        if (pic) {
            // Store or process the picture here (e.g., save to SD card)
            release_picture(pic);
        }
        vTaskDelay(5000 / portTICK_RATE_MS); // Delay before taking another picture
    }
#else
    ESP_LOGE(TAG, "Camera support is not available for this chip");
    return;
#endif
}