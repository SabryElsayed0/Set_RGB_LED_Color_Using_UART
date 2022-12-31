 /******************************************************************************
 *
 * Module: UART
 *
 * Description: header file of UART driver for AVR
 *
 *******************************************************************************/


#ifndef UART_H_
#define UART_H_
#include "STDTYPES.h"
#include "MeMmap.h"
#include "UTILS.h"
/*******************************************************************************/

//UART initialization 
void UART_Init(void);

//UART RECEIVE
u8 UART_Receive(void);




#endif /* UART_H_ */