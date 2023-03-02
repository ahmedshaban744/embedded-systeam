/*
 * DC.c
 *
 *  Created on: Feb 22, 2023
 *      Author: ahmed
 */


#include "DC.h"
enum {
	DC_idle,          //state 1 busye state
	DC_busy1         //state 2 driving state
}DC_state_id;
//Variables
int DC_speed =0;


//STATE Pointer to Function
void (*DC_state )();


void DC_init()
{
	printf("=========DC_motor driver initialized=========\n");
}
void dc_motor_set_speed(int s)
{

	DC_speed=s;
	DC_state= DC_busy;
	printf("CA send <speed> %d to the dc motor \n",DC_speed);
}
void  DC_idel()
{
	//State_Name
	DC_state_id=DC_idle;
	printf(" in DC_idel State  <Speed> =%d\n",DC_speed);

}

void  DC_busy()
{
	//State_Name
	DC_state_id= DC_busy1;
	DC_state=  DC_idel ;
	printf(" in DC_busy State < Speed> =%d\n",DC_speed);


}













