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


#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>


//registers addresses
//RCC
#define RCC_BASE 	0x40021000
#define RCC_APB2ENR	*(volatile uint32_t *)(RCC_BASE + 0x18)

//GPIOA
#define GPIOA_BASE 	0x40010800
#define GPIOA_CRL	*(volatile uint32_t *)(GPIOA_BASE + 0x00)
#define GPIOA_CRH	*(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_IDR	*(volatile uint32_t *)(GPIOA_BASE + 0x08)
#define GPIOA_ODR	*(volatile uint32_t *)(GPIOA_BASE + 0x0C)


//GPIOB
#define GPIOB_BASE 	0x40010C00 
#define GPIOB_CRL	*(volatile uint32_t *)(GPIOB_BASE + 0x00)
#define GPIOB_CRH	*(volatile uint32_t *)(GPIOB_BASE + 0x04)
#define GPIOB_IDR	*(volatile uint32_t *)(GPIOB_BASE + 0x08)
#define GPIOB_ODR	*(volatile uint32_t *)(GPIOB_BASE + 0x0C)

/*******************************/

void CLK_init()
{
	//IOPAEN: GPIO port A clock enable
	RCC_APB2ENR |= (1 << 2);

	//IOPBEN: GPIO port B clock enable
	RCC_APB2ENR |= (1 << 3);
}

void GPIO_init()
{
	//init input pin: PA1
	GPIOA_CRL &= ~(0b11 << 4);		//MODE --> "input mode"
	GPIOA_CRL |= (0b01 << 6);		//CNF --> "floating"

	//init input pin: PA13
	GPIOA_CRH &= ~(0b11 << 20);		//MODE --> "input mode"
	GPIOA_CRH |= (0b01 << 22);		//CNF --> "floating"

	//init output pin: PB1
	GPIOB_CRL |= (0b10 << 4);		//MODE --> "output mode 2 MHz"
	GPIOB_CRL &= ~(0b11 << 6);		//CNF --> "push-pull"
	GPIOB_ODR = (1 << 1);			//turn off led

	//init output pin: PB13
	GPIOB_CRH |= (0b10 << 20);		//MODE --> "output mode 2 MHz"
	GPIOB_CRH &= ~(0b11 << 22);		//CNF --> "push-pull"
	GPIOB_ODR = (1 << 13);			//turn off led
}

void wait_ms(uint32_t time)
{
	uint32_t i, j;
	for(i=0; i < time; i++)
		for(j=0; j < 255; j++);
}

int main()
{
	CLK_init();
	GPIO_init();
	while(1)
	{
		//check PA1 Press: PUR -- single press
		if( ((GPIOA_IDR & (1<<1)) >> 1) == 0 )
		{
			GPIOB_ODR ^= (1 << 1);
			while (((GPIOA_IDR & (1<<1)) >> 1) == 0);
		}

		//check PA13 Press: PDR -- multi press
		if( ((GPIOA_IDR & (1<<13)) >> 13) == 1 )
		{
			GPIOB_ODR ^= (1 << 13);
		}
		wait_ms(1);
	}
	return 0;
}
