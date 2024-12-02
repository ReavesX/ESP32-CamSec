/*
 * File:   main.c
 * Author: Donald Jackson
 *
 */

// Include headers
#include <xc.h>
#include "pir.h"
#include "basic_hal.h"
#include "uart.h"

// Config

void main(void) {
    
        /*
     * Initialize UART Commnuication
     * Initialize PIR
     * Initialize Confirmation LED
     * 
     * Short delay before beginning
         */
    
    
    while(1){
    /*
     * 
     * Send Start Command To ESP32-Cam
     * Keep an LED On while Motion Detected --
     * Blink Confirmation LED1 for Recording Start
     * 
     * Wait for PIR Sensor to go low 
     *          Send Stop Command to ESP32-Cam
     *          Blink Confirmation LED2 for Recording Stop
     */
    
    }
    
    
    return;
}
