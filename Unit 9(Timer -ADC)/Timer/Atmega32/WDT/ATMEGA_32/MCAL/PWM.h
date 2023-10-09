/*
 * PWM.h
 *
 * Created: 9/15/2023 12:27:24 AM
 *  Author: Ahmed
 */ 


#ifndef PWM_H_
#define PWM_H_
#include "bit_prosess.h "
#include "DIO.h"
#include <avr/io.h>
#include <util/delay.h>


// pwm timer0
void PWM0_Init(void);
void PWM0_Start(void);
void PWM0_Stop(void);
void PWM_SetDutyCycle(uint8_t DC);

#endif /* PWM_H_ */