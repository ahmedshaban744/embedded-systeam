#include "LIFO.h"

LIFO_Status LIFO_INIT( LIFO_Buffer_t* LIFO_buf , LIFO_t* buf , unsigned int length)
{
	//check if LIFO buffer is exist
	if ( buf == NULL)
		return LIFO_NULL ;

	LIFO_buf->Base = buf ;                    //make the base refre to the start of the arrray
	LIFO_buf->head = buf ;                   //make the base refre to the start of the arrray
	LIFO_buf->length = length ;              
	LIFO_buf->count = 0 ;
	return LIFO_NO_ERROR ;
}

LIFO_Status LIFO_PUSH( LIFO_Buffer_t* LIFO_buf , LIFO_t item )
{
	//check if LIFO buffer is exist
	if ( !LIFO_buf->head || !LIFO_buf->Base )
		return LIFO_NULL ;

	//check if LIFO buffer is full
	if ( LIFO_buf->count == LIFO_buf->length )
		return LIFO_FULL ;

	*(LIFO_buf->head) = item ;                      // push the item to the head
	LIFO_buf->head++ ;                              //increment the head 
	LIFO_buf->count++;                              //increment the count 
	return LIFO_NO_ERROR ;
}

LIFO_Status LIFO_POP ( LIFO_Buffer_t* LIFO_buf , LIFO_t* item )
{
	//check if LIFO buffer is exist
	if ( !LIFO_buf->head || !LIFO_buf->Base )
		return LIFO_NULL ;

	//check if LIFO buffer is empty
	if ( LIFO_buf->count == 0 )
			return LIFO_EMPTY ;

	LIFO_buf->head-- ;                           // decrement the head 
	*item = *(LIFO_buf->head) ;                   // pop the item to the temp
	LIFO_buf->count--;                            // decrement the count 
	return LIFO_NO_ERROR ;
}
