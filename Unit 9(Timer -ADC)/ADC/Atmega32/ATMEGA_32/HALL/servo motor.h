/*
 * servo_motor.h
 *
 * Created: 9/15/2023 3:36:04 AM
 *  Author: Ahmed
 */ 


#ifndef SERVO MOTOR_H_
#define SERVO MOTOR_H_
#include <avr/io.h>

void Servo_Init(void);
void Servo_Angle(uint8_t angle);


#endif /* SERVO MOTOR_H_ */