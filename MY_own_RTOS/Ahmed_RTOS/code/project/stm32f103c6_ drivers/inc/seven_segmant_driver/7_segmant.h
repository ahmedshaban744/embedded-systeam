/*
 * 7_segmant.h
 *
 *  Created on: Aug 3, 2023
 *      Author: Ahmed SHABAN
 */

#ifndef INC_SEVEN_SEGMANT_DRIVER_7_SEGMANT_H_
#define INC_SEVEN_SEGMANT_DRIVER_7_SEGMANT_H_

#define sev_port GPIOB

#define ZERO  0x01
#define ONE   0x79
#define TWO   0x24
#define THREE 0x30
#define FOUR  0x4C
#define FIVE  0x12
#define SIX   0x02
#define SEVEN 0x19
#define EIGHT 0x00
#define NINE  0x10



#define sev_pin0  GPIO_PIN_9
#define sev_pin1  GPIO_PIN_10
#define sev_pin2  GPIO_PIN_11
#define sev_pin3  GPIO_PIN_12
#define sev_pin4  GPIO_PIN_13
#define sev_pin5  GPIO_PIN_14
#define sev_pin6  GPIO_PIN_15
void sev_segmant_init();
 void two_segmant_number_display();

#endif /* INC_SEVEN_SEGMANT_DRIVER_7_SEGMANT_H_ */
