/*
 * LCD.c
 *
 *  Created on: 23 Aug 2019
 *      Author: Yussuf
 */
#include "std_types.h"
#include "registers.h"
#include "utils.h"
#include "DIO.h"
#include "lcd_config.h"
#include "LCD.h"
#include <avr/delay.h>
#define f_cpu 8000000

extern void LCD_vidwritecommand (u8 command)
{
	//RW=0
	DIO_vidwritepinvalue (control_port,RW,low);
	//RS=0
	DIO_vidwritepinvalue (control_port,RS,low);
	//Data
	DIO_vidportwrite (data_port,command);
	//start execution E=1
	DIO_vidwritepinvalue(control_port,E,high);
	_delay_ms(2);
	DIO_vidwritepinvalue(control_port,E,low);
}
extern void LCD_vidwritedata (u8 data)
{
	//RW=0
	DIO_vidwritepinvalue (control_port,RW,low);
	//RS=0
	DIO_vidwritepinvalue (control_port,RS,high);
	//Data
	DIO_vidportwrite (data_port,data);
	//start execution E=1
	DIO_vidwritepinvalue(control_port,E,high);
	_delay_ms(2);
	DIO_vidwritepinvalue(control_port,E,low);
}
extern void LCD_vidinit (void)
{
	DIO_vidsetpindir(control_port,RS,output);
	DIO_vidsetpindir(control_port,RW ,output);
	DIO_vidsetpindir(control_port,E,output);
	DIO_vidportdir(data_port,0b11111111);
	_delay_ms (50);
	LCD_vidwritecommand(0b00111100);
	_delay_ms (2);
	LCD_vidwritecommand(0b00001110);
	_delay_ms (2);
	LCD_vidwritecommand(0b00000001);
}
extern void LCD_setcursorposition (u8 line,u8 column)
{
	u8 i=0;
	switch (line)
	{
	case line1 :
		LCD_vidwritecommand(0b10000000);
		LCD_vidwritecommand(cursorleft);
		LCD_vidwritecommand(cursorleft);
		for (i=0;i<=column;i++)
		{
			LCD_vidwritecommand(cursorright);
		}
		break;
	case line2 :

		LCD_vidwritecommand(0b10000000|0x40);
		LCD_vidwritecommand(cursorleft);
		LCD_vidwritecommand(cursorleft);
		for (i=0;i<=column;i++)
				{
					LCD_vidwritecommand(cursorright);
				}
		break;
	default :
		break;



	}
}
extern void LCD_vidwritestring (u8 line,u8 column,u8 string[])
{
	u8 i=0;
	LCD_setcursorposition(line,column);
	_delay_ms(2);
	while (string[i]!= 0)
	{
		LCD_vidwritedata(string[i]);
		_delay_ms(2);
				i++;
	}
}
extern void LCD_vidwritestringoncursor (u8 string[])
{
	u8 i=0;
	_delay_ms(2);
	while (string[i]!= 0)
	{
		LCD_vidwritedata(string[i]);
		_delay_ms(2);
				i++;
	}
}

extern void LCD_viddisplaynumber(u8 line,u8 column,u32 num)
{
	u32 num1;
	u8 i;
	LCD_setcursorposition(line,column);
	num1=num/10000;
	if (num1 !=0 )
	{
		i=1;
		LCD_vidwritedata(num1+48);
	}
	else
	{
		i=0;
		LCD_vidwritedata(' ');
	}
	num=num%10000;
	num1=num/1000;
	if (i==1)
	{
		i==1;
		LCD_vidwritedata(num1+48);
	}
	else if (i==0)
	{
	if (num1 !=0 )
	{
		i=1;
		LCD_vidwritedata(num1+48);
	}
	else
	{
		i=0;
		LCD_vidwritedata(' ');
	}}
	num=num%1000;
	num1=num/100;
	if (i==1)
	{
		i=1;
		LCD_vidwritedata(num1+48);
	}
	else if (i==0)
	{
	if (num1 !=0 )
	{
		i=1;
		LCD_vidwritedata(num1+48);
	}
	else
	{
		i=0;
		LCD_vidwritedata(' ');
	}}
	num=num%100;
	num1=num/10;
	if (i==1)
	{
		i=1;
		LCD_vidwritedata(num1+48);
	}
	else if (i==0)
	{
	if (num1 !=0 )
	{
		i=1;
		LCD_vidwritedata(num1+48);
	}
	else
	{
		i=0;
		LCD_vidwritedata(' ');
	}}
	num=num%10;
	LCD_vidwritedata(num+48);

}
