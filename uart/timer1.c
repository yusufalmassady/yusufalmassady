/*
 * timer1.c
 *
 *  Created on: 27 Sep 2019
 *      Author: Yussuf
 */
#include "std_types.h"
#include "registers.h"
#include "utils.h"
extern void timer1_vidinit(void)
{
	tccr1a=0b10000010;
	tccr1b=0b00011100;
	icrl1=625;
	ocra1l=0;
}

extern void set_duty(u16 duty)
{
//	tccr0=0b01110101; //Configure TCCR0 as explained in the article
//	timsk=0b00000000;
//	ocr0=duty;
	ocra1l=duty;
}
