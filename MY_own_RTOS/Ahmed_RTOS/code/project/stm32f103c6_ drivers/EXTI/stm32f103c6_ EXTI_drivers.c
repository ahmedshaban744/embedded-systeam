/*
 * stm32f103c6_ gpio_drivers.c
 *
 *  Created on: Jul 31, 2023
 *      Author: Ahmed shaban mohamed
 */
#include <stm32f103c6_EXTI_drivers.h>
#include "stm32f103c6_GPIO_drivers.h"

#define AFIO_EXTI_GPIO_MAPPING(x)                 ((x==GPIOA)? 0:\
		                                           (x==GPIOB)? 1:\
			                                       (x==GPIOC)?2:\
			 		                     	       (x==GPIOD)?3:0 )




void(*Gp_IRQ_Callback[15])(void);
void enable_NVIC(uint16_t IQR)
{
switch(IQR)
{
case 0:
		NVIC_IRQ6_EXTI0_enable();
break;
case 1:
		NVIC_IRQ7_EXTI1_enable();
break;
case 2:
		NVIC_IRQ8_EXTI2_enable();
break;
case 3:
		NVIC_IRQ9_EXTI3_enable();
break;
case 4:
		NVIC_IRQ10_EXTI4_enable();
break;

case 5:
case 6:
case 7:
case 8:
case 9:
	NVIC_IRQ23_EXTI5_to_EXTI9_enable();
break;
case 10:
case 11:
case 12:
case 13:
case 14:
case 15:

	NVIC_IRQ40_EXTI10_to_EXTI15_enable();
break;



}


}
void disable_NVIC(uint16_t IQR)
{
switch(IQR)
{
case 0:
   	NVIC_IRQ6_EXTI0_disable()   ;
break;
case 1:
		NVIC_IRQ7_EXTI1_disable();
break;
case 2:
		NVIC_IRQ8_EXTI2_disable();
break;
case 3:
		NVIC_IRQ9_EXTI3_disable();
break;
case 4:
		NVIC_IRQ10_EXTI4_disable();
break;

case 5:
case 6:
case 7:
case 8:
case 9:
	NVIC_IRQ23_EXTI5_to_EXTI9_disable();
break;
case 10:
case 11:
case 12:
case 13:
case 14:
case 15:

	NVIC_IRQ40_EXTI10_to_EXTI15_disable();
break;



}


}




void EXTI_UPDATE(EXIT_Confing_t *EXTI_config)
{
	//configure GPIo pin to be Altarnative input
	GPIO_pinconfig_t pinconfig;
	pinconfig.gpio_pin_number=EXTI_config->EXIT_Pin.GPIO_pin;
	pinconfig.GPIO_MODE=GPIO_MODE_INPUT_FLO;

	MCAL_GPIO_INIT((EXTI_config->EXIT_Pin.GPIO_port),& pinconfig);


	//configuer AFIO to routing between GPIO port A B C D
	uint8_t AFIO_EXTICR_Index =EXTI_config->EXIT_Pin.EXTI_Line_Number / 4;
	uint8_t AFIO_EXTICR_posation =(EXTI_config->EXIT_Pin.EXTI_Line_Number % 4)*4;
	//clear the four bit first to mack sure that that the value want to write ie right
	AFIO->EXTICR[AFIO_EXTICR_Index]&=~(0XF<<AFIO_EXTICR_posation);
	//set the value
	AFIO->EXTICR[AFIO_EXTICR_Index]   |= ((AFIO_EXTI_GPIO_MAPPING (EXTI_config->EXIT_Pin.GPIO_port) &0xf) <<AFIO_EXTICR_posation);
	//update Rising OR Faling or both
	EXTI->RTSR &=~(1<<EXTI_config->EXIT_Pin.EXTI_Line_Number);
	EXTI->FTSR &=~(1<<EXTI_config->EXIT_Pin.EXTI_Line_Number);
	if(EXTI_config->trigger_case==EXIT_Rising )
	{
		EXTI->RTSR |=(1<<EXTI_config->EXIT_Pin.EXTI_Line_Number);
	}
	else if(EXTI_config->trigger_case==EXIT_Falling  )
	{

		EXTI->FTSR |=(1<<EXTI_config->EXIT_Pin.EXTI_Line_Number);
	}
	else if(EXTI_config->trigger_case==EXIT_Falling_and_Rising  )
	{
		EXTI->RTSR |=(1<<EXTI_config->EXIT_Pin.EXTI_Line_Number);
		EXTI->FTSR |=(1<<EXTI_config->EXIT_Pin.EXTI_Line_Number);
	}
	//update IQR handling callback
	Gp_IRQ_Callback[EXTI_config->EXIT_Pin.EXTI_Line_Number]=EXTI_config->p_IRQ_Callback;
	//enable IQR in EXTI and NVIC
	if(EXTI_config->IRQ_define==EXIT_IRQ_enable)
	{
		EXTI->IMR|=(1<<EXTI_config->EXIT_Pin.EXTI_Line_Number);
		enable_NVIC (EXTI_config->EXIT_Pin.EXTI_Line_Number);
	}
	else
	{

		EXTI->IMR &=~(1<< EXTI_config->EXIT_Pin.EXTI_Line_Number);
		disable_NVIC(EXTI_config->EXIT_Pin.EXTI_Line_Number);

	}
}


/**================================================================
 * @Fn                   -  MCAL_EXTI_GPIO_INIT
 * @brief                -  initialize the GPIO pin  to a specified parameters
 * @param [in]           -config  base on @EXIT_Trigger and  @EXIT_define and @EXIT_IRQ_define
 * @retval               - null
 * Note                  - for stm32f103c6 use only GPIO port A  B C D but package 	LQFP48 has only A  B part of  C D
 *                       - ALSO not no open clock for AFIO and the GPIOX port
 * */

void MCAL_EXTI_GPIO_INIT(EXIT_Confing_t *EXTI_config)
{


	 EXTI_UPDATE( EXTI_config);


}

/**================================================================
 * @Fn                   -  MCAL_EXTI_GPIO_DEINIT
 * @brief                -  deinitialize the GPIO pin  to a the reset value
 * @retval               - null
 * Note                  - null
 * */

void MCAL_EXTI_GPIO_DEINIT()
{
	EXTI->IMR   =  0x00000000;
	EXTI->EMR   =  0x00000000;
	EXTI->RTSR  =  0x00000000;
	EXTI->FTSR  =  0x00000000;
	EXTI->SWIER =  0x00000000;
	EXTI->PR    =  0xFFFFFFFF;      //0: No trigger request occurred
	// 1: selected trigger request occurred
	// This bit is set when the selected edge event arrives on the external interrupt line. This bit is
	//  cleared by writing a ‘1’ into the bit.

	//disable the EXTI IRQ from NVIC
	NVIC->ICPR0 |=(1<<6);
	NVIC->ICPR0 |=(1<<7);
	NVIC->ICPR0 |=(1<<8);
	NVIC->ICPR0 |=(1<<9);
	NVIC->ICPR0 |=(1<<10);
	NVIC->ICPR0 |=(1<<23);
	NVIC->ICPR1 |=(1<<8);

}
/**================================================================
 * @Fn                   -  CAL_EXTI_GPIO_UPDATE
 * @brief                -  initialize the GPIO pin  to a specified parameters
 * @param [in]           -config  base on @EXIT_Trigger and  @EXIT_define and @EXIT_IRQ_define
 * @retval               - null
 * Note                  - for stm32f103c6 use only GPIO port A  B C D but package 	LQFP48 has only A  B part of  C D
 *                       - ALSO not no open clock for AFIO and the GPIOX port
 * */

void MCAL_EXTI_GPIO_UPDATE(EXIT_Confing_t *EXTI_config)
{


	 EXTI_UPDATE(EXTI_config);
}

//================================================================
//================== ISR Funcatiom================================
//================================================================

void EXTI0_IRQHandler(void)
{
EXTI->PR |=(1<<0);
Gp_IRQ_Callback[0]();
}

void EXTI1_IRQHandler(void)
{
	EXTI->PR |=(1<<1);
	Gp_IRQ_Callback[1]();
}

 void EXTI2_IRQHandler(void)
{
	EXTI->PR |=(1<<2);
	Gp_IRQ_Callback[2]();
}

void EXTI3_IRQHandler(void)
{
	EXTI->PR |=(1<<3);
	Gp_IRQ_Callback[3]();
}

void EXTI4_IRQHandler(void)
{
	EXTI->PR |=(1<<4);
	Gp_IRQ_Callback[4]();
}


void EXTI9_5_IRQHandler  (void)
{
	if(EXTI->PR & 1<<5 )   {EXTI->PR |=    (1<<5);     Gp_IRQ_Callback[5](); }
	if(EXTI->PR & 1<<6 )   {EXTI->PR |=    (1<<6);     Gp_IRQ_Callback[6](); }
	if(EXTI->PR & 1<<7)    {EXTI->PR |=    (1<<7);      Gp_IRQ_Callback[7](); }
	if(EXTI->PR & 1<<8 )   {EXTI->PR |=    (1<<8);     Gp_IRQ_Callback[8](); }
	if(EXTI->PR & 1<<9 )   {EXTI->PR |=    (1<<9);     Gp_IRQ_Callback[9](); }
}
void EXTI15_10_IRQHandler (void)
{
	if(EXTI->PR & 1<<10 )   {EXTI->PR |=    (1<<10);     Gp_IRQ_Callback[10](); }
	if(EXTI->PR & 1<<11 )   {EXTI->PR |=    (1<<11);     Gp_IRQ_Callback[11](); }
	if(EXTI->PR & 1<<12 )   {EXTI->PR |=    (1<<12);     Gp_IRQ_Callback[12](); }
	if(EXTI->PR & 1<<13 )   {EXTI->PR |=    (1<<13);     Gp_IRQ_Callback[13](); }
	if(EXTI->PR & 1<<14 )   {EXTI->PR |=    (1<<14);     Gp_IRQ_Callback[14](); }
	if(EXTI->PR & 1<<15 )   {EXTI->PR |=    (1<<15);     Gp_IRQ_Callback[15](); }
}

















