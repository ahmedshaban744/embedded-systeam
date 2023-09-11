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
uint16_t ch;

void UART_CALLBACK(void)
{
#ifdef MCU_ACT_AS_MASTER
	MCAL_USART_Rescieve_Data(USART1, &ch, disable)	;
	MCAL_USART_Send_Data(USART1, &ch, disable);
	MCAL_GPIO_write_pin(GPIOA, GPIO_PIN_4, GPIO_pin_reset);
	MCAL_SPI_TX_RX(SPI1, &ch, SPI_enable);
	MCAL_GPIO_write_pin(GPIOA, GPIO_PIN_4,GPIO_pin_set);
#endif

}
void SPI_CALLBACK(struct intrput_src scr)
{
#ifdef MCU_ACT_AS_slave
	if(scr.RXNE)
	{
		MCAL_SPI_TX_RX(SPI1, &ch, SPI_enable);
        MCAL_USART_Send_Data(USART1, &ch, enable);
    }
}

#endif

void clock_init()
{
	GPIOA_clock_enable();
	GPIOB_clock_enable();
	AFIO_clock_enable();
}


int main(void)
{
	//UART INIT
	clock_init();
	USART_config uart_define;
	uart_define.BoudRate      = USART_BaudRate_115200Kbps;
	uart_define.Data_size     = Data_size_8;
	uart_define.IRq_enable    = USART_IRQ_enable_RXNE;
	uart_define.P_IRQ_callback=UART_CALLBACK;
	uart_define.Parity        = none_parity;
	uart_define.flow_control  = none_flow_control;
	uart_define.mode_enable   =  USART_TX_RX_enable;
	uart_define.stop_bit      = stop_bit_one;
	MCAL_GPIO_USART_Set_pins(USART1);
	MCAL_USART_Init(USART1,&uart_define);

	//SPI_INIT
	SPI_confog_t SPI_confog_t;
	SPI_confog_t.Boud_rate=SPI_boud_rate_prescaler8;
	SPI_confog_t.clock_phase=SPI_second_edge_sampling;
	SPI_confog_t.clock_polarity=SPI_high_at_idil_state;
	SPI_confog_t.data_size=SPI_data_size_8_bit;
	SPI_confog_t.fram_format=SPI_MSB_first;
	SPI_confog_t.direcation=SPI_full_duplex;

#ifdef MCU_ACT_AS_MASTER
	SPI_confog_t.device_mode =SPI_Master_mode;
	SPI_confog_t.NSS=SPI_NSS_software_enable;
	SPI_confog_t.IRQ_enable=SPI_IRQ_RXNEIE_enable;
	SPI_confog_t.p_IQR_callback=NULL;
//control NSS by SW
	GPIO_pinconfig_t pinconfig;
	pinconfig.gpio_pin_number =GPIO_PIN_4;
	pinconfig.GPIO_MODE=GPIO_MODE_OUTPUT_PP;
	pinconfig.GPIO_OUTPUT_SPEED=GPIO_SPEED_10MHZ;
	MCAL_GPIO_INIT(GPIOA, &pinconfig);
	MCAL_GPIO_write_pin(GPIOA, GPIO_PIN_4, GPIO_pin_set);

#endif

#ifdef MCU_ACT_AS_slave
	SPI_confog_t.device_mode =SPI_slave_mode;
	SPI_confog_t.NSS=SPI_NSS_hardware_slave_mode;
	SPI_confog_t.p_IQR_callback=SPI_CALLBACK;
#endif
	MCAL_SPI_INIT(SPI1, &SPI_confog_t);
	MCAL_SPI_GPIO_SET_PINS(SPI1);



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
