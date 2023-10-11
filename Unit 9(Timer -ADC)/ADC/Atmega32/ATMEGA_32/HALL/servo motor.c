/*
 * servo_motor.c
 *
 * Created: 9/15/2023 3:35:11 AM
 *  Author: Ahmed
 */ 
#include "servo motor.h"
void Servo_Init(void)
{
	PWM0_Init();
}
void Servo_Angle(uint8_t angle)
{
	OCR0 = (uint32_t)((float)(angle * 32.00)/180 +30 );
	PWM0_Start();
}