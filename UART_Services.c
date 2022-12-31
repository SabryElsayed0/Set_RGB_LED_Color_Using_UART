 /******************************************************************************
 *
 * Module: UART_Services
 *
 * Description: Source file of UART SERVICES for AVR
 *
 *******************************************************************************/
#include "UART_Services.h"
#include "LCD.h"
static void FUNC_TX(void);
static void FUNC_RX(void);

/************************UART RECEIVE STRING FROM THE USER******************************/
void UART_RecieveString(u8*str)
{
	u8 i=0;
	//To RECEIVE CHARACTER BY CHARACTER FROM THE USER
	str[i]=UART_Receive();
	
	
	/*13 here is asci of enter key if the user press enter that mean
	 the end of string*/
	for(i=0;str[i]!=13;)
	{
		i++;
		str[i]=UART_Receive();
	}
	str[i]=0; //to instead # by '/0'null
}
/**********************************************************************/
