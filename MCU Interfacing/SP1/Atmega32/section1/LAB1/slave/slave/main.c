/*
 * slave.c
 *
 * Created: 9/8/2023 12:46:44 AM
 * Author : Ahmed
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define ss   4
#define CLK  7
#define MISO 6
#define MOSI 5

#define  F_CPU 8000000
void slave_init()
{    // slave select and clock and master output slave input  is output
	DDRB=(1<<MISO);
		DDRB &= ~(1<<MOSI) & ~(1<<CLK) & ~(1<<ss);
	//enable SPI
	SPCR|= 1<<SPE ;
	// DATA ORDER  MSB
//	SPCR &= ~(1<<DORD);
	
	//configer as slave
	//SPCR&=~(1<<MSTR);
	//clock idel low
	//SPCR &= ~(1<<CPOL);
	//clock rate	
	//SPCR|=1<<SPR0;
}
uint8_t slave_resived_data(uint8_t data)
{
	SPDR= data;
	while(!(SPSR & (1<<SPIF)));
	return SPDR;
	
}
int main(void)
{
   slave_init();
   DDRA=0xFF;
   for( unsigned char data=0 ; data <=255; data++)
   {
	   PORTA=slave_resived_data(data);
	   _delay_ms(1000);
   }
}

