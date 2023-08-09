/*

 ******************************************************************************
 * @file           : main.c
 * @author         : Ahmed shaban mohamed
 * @brief          : Main program body
 ******************************************************************************

 *
 ******************************************************************************
 */
//Includes ------------------------------------------------------------------*/

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


#include "stm32f103x6.h"
#include "stm32f103c6_GPIO_drivers.h"
#include "stm32f103c6_EXTI_drivers.h"
#include  "lcd.h"
#include "keypad.h"
#include "7_segmant.h"
unsigned int  flag=0;
void EXTI9B_Callback (void)
{
	flag=1;
LCD_WRITE_STRING("IQR9 is happen");
delay(500);


}
void clock_init()
{
	GPIOA_clock_enable();
	GPIOB_clock_enable();
	AFIO_clock_enable();

}

void delay(unsigned int x)

{
	volatile int i,j;
	for(i=0;i<x;i++)
	for(j=0;j<50;j++);

}

int main(void)
{
	clock_init();
	LCD_INIT();
	LCD_clear_screen();
	LCD_WRITE_STRING("LCD IS READY");
	delay(50);
	LCD_clear_screen();
	keypad_init();
	LCD_WRITE_STRING("KEYPAD IS READY");
	delay(50);
	LCD_clear_screen();


	EXIT_Confing_t confuger;
	confuger.EXIT_Pin= EXTI9B9;
	confuger.trigger_case= EXIT_Rising ;

	confuger.p_IRQ_Callback = EXTI9B_Callback;
	confuger.IRQ_define=EXIT_IRQ_enable;
	MCAL_EXTI_GPIO_INIT(&confuger);
   flag=1;
	while(1)
	{


		if(flag)
		{
			LCD_clear_screen();
			flag=0;
	}
	}
return 0;
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
