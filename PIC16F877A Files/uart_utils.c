#include "uart.h"

void UART_Init(void) {
    TRISCbits.TRISC6 = 0;  // Set RC6 (TX Pin) as output
    TRISCbits.TRISC7 = 1;  // Set RC7 (RX Pin) as input

    SPBRG = SPBRG_VAL;  // Set the baud rate (calculated SPBRG)
    TXSTA = 0x24;  // TX enable, async mode
    RCSTA = 0x90;  // RX enable, serial port enable
}

void UART_Write(char data) {
    while (!TXIF);  // Wait for TX buffer to be empty
    TXREG = data;   // Transmit data
}

void UART_Write_String(const char* str) {
    while (*str) {
        UART_Write(*str++);  // Send each character
    }
}

unsigned char UART_Read(void) {
    while (!RCIF);    // Wait for data to be received
    return RCREG;     // Read received data from the RX register
}
