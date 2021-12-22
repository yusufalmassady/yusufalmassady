/*
 * main.c
 *
 *  Created on: Dec 12, 2021
 *      Author: SAMA
 */

#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/RCC_interface.h"
#include "../include/GPIO_interface.h"
#include "../include/NVIC_interface.h"
#include "../include/EXTI_interface.h"
void ISR_Led(void);
void main(void)
{
    MRCC_voidSystemClockIntit();
	MRCC_voidEnablePeripheralClock(RCC_APB2,2);
	MRCC_voidEnablePeripheralClock(RCC_APB2,3);
	MEXTI_voidSetInterruptPin(EXTI_LINE0);
	MEXTI_voidEXTISetSenseControl(EXTI_LINE0,RISING_EDGE);
    MEXTI_voidSetCallback(EXTI_LINE0,ISR_Led);
	MNVIC_voidEnablePeripheralInterrupt(6);
	MGPIO_voidSetPinDirection(PORTA,0,INPUT_PULL_UP_DOWN);
	MGPIO_voidSetPinDirection(PORTB,0,OUTPUT_2MHZ_PP);

	while (1)
	{

	}

}


void ISR_Led(void)
{


		MGPIO_voidSetPinValue(PORTB,0,GPIO_HIGH);

}
