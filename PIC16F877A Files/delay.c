#include "delay.h"

void Delay_sec(unsigned int sec) {
    while (sec--) {
        __delay_ms(1000);  // __delay_ms() creates a 1 millisecond delay
    }
}
