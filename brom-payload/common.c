#include "common.h"


void (*send_usb_response)(int, int, int) = (void*)0x6C7D;
int (*send_dword)() = (void*)0xD1FF;
int (*recv_dword)() = (void*)0xD1CB;
int (*send_data)() = (void*)0xD2C7;
int (*recv_data)() = (void*)0xD241;

void low_uart_put(int ch) {
    volatile uint32_t *uart_reg0 = (volatile uint32_t*)0x11005014; // 0x11002014
    volatile uint32_t *uart_reg1 = (volatile uint32_t*)0x11005000; // 0x11002000

    while ( !((*uart_reg0) & 0x20) )
    {}

    *uart_reg1 = ch;
}

void _putchar(char character)
{
    if (character == '\n')
        low_uart_put('\r');
    low_uart_put(character);
}
