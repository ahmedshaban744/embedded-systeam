/*
 * 7_segmant.c
 *
 *  Created on: Aug 3, 2023
 *      Author: Ahmed
 */

#include "7_segmant.h"
#include  "stm32f103c6_ gpio_drivers.h"
#include "stm32f103x6.h"
/*=======================================================================================
 * @Fn          -  sev_segmant_init
 * @brief       -initalization tht 7 segmant pins 0<<<<<<6
 * @param [in]  -NULL
 * @retval      - null
 * Note         - null
 * */
void sev_segmant_init()
{
GPIO_pinconfig_t pincongif;
pincongif.gpio_pin_number=sev_pin0;
pincongif.GPIO_MODE=GPIO_MODE_OUTPUT_PP;
pincongif.GPIO_OUTPUT_SPEED=GPIO_SPEED_10MHZ;
MCAL_GPIO_INIT(sev_port, &pincongif);

pincongif.gpio_pin_number=sev_pin1;
pincongif.GPIO_MODE=GPIO_MODE_OUTPUT_PP;
pincongif.GPIO_OUTPUT_SPEED=GPIO_SPEED_10MHZ;
MCAL_GPIO_INIT(sev_port, &pincongif);

pincongif.gpio_pin_number=sev_pin2;
pincongif.GPIO_MODE=GPIO_MODE_OUTPUT_PP;
pincongif.GPIO_OUTPUT_SPEED=GPIO_SPEED_10MHZ;
MCAL_GPIO_INIT(sev_port, &pincongif);

pincongif.gpio_pin_number=sev_pin3;
pincongif.GPIO_MODE=GPIO_MODE_OUTPUT_PP;
pincongif.GPIO_OUTPUT_SPEED=GPIO_SPEED_10MHZ;
MCAL_GPIO_INIT(sev_port, &pincongif);

pincongif.gpio_pin_number=sev_pin4;
pincongif.GPIO_MODE=GPIO_MODE_OUTPUT_PP;
pincongif.GPIO_OUTPUT_SPEED=GPIO_SPEED_10MHZ;
MCAL_GPIO_INIT(sev_port, &pincongif);

pincongif.gpio_pin_number=sev_pin5;
pincongif.GPIO_MODE=GPIO_MODE_OUTPUT_PP;
pincongif.GPIO_OUTPUT_SPEED=GPIO_SPEED_10MHZ;
MCAL_GPIO_INIT(sev_port, &pincongif);

pincongif.gpio_pin_number=sev_pin6;
pincongif.GPIO_MODE=GPIO_MODE_OUTPUT_PP;
pincongif.GPIO_OUTPUT_SPEED=GPIO_SPEED_10MHZ;
MCAL_GPIO_INIT(sev_port, &pincongif);

}
/*=======================================================================================
 * @Fn           -  number_display
 * @brief        -display number from 0 ------9 on 7segmant
 * @param [in]   -NULL
 * @retval       - null
 * Note          - null
 * */
void two_segmant_number_display()
{
	static unsigned char segment_number[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
for(int i=0 ;i<9; i++)
{
MCAL_GPIO_write_port(sev_port, segment_number[i]);
}

}



