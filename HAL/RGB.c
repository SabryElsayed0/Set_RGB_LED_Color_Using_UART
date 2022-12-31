/******************************************************************************
 *
 * Module: RGB
 *
 * Description: Source file of RGB driver for AVR
 *
 *******************************************************************************/
#include "RGB.h"
u8 key=0;
static u8 i=0,j=0,k=0;
void RGB_init(void)
{
	/**********************************************************/
	TIMER0_Init(TIMER0_FASTPWM_MODE,TIMER0_SCALER_8);
	TIMER0_OC0Mode(OC0_NON_INVERTING);
	/***********************************************************/
	Timer1_Init(TIMER1_FASTPWM_ICR_TOP_MODE,TIMER1_SCALER_8);
	Timer1_OCRB1Mode(OCRB_NON_INVERTING);
	Timer1_OCRA1Mode(OCRA_NON_INVERTING);
	ICR1=255;
	/*********************************************************************/
	//Set_Color(RED);
	//_delay_ms(1000);
}

/*******************************SET_Color*******************************/
 void Set_Color(COLOR_t color)
 {
		 OCR1A=arr_color[color][RED];//RED
		 OCR1B=arr_color[color][GREEN];//green
		 OCR0=arr_color[color][BLUE];//BLUE
 }
 /******************************************************************************/
