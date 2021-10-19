/*
 * DIO.h
 *
 *  Created on: 17 Aug 2019
 *      Author: Yussuf
 */

#ifndef DIO_H_
#define DIO_H_
extern void DIO_vidsetpindir (u8 port ,u8 pin , u8 dir);
extern void DIO_vidwritepinvalue (u8 port, u8 pin, u8 value);
extern u8 DIO_u8readpinvalue (u8 port, u8 pin);
extern void DIO_vidportdir (u8 port ,u8 direction);
extern void DIO_vidportwrite (u8 port ,u8 input);
#define a 0
#define b 1
#define c 2
#define d 3
#define pin0 0
#define pin1 1
#define pin2 2
#define pin3 3
#define pin4 4
#define pin5 5
#define pin6 6
#define pin7 7
#define output 1
#define input 0
#define high 1
#define low 0
#endif /* DIO_H_ */
