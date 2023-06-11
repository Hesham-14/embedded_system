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

//Learn-in-depth
//Hesham Mohamed

#include <stdint.h>

typedef volatile unsigned int vuint32_t;

//registers addresses
//RCC
#define RCC_BASE 	0x40021000
#define RCC_CR *(volatile uint32_t *)(RCC_BASE + 0x0)
#define RCC_CFGR *(volatile uint32_t *)(RCC_BASE + 0x04)
#define RCC_APB2ENR *(volatile uint32_t *)(RCC_BASE + 0x18)
#define RCC_IOPAEN 	(1<<2)

//GPIO
#define GPIOPA_BASE 0x40010800
#define GPIOA_CRH	*(volatile uint32_t *)(GPIOPA_BASE + 0x04)
#define GPIOA_CRL	*(volatile uint32_t *)(GPIOPA_BASE + 0x00)
#define GPIOA_ODR 	*(volatile uint32_t *)(GPIOPA_BASE + 0x0C)
#define GPIOA13		(1UL<<13)

//EXTI
#define EXTI_BASE 0x40010400
#define EXTI_IMR	*(volatile uint32_t *)(EXTI_BASE + 0x00)
#define EXTI_RTSR	*(volatile uint32_t *)(EXTI_BASE + 0x08)
#define EXTI_FTSR	*(volatile uint32_t *)(EXTI_BASE + 0x0C)
#define EXTI_PR		*(volatile uint32_t *)(EXTI_BASE + 0x14)


//AFIO
#define AFIO_BASE 0x40010000
#define AFIO_EXTICR1	*(volatile uint32_t *)(AFIO_BASE + 0x08)

//NVIC [0:7]
#define NVIC_BASE 0xE000E100
#define NVIC_ISER		*(volatile uint32_t *)(NVIC_BASE + 0x00)



/************************************/

void CLK_init()
{
	//PLLON: PLL enable
	RCC_CR |= (1 << 24);

	//PLLSRC: PLL entry clock source set to the HSI
	RCC_CFGR |= (0b0 << 16);

	//PLLMUL: PLL multiplication factor, x8 = 32 MHz
	RCC_CFGR |= (0b0110 << 18);

	//SW: System clock switch, select PLLCLK
	RCC_CFGR |= (0b10 << 0);

	//HPRE: AHB prescaler, no divide
	//Zero

	//PPRE2: APB high-speed prescaler (APB2), set to AHB/4 = 8 MHz
	RCC_CFGR |= (0b101 << 11);

	//IOPAEN: enable clock for GPIOA
	RCC_APB2ENR |= RCC_IOPAEN;

	//AFIOEN: enable clock for AFIO
	RCC_APB2ENR |= (1<<0);

	//EXTI clock is automatically enables
}

void GPIO_init()
{
	//enable pin 13 port A as output
	GPIOA_CRH   &= 0xFF0FFFFF;
	GPIOA_CRH   |= 0x00200000;

	//CNF0: set Port A pin 0 as an input pin, [01: Floating input (reset state)]
	GPIOA_CRL |= (01<<2);
}

void AFIO_init()
{
	//AFIO_EXTICR1: configure PA0 as a source input for EXT0
	AFIO_EXTICR1 |= (0<<0);
}

void EXTI_init()
{
	//IMR: enable EXTI line 0 (mask = 1)
	EXTI_IMR |= (1<<0);

	//RTSR:  Rising trigger event for EXT0
	EXTI_RTSR |= (1<<0);

	//Configure the enable and mask bits that control the NVIC IRQ
	NVIC_ISER |= (1<<6);
}

int main(void)
{
	CLK_init();
	GPIO_init();
	AFIO_init();
	EXTI_init();
	while(1);
	return 0;
}
void EXTI0_IRQHandler()
{
	//IRQ is happened EXTI0 >>> PORTA Pin 0 _|- rising edge

	//toggle led pin A 13
	GPIOA_ODR ^= (1<<13);

	//PR: clear pending request,  by writing a ‘1’ into the bit
	EXTI_PR |= (1<<0);
}

