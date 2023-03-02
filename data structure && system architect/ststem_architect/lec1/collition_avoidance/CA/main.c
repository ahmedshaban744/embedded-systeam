/*
 * main.c
 *
 *  Created on: Feb 22, 2023
 *      Author: ahmed shaban
 */

#include "CA.h"

void setup()
{
	//init all The Drivers;
	//inti IRQ ....
	//init HAL US_Driver DC_Driver
	//init Block
	//Set States Pointer for each Block
	CA_state =state_wating(CA_waiting);  //make the pointer to refer to the wating state
}
int main ()
{
	volatile int i ;  // use volatile to save from the optimizer from removing
	setup();

	while(1)
	{
		//Call State for each Block
		CA_state();
		for(i=0;i<50000;i++);  //time delay
	}
	return 0;
}
