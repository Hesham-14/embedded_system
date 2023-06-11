/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Hesham Mohamed
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "STM32F103x6.h"
#include <STM32F103C6_USART_Driver.h>
#include "STM32F103C6_GPIO_Driver.h"
#include "STM32F103C6_RCC_Driver.h"
#include "STM32F103C6_EXTI_Driver.h"



unsigned int IQ_Flag =0;

void Clock_init()
{
	//Enable Clk
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();
}



int main(void)
{

	uint16_t ch;
	UART_Config_t uartCfg;
	uartCfg.BaudRate = USART_BAUDRATE_115200;
	uartCfg.HW_Flow_CTRL = HW_FLOW_CTRL_CTS_NONE;
	uartCfg.IRQ_EN = USART_IRQ__EN_NONE;
	uartCfg.IRQ_CallBack = NULL;
	uartCfg.Parity = USART_PARITY_NONE;
	uartCfg.PayLoad = USART_PAYLOAD_8B;
	uartCfg.StopBit = UASRT_STOPBIT_1;
	uartCfg.USART_Mode = USART_MODE_Tx_Rx;

	MCAL_UART_Init(USART1, &uartCfg);
	MCAL_UART_GPIO_SetPins(USART1);

    /* Loop forever */
	while(1)
	{
		MCAL_UART_ReceiveData(USART1, &ch, enable);

		MCAL_UART_SendData(USART1, &ch, enable);

	}

}





