#include <xc.h>
#include "pins.h"
#include "uart.h"
#include "led.h"
#include "delay.h"

// Define configuration bits
#pragma config FOSC = HS    // High-speed oscillator
#pragma config WDTE = OFF   // Watchdog Timer disabled
#pragma config PWRTE = OFF  // Power-up Timer disabled
#pragma config MCLRE = ON   // MCLR pin enabled
#pragma config LVP = OFF    // Low Voltage Programming disabled
#pragma config CPD = OFF    // Data code protection off
#pragma config BOREN = OFF  // Brown-out Reset disabled
#pragma config WRT = OFF    // Flash memory write protection disabled
#pragma config CP = OFF     // Flash memory code protection disabled

void main(void) {
    // Initialize peripherals
    UART_Init();  // Initialize UART communication
    LED_Init();   // Initialize LED for feedback

    // Wait for 2 seconds before starting recording
    Delay_sec(2);  

    // Send start recording command to ESP32-CAM
    UART_Write_String("start recording\r\n");
    LED_On();  // Turn on LED to indicate recording has started
    Delay_sec(5);  // Record for 5 seconds as an example
    LED_Off();  // Turn off LED after a short period

    // Send stop recording command to ESP32-CAM
    UART_Write_String("stop recording\r\n");
    LED_On();  // Turn on LED to indicate stop recording command sent
    Delay_sec(2);  // Wait for 2 seconds before turning off the LED

    // Turn off the LED
    LED_Off();

    while(1) {
        // Main loop, could be expanded for other tasks
    }
}
