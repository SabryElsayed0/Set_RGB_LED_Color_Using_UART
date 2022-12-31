/**************************************************************************************************
 * Author      : Sabry Elsayed
/
 * Description : Main file for SET COLOR  ON RGB LED THAT USER ENTERS 
/ 
 ************************************************************************/

/***********************************************************************/

#define F_CPU 8000000
#include <Util/delay.h>
#include "MEMmap.h"
#include  "STDTYPES.h"
#include "UTILS.h"
#include "DIO_interface.h"
#include "Timers.h"
#include "UART.h"
#include "LCD.h"
/***************************************************************************/
//declaration for String_Compare function
u16 String_Compare(u8*str ,u8*arr[]);

// index of array of cloros that user need to turn on
u8 index=0;

//array of cloros for RGB LED
u8*arr[9]={"RED","GREEN","BLUE","YELLOW","WHITE",
"LIGHT BLUE","PINK","PURPLE","BLACK"};

//array of charcter to store user string inputs
u8 str[20];

//For the unsed data in UDR
u8 Recycle = 0;
/*********************************************************/
int main(void)
{
	//initialize dio pins
	DIO_Init();
	
	//initialize LCD
	LCD_Init();
	
	//initialize RGB
	RGB_init();
	
	//initialize UART
	UART_Init();
	
	while(1)
	{
/*********************recieve String from user*****************************/
		LCD_GoTo(0,2);
		LCD_WriteString("ENTER COLOR ");
	    
		UART_RecieveString(str);
		Recycle = UART_Receive();
		LCD_GoTo(1,6);
		LCD_WriteString(str);
		LCD_WriteString("      ");
/**************************************************************************/
/*****************Compare String that user entered by Array of Colors********/
		if(String_Compare(str,arr))
		{
			Set_Color(index);
			for(u8 i=0;str[i];i++)
			{
				str[i] = 0;
			}
		}
		else
		{
			LCD_Clear();
			LCD_GoTo(0,0);
			LCD_WriteString("error");
			LCD_WriteString("      ");
			_delay_ms(1000);
			LCD_Clear();
			for(u8 i=0;str[i];i++)
			{
				str[i] = 0;
			}
		}
	}

}
/***************************String_Compare_function***************************/
u16 String_Compare(u8*str ,u8*arr[])
{
	u16 status_error=0;
	for(u8 i=0;i<9;i++)
	{
		for(u8 j=0; ( str[j] || arr[i][j] ) ;j++)
		{
			if(str[j]!= arr[i][j])//compare each charcter on str by arr
			{
				status_error=0;
				break;
			}
			else
			{
				status_error=1;
			}
			
		}
		if(status_error == 1)
		{
			index=i;
			break;
		}

	}
	return status_error;

}
/********************************************************************/