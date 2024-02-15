/*
 * My_RTOS_FIFO.c
 *
 *  Created on: Dec 7, 2023
 *      Author: Ahmed shaban
 */
#include "My_RTOS_FIFO.h"
#define NULL ((void *)0)

FIFO_BUFF_STATUS FIFO_Init    (FIFO_buf_t* fifo, element_type* buff, uint32_t length)
{
	if(buff == NULL)
		return FIFO_NULL;

	fifo->base = buff;
	fifo->head = fifo->base ;
	fifo->tail = fifo->base ;
	fifo->length = length;
	fifo->count = 0;

	return FIFO_NO_ERROR;
}
/**=============================================================================================================================================
 * @Fn                   -  FIFO_Enqueue
 * @brief                - put the  ready tasks in the ready queu
 * @param [in]           -*Task_info
 * @param [in]           -*item
 * @param [out]          -void
 * Note                  -null
 **///=============================================================================================================================================
FIFO_BUFF_STATUS FIFO_Enqueue (FIFO_buf_t* fifo, element_type item)
{
	//Check if the FIFO Exists
	if(!fifo->base || !fifo->length)
		return FIFO_NULL;
	//Check if the FIFO is Full
	//if (FIFO_IS_FULL(fifo) == FIFO_FULL)
	if ((fifo->head == fifo->tail) && (fifo->count == fifo->length))
		return FIFO_FULL;

	*(fifo->tail) = item;
	fifo->count++;

	//Circular FIFO
	if(fifo->tail == (((uint32_t)fifo->base + (4*fifo->length )) - 4 ))
		fifo->tail = fifo->base;
	else
		//fifo->head++;
		fifo->tail++;
	return FIFO_NO_ERROR;

}
/**=============================================================================================================================================
 * @Fn                   -  FIFO_Dequeue
 * @brief                - empty the ready queu from the task to re ordwe it again )
 * @param [in]           -*Task_info
 * @param [in]           -*item
 * @param [out]          -void
 * Note                  - that funcation do not  delelat the task from the ready queu  but overwrite the old tasks to the news tasks
 **///=============================================================================================================================================
FIFO_BUFF_STATUS FIFO_Dequeue (FIFO_buf_t* fifo, element_type* item)
{
	//Check if the FIFO Exists
	if(!fifo->base || !fifo->length )
		return FIFO_NULL;
	//Check if the FIFO is Empty
	if (fifo->head == fifo->tail)
		return FIFO_EMPTY;

	*item = *(fifo->head);
	fifo->count--;

	//Circular FIFO
	if(fifo->head == (((uint32_t)fifo->base + (4*fifo->length )) - 4 ))
		fifo->head = fifo->base;
	else
		fifo->head++;
	//fifo->head--;

	return FIFO_NO_ERROR;

}
FIFO_BUFF_STATUS FIFO_IS_FULL (FIFO_buf_t* fifo)
{
	//Check if the FIFO Exists
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_NULL;
	if(fifo->count == fifo->length)
		return FIFO_FULL;
	return FIFO_NO_ERROR;
}
