#include "ALL_Includes.h"//包含所需的头文件

void ALL_Config(void);

void usart1_input_byte(unsigned char byte) {
    USART1_write(&byte, 1);
}

int main(void)
{	
	int count = 0;
	ALL_Config();
	
	printf("\r\n\r\n STM32F030F4P6 demo");
	while(1)
	{
			printf("\r\n\r\n count:%d", count++);
			printf("\r\n PA1口采集的电压数值：%d",RegularConvData_Tab[0]); 
			printf("\r\n PA0:%x",GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0)); 
			LED_ON();
			delay_ms(500);
			LED_OFF();
			delay_ms(500);
	}
}

/************************
函数功能：总初始化
输入参数：无
输出参数：无
备    注：无
************************/
void ALL_Config(void)
{
    Delay_Init(48);
		LED_Init();
		USART1_Init(115200);
    USART1_set_input_byte_callback(usart1_input_byte);
		KEY_EXTI_Init();
		ADC1_DMA_Init();
}






