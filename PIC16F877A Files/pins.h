#ifndef PINS_H
#define PINS_H

// PORTA - Analog pins (can be configured as digital as needed)
#define LED                 RA0    // LED connected to RA0
#define BUTTON_INPUT        RA1    // Button connected to RA1 (Analog input AN1)
#define ADC_INPUT           RA2    // Analog input (AN2)
#define VREF                RA3    // Analog input (AN3) for VREF
#define T0CKI               RA4    // T0CKI - Timer 0 External Clock Input
#define ADC_INPUT2          RA5    // Analog input (AN4)

// PORTB - Digital I/O pins, Interrupts, UART
#define UART_RX             RB7    // UART Receive (RX)
#define UART_TX             RB6    // UART Transmit (TX)
#define INT0                RB0    // External Interrupt 0 (INT0)
#define INT1                RB1    // External Interrupt 1 (INT1)
#define INT2                RB2    // External Interrupt 2 (INT2)
#define CCP2                RB3    // CCP2 (Capture/Compare/PWM)

// PORTC - PWM, I2C, Digital I/O
#define PWM1                RC0    // PWM1 output
#define PWM2                RC1    // PWM2 output
#define CCP1                RC2    // CCP1 (Capture/Compare/PWM)
#define I2C_SCL             RC3    // I2C Clock (SCL)
#define I2C_SDA             RC4    // I2C Data (SDA)

// PORTD - Digital I/O, SPI
#define SPI_SCK             RD3    // SPI Clock (SCK)
#define SPI_MISO            RD0    // SPI MISO (Master In Slave Out)
#define SPI_MOSI            RD1    // SPI MOSI (Master Out Slave In)
#define SPI_CS              RD2    // SPI Chip Select (CS)

// PORTE - Digital I/O, SPI
#define SPI_MISO2           RE0    // SPI MISO (Master In Slave Out)
#define SPI_MOSI2           RE1    // SPI MOSI (Master Out Slave In)
#define SPI_SCK2            RE2    // SPI Clock (SCK)

// Special Pins - Power, Reset
#define VDD                 VDD    // Power supply
#define VSS                 VSS    // Ground
#define MCLR                MCLR   // Master Clear (reset pin)

// PIR Sensor Pins - Connect to OUT pins of HC-SR501
#define PIR_SENSOR_1        RB4    // PIR sensor 1 output connected to RB4
#define PIR_SENSOR_2        RB5    // PIR sensor 2 output connected to RB5
#define PIR_SENSOR_3        RD4    // PIR sensor 3 output connected to RD4
#define PIR_SENSOR_4        RD5    // PIR sensor 4 output connected to RD5

// Macros for setting pin direction (input/output) and state (high/low)
#define SET_PIN_OUTPUT(pin)  (TRIS##pin = 0)
#define SET_PIN_INPUT(pin)   (TRIS##pin = 1)
#define SET_PIN_HIGH(pin)    (LAT##pin = 1)
#define SET_PIN_LOW(pin)     (LAT##pin = 0)

#endif // PINS_H
