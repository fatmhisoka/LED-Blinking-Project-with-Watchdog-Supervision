#include "WDGM.h"
#include "WDGDRV.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include "DIO.h"
#include <util/delay.h>
#include <avr/wdt.h>

volatile uint8 WDGM_MainFunction_OK;
// Function to initialize the Watchdog Timer
void WDGDrv_Init(void) {
    // Disable global interrupts
    cli();

    // Clear the Watchdog Reset Flag
    MCUSR &= ~(1 << WDRF);

    // Reset the watchdog timer
    wdt_reset();

    // Enable Watchdog Change Enable and Watchdog Enable
    WDTCSR |= (1 << WDCE) | (1 << WDE);

    // Set Watchdog Timer to system reset mode with a timeout of ~0.5s (prescaler set to WDP1)
    WDTCSR = (1 << WDE) | (1 << WDP1);

    // Enable global interrupts
    sei();
}

// ISR notification function for the watchdog
void WDGDrv_IsrNotification(void) {

    // Check if the main function of the WDGM module is running and if the supervision status is OK
    if ((WDGM_MainFunction_OK >= 2) && (WDGM_PovideSuppervisionStatus() == OK)) {
        // Refresh the watchdog timer by toggling a pin and resetting the watchdog
        DIO_writePin(1, PIN5, 1); // Set pin high
        _delay_ms(1);             // Delay for 1 millisecond
        DIO_writePin(1, PIN5, 0); // Set pin low
        wdt_reset();              // Reset the watchdog timer
    } else {
        // Enable watchdog with a timeout of 15 milliseconds
        wdt_enable(WDTO_15MS);
    }

    // Reset the watchdog main function OK flag
    WDGM_MainFunction_OK = 0;
}

