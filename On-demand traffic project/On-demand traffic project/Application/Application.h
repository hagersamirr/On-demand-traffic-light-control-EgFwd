/*
 * Application.h
 *
 * Created: 9/13/2022 7:43:49 PM
 *  Author: Hager Samir
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_
#include "../ECUAL/Buttons/buttons.h"
#include "../ECUAL/LEDs/Leds.h"
#include "../MCAL/Interrupts/Interrupts.h"
#include "../MCAL/Timers/Timers.h"
#include "../MCAL/DIO/DIO.h"


/*************************** Function Prototype ******************************/

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
void app_inits(void);

/*
 * Description : // NORMAL MODE ///
 * This function takes void and return void 
 Cars' LEDs will be changed every five seconds starting from Green then yellow then red then yellow then Green.
 Pedestrians' LEDs is opposite to cars' LEDs
 The Yellow LED of both  will blink for five seconds before moving to Green or Red LEDs.
 */
void app_start(void);

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
void Allow_ped (void);

/*
 * Description : // Blinking yellow leds ///
 * This function takes void and return void 
  it toggles the yellow leds of both cars and ped. every 500 ms for 5 
 */
void Blinking_yellow (void);


#endif /* APPLICATION_H_ */