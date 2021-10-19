/*
 * utils.h
 *
 *  Created on: 19 Aug 2019
 *      Author: Yussuf
 */

#ifndef UTILS_H_
#define UTILS_H_
#define set_bit(reg,bit) reg|=(1<<bit)
#define clr_bit(reg,bit) reg&=(~(1<<bit))
#define get_bit(reg,bit) ((reg&(1<<bit))>>bit)
#endif /* UTILS_H_ */
