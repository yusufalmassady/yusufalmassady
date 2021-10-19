/*
 * DIO.c
 *
 *  Created on: 17 Aug 2019
 *      Author: Yussuf
 */
#include "std_types.h"
#include "registers.h"
#include "utils.h"
extern void DIO_vidsetpindir (u8 port ,u8 pin , u8 dir)
{
	switch (port)
	{
	case 0:
		if (dir==0)
			clr_bit(ddra,pin);
		if (dir==1)
			set_bit (ddra,pin);
		break;
	case 1:
		if (dir==0)
			clr_bit (ddrb,pin);
		if (dir==1)
			set_bit (ddrb,pin);
		break;
	case 2:
		if (dir==0)
			clr_bit (ddrc,pin);
		if (dir==1)
			set_bit (ddrc,pin);
		break;
	case 3:
		if (dir==0)
			clr_bit (ddrd,pin);
		if (dir==1)
			set_bit (ddrd,pin);
		break;
	default :
		break;
	}
}

extern void DIO_vidwritepinvalue (u8 port, u8 pin, u8 value)
{
	switch (port)
		{
	case 0:
		if (value==0)
			clr_bit (porta,pin);
		if (value==1)
			set_bit (porta,pin);
			break;
		case 1:
		if (value==0)
			clr_bit (portb,pin);
		if (value==1)
			set_bit (portb,pin);
		break;
	case 2:
		if (value==0)
			clr_bit (portc,pin);
		if (value==1)
			set_bit (portc,pin);
			break;
		case 3:
		if (value==0)
			clr_bit (portd,pin);
		if (value==1)
				set_bit (portd,pin);
			break;
		default :
			break;
		}
}

extern u8 DIO_u8readpinvalue (u8 port, u8 pin)
{
	switch (port)
	{
	case 0 :
		return get_bit (pina,pin);
		break;
	case 1 :
		return get_bit (pinb,pin);
		break;
	case 2 :
		return get_bit (pinc,pin);
		break;
	case 3 :
		return  get_bit (pind,pin);
	break;
	default :
		return 2;
	}
}
extern void DIO_vidportdir (u8 port ,u8 direction)
{
	switch (port)
	{
	case 0 :
		ddra=direction;
		break;
	case 1 :
		ddrb=direction;
		break;
	case 2 :
		ddrc=direction;
		break;
	case 3 :
		ddrd=direction;
		break;
	default :
		break;
	}
}
extern void DIO_vidportwrite (u8 port ,u8 input)
{
	switch (port)
	{
	case 0 :
		porta=input;
		break;
	case 1 :
		portb=input;
		break;
	case 2 :
		portc=input;
		break;
	case 3 :
		portd=input;
		break;
	default :
		break;
	}
}
