/*
 * keypad.h
 *
 * Created: 7/29/2023 7:12:34 PM
 *  Author:  Ahmed Shaban
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#define keypad_port GPIOB

#define R0 GPIO_PIN_0
#define R1 GPIO_PIN_1
#define R2 GPIO_PIN_3
#define R3 GPIO_PIN_4
#define C0 GPIO_PIN_5
#define C1 GPIO_PIN_6
#define C2 GPIO_PIN_7
#define C3 GPIO_PIN_8
void keypad_init();
char git_char();
#endif /* KEYPAD_H_ */
