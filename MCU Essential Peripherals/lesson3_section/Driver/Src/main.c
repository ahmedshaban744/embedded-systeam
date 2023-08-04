/* Includes ------------------------------------------------------------------*/
/**
 ******************************************************************************
 * @file           : main.c
 * @author         : ahmed shaban mohamed
 * @brief          : Main program body
 ******************************************************************************

 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


#include "stm32f103x6.h"
#include "stm32f103c6_ gpio_drivers.h"
#include  "lcd.h"
#include "keypad.h"
#include "7_segmant.h"

void clock_init()
{
	//Enable Init Clock GPIOA
	GPIOA_clock_enable();

	//Enable Init Clock GPIOB
	GPIOB_clock_enable();

}


void delay_main(unsigned int x)
{
	volatile int i,j;
	for(i=0;i<x;i++)
		for(j=0;j<255;j++);

}

int main(void)
{
	clock_init();
	LCD_INIT();
	LCD_WRITE_STRING("   LCD is READY   ");
	delay_main(500);
	LCD_clear_screen();

	sev_segmant_init();
	LCD_WRITE_STRING("SEVEN SEGMANT    is READY");
	delay_main(500);
	LCD_clear_screen();


	unsigned char LCD_DISPLAY [11] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
	unsigned int DISPLAY [11] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, ZERO};
	for (unsigned char i = 0; i < 11; i++)
	{
		LCD_WRITE_CHAR(LCD_DISPLAY[i]);
		MCAL_GPIO_write_port(GPIOB,DISPLAY[i]<<9 ); /* write data on to the LED port */

		delay_main(100);

	}
	LCD_clear_screen();
	keypad_init();
	LCD_WRITE_STRING("    KEYPAD_READY   "   );
	delay_main(500);
	LCD_clear_screen();

	int key_press;
	int count=0;
	while(1)
	{

		key_press=	git_char();
		switch(key_press)
		{
		case 'N':
			break;
		case '!':
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


			LCD_WRITE_CHAR(key_press) ;
			break;


		}


	}

}

#ifdef  USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t *file, uint32_t line)
{
	/* USER CODE BEGIN 6 */
	/* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
	/* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
