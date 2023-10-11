/*
 * Timer0.h
 *
 * Created: 10/7/2023 9:03:54 PM
 *  Author: Ahmed shaban
 */ 
//===========================================================================
//=========================includes==========================================
//===========================================================================
#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "DIO.h"
#include "bit_prosess.h"

//===========================================================================
//=========================serves============================================
//===========================================================================
#ifndef TIMER0_H_
#define TIMER0_H_
typedef unsigned char* ptr_uint_8; 
typedef void(*ptr_void_fun)(void);
#define  NULL_ptr    ((void*)(0))
typedef unsigned char EN_status; 
#define  NOT_OK    (EN_status)(1)
#define  OK        (EN_status)(0)

//===========================================================================
//================================enums======================================
//===========================================================================

typedef enum
{
	normal ,
	PC_PWM    ,
	CTC    ,
	Fast_PWM		
}Timer0_modes;

typedef enum
{
	No_clock_source,
	clock_without_prescaller ,
	clock_with_prescaller8   ,
	clock_with_prescaller64  ,
	clock_with_prescaller256 ,
	clock_with_prescaller1024,
    External_clock_source_on_falling_edge,
    External_clock_source_on_rising_edge
  
}Timer0_clock_prescaller;

typedef enum
{
	OCF0_disable  ,
	OCF0_enable=0x2

}Timer0_OCF0_interrput;
typedef enum
{
	TOV0_disable ,
	TOV0_enable

}Timer0_TOV0_interrput;
typedef enum
{
Normal_port_operation,
Clear_OC0_on_compare_match=0X2,
Set_OC0_on_compare_match
}Timer0_PWM_mode;



//===========================================================================
//================================config struct==============================
//===========================================================================
typedef struct
{
	Timer0_modes mode;
	Timer0_clock_prescaller clock;
	Timer0_OCF0_interrput comp_mat ;
	Timer0_TOV0_interrput overflow;
	Timer0_PWM_mode  FAST_PWM;
	

}TIMER0_config;

//===========================================================================
//================================APIS=======================================
//===========================================================================
EN_status MCAL_Timer0_init(TIMER0_config*timer_define);
EN_status MCAL_Timer0_stop(void);

EN_status MCAL_Timer0_get_comper_val(ptr_uint_8 pi8_ticks);
EN_status MCAL_Timer0_set_comper_val(ptr_uint_8 pi8_ticks);

EN_status MCAL_Timer0_get_overflow_val(ptr_uint_8 pi8_ticks);
EN_status MCAL_Timer0_set_overflow_val(ptr_uint_8 pi8_ticks);

void MCAL_Timer0_overflow_interrput_callback(ptr_void_fun callback);
void MCAL_Timer0_comper_match_interrput_callback(ptr_void_fun callback);

void MCAL_Timer0_PWM_start( TIMER0_config*timer0_define);
void MCAL_Timer0_PWM_stop();
void MCAL_Timer0_PWM_set_duty_cycle(uint8_t cyclle);

#endif /* TIMER0_H_ */