/*
 * STM32F103x6.h
 *
 *  Created on: May 2, 2023
 *      Author: hesham mohamed
 */

#ifndef INC_STM32F103X6_H_
#define INC_STM32F103X6_H_

//-----------------------------
//Includes
//-----------------------------
#include "stdlib.h"
#include "stdint.h"

//-----------------------------
//Base addresses for Memories
//-----------------------------
#define FLASH_MEMORY_BASE						0x08000000UL
#define SYSTEM_MEMORY_BASE						0x1FFFF000UL
#define SRAM_BASE								0x1FFFF000UL
#define Peripherals_BASE						0x40000000UL
#define Cortex_M3_Internal_Peripherals_BASE		0xE0000000UL


//-----------------------------
//Base addresses for AHB Peripherals
//-----------------------------
#define RCC_BASE							(Peripherals_BASE + 0x00021000UL)


//-----------------------------
//Base addresses for APB2 Peripherals
//-----------------------------
//GPIO
//A,B fully included in LQFP48 package
#define GPIOA_BASE							(Peripherals_BASE + 0x00010800UL)
#define GPIOB_BASE							(Peripherals_BASE + 0x00010C00UL)
//C,D partial included in LQFP48 package
#define GPIOC_BASE							(Peripherals_BASE + 0x00011000UL)
#define GPIOD_BASE							(Peripherals_BASE + 0x00011400UL)
//E not included in LQFP48 package
#define GPIOE_BASE							(Peripherals_BASE + 0x00011800UL)

//EXTI
#define EXTI_BASE							(Peripherals_BASE + 0x00010400UL)

//AFIO
#define AFIO_BASE							(Peripherals_BASE + 0x00010000UL)


//>>>>>>>>>>>>>>>>>>>>>>>>>
//Peripheral register:
//>>>>>>>>>>>>>>>>>>>>>>>>>
//Peripheral register: RCC
typedef struct
{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHNENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
} RCC_t;

//Peripheral register: GPIO
typedef struct
{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;
} GPIO_t;

//Peripheral register: EXTI
typedef struct
{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
} EXTI_t;

//Peripheral register: AFIO
typedef struct
{
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR1;
	volatile uint32_t EXTICR2;
	volatile uint32_t EXTICR3;
	volatile uint32_t EXTICR4;
	volatile uint32_t RESERVED0;
	volatile uint32_t MAPR2;
} AFIO_t;


//>>>>>>>>>>>>>>>>>>>>>>>>>
//Peripheral Instants:
//>>>>>>>>>>>>>>>>>>>>>>>>>
#define GPIOA				((GPIO_t *)GPIOA_BASE)
#define GPIOB				((GPIO_t *)GPIOB_BASE)
#define GPIOC				((GPIO_t *)GPIOC_BASE)
#define GPIOD				((GPIO_t *)GPIOD_BASE)
#define GPIOE				((GPIO_t *)GPIOE_BASE)

#define RCC					((RCC_t *)RCC_BASE)

#define EXTI				((EXTI_t *)EXTI_BASE)
#define AFIO				((AFIO_t *)AFIO_BASE)


//>>>>>>>>>>>>>>>>>>>>>>>>>
//clock enable Macros:
//>>>>>>>>>>>>>>>>>>>>>>>>>
#define RCC_AFIO_CLK_EN()	(RCC->APB2ENR |= 1 <<0)
#define RCC_GPIOA_CLK_EN()	(RCC->APB2ENR |= 1 <<2)
#define RCC_GPIOB_CLK_EN()	(RCC->APB2ENR |= 1 <<3)
#define RCC_GPIOC_CLK_EN()	(RCC->APB2ENR |= 1 <<4)
#define RCC_GPIOD_CLK_EN()	(RCC->APB2ENR |= 1 <<5)
#define RCC_GPIOE_CLK_EN()	(RCC->APB2ENR |= 1 <<6)

//>>>>>>>>>>>>>>>>>>>>>>>>>
//Generic Macros:
//>>>>>>>>>>>>>>>>>>>>>>>>>


















#endif /* INC_STM32F103X6_H_ */
