/*
 * LDR.c
 *
 * Created: 9/16/2023 1:40:26 AM
 *  Author: Ahmed
 */ 
#include "LDR.h"
void HALL_LDR_INIT()
{
	 ADC_Confeg  ADC_define;
	 
	 ADC_define.Auto_Trigger= ADC_Auto_Trigger_enable;
	 ADC_define.result_state= right_Adjust;
	 ADC_define.Prescaler= ADC_64_Prescaler;
	 ADC_define.refrence_volt= ADC_AVCC_refrence;
	 ADC_define.interrput=ADC_interrput_disable;
	 MCAL_ADC_INIT(ADC7,& ADC_define);
	// MCAL_DIO_PIN_Dir(DIO_PORTA,PA7,DIO_pin_INT);
}
uint16_t HALL_LDR_REED()
{
	   ADC_Confeg  ADC_define;
	   
	   ADC_define.Auto_Trigger= ADC_Auto_Trigger_disable;
	   ADC_define.result_state= right_Adjust;
	   ADC_define.Prescaler= ADC_64_Prescaler;
	   ADC_define.refrence_volt= ADC_AVCC_refrence;
	   SET_BIT(ADMUX,6);
	   ADC_define.interrput=ADC_interrput_disable;
	   uint16_t vin= MCAL_ADC_REED( ADC7, &ADC_define);
	   
	 // uint16_t analogVoltage_input =(vin * 5000.00 )/1024;
	   
	 //  uint16_t light = analogVoltage_input /10;
	   
	   return vin;
	//  return (5*(10/10+100));
}