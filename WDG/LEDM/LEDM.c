#include "LEDM.h"

#include "DIO.h"
#include "WDGM.h"
#include <avr/io.h> /* To use the IO Ports Registers */

#include <util/delay.h>

static uint16 LEDTimer = 0;
volatile uint8 LEDState;



void LEDM_Init(void) {
    // Initialize the GPIO pin for the LED
	DIO_init();
	LEDState= 1;

    // Initialize the internal variables
    LEDTimer = 0;
    // Set initial LED state
    DIO_writePin(3,0, LEDState);
}

void LEDM_Manage(void) {
    // Increment the timer

    LEDTimer+=5; // Called every 10ms

    // Check if 500ms have passed
    if (LEDTimer >400) {
        // Toggle LED state
    	if(LEDState==0)
    		LEDState=1;
		else
			LEDState=0;

        DIO_writePin(3,0, LEDState);
        // Reset the timer
        LEDTimer = 0;
    }
	DIO_writePin(2, PIN0, 1);
	_delay_ms(1);
	DIO_writePin(2, PIN0, 0);

    WDGM_AlivenessIndication();

}
