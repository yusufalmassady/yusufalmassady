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
#include <avr/delay.h>
#define f_cpu 8000000
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
extern u16 UART_recievenum (void)
{
	u16 fact=1,num2=0;
	u8 num1[10];
	u8 i=0,num=UART_vidrecieve(),j,f;
	while(num!='/')
	{
		num=UART_vidrecieve();
		switch (num)
		{
		case '0':
			num1[i]=0;
			break;
		case '1':
			num1[i]=1;
			break;
		case '2':
			num1[i]=2;
			break;
		case '3':
			num1[i]=3;
			break;
		case '4':
			num1[i]=4;
			break;
		case '5':
			num1[i]=5;
			break;
		case '6':
			num1[i]=6;
			break;
		case '7':
			num1[i]=7;
			break;
		case '8':
			num1[i]=8;
			break;
		case '9':
			num1[i]=9;
			break;
		default:
			break;
		}
		i++;
	}
i=i-1;
switch (i)
{
case 1:
	num2=num1[0];
	return num2;
	break;
case 2:
	num2=num1[0]*10+num1[1];
	return num2;
	break;
case 3:
	num2=num1[0]*100+num1[1]*10+num1[2];
	return num2;
	break;
case 4:
	num2=num1[0]*1000+num1[1]*100+num1[2]*10+num1[3];
	return num2;
	break;

}

}
extern void UART_transmit_string (u8 string[])
{
	u8 i=0;
	while (string[i]!= 0)
	{
		UART_vidtransmit(string[i]);
		_delay_ms(1);
				i++;
	}
}
extern void UART_transmit_integar (u16 number)
{
	u8 num1,num2;
	if (number<10)
	UART_vidtransmit(number+48);
	if (number>=10 && number<100)
	{
		num1=number/10;
		num2=number%10;
		UART_vidtransmit(num1+48);
		UART_vidtransmit(num2+48);
	}

}
