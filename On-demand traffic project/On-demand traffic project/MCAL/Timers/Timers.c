/*
 * Timers.c
 *
 * Created: 9/12/2022 4:24:53 PM
 *  Author: Hager Samir
 */ 

#include "Timers.h"
#include <math.h>


/*
 * Description : // Timer0 initialization ///
 * This function takes void and return void 
 // set timer configuration
 //1) mode of operation
 //2) setting timer initial value
 //3) setting timer prescaler 
 */
void Timer0_Init()
{ 
 // choose timer mode
 TCCR0 =0x00;     // normal mode
 // timer set initial value
 TCNT0 =0X00; // 
// while(1){
 //start timer -> by setting prescaler value 1024
 TCCR0 |= (1<<0) | (1<<2);
 
}
/*
 * Description : // delay counter ///
 * This function takes The needed time delay in ms  and return void 
 // calculate tick time 
 // and max delay for this timer 
 // and check for three cases to calculate timer initial value and no. of over flows needed 
 */
void Timer0_delay(int Time_delay)
{
unsigned int overflowCounter=0;
unsigned int Number_of_OVERFLOWs;
double T_maxdelay ,T_tick;
int InitialTimerValue;
// at Frequency 1MHZ & prescaler 1024
//T_tick= prescaler/ CPU frequency
T_tick = 1024.0 / 1000.0; // milLi second
// Tmaxdelay = Ttick * 2^n -> 8-bit timer
T_maxdelay = T_tick * 256; // milli seconds
////////// FIRST CASE //////////////
if(Time_delay<T_maxdelay)
{
	InitialTimerValue = (T_maxdelay-Time_delay)/T_tick;
	Number_of_OVERFLOWs = 1;
	
}
////////// SECOND CASE //////////////
else if(Time_delay == (int)T_maxdelay)
{
	InitialTimerValue=0;
	Number_of_OVERFLOWs=1;
}
////////// THIRD CASE //////////////
else
{
	Number_of_OVERFLOWs = ceil((double)Time_delay/T_maxdelay);
	InitialTimerValue = 256 - ((double)Time_delay/T_tick)/Number_of_OVERFLOWs;
	
}
/////// busy waiting for over flow flag 
while (overflowCounter < Number_of_OVERFLOWs){
		while (( TIFR & (1<<0) )==0 )
		{
			//	 wait for the flag
		}
		//clear the overflow flag
	          	TIFR |= (1<<0);
		overflowCounter++;
	}
	overflowCounter =0;
	// delay 5000 ms
	// wait until the overflow flag to be set
	// timer stop
	//TCCR0 = 0x00;
}





///////// function delay adema 

/*
void Timer0_delay_5000ms()
{

 while (overflowCounter < Number_of_OVERFLOWs){
	 while (( TIFR & (1<<0) )==0 ){
		 //	 wait for the flag
	 }
	 //clear the overflow flag
	 TIFR |= (1<<0);
	 overflowCounter++;
 }
 overflowCounter =0;
 // delay 5000 ms
 // wait until the overflow flag to be set
 // timer stop
 //TCCR0 = 0x00;
}
 */
 
 
 
 
 
 