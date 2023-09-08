/*
 * MAX7219 with spi.c
 *
 * Created: 9/8/2023 3:22:26 PM
 * Author : Ahmed
 */ 

#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>

#define SS   4
#define MOSI 5
#define SCK  7
char  arr[7]={2,2,7,2,0,0,1};

void SPI_MasterInit()
{
	/* Set MOSI, SCK and SS output*/
	DDRB |= (1 << MOSI) | (1 << SS) | (1 << SCK);
	
	/* Enable SPI, Master, set clock rate fck/16 */
	SPCR |= (1 << MSTR) | (1 << SPE) | (1 << SPR0);
}
void MUX(uint8_t command , uint8_t data)
{// make ss  logic 0 to start 
	PORTB &= ~(1 << SS);
	SPDR=command ;
	//polling in the flag to ensure that command is send
	while (!(SPSR &(1<<SPIF)));
	SPDR=data ;
	//polling in the flag to ensure that data is send
	while (!(SPSR &(1<<SPIF)));
	//make slave selact hight to stop
	PORTB = (1 << SS);	
}



int main(void)
{
	char index_display ;
	char counter=0;
    SPI_MasterInit();
	// Shutdown Register Format (
	// normal mode
	MUX(0x0C,0x01);
	//Decode-Mode Register
	//Code B decode for digits 7–0
	MUX(0x09,0xFF);
	// Intensity Register Format
	//max  Intensity
	MUX(0x0A,0xFF);
	//. Scan-Limit Register Format (
	//Display digits 0 1 2 3 4 5 6 7
	MUX(0x0B,0x06);
	
 static uint8_t x=1;
		/*SPDR=0X1F ;*/
    while (1) 
    {
				
				for (index_display =0; index_display <= 7; index_display++)
				{
				MUX( index_display ,arr[index_display-1]);
				_delay_ms(100);
			
				}
				
    }
}

