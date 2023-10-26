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


#include "stm32f103x6.h"
//#include "stm32f103c6_cortex_m3_core.h"
#include "stm32f103c6_GPIO_drivers.h"
#include "stm32f103c6_EXTI_drivers.h"
#define  OS_set_PSP(address)                  __asm volatile ("mov r0,%0 \n\t msr PSP,r0 \n\t": :"r"(address));
#define  OS_switch_TO_PSP()     		      __asm volatile("mrs R3,control \n\t mov R1,#0X2 \n\t  ORR R1,R1,R3 \n\t  msr control,R1 \n\t");
#define   OS_switch_TO_MSP()                  __asm volatile("mrs R9,control \n\t mov R10,#0X0  \n\t and R10,R10,R9  \n\t msr control,R10 \n\t");
#define  Privileged_acces_leavel              __asm volatile("mrs R3,control \n\t  BIC R3, R3, #1  \n\t   MSR CONTROL,R3  \n\t")
#define  unPrivileged_acces_leavel            __asm volatile("mrs R3,control \n\t  ORR R3,R3,#0x1   \n\t  msr control,R3   \n\t")
#define  os_Genrat_int                        __asm volatile("SVC #0X03");
#define  task_A_stack_size 100
#define  task_B_stack_size 100
enum  user_level {Privileged,UnPrivileged};
void swich_CPU_access_user_level(enum user_level level)
{

	switch(level)
	{
	case Privileged :
		__asm("mrs R3,control \n\t"
				"BIC R3, R3, #1\n\t"
				"MSR CONTROL, R3\n\t"
		);
		break;
	case UnPrivileged:

		__asm("mrs R3,control \n\t"
				"ORR R3,R3,#0x1  \n\t"
				"msr control,R3 \n\t");
		break;

	}

}
uint32_t flag ,taskA_flag,taskB_flag;
extern uint32_t _estack;

    //main stack size
uint32_t __S_MSP= &_estack;
uint32_t __E_MSP;
     //PSP  task A size

uint32_t __S_PSP_Task_A;
uint32_t __E_PSP_Task_A;
     //PSP  task B size

uint32_t __S_PSP_Task_B;
uint32_t __E_PSP_Task_B;

void main_OS(void)
{
	// MSP end
__E_MSP=__S_MSP - 512;
	//tasK A PSP
__S_PSP_Task_A=__E_MSP - 8;
__E_PSP_Task_A=__S_PSP_Task_A-100;
	//task B  PSP
__S_PSP_Task_B=__E_PSP_Task_A-8;
__E_PSP_Task_B=__S_PSP_Task_B-100;


	while(1)
	{
   __asm("nop");
   if(taskA_flag==1)
   {
	   //set PSP register -> __S_PSP_Task_A
 OS_set_PSP(__S_PSP_Task_A);
	   //SP -> PSP
  OS_switch_TO_PSP();
	   //switch between Privileged >>>>>unPrivileged
  unPrivileged_acces_leavel ;

 taskA_flag=Task_A(1,2,3) ;
	   //switch between unPrivileged >>>>>Privileged
 os_Genrat_int;
	   //SP -> MSP
 OS_switch_TO_MSP() ;
   }
 else if(taskB_flag==1)
   {
	   //set PSP register -> __S_PSP_Task_B
 OS_set_PSP(__S_PSP_Task_B);
	   //SP -> PSP
 OS_switch_TO_PSP();
	   //switch between Privileged >>>>>unPrivileged
 unPrivileged_acces_leavel ;
 taskB_flag=  Task_B(2,5,2);
	   //switch between unPrivileged >>>>>Privileged
 os_Genrat_int;
	   //SP -> MSP
OS_switch_TO_MSP() ;

   }

	}

}
int Task_A(int a ,int b, int c)
{

     return a+b+c;
}
int Task_B(int a ,int b, int c)
{
    return a+b+c;
}

void EXTI9B_Callback (void)
{
	if(flag==0)
	{
		taskA_flag=1;
		flag=1;
	}
	else if(flag==1)
	{
		taskB_flag=1;
		flag =0;
	}
}
void clock_init()
{
GPIOA_clock_enable();
GPIOB_clock_enable();
AFIO_clock_enable();

}
void HardFault_Handler()
{
}
void MemManage_Handler()
{

}
void BusFault_Handler()
{

}
void UsageFault_Handler()
{

}
void SVC_Handler()
{

	Privileged_acces_leavel ;
}
int main(void)
{
	//if make  UnPrivileged befor EXTI INIT  Tthe cpu can not have access to NVIC and can not make eny enterrput
	//swich_CPU_access_user_level(UnPrivileged);
clock_init();
EXIT_Confing_t confuger;
confuger.EXIT_Pin= EXTI9B9;
confuger.trigger_case= EXIT_Rising ;

confuger.p_IRQ_Callback = EXTI9B_Callback;
confuger.IRQ_define=EXIT_IRQ_enable;
MCAL_EXTI_GPIO_INIT(&confuger);
main_OS();
	flag=1;


	while(1)
	{
		if(flag)
	{
			flag=0;
	}
		else
    {

	}
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
