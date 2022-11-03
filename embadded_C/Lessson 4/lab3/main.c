/* make by :: AHMED SHABAN MOHAMED
	 lab 3 mortex m4*/

	#define SYSCTL_RCG2_R         (*(( unsigned long*) 0x400FE108))  
	#define GPIO_PORTF_DIR_R      (*(( unsigned long*) 0x40025400))
	#define GPIO_PORTF_DEN_R      (*(( unsigned long*) 0x4002551C))
	#define GPIO_PORTF_DATA_R     (*(( unsigned long*) 0x400253FC))
int main()
{
 volatile  unsigned long delay;
SYSCTL_RCG2_R =0x00000020;
	  for(delay=0 ; delay<500 ; delay++) ; 
 // delay  to make sure the  SYSCTL_RCG2_R is start
  GPIO_PORTF_DIR_R |=1<<3;
  GPIO_PORTF_DEN_R |=1<<3;
while (1)
{
GPIO_PORTF_DATA_R |=1<<3;
for(delay=0;delay<500000;delay++) ;
GPIO_PORTF_DATA_R      &= ~(1<<3);
for(delay=0;delay<500000;delay++) ;
 
}
     return 0;

}