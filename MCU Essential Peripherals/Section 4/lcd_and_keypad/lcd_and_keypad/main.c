/*
 * lcd_and_keypad.c
 *
 * Created: 7/29/2023 4:27:38 PM
 * Author : Ahmed Shaban
 */ 

#include <avr/io.h>
#include "lcd driver1/lcd.h"
#include "keypad driver 1/keypad.h"
#define F_CPU 1000000
#define PORTC (*(volatile unsigned char *)0x35)
#define DDRC (*(volatile unsigned char*)0x34)
#define PINC (*(volatile unsigned char*)0x33)
static unsigned char segment_number[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
static unsigned char num[]={'0','1','2','3','4','5','6','7','8','9'};
int main(void)
{
	 
	 LCD_INIT();
	 	  LCD_WRITE_STRING("  *welcom*");	 
		   _delay_ms(10000);
		  LCD_clear_screen();
	DDRC=0xff;
	unsigned int j;
			
			for(j=0;j<10;j++)
			{
				PORTC=segment_number[j];
				
				_delay_ms(10000);
				LCD_WRITE_CHAR(num[j]);
			}
				_delay_ms(10000);
			 LCD_clear_screen();;
 keypad_init();
 LCD_WRITE_STRING("*keypad ready*");
 _delay_ms(10000);
 LCD_clear_screen(); 
	 int keypad_press;
	 int count;

	 while (1)
	 {
		 keypad_press=git_char();
		 
		 switch(keypad_press)
		 {
			 case ('N'):
			 
			 break;
			 
			 case ('!'):
			 
			 LCD_clear_screen();
			 break;
			 
			 default:
	
			 if(count == 16) // check if cursor reach to the end of line 1
			 {
				 LCD_GOTO_XY(2,0);
			 }
			 else if(count == 32)// check if cursor reach to the end of line 2
			 {
				 LCD_clear_screen();
				 LCD_GOTO_XY(1,0);
			 }
			 count++;
			 
			 
			 LCD_WRITE_CHAR(keypad_press) ;
			 
		 } 
   
	
	
   
		 }
}



