 /******************************************************************************
 *
 * Module: TIMER
 *
 * Description: header file of TIMER driver for AVR
 *
 *******************************************************************************/

#ifndef TIMERS_H_
#define TIMERS_H_
/*****************************************************************************/

#include "StdTypes.h"
#include "Utils.h"
#include "MemMap.h"
/***********************************enum for prescaler of timer 0****************************/

typedef enum{
	TIMER0_STOP=0,
	TIMER0_SCALER_1,
	TIMER0_SCALER_8,
	TIMER0_SCALER_64,
	TIMER0_SCALER_256,
	TIMER0_SCALER_1024,
	EXTERNALl_FALLING,
	EXTERNAL_RISING
}Timer0Scaler_type;
/*****************************************************************************************/
/********************************enum for mode of timer 0***************************************/
typedef enum
{
	TIMER0_NORMAL_MODE=0,
	TIMER0_PHASECORRECT_MODE,
	TIMER0_CTC_MODE,
	TIMER0_FASTPWM_MODE

}Timer0Mode_type;

/***********************************************************************************************/
/****************************enum for output compare pin OCR0***********************************/
typedef enum
{
	OC0_DISCONNECTED=0,
	OC0_TOGGLE,
	OC0_NON_INVERTING,
	OC0_INVERTING

}OC0Mode_type;

/***********************************enum for prescaler for timer 1****************************/

typedef enum{
	TIMER1_STOP=0,
	TIMER1_SCALER_1,
	TIMER1_SCALER_8,
	TIMER1_SCALER_64,
	TIMER1_SCALER_256,
	TIMER1_SCALER_1024,
	EXTERNAL0_FALLING,
	EXTERNAL0_RISING
}Timer1Scaler_type;

/********************************enum for mode of timer 1***************************************/

typedef enum
{
	TIMER1_NORMAL_MODE=0,
	TIMER1_CTC_ICR_TOP_MODE,
	TIMER1_CTC_OCRA_TOP_MODE,
	TIMER1_FASTPWM_ICR_TOP_MODE,
	TIMER1_FASTPWM_OCRA_TOP_MODE

}Timer1Mode_type;

/***********************************************************************************************/
/****************************enum for output compare pin OCRA***********************************/
typedef enum
{
	OCRA_DISCONNECTED=0,
	OCRA_TOGGLE,
	OCRA_NON_INVERTING,
	OCRA_INVERTING

}OC1A_Mode_type;

/***********************************************************************************************/
/****************************enum for output compare pin OCRB***********************************/
typedef enum
{
	OCRB_DISCONNECTED=0,
	OCRB_TOGGLE,
	OCRB_NON_INVERTING,
	OCRB_INVERTING

}OC1B_Mode_type;




/*******************************************************************************************/
//initialize TIMER0
void TIMER0_Init(Timer0Mode_type mode,Timer0Scaler_type scaler);

//OUTPUT COMPARE  MODE
void TIMER0_OC0Mode(OC0Mode_type mode);

////initialize TIMER1
void Timer1_Init( Timer1Mode_type mode,Timer1Scaler_type scaler);

//OUTPUT COMPARE for A1 pin  MODE
void Timer1_OCRA1Mode(OC1A_Mode_type oc1a_mode);

//OUTPUT COMPARE for B1 pin  MODE
void Timer1_OCRB1Mode(OC1B_Mode_type oc1b_mode);



/*********************************************************************************************************/



#endif /* TIMERS_H_ */