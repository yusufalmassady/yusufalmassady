/*******************************************************************************************************
/* Author   : yusuf almassady
/* Date     : 13 DEC , 2021
/* Version  : v1.0
*******************************************************************************************************/
#ifndef STK_INTERFACE_H_
#define STK_INTERFACE_H_

void MSTK_voidInit(void);
void MTSK_voidSetBusyWait(u32 Copy_u32Ticks);
u32 MSTK_u32GetElapsedTime(void);
u32 MSTK_u32GetRemainingTime(void);
void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks,void(*Copy_pvNotificationFunction)(void));
void MSTK_voidIntervalSingle(u32 Copy_u32Ticks,void(*Copy_pvNotificationFunction)(void));




#endif
