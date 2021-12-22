/*******************************************************************************************************
// Author   : yusuf almassady
// Date     : 18 NOV , 2021
// Version  : v1.0
*******************************************************************************************************/





#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/GPIO_interface.h"
#include "../include/GPIO_private.h"
#include "../include/GPIO_config.h"


void MGPIO_voidSetPinDirection (u8 Copy_u8PortName,u8 Copy_u8PinNumber,u8 Copy_u8PinMode)
{
	switch (Copy_u8PortName)
	{
	case PORTA:
	//check the pin number 
	if (Copy_u8PinNumber <= 7)
	{
		//MASKS THE 4 BITS 
		GPIOA->CRL&=~((0b1111)<<(Copy_u8PinNumber*4));
		//SET THE PIN MODE VALUES
		GPIOA->CRL|=((Copy_u8PinMode)<< (Copy_u8PinNumber*4 ));
	}
	else
	{
	Copy_u8PinNumber-=8;	
	GPIOA->CRH&=~((0b1111)<<(Copy_u8PinNumber*4));
	GPIOA->CRH|=((Copy_u8PinMode)<< (Copy_u8PinNumber*4 ));	
	
	}
	break;
	case PORTB:
	//check the pin number 
	if (Copy_u8PinNumber <= 7)
	{
		//MASKS THE 4 BITS 
		GPIOB->CRL&=~((0b1111)<<(Copy_u8PinNumber*4));
		//SET THE PIN MODE VALUES
		GPIOB->CRL|=((Copy_u8PinMode)<< (Copy_u8PinNumber*4 ));
	}
	else
	{
	Copy_u8PinNumber-=8;	
	GPIOB->CRH&=~((0b1111)<<(Copy_u8PinNumber*4));
	GPIOB->CRH|=((Copy_u8PinMode)<< (Copy_u8PinNumber*4 ));	
	
	}
	
	break;
	case PORTC:
	//check the pin number 
	if (Copy_u8PinNumber <= 7)
	{
		//MASKS THE 4 BITS 
		GPIOC->CRL&=~((0b1111)<<(Copy_u8PinNumber*4));
		//SET THE PIN MODE VALUES
		GPIOC->CRL|=((Copy_u8PinMode)<< (Copy_u8PinNumber*4 ));
	}
	else
	{
	Copy_u8PinNumber-=8;	
	GPIOC->CRH&=~((0b1111)<<(Copy_u8PinNumber*4));
	GPIOC->CRH|=((Copy_u8PinMode)<< (Copy_u8PinNumber*4 ));	
	
	}
	
	break;
	
	}
	
	
}

void MGPIO_voidSetPinValue (u8 Copy_u8PortName, u8 Copy_u8PinNumber,u8 Copy_PinValue)
{
	switch (Copy_u8PortName)
	{
		case PORTA:
		if (Copy_PinValue== GPIO_HIGH)
			SET_BIT(GPIOA->ODR,Copy_u8PinNumber);
		else
			CLR_BIT(GPIOA->ODR,Copy_u8PinNumber);

		break;
		case PORTB:
		if (Copy_PinValue== GPIO_HIGH)
			SET_BIT(GPIOB->ODR,Copy_u8PinNumber);
		else
			CLR_BIT(GPIOB->ODR,Copy_u8PinNumber);

		break;
		case PORTC:
		if (Copy_PinValue== GPIO_HIGH)
			SET_BIT(GPIOC->ODR,Copy_u8PinNumber);
		else
			CLR_BIT(GPIOC->ODR,Copy_u8PinNumber);
		break;
		
	}
	
}


void MGPIO_voidSetPortSectionDirection(u8 Copy_u8PortName,u8 Copy_u8Section,u8 Copy_u8Mode)
{
	switch (Copy_u8PortName)
		{
		case PORTA:
		//check the pin number
		if (Copy_u8Section == 0)
		{
             switch (Copy_u8Mode)
             {
             case OUTPUT_2MHZ_PP:
            	 GPIOA->CRL=0b00100010001000100010001000100010;
            	 break;
             case OUTPUT_2MHZ_OD:
            	 GPIOA->CRL=0b01100110011001100110011001100110;
            	 break;
             case OUTPUT_2MHZ_AFPP:
            	 GPIOA->CRL=0b10101010101010101010101010101010;
            	 break;
             case OUTPUT_2MHZ_AFOD:
            	 GPIOA->CRL=0b11101110111011101110111011101110;
            	 break;
             case OUTPUT_10MHZ_PP:
            	 GPIOA->CRL=0b00010001000100010001000100010001;
            	 break;
             case OUTPUT_10MHZ_OD:
            	 GPIOA->CRL=0b01010101010101010101010101010101;
            	 break;
             case OUTPUT_10MHZ_AFPP:
            	 GPIOA->CRL=0b10011001100110011001100110011001;
            	 break;
             case OUTPUT_10MHZ_AFOD:
            	 GPIOA->CRL=0b11011101110111011101110111011101;
            	 break;
             case OUTPUT_50MHZ_PP:
            	 GPIOA->CRL=0b00110011001100110011001100110011;
            	 break;
             case OUTPUT_50MHZ_OD:
            	 GPIOA->CRL=0b01110111011101110111011101110111;
            	 break;
             case OUTPUT_50MHZ_AFPP:
            	 GPIOA->CRL=0b10111011101110111011101110111011;
            	 break;
             case OUTPUT_50MHZ_AFOD:
            	 GPIOA->CRL=0b11111111111111111111111111111111;
            	 break;
             case INPUT_ANALOG:
            	 GPIOA->CRL=0b00000000000000000000000000000000;
            	 break;
             case INPUT_FLOAT:
            	 GPIOA->CRL=0b01000100010001000100010001000100;
            	 break;
             case INPUT_PULL_UP_DOWN:
            	 GPIOA->CRL=0b10001000100010001000100010001000;
             }
		}
		else
		{
            switch (Copy_u8Mode)
            {
            case OUTPUT_2MHZ_PP:
           	 GPIOA->CRH=0b00100010001000100010001000100010;
           	 break;
            case OUTPUT_2MHZ_OD:
           	 GPIOA->CRH=0b01100110011001100110011001100110;
           	 break;
            case OUTPUT_2MHZ_AFPP:
           	 GPIOA->CRH=0b10101010101010101010101010101010;
           	 break;
            case OUTPUT_2MHZ_AFOD:
           	 GPIOA->CRH=0b11101110111011101110111011101110;
           	 break;
            case OUTPUT_10MHZ_PP:
           	 GPIOA->CRH=0b00010001000100010001000100010001;
           	 break;
            case OUTPUT_10MHZ_OD:
           	 GPIOA->CRH=0b01010101010101010101010101010101;
           	 break;
            case OUTPUT_10MHZ_AFPP:
           	 GPIOA->CRH=0b10011001100110011001100110011001;
           	 break;
            case OUTPUT_10MHZ_AFOD:
           	 GPIOA->CRH=0b11011101110111011101110111011101;
           	 break;
            case OUTPUT_50MHZ_PP:
           	 GPIOA->CRH=0b00110011001100110011001100110011;
           	 break;
            case OUTPUT_50MHZ_OD:
           	 GPIOA->CRH=0b01110111011101110111011101110111;
           	 break;
            case OUTPUT_50MHZ_AFPP:
           	 GPIOA->CRH=0b10111011101110111011101110111011;
           	 break;
            case OUTPUT_50MHZ_AFOD:
           	 GPIOA->CRH=0b11111111111111111111111111111111;
           	 break;
            case INPUT_ANALOG:
           	 GPIOA->CRH=0b00000000000000000000000000000000;
           	 break;
            case INPUT_FLOAT:
           	 GPIOA->CRH=0b01000100010001000100010001000100;
           	 break;
            case INPUT_PULL_UP_DOWN:
           	 GPIOA->CRH=0b10001000100010001000100010001000;
            }

		}
		break;
		case PORTB:
		//check the pin number
			if (Copy_u8Section == 0)
			{
	             switch (Copy_u8Mode)
	             {
	             case OUTPUT_2MHZ_PP:
	            	 GPIOB->CRL=0b00100010001000100010001000100010;
	            	 break;
	             case OUTPUT_2MHZ_OD:
	            	 GPIOB->CRL=0b01100110011001100110011001100110;
	            	 break;
	             case OUTPUT_2MHZ_AFPP:
	            	 GPIOB->CRL=0b10101010101010101010101010101010;
	            	 break;
	             case OUTPUT_2MHZ_AFOD:
	            	 GPIOB->CRL=0b11101110111011101110111011101110;
	            	 break;
	             case OUTPUT_10MHZ_PP:
	            	 GPIOB->CRL=0b00010001000100010001000100010001;
	            	 break;
	             case OUTPUT_10MHZ_OD:
	            	 GPIOB->CRL=0b01010101010101010101010101010101;
	            	 break;
	             case OUTPUT_10MHZ_AFPP:
	            	 GPIOB->CRL=0b10011001100110011001100110011001;
	            	 break;
	             case OUTPUT_10MHZ_AFOD:
	            	 GPIOB->CRL=0b11011101110111011101110111011101;
	            	 break;
	             case OUTPUT_50MHZ_PP:
	            	 GPIOB->CRL=0b00110011001100110011001100110011;
	            	 break;
	             case OUTPUT_50MHZ_OD:
	            	 GPIOB->CRL=0b01110111011101110111011101110111;
	            	 break;
	             case OUTPUT_50MHZ_AFPP:
	            	 GPIOB->CRL=0b10111011101110111011101110111011;
	            	 break;
	             case OUTPUT_50MHZ_AFOD:
	            	 GPIOB->CRL=0b11111111111111111111111111111111;
	            	 break;
	             case INPUT_ANALOG:
	            	 GPIOB->CRL=0b00000000000000000000000000000000;
	            	 break;
	             case INPUT_FLOAT:
	            	 GPIOB->CRL=0b01000100010001000100010001000100;
	            	 break;
	             case INPUT_PULL_UP_DOWN:
	            	 GPIOB->CRL=0b10001000100010001000100010001000;
	             }
			}
			else
			{
	            switch (Copy_u8Mode)
	            {
	            case OUTPUT_2MHZ_PP:
	           	 GPIOB->CRH=0b00100010001000100010001000100010;
	           	 break;
	            case OUTPUT_2MHZ_OD:
	           	 GPIOB->CRH=0b01100110011001100110011001100110;
	           	 break;
	            case OUTPUT_2MHZ_AFPP:
	           	 GPIOB->CRH=0b10101010101010101010101010101010;
	           	 break;
	            case OUTPUT_2MHZ_AFOD:
	           	 GPIOB->CRH=0b11101110111011101110111011101110;
	           	 break;
	            case OUTPUT_10MHZ_PP:
	           	 GPIOB->CRH=0b00010001000100010001000100010001;
	           	 break;
	            case OUTPUT_10MHZ_OD:
	           	 GPIOB->CRH=0b01010101010101010101010101010101;
	           	 break;
	            case OUTPUT_10MHZ_AFPP:
	           	 GPIOB->CRH=0b10011001100110011001100110011001;
	           	 break;
	            case OUTPUT_10MHZ_AFOD:
	           	 GPIOB->CRH=0b11011101110111011101110111011101;
	           	 break;
	            case OUTPUT_50MHZ_PP:
	           	 GPIOB->CRH=0b00110011001100110011001100110011;
	           	 break;
	            case OUTPUT_50MHZ_OD:
	           	 GPIOB->CRH=0b01110111011101110111011101110111;
	           	 break;
	            case OUTPUT_50MHZ_AFPP:
	           	 GPIOB->CRH=0b10111011101110111011101110111011;
	           	 break;
	            case OUTPUT_50MHZ_AFOD:
	           	 GPIOB->CRH=0b11111111111111111111111111111111;
	           	 break;
	            case INPUT_ANALOG:
	           	 GPIOB->CRH=0b00000000000000000000000000000000;
	           	 break;
	            case INPUT_FLOAT:
	           	 GPIOB->CRH=0b01000100010001000100010001000100;
	           	 break;
	            case INPUT_PULL_UP_DOWN:
	           	 GPIOB->CRH=0b10001000100010001000100010001000;
	            }

			}
		break;
		case PORTC:
		//check the pin number
			if (Copy_u8Section == 0)
			{
	             switch (Copy_u8Mode)
	             {
	             case OUTPUT_2MHZ_PP:
	            	 GPIOC->CRL=0b00100010001000100010001000100010;
	            	 break;
	             case OUTPUT_2MHZ_OD:
	            	 GPIOC->CRL=0b01100110011001100110011001100110;
	            	 break;
	             case OUTPUT_2MHZ_AFPP:
	            	 GPIOC->CRL=0b10101010101010101010101010101010;
	            	 break;
	             case OUTPUT_2MHZ_AFOD:
	            	 GPIOC->CRL=0b11101110111011101110111011101110;
	            	 break;
	             case OUTPUT_10MHZ_PP:
	            	 GPIOC->CRL=0b00010001000100010001000100010001;
	            	 break;
	             case OUTPUT_10MHZ_OD:
	            	 GPIOC->CRL=0b01010101010101010101010101010101;
	            	 break;
	             case OUTPUT_10MHZ_AFPP:
	            	 GPIOC->CRL=0b10011001100110011001100110011001;
	            	 break;
	             case OUTPUT_10MHZ_AFOD:
	            	 GPIOC->CRL=0b11011101110111011101110111011101;
	            	 break;
	             case OUTPUT_50MHZ_PP:
	            	 GPIOC->CRL=0b00110011001100110011001100110011;
	            	 break;
	             case OUTPUT_50MHZ_OD:
	            	 GPIOC->CRL=0b01110111011101110111011101110111;
	            	 break;
	             case OUTPUT_50MHZ_AFPP:
	            	 GPIOC->CRL=0b10111011101110111011101110111011;
	            	 break;
	             case OUTPUT_50MHZ_AFOD:
	            	 GPIOC->CRL=0b11111111111111111111111111111111;
	            	 break;
	             case INPUT_ANALOG:
	            	 GPIOC->CRL=0b00000000000000000000000000000000;
	            	 break;
	             case INPUT_FLOAT:
	            	 GPIOC->CRL=0b01000100010001000100010001000100;
	            	 break;
	             case INPUT_PULL_UP_DOWN:
	            	 GPIOC->CRL=0b10001000100010001000100010001000;
	             }
			}
			else
			{
	            switch (Copy_u8Mode)
	            {
	            case OUTPUT_2MHZ_PP:
	           	 GPIOC->CRH=0b00100010001000100010001000100010;
	           	 break;
	            case OUTPUT_2MHZ_OD:
	           	 GPIOC->CRH=0b01100110011001100110011001100110;
	           	 break;
	            case OUTPUT_2MHZ_AFPP:
	           	 GPIOC->CRH=0b10101010101010101010101010101010;
	           	 break;
	            case OUTPUT_2MHZ_AFOD:
	           	 GPIOC->CRH=0b11101110111011101110111011101110;
	           	 break;
	            case OUTPUT_10MHZ_PP:
	           	 GPIOC->CRH=0b00010001000100010001000100010001;
	           	 break;
	            case OUTPUT_10MHZ_OD:
	           	 GPIOC->CRH=0b01010101010101010101010101010101;
	           	 break;
	            case OUTPUT_10MHZ_AFPP:
	           	 GPIOC->CRH=0b10011001100110011001100110011001;
	           	 break;
	            case OUTPUT_10MHZ_AFOD:
	           	 GPIOC->CRH=0b11011101110111011101110111011101;
	           	 break;
	            case OUTPUT_50MHZ_PP:
	           	 GPIOC->CRH=0b00110011001100110011001100110011;
	           	 break;
	            case OUTPUT_50MHZ_OD:
	           	 GPIOC->CRH=0b01110111011101110111011101110111;
	           	 break;
	            case OUTPUT_50MHZ_AFPP:
	           	 GPIOC->CRH=0b10111011101110111011101110111011;
	           	 break;
	            case OUTPUT_50MHZ_AFOD:
	           	 GPIOC->CRH=0b11111111111111111111111111111111;
	           	 break;
	            case INPUT_ANALOG:
	           	 GPIOC->CRH=0b00000000000000000000000000000000;
	           	 break;
	            case INPUT_FLOAT:
	           	 GPIOC->CRH=0b01000100010001000100010001000100;
	           	 break;
	            case INPUT_PULL_UP_DOWN:
	           	 GPIOC->CRH=0b10001000100010001000100010001000;
	            }

			}

		break;

		}

}


void MGPIO_voidSetPortSectionValue(u8 Copy_u8PortName,u8 Copy_u8Section,u8 Copy_u8PortValue)
{
	switch (Copy_u8PortName)
	{
	case PORTA:
	if (Copy_u8Section == 0)
		{
			//MASKS THE 4 BITS
			GPIOA->ODR&=~((0xFF)<<(8));
			//SET THE PIN MODE VALUES
			GPIOA->ODR|=((Copy_u8PortValue)<< (8));
		}
		else
		{

		GPIOA->ODR&=~((0xFF)>>(8));
		GPIOA->ODR|=((Copy_u8PortValue)>>(8));

		}
	break;
	case PORTB:
	if (Copy_u8Section == 0)
		{
			//MASKS THE 4 BITS
			GPIOB->ODR&=~((0xFF)<<(8));
			//SET THE PIN MODE VALUES
			GPIOB->ODR|=((Copy_u8PortValue)<< (8));
		}
		else
		{

		GPIOB->ODR&=~((0xFF)>>(8));
		GPIOB->ODR|=((Copy_u8PortValue)>>(8));

		}
	break;
	case PORTC:
	if (Copy_u8Section == 0)
		{
			//MASKS THE 4 BITS
			GPIOC->ODR&=~((0xFF)<<(8));
			//SET THE PIN MODE VALUES
			GPIOC->ODR|=((Copy_u8PortValue)<< (8));
		}
		else
		{

		GPIOC->ODR&=~((0xFF)>>(8));
		GPIOC->ODR|=((Copy_u8PortValue)>>(8));

		}
	}
}
