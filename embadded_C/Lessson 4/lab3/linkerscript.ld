/*linker_script.ld 
ENG: Ahmed shaban
*/
MEMORY
{
	flash(RX) : ORIGIN = 0x00000000, LENGTH = 512M
	sram(RWX) : ORIGIN = 0x20000000, LENGTH = 512M
}

SECTIONS
{
	.text : {
		*(.vectors*)
		*(.text*)
		*(.rodata)
		. = ALIGN(4);
		_E_TEXT = .;
	}> flash

	.data : {
		. = ALIGN(4);
		_S_DATA = .;
		*(.data)
		. = ALIGN(4);
		_E_DATA = .;
	}> sram AT>flash

	.bss : {
		. = ALIGN(4);
		_S_BSS = .;
		*(.bss*)
		. = ALIGN(4);
		*(COMMON*)
		. = ALIGN(4);
		_E_bss = .;
	}> sram
}
  

