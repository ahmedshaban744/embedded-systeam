/*
 * lcd_and_keypad.c
 *
 * Created: 7/29/2023 4:27:38 PM
 * Author : Ahmed Shaban
 */ 

#include <avr/io.h>
#include "lcd driver1/lcd.h"
#include "keypad driver 1/keypad.h"
int cal(int val1 , int val2, char oparator)
{ 
	switch(oparator)
	{
		case '+':
		     return val1+val2;
		     break;
		case '-':
		     return val1-val2;
		     break;
		case '/':
		    return val1 /val2;
	     	break;
		case'*':
		   return val1*val2;
		    break;
	default:			  
	break;
	}
}
int main(void)
{
	 
	 LCD_INIT();
	 keypad_init();
	 
     LCD_WRITE_STRING("   ***welcom*** ");
	 _delay_ms(600);
	 LCD_clear_screen();
	 char keypad_press;
	 int count;
    /* Replace with your application code */
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
return 0;
}



