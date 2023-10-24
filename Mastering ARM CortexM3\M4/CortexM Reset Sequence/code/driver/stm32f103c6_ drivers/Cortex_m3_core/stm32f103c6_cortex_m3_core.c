/*
 * stm32f103c6_cortex_m3_core.c
 *
 *  Created on: Oct 24, 2023
 *      Author: Ahmed
 */

#include "stm32f103c6_cortex_m3_core.h"
void swich_CPU_access_user_level(enum user_level level)

{
	switch(level)
	{
	case Privileged :
		__asm("mrs R3,control \n\t"
			"LSR R3,R3,#0X1 \n\t"
			"LSL R3,R3,#0X1 \n\t"
			);
		break;
	case UnPrivileged:

		__asm("mrs R3,control \n\t"
              "ORR R3,R3,#0x1  \n\t"
			  "msr control,R3 \n\t");
        break;

	}

}
