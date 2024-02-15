/*
 * My_RTOS_FIFO.h
 *
 *  Created on: Dec 7, 2023
 *      Author: Ahmed shaban
 */

#ifndef INC_MY_RTOS_FIFO_H_
#define INC_MY_RTOS_FIFO_H_
#include "scheduler.h"
//Select the element type (unit8_t,unit16_t, unit32_t,...)
#define element_type Task_info*

typedef struct {
    element_type* base;             // base address of the buffer
    element_type* head;             // head address of the buffer
    element_type* tail;             // tail address of the buffer
    uint32_t count;             // count of elements in the buffer
    uint32_t length;            // maximum length of the buffer
}FIFO_buf_t;                       // define the FIFO buffer struct

typedef enum {
	FIFO_NO_ERROR,
	FIFO_FULL,
	FIFO_EMPTY,
	FIFO_NULL
}FIFO_BUFF_STATUS;

FIFO_BUFF_STATUS FIFO_Init    (FIFO_buf_t* fifo, element_type* buff, uint32_t length);
FIFO_BUFF_STATUS FIFO_Enqueue (FIFO_buf_t* fifo, element_type item);
FIFO_BUFF_STATUS FIFO_Dequeue (FIFO_buf_t* fifo, element_type* item);
FIFO_BUFF_STATUS FIFO_IS_FULL (FIFO_buf_t* fifo);




#endif /* INC_MY_RTOS_FIFO_H_ */
