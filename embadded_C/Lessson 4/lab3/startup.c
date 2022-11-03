#include <stdint.h >
void Reset_Handler(void);
extern int main(void);
void Default_Handler(void)
{
	Reset_Handler();
}
	//weak>>>>>>can be overrid by anather symbol
	//alise >>>>all funcation refer to the Default_Handler
	//__attribute__ give the processsor direct order  
	// section not  c or assembly  
void H_fault_Handler()__attribute__((weak,alias ("Default_Handler")));;
void MM_fault_Handler()__attribute__((weak,alias ("Default_Handler")));;
static unsigned int stack_top [265];
void  (*const g_p_fn_vector[])() __attribute__((section(".vectors"))) ={                           
(void (*)())    ((unsigned long )stack_top+sizeof(stack_top)),
         &Reset_Handler,
		// &NMI_Handler,
         &H_fault_Handler
};
extern unsigned int _E_TEXT ;
extern unsigned int _S_DATA ;
extern unsigned int _E_DATA ;
extern unsigned int _S_BSS  ;
extern unsigned int _E_BSS  ;

//Defination of the target
void Reset_Handler()
 {
	//copy .data from flash to sram
	uint32_t DATA_SIZE = (unsigned char*)&_E_DATA - (unsigned char*)&_S_DATA ;
	unsigned char* DATA_SRC = (unsigned char*)&_E_TEXT ;
	unsigned char* DATA_DST = (unsigned char*)&_S_DATA ;
	unsigned char i;
	for( i=0;i < DATA_SIZE ;i++)
	{
		*((unsigned char*)DATA_DST++) = *((unsigned char*)DATA_SRC++) ;
	}
	for(i=0; i<DATA_SRC ;i++)
	{
		*((unsigned char*)DATA_SRC++) = (unsigned char)0;
	}	
main();
}