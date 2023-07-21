/* Includes ------------------------------------------------------------------*/
/**
 ******************************************************************************
 * @file           : main.c
 * @author         : ahmed shaban mohamed
 * @brief          : Main program body
 ******************************************************************************

 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

typedef volatile unsigned int vuint32_t ;
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
// register address

//RCC
#define RCC_BASE 	0x40021000
#define RCC_APB2ENR  *((volatile uint32_t *)(RCC_BASE + 0x18))
#define RCC_IOPAEN (1<<2)

//GPIO PORT A
#define GPIOA_BASE           0x40010800
#define GPIOA_CRH *(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_CRL *(volatile uint32_t *)(GPIOA_BASE + 0x00)
#define GPIOA_ODR *(volatile uint32_t *)(GPIOA_BASE + 0x0C)
#define GPIOA_IDR *(volatile uint32_t *)(GPIOA_BASE + 0x08)

//GPIO PORT B
#define GPIOB_BASE      0x40010C00
#define GPIOB_CRH *(volatile uint32_t *)(GPIOB_BASE + 0x04)
#define GPIOB_CRL *(volatile uint32_t *)(GPIOB_BASE + 0x00)
#define GPIOB_ODR *(volatile uint32_t *)(GPIOB_BASE + 0x0C)
#define GPIOB_IDR *(volatile uint32_t *)(GPIOA_BASE + 0x08)


void clock_init()
{
	//Enable Init Clock GPIOA
	//RCC_APB2ENR |= RCC_IOPAEN ;
	RCC_APB2ENR |= (1<<2);
	//Enable Init Clock GPIOB
	RCC_APB2ENR |= (1<<3);
}

void GPIO_init()
{
	GPIOA_CRL = 0x0;
	GPIOB_CRL = 0x0;
	GPIOA_CRH = 0x0;
	GPIOB_CRH = 0x0;
	GPIOB_ODR=0;


//PA1 (Floating/High-Z) Input
	//00: Input mode (reset state)
	//01: Floating input (reset state)
	GPIOA_CRL |= 1<<6;


//PB1 Push_Pull Output
	//00: General purpose output push-pull
	//01: Output mode, max speed 50 MHz.
	GPIOB_CRL |= (0b11<<4);
	GPIOB_CRL&= ~(0b11<<6);
//PA13 (Floating/High-Z) Input
	//00: Input mode (reset state)
	//01: Floating input (reset state)

	GPIOA_CRH |= (0b01<<22);
	//GPIOA_CRH |= (1<<22);

//PB13 Push_Pull Output
	//00: General purpose output push-pull
	//01: Output mode, max speed 50 MHz.
	GPIOB_CRH |= (0b11<<22);
	GPIOB_CRH &=~(0b11<<20);

}
void delay(unsigned int x)
{
	unsigned int i,j;
	for(i=0;i<x;i++)
		for(j=0;j<255;j++);

}
#include "main.h"
int main(void)
{
	clock_init();
	GPIO_init();
	while(1)
	{
	    // PA1 Button (Pull-up) >> Toggle LED on Single Press
	    if (((GPIOA_IDR & (1<<1)) >>1) == 0) // Button A1 is pressed
	    {
	        GPIOB_ODR ^= (1<<1); // Toggle LED
	        while ((((GPIOA_IDR & (1<<1)) >>1) == 0)); // Wait until button is released
	    }

	    // PA13 Button (Pull-down) >> Toggle LED on Press
	    if (((GPIOA_IDR & (1<<13))>>13) == 1) // Button A13 is pressed
	    {
	        GPIOB_ODR ^= (1<<13); // Toggle LED

	    }

	    // Delay to avoid rapid toggling due to button bounce
	    delay(1);
	}
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
