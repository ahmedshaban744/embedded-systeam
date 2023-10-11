/*
 * LM_35.c
 *
 * Created: 8/31/2023 2:20:28 PM
 *  Author: Ahmed
 */ 
#include "LM35.h"

void HALL_LM35_INIT()
{     ADC_Confeg  ADC_define;
	
	ADC_define.Auto_Trigger= ADC_Auto_Trigger_enable;
	ADC_define.result_state= right_Adjust;
	ADC_define.Prescaler= ADC_64_Prescaler;
	ADC_define.refrence_volt= ADC_AVCC_refrence;
	ADC_define.interrput=ADC_interrput_disable;
	MCAL_ADC_INIT(ADC0,& ADC_define);
	MCAL_DIO_PIN_Dir(DIO_PORTA,PA0,DIO_pin_INT);
	
}
uint16_t HALL_LM35_REED()
{
        ADC_Confeg  ADC_define;
		
		ADC_define.Auto_Trigger= ADC_Auto_Trigger_enable;
		ADC_define.result_state= right_Adjust;
		ADC_define.Prescaler= ADC_64_Prescaler;
		ADC_define.refrence_volt= ADC_AVCC_refrence;
		SET_BIT(ADMUX,6);
		ADC_define.interrput=ADC_interrput_disable;	
        uint16_t ADC_VAL= MCAL_ADC_REED( ADC0, &ADC_define);
		//from microcontroller datasheet
		//input volt= (ADC_VAL*refrance volt)/resulation
		uint16_t analogVoltage_input =(ADC_VAL * 5000.00 )/1024;
		//from sensor data sheet
		uint16_t temp = analogVoltage_input /10;
		return temp;
}