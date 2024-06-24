
#include "DIO.h"
#include "Bit_Operations.h" /* To use the macros like SET_BIT */
#include <avr/io.h> /* To use the IO Ports Registers */



void DIO_init(void){

	SET_BIT(DDRB,PIN0);//MCU reset
	SET_BIT(DDRB,PIN5);//WDT counter reset
	SET_BIT(DDRC,PIN0); // LED manage
	SET_BIT(DDRC,PIN4);//WDGM_mainfunction
	SET_BIT(DDRD,PIN0);//LED toggle
//	SET_BIT(DDRC,PIN5);//ISR calling


};



void DIO_writePin(uint8 port_num, uint8 pin_num, uint8 value)
{
	if((port_num > 4) || (pin_num > 8))
	{
	   /* Do Nothing */
	}
	else
	{
		switch(port_num)
		{

		case 1:
			if(value == 1)
			{
				SET_BIT(PORTB, pin_num);
			}
			else
			{
				CLEAR_BIT(PORTB, pin_num);
			}
			break;
		case 2:
			if(value == 1)
			{
				SET_BIT(PORTC, pin_num);
			}
			else
			{
				CLEAR_BIT(PORTC, pin_num);
			}
			break;
		case 3:
			if(value == 1)
			{
				SET_BIT(PORTD, pin_num);
			}
			else
			{
				CLEAR_BIT(PORTD, pin_num);
			}
			break;
		}
	}
}

