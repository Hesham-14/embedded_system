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
#include "STM32F103C6_GPIO_Driver.h"
#include "STM32F103C6_EXTI_Driver.h"
#include "Keypad.h"
#include "LCD.h"

uint32_t IRQ_Flag;

void CLK_init()
{
	//1. GPIO port A clock enable
	RCC_GPIOA_CLK_EN();
	//2. GPIO port B clock enable
	RCC_GPIOB_CLK_EN();
	//2. AFIO clock enable
	RCC_AFIO_CLK_EN();
}

void GPIO_init()
{

}

void wait_ms(uint32_t time)
{
	uint32_t i, j;
	for(i=0; i < time; i++)
		for(j=0; j < 255; j++);
}

void EXTI9PB9_Callback()
{
	IRQ_Flag = 1;
	//clear screen
	//write on screen
	//wait
}

int main()
{
	//1. Enable CLK

	//2. LCD init, then clear screen

	//3. Keypad init

	//4.configure EXTI pin
	EXTI_PinConfig_t EXTI_CFG;
	EXTI_CFG.EXTI_PIN = EXTI9PB9;
	EXTI_CFG.Trigger_Case = EXTI_TRIGGER_RISING;
	EXTI_CFG.IRQ_EN = EXTI_IRQ_ENABLE;
	EXTI_CFG.P_IRQ_CallBack = EXTI9PB9_Callback;

	MCAL_EXTI_GPIO_Init(&EXTI_CFG);

	 IRQ_Flag = 1;

	//loop
	while(1)
	{
		if(IRQ_Flag)
		{
			//clear screen
			IRQ_Flag = 0;
		}
	}

	return 0;
}
