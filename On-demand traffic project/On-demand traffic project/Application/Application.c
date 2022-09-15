/*
 * Application.c
 *
 * Created: 9/13/2022 7:43:22 PM
 *  Author: Hager Samir
 */ 
#include "Application.h"
 boolean Yellow_is_blinking=0;
 boolean buttonClick =0;
 
 
/*
 * Description : //  initializations  for each peripheral ///
 * This function takes void and return void 
 1- Initialize port A, pins 0, 1, and 2  Green, Yellow, and Red
           as LEDs for cars traffic light  
 2- Initialize port B, pins 0, 1, and 2   Green, Yellow, and Red
             as LEDs  for pedestrians  traffic light
 3- Initialize One push button connected to INT0 pin for pedestrian
 4- Initialize Timer 0 
 5- Initialize interrupt 0
 */
void app_inits(void)
{
		//// CAR_LEDS INITIALIZATIONSS
		LED_INIT(PORTA_ID,PIN0_ID);  // GREEN LED FOR CARS
		LED_INIT(PORTA_ID,PIN1_ID);  // YELLOW LED FOR CARS
		LED_INIT(PORTA_ID,PIN2_ID);  // RED LED FOR CARS
		
		//// PEDESTRIANS_LEDS INITIALIZATIONSS
		LED_INIT(PORTB_ID,PIN0_ID);  // GREEN LED FOR PEDESTRIANS
		LED_INIT(PORTB_ID,PIN1_ID);  // YELLOW LED FOR PEDESTRIANS
		LED_INIT(PORTB_ID,PIN2_ID);  // RED LED FOR PEDESTRIANS
		
		/////////LED_INIT(PORTA_ID,PIN6_ID); 
		
		//// PEDESTRIANS_Push_BUTTON INITIALIZATION
		BUTTON_INIT(PORTD_ID, PIN2_ID);
		
		//// Timer 0 INITIALIZATION
		Timer0_Init();
		
		//// Interrupt 0 INITIALIZATION
		Interrupt0_init ();
}


 
/*
 * Description : // NORMAL MODE ///
 * This function takes void and return void 
 Cars' LEDs will be changed every five seconds starting from Green then yellow then red then yellow then Green.
 Pedestrians' LEDs is opposite to cars' LEDs
 The Yellow LED of both  will blink for five seconds before moving to Green or Red LEDs.
 */
void app_start(void)
{
// 	LED_ON(PORTA_ID,PIN6_ID);
// 	Timer0_delay(3000);
// 	LED_OFF(PORTA_ID,PIN6_ID);

// Green led for cars & Red led for ped. is on for five seconds

	LED_ON(PORTA_ID,PIN0_ID);  // GREEN LED FOR CARS
	LED_ON(PORTB_ID,PIN2_ID);  // RED LED FOR PEDESTRIANS
	Timer0_delay(5000);
	
// After 5 second  Green led for cars & Red led for ped. switched OFF 
// And yellow LEDs of both will blinking for five second
  
	LED_OFF(PORTA_ID,PIN0_ID);  // GREEN LED FOR CARS
	LED_OFF(PORTB_ID,PIN2_ID);  // RED LED FOR PEDESTRIANS
	Blinking_yellow ();
	LED_OFF(PORTA_ID,PIN1_ID);  // YELLOW LED FOR CARS
	LED_OFF(PORTB_ID,PIN1_ID);  // YELLOW LED FOR PEDESTRIANS
	
// After yellow blinking for 5 seconds 
// Red led for cars & green led for ped. is on for five seconds
// then yellow blinking again 

	LED_ON(PORTA_ID,PIN2_ID);  // RED LED FOR CARS
	LED_ON(PORTB_ID,PIN0_ID);  // GREEN LED FOR PEDESTRIANS
	Timer0_delay(5000);
	LED_OFF(PORTA_ID,PIN2_ID); // RED LED FOR CARS
	LED_OFF(PORTB_ID,PIN0_ID);  // GREEN LED FOR PEDESTRIANS
	
	Blinking_yellow ();
	
	LED_OFF(PORTA_ID,PIN1_ID);  // YELLOW LED FOR CARS
	LED_OFF(PORTB_ID,PIN1_ID);  // YELLOW LED FOR PEDESTRIANS

}
/*
 * Description : // Blinking yellow leds ///
 * This function takes void and return void 
  it toggles the yellow leds of both cars and ped. every 500 ms for 5 
 */
void Blinking_yellow ()
{
	 Yellow_is_blinking = 1;
	LED_TOGGLE(PORTA_ID,PIN1_ID);
    LED_TOGGLE(PORTB_ID,PIN1_ID);  // YELLOW LED FOR PEDESTRIANS
	Timer0_delay(500);
	LED_TOGGLE(PORTA_ID,PIN1_ID);
	 LED_TOGGLE(PORTB_ID,PIN1_ID);  // YELLOW LED FOR PEDESTRIANS
	Timer0_delay(500);
	LED_TOGGLE(PORTA_ID,PIN1_ID);
	 LED_TOGGLE(PORTB_ID,PIN1_ID);   // YELLOW LED FOR PEDESTRIANS
	Timer0_delay(1000);
	LED_TOGGLE(PORTA_ID,PIN1_ID);
	 LED_TOGGLE(PORTB_ID,PIN1_ID);   // YELLOW LED FOR PEDESTRIANS
	Timer0_delay(500);
	LED_TOGGLE(PORTA_ID,PIN1_ID);
	 LED_TOGGLE(PORTB_ID,PIN1_ID); // YELLOW LED FOR PEDESTRIANS
	Timer0_delay(500);
	LED_TOGGLE(PORTA_ID,PIN1_ID);
	 LED_TOGGLE(PORTB_ID,PIN1_ID);  // YELLOW LED FOR PEDESTRIANS
	Timer0_delay(1000);
	LED_TOGGLE(PORTA_ID,PIN1_ID);
	 LED_TOGGLE(PORTB_ID,PIN1_ID);   // YELLOW LED FOR PEDESTRIANS
	Timer0_delay(500);
	LED_TOGGLE(PORTA_ID,PIN1_ID);
	 LED_TOGGLE(PORTB_ID,PIN1_ID);  // YELLOW LED FOR PEDESTRIANS
	Timer0_delay(500);

	 Yellow_is_blinking = 0;
}
 
/*
 * Description : // Pedestrians MODE ///
 * This function takes void and return void 
Change from normal mode to pedestrian mode when the pedestrian button is pressed.
1- If pressed when the cars' Red LED is on
 ---> the pedestrian's Green LED and the cars' Red LEDs will be on for five seconds,
 this means that pedestrians can cross the street while the pedestrian's Green LED is on.
 
2-If pressed when the cars' Green LED is on or the cars' Yellow LED is blinking,
--> the pedestrian Red LED will be on -- then both Yellow LEDs start to blink for five seconds,
 --then the cars' Red LED and pedestrian Green LEDs are on for five seconds,
  this means that pedestrian must wait until the Green LED is on.
  
-------------->>>>>>> At the end of the two states  <<<<<<------------------
 the cars' Red LED will be off and both Yellow LEDs start blinking for 5 seconds
 and the pedestrian's Green LED is still on.
After the five seconds the pedestrian Green LED will be off and both the pedestrian Red LED and the cars' Green LED will be on.
Traffic lights signals are going to the normal mode again.
 */

void Allow_ped ()
{
	/*                  FIRST CASE 
	       If BUTTON is pressed when the cars' Red LED is on
	 the pedestrian's Green LED and the cars' Red LEDs will be on for five seconds
	*/ 
	if ( BIT_IS_SET(PINA,PIN2_ID) )  // check if the button is pressed when the cars' RED LED is on
	 {   LED_ON(PORTA_ID,PIN2_ID);  // RED LED FOR CARS
		 LED_ON(PORTB_ID,PIN0_ID);  // GREEN LED FOR PEDESTRIANS
	   	Timer0_delay(5000);	   
	 }
	 /*                  SECOND CASE 
	      If BUTTON is pressed when the cars' Green LED is on or the cars' Yellow LED is blinking,
	*/ 
	 else if ( BIT_IS_SET(PINA,PIN0_ID) ||   Yellow_is_blinking ==1) 
	 {   
  // the pedestrian Red LED will be on 
		 LED_OFF(PORTA_ID,PIN0_ID);  // GREEN LED FOR CARS
		 LED_ON(PORTB_ID,PIN2_ID);  // RED LED FOR PEDESTRIANS
// then both Yellow LEDs start to blink for five seconds,
	    	Blinking_yellow ();
		 LED_OFF(PORTA_ID,PIN1_ID);  // YELLOW LED FOR CARS
		 LED_OFF(PORTB_ID,PIN1_ID);  // YELLOW LED FOR PEDESTRIANS
		  LED_OFF(PORTB_ID,PIN2_ID);  // RED LED FOR PEDESTRIANS
// then the cars' Red LED and pedestrian Green LEDs are on for five seconds,
		 LED_ON(PORTA_ID,PIN2_ID);  // RED LED FOR CARS
		 LED_ON(PORTB_ID,PIN0_ID);  // GREEN LED FOR PEDESTRIANS
		  Timer0_delay(5000);
	 }
// 	 -------------->>>>>>> At the end of the two states  <<<<<<------------------

// 	 the cars' Red LED will be off and both Yellow LEDs start blinking for 5 seconds
// 	 and the pedestrian's Green LED is still on
	  LED_OFF(PORTA_ID,PIN2_ID);  // RED LED FOR CARS
		Blinking_yellow ();
	  LED_OFF(PORTA_ID,PIN1_ID);  // YELLOW LED FOR CARS
	  LED_OFF(PORTB_ID,PIN1_ID);  // YELLOW LED FOR PEDESTRIANS
	  
//   After 5 seconds the pedestrian Green LED will be off 
//   and both the pedestrian Red LED and the cars' Green LED will be on.
	  LED_OFF(PORTB_ID,PIN0_ID);  // GREEN LED FOR PEDESTRIANS
	  
	  LED_ON(PORTA_ID,PIN0_ID);  // GREEN LED FOR CARS
	  LED_ON(PORTB_ID,PIN2_ID);  // RED LED FOR PEDESTRIANS
	  Timer0_delay(5000);
	  LED_OFF(PORTA_ID,PIN0_ID);  // GREEN LED FOR CARS
	  LED_OFF(PORTB_ID,PIN2_ID);  // RED LED FOR PEDESTRIANS
	  
	  
  //      buttonClick =0;
        //app_start();
// 		LED_ON(PORTA_ID,PIN6_ID);
// 		Timer0_delay(3000);
// 		LED_OFF(PORTA_ID,PIN6_ID);
}

ISR (INT0_vect)
{
	Allow_ped ();
	
}
