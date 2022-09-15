/*
 * DIO.c
 *
 * Created: 9/12/2022 4:24:02 PM
 *  Author: Hager Samir
 */ 


#include "DIO.h"



/*
 * Description :
 * Setup the direction of the required pin input/output.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
void DIO_setPinDirection(uint8_t port_num, uint8_t pin_num, uint8_t direction)
{
	/*
	 * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
	 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	 * In this case the input is not valid port/pin number
	 */
	if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS))
	{
		/* Do Nothing */
	}
	else
	{
		/* Setup the pin direction as required */
		switch(port_num)
		{
		case PORTA_ID:
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(DDRA,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRA,pin_num);
			}
			break;
		case PORTB_ID:
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(DDRB,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRB,pin_num);
			}
			break;
		case PORTC_ID:
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(DDRC,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRC,pin_num);
			}
			break;
		case PORTD_ID:
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(DDRD,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRD,pin_num);
			}
			break;
		}
	}
}

/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will not handle the request.
 * If the pin is input, this function will enable/disable the internal pull-up resistor.
 */
void DIO_writePin(uint8_t port_num, uint8_t pin_num, uint8_t value)
{
	if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS))
		{
			/* Do Nothing */
		}
		else
		{
			/* Setup the pin direction as required */
			switch(port_num)
			{
			case PORTA_ID:
				if(value == PIN_OUTPUT)
				{
					SET_BIT(PORTA,pin_num);
				}
				else
				{
					CLEAR_BIT(PORTA,pin_num);
				}
				break;
			case PORTB_ID:
				if(value == PIN_OUTPUT)
				{
					SET_BIT(PORTB,pin_num);
				}
				else
				{
					CLEAR_BIT(PORTB,pin_num);
				}
				break;
			case PORTC_ID:
				if(value == PIN_OUTPUT)
				{
					SET_BIT(PORTC,pin_num);
				}
				else
				{
					CLEAR_BIT(PORTC,pin_num);
				}
				break;
			case PORTD_ID:
				if(value == PIN_OUTPUT)
				{
					SET_BIT(PORTD,pin_num);
				}
				else
				{
					CLEAR_BIT(PORTD,pin_num);
				}
				break;
			}
		}

}

/*
 * Description :
 * Read and return the value for the required pin, it should be Logic High or Logic Low.
 * If the input port number or pin number are not correct, The function will return Logic Low.
 */
void DIO_readPin(uint8_t port_num, uint8_t pin_num, uint8_t *value )
{
	//uint8_t value= LOGIC_LOW;
     
	if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS))
	{
		//return value;
		/* Do Nothing */
	}
	else
	{
		/* Setup the pin direction as required */
		switch(port_num)
		{
		case PORTA_ID:
			if(BIT_IS_SET(PINA, pin_num))
			{
				*value=LOGIC_HIGH;
				//return  value	;
			}
			else
			{
				 *value= LOGIC_LOW;
				//return value	;
			}
			break;
		case PORTB_ID:
			if(BIT_IS_SET(PINB, pin_num))
			{
				*value=LOGIC_HIGH;
			//	return  value	;
			}
			else
			{
				* value= LOGIC_LOW;
				//return value	;
			}
			break;
		case PORTC_ID:
			if(BIT_IS_SET(PINC,pin_num))
			{
				* value=LOGIC_HIGH;
				//return  value	;
			}
			else
			{
				 * value= LOGIC_LOW;
				//return value	;

			}
			break;
		case PORTD_ID:
			if(BIT_IS_SET(PIND ,pin_num))
			{
				* value=LOGIC_HIGH;
			//	return  value	;
			}
			else
			{
				 * value= LOGIC_LOW;
				// return value	;

			}
			break;
		}
	}
	//return value;
}

void DIO_toggle(uint8_t portNumber, uint8_t pinNumber)
{
	switch(portNumber){
		case PORTA_ID:
		TOGGLE_BIT(PORTA,pinNumber);
		break;
		case PORTB_ID:
		TOGGLE_BIT(PORTB,pinNumber);
		break;
		case PORTC_ID:
		TOGGLE_BIT(PORTC,pinNumber);
		break;
		case PORTD_ID:
		TOGGLE_BIT(PORTD,pinNumber);
		break;
	}
}