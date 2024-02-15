/*
 * scheduler.c
 *
 *  Created on: Dec 7, 2023
 *      Author: Ahmed shaban
 */
#include "scheduler.h"
#include <string.h>
#define NULL ((void *)0)

//================================================================================================================================================
//                                                               ENUMS
//================================================================================================================================================
typedef enum{
	OS_Suspend,
	OS_Running

}OS_state;
typedef enum {
	SVC_Activatetask=0,
	SVC_terminateTask,
	SVC_TaskWaitingTime,
	SVC_AquireMutex,
	SVC_ReleaseMutex
}SVC_ID;

//================================================================================================================================================
//                                                               Structures
//================================================================================================================================================
struct{
	Task_info *os_tasks[20];    //Maxim number of tasks
	uint32_t MSP_Start;
	uint32_t MSP_End;
	uint32_t PSP_locator;      //use to know the address of the end of the task table  to add any new task
	uint32_t num_active_task;
	Task_info* current_task;
	Task_info *next_task;
	OS_state state;

}OS_Control;

//================================================================================================================================================
//                                                               GLobal_variable
//================================================================================================================================================

#include "My_RTOS_FIFO.h"          //put it because complier can not see the FIFO_buf_t
FIFO_buf_t Ready_queue;
Task_info* Ready_queue_FIFO [100];
FIFO_buf_t mutex_queue;
Task_info* mutex_queue_FIFO [100];
Task_info my_idel_task;
//volatile OS_Control OS_configer;
//================================================================================================================================================
//                                                            Local funcation
//================================================================================================================================================
/**=============================================================================================================================================
 * @Fn                   -  OS_GET_Cureent_psp
 * @param [in]           -void
 * @param [out]          -void
 * Note                  - that  funsation can not call from pensv handler

 **///=============================================================================================================================================

void OS_GET_Cureent_psp()
{
	OS_GET_PSP(OS_Control.current_task->current_PSP_posation);
}

/**=============================================================================================================================================
 * @Fn                   -  OS_set_psp
 * @param [in]           -void
 * @param [out]          -void
 * Note                  - that  funsation can not call from pensv handler

 **///=============================================================================================================================================

void OS_set_psp()
{

	OS_set_PSP(OS_Control.current_task->current_PSP_posation);
}

/**=============================================================================================================================================
 * @Fn                    -  PendSV_Handler
 * @brief                 - make context switching and restore
 * @param [in]            -__attribute ((naked))
 * @param [out]           -void
 * Note                   - that handler have priority less than systick and SVC (portrait=15)
 *                        -that function is __attribute ((naked))  mean that compiler can not add any assamply code for return
 *                        - inside that funcation can not  call any funcation  becouse the 	lr value will change and  will  conflect the result
 **///=============================================================================================================================================
__attribute((naked)) void PendSV_Handler()

{
	//====================================
	//Save the Context of the Current Task
	//====================================
	//Get the Current Task "Current PSP from CPU register" after CPU Push XPSR pc lr R0 R1 R2 R3 R12

	//using this current_PSP_posation (Pointer) tp store (R5 to R11)

	//OS_GET_Cureent_psp();
	OS_GET_PSP(OS_Control.current_task->current_PSP_posation);
	OS_Control.current_task->current_PSP_posation-- ;
	__asm volatile("mov %0,r4 " : "=r" (*(OS_Control.current_task->current_PSP_posation))  );
	OS_Control.current_task->current_PSP_posation-- ;
	__asm volatile("mov %0,r5 " : "=r" (*(OS_Control.current_task->current_PSP_posation))  );
	OS_Control.current_task->current_PSP_posation-- ;
	__asm volatile("mov %0,r6 " : "=r" (*(OS_Control.current_task->current_PSP_posation))  );
	OS_Control.current_task->current_PSP_posation-- ;
	__asm volatile("mov %0,r7 " : "=r" (*(OS_Control.current_task->current_PSP_posation))  );
	OS_Control.current_task->current_PSP_posation-- ;
	__asm volatile("mov %0,r8 " : "=r" (*(OS_Control.current_task->current_PSP_posation))  );
	OS_Control.current_task->current_PSP_posation-- ;
	__asm volatile("mov %0,r9 " : "=r" (*(OS_Control.current_task->current_PSP_posation))  );
	OS_Control.current_task->current_PSP_posation-- ;
	__asm volatile("mov %0,r10 " : "=r" (*(OS_Control.current_task->current_PSP_posation))  );
	OS_Control.current_task->current_PSP_posation-- ;
	__asm volatile("mov %0,r11 " : "=r" (*(OS_Control.current_task->current_PSP_posation))  );

	//====================================
	// protecation if the next task =null as a result of two tick occor at the same time make the next task=null
	//====================================
	if (OS_Control.next_task!= NULL)
	{
		OS_Control.current_task = OS_Control.next_task;
		OS_Control.next_task= NULL ;
	}

	else
	{
		while(1);
	}
	//====================================
	//Restore the Context of the Next Task
	//====================================
	__asm volatile("mov r11,%0 " : : "r" (*(OS_Control.current_task->current_PSP_posation))  );
	OS_Control.current_task->current_PSP_posation++ ;
	__asm volatile("mov r10,%0 " : : "r" (*(OS_Control.current_task->current_PSP_posation))  );
	OS_Control.current_task->current_PSP_posation++ ;
	__asm volatile("mov r9,%0 " : : "r" (*(OS_Control.current_task->current_PSP_posation))  );
	OS_Control.current_task->current_PSP_posation++ ;
	__asm volatile("mov r8,%0 " : : "r" (*(OS_Control.current_task->current_PSP_posation))  );
	OS_Control.current_task->current_PSP_posation++ ;
	__asm volatile("mov r7,%0 " : : "r" (*(OS_Control.current_task->current_PSP_posation))  );
	OS_Control.current_task->current_PSP_posation++ ;
	__asm volatile("mov r6,%0 " : : "r" (*(OS_Control.current_task->current_PSP_posation))  );
	OS_Control.current_task->current_PSP_posation++ ;
	__asm volatile("mov r5,%0 " : : "r" (*(OS_Control.current_task->current_PSP_posation))  );
	OS_Control.current_task->current_PSP_posation++ ;
	__asm volatile("mov r4,%0 " : : "r" (*(OS_Control.current_task->current_PSP_posation))  );
	OS_Control.current_task->current_PSP_posation++ ;

	//update PSP  and exit
	//save the current Value of PSP
	//already saved in current_PSP_posation
	OS_set_PSP(OS_Control.current_task->current_PSP_posation);
	//OS_set_psp();
	__asm volatile("BX LR"); //that have value0xfffffffD which mean that take PSP address (thread mode and PSP)
}

/**==========================================================================================================================================================================================================================
 * @Fn                   -  OS_serves
 * @brief                - get the SVC number and then switch to excuse specific event
 * @param [in]           -int *fream_pointer
 * @param [out]          -void
 * Note                  - that function excuse in handler mode
 *                       -
 **///=============================================================================================================================================
void OS_serves(int *fream_pointer)
{
	uint8_t SVC_number=0;
	SVC_number = *((unsigned char*)(((unsigned char*)fream_pointer[6])-2)) ;  //get the event number from the PC/(XPSR) register which save in the stack at posation 7 sub 2 to get SVC number that set by OS_SVC_set
	switch(SVC_number)
	{
	case SVC_Activatetask:
	case SVC_terminateTask:
		//1)update sch table

		OS_updata_scheduler_table();
		if(OS_Control.state==OS_Running)
		{
			if(strcmp( OS_Control.current_task->task_name,"Idel task")!=0)
			{
				//2)update  ready queu
				OS_Decide_What_Next();
				//3)trigger pend sv to make switch context abd restore
				OS_Trigger_pend_SV();
			}
		}

		break;
	case SVC_TaskWaitingTime:
		OS_updata_scheduler_table();
		break;
	case SVC_AquireMutex:
		break;
	case SVC_ReleaseMutex:
		break;
	}
}
/**=============================================================================================================================================
 * @Fn                   -  OS_Decide_What_Next
 * @brief                - decide what task shoud run next
 * @param [in]           -void
 * @param [out]          -void
 * Note                  - in that function still in Handler  mode
 **///=============================================================================================================================================
void OS_Decide_What_Next()
{

	// Check if the ready queue is empty and the current task is not suspended
	//if yes put the current task ( the task run befour update ready queur )in  running mode
	if (Ready_queue.count == 0 && OS_Control.current_task->state != suspend)
	{
		OS_Control.current_task->state = running;
		// Add the current task back to the ready queue (round-robin)
		FIFO_Enqueue(&Ready_queue, OS_Control.current_task);
		// Set the next task to be the current task
		OS_Control.next_task = OS_Control.current_task;
	}
	else
	{
		// Dequeue the next task
		FIFO_Dequeue(&Ready_queue, &OS_Control.next_task);
		OS_Control.next_task->state = running;

		// Update the ready queue (to keep round-robin)
		if ((OS_Control.current_task->task_Priority == OS_Control.next_task->task_Priority) &&
				(OS_Control.current_task->state != suspend))
		{
			// Add the current task back to the ready queue
			FIFO_Enqueue(&Ready_queue, OS_Control.current_task);
			OS_Control.current_task->state = ready;
		}
		//		else
		//		{
		//			// The priorities are different, continue round-robin
		//			OS_Control.current_task->state = running;
		//		}
	}


}
/**=============================================================================================================================================
 * @Fn                   -  OS_SVC_set
 * @brief                - set the supervisor call ID
 * @param [in]           -SVC_ID ID
 * @param [out]          -void
 * Note                  - in that function still in Thread  mode
 **///=============================================================================================================================================
void OS_SVC_set(SVC_ID ID)
{

	switch(ID)
	{
	case SVC_Activatetask:
		__asm("SVC 0x00");
		break;
	case SVC_terminateTask:
		__asm("SVC 0X00");
		break;
	case SVC_TaskWaitingTime:
		__asm("SVC 0X01");
		break;
	case SVC_AquireMutex:
		__asm("SVC 0X02");
		break;
	case SVC_ReleaseMutex:
		__asm("SVC 0X03");
		break;
	}
}

/**=============================================================================================================================================
 * @Fn                   -  my_RTOS_create_main_stack
 * @brief                - PUT the start and the end address of the main stack
 * @param [in]           -void
 * @param [out]          -void
 * Note                  - that function base on the _estack for the SOC  so see the memory map and the linker for your SOC
 **///=============================================================================================================================================

MY_RTOS_Error_ID OS_create_main_stack()
{
	OS_Control.MSP_Start = &_estack;
	OS_Control.MSP_End =OS_Control.MSP_Start-MSP_size;
	OS_Control.PSP_locator=(OS_Control.MSP_End-8);
	if(OS_Control.PSP_locator <=&(_eheap))
	{

		return create_main_stack_error;
		while(1); // excided the SRAM size
	}

}
/**=============================================================================================================================================
 * @Fn                   -  my_RTOS_Create_task_fram
 * @brief                - create stack for the stack (Task_info * task)
 * @param [in]           -*Task_info
 * @param [out]          -void
 * Note                  - pass the task_info as a pointer
 **///=============================================================================================================================================
MY_RTOS_Error_ID OS_Create_task_fram(Task_info * task)
{
	//	task fram
	//	xpsr
	//	pc
	//	lr
	//	R12
	//	R4
	//	R3
	//	R2
	//	R1
	//	R0
	//R5 R6 R7 R8 R9 R10 R11

	task->current_PSP_posation=task->Start_task_address;

	task->current_PSP_posation--;
	//push XPSR register
	*(task->current_PSP_posation)=0x01000000 ;//avoid bus fult by T bit arm cortex m work whit thump2 if that bit is change bus error will occur

	task->current_PSP_posation --;
	//push PC register
	*(task->current_PSP_posation)=(uint32_t)task->task_pointer;

	//push link register LR
	task->current_PSP_posation --;
	*(task->current_PSP_posation) = 0xFFFFFFFD; // 0XFFFFFFFD with excu_return to tread mode and  come from PSP

	//push  r0,r1,r2,r3,r4,r12
	for(char i=0;i<13;i++)
	{
		task->current_PSP_posation --;
		*(task->current_PSP_posation)=0;
	}
	if(task->current_PSP_posation<=&(_eheap))
	{
		return create_task_stack_error;
		while (1);
	}
}
/**=============================================================================================================================================
 * @Fn                   -  idel_task
 * @brief                - ideal task  do nothing  if the user do not enter any task
 * @param [in]           -void
 * @param [out]          -void
 * Note                  _ that task have priority =255
 **///=============================================================================================================================================
uint8_t idel_led;
void idel_task()
{
	while(1)
	{

		idel_led^=1;

		__asm("WFE");
	}
}
/**=============================================================================================================================================
 * @Fn                   -  OS_updata_scheduler_table
 * @brief                - update  scheduler_table for any change occur
 * @param [in]           -void
 * @param [out]          -void
 * Note                  _ that function work in the handler state
 **///=============================================================================================================================================
void OS_updata_scheduler_table()
{
	Task_info* temp=NULL;
	Task_info *F_task;
	Task_info*N_task;
	int counter=0; // if uint32_t will error


	//1)Bubble sort the scheduler_table  base on the priority
	OS_Bubble_sort_scheduler_table();
	//2)dequeue the FIFO TO re_update it
	while(FIFO_Dequeue(&Ready_queue, &temp)!= FIFO_EMPTY); //&temp becouse it pointer to pointer
	//3)update theQueue
	for(counter=0;counter< OS_Control.num_active_task;counter++)
	{
		F_task=OS_Control.os_tasks[counter];
		N_task=OS_Control.os_tasks[counter+1];
		if (F_task->state != suspend)
		{
			//in case we reached to the end of avaliable OS TASKS
			if (N_task->state == suspend)
			{
				FIFO_Enqueue(&Ready_queue,F_task);
				F_task->state = ready ;
				break ;
			}
			//	if the F_task priority > nexttask then (lowest number is meaning higher priority)
			if (F_task->task_Priority < N_task->task_Priority )
			{
				FIFO_Enqueue(&Ready_queue, F_task);
				F_task->state = ready ;
				break ;
			}
			else if (F_task->task_Priority == N_task->task_Priority)
			{
				//	if the F_task task_Priority == nexttask then
				//		push F_task to ready state
				//	And make the F_task = nexttask  and nexttask++
				FIFO_Enqueue(&Ready_queue, F_task);
				F_task->state = ready ;
			}
			//			else if (F_task->task_Priority > N_task->task_Priority)
			//			{
			//				//not allowed to happen as we already reordered it by bubble sort
			//				break ;
			//			}

		}



	}

}
/**=============================================================================================================================================
 * @Fn                   -  OS_Bubble_sort_scheduler_table
 * @brief                - Re_arrangment the scheduler table tasks
 * @param [in]           -MY_RTOS_Error_ID
 * @param [out]          -void
 * Note                  _ that function work in the handler state
 **///=============================================================================================================================================
void  OS_Bubble_sort_scheduler_table()
{
	uint32_t i=0, j =0, n=0;
	Task_info* temp =NULL;
	n = OS_Control.num_active_task ;

	for (i = 0; i < n - 1; i++)
		// Last i elements are already in place
		for (j = 0; j < n - i - 1; j++)
			if (OS_Control.os_tasks[j]->task_Priority > OS_Control.os_tasks[j+1]->task_Priority )
			{
				//Swiping
				temp = OS_Control.os_tasks [j] ;
				OS_Control.os_tasks[j] = OS_Control.os_tasks[j + 1 ] ;
				OS_Control.os_tasks[j + 1] = temp ;
			}

}

/**=============================================================================================================================================
 * @Fn                   -  OS_Update_Task_watting_time
 * @brief                - Update  all fincations that in watting state
 * @param [in]           -void
 * @param [out]          -void
 * Note                  _ that function work in the handler state
 **///=============================================================================================================================================
void OS_Update_Task_watting_time()
{
	for(uint32_t task;task<OS_Control.num_active_task;task++)
	{
		if(OS_Control.os_tasks[task]->state==suspend)
		{
			if(OS_Control.os_tasks[task]->time.state==Enadle)
			{
				OS_Control.os_tasks[task]->time.time--;
				if(OS_Control.os_tasks[task]->time.time==0)
				{
					OS_Control.os_tasks[task]->time.state=Disable;
					OS_Control.os_tasks[task]->state=watting;
					OS_SVC_set(SVC_TaskWaitingTime);
				}

			}

		}

	}

}
//==============================================================================================================================================
//                                                               APIS implemation
//==============================================================================================================================================
/**=============================================================================================================================================
 * @Fn                   -  MY_RTOS_init
 * @brief                - deinitialize the OS
 * @param [in]           -NULL
 * @retval               - MY_RTOS_Error_ID
 * Note                  - shoud put the FIFO lenght base in number of tass
 **///==========================================================================================================================================
MY_RTOS_Error_ID MY_RTOS_init(void)
{


	MY_RTOS_Error_ID error=no_error;

	//put OS in Suspend state
	OS_Control.state=OS_Suspend;
	//main stack confeger
	error+=OS_create_main_stack( );
	//FIFO INIT
	if(FIFO_Init(&Ready_queue,Ready_queue_FIFO, 30) !=FIFO_NO_ERROR)
		error +=FIFO_error; //+=        if have more than one error
	if(FIFO_Init(&mutex_queue,mutex_queue_FIFO, 30) !=FIFO_NO_ERROR)
		error +=FIFO_error; //+=        if have more than one error

	strcpy(my_idel_task.task_name,"Idel task");
	my_idel_task.task_Priority=255; //the lowest Priority
	my_idel_task.task_pointer=idel_task; //idel task entry

	my_idel_task.task_size=500;
	error+= MY_RTOS_Create_task(&my_idel_task);



	return error;


}
/**=============================================================================================================================================
 * @Fn                   -  MY_RTOS_Create_task
 * @brief                - OS crate task
 * @param [in]           -task
 * @retval               - MY_RTOS_Error_ID
 * Note                  - null
 **///=============================================================================================================================================
MY_RTOS_Error_ID MY_RTOS_Create_task(Task_info *task)
{

	MY_RTOS_Error_ID error=no_error;

	task->Start_task_address=OS_Control.PSP_locator;
	task->End_task_address=task->Start_task_address-task->task_size;
	//check if the stack size exceed heep size
	if(task->End_task_address <(uint32_t)(&(_eheap)))
	{

		error+=create_task_error;
		while(1);
	}
	//aligned 8 byte between tasks
	OS_Control.PSP_locator=task->End_task_address-8;
	//create task fream  to manage task to make switch context
	error+=OS_Create_task_fram(task);
	//put the task in schaduler table
	OS_Control.os_tasks[OS_Control.num_active_task]=task;
	OS_Control.num_active_task++;
	//put the task in suspend state
	task->state=suspend;



	return error;

}
/**=============================================================================================================================================
 * @Fn                   -  MY_RTOS_Activat_task
 * @brief                - Put the task in wetting state
 * @param [in]           -Task_info* task
 * @param [out]          -MY_RTOS_Error_ID
 * Note                  - that function use Supervisor call interrupt
 **///=============================================================================================================================================
MY_RTOS_Error_ID MY_RTOS_Activat_task(Task_info* task)

{
	MY_RTOS_Error_ID error=0;
	error=no_error;
	//put the task in watting state
	task->state =watting;
	//svc  requset
	OS_SVC_set(SVC_Activatetask);
	return error;


}
/**=============================================================================================================================================
 * @Fn                   -  MY_RTOS_Terminate_task
 * @brief                - Put the task in suspend state
 * @param [in]           -Task_info* task
 * @param [out]          -MY_RTOS_Error_ID
 * Note                  - that function use Supervisor call interrupt
 **///===========================================================================================================================================
MY_RTOS_Error_ID MY_RTOS_Terminate_task(Task_info* task)

{
	MY_RTOS_Error_ID  error=no_error;
	task->state =suspend;
	OS_SVC_set(SVC_terminateTask);
	return  error;

}


/**=============================================================================================================================================
 * @Fn                   -  MY_RTOS_Start
 * @brief                - starting schaduling tasks
 * @param [in]           -void
 * @param [out]          -MY_RTOS_Error_ID
 * Note                  -OS run idel_task as a defult task
 **///===========================================================================================================================================
MY_RTOS_Error_ID MY_RTOS_Start()
{
	MY_RTOS_Error_ID error=no_error;

	//put OS in Running stste
	OS_Control.state=OS_Running;
	//PUT current_task point to  idel task
	OS_Control.current_task=&my_idel_task;
	//Activat idel task
	error+=MY_RTOS_Activat_task(&my_idel_task);
	//start periodic interrput each 1mms
	HW_Start_Systic();
	OS_set_PSP(OS_Control.current_task->current_PSP_posation);
	//switching to PSP
	OS_switch_TO_PSP();
	//switching to unPrivileged state
	unPrivileged_acces_leavel() ;
	//go to the entery og the idel task
	my_idel_task.task_pointer();

	return error;
}
/**=============================================================================================================================================
 * @Fn                   -  MY_RTOS_watting
 * @brief                - wating spasicic task for spasific time
 * @param [in]           -uint32_t time,Task_info* task
 * @param [out]          -MY_RTOS_Error_ID
 * Note                  -
 **///===========================================================================================================================================
MY_RTOS_Error_ID MY_RTOS_watting(uint32_t time,Task_info* task)
{
	MY_RTOS_Error_ID error=no_error;
	task->time.state=Enadle;
	task->time.time=time;

	task->state=suspend;
	OS_SVC_set(SVC_terminateTask);

	return error;

}
/**=============================================================================================================================================
 * @Fn                   -  MY_RTOS_Acquire_mutex
 * @brief                -  acquired spasific  mutex to the spasific task
 * @param [in]           -mutex_info *mutex
 * @param [in]           -Task_info* task
 * @param [out]          -MY_RTOS_Error_ID
 * Note                  -
 **///===========================================================================================================================================
MY_RTOS_Error_ID MY_RTOS_Acquire_mutex(mutex_info *mutex,Task_info* task)
{
	MY_RTOS_Error_ID error=no_error;

	if(mutex->current_user==NULL)
	{
		mutex->current_user=task;

	}
	else
	{
		if(mutex->next_user==NULL)
		{
			mutex->next_user=task;
			task->state=suspend;
			OS_SVC_set(SVC_terminateTask);
		}
		else
		{
			error=FIFO_Enqueue(&mutex_queue, task);
			task->state=suspend;
			OS_SVC_set(SVC_terminateTask);
			if(mutex->current_user==mutex_queue.count)
			{
				error=Aquired_mutex_reched_max_number_of_user_error;
			}
		}
	}

	return error;

}
/**=============================================================================================================================================
 * @Fn                   -  MY_RTOS_Release_mutex
 * @brief                - relaese a spasific   mutex
 * @param [in]           -mutex_info *mutex
 * @param [out]          -MY_RTOS_Error_ID
 * Note                  -
 **///===========================================================================================================================================
MY_RTOS_Error_ID MY_RTOS_Release_mutex(mutex_info* mutex)
{
	MY_RTOS_Error_ID error=no_error;
	if(mutex->current_user!=NULL)
	{


		error=FIFO_Dequeue(&mutex_queue, &mutex->next_user);
		mutex->current_user=mutex->next_user;
		//	mutex->next_user=NULL;
		mutex->current_user->state=watting;
		OS_SVC_set(SVC_Activatetask);


	}

	return error;



}
