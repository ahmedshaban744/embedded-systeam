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
#include "PWM.h"
#include "servo motor.h"
#include "stepper_motor.h"
#include "LDR.h"
#include "watch_dog_timer.h"
#define NULL ((void *)0)





int main() {
	MCAL_DIO_PIN_Dir( DIO_PORTA , PA0, DIO_pin_OUT);
	MCAL_DIO_PIN_Dir( DIO_PORTA , PA1, DIO_pin_OUT);
	MCAL_DIO_PIN_val (DIO_PORTA , PA0 ,DIO_pin_HIGH);
	_delay_ms(900);
	MCAL_DIO_PIN_val (DIO_PORTA , PA0 ,DIO_pin_LOW);
	
	
while(1)
{
		MCAL_watch_dog_timer_start(WDT_2100_ms);
		MCAL_DIO_PIN_toggle (DIO_PORTA , PA1 );
		_delay_ms(10000);
	    MCAL_watch_dog_timer_stop();	

}
	
}






















 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

