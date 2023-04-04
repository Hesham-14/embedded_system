@@the following line is to make the reset symbol global, to be seen by the symbol table
.global reset
reset:
		ldr sp, =stack_top
		bl main
stop:	
		b stop