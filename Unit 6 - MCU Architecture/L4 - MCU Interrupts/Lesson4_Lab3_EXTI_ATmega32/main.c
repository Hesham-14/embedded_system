/*
 * main.c
 *
 *  Created on: Apr 18, 2023
 *      Author: Hesham Mohamed
 *      
 */

#define F_CPU 8000000ul
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

//define functions
#define SET_BIT(ADDRESS, BIT) ADDRESS |= (1 << BIT)
#define RESET_BIT(ADDRESS, BIT) ADDRESS &= ~(1 << BIT)
#define TOGGLE_BIT(ADDRESS, BIT) ADDRESS ^= (1 << BIT)
#define READ_BIT(ADDRESS, BIT) ((ADDRESS & (1 << BIT)) >> BIT)

//define PORTs
#define IO_BASE 0x20
#define IO_PORTD *(volatile unsigned char *)(IO_BASE + 0X12)
#define IO_DDRD *(volatile unsigned char *)(IO_BASE + 0X11)

#define IO_PORTB *(volatile unsigned char *)(IO_BASE + 0X18)
#define IO_DDRB *(volatile unsigned char *)(IO_BASE + 0X17)

//define INT
#define SREG *(volatile unsigned char* const)(IO_BASE + 0X3f)
#define INT_MCUCR *(volatile unsigned char* const)(IO_BASE + 0X35)
#define INT_MCUCSR *(volatile unsigned char* const)(IO_BASE + 0X34)
#define INT_GICR *(volatile unsigned char* const)(IO_BASE + 0X3B)
#define INT_GIFR *(volatile unsigned char* const)(IO_BASE + 0X3A)

void PORT_init()
{
    //set output pins 5,6,7 in DDRD
    SET_BIT(IO_DDRD, 5);
    SET_BIT(IO_DDRD, 6);
    SET_BIT(IO_DDRD, 7);

    //set input pins 2,3 in PORTD & 2 in PORTB

}
void INT_init()
{
    //SREG: enable global interrupt
    sei();
    //OR
    /*SET_BIT(SREG,7);*/

    //GICR: enable INTs
    SET_BIT(INT_GICR,6);
    SET_BIT(INT_GICR,7);
    SET_BIT(INT_GICR,5);

    //GIFR:enable INTs flags
    SET_BIT(INT_GIFR,6);
    SET_BIT(INT_GIFR,7);
    SET_BIT(INT_GIFR,5);

    //set any triger for INT0
    SET_BIT(INT_MCUCR,0);
    RESET_BIT(INT_MCUCR,0);

    //set rising triger for INT1
    SET_BIT(INT_MCUCR,2);
    SET_BIT(INT_MCUCR,3);

    //set falling triger for INT2
    SET_BIT(INT_MCUCSR,6);

}

int main()
{
    PORT_init();
    INT_init();
    
    while(1)
    {
    }

    return 0;
}

ISR(INT0_vect)
{
    SET_BIT(IO_PORTD,5);
    _delay_ms(1000);
    RESET_BIT(IO_PORTD,5);
}

ISR(INT1_vect)
{
    SET_BIT(IO_PORTD,6);
    _delay_ms(1000);
    RESET_BIT(IO_PORTD,6);
}

ISR(INT2_vect)
{
    SET_BIT(IO_PORTD,7);
    _delay_ms(1000);
    RESET_BIT(IO_PORTD,7);
}
