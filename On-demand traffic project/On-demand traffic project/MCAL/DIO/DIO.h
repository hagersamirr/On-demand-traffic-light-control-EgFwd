/*
 * DIO.h
 *
 * Created: 9/12/2022 4:24:12 PM
 *  Author: Hager Samir
 */ 


#ifndef DIO_H_
#define DIO_H_
#include <avr/io.h>  /* To use the IO Ports Registers */

// all internal driver typedefs
//all driver macros
// all function proto types

/*******************************************************************************
 *                                STD types                                  *
 *******************************************************************************/

/* Boolean Data Type */
typedef unsigned char boolean;

/* Boolean Values */
#ifndef FALSE
#define FALSE       (0u)
#endif
#ifndef TRUE
#define TRUE        (1u)
#endif


#define NULL_PTR    ((void*)0)

typedef unsigned char         uint8_t;          /*           0 .. 255              */
typedef signed char           sint8_t;          /*        -128 .. +127             */
//typedef unsigned short           uint16_t;



/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define NUM_OF_PORTS           4
#define NUM_OF_PINS_PER_PORT   8

#define PORTA_ID               0
#define PORTB_ID               1
#define PORTC_ID               2
#define PORTD_ID               3

#define PIN0_ID                0
#define PIN1_ID                1
#define PIN2_ID                2
#define PIN3_ID                3
#define PIN4_ID                4
#define PIN5_ID                5
#define PIN6_ID                6
#define PIN7_ID                7
//////////////// Direction definitions //////////////////
#define PIN_INPUT                0
#define PIN_OUTPUT               1
//////////////// value  definitions //////////////////

#define LOGIC_HIGH        (1u)
#define LOGIC_LOW         (0u)
/*******************************************************************************
 *                                MACROS                                  *
 *******************************************************************************/

#define SET_BIT(REG,BIT) (REG|=(1<<BIT)) // Set a certain bit in any register 


#define CLEAR_BIT(REG,BIT) (REG&=(~(1<<BIT))) // Clear a certain bit in any register

#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT)) // Toggle a certain bit in any register 


#define ROR(REG,num) ( REG= (REG>>num) | (REG<<(8-num)) ) // Rotate right the register value with specific number of rotates 


#define ROL(REG,num) ( REG= (REG<<num) | (REG>>(8-num)) ) // Rotate left the register value with specific number of rotates 


#define BIT_IS_SET(REG,BIT) ( REG & (1<<BIT) ) // Check if a specific bit is set in any register and return true if yes 


#define BIT_IS_CLEAR(REG,BIT) ( !(REG & (1<<BIT)) ) // Check if a specific bit is cleared in any register and return true if yes 





/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description :
 * Setup the direction of the required pin input/output.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
void DIO_setPinDirection(uint8_t port_num, uint8_t pin_num, uint8_t direction);

/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will not handle the request.
 * If the pin is input, this function will enable/disable the internal pull-up resistor.
 */
void DIO_writePin(uint8_t port_num, uint8_t pin_num, uint8_t value);

/*
 * Description :
 * Read and return the value for the required pin, it should be Logic High or Logic Low.
 * If the input port number or pin number are not correct, The function will return Logic Low.
 */
void DIO_readPin(uint8_t port_num, uint8_t pin_num , uint8_t* value);



#endif /* DIO_H_ */



