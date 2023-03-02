/*
 * main.c
 *
 *  Created on: Feb 22, 2023
 *      Author: ahmed shaban
 */
#include "DC.h"
#include "US.h"
#include "CA.h"
void US_busy2 ();
void setup()
{
	//init all The Drivers;
	//inti IRQ ....
	//init HAL US_Driver DC_Driver
	//init Block
	US_inte();
	DC_init();
	//Set States Pointer for each Block
	CA_state =  state_wating;
	US_state=   US_busy2;
	DC_state=  DC_idel;

}
int main ()
{
	volatile int i ;  // use volatile to save from the optimizer from removing
	setup();

	while(1)
	{
		//Call State for each Block
		US_state(); //1st  the us sensor read the distance to the CA
		CA_state(); //2sd CA reseve the distance
		DC_state(); //3rd the dc motor take action stop or go
		for(i=0;i<50000;i++);  //time delay
	}
	return 0;
}
