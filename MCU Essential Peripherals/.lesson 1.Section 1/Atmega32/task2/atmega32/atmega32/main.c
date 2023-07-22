/*
 * atmega32.c
 *
 * Created: 7/20/2023 7:51:06 PM
 * Author : Ahmed Shaban 
 */ 
#include <util/delay.h>
//UTIL.H
#define set_bit(reg,bit) reg|=1<<bit
#define clear_bit(reg,bit) reg&=~(1<<bit)
#define read_bit(reg,bit) ((reg>>bit)&1)
#define toggle_bit(reg,bit) reg^=1<<bit

//portA
#define PORTA (*(volatile unsigned char *)0x3B)
#define DDRA (*(volatile unsigned char*)0x3A)
#define PINA (*(volatile unsigned char*)0x39)

//PORTC
#define PORTC  (*(volatile unsigned char *)0x35)
#define DDRC   (*(volatile unsigned char*)0x34)
#define PINC   (*(volatile unsigned char*)0x33)
#define F_CPU 8000000UL
int main(void)
{
	 DDRA=0b11111111;
      clear_bit(DDRC,0);
      set_bit(PORTC,0) ;
    unsigned int flag=0;
    while (1) 
    {   
		if(read_bit(PINC,0)==0)
		{
				set_bit(PORTA,flag);
				_delay_ms(2500);
				clear_bit(PORTA,flag-1)	;
		}
		if(read_bit(PINC,0)==1)
		{
		flag++;
		set_bit(PORTA,flag);
		_delay_ms(2500);
			clear_bit(PORTA,flag-1)	;	
		}
    }
 }

