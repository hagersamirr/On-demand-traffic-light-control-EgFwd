/*
 * buttons.c
 *
 * Created: 9/12/2022 4:22:01 PM
 *  Author: Hager Samir
 */ 

#include "buttons.h"
/*
 * Description : // initializations ///
 * This function takes the button PORT and pin  
 * Setup the direction of the Button pin as an input.
 */
void BUTTON_INIT(uint8_t ButtonPort, uint8_t ButtonPin)
{
	DIO_setPinDirection (ButtonPort, ButtonPin, PIN_INPUT);
}
/*
 * Description : // Read button state //
 * Read and return the value for the required pin, it should be Logic High or Logic Low.
 */
void BUTTON_READ(uint8_t ButtonPort, uint8_t ButtonPin, uint8_t * value)
{
	DIO_readPin( ButtonPort, ButtonPin, value );
	
}
// when calling 
// create variable uint8_t button state 
//BUTTON_READ( ButtonPort, ButtonPin, &button state)