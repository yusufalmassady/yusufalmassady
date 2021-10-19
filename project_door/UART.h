/*
 * UART.h
 *
 *  Created on: 5 Oct 2019
 *      Author: Yussuf
 */

#ifndef UART_H_
#define UART_H_
extern void UART_vidinit ();
extern void UART_vidtransmit (u8 data);
extern u8 UART_vidrecieve (void);
extern u16 UART_recievenum (void);
extern void UART_transmit_string (u8 string[]);

#endif /* UART_H_ */
