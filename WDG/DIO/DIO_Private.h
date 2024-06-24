#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H



/*
	REGISTER FOR PORTB, DDRB, PINB
	1.SET PORT ADDRESS
	2.SET DDR ADDRESS
	3.SET PIN ADDRESS
*/

#define PORTB *((volatile uint8 *)0x25)
#define DDRB *((volatile uint8 *)0x24)
#define PINB *((volatile uint8 *)0x23)


/*
	REGISTER FOR PORTC, DDRC, PINC
	1.SET PORT ADDRESS
	2.SET DDR ADDRESS
	3.SET PIN ADDRESS
*/

#define PORTC *((volatile uint8 *)0x28)
#define DDRC *((volatile uint8 *)0x27)
#define PINC *((volatile uint8 *)0x26)


/*
	REGISTER FOR PORTD, DDRD, PIND
	1.SET PORT ADDRESS
	2.SET DDR ADDRESS
	3.SET PIN ADDRESS
*/

#define PORTD *((volatile uint8 *)0x2B)
#define DDRD *((volatile uint8 *)0x2A)
#define PIND *((volatile uint8 *)0x29)





#endif
