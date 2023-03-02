/*
 * CA.c
 *
 *  Created on: Feb 22, 2023
 *      Author: ahmed
 */


#include "CA.h"
int US_GET_distance_rondom(int l,int r);
//Variables
int CA_speed =0;
int CA_distance =0;
int CA_threshold =50;

//STATE Pointer to Function
void (*CA_state )();

int state_wating()
{
	//State_Name
	CA_state_id=CA_waiting;

	//State_Action
	CA_speed=0;

	//Event_Check
	//US_GET_Distance(CA_distance)
	CA_distance=US_GET_distance_rondom(45,55);
	//Event_Check
	//line condation if the condation is true do the 1st else do the 2th
	(CA_distance <=CA_threshold)?(CA_state= state_wating (CA_waiting)):(CA_state=state_driving(CA_driving));

	printf("CA_driving State   : Distance =%d \t Speed =%d\n",CA_distance,CA_speed);
return 1;

}

int state_driving()
{
	//State_Name
	CA_state_id=CA_driving;

	//State_Action
	CA_speed=30;


	//US_GET_Distance(CA_distance)
	CA_distance=US_GET_distance_rondom(45,55);
	//Event_Check
	//line condation if the condation is true do the 1st else do the 2th
	(CA_distance <=CA_threshold)?(CA_state= state_wating (CA_waiting)):(CA_state=state_driving(CA_driving));


	printf("CA_driving State   : Distance =%d \t Speed =%d\n",CA_distance,CA_speed);

}
int US_GET_distance_rondom(int l,int r )   //funcation that use to give randum value
{
	int rand_num;
	rand_num = (rand() % (r - l + 1)) + l;
	return rand_num;
}












