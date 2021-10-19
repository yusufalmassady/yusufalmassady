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
	i2c_init_master();
	i2c_start();
	i2c_send_slave_address_with_write_req(1);
	i2c_slave_write_byte(0x03);
	i2c_stop();


	while (1)
	{

	}
}
