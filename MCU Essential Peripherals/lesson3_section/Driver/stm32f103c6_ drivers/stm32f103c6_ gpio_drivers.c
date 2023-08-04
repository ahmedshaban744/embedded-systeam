/*
 * stm32f103c6_ gpio_drivers.c
 *
 *  Created on: Jul 31, 2023
 *      Author: Ahmed shaban mohamed
 */
#include "stm32f103c6_ gpio_drivers.h"
uint8_t git_pin_posation( uint16_t gpio_pin_number)
{
	switch(gpio_pin_number)
	{
	case GPIO_PIN_0 :
		return 0;
		break;
	case GPIO_PIN_1 :
		return 4;
		break;

	case GPIO_PIN_2 :
		return 8;
		break;

	case GPIO_PIN_3 :
		return 12;
		break;

	case GPIO_PIN_4 :
		return 16;
		break;

	case GPIO_PIN_5 :
		return 20;
		break;

	case GPIO_PIN_6 :
		return 24;
		break;


	case GPIO_PIN_7 :
		return 28;
		break;

	case GPIO_PIN_8 :
		return 0;
		break;
	case GPIO_PIN_9 :
		return 4;
		break;

	case GPIO_PIN_10 :
		return 8;
		break;

	case GPIO_PIN_11 :
		return 12;
		break;

	case GPIO_PIN_12 :
		return 16;
		break;

	case GPIO_PIN_13 :
		return 20;
		break;

	case GPIO_PIN_14 :
		return 24;
		break;


	case GPIO_PIN_15 :
		return 28;
		break;
	default :
		break ;

	}
	return 0;

}

/**================================================================
 * @Fn                   -  MCAL_GPIO_INIT
 * @brief                -initialize the GPIO pin  to a specified parameters
 * @param [in]           -GPIOX where x can be (A,B,C,D,E)  to select the gpio pripher
 * @param [IN]           -pinconfig is apointer to the GPIO_pinconfig_t struture that contains  all
                        -//configration information
 * @retval               - null
 * Note                  -in STM32F103c6 mcu has gpio port A B C D but LQFP48 package hava only A and B and part OF C and  D
 */

void MCAL_GPIO_INIT(GPIO_typedef *GPIOX ,GPIO_pinconfig_t *pinconfig)
{
	//port configur register low (GPIO_CRL) configure  pins from 0 ti 7
	//port configur register high (GPIO_CRH) configure  pins from 8 ti 15
	volatile uint32_t *configregister =NULL;
	uint8_t config=0;
	configregister=(pinconfig->gpio_pin_number<GPIO_PIN_8)? &GPIOX->CRL : &GPIOX->CRH  ;
	//clear CNFy[1:0] and  	M0DE y[1:0]
	(*configregister) &= ~(0xf<<git_pin_posation(pinconfig->gpio_pin_number));
	// if pin is output
	if(  (pinconfig->GPIO_MODE==GPIO_MODE_OUTPUT_AF_OD) ||(pinconfig->GPIO_MODE==GPIO_MODE_OUTPUT_AF_PP)||(pinconfig->GPIO_MODE==GPIO_MODE_OUTPUT_OD)||(pinconfig->GPIO_MODE==GPIO_MODE_OUTPUT_PP ))
	{
		//set CNFy[1:0] and M0DE y[1:0]
		config=((((pinconfig->GPIO_MODE -4)<<2)|(pinconfig->GPIO_OUTPUT_SPEED))&0X0f) ;
		//(*configregister)|=((config)<<git_pin_posation(pinconfig->gpio_pin_number));

	}
	else
	{
		if(  (pinconfig->GPIO_MODE==GPIO_MODE_INPUT_FLO) ||(pinconfig->GPIO_MODE==GPIO_MODE_Analog))
		{
			//set CNFy[1:0] and M0DE y[1:0]
			config=((((pinconfig->GPIO_MODE )<<2)| 0X0) & 0X0F) ;
			//	(*configregister)|=((config)<<git_pin_posation(pinconfig->gpio_pin_number));

		}
		else if  (pinconfig->GPIO_MODE==GPIO_MODE_INPUT_AF )
		{
			config=(((GPIO_MODE_INPUT_AF<<2)|0x0)&0x0f);
			//(*configregister)|=((config)<<git_pin_posation(pinconfig->gpio_pin_number));

		}
		else
		{
			config=((((GPIO_MODE_INPUT_PU)<<2)|0x0)&0x0f);
			if(pinconfig->GPIO_MODE==GPIO_MODE_INPUT_PU)
			{
				GPIOX->ODR |= pinconfig->gpio_pin_number;
			}
			else
			{
				GPIOX->ODR &=~( pinconfig->gpio_pin_number);

			}
		}
	}
	//write or read to CL or CRH
	(*configregister)|=((config)<<git_pin_posation(pinconfig->gpio_pin_number));
}
/**================================================================
 * @Fn                   -  MCAL_GPIO_DEINIT
 * @brief                - deinitialize the GPIOX port
 * @param [in]           -GPIOX where x can be (A,B,C,D,E)   to select the gpio pripher
 * @retval               - null
 * Note                  - null
 * */

void MCAL_GPIO_DEINIT(GPIO_typedef *GPIOX )
{
	//	GPIOX->CRH|=0X44444444;
	//	GPIOX->BRR|=0X44444444;
	//	GPIOX->BSRR|=0X44444444;
	//	GPIOX->ODR|=0X44444444;
	//	GPIOX->LCKR|=0X44444444;
	//	//GPIOX->IDR|=(read only);
	//	GPIOX->CRL|=0X44444444;

	//or

	if(GPIOX==GPIOA)
	{
		RCC->APB2RSTR|=1<<2;
		RCC->APB2RSTR&=~(1<<2);
	}
	else if(GPIOX==GPIOB)
	{
		RCC->APB2RSTR|=1<<3;
		RCC->APB2RSTR&=~(1<<3);
	}
	else if(GPIOX==GPIOC)
	{
		RCC->APB2RSTR|=1<<4;
		RCC->APB2RSTR&=~(1<<4);
	}
	else if(GPIOX==GPIOD)
	{
		RCC->APB2RSTR|=1<<5;
		RCC->APB2RSTR&=~(1<<5);
	}
	else if(GPIOX==GPIOE)
	{
		RCC->APB2RSTR|=1<<6;
		RCC->APB2RSTR&=~(1<<6);
	}


}

/**================================================================
 * @Fn                   -  MCAL_GPIO_write_pin
 * @brief                - write to  the GPIOX pin
 * @param [in]           -GPIOX where x can be (A,B,C,D,E)  to select the gpio pripher
 *                       -gpio_pin_number specifies the port bit to read  set by @ ref GPIO_PIN_define
 *                       -value  pin  value that use to raad to the pin   @ ref GPIO_PIN_stata
 * @retval               - null
 * Note                  - null
 * */

void MCAL_GPIO_write_pin(GPIO_typedef *GPIOX ,  uint16_t gpio_pin_number ,  uint16_t value)
{
	if(value!=GPIO_pin_reset)
	{
		GPIOX->BSRR=(uint32_t)gpio_pin_number;
	}
	else
	{
		GPIOX->BRR=(uint32_t)gpio_pin_number;

	}

	//	BRy: Port x Reset bit y (y= 0 .. 15)
	//	These bits are write-only and can be accessed in Word mode only.
	//	0: No action on the corresponding ODRx bit
	//	1: Reset the corresponding ODRx bit
	//	Note: If both BSx and BRx are set, BSx has priority.
	//	Bits 15:0 BSy: Port x Set bit y (y= 0 .. 15)
	//	These bits are write-only and can be accessed in Word mode only.
	//	0: No action on the corresponding ODRx bit
	//	1: Set the corresponding ODRx bit
}
/**================================================================
 * @Fn                   -  MCAL_GPIO_write_port
 * @brief                - write to  the GPIO port
 * @param [in]           -GPIOX where x can be (A,B,C,D,E)  to select the gpio pripher
 *                       -value  pin  value that use to raad to the pin   @ ref GPIO_PIN_stata
 * @retval               - null
 * Note                  - null
 * */
void MCAL_GPIO_write_port(GPIO_typedef *GPIOX,uint16_t value)
{
	GPIOX->ODR=(uint32_t)value;

}
/**================================================================
 * @Fn                   -  MCAL_GPIO_look_pin
 * @brief                - look a specific pin in a specific gpio port
 * @param [in]           -GPIOX where x can be (A,B,C,D,E)  to select the gpio pripher
 * @param [in]           -gpio_pin_number specifies the port bit to read  set by @ ref GPIO_PIN_defin
 * @retval               - ok if the pin is looked and error if not  @ref GPIO_return_look
 * Note                  - null
 * */

uint8_t MCAL_GPIO_look_pin(GPIO_typedef   *GPIOX  ,  uint16_t    gpio_pin_number)
{
//	This register is used to lock the configuration of the port bits when a correct write sequence
//	is applied to bit 16 (LCKK). The value of bits [15:0] is used to lock the configuration of the
//	GPIO. During the write sequence, the value of LCKR[15:0] must not change. When the
//	LOCK sequence has been applied on a port bit it is no longer possible to modify the value of
//	the port bit until the next reset.
//	Each lock bit freezes the corresponding 4 bits of the control register (CRL, CRH)


	volatile uint32_t temp =1<<16;
//	LOCK key writing sequence:
//	Write 1
//	read 0
//	Write 1
//	Read  0
	temp|=gpio_pin_number;
	GPIOX->LCKR= temp;
	GPIOX->LCKR= gpio_pin_number;
	GPIOX->LCKR= temp;
	if((uint32_t)(GPIOX->LCKR&1<<16))
	{
		return GPIO_return_ok;
	}
	else
	{
		return	GPIO_pin_error;
	}

}
/**================================================================
 * @Fn                   -  MCAL_GPIO_Read_pin
 * @brief                - read a specific pin in a specific gpio port
 * @param [in]           -GPIOX where x can be (A,B,C,D,E)  to select the gpio pripher
 *@param [in]            -gpio_pin_number specifies the port bit to read  set by @ ref GPIO_PIN_defin
 * @retval               - the input pin value
 * Note                  - null
 * */
uint8_t MCAL_GPIO_Read_pin(GPIO_typedef *GPIOX,uint16_t gpio_pin_number)
{
	uint8_t pin_status;
	if(((GPIOX->IDR) & gpio_pin_number)!=(uint8_t) GPIO_pin_reset)
	{
		pin_status =GPIO_pin_set;
	}
	else
	{
		pin_status =GPIO_pin_reset;
	}
	return  pin_status;

}
/**================================================================
 * @Fn                   -  MCAL_GPIO_Read_port
 * @brief                - read a specific port value
 * @param [in]            -GPIOX where x can be (A,B,C,D,E)  to select the gpio pripher
 * @retval               - the input port value
 * Note                  - null
 * */
uint16_t MCAL_GPIO_Read_port(GPIO_typedef *GPIOX)
{
	uint16_t port_state;

	port_state=(uint16_t)GPIOX->IDR;
	return  port_state;
}
/**================================================================
 * @Fn                   -  MCAL_GPIO_toggle_pin
 * @brief                - toggle  a specific pin in a specific port
 * @param [in]           -GPIOX where x can be (A,B,C,D,E)  to select the gpio pripher
 * @param [in]           - gpio_pin_number specifies the port bit to read  set by @ ref GPIO_PIN_defin
 * @retval               - null
 * Note                  - null
 * */
void MCAL_GPIO_toggle_pin(GPIO_typedef *GPIOX,uint16_t gpio_pin_number)
{

	GPIOX->ODR ^=gpio_pin_number;
}


