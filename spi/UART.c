/*
 * UART.c
 *
 *  Created on: 5 Oct 2019
 *      Author: Yussuf
 */
#include "std_types.h"
#include "registers.h"
#include "utils.h"
#include "DIO.h"
extern void UART_vidinit ()
{
	DIO_vidsetpindir(d,0,input);
    DIO_vidsetpindir(d,1,output);
	UCSRA=0b00000000;
//	UCSRB=0b00011000;
	set_bit(UCSRB,3);
	set_bit(UCSRB,4);
	set_bit(UCSRC,2);
	set_bit(UCSRC,1);
	UBRRL=51;
	UBRRH=0;
}
extern void UART_vidtransmit (u8 data)
{
	while (get_bit(UCSRA,5)==0);
	UDR=data;
}
extern u8 UART_vidrecieve (void)
{

	u8 data=0;
	while (get_bit(UCSRA,7)==0);
	data=UDR;
	set_bit(UCSRA,7);
	return data;
}
