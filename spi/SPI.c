/*
 * SPI.c
 *
 *  Created on: 11 Oct 2019
 *      Author: Yussuf
 */
#include "std_types.h"
#include "registers.h"
#include "utils.h"
#include "DIO.h"
#include "SPI.h"
extern void SPI_init (u8 state)
{
switch (state)
{
case master:
		SPCR=0b01010011;
		DIO_vidsetpindir(b,7,output);
		DIO_vidsetpindir(b,5,output);
		DIO_vidsetpindir(b,6,input);
		DIO_vidsetpindir(b,4,output);
break;
case slave:
		SPCR=0b01000011;
		DIO_vidsetpindir(b,7,input);
		DIO_vidsetpindir(b,5,input);
		DIO_vidsetpindir(b,6,output);
		DIO_vidsetpindir(b,4,input);
		break;
}
}
extern u8 SPI_tranciever (u8 data)
{
	DIO_vidwritepinvalue(b,4,low);
	SPDR=data;
	while (get_bit(SPSR,7)==0);
	DIO_vidwritepinvalue(b,4,high);
	return SPDR;

}

