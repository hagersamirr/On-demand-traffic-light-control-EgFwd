/*
 * test_buttons_main.h
 *
 * Created: 9/14/2022 6:36:02 PM
 *  Author: Hager Samir
 */ 


#ifndef TEST_BUTTONS_MAIN_H_
#define TEST_BUTTONS_MAIN_H_
#include "buttons.h"
#include "../LEDs/Leds.h"
 #include "util/delay.h"
 void main_for_testing_buttons ()
 {
	  // TESTING Buttons DRIVER ////
	  LED_INIT (PORTA_ID,PIN6_ID);
	  BUTTON_INIT(PORTD_ID, PIN2_ID);
	  while (1)
	  {
		  uint8_t button_state ;
		  BUTTON_READ(PORTD_ID, PIN2_ID, &button_state );
		  if (button_state == LOGIC_HIGH)
		  {
			  LED_ON (PORTA_ID,PIN6_ID);
		  }
		  else if (button_state == LOGIC_LOW)
		  {
			  LED_OFF (PORTA_ID,PIN6_ID);
		  }

	  }
 }




#endif /* TEST_BUTTONS_MAIN_H_ */