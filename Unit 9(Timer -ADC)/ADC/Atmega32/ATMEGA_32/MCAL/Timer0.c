/*
 * Timer0.c
 *
 * Created: 10/7/2023 9:03:40 PM
 *  Author: Ahmed Shaban 
 */ 
//===========================================================================
//=========================includes==========================================
//===========================================================================
#include "Timer0.h"
//===========================================================================
//=============================globle var====================================
//===========================================================================
void (*GL_pointer_TOV0)(void);
void (*GL_pointer_OCF0)(void);
TIMER0_config * timer0_define;
uint8_t OVF_VAL=0;
//===========================================================================
//================================APIS=======================================
//===========================================================================

EN_status MCAL_Timer0_init(TIMER0_config*timer_define)
{ 
	EN_status state=NOT_OK;
	timer0_define=timer_define;
	
if(NULL_ptr==timer0_define)
	{
	state=NOT_OK;
	}
else
	{
		state=OK;		
	}
if((timer0_define->mode==normal) ||(timer0_define->mode==CTC)|| (timer0_define->mode==PC_PWM ) ||(timer0_define->mode==Fast_PWM))
		{
     switch(timer0_define->mode)
	 {
	case normal:
	{
		CLR_BIT(TCCR0,WGM00);
		CLR_BIT(TCCR0,WGM01);
		
		break;
	}
	case PC_PWM :
	{
		SET_BIT(TCCR0,WGM00);
		CLR_BIT(TCCR0,WGM01);
		break;
	}
	case CTC:
	{	CLR_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
		break;
	}
	case Fast_PWM:
	{
			SET_BIT(TCCR0,WGM00);
			SET_BIT(TCCR0,WGM01);
		break;
	}
	default:
	break;
		 
		 
	 }
			
		}
else
		{
			state=NOT_OK;
		}
if((timer0_define->clock >= No_clock_source) && (timer0_define->clock<=External_clock_source_on_rising_edge))
		{
			TCCR0 |=timer0_define->clock;
			state=OK;		
		}
else
		         {
			state=NOT_OK;
	    	}
//determind the PWM mode			
if((timer0_define-> FAST_PWM == Normal_port_operation) ||(timer0_define->FAST_PWM == Clear_OC0_on_compare_match)||(timer0_define->FAST_PWM == Set_OC0_on_compare_match))
{
	TCCR0 |=timer0_define->FAST_PWM<<4;
	state=OK;

}
else
      {
	     state=NOT_OK;
     }				
if(timer0_define->comp_mat == OCF0_disable ||timer0_define->comp_mat == OCF0_enable)
{
	TIMSK |=timer0_define->comp_mat;
	state=OK;

}
else
      {
	     state=NOT_OK;
     }
if(timer0_define->overflow == TOV0_disable ||timer0_define->overflow == TOV0_enable)
{
	TIMSK |= timer0_define->overflow;
	state=OK;
}
else
{
	state=NOT_OK;
}	 
	
     return  state;
}
EN_status MCAL_Timer0_stop(void)
{
	EN_status state=OK;
	//clear the input clock
	CLR_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);
   return  state;
}

EN_status MCAL_Timer0_get_comper_val(ptr_uint_8 pi8_ticks)
{
	EN_status state=OK;
	*pi8_ticks= OCR0;
    return  state;
}
EN_status MCAL_Timer0_set_comper_val(ptr_uint_8 pi8_ticks)
{
	EN_status state=OK;
	OCR0=pi8_ticks;
	return  state;
}

EN_status MCAL_Timer0_get_overflow_val(ptr_uint_8 pi8_ticks)
{
	EN_status state=OK;
	
	*pi8_ticks=OVF_VAL;
	return  state;
}
EN_status MCAL_Timer0_set_overflow_val(ptr_uint_8 pi8_ticks)
{
	EN_status state=OK;
	OVF_VAL=pi8_ticks;
	return  state;
}

void MCAL_Timer0_overflow_interrput_callback(ptr_void_fun callback)
{
	GL_pointer_TOV0=callback;

}
void MCAL_Timer0_comper_match_interrput_callback(ptr_void_fun callback)
{
      GL_pointer_OCF0=callback;
}

void MCAL_Timer0_PWM_start( TIMER0_config*timer0_define)
{
	timer0_define=timer0_define;
	MCAL_DIO_PIN_Dir(DIO_PORTB,PB3,DIO_pin_OUT);
if(timer0_define->mode==Fast_PWM)
{
    switch(timer0_define->mode)
    {
	    case normal:
	    {
		    CLR_BIT(TCCR0,WGM00);
		    CLR_BIT(TCCR0,WGM01);
		    
		    break;
	    }
	    case PC_PWM :
	    {
		    SET_BIT(TCCR0,WGM00);
		    CLR_BIT(TCCR0,WGM01);
		    break;
	    }
	    case CTC:
	    {	CLR_BIT(TCCR0,WGM00);
		    SET_BIT(TCCR0,WGM01);
		    break;
	    }
	    case Fast_PWM:
	    {
		    SET_BIT(TCCR0,WGM00);
		    SET_BIT(TCCR0,WGM01);
		    break;
	    }
	    default:
	    break;
	TCCR0 |=timer0_define->clock;
	TCCR0|= timer0_define->FAST_PWM<<4;

}	
}
}
void MCAL_Timer0_PWM_stop()
{
		MCAL_DIO_PIN_Dir(DIO_PORTB,PB0,DIO_pin_INT);
		CLR_BIT(TCCR0,CS00);
		CLR_BIT(TCCR0,CS01);
		CLR_BIT(TCCR0,CS02);
		
		
}
void MCAL_Timer0_PWM_set_duty_cycle(uint8_t cyclle)
{
uint8_t val=(uint8_t )((cyclle/100.0 *256)-1);
ptr_uint_8 cal=val;
MCAL_Timer0_set_comper_val(cal);
}

void MCAL_Timer0_PC_PWM_stop()
{

}
void MCAL_Timer0_PC_PWM_set_duty_cycle(uint8_t cyclle)
{
	
}
 ISR(TIM0_COMP)
{
GL_pointer_OCF0();
}
 ISR(TIM0_OVF)
{   
	OVF_VAL++;
	GL_pointer_TOV0();
}
	