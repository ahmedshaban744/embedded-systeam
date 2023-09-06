/*
 * ATMEGA_32.c
 *
 * Created: 8/16/2023 3:42:38 PM
 * Author : Ahmed shaban
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 8000000UL
#include "bit_prosess.h"
#include "DIO.h"
#include "lcd.h"
#include "UART.h"

//=============================Perodic_ckeck==================================

int main(void)
{ 
	LCD_INIT();
	UART_INIT();

	char Perodic_ckeck='A';
if(UART_send_Perodic_ckeck(Perodic_ckeck))
{
	LCD_WRITE_CHAR(Perodic_ckeck);
}
   
while(1)
{
for(int i=0 ;i<10;i++)
{
	display_int_number( i);
    _delay_ms(10000);
}
		
}	

}

//==========================================polling========================
/*
int main(void)
{
	LCD_INIT();
	UART_INIT();
	//UART_SendString("ahmed shaban mohamed");
	char arr[100];
	char Perodic_ckeck;

	while(1)
	{
		
		UART_ReceiveString(arr);
		LCD_WRITE_STRING(arr);
	}

}
*/

//==========================================interrput========================
/*
int main(void)
{
	LCD_INIT();
	UART_INIT();
	int x=10;
	char arr[20];
	UART_ASYCH_SEND_STRING("sss");
	
	UART_ReceiveString(arr);
	LCD_WRITE_STRING(arr);
	display_int_number(x);

	
	
	x++;	
	if(x==10)
	{
	x=0;
	}
_delay_ms(1000);

}

*/
