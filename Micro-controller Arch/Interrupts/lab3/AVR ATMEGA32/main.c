#include <avr/io.h>
#define F_CPU 16000000UL
#include <avr/interrupt.h>
#include <util/delay.h>

//Base Addresses
#define IO_Base  0x20


//IO Registers
#define IO_DDRD		*(unsigned volatile int*)(IO_Base + 0x11)   //portD use as input
#define IO_PORTD	*(unsigned volatile int*)(IO_Base + 0x12)  //PORT D   use as output
#define IO_DDRB		*(unsigned volatile int*)(IO_Base + 0x17)  //PORT B use as input

void INT_Init();
void IO_Init();

//Interrupts Registers
#define MCUCR   *(unsigned volatile int*)(IO_Base + 0x35)
#define MCUCSR  *(unsigned volatile int*)(IO_Base + 0x34)
#define GICR	*(unsigned volatile int*)(IO_Base + 0x3B)   


int main(void)
{
	IO_Init();
	INT_Init();
	while(1)
	{
		//Turn LEDs off
		IO_PORTD &= ~(1<<5);
		IO_PORTD &= ~(1<<6);
		IO_PORTD &= ~(1<<7);
	}
}

void IO_Init()
{
	//All LEDs pins as output
	IO_DDRD |= (1<<7);
	IO_DDRD |= (1<<6);
	IO_DDRD |= (1<<5);
}

void INT_Init()
{

	
	//Set INIT0 as logical change generates an interrupt request.
	MCUCR |=  (0b01<<0);


	//Set INIT1 as The rising edge.
	MCUCR |=  (0b11<<2);

	
	//Set INIT1 as The falling edge.
   MCUCSR &= ~(1<<6);
	
	//Enable all interrupts
	GICR |= (1<<5);
	GICR |= (1<<6);
	GICR |= (1<<7);
	
	//To enable Global interrupt
	sei();
}

ISR(_vect_INT0)
{
	IO_PORTD |= (1<<5);
	_delay_ms(1000);
}

ISR(_vect_INT1)
{
	IO_PORTD |= (1<<6);
	_delay_ms(1000);
}

ISR(_vect_INT2)
{
	IO_PORTD |= (1<<7);
	_delay_ms(1000);
}