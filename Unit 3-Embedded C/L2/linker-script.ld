/*Eng Hesham Mohamed*/
/*4 Fab, 2023*/

ENTRY(reset)

MEMORY
{
	Mem (rwx): ORIGIN = 0x00000000, LENGTH = 64M
}

SECTIONS
{
	. = 0x10000; /*start from this location*/
	.startup . :
	{
		startup.o(.text)
	}> Mem
	.text :
	{
		*(.text) *(.rodata)
	}> Mem
	.data :
	{
		*(.data)
	}> Mem
	.bss :
	{
		*(.bss) *(.COMMON)
	}> Mem
/*	.debug_sections :
	{
		*(.debug_info) *(.debug_abbrev) *(.debug_loc) *(.debug_aranges) *(.debug_line) *(.debug_str) *(.debug_frame)
	}> Mem*/
	. = . + 0x1000; /*4kb of stack memory*/
	stack_top = . ;
}