/*
 * state.h
 *
 *  Created on: Feb 22, 2023
 *      Author: ahmed
 */
#ifndef STATE_H_
#define STATE_H_
#include "stdio.h"
#include "stdlib.h"

//Automatic State Function Generated
#define STATE_define(_stateFUN_) void ST_##_stateFUN_()
#define STATE(_stateFUN_) ST_##_stateFUN_
//STATE conectation
void us_set_destance(int d);     //funcation that read the distance from the US and set the distance
void dc_motor_set_speed(int s);   //funcation that set the speed to the motor
#endif /* STATE_H_ */
