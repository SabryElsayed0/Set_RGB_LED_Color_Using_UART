


#ifndef KEYPAD_H_
#define KEYPAD_H_

 #include "DIO_interface.h"
/****************************config*****************/
#define FIRST_OUTPUT    PINB4
#define FIRST_INPUT     PINC0
#define ROWS             4
#define COLS             4
#define NO_KEY           'N'
 static u8 kayarrarr[ROWS][COLS]= {{'7' , '8' , '9' , 'a'},
	                              {'4' , '5' , '6' , 'b'},  
                                   {'1' , '2' , '3' , 'e'},
                                   {'C' , '0' ,'=' , 'f'},
	                                                       };
/***************************************************************************/
  u8 KEYPAD_GetKey(void);

#endif 