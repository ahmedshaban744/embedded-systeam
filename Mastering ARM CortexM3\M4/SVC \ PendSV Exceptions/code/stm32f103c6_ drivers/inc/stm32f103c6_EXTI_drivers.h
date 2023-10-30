/*
 * stm32f103c6_ gpio_drivers.h
 *
 *  Created on:  6/8/2023
 *  Author: Ahmed shaban mohamed
 */

#ifndef INC_STM32F103C6_EXTI_DRIVERS_H_
#define INC_STM32F103C6_EXTI_DRIVERS_H_

//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
//includes
//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
#include "stm32f103x6.h"
#include "stm32f103c6_GPIO_drivers.h"
typedef struct
{
	uint16_t            EXTI_Line_Number;
	GPIO_pinconfig_t *  GPIO_port;
	uint16_t            GPIO_pin;
	uint8_t             IVT_IRQ_number;



}typedef_EXTI_GPIO_Maping_t;

typedef struct
{
	typedef_EXTI_GPIO_Maping_t EXIT_Pin;   	//specifice the external interrupt GPIO maping
                                         	//thies parameter must be set base on @EXIT_define
	uint8_t             trigger_case;      //specifice the external interrupt status
 	                                      //thies parameter must be set base on @EXIT_Trigger
	uint8_t            IRQ_define    ;   //enable and disable the EXTI IRQ
	                                    //thies parameter must be set base on @EXIT_IRQ_define
 void(*p_IRQ_Callback)(void);          //set the c_ funcation that will handle when IRQ IS handling
}EXIT_Confing_t;



//=================================================================================
//Macros Configuration References
//=================================================================================
#define EXTI0    0
#define EXTI1    1
#define EXTI2    2
#define EXTI3    3
#define EXTI4    4
#define EXTI5    5
#define EXTI6    6
#define EXTI7    7
#define EXTI8    8
#define EXTI9    9
#define EXTI10   10
#define EXTI11   11
#define EXTI12   12
#define EXTI13   13
#define EXTI14   14
#define EXTI15   15


//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
//Refrance Macro
//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-


//=====================================================================================
//@EXIT_define
//====================================================================================
//EXTI0
#define EXTI0A0        (typedef_EXTI_GPIO_Maping_t) {EXTI0, GPIOA, GPIO_PIN_0,  EXIT0_IRQ}
#define EXIT0B0        (typedef_EXTI_GPIO_Maping_t) {EXTI0, GPIOB, GPIO_PIN_0,  EXTI0_IRQ}
#define EXIT0C0        (typedef_EXTI_GPIO_Maping_t) {EXTI0, GPIOC, GPIO_PIN_0,  EXIT0_IRQ}
#define EXTI0D0        (typedef_EXTI_GPIO_Maping_t) {EXTI0, GPIOD, GPIO_PIN_0,  EXIT0_IRQ}


//EXTI1
#define EXTI1A1        (typedef_EXTI_GPIO_Maping_t) {EXTI1, GPIOA, GPIO_PIN_1,  EXIT1_IRQ}
#define EXTI1B1        (typedef_EXTI_GPIO_Maping_t) {EXTI1, GPIOB, GPIO_PIN_1,  EXIT1_IRQ}
#define EXTI1C1        (typedef_EXTI_GPIO_Maping_t) {EXTI1, GPIOC, GPIO_PIN_1,  EXIT1_IRQ}
#define EXTI1D1        (typedef_EXTI_GPIO_Maping_t) {EXTI1, GPIOD, GPIO_PIN_1,  EXIT1_IRQ}


//EXTI2
#define EXTI2A2        (typedef_EXTI_GPIO_Maping_t) {EXTI2, GPIOA, GPIO_PIN_2,  EXIT2_IRQ}
#define EXTI2B2        (typedef_EXTI_GPIO_Maping_t) {EXTI2, GPIOB, GPIO_PIN_2,  EXIT2_IRQ}
#define EXTI2C2        (typedef_EXTI_GPIO_Maping_t) {EXTI2, GPIOC, GPIO_PIN_2,  EXIT2_IRQ}
#define EXTI2D2        (typedef_EXTI_GPIO_Maping_t) {EXTI2, GPIOD, GPIO_PIN_2,  EXIT2_IRQ}


//EXTI3
#define EXTI3A3        (typedef_EXTI_GPIO_Maping_t) {EXTI3, GPIOA, GPIO_PIN_3,  EXIT3_IRQ}
#define EXTI3B3        (typedef_EXTI_GPIO_Maping_t) {EXTI3, GPIOB, GPIO_PIN_3,  EXIT3_IRQ}
#define EXTI3C3        (typedef_EXTI_GPIO_Maping_t) {EXTI3, GPIOC, GPIO_PIN_3,  EXIT3_IRQ}
#define EXTI3D3        (typedef_EXTI_GPIO_Maping_t) {EXTI3, GPIOD, GPIO_PIN3,  EXIT3_IRQ}


//EXTI4
#define EXTI4A4        (typedef_EXTI_GPIO_Maping_t) {EXTI4, GPIOA, GPIO_PIN_4,  EXIT4_IRQ}
#define EXTI4B4        (typedef_EXTI_GPIO_Maping_t) {EXTI4, GPIOB, GPIO_PIN_4,  EXIT4_IRQ}
#define EXTI4C4        (typedef_EXTI_GPIO_Maping_t) {EXTI4, GPIOC, GPIO_PIN_4,  EXIT4_IRQ}
#define EXTI4D4        (typedef_EXTI_GPIO_Maping_t) {EXTI4, GPIOD, GPIO_PIN_4,  EXIT4_IRQ}


//EXTI5
#define EXTI5A5        (typedef_EXTI_GPIO_Maping_t) {EXTI5, GPIOA, GPIO_PIN_5,  EXIT5_IRQ}
#define EXTI5B5        (typedef_EXTI_GPIO_Maping_t) {EXTI5, GPIOB, GPIO_PIN_5,  EXIT5_IRQ}
#define EXTI5C5        (typedef_EXTI_GPIO_Maping_t) {EXTI5, GPIOC, GPIO_PIN_5,  EXIT5_IRQ}
#define EXTI5D5        (typedef_EXTI_GPIO_Maping_t) {EXTI5, GPIOD, GPIO_PIN_5,  EXIT5_IRQ}


//EXTI6
#define EXTI6A6        (typedef_EXTI_GPIO_Maping_t) {EXTI6, GPIOA, GPIO_PIN_6,  EXIT6_IRQ}
#define EXTI6B6        (typedef_EXTI_GPIO_Maping_t) {EXTI6, GPIOB, GPIO_PIN_6,  EXIT6_IRQ}
#define EXTI6C6        (typedef_EXTI_GPIO_Maping_t) {EXTI6, GPIOC, GPIO_PIN_6,  EXIT6_IRQ}
#define EXTI6D6        (typedef_EXTI_GPIO_Maping_t) {EXTI6, GPIOD, GPIO_PIN_6,  EXIT6_IRQ}


//EXTI7
#define EXTI7A7        (typedef_EXTI_GPIO_Maping_t) {EXTI7, GPIOA, GPIO_PIN_7,  EXIT7_IRQ}
#define EXTI7B7        (typedef_EXTI_GPIO_Maping_t) {EXTI7, GPIOB, GPIO_PIN_7,  EXIT7_IRQ}
#define EXTI7C7        (typedef_EXTI_GPIO_Maping_t) {EXTI7, GPIOC, GPIO_PIN_7,  EXIT7_IRQ}
#define EXTI7D7        (typedef_EXTI_GPIO_Maping_t) {EXTI7, GPIOD, GPIO_PIN_7,  EXIT7_IRQ}


//EXTI8
#define EXTI8A8        (typedef_EXTI_GPIO_Maping_t) {EXTI8, GPIOA, GPIO_PIN_8,  EXIT8_IRQ}
#define EXTI8B8        (typedef_EXTI_GPIO_Maping_t) {EXTI8, GPIOB, GPIO_PIN_8,  EXIT8_IRQ}
#define EXTI8C8        (typedef_EXTI_GPIO_Maping_t) {EXTI8, GPIOC, GPIO_PIN_8,  EXIT8_IRQ}
#define EXTI8D8        (typedef_EXTI_GPIO_Maping_t) {EXTI8, GPIOD, GPIO_PIN_8,  EXIT8_IRQ}


//EXTI9
#define EXTI9A9         (typedef_EXTI_GPIO_Maping_t) {EXTI9, GPIOA, GPIO_PIN_9,  EXIT9_IRQ}
#define EXTI9B9         (typedef_EXTI_GPIO_Maping_t) {EXTI9, GPIOB, GPIO_PIN_9,  EXIT9_IRQ}
#define EXTI9C9         (typedef_EXTI_GPIO_Maping_t) {EXTI9, GPIOC, GPIO_PIN_9,  EXIT9_IRQ}
#define EXTI9D9         (typedef_EXTI_GPIO_Maping_t) {EXTI9, GPIOD, GPIO_PIN_9,  EXIT9_IRQ}


//EXTI10
#define EXTI10A10        (typedef_EXTI_GPIO_Maping_t) {EXTI10, GPIOA GPIO_PIN_10,  EXIT10_IRQ}
#define EXTI10B10        (typedef_EXTI_GPIO_Maping_t) {EXTI10, GPIOB, GPIO_PIN_10,  EXIT10_IRQ}
#define EXTI10C10        (typedef_EXTI_GPIO_Maping_t) {EXTI10, GPIOC, GPIO_PIN_10,  EXIT10_IRQ}
#define EXTI10D10        (typedef_EXTI_GPIO_Maping_t) {EXTI10, GPIOD, GPIO_PIN1_0,  EXIT10_IRQ}


//EXTI11
#define EXTI11A11        (typedef_EXTI_GPIO_Maping_t) {EXTI11, GPIOA, GPIO_PIN_11,  EXIT11_IRQ}
#define EXTI11B11        (typedef_EXTI_GPIO_Maping_t) {EXTI11, GPIOB, GPIO_PIN_11,  EXIT11_IRQ}
#define EXTI11C11        (typedef_EXTI_GPIO_Maping_t) {EXTI11, GPIOC, GPIO_PIN_11,  EXIT11_IRQ}
#define EXTI11D11        (typedef_EXTI_GPIO_Maping_t) {EXTI11, GPIOD, GPIO_PIN_11,  EXIT11_IRQ}


//EXTI12
#define EXTI12A12        (typedef_EXTI_GPIO_Maping_t) {EXTI12, GPIOA, GPIO_PIN_12,  EXIT12_IRQ}
#define EXTI12B12        (typedef_EXTI_GPIO_Maping_t) {EXTI12, GPIOB, GPIO_PIN_12,  EXIT12_IRQ}
#define EXTI12C12        (typedef_EXTI_GPIO_Maping_t) {EXTI12, GPIOC, GPIO_PIN_12,  EXIT12_IRQ}
#define EXTI12D12        (typedef_EXTI_GPIO_Maping_t) {EXTI12, GPIOD, GPIO_PIN_12,  EXIT12_IRQ}


//EXTI13
#define EXTI13A13        (typedef_EXTI_GPIO_Maping_t) {EXTI13, GPIOA, GPIO_PIN_13,  EXIT13_IRQ}
#define EXTI13B13        (typedef_EXTI_GPIO_Maping_t) {EXTI13, GPIOB, GPIO_PIN_13,  EXIT13_IRQ}
#define EXTI13C13        (typedef_EXTI_GPIO_Maping_t) {EXTI13, GPIOC, GPIO_PIN_13,  EXIT13_IRQ}
#define EXTI13D13        (typedef_EXTI_GPIO_Maping_t) {EXTI13, GPIOD, GPIO_PIN_13,  EXIT13_IRQ}


//EXTI14
#define EXTI14A14        (typedef_EXTI_GPIO_Maping_t) {EXTI14, GPIOA, GPIO_PIN_14,  EXIT14_IRQ}
#define EXTI14B14        (typedef_EXTI_GPIO_Maping_t) {EXTI14, GPIOB, GPIO_PIN_14,  EXIT14_IRQ}
#define EXTI14C14        (typedef_EXTI_GPIO_Maping_t) {EXTI14, GPIOC, GPIO_PIN_14,  EXIT14_IRQ}
#define EXTI14D14        (typedef_EXTI_GPIO_Maping_t) {EXTI14, GPIOD, GPIO_PIN_14,  EXIT14_IRQ}


//EXTI15
#define EXTI15A15        (typedef_EXTI_GPIO_Maping_t) {EXTI15, GPIOA, GPIO_PIN_15,  EXIT15_IRQ}
#define EXTI15B15        (typedef_EXTI_GPIO_Maping_t) {EXTI15, GPIOB, GPIO_PIN_15,  EXTI15_IRQ}
#define EXIT15C15        (typedef_EXTI_GPIO_Maping_t) {EXTI15, GPIOC, GPIO_PIN_15,  EXIT15_IRQ}
#define EXTI15D15        (typedef_EXTI_GPIO_Maping_t) {EXTI15, GPIOD, GPIO_PIN_15,  EXIT15_IRQ}


//EXTI16
#define EXTI16A16        (typedef_EXTI_GPIO_Maping_t) {EXTI16, GPIOA, GPIO_PIN_16,  EXIT16_IRQ}
#define EXTI16B16        (typedef_EXTI_GPIO_Maping_t) {EXTI16, GPIOB, GPIO_PIN_16,  EXIT16_IRQ}
#define EXIT16C16        (typedef_EXTI_GPIO_Maping_t) {EXTI16, GPIOC, GPIO_PIN_16,  EXTI16_IRQ}
#define EXIT16D16        (typedef_EXTI_GPIO_Maping_t) {EXTI16, GPIOD, GPIO_PIN_16,  EXIT16_IRQ}
//===========================================================================================================================

//=================================================================================
//@EXIT_Trigger
//================================================================================

#define EXIT_Rising                  0
#define EXIT_Falling                 1
#define EXIT_Falling_and_Rising      2

//=================================================================================
//@EXIT_IRQ_define
//================================================================================
#define EXIT_IRQ_disable             0
#define EXIT_IRQ_enable              1




//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
// APIS Supported by "MCAL EXTI  DRIVER"
//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
void MCAL_EXTI_GPIO_INIT(EXIT_Confing_t *EXTI_config);
void MCAL_EXTI_GPIO_UPDATE(EXIT_Confing_t *EXTI_config);
void MCAL_EXTI_GPIO_DEINIT();


#endif /* INC_STM32F103C6_EXTI_DRIVERS_H_ */
