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

#include "../include/IR_interface.h";


void main(void)
{
	//initialize system clock
    MRCC_voidSystemClockIntit();
    //enable clock for porta
	MRCC_voidEnablePeripheralClock(RCC_APB2,2);

	//enable pa0 as interrupt
	MEXTI_voidSetInterruptPin(EXTI_LINE0);
	//set interrupt mode
	MEXTI_voidEXTISetSenseControl(EXTI_LINE0,FALLING_EDGE);
	//set call back function for ISR
    MEXTI_voidSetCallback(EXTI_LINE0,HIR_voidGetFrame);

    //enable EXTIO as interrupt
	MNVIC_voidEnablePeripheralInterrupt(6);

	//setting pin direction
	MGPIO_voidSetPinDirection(PORTA,0,INPUT_FLOAT);
	MGPIO_voidSetPinDirection(PORTA,1,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(PORTA,2,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(PORTA,3,OUTPUT_2MHZ_PP);

	//Initializing SYSTICK
	MSTK_voidInit();


	while (1)
	{

	}

}



