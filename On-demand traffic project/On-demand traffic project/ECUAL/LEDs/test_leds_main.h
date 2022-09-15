/*
 * test_leds_main.h
 *
 * Created: 9/14/2022 6:20:59 PM
 *  Author: Hager Samir
 */ 


#ifndef TEST_LEDS_MAIN_H_
#define TEST_LEDS_MAIN_H_
 #include "Leds.h"
 
 #include "util/delay.h"
void main_for_testing_leds ()
{
	 // TESTING LEDS DRIVER ////
	 
	 LED_INIT (PORTA_ID,PIN6_ID);
	 while (1)
	 { 
		 LED_ON (PORTA_ID,PIN6_ID);
		 _delay_ms (5000);
		 LED_OFF (PORTA_ID,PIN6_ID);
		 _delay_ms (5000);
		 LED_TOGGLE (PORTA_ID,PIN6_ID);
	 }
}
#endif /* TEST_LEDS_MAIN_H_ */