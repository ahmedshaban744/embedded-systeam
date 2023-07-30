/*
 * lcd and keypad.c
 *
 * Created: 7/27/2023 1:58:49 PM
 * Author : Ahmed shaban
 */ 

#include <avr/io.h>
//#include "lcd driver/lcd.h"
#include "lcd.h"

int main(void)
{
    /* Replace with your application code */
	LCD_INIT();
	LCD_WRITE_CHAR('A');
	
    while (1) 
    {
    }
}

