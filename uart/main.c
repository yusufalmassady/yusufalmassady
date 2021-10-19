#include "std_types.h"
#include "registers.h"
#include "utils.h"
#include "DIO.h"
#include "LCD.h"
#include "timer1.h"
#include "UART.h"
#include <avr/delay.h>
#define f_cpu 8000000
//void main (void)
//{
//	UART_vidinit();
//	LCD_vidinit();
//	u8 bit;
//	u16 u=0;
//	DIO_vidsetpindir(d,5,output);
//timer1_vidinit();
//while (1)
//{
//	LCD_viddisplaynumber(1,1,u);
//	bit=UART_vidrecieve();
//switch (bit)
//{
//case 'w':
//	u=u+1;
//	set_duty(u);
//	LCD_viddisplaynumber(2,1,u);
//	break;
//case 's':
//	u=u-1;
//	set_duty(u);
//	LCD_viddisplaynumber(2,1,u);
//	break;
//}
//}
//}
void main()
{
	UART_vidinit();
	LCD_vidinit();
	u8 bit;
	DIO_vidsetpindir(d,5,output);
	timer1_vidinit();
	while (1);
	{
		bit=UART_vidrecieve();
		if (bit=='a')
		{
			set_duty(75);

		}
		else if (bit=='s')
		{
			set_duty(125);
		}
		else if (bit=='d')
		{
			set_duty(200);
		}
		else if (bit=='f')
		{
			set_duty(275);
		}
		else if (bit=='g')
		{
			set_duty(325);
		}
		else if (bit=='h')
		{
			set_duty(400);
		}
		else if (bit=='j')
		{
			set_duty(475);
		}
		else if (bit=='k')
		{
			set_duty(525);
		}
		else if (bit=='l')
		{
			set_duty(600);
		}
		else
			set_duty(0);
	}
}
//void main ()
//{
//	u8 bit;
//	DIO_vidsetpindir(d,5,output);
//	UART_vidinit();
//	while (1)
//	{
//		bit=UART_vidrecieve();
//		if (bit=='a')
//			DIO_vidwritepinvalue(d,5,high);
//		if (bit=='s')
//			DIO_vidwritepinvalue(d,5,low);
//	}
//}
