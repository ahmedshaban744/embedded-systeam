/*linker_script.ld 
ENG: Ahmed shaban
*/
MEMORY 
{
FLASH (Rx): ORIGIN =0x08000000 , LENGTH =128k
sram (RWx): ORIGIN =0x2000000 , LENGTH =20k
}
SECTIONS
 {
   .text :{ 
     	*(.vector*)
     	 *(.text*)
    	    *(.rodata*)
}>FLASH

	.data :{
		*(.data*)
			
} >FLASH
	.bss : {
		*(.bss*) 
}>sram
  
}
  

