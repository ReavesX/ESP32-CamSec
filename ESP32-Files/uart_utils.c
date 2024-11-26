#include "driver/uart.h"
#include "esp_log.h"

// Global UART number definition
const uart_port_t uart_num = UART_NUM_2;

void init_uart() {
    // UART configuration for basic reception
    uart_config_t uart_config = {
        .baud_rate = 115200,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE, // Disable flow control unless needed
    };

    // Configure UART parameters
    ESP_ERROR_CHECK(uart_param_config(uart_num, &uart_config));

    // Install UART driver
    const int uart_buffer_size = 2048; // Double buffer size
    ESP_ERROR_CHECK(uart_driver_install(uart_num, uart_buffer_size, uart_buffer_size, 0, NULL, 0));
}

int uart_receive(uint8_t *data, int max_len, int timeout_ms) {
    // Read data from UART buffer
    int length = uart_read_bytes(uart_num, data, max_len, timeout_ms / portTICK_RATE_MS);
    
    if (length > 0) {
        // Log the received data
        ESP_LOGI("UART", "Received: %.*s", length, data);

        // Process received instructions from the PIC16F877A
        if (data[0] == 'START') {
            // Example: If data received is 'A', do something
            ESP_LOGI("UART", "START Instruction received. Performing action.");
            // Action for instruction A
        } 
        else if (data[0] == 'STOP') {
            
            // Example: If data received is 'B', do something else
            ESP_LOGI("UART", "STOP Instruction received. Performing different action.");
            // Action for instruction B
        } 
        else {
            ESP_LOGI("UART", "Unknown instruction received.");
        }
    }
    return length;  // Return number of bytes read
}