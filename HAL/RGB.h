 /******************************************************************************
 *
 * Module: RGB
 *
 * Description: header file of RGB driver 
 *
 *******************************************************************************/

#ifndef RGB_H_
#define RGB_H_

/**********************************************************************************/
#define F_CPU 8000000
#include <Util/delay.h>
#include "DIO_interface.h"
#include   "KeyPad.h"
#include "Timers.h"
/*******************************************************************************/

//NUMBER OF COLORS
#define  No_Color  9

/*************************ENUM FOR COLORS**********************/
typedef enum{
	RED,
	GREEN,
	BLUE,
	YELLOW,
	WHITE,
	LIGHT_BLUE,
	PINK,
	PURPPLE,
	BLACK
}COLOR_t;

/******************************COLOR ARRAY*********************************/
                                 /*RED  Green BLUE*/
static u8 arr_color[No_Color][3]={ {255,0,0},//RED
                                   {0,255,0},//GREEN
                                   {0,0,255},//BLUE
                                   {100,200,0},//YELLOW
                                   {200,150,150},//WHITE
                                   {0,80,60},//LIGHT BLUE
                                   {100,0,60},//PINK
                                    {20,30,200},//PURPLE
                                    {0,10,20}};//BLACK
/**************************************************************************************************/
//RGB INITIALIZATION
void RGB_init(void);

//TO SET COLOR THAT USER ENTERED
 void Set_Color(COLOR_t color);


#endif 
/*******************************************************************************************/