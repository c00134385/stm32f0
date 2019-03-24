
#ifndef _USART1_H
#define _USART1_H

#include "stm32f0xx.h"
#include <stdio.h>

typedef void (*uart2_input_byte_callback)(unsigned char);

void USART1_Init(uint32_t baud);

void USART1_set_input_byte_callback(uart2_input_byte_callback cb);
void USART1_write(unsigned char *buff, int length);


#endif
