 #include "KeyPad.h"
#define F_CPU 8000000
#include <util/delay.h>
 u8 KEYPAD_GetKey(void)
 {
	 u8 Key=NO_KEY;
	 u8 r,c;
	 DIO_WritePin(FIRST_OUTPUT,HIGH);
	 DIO_WritePin(FIRST_OUTPUT+1,HIGH);
	 DIO_WritePin(FIRST_OUTPUT+2,HIGH);
	 DIO_WritePin(FIRST_OUTPUT+3,HIGH);
	 for(r=0;r<ROWS;r++)
	 {
		 DIO_WritePin(FIRST_OUTPUT+r,LOW);
		 for(c=0;c<COLS;c++)
		 {
			
			 if(DIO_ReadPin(FIRST_INPUT+c)==LOW)
			 {
				 
				 Key=kayarrarr[r][c];
				 while(DIO_ReadPin(FIRST_INPUT+c)==LOW);
			 }
		 }
		 DIO_WritePin(FIRST_OUTPUT+r,HIGH);

	 }
	 return Key ;
 }
 
 