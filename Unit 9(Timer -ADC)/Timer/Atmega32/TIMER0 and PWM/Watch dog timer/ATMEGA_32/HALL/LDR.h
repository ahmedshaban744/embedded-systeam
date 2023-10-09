/*
 * LDR.h
 *
 * Created: 9/16/2023 1:40:40 AM
 *  Author: Ahmed
 */ 


#ifndef LDR_H_
#define LDR_H_
#include "ADC.h"
#include <avr/io.h>
#include <util/delay.h>

void HALL_LDR_INIT();
uint16_t HALL_LDR_REED();



#endif /* LDR_H_ */