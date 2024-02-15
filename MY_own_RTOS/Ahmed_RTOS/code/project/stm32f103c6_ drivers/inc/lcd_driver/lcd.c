/*
 * lcd.c
 *
 * Created: 7/29/2023 5:07:15 PM
 *  Author: Ahmed shaban
 */


#include <stm32f103c6_GPIO_drivers.h>
#include "lcd.h"
#include "stm32f103x6.h"

/**================================================================
 * @Fn          -  delay_LCD
 * @brief       - make simdelay_LCDlay
 * @param [in]  -delay/ the time of the delay
 * @retval      - null
 * Note         - null
 * */
void delay_LCD(unsigned int delay)
{
	volatile int i,j;
	for(i=0;i<delay;i++)
		for(j=0;j<255;j++);

}
/**================================================================
 * @Fn                   -  LCD_GOTO_XY
 * @brief                - determind the position in the LCD
 * @param [in]           - line: the line number   <<< 1 or 2>>>
 * @param [in]           - position : the cursor position in the LCD  <<<1 --- 16>>>
 * @retval               - null
 * Note                  - that valled for LCD 2*16 only
 * */
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
/**================================================================
 * @Fn                   -  LCD_INIT
 * @brief                - initalization the LCD PINS
 * @param [in]           -NULL
 * @param [in]           -NULL
 * @retval               -NULL
 * Note                  -NULL
 * */
void LCD_INIT()
{
	delay_LCD(20);
	GPIO_pinconfig_t  pincfg;

	//-------------------------------------------------------------------------------------------
	// the data pins
	pincfg.gpio_pin_number =GPIO_PIN_0;
	pincfg.GPIO_MODE=GPIO_MODE_OUTPUT_PP ;
	pincfg.GPIO_OUTPUT_SPEED=GPIO_SPEED_10MHZ;
	MCAL_GPIO_INIT(LCD_PORT, &pincfg);

	pincfg.gpio_pin_number =GPIO_PIN_1;
	pincfg.GPIO_MODE=GPIO_MODE_OUTPUT_PP ;
	pincfg.GPIO_OUTPUT_SPEED=GPIO_SPEED_10MHZ;
	MCAL_GPIO_INIT(LCD_PORT, &pincfg);


	pincfg.gpio_pin_number =GPIO_PIN_2;
	pincfg.GPIO_MODE=GPIO_MODE_OUTPUT_PP ;
	pincfg.GPIO_OUTPUT_SPEED=GPIO_SPEED_10MHZ;
	MCAL_GPIO_INIT(LCD_PORT, &pincfg);


	pincfg.gpio_pin_number =GPIO_PIN_3;
	pincfg.GPIO_MODE=GPIO_MODE_OUTPUT_PP ;
	pincfg.GPIO_OUTPUT_SPEED=GPIO_SPEED_10MHZ;
	MCAL_GPIO_INIT(LCD_PORT, &pincfg);

	pincfg.gpio_pin_number =GPIO_PIN_4;
	pincfg.GPIO_MODE=GPIO_MODE_OUTPUT_PP ;
	pincfg.GPIO_OUTPUT_SPEED=GPIO_SPEED_10MHZ;
	MCAL_GPIO_INIT(LCD_PORT, &pincfg);

	pincfg.gpio_pin_number =GPIO_PIN_5;
	pincfg.GPIO_MODE=GPIO_MODE_OUTPUT_PP ;
	pincfg.GPIO_OUTPUT_SPEED=GPIO_SPEED_10MHZ;
	MCAL_GPIO_INIT(LCD_PORT, &pincfg);

	pincfg.gpio_pin_number =GPIO_PIN_6;
	pincfg.GPIO_MODE=GPIO_MODE_OUTPUT_PP ;
	pincfg.GPIO_OUTPUT_SPEED=GPIO_SPEED_10MHZ;
	MCAL_GPIO_INIT(LCD_PORT, &pincfg);

	pincfg.gpio_pin_number =GPIO_PIN_7;
	pincfg.GPIO_MODE=GPIO_MODE_OUTPUT_PP ;
	pincfg.GPIO_OUTPUT_SPEED=GPIO_SPEED_10MHZ;
	MCAL_GPIO_INIT(LCD_PORT, &pincfg);
//--------------------------------------------------------------------------------------------
	//	RS_SWITCH input floating
	pincfg.gpio_pin_number =RS_SWITCH;
	pincfg.GPIO_MODE=GPIO_MODE_OUTPUT_PP ;
	pincfg.GPIO_OUTPUT_SPEED=GPIO_SPEED_10MHZ;
	MCAL_GPIO_INIT(LCD_PORT, &pincfg);

	//	RW_SWITCH input floating
	pincfg.gpio_pin_number =RW_SWITCH;
	pincfg.GPIO_MODE=GPIO_MODE_OUTPUT_PP ;
	pincfg.GPIO_OUTPUT_SPEED=GPIO_SPEED_10MHZ;
	MCAL_GPIO_INIT(LCD_PORT, &pincfg);

	//	ENABLE_SWITCH  input floating
	pincfg.gpio_pin_number =ENABLE_SWITCH ;
	pincfg.GPIO_MODE=GPIO_MODE_OUTPUT_PP ;
	pincfg.GPIO_OUTPUT_SPEED=GPIO_SPEED_10MHZ;
	MCAL_GPIO_INIT(LCD_PORT, &pincfg);





	MCAL_GPIO_write_pin(LCD_CTRL, ENABLE_SWITCH, GPIO_pin_reset);
	MCAL_GPIO_write_pin(LCD_CTRL, RS_SWITCH, GPIO_pin_reset);
	MCAL_GPIO_write_pin(LCD_CTRL, RW_SWITCH, GPIO_pin_reset);

	delay_LCD(15);

	LCD_WRITE_COMMAND(LCD_FUNCTION_8BIT_2LINES);
	LCD_WRITE_COMMAND(LCD_ENTRY_MODE);
	LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
	LCD_WRITE_COMMAND(LCD_DISP_ON_CURSOR_BLINK);
	LCD_clear_screen();





}
/**================================================================
 * @Fn                   -  LCD_clear_screen
 * @brief                - clear the screen and start from line 0 posation 0
 * @param [in]           -NULL
 * @retval               -NULL
 * Note                  -NULL
 * */
void LCD_clear_screen(){
	LCD_WRITE_COMMAND( LCD_CLEAR_SCREEN);
}
/**================================================================
 * @Fn                   -  LCD_lcd_kick
 * @brief                - set and then reset the  ENABLE_SWITCH
 * @param [in]           -NULL
 * @retval               -NULL
 * Note                  -NULL
 * */
void LCD_lcd_kick(){
	MCAL_GPIO_write_pin(LCD_CTRL, ENABLE_SWITCH , GPIO_pin_set);
	delay_LCD(50);
	MCAL_GPIO_write_pin(LCD_CTRL, ENABLE_SWITCH , GPIO_pin_reset);
}
/**================================================================
 * @Fn                   -  LCD_WRITE_COMMAND
 * @brief                - write command to the port
 * @param [in]           -command the command than need to write
 * @retval               -NULL
 * Note                  - that code for 8 bit mode
 * */
void LCD_WRITE_COMMAND(unsigned char command){



	//LCD_check_lcd_isbusy();
	MCAL_GPIO_write_port(LCD_PORT , command);
	MCAL_GPIO_write_pin(LCD_PORT, RS_SWITCH, GPIO_pin_reset);
	MCAL_GPIO_write_pin(LCD_PORT, RW_SWITCH, GPIO_pin_reset);
	delay_LCD(1);
	LCD_lcd_kick();

	//#ifdef EIGHT_BIT_MODE
	//	LCD_check_lcd_isbusy();
	//	MCAL_GPIO_write_port(LCD_PORT , command);
	//	MCAL_GPIO_write_pin(LCD_PORT, RS_SWITCH, GPIO_pin_reset);
	//	MCAL_GPIO_write_pin(LCD_PORT, RW_SWITCH, GPIO_pin_set);
	//	delay_LCD(1);
	//	LCD_lcd_kick();
	//#endif

	//#ifdef FOUR_BIT_MODE
	//	LCD_check_lcd_isbusy();
	//	MCAL_GPIO_write_port(LCD_PORT & 0x0F, command & 0xF0);
	//	MCAL_GPIO_write_pin(LCD_CTRL, RW_SWITCH, GPIO_pin_reset);
	//	MCAL_GPIO_write_pin(LCD_CTRL, RS_SWITCH, GPIO_pin_set);
	//	delay_LCD(5);
	//	LCD_lcd_kick ();
	//	MCAL_GPIO_write_port(LCD_PORT & 0x0F, command << 4);
	//	delay_LCD(1);
	//	LCD_lcd_kick();
	//	//#endif
}

/**================================================================
 * @Fn                   -  LCD_WRITE_CHAR
 * @brief                - write char to the port
 * @param [in]           -character the character than need to write
 * @retval               -NULL
 * Note                  - that code for 8 bit mode
 * */
void LCD_WRITE_CHAR(unsigned char character){
	//LCD_check_lcd_isbusy();
	MCAL_GPIO_write_port(LCD_PORT, character);
	MCAL_GPIO_write_pin(LCD_PORT, RW_SWITCH, GPIO_pin_reset);
	MCAL_GPIO_write_pin(LCD_PORT, RS_SWITCH, GPIO_pin_set);
	delay_LCD(1);
	LCD_lcd_kick();
	//
	//#ifdef EIGHT_BIT_MODE
	//	MCAL_GPIO_write_port(LCD_PORT, character);
	//	MCAL_GPIO_write_pin(LCD_PORT, RW_SWITCH, GPIO_pin_reset);
	//	MCAL_GPIO_write_pin(LCD_PORT, RS_SWITCH, GPIO_pin_set);
	//	delay_LCD(1);
	//	LCD_lcd_kick();
	//#endif
	//#ifdef FOUR_BIT_MODE
	//	LCD_check_lcd_isbusy();
	//	MCAL_GPIO_write_port(LCD_PORT & 0x0F, character & 0xF0);
	//	MCAL_GPIO_write_pin(LCD_CTRL, RS_SWITCH, GPIO_pin_set);
	//	MCAL_GPIO_write_pin(LCD_CTRL, RW_SWITCH, GPIO_pin_reset);
	//	delay_LCD(1);
	//	LCD_lcd_kick();
	//	MCAL_GPIO_write_port(LCD_PORT & 0x0F, character <<4);
	//    MCAL_GPIO_write_pin(LCD_CTRL, RS_SWITCH, GPIO_pin_set);
	//    MCAL_GPIO_write_pin(LCD_CTRL, RW_SWITCH, GPIO_pin_reset);
	//	delay_LCD(1);
	//	LCD_lcd_kick ();
	//	LCD_PORT = (LCD_PORT & 0x0F) | (character & 0xF0);
	//	LCD_CTRL |= 1<<RS_SWITCH; //turn RS ON for Data mode.
	//	LCD_CTRL &= ~ (1<<RW_SWITCH);//turn RW off so you can write.
	//	delay_LCD(1);
	//	LCD_lcd_kick();
	//	LCD_PORT = (LCD_PORT & 0x0F) | (character << 4);
	//	LCD_CTRL |= 1<<RS_SWITCH; //turn RS ON for Data mode.
	//	LCD_CTRL &= ~ (1<<RW_SWITCH);//turn RW off so you can write.
	//	delay_LCD(1);
	//	LCD_lcd_kick ();
	//#endif
}
/**================================================================
 * @Fn                   -  LCD_WRITE_STRING
 * @brief                - write string  to the port
 * @param [in]           -string the string than need to write
 * @retval               -NULL
 * Note                  - that code for 8 bit mode
 * */
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

/**================================================================
 * @Fn                   -  LCD_check_lcd_isbusy
 * @brief                - check lcd state
 * @param [in]           -NULL
 * @retval               -NULL
 * Note                  -NULL
 * */
void LCD_check_lcd_isbusy()
{
	//GPIO_pinconfig_t pincfg;
	GPIO_pinconfig_t  pincfg;
	pincfg.gpio_pin_number = GPIO_PIN_0;
	pincfg.GPIO_MODE= GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_INIT(LCD_CTRL, &pincfg);

	pincfg.gpio_pin_number = GPIO_PIN_1;
	pincfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_INIT(LCD_CTRL, &pincfg);

	pincfg.gpio_pin_number = GPIO_PIN_2;
	pincfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_INIT(LCD_CTRL, &pincfg);

	pincfg.gpio_pin_number = GPIO_PIN_3;
	pincfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_INIT(LCD_CTRL, &pincfg);

	pincfg.gpio_pin_number = GPIO_PIN_4;
	pincfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_INIT(LCD_CTRL, &pincfg);

	pincfg.gpio_pin_number = GPIO_PIN_5;
	pincfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_INIT(LCD_CTRL, &pincfg);

	pincfg.gpio_pin_number = GPIO_PIN_6;
	pincfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_INIT(LCD_CTRL, &pincfg);

	pincfg.gpio_pin_number = GPIO_PIN_7;
	pincfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_INIT(LCD_CTRL, &pincfg);

	MCAL_GPIO_write_pin(LCD_CTRL, RW_SWITCH, GPIO_pin_set)  ;
	MCAL_GPIO_write_pin(LCD_CTRL, RS_SWITCH, GPIO_pin_reset);
	LCD_lcd_kick();
	MCAL_GPIO_write_pin(LCD_CTRL, RW_SWITCH, GPIO_pin_reset);


}
