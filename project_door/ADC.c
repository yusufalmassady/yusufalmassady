/*
 * ADC.c
 *
 *  Created on: 6 Sep 2019
 *      Author: Yussuf
 */
#include "std_types.h"
#include "registers.h"
#include "utils.h"
#include "DIO.h"
#include "ADC.h"
extern void ADC_vidinit (u8 ps)
{
	u8 ps1;
	set_bit(admux,pin6);
	set_bit(adcsra,pin7);
	if (ps1==ps4)
	{
	set_bit(adcsra,pin1);
	}
	else	if (ps1==ps8)
	{
	set_bit(adcsra,pin0);
	set_bit(adcsra,pin1);
	}
	else	if (ps1==ps16)
	{
	set_bit(adcsra,pin2);
	}
	else	if (ps1==ps32)
	{
	set_bit(adcsra,pin0);
	set_bit(adcsra,pin2);
	}
	else	if (ps1==ps64)
	{
	set_bit(adcsra,pin1);
	set_bit(adcsra,pin2);
	}
	else	if (ps1==ps128)
	{
	set_bit(adcsra,pin0);
	set_bit(adcsra,pin1);
	set_bit(adcsra,pin2);
	}

}

extern u16 ADC_u16read(u8 ch)
{
	admux &=0b11100000;
	admux |=ch;
	adcsra |=(1<<6);
	while (!(adcsra&(1<<4)));
	adcsra |=(1<<4);
	return (adc);
}
