
#ifndef LIFO_H_            //header protected
#define LIFO_H_            //header protected
#include "stdio.h"

//define typedef of LIFO and LIFO status
typedef unsigned int  LIFO_t ;
//LIFO componation

typedef struct{
	LIFO_t* Base ;                   //pointer refer to the start of the  array
	LIFO_t* head ;                   //pointer used to push or pop item from the buffer
	unsigned int count ;
	unsigned int length ;
}LIFO_Buffer_t;
//lifo statous
typedef enum {
		LIFO_EMPTY,                 //lifo if empty
		LIFO_FULL,                 //lifo is full
		LIFO_NULL,                //lifo  is not find
		LIFO_NO_ERROR            //lifo have no error 
}LIFO_Status;

//APIS
LIFO_Status LIFO_INIT( LIFO_Buffer_t* LIFO_buf , LIFO_t* buf , unsigned int length);           //make the buffer take argument (LIFO componation , buffer(array) , lengthof the array) 
LIFO_Status LIFO_PUSH( LIFO_Buffer_t* LIFO_buf , LIFO_t item );                               //add itam to the biffer take argument (LIFO componation , atem that want to add) 
LIFO_Status LIFO_POP ( LIFO_Buffer_t* LIFO_buf , LIFO_t* item );                             //get item to the buffer take argument (LIFO componation  , address of the atem that want to add) 


#endif /* LIFO_H_ */         //header protected
