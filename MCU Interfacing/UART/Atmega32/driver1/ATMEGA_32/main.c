/*
 * ATMEGA_32.c
 *
 * Created: 8/16/2023 3:42:38 PM
 * Author : Ahmed shaban
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 8000000UL
#include "lcd.h"
#include "UART.h"




int main(void)

{
	char arr[30]="ahmed";
	
	LCD_INIT();
	LCD_clear_screen();
	LCD_WRITE_STRING("LCD  init");
	_delay_ms(5000);
	LCD_clear_screen();
	UART_INIT();
		LCD_WRITE_STRING("uart  init");
		_delay_ms(5000);
		LCD_clear_screen();
		UART_SendString("AHMED shaban mohamed");

	
		
 uint8_t x;
 LCD_WRITE_STRING("UART RX");
 
 LCD_GOTO_XY(2,0);
    while (1) 
    { 

		
	x=UART_RESIVED();
	LCD_WRITE_CHAR(x);
    }

}

