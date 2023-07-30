/*
 * lcd.c
 *
 * Created: 7/27/2023 2:00:26 PM
 *  Author: Ahmed shaban
 */ 
#include<lcd.h>
LCD_lcd_kick()
{
	LCD_CTRL |= (1 <<  ENABLE_SWITCH);
	_delay_ms(50);
	LCD_CTRL &= ~(1 <<  ENABLE_SWITCH);
}

void LCD_check_lcd_isbusy(void) 
{ 
DataDir_LDD_port&=~(0xff<<4);// DDR PORT A input mode
 //  put in read mode
	LCD_CTRL |= (1 << RW_SWITCH);
	LCD_CTRL &= ~(1 << RS_SWITCH); //close the command 
	LCD_CTRL &=~(1<<ENABLE_SWITCH); // close the enable to stop
	_delay_ms(50);
	
	LCD_CTRL &=(1<<ENABLE_SWITCH);
	DataDir_LDD_port&=(0xff<<4);
	LCD_CTRL &=~(1 << RW_SWITCH);
	
}
void LCD_clear_screen()
{
LCD_WRITE_COMMAND(LCD_clear_screen());
}
void LCD_WRITE_COMMAND(unsigned char command)
{
	#ifdef EIGHT_BIT_MODE
	LCD_check_lcd_isbusy();
	LCD_PORT = command;
	LCD_CTRL &= ~((1 << RS_SWITCH) | (1<<RW_SWITCH));
	_delay_ms(1);
	LCD_lcd_kick();
	#endif
}

void LCD_WRITE_CHAR(unsigned char character)
{
	#ifdef EIGHT_BIT_MODE
	LCD_check_lcd_isbusy();
	LCD_PORT = character;
	LCD_CTRL &= ~(1 << RW_SWITCH) ;
	LCD_CTRL |=(1 << RS_SWITCH) ;	
	_delay_ms(1);
	LCD_lcd_kick();
	#endif
}
void LCD_INIT()
{
_delay_ms(20);
#ifdef EIGHT_BIT_MODE
    LCD_check_lcd_isbusy() ;
DataDir_LDD_port|=(1<<ENABLE_SWITCH)|(1<<RW_SWITCH)|(1<<RS_SWITCH);
LCD_CTRL&=~(1<<ENABLE_SWITCH)|(1<<RW_SWITCH)|(1<<RS_SWITCH);
DataDir_LDD_port=0xff; // 
LCD_clear_screen();
LCD_WRITE_COMMAND(LCD_FUNCTION_8BIT_2LINES );	
#endif

LCD_WRITE_COMMAND(LCD_ENTRY_MODE	);
LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);	
LCD_WRITE_COMMAND(LCD_DISP_ON_CURSOR_BLINK );


	
}