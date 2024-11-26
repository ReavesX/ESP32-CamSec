#ifndef PINS_H
#define PINS_H

// Define PORTA Pins (Analog or Digital)
#define BUTTON_INPUT        RA0    // Button connected to RA0 (Analog input AN0)
#define SENSOR_INPUT        RA1    // Sensor connected to RA1 (Analog input AN1)
#define ADC_INPUT           RA2    // Analog input (AN2)
#define VREF                RA3    // Analog input (AN3) for VREF
#define T0CKI               RA4    // T0CKI - Timer 0 External Clock Input
#define ADC_INPUT2          RA5    // Analog input (AN4)

// Define PORTB Pins (Digital I/O, Interrupts, UART)
#define UART_RX             RB7    // UART Receive (RX)
#define UART_TX             RB6    // UART Transmit (TX)
#define INT0                RB0    // External Interrupt 0 (INT0)
#define INT1                RB1    // External Interrupt 1 (INT1)
#define INT2                RB2    // External Interrupt 2 (INT2)
#define CCP2                RB3    // CCP2 (Capture/Compare/PWM)

// Define PORTC Pins (PWM, I2C, Digital I/O)
#define PWM1                RC0    // PWM1 output
#define PWM2                RC1    // PWM2 output
#define CCP1                RC2    // CCP1 (Capture/Compare/PWM)
#define I2C_SCL             RC3    // I2C Clock (SCL)
#define I2C_SDA             RC4    // I2C Data (SDA)

// Define PORTD Pins (Digital I/O, SPI)
#define SPI_SCK             RD3    // SPI Clock (SCK)
#define SPI_MISO            RD0    // SPI MISO (Master In Slave Out)
#define SPI_MOSI            RD1    // SPI MOSI (Master Out Slave In)
#define SPI_CS              RD2    // SPI Chip Select (CS)

// Define PORTE Pins (Digital I/O, SPI)
#define SPI_MISO2           RE0    // SPI MISO (Master In Slave Out)
#define SPI_MOSI2           RE1    // SPI MOSI (Master Out Slave In)
#define SPI_SCK2            RE2    // SPI Clock (SCK)

// Define Special Pins (Power, Reset)
#define VDD                 VDD    // Power supply
#define VSS                 VSS    // Ground
#define MCLR                MCLR   // Master Clear (reset pin)

#endif // PINS_H
