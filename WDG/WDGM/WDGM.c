#include "WDGM.h"
#include "Std_Types.h"
#include <util/delay.h>
#include "DIO.h"
#include <avr/io.h> /* To use the IO Ports Registers */

// Define static variables for WDGM state, call count, and cycle count
static WDGM_StatusType wdgm_state ;
static uint8 WDGM_call_count ;
static uint32 WDGM_CycleCount;

// Define the flag indicating whether WDGM_MainFunction is running
extern volatile uint8 WDGM_MainFunction_OK;

// Initialization function for WDGM
void WDGM_Init(void) {
    WDGM_call_count = 0;
    WDGM_CycleCount = 0;
    wdgm_state = OK;
    WDGM_MainFunction_OK = 0;
    DIO_init();

}

// Main function to be called periodically
void WDGM_MainFunction(void) {
	DIO_writePin(2, PIN4, 1);
	_delay_ms(1);
	DIO_writePin(2, PIN4, 0);

    WDGM_CycleCount++;

    // Check if within the 100ms window (5 * 20ms cycles)
    if (WDGM_CycleCount >= 5) {

        // Check if LEDM_Manage was called between 8 and 12 times in the last 100ms
        if (WDGM_call_count >= 8 && WDGM_call_count <= 12) {
            wdgm_state = OK;
        } else {
            wdgm_state = NOK;

        }

        // Reset the call count for the next period
        WDGM_call_count = 0;
        WDGM_CycleCount = 0;
    }

    // Set the flag indicating WDGM_MainFunction is running
    WDGM_MainFunction_OK++;


}

// Function to provide the current supervision status
WDGM_StatusType WDGM_PovideSuppervisionStatus(void) {
    return wdgm_state;
}

// Function to indicate aliveness by incrementing the call count
void WDGM_AlivenessIndication(void) {
    WDGM_call_count++;
}
