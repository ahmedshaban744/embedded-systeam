/*
 * stm32f103c6_RCC_drivers.h
 *
 *  Created on: Aug 20, 2023
 *      Author: Ahmed Shaban
 */

#ifndef INC_STM32F103C6_RCC_DRIVERS_H_
#define INC_STM32F103C6_RCC_DRIVERS_H_
//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
//includes
//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
#include "stm32f103x6.h"

//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
//macros
//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
#define  HSI_clock  8000000   //the enternal OSC frequency
#define  HSE_clock 16000000  //enter value from 4MHZ >>>>>>>16MHZ
#define  PLL_clock 16000000

//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
// APIS Supported by "MCAL RCC  DRIVER"
//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
uint32_t MCAL_RCC_Get_Sys_clock     (void);
uint32_t MCAL_RCC_Get_HClock_clock  (void);
uint32_t MCAL_RCC_Get_PClock1_clock (void);
uint32_t MCAL_RCC_Get_PClock2_clock (void);

#endif /* INC_STM32F103C6_RCC_DRIVERS_H_ */
