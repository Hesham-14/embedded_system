/*
 * LCD.c
 *
 * Created: 6/3/2023 9:19:41 PM
 *  Author: hesham mohamed
 */ 

//========================
// Includes
//========================
#include "TWI.h"

//========================
//	 Generic Variables
//========================
uint8_t PrescalerValue = 1; //1 4 16 64

//========================
//		Generic Macros
//========================


/*
 * =========================================================================
 * 								Generic Functions
 * =========================================================================
 */
void TWI_Start()
{
	/*send start bit*/
	//1. write 1 on [TWINT | TWSTA | TWEN]
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	
	//2. wait until transmission is done (TWINT is set)
	while(!(TWCR & (1<<TWINT)));
	
	//3. loop until TWSR = start command
	while(TWSR != 0x08);
	
	//4. clear TWSTA
	//TWCR &= ~(1<<TWSTA);
}

void TWI_Stop()
{
	//1. Transmit STOP condition by writing 1 on [TWINT | TWSTO | TWEN]
	TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
}
void TWI_Write(unsigned char DATA)
{
	//1. store data 
	TWDR = DATA;
	
	//2. write 1 on [TWINT | TWEN]
	TWCR = (1<<TWINT)|(1<<TWEN);
	
	//3. wait until transmission is done (TWINT is set)
	while(!(TWCR & (1<<TWINT)));
}
uint8_t TWI_MASTER_Read(unsigned char ack)
{
	//1. Transmit read condition by writing 1 on [TWINT | TWEA | TWEN]
	TWCR = (1<<TWINT)|(1<<TWEA)|(1<<TWEN);
	
	//2. wait until transmission is done (TWINT is set)
	while(!(TWCR & (1<<TWINT)));
	
	// return byte value
	return TWDR;
}

uint8_t TWI_SLAVE_Read(unsigned char ack)
{
	//1. Transmit read condition by writing 1 on [TWINT | TWEA | TWEN]
	if(ack ==1){
		TWCR = (1<<TWINT)|(1<<TWEA)|(1<<TWEN);
	}
	
	//2. wait until transmission is done (TWINT is set)
	while(!(TWCR & (1<<TWINT)));
	
	//3. loop unless SLA+W has been received
	while(TWSR != 0x60);
	
	//4. Transmit read condition by writing 1 on [TWINT | TWEA | TWEN]
	if(ack ==1){
		TWCR = (1<<TWINT)|(1<<TWEA)|(1<<TWEN);
	}
	
	//5. wait until transmission is done (TWINT is set)
	while(!(TWCR & (1<<TWINT)));
	
	//6. loop unless data has been received
	while(TWSR != 0x80);
	
	// return byte value
	return TWDR;
}


void TWI_SetAddress(unsigned char address)
{
	//set salve address
	TWAR = address;
}



/*
 * =========================================================================
 * 								APIs Functions Definitions
 * =========================================================================
 */

void MCAL_TWI_Init(unsigned long SCL_Clock)
{	TWBR =  ((F_CPU/SCL_Clock)-16) / (2*PrescalerValue);
	switch(PrescalerValue){
		case 1:
		TWSR = 0;
		break;
		case 4:
		TWSR = 1;
		break;
		case 16:
		TWSR = 2;
		break;
		case 64:
		TWSR = 3;
		break;
		
	}
}

void MCAL_TWI_Master_Transmit(uint8_t T_data)
{
	//1. set a delay
	_delay_ms(2000);
	
	//2. send start bit
	TWI_Start();
	
	//3. send SLA+W
	TWI_Write(0b11010000+0);
	while(TWSR != 0x18);
	
	//4. send byte i of data
	TWI_Write(T_data);
	while(TWSR != 0x28);
	
	//5. send stop bit
	TWI_Stop();
}

void MCAL_TWI_Master_Receive(uint8_t R_data)
{
	//1. set a delay
	_delay_ms(2000);
	
	//2. send start bit
	TWI_Start();
	
	//3. send SLA+R
	TWI_Write(0b11010000+1);
	while(TWSR != 0x40);
	
	//4. read data
	R_data = TWI_MASTER_Read(0);
	
	//5. send stop bit
	TWI_Stop();
}

uint8_t MCAL_TWI_Slave_Receive()
{
	//read SLA+W
	return TWI_SLAVE_Read(1);
}


void MCAL_TWI_Slave_Transmit(uint8_t T_data)
{
	
}