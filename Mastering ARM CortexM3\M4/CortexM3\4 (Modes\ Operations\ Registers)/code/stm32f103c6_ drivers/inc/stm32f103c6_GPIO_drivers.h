/*
 * stm32f103c6_ gpio_drivers.h
 *
 *  Created on:  6/8/2023
 *  Author: Ahmed shaban mohamed
 */

#ifndef INC_STM32F103C6_GPIO_DRIVERS_H_
#define INC_STM32F103C6_GPIO_DRIVERS_H_
//---------------------------
//includes
//----------------------------
#include "stm32f103x6.h"

typedef struct {
	uint16_t gpio_pin_number;  	   		   //specifies the GPIO pins to be configured
	//this parameter can be a value of @GPIO_PIN_define

	uint8_t GPIO_MODE;        			 //specifies the GPIO pins to be configured
	//this parameter can be a value of @GPIO_MODE_define

	uint8_t GPIO_OUTPUT_SPEED;         //specifies the GPIO pins to be configured
	//this parameter can be a value of @GPIO_SPEED_define


}GPIO_pinconfig_t;


//----------------------------------------------------------------------------------------
//Macros Configuration References
//----------------------------------------------------------------------------------------
//@GPIO_PIN_define
#define GPIO_PIN_0       ((uint16_t) 0x0001)	//PIN_0 selected
#define GPIO_PIN_1       ((uint16_t) 0x0002)	//PIN_1 selected
#define GPIO_PIN_2       ((uint16_t) 0x0004)	//PIN_2 selected
#define GPIO_PIN_3       ((uint16_t) 0x0008)	//PIN_3 selected
#define GPIO_PIN_4       ((uint16_t) 0x0010)	//PIN_4 selected
#define GPIO_PIN_5       ((uint16_t) 0x0020)	//PIN_5 selected
#define GPIO_PIN_6       ((uint16_t) 0x0040)	//PIN_6 selected
#define GPIO_PIN_7       ((uint16_t) 0x0080)	//PIN_7 selected

#define GPIO_PIN_8       ((uint16_t) 0x0100)    //PIN_8 selected
#define GPIO_PIN_9       ((uint16_t) 0x0200)    //PIN_9 selected
#define GPIO_PIN_10      ((uint16_t) 0x0400)   //PIN10 selected
#define GPIO_PIN_11      ((uint16_t) 0x0800)    //PIN_11 selected
#define GPIO_PIN_12      ((uint16_t) 0x1000)    //PIN_12 selected
#define GPIO_PIN_13      ((uint16_t) 0x2000)    //PIN_13 selected
#define GPIO_PIN_14      ((uint16_t) 0x4000)    //PIN_14 selected
#define GPIO_PIN_15      ((uint16_t) 0x8000)    //PIN_15 selected

#define GPIO_PIN_ALL     ((uint16_t) 0xFFFF)    //_ALL selected
#define GPIO_PIN_MASK     0x0000FFFF	        //PIN MASK FOR ASSERT TEST
//@GPIO_MODE_define
//0: Analog mode
//1: Floating input (reset state)
//2: Input with pull-up
//3: pull-down mode

//4: General purpose output push-pull
//5: General purpose output Open-drain
//6: Alternate function output Push-pull
//7: Alternate function output Open-drain
//8: Alternate function input
#define GPIO_MODE_Analog             0x00000000U  //Analog mode
#define GPIO_MODE_INPUT_FLO          0x00000001U  //floating input mode
#define GPIO_MODE_INPUT_PU           0x00000002U  //pull-up  mode
#define GPIO_MODE_INPUT_PD           0x00000003U  //Open-drain mode

#define GPIO_MODE_OUTPUT_PP  	     0x00000004U  //General purpose output Open-drain
#define GPIO_MODE_OUTPUT_OD 	     0x00000005U  //General purpose output Open-drain
#define GPIO_MODE_OUTPUT_AF_PP  	 0x00000006U  //Alternate function output Push-pull
#define GPIO_MODE_OUTPUT_AF_OD  	 0x00000007U  //Alternate function output Open-drain
#define GPIO_MODE_INPUT_AF 			 0x00000008U  //Alternate function input
//GPIO_SPEED_define
//1: Output mode, max speed 10 MHz.
//2: Output mode, max speed 2 MHz.
//3: Output mode, max speed 50 MHz
#define GPIO_SPEED_10MHZ     0x00000001u //max speed 10 MHz.
#define GPIO_SPEED_2MHZ      0x00000002u //max speed 2 MHz.
#define GPIO_SPEED_50MHZ     0x00000002u //max speed 50 MHz.


//@ ref GPIO_PIN_stata
#define GPIO_pin_set 1
#define GPIO_pin_reset 0

//@ref GPIO_return_look
#define GPIO_return_ok 1
#define GPIO_pin_error 0
/*
 * =================================================================================
 * APIs Supported by "MCAL GPIO DRIVER"
 * =================================================================================
 */
void MCAL_GPIO_INIT(GPIO_typedef            *GPIOX ,   GPIO_pinconfig_t   *pinconfig);
void MCAL_GPIO_write_pin(GPIO_typedef       *GPIOX,uint16_t   gpio_pin_number ,uint16_t value);
void MCAL_GPIO_write_port(GPIO_typedef      *GPIOX,uint16_t    value);
void MCAL_GPIO_toggle_pin(GPIO_typedef      *GPIOX,uint16_t    gpio_pin_number);
uint8_t  MCAL_GPIO_look_pin(GPIO_typedef   *GPIOX,uint16_t   gpio_pin_number);
uint8_t MCAL_GPIO_Read_pin(GPIO_typedef     *GPIOX,uint16_t   gpio_pin_number);
uint16_t MCAL_GPIO_Read_port(GPIO_typedef   *GPIOX);
void MCAL_GPIO_DEINIT(GPIO_typedef          *GPIOX );



#endif /* INC_STM32F103C6_GPIO_DRIVERS_H_ */
