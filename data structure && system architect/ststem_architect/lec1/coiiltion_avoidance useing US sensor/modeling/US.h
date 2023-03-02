#ifndef US_H_       //header protection
#define US_H_       //header protection
#include "state.h"
//Define States by use enumeration
/*
 enum {
	US_busy ,      //state 1 busye state

}US_state_id ;
 */

void US_inte();            //funcation that initation the US driver
void US_busy2();       //funcation that make the US go
//STATE Pointer to Function (extern to be readable in main function)
extern void (*US_state )();

#endif /* US_H_ */   //header protection
