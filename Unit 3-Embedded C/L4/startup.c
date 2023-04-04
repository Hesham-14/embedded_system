//startup.c
//Eng. Hesham Mohamed

#include <stdint.h>

//init the main() from main.c
extern int main(void);

//init the symbols from the linker
extern uint32_t _E_TEXT;
extern uint32_t _S_DATA;
extern uint32_t _E_DATA;
extern uint32_t _S_BSS;
extern uint32_t _E_BSS;

//to specify the stack_top location there are two ways
/*1st: to make sure that .BSS doesn't interface with the stack_top section in sram,
 we will get its postion size from the linker*/
extern uint32_t _STACK_TOP;
//2nd: booking 1024B located by .bss through un intialized array of int 256 element
static unsigned long stack_top[256];

//intializing handler functions
void _DEFAULT_handler(void);
void _reset(void);
void _NMI_handler(void) __attribute__((weak,alias ("_DEFAULT_handler")));
void _HARD_FAULT_handler(void) __attribute__((weak,alias ("_DEFAULT_handler")));
void _MM_FAULT_handler(void) __attribute__((weak,alias ("_DEFAULT_handler")));
void _BUS_FAULT_handler(void) __attribute__((weak,alias ("_DEFAULT_handler")));
void _USAGE_FAULT_handler(void) __attribute__((weak,alias ("_DEFAULT_handler")));


//to define vectors section there are two ways
/*
//1st: using array
uint32_t vectors[] __attribute__((section(".vectors"))) = {
//	(uint32_t) &_STACK_TOP,											//first way 	
	(uint32_t) ((unsigned long)stack_top + sizeof(stack_top)),		//second way
	(uint32_t) &_reset,
	(uint32_t) &_NMI_handler,
	(uint32_t) &_HARD_FAULT_handler,
	(uint32_t) &_MM_FAULT_handler,
	(uint32_t) &_BUS_FAULT_handler,
	(uint32_t) &_USAGE_FAULT_handler
};*/

/*2nd: using array of pointers to the handler functions*/
void (* const g_p_fn_vectors[])() __attribute__((section(".vectors"))) = {
	(void (*)()) ((unsigned long)stack_top + sizeof(stack_top)),
	&_reset,
	&_NMI_handler,
	&_HARD_FAULT_handler,
	&_MM_FAULT_handler,
	&_BUS_FAULT_handler,
	&_USAGE_FAULT_handler

};

void _reset(void)
{
	int i=0;
	//we need to copy data section from flash to sram
	/*we cast it to uchar to move byte by byte, but as we have make an allignment on the .data section
	  we can use uint casting*/
	uint32_t DATA_size = (unsigned char*)&_E_DATA - (unsigned char*)&_S_DATA;
	unsigned char* P_src = (unsigned char*)&_E_TEXT;
	unsigned char* P_dst = (unsigned char*)&_S_DATA;
	for(i = 0; i<DATA_size; i++)
	{
		*((unsigned char*) P_dst++) = *((unsigned char*) P_src++);
	}


	//init .bss section in sram with value = 0
	uint32_t BSS_size = (unsigned char*)&_E_BSS - (unsigned char*)&_S_BSS;
	P_dst = (unsigned char*)&_S_BSS;		//can i skip this step?? as _E_DATA == _S_BSS ??
	for(i = 0; i<BSS_size; i++)
	{
		*((unsigned char*) P_dst++) = (unsigned char)0;
	}

	//jumping to the main()
	main();
}

void _DEFAULT_handler(void)
{
	_reset();
}
