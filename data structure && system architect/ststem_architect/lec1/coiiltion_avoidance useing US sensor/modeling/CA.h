#ifndef CA_H_       //header protection
#define CA_H_       //header protection
#include "state.h"
//Define States by use enumeration
/*
 enum {
	CA_waiting,       //state 1 waiting state
	CA_driving         //state 2 driving state
}CA_state_id;
 */

void state_wating(void);        //prototype of the waiting function
void state_driving(void);      //prototype of the CA_driving function
//STATE Pointer to Function (extern to be readable in main function)
extern void (*CA_state )();

#endif /* CA_H_ */   //header protection
