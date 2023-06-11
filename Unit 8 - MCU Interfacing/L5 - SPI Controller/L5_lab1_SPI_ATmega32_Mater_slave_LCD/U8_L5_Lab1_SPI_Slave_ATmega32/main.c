/*
 * unit7_L2_section.c
 *
 * Created: 4/26/2023 9:34:54 AM
 * Author : hesham mohamed
 */ 
/* ======= Includes ======= */
#include "LCD_driver/LCD.h"
#include "MCAL/SPI.h"

/* =======Global Macros======= */
//#define MCU_SPI_Master
#define MCU_SPI_Slave

/* =======Global Variables======= */
char received_data;
char data ='a';


/* =======CallBack Functions======= */
void SPI_Receive_CallBack(void)
{
	#ifdef MCU_SPI_Slave
	received_data = MCAL_SPI_Receive(SPI_Polling_Enable);
	LCD_GOTO(2,11);
	LCD_write_char(received_data);	
	// Send data to Master
	/*MCAL_SPI_Send(data, SPI_Polling_Enable);
	data++;
	if(data == 'z'+1)
	{
		data = 'a';
	}*/
	#endif
}

int main(void)
{
	uint8_t x=1;
	
	//Initialize LCD
	LCD_init();
	
	/*SPI Configuration*/
	SPI_Config_t* SPI_Cfg;
	SPI_Cfg->Master_Speed = SPI_MASTER_SPEED_f_4;
	SPI_Cfg->CLK_Speed = SPI_CLK_SPEED_Normal;
	SPI_Cfg->Data_Order = SPI_DATA_ORDER_MSB;
	SPI_Cfg->CLK_Polarity = SPI_CLK_Polarity_Leading_Rising;
	
	/*SPI Mode Configuration*/
	#ifdef MCU_SPI_Master
	SPI_Cfg->SPI_Mode = SPI_MODE_MASTER;
	SPI_Cfg->IRQ_Enable = SPI_IRQ_None;
	SPI_Cfg->p_IRQ_CallBack = NULL;
	
	MCAL_SPI_Init(SPI_Cfg);
	LCD_write_string("Master >> ");
	_delay_ms(50);
	#endif

	#ifdef MCU_SPI_Slave
	SPI_Cfg->SPI_Mode = SPI_MODE_SLAVE;
	SPI_Cfg->IRQ_Enable = SPI_IRQ_Enable;
	SPI_Cfg->p_IRQ_CallBack = SPI_Receive_CallBack;
	
	MCAL_SPI_Init(SPI_Cfg);
	LCD_clear_screen();
	LCD_GOTO(1,0);
	LCD_write_string("Slave:");
	LCD_GOTO(2,0);
	LCD_write_string("Received: ");
	_delay_ms(50);
	#endif
	
	/* Set Idle High (Active High), set "SS" by 1 */
	PORTB |= (1<<SS);
	
    while (1) 
    {
		
		#ifdef MCU_SPI_Master
		/* Start Sending Operation */
		//1. Set SS (Low), to listen
		PORTB &= ~(1<<SS);
		
		//2. Send data over SPI
		_delay_ms(10);
		MCAL_SPI_Send(&data, SPI_Polling_Enable);
		
		//3. Reset SS to idle mode
		PORTB |= (1<<SS);
		
		//4. Print send data, then increment data
		LCD_GOTO(1, 11);
		LCD_write_char(data);
		data++;
		if(data == 'Z'+1)
		{
			data = 'A';
		}
		
		//5. Print received data
		received_data = MCAL_SPI_Receive(SPI_Polling_Enable);
		LCD_GOTO(2,11);
		LCD_write_char(received_data);
		#endif		
    }
}

