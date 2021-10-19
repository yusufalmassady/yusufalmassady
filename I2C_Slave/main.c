#define F_CPU 8000000
#include <util/delay.h>
#include "registers.h"
#include "std_types.h"
#include <stdio.h>
#include "DIO.h"
#include "LCD.h"
#include "KeyPad.h"
#include "I2c.h"


int main(void)
{

	DIOSetPinDirection(0,0,1);
	u8 received_data=0;

	i2c_init_slave();
	//check slave address with write req

	while (1)
	{

		received_data=i2c_read_byte();


		if(received_data==0x03)
		{
			DIOSetPinValue(0,0,1);
		}
		else
		{
			DIOSetPinValue(0,0,0);
		}


	}
}
