#ifndef _COMMON_H_
#define _COMMON_H_

#include <inttypes.h>

void (*send_usb_response)(int, int, int);
int (*send_dword)();
int (*recv_dword)();
int (*send_data)();
int (*recv_data)();

void low_uart_put(int ch);

void _putchar(char character);

#endif
