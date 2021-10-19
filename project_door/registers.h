/* * registers.h
 *
 *  Created on: 17 Aug 2019
 *      Author: Yussuf
 */

#ifndef REGISTERS_H_
#define REGISTERS_H_
#define ddra (*(volatile u8*)0x3A)
#define porta (*(volatile u8*)0x3B)
#define pina (*(volatile u8*)0x39)
#define ddrb (*(volatile u8*)0x37)
#define portb (*(volatile u8*)0x38)
#define pinb (*(volatile u8*)0x36)
#define ddrc (*(volatile u8*)0x34)
#define portc (*(volatile u8*)0x35)
#define pinc (*(volatile u8*)0x33)
#define ddrd (*(volatile u8*)0x31)
#define portd (*(volatile u8*)0x32)
#define pind (*(volatile u8*)0x30)

#define admux (*(volatile u8*)0x27)
#define adcsra (*(volatile u8*)0x26)
#define adc (*(volatile u16*)0x24)
#define adcl (*(volatile u8*)0x24)
#define adch (*(volatile u8*)0x25)

#define EEAR (*(volatile u8*)0x3E)
#define EEARH (*(volatile u8*)0x3F)
#define EEARL (*(volatile u8*)0x3E)
#define EEDR (*(volatile u8*)0x3D)
#define EECR (*(volatile u8*)0x3C)
#define SPMCR (*(volatile u8*)0x57)

//timer1
#define tccr1a (*(volatile u8*)0x4F)
#define tccr1b (*(volatile u8*)0x4E)
#define icrl1 (*(volatile u8*)0x46)
#define icrh1 (*(volatile u8*)0x47)
#define ocra1l (*(volatile u8*)0x4A)
#define ocra1h (*(volatile u8*)0x4B)
//WDT
#define WDTCR (*(volatile u8*)0x41)
//UART
#define UDR (*(volatile u8*)0x2C)
#define UCSRA (*(volatile u8*)0x2B)
#define UCSRB (*(volatile u8*)0x2A)
#define UCSRC (*(volatile u8*)0x40)
#define UBRRL (*(volatile u8*)0x29)
#define UBRRH (*(volatile u8*)0x40)
#endif /* REGISTERS_H_ */
