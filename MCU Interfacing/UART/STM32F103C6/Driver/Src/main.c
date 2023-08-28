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
#include "stm32f103c6_USART_drivers.h"
#include "stm32f103c6_RCC_drivers.h"




uint16_t ch ;

//
//void UART_IRQ_Callback (void)
//{
//
//	MCAL_USART_Rescieve_Data(USART1, &ch, disable);
//	MCAL_USART_Send_Data(USART1, &ch, enable);
//
//}

void clock_init()
{
	GPIOA_clock_enable();
	GPIOB_clock_enable();
	AFIO_clock_enable();
}


int main(void)
{

clock_init();
USART_config uart_define;
uart_define.BoudRate      = USART_BaudRate_115200Kbps;
uart_define.Data_size     = Data_size_8;
uart_define.IRq_enable    = USART_IRQ_enable_none;
uart_define.P_IRQ_callback=NULL;
uart_define.Parity        = none_parity;
uart_define.flow_control  = none_flow_control;
uart_define.mode_enable   =  USART_TX_RX_enable;
uart_define.stop_bit      = stop_bit_one;

MCAL_GPIO_USART_Set_pins(USART1);
MCAL_USART_Init(USART1,&uart_define);



	while(1)
	{
		MCAL_USART_Rescieve_Data(USART1, &ch, enable);
	   MCAL_USART_Send_Data    (USART1,     &ch, enable);




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
