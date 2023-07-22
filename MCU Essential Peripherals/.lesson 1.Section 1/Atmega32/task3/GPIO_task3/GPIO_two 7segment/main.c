/*
 * GPIO_two 7segment.c
 *
 * Created: 7/21/2023 1:14:18 AM
 * Author : Ahmed Shaban
 */ 
#include <util/delay.h>
#define F_CPU 8000000UL
#define set_bit(reg,bit) reg|=1<<bit
#define clear_bit(reg,bit) reg&=~(1<<bit)
#define read_bit(reg,bit) ((reg>>bit)&1)
#define toggle_bit(reg,bit) reg^=1<<bit
//PORTA
#define PORTA (*(volatile unsigned char *)0x3B)
#define DDRA (*(volatile unsigned char*)0x3A)
#define PINA (*(volatile unsigned char*)0x39)
static unsigned char segment_number[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
int main(void)
{ 
	DDRA=0xff;

unsigned int flag=0;
    while (1) 
    { 
			
	for(flag=0;flag<10;flag++)
	{
		PORTA=segment_number[flag];
		_delay_ms(1000);
	}	
    }
}

