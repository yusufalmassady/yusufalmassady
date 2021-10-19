/*
 * ADC.h
 *
 *  Created on: 6 Sep 2019
 *      Author: Yussuf
 */

#ifndef ADC_H_
#define ADC_H_
extern void ADC_vidinit (u8 ps);
extern u16 ADC_u16read(u8 ch);
#define ps32 32
#define ps64 64
#define ps128 128
#define ps2 2
#define ps4 4
#define ps8 8
#define ps16 16
#endif /* ADC_H_ */
