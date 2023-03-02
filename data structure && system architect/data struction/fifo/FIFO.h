/*
 * FIFO.h
 *
 *  Created on: Feb 6, 2023
 *      Author: ahmed
 */

#ifndef FIFO_BUFF_H_
#define FIFO_BUFF_H_

#include "stdio.h"
#include "stdint.h"

//User Configuration

//Select the element type (unit8_t,unit16_t, unit32_t,...)
#define element_type uint8_t

//Create Buffer
#define width 5
element_type UART_Buff[width];

//FIFO Data Types


    unsigned int count;             // count of elements in the buffer
    unsigned int length;            // maximum length of the buffer
    element_type* base;             // base address of the buffer
    element_type* head;             // head address of the buffer
    element_type* tail;             // tail address of the buffer
} FIFO_buf_t;                       // define the FIFO buffer struct

typedef enum {
	FIFO_NO_ERROR,
	FIFO_FULL,
	FIFO_EMPTY,
	FIFO_NULL
}FIFO_BUFF_STATUS;

//FIFO APIs
FIFO_BUFF_STATUS FIFO_Init (FIFO_Buff_t* fifo, element_type* buff, uint32_t length);
FIFO_BUFF_STATUS FIFO_Enqueue (FIFO_Buff_t* fifo, element_type item);
FIFO_BUFF_STATUS FIFO_Dequeue (FIFO_Buff_t* fifo, element_type* item);
FIFO_BUFF_STATUS FIFO_IS_FULL (FIFO_Buff_t* fifo);
void FIFO_Print (FIFO_Buff_t* fifo);

#endif /* FIFO_BUFF_H_ */
