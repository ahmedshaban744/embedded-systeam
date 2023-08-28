/*
 * stm32f103c6_USART_drivers.h
 *
 *  Created on: Aug 20, 2023
 *   Author: Ahmed Shaban
 */

#ifndef INC_STM32F103C6_USART_DRIVERS_H_
#define INC_STM32F103C6_USART_DRIVERS_H_

#include "stm32f103c6_GPIO_drivers.h"
#include "stm32f103c6_RCC_drivers.h"
#include "stm32f103x6.h"
#include <stdint.h>

typedef struct
{
	uint8_t   mode_enable 	 ;       //that parameter set base on refrans @USART_mode_config
	uint32_t  BoudRate       ;      //that parameter set base on refrans  @USART_BoudRate_config
	uint8_t  Data_size       ;     //that parameter set base on refrans   @USART_data_size_config
	uint8_t  Parity          ;    //that parameter set base on refrans    @USART_Parity_config
	uint8_t  stop_bit        ;   //that parameter set base on refrans     @USART_Stop_bit_config
	uint8_t  flow_control    ;  //that parameter set base on refrans      @USART_flow_control_config
	uint8_t  IRq_enable      ; //that parameter set base on refrans       @USART_IRq_enable_config
	void (*P_IRQ_callback)(void)  ;

}USART_config;






#endif /* INC_STM32F103C6_USART_DRIVERS_H_ */
//===========================================================================
//=================================macros====================================
//===========================================================================

//@USART_mode_config
#define USART_TX_enable       (uint32_t)(1<<3)
#define USART_RX_enable       (uint32_t)(1<<2)
#define USART_TX_RX_enable   ((uint32_t)(1<<2|1<<3))

// @USART_BoudRate_config
#define  USART_BaudRate_2400Kbps           2400
#define  USART_BaudRate_9600Kbps           9600
#define  USART_BaudRate_19200Kbps          19200
#define  USART_BaudRate_57600Kbps          57600
#define  USART_BaudRate_115200Kbps        115200
#define  USART_BaudRate_230400Kbps         230400
#define  USART_BaudRate_460800Kbps         460800
#define  USART_BaudRate_921600Kbps         921600
#define  USART_BaudRate_2250000Kbps        2250000
#define  USART_BaudRate_4500Kbps           4500000

//@USART_data_size_config
#define Data_size_8                    (uint32_t)(0)
#define Data_size_9                    (uint32_t)(1<<12)

//@USART_Parity_config
#define none_parity                   (uint32_t)(0)
#define even_parity                   (uint32_t)(1<<10)
#define odd_parity                    ((uint32_t)(1<<10|1<<9))

//@USART_Stop_bit_config
#define stop_bit_one                     (uint32_t)(0)
#define stop_bit_half                    (uint32_t)(1<<12 )     // (uint32_t)(0b01<<12 & 0b11)
#define stop_bit_one_and_half            (uint32_t)(3<<12 )     //  (uint32_t)(0b10<<12 & 0b11)
#define stop_bit_two                     (uint32_t)(2<<12 )    // (uint32_t)(0b11<<12 & 0b11)

//USART_flow_control_config
#define flow_control_CTS_enable        (uint32_t)(1<<9)
#define flow_control_RTS_enable        (uint32_t)(1<<8)
#define flow_control_RTS_CTS_enable    ((uint32_t)(1<<8|1<<9))
#define none_flow_control              (uint32_t)(0)
// @USART_IRq_enable_config
#define USART_IRQ_enable_none              (uint32_t)(0)       //none
#define USART_IRQ_enable_TXE               (uint32_t)(1<<7)    //tensemet data register empty
#define USART_IRQ_enable_TC                (uint32_t)(1<<6)   //trnasiming compelet
#define USART_IRQ_enable_RXNE             (uint32_t)(1<<5)   //Received data ready to be read
#define USART_IRQ_enable_PE                (uint32_t)(1<<8)  //parrity error
#define USART_IRQ_enable_CTS               (uint32_t)(1<<10)  //CTS flag


//BaudRate Calculation
//USARTDIV = fclk / (16 * Baudrate)
//USARTDIV_MUL100 =
// uint32((100 *fclk ) / (16 * Baudrate) == (25 *fclk ) / (4* Baudrate) )
//DIV_Mantissa_MUL100 = Integer Part (USARTDIV  )  * 100
//DIV_Mantissa = Integer Part (USARTDIV  )
//DIV_Fraction = (( USARTDIV_MUL100  - DIV_Mantissa_MUL100  ) * 16 ) / 100

#define USARTDIV(_PCLK_, _BAUD_)							(uint32_t) (_PCLK_/(16 * _BAUD_ ))
#define USARTDIV_MUL100(_PCLK_, _BAUD_)						(uint32_t) ( (25 * _PCLK_ ) / (4  * _BAUD_ ))
#define Mantissa_MUL100(_PCLK_, _BAUD_)						(uint32_t) (USARTDIV(_PCLK_, _BAUD_) * 100)
#define Mantissa(_PCLK_, _BAUD_)							(uint32_t) (USARTDIV(_PCLK_, _BAUD_) )
#define DIV_Fraction(_PCLK_, _BAUD_)						(uint32_t) (((USARTDIV_MUL100(_PCLK_, _BAUD_) -  Mantissa_MUL100(_PCLK_, _BAUD_) ) * 16 ) / 100 )
#define UART_BRR_Register(_PCLK_, _BAUD_)					(( Mantissa (_PCLK_, _BAUD_) ) <<4 )|( (DIV_Fraction(_PCLK_, _BAUD_)) & 0xF )








enum USART_IRQ_event
{

	USART_IRQ_TXE  ,
	USART_IRQ_TC   ,
	USART_IRQ_RXNE ,
	USART_IRQ_ORE  ,
	USART_IRQPE_   ,
};
void *P_IRQ_callback(enum USART_IRQ_event flag );
enum polling_mechism
{enable ,
disable
};
//============================================================================================
//===================================================APIS=====================================
//============================================================================================
void MCAL_USART_Send_Data(USART_typedef*USARTX    ,   uint16_t*Data     ,   enum polling_mechism  polling );
void MCAL_USART_Rescieve_Data(USART_typedef*USARTX ,   uint16_t*Data   ,   enum polling_mechism polling );
void MCAL_USART_Init(USART_typedef*USARTX   ,    USART_config*USART_defin);
void MCAL_GPIO_USART_Set_pins(USART_typedef*USARTX);
void MCAL_USART_DEInit(USART_typedef*USARTX);
void MCAL_Wait_TC(USART_typedef*USARTX);
