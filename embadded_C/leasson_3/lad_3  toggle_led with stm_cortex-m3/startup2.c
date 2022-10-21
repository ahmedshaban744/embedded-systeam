#include <stdint.h >
void Default_Handler
{
	Reset_handler();
}
extern int main(void);
void Reset_handler();

void NMI_Handler()__attribute__((weak,alias ("Default_Handler")));;      //weak>>>>>>can be overrid by anather symbol
                                                                         //alise >>>>all funcation refer to the Default_Handler
void H_fault_Handler()__attribute__((weak,alias ("Default_Handler")));;
void MM_fault_Handler()__attribute__((weak,alias ("Default_Handler")));;
void Bus_fault()__attribute__((weak,alias ("Default_Handler")));;
void Usage_fault_Handler()__attribute__((weak,alias ("Default_Handler")));;

uint32_t Vectors[] __attribute__((section(".vectors"))) ={                            //__attribute__ give the processsor order  
    extern unsigned int stack_top;                                                                                  // section not a c or assembly  
(uint32_t)         &stack_top ,
(uint32_t)         &Reset_Handler,
(uint32_t)         &NMI_Handler,
(uint32_t)         &H_fault_Handler,
(uint32_t)         &MM_fault_Handler,
(uint32_t)         &Bus_fault,
(uint32_t)         &Usage_fault_Handler
}
extern uint32_t  _E_TEXT;
extern uint32_t  _S_DATA;
extern uint32_t  _E_DATA;
extern uint32_t  _S_BSS;
extern uint32_t  _E_BSS;

//Defination of the target
void Default_Handler(void)
{
	Reset_Handler();
}

void Reset_Handler(void)
{
	//copy .data from flash to sram
	uint32_t DATA_SIZE = (uchar8_t*)&_E_DATA - (uchar8_t*)&_S_DATA ;
	uchar8_t* DATA_SRC = (uchar8_t*)&_E_TEXT ;
	uchar8_t* DATA_DST = (uchar8_t*)&_S_DATA ;
	uint32_t i;
	for(i=0;i < DATA_SIZE ;i++)
	{
		*((uchar8_t*)DATA_DST++) = *((uchar8_t*)DATA_SRC++) ;
	}


void Reset_handler(void)
{
main();
}