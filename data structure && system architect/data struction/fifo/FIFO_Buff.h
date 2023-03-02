
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

typedef struct {
	unsigned int length;
	unsigned int count;
	element_type* base;
	element_type* head;
	element_type* tail;
}FIFO_Buff_t;

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
