/*///?
 * main.c?////
 *
 *  Created on: 24 Aug 2019
 *      Author: Yussuf
 */
#include "std_types.h"
#include "registers.h"
#include "utils.h"
#include "DIO.h"
#include "UART.h"
#include "SPI.h"
#include <avr/delay.h>
#define f_cpu 8000000
#define WDT_ref() __asm__ __volatile__("WDr")

void main (void)
{
SPI_init(master);
while (1)
{
	SPI_tranciever('n');
	_delay_ms(1000);
	SPI_tranciever('f');
	_delay_ms(100);
}
}
