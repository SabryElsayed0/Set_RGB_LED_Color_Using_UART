/******************************************************************************
 *
 * Module: UART
 *
 * Description: Source file of UART driver for AVR
 *
 *****************************************************************************/

/********************************************************************************/

#include "UART.h"

/**********************************************************************************/

/******************************UART INITIALIZATION **************************/
void UART_Init(void)
{
	//baud rate  9600 ,f=8MHZ ,Normal Speed
	UBRRL=51;
	//normal speed 
	CLR_BIT(UCSRA,U2X);	
	//frame->parity ,data bits, stop bits
	
	//enable for Uart
	SET_BIT(UCSRB,TXEN);
	SET_BIT(UCSRB,RXEN); 
}
/*************************************************************************************/

//TO RECIEVE DATA FROM THE USER
u8 UART_Receive(void)
{
	while(!READ_BIT(UCSRA,RXC));
	
	//RETURN THE ENTERED DATA 
	return UDR;
}


/**********************************************************************************/


