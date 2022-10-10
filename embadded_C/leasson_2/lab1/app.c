#include "uart.h"
unsigned char string_buffer [100]="learn_in_depth :A.shaban";
int main(void )
{
uart_send_string(string_buffer );
}
 
 