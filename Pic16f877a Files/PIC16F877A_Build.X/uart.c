/*
 * File:   uart.c
 * Author: Donald Jackson
 *
 */

#include "basic-hal.h"
#include <xc.h>

void uart_init(){
//function to initialize uart
    UART_RX = INPUT;
    UART_TX = OUTPUT;
    
    SPBRG = SPBRG_VAL;
    TXSTA = TX_BIT_CONFIG;
    RCSTA = RX_BIT_CONFIG; 
    
}
void uart_w(char data){
//function to write a single character
    
}
void uart_r(){
// function to read uart data
}
void uart_w_string(const char* instruction){
// function to write a uart string
}