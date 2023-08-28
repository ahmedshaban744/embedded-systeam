/*
 * stm32f103c6_ RCC_drivers.c
 *
 *  Created on: Aug 20, 2023
 *      Author: Ahmed Shaban
 */
#include "stm32f103c6_RCC_drivers.h"
#include "stm32f103x6.h"
//================================================================================================
//Bits 10:8 PPRE1: APB low-speed prescaler (APB1)
//Set and cleared by software to control the division factor of the APB low-speed clock
//(PCLK1).
//Warning: the software has to set correctly these bits to not exceed 36 MHz on this domain.
//0xx: HCLK not divided
//100: HCLK divided by 2
//101: HCLK divided by 4
//110: HCLK divided by 8
//111: HCLK divided by 16
const uint8_t APB1CLOCK_prescaler[8]={0,0,0,0,1,2,3,4};
//Bits 13:11 PPRE2: APB high-speed prescaler (APB2)
//Set and cleared by software to control the division factor of the APB high-speed clock
//(PCLK2).
//0xx: HCLK not divided
//100: HCLK divided by 2
//101: HCLK divided by 4
//110: HCLK divided by 8
//111: HCLK divided by 16
//to divide by 2 the value is  4 in the register so put four zeros in array
const uint8_t APB2CLOCK_prescaler[8]={0,0,0,0,1,2,3,4};

//Bits 7:4 HPRE: AHB prescaler
//Set and cleared by software to control the division factor of the AHB clock.
//0xxx: SYSCLK not divided
//1000: SYSCLK divided by 2
//1001: SYSCLK divided by 4
//1010: SYSCLK divided by 8
//1011: SYSCLK divided by 16
//1100: SYSCLK divided by 64
//1101: SYSCLK divided by 128
//1110: SYSCLK divided by 256
//1111: SYSCLK divided by 512
//to divide by 2 the value is  8 in the register so put 8 zeros in array
const uint8_t AHPCLOCK_prescaler[16]={0,0,0,0,0,0,0,0,1,2,3,4,6,7,8,9};

/**================================================================
 * @Fn                   -  MCAL_RCC_Get_Sys_clock
 * @brief                -get system clock freq
 * @param [in]           -null
 * @retval               - uint32_t
 * Note                  -that funcation for the internal clock
 */
uint32_t MCAL_RCC_Get_Sys_clock(void)
{
	switch((RCC->CFGR>>2) &0b11)
	{
	case 0:
		return  HSI_clock;  break;
	case 1:
//to do neet to calc HSE clock
		return   HSE_clock;  break;

	case 2:
//to do neet to calc HSE clock
		return  PLL_clock;  break;

    }
}
/**================================================================
 * @Fn                   -  MCAL_RCC_Get_HClock_clock
 * @brief                -  get H Clock  freq
 * @param [in]           -  null
 * @retval               -  uint32_t
 */
uint32_t MCAL_RCC_Get_HClock_clock(void)
{
	return (MCAL_RCC_Get_Sys_clock() >>AHPCLOCK_prescaler[(RCC->CFGR >>4) & 0b1111])	;

}
/**================================================================
 * @Fn                   -  MCAL_RCC_Get_PClock1_clock
 * @brief                -  get P1 Clock  freq
 * @param [in]           -  null
 * @retval               -  uint32_t
 */
uint32_t MCAL_RCC_Get_PClock1_clock(void)
{
	return (MCAL_RCC_Get_HClock_clock() >> APB1CLOCK_prescaler[(RCC->CFGR >> 8) &0b111]);

}
/**================================================================
 * @Fn                   -  MCAL_RCC_Get_PClock2_clock
 * @brief                -  get P1 Clock  freq
 * @param [in]           -  null
 * @retval               -  uint32_t
 */
uint32_t MCAL_RCC_Get_PClock2_clock (void)
{
	return (MCAL_RCC_Get_HClock_clock() >> APB2CLOCK_prescaler[(RCC->CFGR >> 11) & 0b111 ]);

}
