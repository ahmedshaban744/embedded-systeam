/*
 * lcd.c
 *
 * Created: 7/27/2023 2:00:26 PM
 *  Author: Ahmed shaban
 */




#ifndef LCD_H_
#define LCD_H_
#define F_CPU 1000000UL

#include<avr/io.h>
#include<util/delay.h>
#define LCD_PORT PORTA
#define DataDir_LDD_port DDRA
#define LCD_CTRL PORTB
#define DataDir_LDD_CTRL DDRB
#define RS_SWITCH 1
#define RW_SWITCH 2
#define ENABLE_SWITCH 3


#define EIGHT_BIT_MODE
#define FOUR_BIT_MODE

#define LCD_FUNCTION_8BIT_2LINES   					(0x38)
#define LCD_FUNCTION_4BIT_2LINES   					(0x28)
#define LCD_MOVE_DISP_RIGHT       					(0x1C)
#define LCD_MOVE_DISP_LEFT   						(0x18)
#define LCD_MOVE_CURSOR_RIGHT   					(0x14)
#define LCD_MOVE_CURSOR_LEFT 	  					(0x10)
#define LCD_DISP_OFF   								(0x08)
#define LCD_DISP_ON_CURSOR   						(0x0E)
#define LCD_DISP_ON_CURSOR_BLINK   					(0x0F)
#define LCD_DISP_ON_BLINK   						(0x0D)
#define LCD_DISP_ON   								(0x0C)
#define LCD_ENTRY_DEC   							(0x04)
#define LCD_ENTRY_DEC_SHIFT   						(0x05)
#define LCD_ENTRY_INC_   							(0x06)
#define LCD_ENTRY_INC_SHIFT   						(0x07)
#define LCD_BEGIN_AT_FIRST_ROW						(0x80)
#define LCD_BEGIN_AT_SECOND_ROW						(0xC0)
#define LCD_CLEAR_SCREEN							(0x01)
#define LCD_ENTRY_MODE								(0x06)


void LCD_INIT();
void LCD_WRITE_COMMAND(unsigned char command);
void LCD_WRITE_CHAR(unsigned char character);
void LCD_WRITE_STRING(char* string);
void LCD_check_lcd_isbusy(void);
void LCD_lcd_kick(void);
void LCD_clear_screen();
void LCD_GOTO_XY(unsigned char line, unsigned char position);



#endif /* LCD_H_ */



















 
//#include <lcd.h>
void LCD_lcd_kick()
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
//void LCD_clear_screen()
//{
  //  LCD_WRITE_COMMAND(LCD_clear_screen());
//}
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
//LCD_clear_screen();
LCD_WRITE_COMMAND(LCD_FUNCTION_8BIT_2LINES );	
#endif

LCD_WRITE_COMMAND(LCD_ENTRY_MODE	);
LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);	
LCD_WRITE_COMMAND(LCD_DISP_ON_CURSOR_BLINK );


	
}