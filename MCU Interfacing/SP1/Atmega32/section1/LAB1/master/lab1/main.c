/*
 * lab1.c
 *
 * Created: 9/7/2023 11:29:26 PM
 * Author : Ahmed
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define ss   4
#define CLK  7
#define MISO 6
#define MOSI 5

#define  F_CPU 8000000
void master_init()


{ 
	
		//configer as master
	SPCR|= 1<<MSTR;
	   // slave select and clock and master output slave input  is output
	DDRB|=(1<<ss)|(1<<CLK) |(1<<MOSI);
	DDRB &= ~(1<<MISO);
	
	//enable SPI
	SPCR|= 1<<SPE ;

	//clock rate	
	SPCR|=1<< SPR0;	
	SPCR&=~(1<< SPR1);	
}
uint8_t master_send_data(uint8_t data)
{
	SPDR= data;
	while(!(SPSR & (1<<SPIF)));
	return SPDR;
	
}





int main(void)
{
  master_init();
  DDRA=0xff;
  for( unsigned char data=0 ;data <=255;data++)
  {
	  PORTA=master_send_data(data);
	    _delay_ms(1000);
  }
}

