#ifndef UART_H
#define UART_H

// Baud rate settings for UART communication
#define BAUD_RATE 115200
#define FREQ 20000000  // 20 MHz oscillator frequency
#define SPBRG_VAL ((FREQ / (64 * BAUD_RATE)) - 1)

void UART_Init(void);
void UART_Write(char data);
void UART_Write_String(const char* str);
unsigned char UART_Read(void);

#endif // UART_H
