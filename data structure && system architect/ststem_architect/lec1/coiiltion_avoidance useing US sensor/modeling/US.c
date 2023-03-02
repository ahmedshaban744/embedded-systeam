/*
 * US.c
 *
 *  Created on: Feb 22, 2023
 *      Author: ahmed
 */

enum {
	US_busy         //state 2 driving state
}US_state_id;
#include "US.h"
int get_distance_rondom(int l,int r, int count );
//Variables
int US_distance ;
//STATE Pointer to Function
void (*US_state )();


void US_inte()
{
	printf("=========US_driver_initialized=========\n");

}
void US_busy2()
{
	//State_Name
	US_state_id = US_busy ;
	 US_distance = get_distance_rondom(45,55,1 );
	printf(" the ultrasonic sensor read  Distance =%d \n",US_distance);
	us_set_destance(US_distance);
	US_state = US_busy2;
}

int get_distance_rondom(int l,int r, int count )   //funUStion that e to give randum value
{
	int rand_num;
	for(int i=0;i<=count;i++)
	rand_num = (rand() % (r - l + 1)) + l;
	return rand_num;
}











