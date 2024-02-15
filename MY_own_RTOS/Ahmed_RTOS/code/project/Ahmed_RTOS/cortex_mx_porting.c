/*
 * cortex_mx_porting.c
 *
 *  Created on: Dec 7, 2023
 *      Author: Ahmed shaban
 */
#include "cortex_mx_porting.h"




/**=============================================================================================================================================
 * @Fn                   -  HardFault_Handler
 * @brief                - stuck the CPU if HardFault occour
 * @param [in]           -void
 * @param [out]          -void
 * Note                  -handler mode
**///===========================================================================================================================================
  void HardFault_Handler(void)
  {
	  while(1);
  }


/**=============================================================================================================================================
   * @Fn                   -  MemManage_Handler
   * @brief                - stuck the CPU if Memory  fault occour
   * @param [in]           -void
   * @param [out]          -void
   * Note                  -handler mode
  **///===========================================================================================================================================
  void	MemManage_Handler (void)
  {
	  while(1);
  }
  //=======================================================================================================================================================

  /**=============================================================================================================================================
   * @Fn                   -  BusFault_Handler
   * @brief                - stuck the CPU if Bus Fault occour
   * @param [in]           -void
   * @param [out]          -void
   * Note                  -handler mode
  **///===========================================================================================================================================
  void	BusFault_Handler (void)
  {
	  while(1);
  }
  //=======================================================================================================================================================

  /**=============================================================================================================================================
   * @Fn                   -  UsageFault_Handler
   * @brief                - stuck the CPU if UsageFault occour
   * @param [in]           -void
   * @param [out]          -void
   * Note                  -handler mode
  **///===========================================================================================================================================
  void	UsageFault_Handler (void)
  {
	  while(1);
  }
  //=======================================================================================================================================================

  /**=============================================================================================================================================
   * @Fn                   -  Reset_Handler
   * @brief                -for make switching context
   * @param [in]           -void
   * @param [out]          -void
   * Note                  -handler mode
  **///===========================================================================================================================================
//  void Reset_Handler()
//  {
//	while(1);
//
//  }
  /**=============================================================================================================================================
   * @Fn                   -  SVC_Handler
   * @brief                - use for make supervisor calling
   * @param [in]           -void
   * @param [out]          -void
   * Note                  -__attribute ((nacked)) mean the cpmpiler can not add any assimbly for return or exict the funcation
   *                       -use to ask spasific request
   *                       -first know from where the request is come handler or thread mode  then  jump to  OS_serves to handle the request
  **///===========================================================================================================================================

  __attribute__((naked)) void SVC_Handler()
  {
  __asm("tst lr,#4 \n\t"
  		"ITE EQ \n\t"
  		"mrseq r0,msp \n\t"
  	    "mrsne r0,psp \n\t"
  		"B OS_serves");
  }
  /**=============================================================================================================================================
   * @Fn                   -  SysTick_Handler
   * @brief                - hadleing systic timer interrput (decide what task shoud run next and swiching context and restor)
   * @param [in]           -void
   * @param [out]          -void
   * Note                  -hadler mode
  **///===========================================================================================================================================
  uint8_t sys_led;
 void SysTick_Handler()
  {
	 //updata wating time
	OS_Update_Task_watting_time();
	 //update ready queue
	OS_Decide_What_Next();
	//trigger pend sv to make switch context and restore
	OS_Trigger_pend_SV();

     sys_led ^= 1;
  }
  /**=============================================================================================================================================
   * @Fn                   -  Hardware_init
   * @brief                - init the hardware neeed for OS
   * @param [in]           -void
   * @param [out]          -void
   * Note                  -that funcation program any hardware the related to OS like external osillator
  **///===========================================================================================================================================
void Hardware_init ()
{
    //init the RCC that drive CPU (systick timer) or any timer use as OS timer

	//	decrease PenSV  interrupt priority to be  smaller than or equal  SySTICK Timer
	//SysTICK have a priority 14
__NVIC_SetPriority(PendSV_IRQn, 15);
__NVIC_SetPriority( SysTick_IRQn , 13);
// uint32_t pend =__NVIC_GetPriority(PendSV_IRQn);
//uint32_t sys= __NVIC_GetPriority(SysTick_IRQn);

}
/**=============================================================================================================================================
 * @Fn                   -  OS_Trigger_pend_SV
 * @brief                - interrput pend sv for make switching context and restor
 * @param [in]           -void
 * @param [out]          -void
 * Note                  -null
**///===========================================================================================================================================
void OS_Trigger_pend_SV()
{
	//trigger  pend sv to make switch context and restore
SCB->ICSR |=SCB_ICSR_PENDSVSET_Msk;

}
/**=============================================================================================================================================
 * @Fn                   -  HW_Start_Systic
 * @brief                - start systic timer to genarted periodic interrput
 * @param [in]           -void
 * @param [out]          -void
 * Note                  -null
**///===========================================================================================================================================
HW_Start_Systic()
{
	 //if use 8MHZ ocilletor
		//1 count<<<<<<<<<<<0.125us
		//x count<<<<<<<<<<1ms
		//x=8000count
	SysTick_Config(8000);

}
