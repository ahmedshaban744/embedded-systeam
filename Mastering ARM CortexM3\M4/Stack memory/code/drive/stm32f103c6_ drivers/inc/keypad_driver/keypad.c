/*
 * keypad.c
 *
 * Created: 7/29/2023 7:13:14 PM
 *  Author: Ahmed Shaban
 */ 
#include <stm32f103c6_GPIO_drivers.h>
#include "keypad.h"
#include "stm32f103x6.h"
int keypad_row[]={R0,R1,R2,R3};
int keypad_colom[]={C0,C1,C2,C3};


/*=======================================================================================
 * @Fn           -  keypad_init
 * @brief        -initalization tht keypad  pins 0<<<<<<7
 * @param [in]   -NULL
 * @retval       - NULL
 * Note          - NULL
 * */
 void keypad_init()
{
	GPIO_pinconfig_t pinconfig ;

	pinconfig.gpio_pin_number= R0;
	pinconfig.GPIO_MODE=GPIO_MODE_OUTPUT_PP ;
	pinconfig.GPIO_OUTPUT_SPEED=GPIO_SPEED_10MHZ;
	MCAL_GPIO_INIT(keypad_port, &pinconfig);

	pinconfig.gpio_pin_number= R1;
	pinconfig.GPIO_MODE=GPIO_MODE_OUTPUT_PP ;
	pinconfig.GPIO_OUTPUT_SPEED=GPIO_SPEED_10MHZ;
	MCAL_GPIO_INIT(keypad_port, &pinconfig);

	pinconfig.gpio_pin_number= R2;
	pinconfig.GPIO_MODE=GPIO_MODE_OUTPUT_PP ;
	pinconfig.GPIO_OUTPUT_SPEED=GPIO_SPEED_10MHZ;
	MCAL_GPIO_INIT(keypad_port, &pinconfig);

	pinconfig.gpio_pin_number= R3;
	pinconfig.GPIO_MODE=GPIO_MODE_OUTPUT_PP ;
	pinconfig.GPIO_OUTPUT_SPEED=GPIO_SPEED_10MHZ;
	MCAL_GPIO_INIT(keypad_port, &pinconfig);

	pinconfig.gpio_pin_number= C0;
	pinconfig.GPIO_MODE=GPIO_MODE_OUTPUT_PP ;
	pinconfig.GPIO_OUTPUT_SPEED=GPIO_SPEED_10MHZ;
	MCAL_GPIO_INIT(keypad_port, &pinconfig);

	pinconfig.gpio_pin_number= C1;
	pinconfig.GPIO_MODE=GPIO_MODE_OUTPUT_PP ;
	pinconfig.GPIO_OUTPUT_SPEED=GPIO_SPEED_10MHZ;
	MCAL_GPIO_INIT(keypad_port, &pinconfig);
	pinconfig.gpio_pin_number= C2;
	pinconfig.GPIO_MODE=GPIO_MODE_OUTPUT_PP ;
	pinconfig.GPIO_OUTPUT_SPEED=GPIO_SPEED_10MHZ;
	MCAL_GPIO_INIT(keypad_port, &pinconfig);

	pinconfig.gpio_pin_number= C3;
	pinconfig.GPIO_MODE=GPIO_MODE_OUTPUT_PP ;
	pinconfig.GPIO_OUTPUT_SPEED=GPIO_SPEED_10MHZ;
	MCAL_GPIO_INIT(keypad_port, &pinconfig);
	
	MCAL_GPIO_write_port(keypad_port, 0XFF);

}
 /*=======================================================================================
  * @Fn           -  git_char
  * @brief        -detect the key press by user
  * @param [in]   -NULL
  * @retval       - NULL
  * Note          - NULL
  * */
char git_char()
{
	for(int i=0 ;i<4;i++)
	{

		MCAL_GPIO_write_pin(keypad_port, keypad_colom[0], GPIO_pin_set);
		MCAL_GPIO_write_pin(keypad_port, keypad_colom[1], GPIO_pin_set);
		MCAL_GPIO_write_pin(keypad_port, keypad_colom[2], GPIO_pin_set);
		MCAL_GPIO_write_pin(keypad_port, keypad_colom[3], GPIO_pin_set);
		MCAL_GPIO_write_pin(keypad_port, keypad_colom[i], GPIO_pin_reset);

		for(int j=0 ;j<4;j++)
		{
			if(MCAL_GPIO_Read_pin (keypad_port,  keypad_row[j])==0)
			{
				while(MCAL_GPIO_Read_pin (keypad_port,  keypad_row[j])==0);
				switch(i)
				{
				case(0):
	{
					if(j==0) return '7';
					else if(j==1)return '4';
					else if(j==2)return '1';
					else if(j==3)return '!';
					break;
	}
				case(1):
	{
					if(j==0)return '8';
					else if(j==1)return '5';
					else if(j==2)return '2';
					else if(j==3)return '0';
					break;
	}
				case(2):
	{
					if(j==0)return '9';
					else if(j==1)return '6';
					else if(j==2)return '3';
					else if(j==3)return '=';
					break;
	}
				case(3):
	{
					if(j==0)return '/';
					else if(j==1)return '*';
					else if(j==2)return '-';
					else if(j==3)return '+';
					break;
	}

				}
			}

		}

	}
	return 'N';
}

