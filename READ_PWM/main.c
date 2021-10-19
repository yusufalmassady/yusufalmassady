/*
 * main.c

 *
 *  Created on: Dec 2, 2017
 *      Author: Mina Medhat
 */

#define F_CPU 8000000
#include <util/delay.h>
#include "std_types.h"
#include "registers.h"
#include "DIO.h"
#include "timer.h"
#include "LCD.h"
#include "utilss.h"

volatile u32 counter=0,c1,c2,c3,flag=0;

void __vector_6 (void)  __attribute__((signal,__INTR_ATTRS));
void __vector_6 (void)
{
	if (flag==0)
	{
		c1=ICR1;
		counter=0;
		clr_bit(TCCR1B,6);
	}
	else if(flag==1)
	{
		c2=ICR1+(counter*65536);
		set_bit(TCCR1B,6);
	}

	else if(flag==2)
	{
		c3=ICR1+(counter*65536);
		clr_bit(TIMSK,5);//=0b11011111;// close the ICE interrupt

	}
	flag++;
}



void __vector_9 (void)  __attribute__((signal,__INTR_ATTRS));
void __vector_9 (void)
{
	counter++;
}

int main(void)
{
	LCD_init();
	timer0_pwm_init();
	timer1_pwm_init();
	while(1)
	{
		if(flag==3)
		{
			u32 duty=((c2-c1)*100/(c3-c1));
			u32 freq=(8000000/(c3-c1));

			//LCD_writecommand(1);
			LCD_setposition(0,0);
			LCD_writestring("Duty: ");
			//LCD_setposition(0,5);
			LCDWriteInt(duty);

			LCD_setposition(1,0);
			LCD_writestring("Freq: ");
			//LCD_setposition(1,5);
			LCDWriteInt(freq);

 			flag=0;
			set_bit(TIFR,5); // to clear the Input Capture Flag "bit 5"
			set_bit(TIMSK,5);// to re-enable the Input Capture Interrupt "bit 5"
		}
	}
	return 0;
}

