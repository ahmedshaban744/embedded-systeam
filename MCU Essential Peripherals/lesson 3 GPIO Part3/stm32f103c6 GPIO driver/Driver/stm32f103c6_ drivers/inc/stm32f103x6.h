/*
 * stm32f103x6.h
 *
 *  Created on: Jul 31, 2023
 *      Author: Ahmed shaban mohamed
 */

#ifndef INC_STM32F103X6_H_
#define INC_STM32F103X6_H_
//-----------------------------
//Includes
//-----------------------------
#include "stdlib.h"
#include "stdint.h"

//-----------------------------
//Base addresses for Memories
//-----------------------------
#define SRAM_Base_address  							   0x20000000UL
#define flase_memory_Base_address  					   0x08000000UL
#define system_memory_Base_address  				   0x01FFFF000UL
#define pripherals_Base_address         		       0x40000000UL
#define cotex_M3_internal_pripherals_Base_address      0xE0000000UL

//-----------------------------
//Base addresses for AHB Peripherals
//-----------------------------
#define RCC_base_address                         	   0x40021000UL
//#define RCC_base_address                         	   (pripherals_Base_address+0x00021000UL)

//-----------------------------
//Base addresses for APB2 Peripherals
//-----------------------------
//GPIO
//A,B fulled included in LQFP48 package
#define GPIOA_base_address                         	   0x40010800UL
#define GPIOB_base_address                         	   0x40010C00UL
//C,D partial included in LQFP48 package
#define GPIOC_base_address                         	   0x40011000UL
#define GPIOD_base_address                         	   0x40011400UL
//E NOT included in LQFP48 package
#define GPIOE_base_address                         	   0x40011800UL
//EXTI
#define EXTI_base_address                         	   0x40010400UL
//AFIO
#define AFIO_base_address                         	   0x40010000UL
//====================================================================================
//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:
//-*-*-*-*-*-*-*-*-*-*-*

//-*-*-*-*-*-*-*-*-*-*-*-
//GPIO register:
//-*-*-*-*-*-*-*-*-*-*-*
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

//-*-*-*-*-*-*-*-*-*-*-*-
//RCC register:
//-*-*-*-*-*-*-*-*-*-*-*

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

//-*-*-*-*-*-*-*-*-*-*-*-
//EXTI register:
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct
{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;

}EXTI_typedef;
//-*-*-*-*-*-*-*-*-*-*-*-
//AFIO register:
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct
{
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR1;
	volatile uint32_t EXTICR2;
	volatile uint32_t EXTICR3;
	volatile uint32_t EXTICR4;
	volatile uint32_t RESERVED;
	volatile uint32_t MAPR2;


}AFIO_typedef;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*
#define GPIOA          ((GPIO_typedef*)GPIOA_base_address)
#define GPIOB          ((GPIO_typedef*)GPIOB_base_address)
#define GPIOC          ((GPIO_typedef*)GPIOC_base_address)
#define GPIOD          ((GPIO_typedef*)GPIOD_base_address)
#define GPIOE          ((GPIO_typedef*)GPIOE_base_address)
#define RCC            ((RCC_typedef*) RCC_base_address )
#define EXTI           ((EXTI_typedef*)EXII_base_address)
#define AFIO           ((AFIO_typedef*) AFIO_base_address )


//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*
#define  AFIO_clock_enable()    (RCC->APB2ENR |= 1<<0)
#define  GPIOA_clock_enable()   (RCC->APB2ENR |= 1<<2)
#define  GPIOB_clock_enable()   (RCC->APB2ENR |= 1<<3)
#define  GPIOC_clock_enable()   (RCC->APB2ENR |= 1<<4)
#define  GPIOD_clock_enable()   (RCC->APB2ENR |= 1<<5)
#define  GPIOE_clock_enable()   (RCC->APB2ENR |= 1<<6)





#endif /* INC_STM32F103X6_H_ */
