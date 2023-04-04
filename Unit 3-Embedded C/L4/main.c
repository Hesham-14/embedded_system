//Learn-in-depth
//Hesham Mohamed
//Lab 3 - unit 4

#define SYSCTL				0x400FE000
#define GPIOF				0x40025000
#define SYSCTL_RCGC2_R 		(*(volatile unsigned long*)(SYSCTL+0x108))
#define GPIO_PORTF_DIR_R	(*(volatile unsigned long*)(GPIOF +0x400))
#define GPIO_PORTF_DEN_R	(*(volatile unsigned long*)(GPIOF +0x51C))
#define GPIO_PORTF_DATA_R	(*(volatile unsigned long*)(GPIOF +0x3FC))

int main()
{
	volatile unsigned int delay_count=0;
	SYSCTL_RCGC2_R = 0x20;
	//after enabling clock, we need to make a delay to make sure GPIOF is up and running
	for(delay_count=0; delay_count<200; delay_count++);

	GPIO_PORTF_DIR_R |= 1<<3;		//set the direction as output for pin3 port F
	GPIO_PORTF_DEN_R |= 1<<3;		//enabling pin3
	//toggling pin3
	while (1)
	{
		GPIO_PORTF_DATA_R |= 1<<3;		//giving it value one
		for(delay_count=0; delay_count<20000; delay_count++);
		GPIO_PORTF_DATA_R &= ~(1<<3);	//giving it value zero
		for(delay_count=0; delay_count<20000; delay_count++);
	}
	return 0;
}