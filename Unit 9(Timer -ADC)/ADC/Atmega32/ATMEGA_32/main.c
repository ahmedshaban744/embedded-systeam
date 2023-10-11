/*
 * ATMEGA_32.c
 *
 * Created: 8/16/2023 3:42:38 PM
 * Author : Ahmed shaban
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>
#define F_CPU 8000000UL
#include "bit_prosess.h"
#include "DIO.h"
#include "SPI.h"
#include "UART.h"
#include "lcd.h"
#include "keypad.h"
#include "LM35.h"
#include "servo motor.h"
#include "stepper_motor.h"
#include "LDR.h"
#include "watch_dog_timer.h"
#define NULL ((void *)0)
#include "Timer0.h"




uint32_t TEMP;
uint32_t leght;
int main() 
{
LCD_INIT();
LCD_clear_screen();
LCD_GOTO_XY(0,0);
HALL_LDR_INIT();
HALL_LM35_INIT();

	
while(1)
{	

TEMP=(uint16_t)HALL_LM35_REED();
LCD_GOTO_XY(1,0);
LCD_WRITE_STRING("temp");
LCD_GOTO_XY(1,10);
display_int_number(TEMP);	
_delay_ms(5000);

leght=(uint16_t)HALL_LDR_REED();
LCD_GOTO_XY(2,0);
LCD_WRITE_STRING("leght");
LCD_GOTO_XY(2,10);
display_int_number(leght);	
	
}
  }






















 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

