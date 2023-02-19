/*
 * FIFO.h
 *
 *  Created on: Feb 6, 2023
 *      Author: ahmed shaban
 */

#ifndef FIFO_BUFF_H_
#define FIFO_BUFF_H_

#include "stdio.h"
#include "stdint.h"

//User Configuration

//Select the element type (unit8_t,unit16_t, unit32_t,...)
//user configration
#define element_type uint8_t
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
	FIFO_NO_ERROR,               //fifo has no error =0
	FIFO_FULL,                   //fifo is full =1   
	FIFO_EMPTY,                 //fifo is empty =2
	FIFO_NULL                    //fifo not find =3
}FIFO_BUFF_STATUS;

//FIFO APIs 
//funcation make the array as a fifo  tack the argument (the fifo componation ,array, length)
FIFO_BUFF_STATUS FIFO_Init (FIFO_Buff_t* fifo, element_type* buff, uint32_t length);
//funcation push the item to the  a fifo  tack the argument (the fifo componation ,item want to add)
FIFO_BUFF_STATUS FIFO_Enqueue (FIFO_Buff_t* fifo, element_type item);
//funcation pop the item from the  a fifo  tack the argument (the fifo componation , address of the item want to add)
FIFO_BUFF_STATUS FIFO_Dequeue (FIFO_Buff_t* fifo, element_type* item);
//funcation cheak if the fifo is full or not  tack the argument (the fifo componation )
FIFO_BUFF_STATUS FIFO_IS_FULL (FIFO_Buff_t* fifo);
//funcation print the fifo  tack the argument (the fifo componation )
void FIFO_Print (FIFO_Buff_t* fifo);

#endif /* FIFO_BUFF_H_ */             //header protected
