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
void  OS_serves(int *fream_pointer)
{

uint32_t val1,val2;
uint8_t SVC_number;
SVC_number =    *((unsigned char*)(((unsigned char*)fream_pointer[6])-2));
val1= fream_pointer[0];
val2= fream_pointer[1];
switch(SVC_number)
{
case 1:
	fream_pointer[0]=val1+val2;
	break;

case 2:
	fream_pointer[0]=val1-val2;
	break;
case 3:
	fream_pointer[0]=val1*val2;
	break;
}
}
__attribute ((nacked))  void SVC_Handler()
{
__asm("tst lr,#4 \n\t"
		"ITE EQ \n\t"
		"mrseq r0,msp \n\t"
	    "mrsne r0,psp \n\t"
		"b OS_serves");
}

uint32_t OS_SVC_set(int a,int b,int ID)
{
uint32_t result;
switch(ID)
{
case 1:

	__asm("SVC 0x1");
	break;

case 2:
	__asm("SVC 0X2");
	break;
case 3:
	__asm("SVC 0X3");
	break;

}
return result;
}
int   main(void)
{
//	//if make  UnPrivileged befor EXTI INIT  Tthe cpu can not have access to NVIC and can not make eny enterrput
//	//swich_CPU_access_user_level(UnPrivileged);
clock_init();
//EXIT_Confing_t confuger;
//confuger.EXIT_Pin= EXTI9B9;
//confuger.trigger_case= EXIT_Rising ;
//
//confuger.p_IRQ_Callback = EXTI9B_Callback;
//confuger.IRQ_define=EXIT_IRQ_enable;
//MCAL_EXTI_GPIO_INIT(&confuger);
//main_OS();

flag=1;
flag=OS_SVC_set(1,2,1);
flag=OS_SVC_set(3,8,2);
flag=OS_SVC_set(4,7,3);

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
