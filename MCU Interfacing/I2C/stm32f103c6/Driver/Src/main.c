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
#define  MCU_ACT_AS_MASTER
#define  MCU_ACT_AS_slave

#include "stm32f103x6.h"
#include "stm32f103c6_GPIO_drivers.h"
#include "stm32f103c6_USART_drivers.h"
#include "stm32f103c6_RCC_drivers.h"
#include "stm32f103c6_SPI_drivers.h"
#include "stm32f103c6_I2C_drivers.h"
#include "EEPROM.h"



void clock_init()
{
	GPIOA_clock_enable();
	GPIOB_clock_enable();
	AFIO_clock_enable();
}


int main(void)
{
	clock_init();

	//Test case 1
		uint8_t DATA1[] = {0x1,0x2,0x3,0x4,0x5,0x6,0x7};
		uint8_t DATA2[7]= {0};

		Hall_E2PROM_INIT();
	    Hall_E2PROM_Write_NBYTE (0xAF, DATA1, 7) ;
		Hall_E2PROM_read_NBYTE(0xAF, DATA2, 7);

		//Test case 2
		DATA1[0] = 0xA;
		DATA1[1] = 0xB;
		DATA1[2] = 0xC;
		DATA1[3] = 0xD;

		 Hall_E2PROM_Write_NBYTE (0xFFF, DATA1, 4);
		 Hall_E2PROM_read_NBYTE  (0xFFF, DATA2, 4);


	while(1)
	{

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
