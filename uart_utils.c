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

void uart_receive() {
    uint8_t data[128];
    int length = uart_read_bytes(uart_num, data, sizeof(data), 100 / portTICK_RATE_MS);
    
    if (length > 0) {
        // Process received data (log it for debugging)
        printf("Received: %.*s\n", length, data);
    } else {
        // Handle timeout or empty buffer case
        printf("No data received or timeout occurred.\n");
    }
}