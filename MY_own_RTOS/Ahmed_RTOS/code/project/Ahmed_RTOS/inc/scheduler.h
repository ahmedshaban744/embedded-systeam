/*
 * scheduler.h
 *
 *  Created on: Dec 7, 2023
 *      Author: Ahmed shaban
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include "cortex_mx_porting.h"
//#include "My_RTOS_FIFO.h"   //IF include it will make infinite paraphrasing and the files will lock each anther
//================================================================================================================================================
//                                                               ENUMS
//================================================================================================================================================
//that enum important in debugging
typedef enum {
	no_error,
	FIFO_error,
	create_main_stack_error,
	create_task_stack_error,
	create_task_error,
	SVC_not_find_error,
	Bubble_sort_error,
	Aquired_mutex_reched_max_number_of_user_error,
	Released_mutex_error



}MY_RTOS_Error_ID;

typedef enum {
	suspend,
	watting,
	ready,
	running

}task_state;
typedef enum{Enadle,Disable}blocking;

//================================================================================================================================================
//                                                               Structures
//================================================================================================================================================
typedef struct {
	blocking state;
	uint32_t time;    // time in MMS
} time_out;

typedef struct
{
	uint8_t task_name[30];
	uint32_t task_size   ;
	uint8_t task_Priority;
	uint32_t Start_task_address;         //not enter by the user
	uint32_t End_task_address;          //not enter by the user
	uint32_t *current_PSP_posation;    //not enter by the user
	task_state state;
	time_out time;
	void(*task_pointer)(void);      //pointer to the entry of the C funcation of the task
}Task_info;



typedef struct
{
	uint8_t mutex_name[30];
	uint32_t * Resource;
	uint32_t Resource_size;
	uint8_t  number_of_user;
	Task_info* current_user;
	Task_info* next_user;

}mutex_info;


//================================================================================================================================================
//                                                               APIS
//================================================================================================================================================
MY_RTOS_Error_ID MY_RTOS_init(void);
MY_RTOS_Error_ID MY_RTOS_Create_task(Task_info* task);
MY_RTOS_Error_ID MY_RTOS_Activat_task(Task_info* task);
MY_RTOS_Error_ID MY_RTOS_Terminate_task(Task_info* task);
MY_RTOS_Error_ID MY_RTOS_Start();
MY_RTOS_Error_ID MY_RTOS_watting(uint32_t time,Task_info* task);
MY_RTOS_Error_ID MY_RTOS_Acquire_mutex(mutex_info *mutex,Task_info* task);
MY_RTOS_Error_ID MY_RTOS_Release_mutex(mutex_info* mutex);



#endif /* INC_SCHEDULER_H_ */
