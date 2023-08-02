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
#define F_CPU 8000000UL


void clock_init()
{
	//Enable Init Clock GPIOA
	GPIOA_clock_enable();

	//Enable Init Clock GPIOB
	GPIOB_clock_enable();

}

void GPIO_init()
{
//PIN 1 PORT A
GPIO_pinconfig_t pincfg;
pincfg.gpio_pin_number =GPIO_PIN_1;
pincfg.GPIO_MODE=GPIO_MODE_INPUT_FLO ;
MCAL_GPIO_INIT(GPIOA, &pincfg);

//PIN 1 PORT B
pincfg.gpio_pin_number =GPIO_PIN_1;
pincfg.GPIO_MODE=GPIO_MODE_OUTPUT_PP;
pincfg.GPIO_OUTPUT_SPEED=GPIO_SPEED_10MHZ;
MCAL_GPIO_INIT(GPIOB, &pincfg);

//PIN 13 PORT A
pincfg.gpio_pin_number =GPIO_PIN_13;
pincfg.GPIO_MODE=GPIO_MODE_INPUT_FLO;
MCAL_GPIO_INIT(GPIOA, &pincfg);

//PIN 13 PORT B
pincfg.gpio_pin_number =GPIO_PIN_13;
pincfg.GPIO_MODE=GPIO_MODE_OUTPUT_PP ;
pincfg.GPIO_OUTPUT_SPEED=GPIO_SPEED_10MHZ;
MCAL_GPIO_INIT(GPIOB, &pincfg);

}
void delay(unsigned int x)
{
	volatile int i,j;
	for(i=0;i<x;i++)
	for(j=0;j<255;j++);

}

int main(void)
{
	clock_init();
	GPIO_init();
	while(1)
	{
	    // PA1 Button (Pull-up) >> Toggle LED on Single Press
	    if ((MCAL_GPIO_Read_pin(GPIOA, GPIO_PIN_1)==0 )) // Button A1 is pressed
	    {

           MCAL_GPIO_toggle_pin(GPIOB, GPIO_PIN_1); // Toggle LED
	       while ((MCAL_GPIO_Read_pin(GPIOA, GPIO_PIN_1))==0);
	       // Wait until button is released
	    }


	    // PA13 Button (Pull-down) >> Toggle LED on Press

	    if ((MCAL_GPIO_Read_pin(GPIOA, GPIO_PIN_13)) == 1) // Button A13 is pressed

	    {
	    	 MCAL_GPIO_toggle_pin(GPIOB, GPIO_PIN_13); // Toggle LED
	    }


	    // Delay to avoid rapid toggling due to button bounce
	    //delay(1);
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
