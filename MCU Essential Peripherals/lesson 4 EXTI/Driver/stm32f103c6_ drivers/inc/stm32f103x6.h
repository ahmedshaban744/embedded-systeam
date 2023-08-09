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

//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
//Base addresses for APB2 Peripherals
//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
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
#define EXII_base_address                         	   0x40010400UL
//AFIO
#define AFIO_base_address                         	   0x40010000UL
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

	volatile uint64_t Reserved6:60;
	volatile uint64_t Reserved7:60;
	volatile uint64_t Reserved8:60;
	volatile uint64_t Reserved9:60;
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
#define  NVIC_ICPR0 *(volatile uint32_t *)(NVIC_base_address+0X80)
#define  NVIC_ICPR1 *(volatile uint32_t *)(NVIC_base_address+0X84)
#define  NVIC_ICPR2 *(volatile uint32_t *)(NVIC_base_address+0X88)

//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
#define GPIOA          ((GPIO_typedef *)GPIOA_base_address)
#define GPIOB          ((GPIO_typedef *)GPIOB_base_address)
#define GPIOC          ((GPIO_typedef *)GPIOC_base_address)
#define GPIOD          ((GPIO_typedef *)GPIOD_base_address)
#define GPIOE          ((GPIO_typedef *)GPIOE_base_address)
#define RCC            ((RCC_typedef  *) RCC_base_address )
#define EXTI           ((EXTI_typedef *)EXII_base_address)
#define AFIO           ((AFIO_typedef *) AFIO_base_address )
#define NVIC           ((NVIC_typedef *) NVIC_base_address )

//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
#define  AFIO_clock_enable()    (RCC->APB2ENR |= 1<<0)
#define  GPIOA_clock_enable()   (RCC->APB2ENR |= 1<<2)
#define  GPIOB_clock_enable()   (RCC->APB2ENR |= 1<<3)
#define  GPIOC_clock_enable()   (RCC->APB2ENR |= 1<<4)
#define  GPIOD_clock_enable()   (RCC->APB2ENR |= 1<<5)
#define  GPIOE_clock_enable()   (RCC->APB2ENR |= 1<<6)

//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
//NVIC enable and disable:
//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
#define NVIC_IRQ6_EXTI0_enable()                (NVIC_ISER0|=(1<<6))
#define NVIC_IRQ7_EXTI1_enable()                (NVIC_ISER0|=(1<<7))
#define NVIC_IRQ8_EXTI2_enable()                (NVIC_ISER0|=(1<<8))
#define NVIC_IRQ9_EXTI3_enable()                (NVIC_ISER0|=(1<<9))
#define NVIC_IRQ10_EXTI4_enable()               (NVIC_ISER0|=(1<<10))
#define NVIC_IRQ23_EXTI5_to_EXTI9_enable()      (NVIC_ISER0|=(1<<23))
#define NVIC_IRQ40_EXTI10_to_EXTI15_enable()    (NVIC_ISER1|=(1<<8))

#define NVIC_IRQ6_EXTI0_disable()               (NVIC_ICPR0|=(1<<6))
#define NVIC_IRQ7_EXTI1_disable()               (NVIC_ICPR0|=(1<<7))
#define NVIC_IRQ8_EXTI2_disable()               (NVIC_ICPR0|=(1<<8))
#define NVIC_IRQ9_EXTI3_disable()               (NVIC_ICPR0|=(1<<9))
#define NVIC_IRQ10_EXTI4_disable()              (NVIC_ICPR0|=(1<<10))
#define NVIC_IRQ23_EXTI5_to_EXTI9_disable()     (NVIC_ICPR0|=(1<<23))
#define NVIC_IRQ40_EXTI10_to_EXTI15_disable()   (NVIC_ICPR1|=(1<<8))



//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
//Interrupt vectors Table (IVT)
//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
//EXIT

#define EXIT0_IRQ   6
#define EXIT1_IRQ   7
#define EXIT2_IRQ   8
#define EXIT3_IRQ   9
#define EXIT4_IRQ   10
#define EXIT5_IRQ   23
#define EXIT6_IRQ   23
#define EXIT7_IRQ   23
#define EXIT8_IRQ   23
#define EXIT9_IRQ   23
#define EXIT10_IRQ  40
#define EXIT11_IRQ  40
#define EXIT12_IRQ  40
#define EXIT13_IRQ  40
#define EXIT14_IRQ  40
#define EXIT15_IRQ  40




#endif /* INC_STM32F103X6_H_ */
