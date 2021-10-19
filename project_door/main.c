/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: sama
 */
#include "std_types.h"
#include "registers.h"
#include "DIO.h"
#include "UART.h"
#include "ADC.h"
#include <avr/delay.h>
#define f_cpu 8000000
void main (void)
{
	ADC_vidinit(ps32);
	UART_vidinit();
	u8 data,i=0,j;
	DIO_vidsetpindir(c,0,output);
	DIO_vidsetpindir(c,7,output);
	DIO_vidsetpindir(c,6,output);
	DIO_vidsetpindir(a,0,output);

	while (1)
	{
		data = UART_vidrecieve();
		if (data=='A')
		{
			if (i==2)
			{

				DIO_vidwritepinvalue(a,0,high);
				UART_vidtransmit('R');
			}
			else
			{
				i++;
				UART_vidtransmit('W');
			}
		}
		if (data=='F')
		{
			DIO_vidwritepinvalue(c,6,high);
		    DIO_vidwritepinvalue(c,7,low);

		}
		if (data=='B')
		{
			DIO_vidwritepinvalue(c,6,low);
			DIO_vidwritepinvalue(c,7,high);

		}
		if (data=='R')
			DIO_vidwritepinvalue(a,0,low);
		if (data=='L')
			DIO_vidwritepinvalue(a,0,high);
		else
			DIO_vidwritepinvalue(a,0,low);
	}
}

