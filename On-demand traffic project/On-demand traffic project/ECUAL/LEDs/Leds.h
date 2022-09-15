/*
 * Leds.h
 *
 * Created: 9/12/2022 4:21:43 PM
 *  Author: Hager Samir
 */ 


#ifndef LEDS_H_
#define LEDS_H_
#include "../../MCAL/DIO/DIO.h"

//////////////////////////////////////////////////////////
////            Functions Prototypes                /////
//////////////////////////////////////////////////////////
/*
 * Description : // initializations ///
 * This function takes the LED PORT and pin  
 * Setup the direction of the led pin as an output.
 */
void LED_INIT (uint8_t LED_PORT , uint8_t LED_PIN);
/*
 * Description : // turn led on 
 * This function takes the LED PORT and pin 
 * Write the value Logic High on the required led pin.
 */
void LED_ON (uint8_t LED_PORT , uint8_t LED_PIN);
/*
 * Description : // turn led off 
 * This function takes the LED PORT and pin 
 * Write the value Logic LOW on the required led pin.
 */
void LED_OFF (uint8_t LED_PORT , uint8_t LED_PIN);
/*
 * Description : // toggle led  
 * This function takes the LED PORT and pin 
 * change the state of the required pin (toggle it )
 */
void LED_TOGGLE (uint8_t LED_PORT , uint8_t LED_PIN);





#endif /* LEDS_H_ */