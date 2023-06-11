/*
 * unit7_L2_section.c
 *
 * Created: 4/26/2023 9:34:54 AM
 * Author : hesham mohamed
 */ 

//this program sends messages from Master to Slave using TWI

/* ======= Includes ======= */
#include "MCAL/TWI.h"

/* =======Global Macros======= */
#undef F_CPU
#define F_CPU	8000000UL
#define MCU_AS_MASTER
//#define MCU_AS_SLAVE


int main(void)
{
	//1. initialize required variables & functions
	#ifdef MCU_AS_MASTER
		unsigned int num = 0;
		MCAL_TWI_Init(0x48);
	#endif
	
	#ifdef MCU_AS_SLAVE
		DDRA = 0xFF;					//make PORTA as output
		TWI_SetAddress(0b11010000);
	#endif
	
	//2. Transmit or Receive message
    while (1) 
    {
		#ifdef MCU_AS_MASTER
		MCAL_TWI_Master_Transmit(num++);
		#endif
		
		#ifdef MCU_AS_SLAVE
		PORTA = MCAL_TWI_Slave_Receive();
		#endif
    }
}

