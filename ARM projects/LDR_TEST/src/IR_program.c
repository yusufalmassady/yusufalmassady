/*******************************************************************************************************
/* Author   : yusuf almassady
/* Date     : 15 DEC , 2021
/* Version  : v1.0
*******************************************************************************************************/
#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/IR_interface.h"
#include "../include/STK_interface.h"
#include "../include/GPIO_interface.h"

volatile u8 Global_u8StartFrame = 0;
volatile u32 Global_u32FrameData[50]={0};
volatile u8 Global_u8EdgeCounter = 0;
volatile u8 Global_u8Data = 0;
volatile u8 Global_u8ModeCycle=1;
void HIR_voidPlay(void)
{
switch (Global_u8Data)
{
case 69:
	MGPIO_voidSetPinValue(PORTA,1,GPIO_LOW);
	MGPIO_voidSetPinValue(PORTA,2,GPIO_LOW);
	MGPIO_voidSetPinValue(PORTA,3,GPIO_LOW);
	break;
case 12:
	MGPIO_voidSetPinValue(PORTA,1,GPIO_HIGH);
	MGPIO_voidSetPinValue(PORTA,2,GPIO_LOW);
	MGPIO_voidSetPinValue(PORTA,3,GPIO_LOW);
	break;
case 24:
	MGPIO_voidSetPinValue(PORTA,1,GPIO_LOW);
	MGPIO_voidSetPinValue(PORTA,2,GPIO_HIGH);
	MGPIO_voidSetPinValue(PORTA,3,GPIO_LOW);
	break;
case 94:
	MGPIO_voidSetPinValue(PORTA,1,GPIO_LOW);
	MGPIO_voidSetPinValue(PORTA,2,GPIO_LOW);
	MGPIO_voidSetPinValue(PORTA,3,GPIO_HIGH);
	break;
case 70:
	if (Global_u8ModeCycle==1)
	{
		MGPIO_voidSetPinValue(PORTA,1,GPIO_LOW);
		MGPIO_voidSetPinValue(PORTA,2,GPIO_HIGH);
		MGPIO_voidSetPinValue(PORTA,3,GPIO_HIGH);
	}
	else if (Global_u8ModeCycle==2)
		{
			MGPIO_voidSetPinValue(PORTA,1,GPIO_HIGH);
			MGPIO_voidSetPinValue(PORTA,2,GPIO_LOW);
			MGPIO_voidSetPinValue(PORTA,3,GPIO_HIGH);
		}
	else if (Global_u8ModeCycle==3)
			{
				MGPIO_voidSetPinValue(PORTA,1,GPIO_HIGH);
				MGPIO_voidSetPinValue(PORTA,2,GPIO_HIGH);
				MGPIO_voidSetPinValue(PORTA,3,GPIO_LOW);
			}
	else if (Global_u8ModeCycle==4)
				{
					MGPIO_voidSetPinValue(PORTA,1,GPIO_HIGH);
					MGPIO_voidSetPinValue(PORTA,2,GPIO_HIGH);
					MGPIO_voidSetPinValue(PORTA,3,GPIO_HIGH);
				}
	else
	{
		Global_u8ModeCycle=0;
	}
	Global_u8ModeCycle++;
	break;
}
}


void HIR_voidGetFrame()
{
	if (Global_u8StartFrame==0)
	{
		MSTK_voidIntervalSingle(80000,HIR_voidTakeAction);
		Global_u8StartFrame=1;
	}
	else
	{
		Global_u32FrameData[Global_u8EdgeCounter] = MSTK_u32GetElapsedTime();
		MSTK_voidIntervalSingle(80000,HIR_voidTakeAction);
		Global_u8EdgeCounter++;
	}
}

void HIR_voidTakeAction()
{
	Global_u8Data=0;
	u8 Local_u8Dummy=0;
	for (Local_u8Dummy=0;Local_u8Dummy<=8;Local_u8Dummy++)
	{
		if ((Global_u32FrameData[Local_u8Dummy+17]>=2000) && (Global_u32FrameData[Local_u8Dummy+17]<=2300))
		{
			SET_BIT(Global_u8Data,Local_u8Dummy);
		}
		else
			CLR_BIT(Global_u8Data,Local_u8Dummy);
	}

	HIR_voidPlay();
	Global_u8StartFrame = 0;
	Global_u32FrameData[0]=0;
	Global_u8EdgeCounter = 0;
}
