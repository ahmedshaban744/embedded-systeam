/*
 * lcd.c
 *
 * Created: 7/29/2023 5:07:15 PM
 *  Author: Ahmed shaban
 */


#include "lcd.h"

void LCD_GOTO_XY(unsigned char line, unsigned char position){
	if (line == 1)
	{
		if (position < 16 && position >= 0)
		{
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW+position);
		}
	}
	if (line == 2)
	{
		if (position < 16 && position >= 0)
		{
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_SECOND_ROW+position);
		}
	}
}

void LCD_INIT()
{
	_delay_ms(20);
    //LCD_check_lcd_isbusy();
	DataDir_LCD_CTRL |= (1<<EN_SWITCH | 1<<RS_SWITCH | 1<<RW_SWITCH); // DDRB   (enable the register , send data , read mode)
	LCD_CTRL &= ~ (1<<EN_SWITCH | 1<<RS_SWITCH | 1<<RW_SWITCH);      // PORTB   (disable the register  , send command , write mode)
	
	DataDir_LCD_PORT = 0xFF;
	_delay_ms(15);
	LCD_clear_screen(); 
	
	#ifdef EIGHT_BIT_MODE
	//LCD_check_lcd_isbusy();
	LCD_WRITE_COMMAND(LCD_FUNCTION_8BIT_2LINES);
	#endif
	#ifdef FOUR_BIT_MODE
	LCD_check_lcd_isbusy();
	LCD_WRITE_COMMAND(0x02);
	LCD_WRITE_COMMAND(LCD_FUNCTION_4BIT_2LINES);
    /* send for 4 bit initialization of LCD  */
	//LCD_WRITE_COMMAND(0x28);              /* 2 line, 5*7 matrix in 4-bit mode */
	//LCD_WRITE_COMMAND(0x0c);              /* Display on cursor off*/
	//LCD_WRITE_COMMAND(0x06);              /* Increment cursor (shift cursor to right)*/
	//LCD_WRITE_COMMAND(0x01);
	//LCD_WRITE_COMMAND(0x02);
	
	#endif
		LCD_WRITE_COMMAND(LCD_ENTRY_MODE);
		LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
		LCD_WRITE_COMMAND(LCD_DISP_ON_CURSOR_BLINK);
}
void LCD_clear_screen(){
	LCD_WRITE_COMMAND(LCD_CLEAR_SCREEN);
}

void LCD_lcd_kick(){
	LCD_CTRL |= (1 << EN_SWITCH);
	_delay_ms(50);
	LCD_CTRL &= ~(1 << EN_SWITCH);
}
void LCD_WRITE_COMMAND(unsigned char command){
	//LCD_check_lcd_isbusy();
	#ifdef EIGHT_BIT_MODE
	LCD_check_lcd_isbusy();
	LCD_PORT = command; // put the command  at port-A
	LCD_CTRL &= ~((1 << RS_SWITCH) | (1<<RW_SWITCH));  //  make portB select command and at read mode
	_delay_ms(1);
	LCD_lcd_kick();
	#endif
	
	
	
	#ifdef FOUR_BIT_MODE
	LCD_check_lcd_isbusy();
	LCD_PORT = (LCD_PORT & 0x0F) | (command & 0xF0);
	LCD_CTRL &= ~ ((1<<RW_SWITCH)|(1<<RS_SWITCH));
	_delay_ms(5);
	LCD_lcd_kick ();
	LCD_PORT = (LCD_PORT & 0x0F) | (command << 4);
	LCD_CTRL &= ~ ((1<<RW_SWITCH)|(1<<RS_SWITCH));
	_delay_ms(1);
	LCD_lcd_kick();
	#endif
}
void LCD_WRITE_CHAR(unsigned char character){
	#ifdef EIGHT_BIT_MODE
	LCD_check_lcd_isbusy();
	LCD_PORT = character;
	LCD_CTRL &= ~(1 << RW_SWITCH);
	LCD_CTRL |= (1 << RS_SWITCH);
	_delay_ms(1);
	LCD_lcd_kick();
	#endif
	#ifdef FOUR_BIT_MODE
	LCD_check_lcd_isbusy();
	LCD_PORT = (LCD_PORT & 0x0F) | (character & 0xF0);
	LCD_CTRL |= 1<<RS_SWITCH; //turn RS ON for Data mode.
	LCD_CTRL &= ~ (1<<RW_SWITCH);//turn RW off so you can write.
	_delay_ms(1);
	LCD_lcd_kick();
	LCD_PORT = (LCD_PORT & 0x0F) | (character << 4);
	LCD_CTRL |= 1<<RS_SWITCH; //turn RS ON for Data mode.
	LCD_CTRL &= ~ (1<<RW_SWITCH);//turn RW off so you can write.
	_delay_ms(1);
	LCD_lcd_kick ();
	#endif
}

void LCD_WRITE_STRING(char* string){
	int count = 0;
	while (*string > 0){
		count++;
		LCD_WRITE_CHAR(*string++);
		if (count == 16)
		{
			LCD_GOTO_XY(2,0);
		}
		else if (count == 32)
		{
			LCD_clear_screen();
			LCD_GOTO_XY(1,0);
			count = 0;
		}
	}
}
void LCD_check_lcd_isbusy(){
	DataDir_LCD_PORT &= ~(0xFF<<shift);
	LCD_CTRL |= (1 << RW_SWITCH);
	LCD_CTRL &= ~(1 << RS_SWITCH);
	LCD_lcd_kick();
	DataDir_LCD_PORT |= (0xFF<<4);
	LCD_CTRL &= ~(1 << RW_SWITCH);
	
}

 
