
#include "FIFO_Buff.h"

void main ()
{
	element_type i, temp;
	FIFO_Buff_t FIFO_UART;

	if(FIFO_Init(&FIFO_UART, UART_Buff, 5) == FIFO_NO_ERROR)
		printf("FIFO INIT --------- DONE \n");

	for(i=0; i<7; i++)
	{
		printf("FIFO Enqueue  (%X) \n", i);
		if(FIFO_Enqueue(&FIFO_UART, i) == FIFO_NO_ERROR)
			printf("\t FIFO Enqueue --------- DONE \n");
		else
			printf("\t FIFO Enqueue --------- FAILD \n");
	}

	FIFO_Print(&FIFO_UART);
	if(FIFO_Dequeue(&FIFO_UART, &temp) == FIFO_NO_ERROR)
				printf("\t FIFO Dequeue %X --------- DONE \n", temp);
	if(FIFO_Dequeue(&FIFO_UART, &temp) == FIFO_NO_ERROR)
				printf("\t FIFO Dequeue %X --------- DONE \n", temp);
	FIFO_Print(&FIFO_UART);
}

