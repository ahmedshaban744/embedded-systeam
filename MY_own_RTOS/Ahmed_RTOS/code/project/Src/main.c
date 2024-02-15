/*

 ******************************************************************************
 * @file           : main.c
 * @author         : Ahmed shaban mohamed
 * @brief          : Main program body
 ******************************************************************************

 *
 ******************************************************************************
 */
//Includes ------------------------------------------------------------------*/

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif
#include "stm32f103c6_GPIO_drivers.h"
#include "stm32f103c6_EXTI_drivers.h"
#include "stm32f103c6_I2C_drivers.h"
#include  "stm32f103c6_RCC_drivers.h"
#include "stm32f103c6_SPI_drivers.h"
#include "stm32f103c6_USART_drivers.h"
#include "stm32f103x6.h"
#include "core_cm3.h"
#include "scheduler.h"
void clock_init()
{
	GPIOA_clock_enable();
	GPIOB_clock_enable();
	AFIO_clock_enable();
}
Task_info task1, task2,task3,task4;
uint8_t task1_led,task2_led,task3_led,task4_led;
mutex_info mutex1,mutex2;
int8_t array[3]={1 ,2,3};
int8_t array2[3]={1 ,2,3};

void taskfun1()
{
	static uint32_t count1=0;
	while(1)
	{
		task1_led^=1;
		//MY_RTOS_watting(100, &task1);
		count1++;
		if(count1==100)
		{
		MY_RTOS_Acquire_mutex(&mutex1, &task1);
		MY_RTOS_Activat_task(&task4);
		MY_RTOS_Acquire_mutex(&mutex2, &task1);
	}
	if(count1==200)
	{
		count1=0;
		MY_RTOS_Release_mutex(&mutex1);
	}
}
}
void taskfun2()
{
	static uint32_t count2=0;
	while(1)
	{
		task2_led^=1;
		count2++;
		if(count2==100)
		{
			MY_RTOS_Activat_task(& task3);
		}
		if(count2==200)
		{
			count2=0;
			MY_RTOS_Terminate_task(&task2);

		}
	}
}
void taskfun3()
{
	static uint32_t count3=0;
	while(1)
		{
			task3_led^=1;
		//	MY_RTOS_watting(100, &task2);
			count3++;
			if(count3==100)
			{
				MY_RTOS_Activat_task(&task4);

			}
			if(count3==200)
			{
				count3=0;
				MY_RTOS_Terminate_task(&task3);
			}
		}
}
void taskfun4()
{
	static uint32_t count4=0;
	while(1)
		{
			task4_led^=1;

			count4++;
			if(count4==3)
			{
			MY_RTOS_Acquire_mutex(&mutex2, &task4);
			MY_RTOS_Acquire_mutex(&mutex1, &task4);
			}
			if(count4==200)
			{
			count4=0;
	        MY_RTOS_Release_mutex(&mutex1);
			MY_RTOS_Terminate_task(&task4);
			}
		}
}


int   main(void)
{
	MY_RTOS_Error_ID error;
	// MY_RTOS_Error_ID error;
	Hardware_init ();
	if( MY_RTOS_init() != no_error)
   mutex1.Resource_size=3;
	mutex1.number_of_user =3;
	mutex1.Resource=array;
	strcpy(mutex1.mutex_name,"shared_data");

	   mutex1.Resource_size=3;
		mutex1.number_of_user =3;
		mutex1.Resource=array2;
		strcpy(mutex1.mutex_name,"shared_data1");

	task1.task_size=1024;
	task1.task_Priority=4;
	task1.task_pointer=taskfun1;
	strcpy(task1.task_name,"task_1");

	task2.task_size=1024;
	task2.task_Priority=3;
	task2.task_pointer=taskfun2;
	strcpy(task2.task_name,"task_2");

	task3.task_size=1024;
	task3.task_Priority=2;
	task3.task_pointer=taskfun3;
	strcpy(task3.task_name,"task_3");

	task4.task_size=1024;
	task4.task_Priority=1  ;
	task4.task_pointer=taskfun4;
	strcpy(task3.task_name,"task_4");

	error+=MY_RTOS_Create_task(&task1);
	error+=MY_RTOS_Create_task(&task2);
	error+=MY_RTOS_Create_task(&task3);
	error+=MY_RTOS_Create_task(&task4);

    error+=MY_RTOS_Activat_task(& task1);
//	error+=MY_RTOS_Activat_task(& task2);
//	error+=MY_RTOS_Activat_task(& task3);
//	error+=MY_RTOS_Activat_task(& task4);
	MY_RTOS_Start();




	while(1)
	{

	}
	return 0;
}
#ifdef  USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t *file, uint32_t line)
{
	/* USER CODE BEGIN 6 */
	/* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
	/* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
