#include "FIFO_Buff.h"

//FIFO APIs
FIFO_BUFF_STATUS FIFO_Init (FIFO_Buff_t* fifo, element_type* buff, uint32_t length)
{
	if(buff == NULL)
		return FIFO_NULL;

	fifo->base = buff;
	fifo->head = buff;
	fifo->tail = buff;
	fifo->length = length;
	fifo->count = 0;

	return FIFO_NO_ERROR;
}

FIFO_BUFF_STATUS FIFO_Enqueue (FIFO_Buff_t* fifo, element_type item)
{
	//Check if the FIFO Exists
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_NULL;
	//Check if the FIFO is Full
	if (FIFO_IS_FULL(fifo) == FIFO_FULL)
		return FIFO_FULL;

	*(fifo->head) = item;
	fifo->count++;

	//Circular FIFO
	if(fifo->head == (fifo->base + (fifo->length * sizeof(element_type))))
		fifo->head = fifo->base;
	else
		fifo->head++;

	return FIFO_NO_ERROR;

}
FIFO_BUFF_STATUS FIFO_Dequeue (FIFO_Buff_t* fifo, element_type* item)
{
	//Check if the FIFO Exists
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_NULL;
	//Check if the FIFO is Empty
	if(fifo->count == 0)
		return FIFO_EMPTY;

	*item = *(fifo->tail);
	fifo->count--;

	//Circular FIFO
		if(fifo->tail == (fifo->base + (fifo->length * sizeof(element_type))))
			fifo->tail = fifo->base;
		else
			fifo->tail++;

		return FIFO_NO_ERROR;

}
FIFO_BUFF_STATUS FIFO_IS_FULL (FIFO_Buff_t* fifo)
{
	//Check if the FIFO Exists
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_NULL;
	if(fifo->count == fifo->length)
		return FIFO_FULL;
	return FIFO_NO_ERROR;
}
void FIFO_Print (FIFO_Buff_t* fifo)
{
	int i;
	element_type* temp;

	if(fifo->count == 0)
	{
		printf("FIFO Is Empty \n");
	}
	else
	{
		temp = fifo->tail;
		printf("\n ===========FIFO_Print========= \n");
		for(i=0; i<fifo->count; i++)
		{
			printf("\t %X \n", *temp);
			temp++;
		}
		printf("=========================== \n");
	}

}
