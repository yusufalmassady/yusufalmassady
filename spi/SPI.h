/*
 * SPI.H
 *
 *  Created on: 11 Oct 2019
 *      Author: Yussuf
 */

#ifndef SPI_H_
#define SPI_H_
#define master 1
#define slave 0
extern void SPI_init (u8 state);
extern u8 SPI_tranciever (u8 data);

#endif /* SPI_H_ */
