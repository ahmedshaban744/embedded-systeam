/*
 * PWM.c
 *
 * Created: 9/15/2023 12:27:13 AM
 *  Author: Ahmed
 */ 
#include "PWM.h"
void PWM0_Init(void)
{
	// pin dir out
	SET_BIT(DDRB,3);
	// pwm mode
	SET_BIT(TCCR0,3);
	SET_BIT(TCCR0 ,6);

	// non inverted mode
	SET_BIT(TCCR0 , 5);
}
void PWM0_Start(void)
{
	// select timer frequency with prescaller 1024
	SET_BIT(TCCR0 , 0);
	CLR_BIT(TCCR0 , 1);
	SET_BIT(TCCR0 , 2);
}
void PWM0_Stop(void)
{
	// select timer frequency = 0
	CLR_BIT(TCCR0 , 0);
	CLR_BIT(TCCR0 , 1);
	CLR_BIT(TCCR0 , 2);
}
void PWM_SetDutyCycle(uint8_t DC)
{
	OCR0 = (uint8_t )((DC/100.0 *256)-1);
}