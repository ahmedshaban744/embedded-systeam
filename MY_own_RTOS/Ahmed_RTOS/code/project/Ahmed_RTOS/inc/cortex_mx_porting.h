/*
 * cortex_mx_porting.h
 *
 *  Created on: Dec 7, 2023
 *      Author: Ahmed shaban
 */

#ifndef INC_CORTEX_MX_PORTING_H_
#define INC_CORTEX_MX_PORTING_H_
#include "core_cm3.h"
//===============================================================================================================================================
//                                   Macros
//===============================================================================================================================================
#define  OS_set_PSP(address)            __asm volatile("mov r0,%0 \n\t msr PSP,r0 \n\t": :"r"(address)) //msr use to write to cpu register
#define  OS_GET_PSP(address)             __asm volatile("mrs r0,PSP \n\t mov %0,r0": "=r" (address))   //mrs use to  read from cpu register
#define  OS_switch_TO_PSP()              __asm volatile("mrs R0,control \n\t mov R1,#0X2 \n\t  ORR R0,R0,R1 \n\t  msr control,R0 \n\t")
#define  OS_switch_TO_MSP()              __asm volatile("mrs r0, CONTROL \n\t mov r1,#0x05 \n\t and r0,r0,r1 \n\t msr CONTROL,r0")
#define  Privileged_acces_leavel()       __asm volatile("mrs R3,control \n\t  LSR R3, R3, #0X1  \n\t   LSL r3,r3,0x1  \n\t  msr CONTROL, r3")   //clear bit 0 in control register
#define  unPrivileged_acces_leavel()     __asm volatile("mrs R3,control \n\t  ORR R3,R3,#0x1   \n\t  msr control,R3   \n\t") //set  bit 0 in control register
#define NULL ((void *)0)
#define MSP_size   3072   // 3*1024

extern uint32_t  _estack;
extern uint32_t  _eheap;
extern uint32_t _heap_start;


//================================================================================================================================================
//                                                               APIS
//================================================================================================================================================
void Hardware_init ();
void OS_Trigger_pend_SV();
void HW_Start_Systic();



#endif /* INC_CORTEX_MX_PORTING_H_ */
