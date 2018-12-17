/*
 Uart initilization and interface functions, like write and read
 */

#ifndef _UART   /* Guard against multiple inclusion */
#define _UART

#include <p32xxxx.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>


void uart_init();
void uart_write(char towrite);
char uart_read();
void uart_write_string(const char *towrite);
char * uart_read_command();
int * getCommand(const char *command);
int  getSize();

#endif
