/*
 * LCD.c
 *
 *  Created on: May 6, 2023
 *      Author: hesham mohamed
 */

/* =========================================================================
 *                                  Includes
 * =========================================================================*/
#include "LCD.h"
#include "STM32F103C6_GPIO_Driver.h"


int count=0;

/*
 * =========================================================================
 * 								Generic Functions
 * =========================================================================
 */
void delay_ms(uint32_t time){
	uint32_t i, j;
	for (i = 0; i < time; i++)
		for (j = 0; j < 255; j++)
			;
}

void LCD_clear_screen(void)
{
	LCD_command(LCD_CLEAR_SCREEN);
	count=0;
}

void ENABLE_cycle()
{
	MCAL_GPIO_WritePin(LCD_CTRL, EN_SWITCH, GPIO_PIN_SET);
	delay_ms(50);
	MCAL_GPIO_WritePin(LCD_CTRL, EN_SWITCH, GPIO_PIN_RESET);
}

void LCD_isbusy(void)
{
	GPIO_PinConfig_t pinCfg;
	int i=0;
	//1. disable data ports as output --> input
	for(i=0; i<=8; i++)
	{
		pinCfg.GPIO_PinNumber = (0b1 << i);
		pinCfg.GPIO_Mode = GPIO_MODE_INPUT_FLO;
		MCAL_GPIO_Init(LCD_CTRL, &pinCfg);
	}

	//2. to read data --> set RW = 1
	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_SET);

	//3. clear RS
	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_PIN_RESET);

	//4. enable cycle
	ENABLE_cycle();

	//5. enable ports as output
	for(i=0; i<=8; i++)
	{
		pinCfg.GPIO_PinNumber = (0b1 << i);
		pinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
		pinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
		MCAL_GPIO_Init(LCD_CTRL, &pinCfg);
	}

	//6. clear RS
	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_PIN_RESET);
}

int LCD_GOTO(unsigned char  line, unsigned char position)
{
	//false case
	if(position > 16 || position < 0)
		return 0;

	if(line == 1)
		LCD_command(LCD_BEGIN_AT_FIRST_ROW + position);
	else if(line == 2)
		LCD_command(LCD_BEGIN_AT_SECOND_ROW + position);
	return 1;
}

void check_line()
{
	if(count == 17)
		LCD_GOTO(2,0);
	else if(count == 33)
	{
		LCD_clear_screen();
		LCD_GOTO(1,0);
		count = 0;
	}
}

/*
 * =========================================================================
 * 								APIs Functions Definitions
 * =========================================================================
 */


/**================================================================
 * @Fn			-LCD_init
 * @brief 		-Initializes LCD states in the ref
 * @param [in]	-EXTI_Config:
 * @retval 		-none
 * Note			-STM32F103C6 MCU has GPIO A,B,C,D,E Modules,
 * 				 but LQFP48 package has only GPIO A, B, and (part of C,D) exported as extenal PINs from thr MCU
 * 				 -Also mandatory to enable RCC clock for AFIO and the corresponding GPIO
 */
void LCD_init(void)
{
	//1. Delay for power ON
	delay_ms(20);

	GPIO_PinConfig_t pinCfg;
	int i=0, j=9;
	//2. set LCD data ports as output
	for(i=0; i<=7; i++)
	{
		pinCfg.GPIO_PinNumber = (0b1 << i);
		pinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
		pinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
		MCAL_GPIO_Init(LCD_CTRL, &pinCfg);
	}
	volatile int k=5;
	if(k==5)
		k=7;
	//3. set LCD CTRL ports as output and reset it
	for(j=8; j<=10; j++)
	{
		pinCfg.GPIO_PinNumber = (0b1 << j);
		pinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
		pinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
		MCAL_GPIO_Init(LCD_CTRL, &pinCfg);
	}
	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_CTRL, EN_SWITCH, GPIO_PIN_RESET);


	//wait
	delay_ms(15);

	//4. initialize LCD
	LCD_command(LCD_FUNCTION_8BIT_2LINES);

	//5. clear LCD
	LCD_clear_screen();

	//6. Return home
	LCD_command(LCD_RETURN_HOME);

	//7. Entry mode
	LCD_command(LCD_ENTRY_MODE);

	//8. start at first row
	LCD_command(LCD_BEGIN_AT_FIRST_ROW);

	//9. cursor blinck
	LCD_command(LCD_DISP_ON_CURSOR_BLINK);
}

void LCD_command(unsigned char cmd)
{
	//1. check busy
	//LCD_isbusy();

	//2. copy data
	MCAL_GPIO_WritePort(LCD_CTRL, cmd);

	//3. clear RS & RW
	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_RESET);
	delay_ms(20);

	//4. enable cycle
	ENABLE_cycle();
}

void LCD_write_char(unsigned char data)
{
	//1. check busy
	//LCD_isbusy();

	//2. check line
	count++;
	check_line();

	//3. copy data
	MCAL_GPIO_WritePort(LCD_CTRL, data);

	//4. set RS & clear RW
	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_PIN_SET);
	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_RESET);
	delay_ms(20);

	//5. enable cycle
	ENABLE_cycle();
}

void LCD_write_string(char* string)
{
	while(*string > 0)
	{
		LCD_write_char(*string++);
	}
}

//=============================================
