#include "LIFO.h"
#include "stdio.h"
#include "stdlib.h"

LIFO_Buffer_t LIFO_UART;                          //define a static LIFO UART  	globeal array stor in RAM
#define LIFO_buffer_length 5                     //define an array
LIFO_t buf[LIFO_buffer_length] , temp ;         

int main()
{
	LIFO_INIT( &LIFO_UART , buf , LIFO_buffer_length );

	//padding LIFO UART Buffer by its values
	for( int i=0 ; i<5 ; i++ )
	{
		LIFO_PUSH( &LIFO_UART , i );
	}

	printf ("LIFO UART Buffer: \n");
	for( int i=0 ; i<5 ; i++)

		printf("\t  uart_lifo_  %x \t \n ",i);





	for( int i=0 ; i<5 ; i++ )
	{
		LIFO_POP( &LIFO_UART , &temp );
		printf (" =====lifo====%d\n", temp ) ;
	}
}
