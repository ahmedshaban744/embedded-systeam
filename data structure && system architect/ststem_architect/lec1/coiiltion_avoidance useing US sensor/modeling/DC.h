#ifndef DC_H_       //header protection
#define DC_H_       //header protection
#include "state.h"
//Define States by use enumeration
/*enum {
	DC_idle,          //state 1 busye state
	DC_busy1         //state 2 driving state
}DC_state_id;*/
void DC_init();   //funcation that initation the motor driver
void DC_idel();   //funcation that make the motor stop
void  DC_busy();  //funcation that make the motor go

//STATE Pointer to Function (extern to be readable in main function)
extern void (*DC_state )();

#endif /* DC_H_ */   //header protection
