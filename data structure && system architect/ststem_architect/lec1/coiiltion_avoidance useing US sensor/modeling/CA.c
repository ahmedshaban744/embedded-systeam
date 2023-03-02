/*
 * CA.c
 *
 *  Created on: Feb 22, 2023
 *      Author: ahmed
 */
enum {
	CA_waiting,       //state 1 waiting state
	CA_driving         //state 2 driving state
}CA_state_id;

#include "CA.h"

//_Variables_
int CA_speed =0;
int CA_distance ;
int CA_threshold =50;

//STATE Pointer to Function
void (*CA_state )();
void us_set_destance(int d)
{
	CA_distance= d;
	(CA_distance <=CA_threshold)?(CA_state=  state_wating ):(CA_state=  state_driving);
	printf("ultrasonic sensor send distance %d to the CA \n",CA_distance);
}
void state_wating()
{
	//State_Name
	CA_state_id=CA_waiting;
	printf("CA_waiting State   :  Distance =%d \t Speed =%d\n",CA_distance,CA_speed);
	//State_Action
	CA_speed=0;
	dc_motor_set_speed(CA_speed);
}
void state_driving()
{
	//State_Name
	CA_state_id=CA_driving;
	printf("CA_driving State   : Distance =%d \t Speed =%d\n",CA_distance,CA_speed);
	//State_Action
	CA_speed=30;
	dc_motor_set_speed(CA_speed);
}













