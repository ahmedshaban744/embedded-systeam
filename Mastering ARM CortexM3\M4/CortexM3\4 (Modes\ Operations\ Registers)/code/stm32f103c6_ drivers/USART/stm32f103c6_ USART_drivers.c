/*
 * stm32f103c6_ USART_drivers.c
 *
 *  Created on: Aug 20, 2023
 *      Author: Ahmed Shaban
 */
//=========================================================================================
//=======================includes==========================================================
//=========================================================================================
#include "stm32f103c6_USART_drivers.h"
#include "stm32f103c6_RCC_drivers.h"
#include "stm32f103x6.h"
#include <stdint.h>



//USART_config * GL_USART_config = NULL;
USART_config *GL_USART_configs[3]={NULL ,NULL,NULL};
/**================================================================
 * @Fn                   -MCAL_USART_Send_Data
 * @brief                -initialize the USARTX pin  to a specified parameters
 * @param [in]           -USARTX where x can be (USARTX1 USARTX2 USART3)
 * @retval               - null
 * Note                  -null
 */

void MCAL_USART_Init(USART_typedef*USARTX,USART_config * USART_defin)
{

	//GL_USART_config= USART_defin;
	uint32_t plck1,BRR;
	//clock enable
	if(USARTX==USART1)
	{

		USART1_clock_enable();
		GL_USART_configs[0]=USART_defin;
	}
	else if(USARTX==USART2)
	{
		USART2_clock_enable();
	   GL_USART_configs[1]=USART_defin;
}
	else if(USARTX==USART3)
	{
		USART3_clock_enable();
		GL_USART_configs[2]=USART_defin;
	}

	//USART enable
	USARTX->CR1|=1<<13;
	//mode init
	USARTX->CR1 |= USART_defin->mode_enable;
	//	size init
	USARTX->CR1 |= USART_defin->Data_size;
	//	parity init
	USARTX->CR1 |= USART_defin->Parity;
	//	stop bit init
	USARTX->CR2 |= USART_defin->stop_bit;
	//	flow control
	USARTX->CR3 |= USART_defin->flow_control;
	//boud rate init

	//cal pll clock
	if (USARTX==USART1)
		plck1= MCAL_RCC_Get_PClock2_clock ();
	else if (USARTX==USART2)
		plck1= MCAL_RCC_Get_PClock1_clock ();
	else if (USARTX==USART3)
		plck1= MCAL_RCC_Get_PClock1_clock ();


	BRR =UART_BRR_Register(plck1,USART_defin->BoudRate);
	USARTX->BRR=BRR;
	//enable interrput
	if(USART_defin->IRq_enable!=USART_IRQ_enable_none )
	{
		USARTX->CR1 |=USART_defin->IRq_enable;

		if (USARTX==USART1)
			NVIC_IRQ37_USART1_enable()   ;
		else if (USARTX==USART2)
			NVIC_IRQ38_USART2_enable()   ;
		else if (USARTX==USART3)
			NVIC_IRQ39_USART3_enable()   ;

	}
}
/**================================================================
 * @Fn                   -MCAL_USART_DEInit
 * @brief                -deinitialize the USARTX pin  to a specified parameters
 * @param [in]           -USARTX where x can be (USARTX1 USARTX2 USART3)
 * @retval               - null
 * Note                  -null
 */

void MCAL_USART_DEInit (USART_typedef*USARTX)
{
	if (USARTX==USART1)
	{
		USART1_clock_RESET() ;
		NVIC_IRQ37_USART1_disable();
	}
	else if (USARTX==USART2)
	{
		USART2_clock_RESET() ;
		NVIC_IRQ38_USART2_disable();
	}
	else if (USARTX==USART3)
	{
		USART3_clock_RESET() ;
		NVIC_IRQ39_USART3_disable();
	}
}
/**================================================================
 * @Fn                   -MCAL_USART_Send_Data
 * @brief                -send data by UART
 * @param [in]           -USARTX where x can be (USARTX1 USARTX2 USART3)
 * @retval               - null
 * Note                  -
 */
void MCAL_USART_Send_Data(USART_typedef*USARTX ,uint16_t*Data,enum polling_mechism polling )
{
	USART_config * UART_Config = NULL;
		if      (USARTX == USART1) 		UART_Config = GL_USART_configs[0];
		else if	(USARTX == USART2) 		UART_Config = GL_USART_configs[1];
		else if	(USARTX == USART3) 		UART_Config = GL_USART_configs[2];
	if(polling==enable)
		//Bit 7 TXE:
		//	0: Data is not transferred to the shift register
		//	1: Data is transferred to the shift register)
	{
//		Bit 7 TXE: Transmit data register empty
//		This bit is set by hardware when the content of the TDR register has been transferred into
//		the shift register. An interrupt is generated if the TXEIE bit =1 in the USART_CR1 register. It
//		is cleared by a write to the USART_DR register.
//		0: Data is not transferred to the shift register
//		1: Data is transferred to the shift register)
//		Note: This bit is used during single buffer transmission
		while(!(USARTX->SR & 1<<7));
//		When transmitting with the parity enabled (PCE bit set to 1 in the USART_CR1 register),
//		the value written in the MSB (bit 7 or bit 8 depending on the data length) has no effect
//		because it is replaced by the parity.
//		When receiving with the parity enabled, the value read in the MSB bit is the received parity
//		bit
	}
	if(UART_Config->Data_size==Data_size_9)
	{
		USARTX->DR=(*Data & (uint16_t) 0x01FF);
	}
	else
	{
		USARTX->DR=(*Data & (uint8_t) 0x00FF);
	}
}
/**================================================================
 * @Fn                   -MCAL_Wait_TC
 * @brief                -wait until transmeting complet
 * @param [in]           -USARTX where x can be (USARTX1 USARTX2 USART3)
 * @retval               - null
 * Note                  -
 */
void MCAL_Wait_TC(USART_typedef*USARTX)
{
	//Bit 6 TC: Transmission complete
	//	This bit is set by hardware if the transmission of a frame containing data is complete and if
	//	TXE is set. An interrupt is generated if TCIE=1 in the USART_CR1 register. It is cleared by a
	//	software sequence (a read from the USART_SR register followed by a write to the
	//	USART_DR register). The TC bit can also be cleared by writing a '0' to it. This clearing
	//	sequence is recommended only for multibuffer communication.
	//	0: Transmission is not complet
	while(!(USARTX->SR &1<<6));

}
/**================================================================
 * @Fn                   -MCAL_USART_Rescieve_Data
 * @brief                -Resived data
 * @param [in]           -USARTX where x can be (USARTX1 USARTX2 USART3)
 * @param [in]           -polling  is statue of enable or disable
 *  @param [in]          *Data  pointer to buffer that stor data resived
 * @retval               - null
 * Note                  -
 */
void MCAL_USART_Rescieve_Data(USART_typedef*USARTX ,uint16_t*Data,enum polling_mechism polling )
{
	USART_config * UART_Config = NULL;
		if      (USARTX == USART1) 		UART_Config = GL_USART_configs[0];
        else if	(USARTX == USART2) 		UART_Config = GL_USART_configs[1];
		else if	(USARTX == USART3) 		UART_Config = GL_USART_configs[2];
	if(polling==enable)
	{
		//		Bit 5 RXNE: Read data register not empty
		//		This bit is set by hardware when the content of the RDR shift register has been transferred to
		//		the USART_DR register. An interrupt is generated if RXNEIE=1 in the USART_CR1 register.
		//		It is cleared by a read to the USART_DR register. The RXNE flag can also be cleared by
		//		writing a zero to it. This clearing sequence is recommended only for multibuffer
		//		communication.
		//		0: Data is not received
		//		1: Received data is ready to be read
		while(!(USARTX->SR & 1<<5));
	}
	if(UART_Config->Data_size==Data_size_9)
	{
		if(UART_Config->Parity==none_parity)
		{
			*(( uint16_t *)Data) =USARTX->DR;
		}
		else
		{
			*(( uint16_t *)Data) =(USARTX->DR &(uint8_t)0xFF);
		}
	}
	else
	{
		if(UART_Config->Parity==none_parity)
		{
			*(( uint16_t*)Data) =(USARTX->DR & (uint8_t)0xFF);
		}
		else
		{
			*(( uint16_t *)Data) =(USARTX->DR &(uint8_t) 0x7F);
		}
	}

}

/**================================================================
 * @Fn                   -MCAL_GPIO_USART_Set_pins
 * @brief                -configuer the  GPIO pin to send and reseive
 * @param [in]           -USARTX where x can be (USARTX1 USARTX2 USART3)
 * @retval               - null
 * Note                  -null
 */
void MCAL_GPIO_USART_Set_pins(USART_typedef*USARTX)
{
	GPIO_pinconfig_t usart_config;
	if(USARTX==USART1)
	{
		 //Tx>>>>>>>>>>PA9
		 //Rx>>>>>>>>>>PA10
		 //CTS>>>>>>>>>PA11
         //RTS>>>>>>>>>PA12

		 //CK1>>>>>>>>>>PA8

		//TX
		usart_config.gpio_pin_number =GPIO_PIN_9;
		usart_config.GPIO_MODE= GPIO_MODE_OUTPUT_AF_PP;
		usart_config.GPIO_OUTPUT_SPEED=GPIO_SPEED_10MHZ;
		MCAL_GPIO_INIT(GPIOA , & usart_config);
		//RX
		usart_config.gpio_pin_number =GPIO_PIN_10;
		usart_config.GPIO_MODE= GPIO_MODE_INPUT_FLO;
		MCAL_GPIO_INIT(GPIOA , &usart_config);
		//CTS

		if(GL_USART_configs[0]->flow_control==flow_control_CTS_enable|| GL_USART_configs[0]->flow_control==flow_control_RTS_CTS_enable)
		{
		usart_config.gpio_pin_number =GPIO_PIN_11;
		usart_config.GPIO_MODE= GPIO_MODE_INPUT_FLO;
		MCAL_GPIO_INIT(GPIOA , &usart_config);
		}

		//RTS

		if(GL_USART_configs[0]->flow_control==flow_control_RTS_enable || GL_USART_configs[0]->flow_control==flow_control_RTS_CTS_enable)
		{
		usart_config.gpio_pin_number =GPIO_PIN_12;
		usart_config.GPIO_MODE= GPIO_MODE_OUTPUT_AF_PP;
		MCAL_GPIO_INIT(GPIOA , &usart_config);

	    }

	}
	else if(USARTX==USART2)
	{
		 //Tx>>>>>>>>>>PA2
		 //Rx>>>>>>>>>>PA3
		 //CTS>>>>>>>>>PA0
         //RTS>>>>>>>>>PA1

		 //CK1>>>>>>>>>>PA4

		//TX
		usart_config.gpio_pin_number =GPIO_PIN_2;
		usart_config.GPIO_MODE= GPIO_MODE_OUTPUT_AF_PP;
		usart_config.GPIO_OUTPUT_SPEED=GPIO_SPEED_10MHZ;
		MCAL_GPIO_INIT(GPIOA , &usart_config);
		//RX
		usart_config.gpio_pin_number =GPIO_PIN_3;
		usart_config.GPIO_MODE= GPIO_MODE_INPUT_FLO;
		MCAL_GPIO_INIT(GPIOA , &usart_config);

		//CTS
		if(GL_USART_configs[1]->flow_control==flow_control_CTS_enable||GL_USART_configs[1]->flow_control==flow_control_RTS_CTS_enable)
		{
		usart_config.gpio_pin_number =GPIO_PIN_0;
		usart_config.GPIO_MODE= GPIO_MODE_INPUT_FLO;
		MCAL_GPIO_INIT(GPIOA , &usart_config);
		}

		//RTS

		if(GL_USART_configs[1]->flow_control==flow_control_RTS_enable||GL_USART_configs[1]->flow_control==flow_control_RTS_CTS_enable)
		{
		usart_config.gpio_pin_number =GPIO_PIN_1;
		usart_config.GPIO_MODE= GPIO_MODE_OUTPUT_AF_PP;
		MCAL_GPIO_INIT(GPIOA , &usart_config);

	    }

	}

	else if(USARTX==USART3)

	{

		 //Tx>>>>>>>>>>PB10
		 //Rx>>>>>>>>>>PB11
		//CTS>>>>>>>>>>PB13
		//RTS>>>>>>>>>PA14

		//TX
		usart_config.gpio_pin_number =GPIO_PIN_10;
		usart_config.GPIO_MODE= GPIO_MODE_OUTPUT_AF_PP;
		usart_config.GPIO_OUTPUT_SPEED=GPIO_SPEED_10MHZ;
		MCAL_GPIO_INIT(GPIOB , &usart_config);

		//RX
		usart_config.gpio_pin_number =GPIO_PIN_11;
		usart_config.GPIO_MODE= GPIO_MODE_INPUT_FLO;
		MCAL_GPIO_INIT(GPIOB , & usart_config);

		//CTS
		if(GL_USART_configs[2]->flow_control==flow_control_CTS_enable||GL_USART_configs[2]->flow_control==flow_control_RTS_CTS_enable)
		{
		usart_config.gpio_pin_number =GPIO_PIN_13;
		usart_config.GPIO_MODE= GPIO_MODE_INPUT_FLO;
		MCAL_GPIO_INIT(GPIOB , &usart_config);
		}

		//RTS

		if(GL_USART_configs[2]->flow_control==flow_control_RTS_enable||GL_USART_configs[2]->flow_control==flow_control_RTS_CTS_enable)
		{
		usart_config.gpio_pin_number =GPIO_PIN_14;
		usart_config.GPIO_MODE= GPIO_MODE_OUTPUT_AF_PP;
		MCAL_GPIO_INIT(GPIOA , &usart_config);

	    }

	}
}

//ISR
void USART1_IRQHandler()
{
	GL_USART_configs[0]->P_IRQ_callback();

}

void USART2_IRQHandler()
{
	GL_USART_configs[1]->P_IRQ_callback();

}

void USART3_IRQHandler()
{
	GL_USART_configs[2]->P_IRQ_callback();

}








