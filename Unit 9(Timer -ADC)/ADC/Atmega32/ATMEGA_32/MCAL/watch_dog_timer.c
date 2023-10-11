/*
 * watch_dog_timer.c
 *
 * Created: 10/6/2023 12:44:33 AM
 *  Author: Ahmed shaban
 */ 

#include "watch_dog_timer.h"

void MCAL_watch_dog_timer_start(uint8_t time_out)
{
 	 //set prescaler
    WDTCR = time_out;
	//enable Watch dog timer
     WDTCR |=(1<<WDE);
	
  
}
void MCAL_watch_dog_timer_stop()
{
	//To disable an enabled Watchdog Timer, the following procedure must be
	//followed:
	//1. In the same operation, write a logic one to WDTOE and WDE. 
	//A logic one must be written to WDE even though it is set to one before the disable operation starts
	//2. Within the next four clock cycles, write a logic 0 to WDE. This disables the Watchdog.
    WDTCR =((1<<WDE)|(1<<WDTOE));
	WDTCR =0x00;	
 
}