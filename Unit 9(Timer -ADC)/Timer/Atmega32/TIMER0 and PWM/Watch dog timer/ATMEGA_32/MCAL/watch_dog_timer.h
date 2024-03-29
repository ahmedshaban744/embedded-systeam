/*
 * watch_dog_timer.h
 *
 * Created: 10/6/2023 12:44:45 AM
 *  Author: Ahmed shaban
 */ 


#ifndef WATCH_DOG_TIMER_H_
#define WATCH_DOG_TIMER_H_
//===========================================================================
//=========================includes==========================================
//===========================================================================
#include "bit_prosess.h"
#include <avr/io.h>

//===========================================================================
//=========================macros==============================================
//=============================================================================
//@WDT_time_out
#define  WDT_16_3_ms	 0
#define  WDT_32_5_ms     1
#define WDT_65_ms        2
#define WDT_130_ms       3
#define WDT_260_ms       4
#define WDT_520_ms       5
#define WDT_1000_ms      6
#define WDT_2100_ms      7
 
//=============================================================================
//============================APIS=============================================
//=============================================================================

void MCAL_watch_dog_timer_start(uint8_t time_out);
void MCAL_watch_dog_timer_stop();





#endif /* WATCH_DOG_TIMER_H_ */