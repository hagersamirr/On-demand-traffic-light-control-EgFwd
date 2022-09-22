# On demand Traffic Light
Implemented a traffic lights system with an on-demand crosswalk button. Crosswalk buttons let the signal operations know that someone is planning to cross the street, so the light adjusts, giving the pedestrian enough time to get across.  

Traffic lights are signaling devices positioned at road intersections, pedestrian crossings, and other locations to control the flow of traffic. Traffic lights normally consist of three signals, transmitting meaning to drivers and riders through colors and symbols including arrows and bicycles.  

The regular traffic light colors are red, yellow, and green arranged vertically or horizontally in that order. Although this is internationally standardized, variations exist on national and local scales as to traffic light sequences and laws.  

## The project can be distributed over 4 main tasks:

### System Design
* Make full static architecture for your system.

### Prepare Development environment
* Apply layered architecture to project's folder structure.

### Application
* Implement drivers.
* Test your drivers.
* Implement system flow.

### Testing
* Test 5 user stories.
  
  
## Hardware
1. ATmega32 microcontroller.
2. One push button connected to (INT0 / INT1 / INT2) pin for pedestrian.
3. Three LEDs for cars (Green - Yellow - Red).
4. Three LEDs for pedestrians (Green - Yellow - Red).

## Application Logic
There are two modes.

### Normal mode
1. Cars' LEDs will be changed every five seconds starting from Green then yellow then red then yellow then Green.
2. The Yellow LED will blink for five seconds before moving to Green or Red LEDs.

### Pedestrian mode
1. Change from normal mode to pedestrian mode when the pedestrian button is pressed.
2. If pressed when the cars' Red LED is on, the pedestrian's Green LED and the cars' Red LEDs will be on for five seconds, this means that pedestrians can cross the street while the pedestrian's Green LED is on.
3. If pressed when the cars' Green LED is on or the cars' Yellow LED is blinking, the pedestrian Red LED will be on then both Yellow LEDs start to blink for five seconds, then the cars' Red LED and pedestrian Green LEDs are on for five seconds, this means that pedestrian must wait until the Green LED is on.
4. At the end of the two states, the cars' Red LED will be off and both Yellow LEDs start blinking for 5 seconds and the pedestrian's Green LED is still on.
5. After the five seconds the pedestrian Green LED will be off and both the pedestrian Red LED and the cars' Green LED will be on.
6. Traffic lights signals are going to the normal mode again.

## Drivers

### MCAL
* **DIO (Digital Input/Output):** this driver is responsible for the pins used to interface with external components. The driver customizes pins' direction to be input or output and their value to be high or low.
* **Interrupts:** 
Thiss driver contains:
`(Global Interrupt Enable)` the Global Interrupt (activation - deactivation) which is considered the global gate for all maskable interrupts.
`(External Interrupt)` responsible for all External Interrupt from setting the sense control for (INT0 - INT1 - INT2) and the call back function for each interrupt so that we can put the desired function in its ISR. 
* **TIMERS (Timer0 - Timer1 - Timer2):** this driver has 3 timers. Timer0 and Timer2 are 8-bit timers with their options and configurations. Timer2 is a 16-bit timer with its options and configurations.

### ECUAL
* **LED (Light Emitting Diode):** this driver contains options that facilitate the interfacing with LEDs by giving ID to every LED so that you can turn them on/off, toggle or blink with just their ID.
* **BUTTONS:** this driver contains options that facilitate the interfacing with Buttons by initializing their configuration and Read their state if is pressed or not 
## Drivers Structure
Every driver has 4 files `DriverName.h`  `DriverName.c`

* **DriverName.h**: this file has the prototypes of the function and the names of any custom inputs or and info I need to inform the user about it, but the user can't change anything in this file just can read it.

* **DriverName.c**: this file has the C code of all functions.



## User stories (Test cases)
* **User story 1:** As a pedestrian when I will make a short press on the crosswalk button while the cars green light is on and pedestrian red light is off, I will wait for the yellow lights to blink for five seconds then the cars red light is on and pededstrian green light is on for five seconds, so that I can cross the street.
* **User story 2:** As a pedestrian when I will make a short press on the crosswalk button while the cars yellow light is blinking and pedestrian red light is on, I will wait for all yellow lights to blink for five seconds then the cars red light is on and pededstrian green light is on for five seconds, so that I can cross the street
* **User story 3:** As a pedestrian when I will make a short press on the crosswalk button while the cars red light is on and pedestrian green light is on, I expect nothing to be done
* **User story 4:** As a pedestrian when I made a long press on the crosswalk button, I expect nothing to be done.
* **User story 5:** As a pedestrian when I made a double press on the crosswalk button, I expect that the first press will do the action and nothing to be done after the second press. 
