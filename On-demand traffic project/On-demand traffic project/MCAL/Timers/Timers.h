/*
 * Timers.h
 *
 * Created: 9/12/2022 4:24:31 PM
 *  Author: Hager Samir
 */ 


#ifndef TIMERS_H_
#define TIMERS_H_
#include "../DIO/DIO.h"

/*************************** Function Prototype ******************************/

/*
 * Description : // Timer0 initialization ///
 * This function takes void and return void 
 // set timer configuration
 //1) mode of operation
 //2) setting timer initial value
 //3) setting timer prescaler 
 */
void Timer0_Init();
/*
 * Description : // delay counter ///
 * This function takes The needed time delay in ms  and return void 
 // calculate tick time 
 // and max delay for this timer 
 // and check for three cases to calculate timer initial value and no. of over flows needed 
 */
void Timer0_delay();

#endif /* TIMERS_H_ */






