/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Hesham Mohamed
 * @brief          : Main program body for unit 6 lesson 3 lab 2
 ******************************************************************************
**/

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


typedef volatile unsigned int vuint32_t ;
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

// register address
//GPIO
#define GPIOA_BASE 0x40010800
#define GPIOA_CRH *(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR *(volatile uint32_t *)(GPIOA_BASE + 0x0C)

//RCC
#define RCC_BASE 0x40021000
#define RCC_CR *(volatile uint32_t *)(RCC_BASE + 0x0)
#define RCC_CFGR *(volatile uint32_t *)(RCC_BASE + 0x04)
#define RCC_APB2ENR *(volatile uint32_t *)(RCC_BASE + 0x18)

void CLK_init()
{
	//PLLON: PLL enable
	RCC_CR |= (1 << 24);

	//PLLSRC: PLL entry clock source
	RCC_CFGR |= (0b0 << 16);

	//PLLMUL: PLL multiplication factor, x8 = 32 MHz
	RCC_CFGR |= (0b0110 << 18);

	//SW: System clock switch, PLL select
	RCC_CFGR |= (0b10 << 0);

	//HPRE: AHB prescaler, no divide
	//Zero

	//PPRE1: APB low-speed prescaler (APB1), /2 = 16 MHz
	RCC_CFGR |= (0b100 << 8);

	//PPRE2: APB high-speed prescaler (APB2), /4 = 8 MHz
	RCC_CFGR |= (0b101 << 11);

	//enable clock for GPIOA
	RCC_APB2ENR |= 1<<2;
}
int main(void)
{
	CLK_init();

	//Init GPIOA
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x00200000;
	while(1)
	{
		GPIOA_ODR |= 1<<13 ;
		for (int i = 0; i < 5000; i++); // arbitrary delay
		GPIOA_ODR &= ~(1<<13) ;
		for (int i = 0; i < 5000; i++); // arbitrary delay

	}
}
