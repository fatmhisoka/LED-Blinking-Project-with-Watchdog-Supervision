#include "DIO.h"
#include "LEDM.h"
#include "WDGM.h"
#include "WDGDRV.h"
#include <util/delay.h>
#include <avr/wdt.h>
#include <avr/io.h>
#include <avr/interrupt.h>


#define PRESCALER 64
#define TIMER1_INTERVAL_MS 50

void timer1_init() {

    // Set entire TCCR1A register to 0
    TCCR1A = 0;

    // Set entire TCCR1B register to 0
    TCCR1B = 0;

    // Turn on CTC (Clear Timer on Compare Match) mode by setting WGM12 bit in TCCR1B register
    TCCR1B |= (1 << WGM12);

    // Calculation for OCR1A:
    // F_CPU = 1 MHz, PRESCALER = 64, TIMER1_INTERVAL_MS = 50 ms
    // Equation: (F_CPU / PRESCALER) * TIMER1_INTERVAL_MS / 1000 - 1;
    // Plugging in values: (1000000 / 64) * 50 / 1000 - 1 = 781.25
    // OCR1A is set to 800 for some additional margin
    OCR1A = 800; // Set Output Compare Register A to 800

    // Enable Timer/Counter1 Output Compare Match A Interrupt
    TIMSK1 |= (1 << OCIE1A);

    // Set the prescaler to 64 and start the timer by setting CS11 and CS10 bits in TCCR1B
    TCCR1B |= (1 << CS11) | (1 << CS10);

}




ISR(TIMER1_COMPA_vect) {
	WDGDrv_IsrNotification();

}


int main(){

	DIO_init();
	DIO_writePin(1, PIN0, 1);
//	_delay_ms(1);
//	DIO_writePin(1, PIN0, 0);
	LEDM_Init();
	WDGM_Init();
	WDGDrv_Init();
	timer1_init();

	int wdg_counter = 0;
	int senario = 4 ;

	while(1){
		switch(senario){
		    case 1:
                // Positive scenario
		        _delay_ms(10);
		        LEDM_Manage();

		    	wdg_counter++;
		    	if (wdg_counter>=2){
		    		WDGM_MainFunction();
		    		wdg_counter=0;
		    	}
		    	break;

		    case 2:
                // Negative scenario: Comment WDGM_MainFunction
		    	_delay_ms(10);
		    	LEDM_Manage();
		    	break;

		    case 3:
                // Negative scenario: Comment WDGM_AlivenessIndication from LEDM_Manage
		    	_delay_ms(10);
		    	LEDM_Manage();
		    	wdg_counter++;
		        if (wdg_counter>=2){
		    		WDGM_MainFunction();
		    	    wdg_counter=0;
		    	}
		        break;

		    case 4:
                // Negative scenario: Change periodicity of LEDM_Manage to every 5ms
		    	_delay_ms(5);
		    	LEDM_Manage();
		    	wdg_counter++;
		        if (wdg_counter>=4){
		    	    WDGM_MainFunction();
		    		wdg_counter=0;
		    	}
		    	break;

		    default:
		        break;
		}

	}
	return 0;
}

