#include "pir.h"
#include <xc.h>

// Initialize the PIR sensor pins
void PIR_Init(void) {
    // Set PIR sensor pins as input
    SET_PIN_INPUT(PIR_SENSOR_1);  // Set PIR_SENSOR_1 as input
    SET_PIN_INPUT(PIR_SENSOR_2);  // Set PIR_SENSOR_2 as input
    SET_PIN_INPUT(PIR_SENSOR_3);  // Set PIR_SENSOR_3 as input
    SET_PIN_INPUT(PIR_SENSOR_4);  // Set PIR_SENSOR_4 as input
}

// Check if motion is detected by any of the PIR sensors
unsigned char PIR_Check(void) {
    if (PORTBbits.RB4 == 1) {
        return 1;  // Motion detected by PIR_SENSOR_1
    }
    if (PORTBbits.RB5 == 1) {
        return 2;  // Motion detected by PIR_SENSOR_2
    }
    if (PORTDbits.RD4 == 1) {
        return 3;  // Motion detected by PIR_SENSOR_3
    }
    if (PORTDbits.RD5 == 1) {
        return 4;  // Motion detected by PIR_SENSOR_4
    }
    return 0;  // No motion detected by any sensor
}

// Clear or reset PIR sensor states (if needed)
void PIR_Clear(void) {
    // For HC-SR501, the OUT pin will automatically go low after a set time, 
    // but you can implement logic here to reset the state if necessary.
}
