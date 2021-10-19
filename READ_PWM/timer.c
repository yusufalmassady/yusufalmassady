/*
 * timer.c
 *
 *  Created on: Dec 23, 2017
 *      Author: Mina
 */

#define F_CPU 8000000
#include <avr/delay.h>
#include "std_types.h"
#include "registers.h"
#include "DIO.h"
#include "utilss.h"

void timer0_pwm_init(void)
{
	TCCR0=0b01101101;
	//set pin B3(OC0) as Output because it will output the PWM signal
	DIOSetPinDirection(1,3,1);
	OCR0=194;
}

void timer1_pwm_init(void)
{

	set_bit(SREG,7);

	TCCR1A = 0b00000000;
	TCCR1B = 0b01000001;

	//enable overflow interrupt
	set_bit(TIMSK,2);
	//enable Input capture interrupt
	set_bit(TIMSK,5);

	//set pin D6(ICP) as Input because it will read the PWM signal
	DIOSetPinDirection(3,6,0);
}
