/*
 * stm32f103x6.h
 *
 *  Created on: Jul 31, 2023
 *      Author: Ahmed shaban mohamed
 */

#ifndef INC_STM32F103X6_H_
#define INC_STM32F103X6_H_
//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
//Includes
//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
#include "stdlib.h"
#include "stdint.h"

//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
//Base addresses for Memories
//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-


#define SRAM_Base_address  							   0x20000000UL
#define flase_memory_Base_address  					   0x08000000UL
#define system_memory_Base_address  				   0x01FFFF000UL
#define pripherals_Base_address         		       0x40000000UL
#define cotex_M3_internal_pripherals_Base_address      0xE0000000UL
#define NVIC_base_address                              0xE000E100UL

//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
//Base addresses for AHB Peripherals
//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
#define RCC_base_address                         	   0x40021000UL
//======================================================================================

//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
//Base addresses for APB2 Peripherals
//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
//GPIO
//A,B fulled included in LQFP48 package
#define GPIOA_base_address                         	    0x40010800UL
#define GPIOB_base_address                         	    0x40010C00UL
//C,D partial included in LQFP48 package
#define GPIOC_base_address                         	    0x40011000UL
#define GPIOD_base_address                              0x40011400UL
//E NOT included in LQFP48 package
#define GPIOE_base_address                         	    0x40011800UL
//EXTI
#define EXII_base_address                         	    0x40010400UL
//AFIO
#define AFIO_base_address                         	    0x40010000UL
//USART1
#define USART1_Base                        	            0x40013800UL
//SPI1
#define  SPI1_Base_address                              0x40013000UL
//====================================================================================================
//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
//Base addresses for APB1 Peripherals
//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-

//USART1
#define USART2_Base                        	            0x40004400UL
//USART1
#define USART3_Base                        	            0x40004800UL
//SPI2
#define  SPI2_Base_address                              0x40003800UL
#define  I2C1_Base_address                              0x40005400UL
#define  I2C2_Base_address                              0x40005800UL
//====================================================================================
//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
//Peripheral register:
//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-

//=====================================================================================
//GPIO register:
//======================================================================================
typedef struct
{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;

}GPIO_typedef;

//======================================================================================
//RCC register:
//======================================================================================

typedef struct
{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
}RCC_typedef;

//======================================================================================
//EXTI register:
//======================================================================================

typedef struct
{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;

}EXTI_typedef;
//======================================================================================
//AFIO register:
//======================================================================================

typedef struct
{
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR[3];
	volatile uint32_t RESERVED;
	volatile uint32_t MAPR2;


}AFIO_typedef;

//======================================================================================
//NVIC register:
//======================================================================================
typedef struct
{
	volatile uint32_t ISER0;
	volatile uint32_t ISER1;
	volatile uint32_t ISER2;
	volatile uint32_t Reserved0:29;

	volatile uint32_t ICER0;
	volatile uint32_t ICER1;
	volatile uint32_t ICER2;
	volatile uint32_t Reserved1:29;

	volatile uint32_t ISPR0;
	volatile uint32_t ISPR1;
	volatile uint32_t ISPR2;
	volatile uint32_t Reserved2:29;

	volatile uint32_t ICPR0;
	volatile uint32_t ICPR1;
	volatile uint32_t ICPR2;
	volatile uint32_t Reserved3:29;

	volatile uint32_t IABR0;
	volatile uint32_t IABR1;
	volatile uint32_t IABR2;
	volatile uint64_t Reserved4:30;

	volatile uint32_t IPR0;
	volatile uint32_t Reserved5:7;
	volatile uint32_t IPR20;

	volatile uint64_t Reserved6: 60;
	volatile uint64_t Reserved7: 60;
	volatile uint64_t Reserved8: 60;
	volatile uint64_t Reserved9: 60;
	volatile uint64_t Reserved10:60;
	volatile uint64_t Reserved11:40;
	volatile uint32_t Reserved12:7;
	volatile uint32_t Reserved13:8;
	volatile uint32_t STIR;
}NVIC_typedef;

//anther way of of handling NVIV registers
#define  NVIC_ISER0 *(volatile uint32_t *)(NVIC_base_address+0x0)
#define  NVIC_ISER1 *(volatile uint32_t *)(NVIC_base_address+0X4)
#define  NVIC_ISER2 *(volatile uint32_t *)(NVIC_base_address+0X8)
#define  NVIC_ICER0 *(volatile uint32_t *)(NVIC_base_address+0X80)
#define  NVIC_ICER1 *(volatile uint32_t *)(NVIC_base_address+0X84)
#define  NVIC_ICER2 *(volatile uint32_t *)(NVIC_base_address+0X88)
//=====================================================================================
//USART register:
//======================================================================================
typedef struct
	{
		volatile uint32_t SR;
		volatile uint32_t DR;
		volatile uint32_t BRR;
		volatile uint32_t CR1;
		volatile uint32_t CR2;
		volatile uint32_t CR3;
		volatile uint32_t GTPR;


}USART_typedef;

//=====================================================================================
//SPI register:
//======================================================================================
typedef struct
{
	volatile uint32_t SPI_CR1;
	volatile uint32_t SPI_CR2;
	volatile uint32_t SPI_SR;
	volatile uint32_t SPI_DR;
	volatile uint32_t SPI_CRCPR;
	volatile uint32_t SPI_RXCRCR;
	volatile uint32_t SPI_TXCRCR;
	volatile uint32_t SPI_I2SCFGR;
	volatile uint32_t SPI_I2SPR;

}SPI_typedef;
//=====================================================================================
//I2C register:
//======================================================================================
typedef struct
{
	volatile uint32_t I2C_CR1;
	volatile uint32_t I2C_CR2;
	volatile uint32_t I2C_OAR1;
	volatile uint32_t I2C_OAR2;
	volatile uint32_t I2C_DR;
	volatile uint32_t I2C_SR1;
	volatile uint32_t I2C_SR2;
	volatile uint32_t I2C_CCR;
	volatile uint32_t I2C_TRISE;

}I2C_typedef;

//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
#define GPIOA            ((GPIO_typedef   *)GPIOA_base_address)
#define GPIOB            ((GPIO_typedef   *)GPIOB_base_address)
#define GPIOC            ((GPIO_typedef   *)GPIOC_base_address)
#define GPIOD            ((GPIO_typedef   *)GPIOD_base_address)
#define GPIOE            ((GPIO_typedef   *)GPIOE_base_address)
#define RCC              ((RCC_typedef    *) RCC_base_address )
#define EXTI             ((EXTI_typedef   *)EXII_base_address)
#define AFIO             ((AFIO_typedef   *) AFIO_base_address )
#define NVIC             ((NVIC_typedef   *) NVIC_base_address )
#define USART1           ((USART_typedef  *) USART1_Base )
#define USART2           ((USART_typedef  *) USART2_Base )
#define USART3           ((USART_typedef  *) USART3_Base )
#define  SPI1            ((SPI_typedef    *)SPI1_Base_address)
#define  SPI2            ((SPI_typedef    *)SPI2_Base_address)
#define  I2C1            ((I2C_typedef    *)I2C1_Base_address)
#define  I2C2            ((I2C_typedef    *)I2C2_Base_address)
//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
//clock enable/disable Macros:
//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
//AFIO
#define  AFIO_clock_enable()    (RCC->APB2ENR    |= 1<<0)
//GPIO
#define  GPIOA_clock_enable()   (RCC->APB2ENR    |= 1<<2)
#define  GPIOB_clock_enable()   (RCC->APB2ENR    |= 1<<3)
#define  GPIOC_clock_enable()   (RCC->APB2ENR    |= 1<<4)
#define  GPIOD_clock_enable()   (RCC->APB2ENR    |= 1<<5)
#define  GPIOE_clock_enable()   (RCC->APB2ENR    |= 1<<6)
//UART
#define  USART1_clock_enable()   (RCC->APB2ENR   |= 1<<14)
#define  USART2_clock_enable()   (RCC->APB1ENR   |= 1<<17)
#define  USART3_clock_enable()   (RCC->APB1ENR   |= 1<<18)
#define  USART1_clock_RESET()   (RCC->APB2RSTR  |= 1<<14)
#define  USART2_clock_RESET()   (RCC->APB1RSTR  |= 1<<17)
#define  USART3_clock_RESET()   (RCC->APB1RSTR  |= 1<<18)

//SPI
#define  SPI1_clock_enable()    (RCC->APB2ENR   |=1<<12)
#define  SPI2_clock_enable()    (RCC->APB1ENR   |=1<<14)
#define  SPI1_clock_RESET()    (RCC->APB2RSTR  |=1<<12)
#define  SPI2_clock_RESET()    (RCC->APB1RSTR  |=1<<14)

//I2C
#define  I2C1_clock_enable()    (RCC->APB1ENR   |=1<<21)
#define  I2C2_clock_enable()    (RCC->APB1ENR   |=1<<22)
#define  I2C1_clock_RESET()    (RCC->APB1RSTR  |=1<<21)
#define  I2C2_clock_RESET()    (RCC->APB1RSTR  |=1<<22)

//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
//NVIC enable and disable:
//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
//EXTI
#define NVIC_IRQ6_EXTI0_enable()                (NVIC_ISER0|=(1<<6))
#define NVIC_IRQ7_EXTI1_enable()                (NVIC_ISER0|=(1<<7))
#define NVIC_IRQ8_EXTI2_enable()                (NVIC_ISER0|=(1<<8))
#define NVIC_IRQ9_EXTI3_enable()                (NVIC_ISER0|=(1<<9))
#define NVIC_IRQ10_EXTI4_enable()               (NVIC_ISER0|=(1<<10))
#define NVIC_IRQ23_EXTI5_to_EXTI9_enable()      (NVIC_ISER0|=(1<<23))
#define NVIC_IRQ40_EXTI10_to_EXTI15_enable()    (NVIC_ISER1|=(1<<8))

#define NVIC_IRQ6_EXTI0_disable()               (NVIC_ICER0|=(1<<6))
#define NVIC_IRQ7_EXTI1_disable()               (NVIC_ICER0|=(1<<7))
#define NVIC_IRQ8_EXTI2_disable()               (NVIC_ICER0|=(1<<8))
#define NVIC_IRQ9_EXTI3_disable()               (NVIC_ICER0|=(1<<9))
#define NVIC_IRQ10_EXTI4_disable()              (NVIC_ICER0|=(1<<10))
#define NVIC_IRQ23_EXTI5_to_EXTI9_disable()     (NVIC_ICER0|=(1<<23))
#define NVIC_IRQ40_EXTI10_to_EXTI15_disable()   (NVIC_ICER1|=(1<<8))

//USART
#define NVIC_IRQ37_USART1_enable()                (NVIC_ISER1|=(1<<5))
#define NVIC_IRQ38_USART2_enable()                (NVIC_ISER1|=(1<<6))
#define NVIC_IRQ39_USART3_enable()                (NVIC_ISER1|=(1<<7))

#define NVIC_IRQ37_USART1_disable()                (NVIC_ICER1|=(1<<5))
#define NVIC_IRQ38_USART2_disable()                (NVIC_ICER1|=(1<<6))
#define NVIC_IRQ39_USART3_disable()                (NVIC_ICER1|=(1<<7))

//SPI
#define NVIC_IRQ37_SPI1_enable()                   (NVIC_ISER1|=(1<<3))
#define NVIC_IRQ38_SPI2_enable()                   (NVIC_ISER1|=(1<<4))

#define NVIC_IRQ37_SPI1_disable()                  (NVIC_ICER1|=(1<<3))
#define NVIC_IRQ38_SPI2_disable()                  (NVIC_ICER1|=(1<<4))

//I2C
#define NVIC_IRQ31_I2C1_EV_enable()                (NVIC_ISER0|=(1<<31))
#define NVIC_IRQ32_I2C1_ER_enable()                (NVIC_ISER1|=(1<<0) )
#define NVIC_IRQ33_I2C2_EV_enable()                (NVIC_ISER1|=(1<<1) )
#define NVIC_IRQ34_I2C2_ER_enable()                (NVIC_ISER1|=(1<<2))

#define NVIC_IRQ31_I2C1_EV_disable()                (NVIC_ICER0|=(1<<31))
#define NVIC_IRQ32_I2C1_ER_disable()                (NVIC_ICER1|=(1<<0))
#define NVIC_IRQ33_I2C2_EV_disable()                (NVIC_ICER1|=(1<<1))
#define NVIC_IRQ34_I2C2_ER_disable()                (NVIC_ICER1|=(1<<2))


//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
//Interrupt vectors Table (IVT)
//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
//EXIT

#define EXIT0_IRQ      6
#define EXIT1_IRQ      7
#define EXIT2_IRQ      8
#define EXIT3_IRQ      9
#define EXIT4_IRQ      10
#define EXIT5_IRQ      23
#define EXIT6_IRQ      23
#define EXIT7_IRQ      23
#define EXIT8_IRQ      23
#define EXIT9_IRQ      23
#define EXIT10_IRQ     40
#define EXIT11_IRQ     40
#define EXIT12_IRQ     40
#define EXIT13_IRQ     40
#define EXIT14_IRQ     40
#define EXIT15_IRQ     40

//USART
#define USART1_IRQ      37
#define USART2_IRQ      38
#define USART3_IRQ      39
//SPI
#define SPI1_IRQ        35
#define SPI2_IRQ        36

//I2C
#define I2C1_EV         31
#define I2C1_ER         32
#define I2C2_EV         33
#define I2C2_ER         34




/********************************************************/
/********************************************************/
/********************************************************/
/*******************  Bit definition  ********************/
/********************************************************/
/********************************************************/



/*******************  Bit definition for I2C_CR1 register  ********************/
#define I2C_CR1_PE_Pos                      (0U)
#define I2C_CR1_PE_Msk                      (0x1UL << I2C_CR1_PE_Pos)           /*!< 0x00000001 */
#define I2C_CR1_PE                          I2C_CR1_PE_Msk                     /*!< Peripheral Enable */
#define I2C_CR1_SMBUS_Pos                   (1U)
#define I2C_CR1_SMBUS_Msk                   (0x1UL << I2C_CR1_SMBUS_Pos)        /*!< 0x00000002 */
#define I2C_CR1_SMBUS                       I2C_CR1_SMBUS_Msk                  /*!< SMBus Mode */
#define I2C_CR1_SMBTYPE_Pos                 (3U)
#define I2C_CR1_SMBTYPE_Msk                 (0x1UL << I2C_CR1_SMBTYPE_Pos)      /*!< 0x00000008 */
#define I2C_CR1_SMBTYPE                     I2C_CR1_SMBTYPE_Msk                /*!< SMBus Type */
#define I2C_CR1_ENARP_Pos                   (4U)
#define I2C_CR1_ENARP_Msk                   (0x1UL << I2C_CR1_ENARP_Pos)        /*!< 0x00000010 */
#define I2C_CR1_ENARP                       I2C_CR1_ENARP_Msk                  /*!< ARP Enable */
#define I2C_CR1_ENPEC_Pos                   (5U)
#define I2C_CR1_ENPEC_Msk                   (0x1UL << I2C_CR1_ENPEC_Pos)        /*!< 0x00000020 */
#define I2C_CR1_ENPEC                       I2C_CR1_ENPEC_Msk                  /*!< PEC Enable */
#define I2C_CR1_ENGC_Pos                    (6U)
#define I2C_CR1_ENGC_Msk                    (0x1UL << I2C_CR1_ENGC_Pos)         /*!< 0x00000040 */
#define I2C_CR1_ENGC                        I2C_CR1_ENGC_Msk                   /*!< General Call Enable */
#define I2C_CR1_NOSTRETCH_Pos               (7U)
#define I2C_CR1_NOSTRETCH_Msk               (0x1UL << I2C_CR1_NOSTRETCH_Pos)    /*!< 0x00000080 */
#define I2C_CR1_NOSTRETCH                   I2C_CR1_NOSTRETCH_Msk              /*!< Clock Stretching Disable (Slave mode) */
#define I2C_CR1_START_Pos                   (8U)
#define I2C_CR1_START_Msk                   (0x1UL << I2C_CR1_START_Pos)        /*!< 0x00000100 */
#define I2C_CR1_START                       I2C_CR1_START_Msk                  /*!< Start Generation */
#define I2C_CR1_STOP_Pos                    (9U)
#define I2C_CR1_STOP_Msk                    (0x1UL << I2C_CR1_STOP_Pos)         /*!< 0x00000200 */
#define I2C_CR1_STOP                        I2C_CR1_STOP_Msk                   /*!< Stop Generation */
#define I2C_CR1_ACK_Pos                     (10U)
#define I2C_CR1_ACK_Msk                     (0x1UL << I2C_CR1_ACK_Pos)          /*!< 0x00000400 */
#define I2C_CR1_ACK                         I2C_CR1_ACK_Msk                    /*!< Acknowledge Enable */
#define I2C_CR1_POS_Pos                     (11U)
#define I2C_CR1_POS_Msk                     (0x1UL << I2C_CR1_POS_Pos)          /*!< 0x00000800 */
#define I2C_CR1_POS                         I2C_CR1_POS_Msk                    /*!< Acknowledge/PEC Position (for data reception) */
#define I2C_CR1_PEC_Pos                     (12U)
#define I2C_CR1_PEC_Msk                     (0x1UL << I2C_CR1_PEC_Pos)          /*!< 0x00001000 */
#define I2C_CR1_PEC                         I2C_CR1_PEC_Msk                    /*!< Packet Error Checking */
#define I2C_CR1_ALERT_Pos                   (13U)
#define I2C_CR1_ALERT_Msk                   (0x1UL << I2C_CR1_ALERT_Pos)        /*!< 0x00002000 */
#define I2C_CR1_ALERT                       I2C_CR1_ALERT_Msk                  /*!< SMBus Alert */
#define I2C_CR1_SWRST_Pos                   (15U)
#define I2C_CR1_SWRST_Msk                   (0x1UL << I2C_CR1_SWRST_Pos)        /*!< 0x00008000 */
#define I2C_CR1_SWRST                       I2C_CR1_SWRST_Msk                  /*!< Software Reset */
/*******************  Bit definition for I2C_CR2 register  ********************/
#define I2C_CR2_FREQ_Pos                    (0U)
#define I2C_CR2_FREQ_Msk                    (0x3FUL << I2C_CR2_FREQ_Pos)        /*!< 0x0000003F */
#define I2C_CR2_FREQ                        I2C_CR2_FREQ_Msk                   /*!< FREQ[5:0] bits (Peripheral Clock Frequency) */
#define I2C_CR2_ITERREN_Pos                 (8U)
#define I2C_CR2_ITERREN_Msk                 (0x1UL << I2C_CR2_ITERREN_Pos)      /*!< 0x00000100 */
#define I2C_CR2_ITERREN                     I2C_CR2_ITERREN_Msk                /*!< Error Interrupt Enable */
#define I2C_CR2_ITEVTEN_Pos                 (9U)
#define I2C_CR2_ITEVTEN_Msk                 (0x1UL << I2C_CR2_ITEVTEN_Pos)      /*!< 0x00000200 */
#define I2C_CR2_ITEVTEN                     I2C_CR2_ITEVTEN_Msk                /*!< Event Interrupt Enable */
#define I2C_CR2_ITBUFEN_Pos                 (10U)
#define I2C_CR2_ITBUFEN_Msk                 (0x1UL << I2C_CR2_ITBUFEN_Pos)      /*!< 0x00000400 */
#define I2C_CR2_ITBUFEN                     I2C_CR2_ITBUFEN_Msk                /*!< Buffer Interrupt Enable */
#define I2C_CR2_DMAEN_Pos                   (11U)
#define I2C_CR2_DMAEN_Msk                   (0x1UL << I2C_CR2_DMAEN_Pos)        /*!< 0x00000800 */
#define I2C_CR2_DMAEN                       I2C_CR2_DMAEN_Msk                  /*!< DMA Requests Enable */
#define I2C_CR2_LAST_Pos                    (12U)
#define I2C_CR2_LAST_Msk                    (0x1UL << I2C_CR2_LAST_Pos)         /*!< 0x00001000 */
#define I2C_CR2_LAST                        I2C_CR2_LAST_Msk                   /*!< DMA Last Transfer */
/*******************  Bit definition for I2C_OAR2 register  *******************/
#define I2C_OAR2_ENDUAL_Pos                 (0U)
#define I2C_OAR2_ENDUAL_Msk                 (0x1UL << I2C_OAR2_ENDUAL_Pos)      /*!< 0x00000001 */
#define I2C_OAR2_ENDUAL                     I2C_OAR2_ENDUAL_Msk                /*!< Dual addressing mode enable */
#define I2C_OAR2_ADD2_Pos                   (1U)
/*******************  Bit definition for I2C_SR1 register  ********************/
#define I2C_SR1_SB_Pos                      (0U)
#define I2C_SR1_SB_Msk                      (0x1UL << I2C_SR1_SB_Pos)           /*!< 0x00000001 */
#define I2C_SR1_SB                          I2C_SR1_SB_Msk                     /*!< Start Bit (Master mode) */
#define I2C_SR1_ADDR_Pos                    (1U)
#define I2C_SR1_ADDR_Msk                    (0x1UL << I2C_SR1_ADDR_Pos)         /*!< 0x00000002 */
#define I2C_SR1_ADDR                        I2C_SR1_ADDR_Msk                   /*!< Address sent (master mode)/matched (slave mode) */
#define I2C_SR1_BTF_Pos                     (2U)
#define I2C_SR1_BTF_Msk                     (0x1UL << I2C_SR1_BTF_Pos)          /*!< 0x00000004 */
#define I2C_SR1_BTF                         I2C_SR1_BTF_Msk                    /*!< Byte Transfer Finished */
#define I2C_SR1_ADD10_Pos                   (3U)
#define I2C_SR1_ADD10_Msk                   (0x1UL << I2C_SR1_ADD10_Pos)        /*!< 0x00000008 */
#define I2C_SR1_ADD10                       I2C_SR1_ADD10_Msk                  /*!< 10-bit header sent (Master mode) */
#define I2C_SR1_STOPF_Pos                   (4U)
#define I2C_SR1_STOPF_Msk                   (0x1UL << I2C_SR1_STOPF_Pos)        /*!< 0x00000010 */
#define I2C_SR1_STOPF                       I2C_SR1_STOPF_Msk                  /*!< Stop detection (Slave mode) */
#define I2C_SR1_RXNE_Pos                    (6U)
#define I2C_SR1_RXNE_Msk                    (0x1UL << I2C_SR1_RXNE_Pos)         /*!< 0x00000040 */
#define I2C_SR1_RXNE                        I2C_SR1_RXNE_Msk                   /*!< Data Register not Empty (receivers) */
#define I2C_SR1_TXE_Pos                     (7U)
#define I2C_SR1_TXE_Msk                     (0x1UL << I2C_SR1_TXE_Pos)          /*!< 0x00000080 */
#define I2C_SR1_TXE                         I2C_SR1_TXE_Msk                    /*!< Data Register Empty (transmitters) */
#define I2C_SR1_BERR_Pos                    (8U)
#define I2C_SR1_BERR_Msk                    (0x1UL << I2C_SR1_BERR_Pos)         /*!< 0x00000100 */
#define I2C_SR1_BERR                        I2C_SR1_BERR_Msk                   /*!< Bus Error */
#define I2C_SR1_ARLO_Pos                    (9U)
#define I2C_SR1_ARLO_Msk                    (0x1UL << I2C_SR1_ARLO_Pos)         /*!< 0x00000200 */
#define I2C_SR1_ARLO                        I2C_SR1_ARLO_Msk                   /*!< Arbitration Lost (master mode) */
#define I2C_SR1_AF_Pos                      (10U)
#define I2C_SR1_AF_Msk                      (0x1UL << I2C_SR1_AF_Pos)           /*!< 0x00000400 */
#define I2C_SR1_AF                          I2C_SR1_AF_Msk                     /*!< Acknowledge Failure */
#define I2C_SR1_OVR_Pos                     (11U)
#define I2C_SR1_OVR_Msk                     (0x1UL << I2C_SR1_OVR_Pos)          /*!< 0x00000800 */
#define I2C_SR1_OVR                         I2C_SR1_OVR_Msk                    /*!< Overrun/Underrun */
#define I2C_SR1_PECERR_Pos                  (12U)
#define I2C_SR1_PECERR_Msk                  (0x1UL << I2C_SR1_PECERR_Pos)       /*!< 0x00001000 */
#define I2C_SR1_PECERR                      I2C_SR1_PECERR_Msk                 /*!< PEC Error in reception */
#define I2C_SR1_TIMEOUT_Pos                 (14U)
#define I2C_SR1_TIMEOUT_Msk                 (0x1UL << I2C_SR1_TIMEOUT_Pos)      /*!< 0x00004000 */
#define I2C_SR1_TIMEOUT                     I2C_SR1_TIMEOUT_Msk                /*!< Timeout or Tlow Error */
#define I2C_SR1_SMBALERT_Pos                (15U)
#define I2C_SR1_SMBALERT_Msk                (0x1UL << I2C_SR1_SMBALERT_Pos)     /*!< 0x00008000 */
#define I2C_SR1_SMBALERT                    I2C_SR1_SMBALERT_Msk               /*!< SMBus Alert */

/*******************  Bit definition for I2C_SR2 register  ********************/
#define I2C_SR2_MSL_Pos                     (0U)
#define I2C_SR2_MSL_Msk                     (0x1UL << I2C_SR2_MSL_Pos)          /*!< 0x00000001 */
#define I2C_SR2_MSL                         I2C_SR2_MSL_Msk                    /*!< Master/Slave */
#define I2C_SR2_BUSY_Pos                    (1U)
#define I2C_SR2_BUSY_Msk                    (0x1UL << I2C_SR2_BUSY_Pos)         /*!< 0x00000002 */
#define I2C_SR2_BUSY                        I2C_SR2_BUSY_Msk                   /*!< Bus Busy */
#define I2C_SR2_TRA_Pos                     (2U)
#define I2C_SR2_TRA_Msk                     (0x1UL << I2C_SR2_TRA_Pos)          /*!< 0x00000004 */
#define I2C_SR2_TRA                         I2C_SR2_TRA_Msk                    /*!< Transmitter/Receiver */
#define I2C_SR2_GENCALL_Pos                 (4U)
#define I2C_SR2_GENCALL_Msk                 (0x1UL << I2C_SR2_GENCALL_Pos)      /*!< 0x00000010 */
#define I2C_SR2_GENCALL                     I2C_SR2_GENCALL_Msk                /*!< General Call Address (Slave mode) */
#define I2C_SR2_SMBDEFAULT_Pos              (5U)
#define I2C_SR2_SMBDEFAULT_Msk              (0x1UL << I2C_SR2_SMBDEFAULT_Pos)   /*!< 0x00000020 */
#define I2C_SR2_SMBDEFAULT                  I2C_SR2_SMBDEFAULT_Msk             /*!< SMBus Device Default Address (Slave mode) */
#define I2C_SR2_SMBHOST_Pos                 (6U)
#define I2C_SR2_SMBHOST_Msk                 (0x1UL << I2C_SR2_SMBHOST_Pos)      /*!< 0x00000040 */
#define I2C_SR2_SMBHOST                     I2C_SR2_SMBHOST_Msk                /*!< SMBus Host Header (Slave mode) */
#define I2C_SR2_DUALF_Pos                   (7U)
#define I2C_SR2_DUALF_Msk                   (0x1UL << I2C_SR2_DUALF_Pos)        /*!< 0x00000080 */
#define I2C_SR2_DUALF                       I2C_SR2_DUALF_Msk                  /*!< Dual Flag (Slave mode) */
#define I2C_SR2_PEC_Pos                     (8U)
#define I2C_SR2_PEC_Msk                     (0xFFUL << I2C_SR2_PEC_Pos)         /*!< 0x0000FF00 */
#define I2C_SR2_PEC                         I2C_SR2_PEC_Msk                    /*!< Packet Error Checking Register */
/*******************  Bit definition for I2C_OAR1 register  ********************/
#define I2C_OAR1_ADDMODE_Pos                     (15U)
#define I2C_OAR1_ADDMODE_Msk                     (0x1UL << I2C_OAR1_ADDMODE_Pos)          /*!< 0x00000001 */
#define I2C_OAR1_ADDMODE                         I2C_OAR1_ADDMODE_Msk                    /*!< Master/Slave */

#endif /* INC_STM32F103X6_H_ */
