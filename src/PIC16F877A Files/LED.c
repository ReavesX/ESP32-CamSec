#include "led.h"

void LED_Init(void) {
    SET_PIN_OUTPUT(LED);  // Use the pin abstraction from pins.h to set LED pin as output
}

void LED_On(void) {
    SET_PIN_HIGH(LED);  // Set the LED pin high
}

void LED_Off(void) {
    SET_PIN_LOW(LED);   // Set the LED pin low
}
