/*

 * main.c
 *
 *  Created on: Nov 18, 2021
 *      Author: SAMA
 */
#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/RCC_interface.h"
#include "../include/GPIO_interface.h"

void main(void)
{
	MRCC_voidSystemClockIntit();
	MRCC_voidEnablePeripheralClock(RCC_APB2,2);
	MRCC_voidEnablePeripheralClock(RCC_APB2,3);
	MRCC_voidEnablePeripheralClock(RCC_APB2,4);
	MGPIO_voidSetPinDirection(PORTA,0,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(PORTA,1,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(PORTA,2,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(PORTA,3,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(PORTA,4,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(PORTA,5,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(PORTA,6,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(PORTA,7,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(PORTA,8,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(PORTA,9,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(PORTA,10,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(PORTA,11,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(PORTA,12,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(PORTA,13,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(PORTA,14,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(PORTA,15,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(PORTB,0,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(PORTB,1,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(PORTB,2,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(PORTB,3,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(PORTB,4,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(PORTB,5,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(PORTB,6,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(PORTB,7,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(PORTB,8,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(PORTB,9,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(PORTB,10,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(PORTB,11,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(PORTB,12,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(PORTB,13,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(PORTB,14,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(PORTB,15,OUTPUT_2MHZ_PP);
	while (1)
	{
		MGPIO_voidSetPinValue(PORTA,0,GPIO_HIGH);
		MGPIO_voidSetPinValue(PORTA,1,GPIO_HIGH);
		MGPIO_voidSetPinValue(PORTA,2,GPIO_HIGH);
		MGPIO_voidSetPinValue(PORTA,3,GPIO_HIGH);
		MGPIO_voidSetPinValue(PORTA,4,GPIO_HIGH);
		MGPIO_voidSetPinValue(PORTA,5,GPIO_HIGH);
		MGPIO_voidSetPinValue(PORTA,6,GPIO_HIGH);
		MGPIO_voidSetPinValue(PORTA,7,GPIO_HIGH);
		MGPIO_voidSetPinValue(PORTA,8,GPIO_HIGH);
		MGPIO_voidSetPinValue(PORTA,9,GPIO_HIGH);
		MGPIO_voidSetPinValue(PORTA,10,GPIO_HIGH);
		MGPIO_voidSetPinValue(PORTA,11,GPIO_HIGH);
		MGPIO_voidSetPinValue(PORTA,12,GPIO_LOW);
		MGPIO_voidSetPinValue(PORTA,13,GPIO_HIGH);
		MGPIO_voidSetPinValue(PORTA,14,GPIO_HIGH);
		MGPIO_voidSetPinValue(PORTA,15,GPIO_HIGH);
		MGPIO_voidSetPinValue(PORTB,0,GPIO_HIGH);
		MGPIO_voidSetPinValue(PORTB,1,GPIO_HIGH);
		MGPIO_voidSetPinValue(PORTB,2,GPIO_HIGH);
		MGPIO_voidSetPinValue(PORTB,3,GPIO_HIGH);
		MGPIO_voidSetPinValue(PORTB,4,GPIO_HIGH);
		MGPIO_voidSetPinValue(PORTB,5,GPIO_HIGH);
		MGPIO_voidSetPinValue(PORTB,6,GPIO_HIGH);
		MGPIO_voidSetPinValue(PORTB,7,GPIO_HIGH);
		MGPIO_voidSetPinValue(PORTB,8,GPIO_HIGH);
		MGPIO_voidSetPinValue(PORTB,9,GPIO_HIGH);
		MGPIO_voidSetPinValue(PORTB,10,GPIO_HIGH);
		MGPIO_voidSetPinValue(PORTB,11,GPIO_HIGH);
		MGPIO_voidSetPinValue(PORTB,12,GPIO_HIGH);
		MGPIO_voidSetPinValue(PORTB,13,GPIO_HIGH);
		MGPIO_voidSetPinValue(PORTB,14,GPIO_HIGH);
		MGPIO_voidSetPinValue(PORTB,15,GPIO_HIGH);
	}
}


