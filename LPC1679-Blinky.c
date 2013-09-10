#include "LPC17xx.h"
#include "system_LPC17xx.h"

volatile uint32_t msTicks; // counter for 1ms SysTicks

void main()
{
	long i;
	
	SystemInit();	//Called by startup code
	
	msTicks = 0;
	
	// Init on-board LED
	GPIO1->FIODIR |= 1 << 18;
	GPIO1->FIOSET = 1 << 18;
	
	// Init SysTick
	SysTick_Config(120000);               /* Generate interrupt every 1 ms */
	
	for (;;)
	{
		while(msTicks < 100);
		
		msTicks = 0;
		
		if(GPIO1->FIOPIN & (1 << 18))
		{
			GPIO1->FIOCLR = 1 << 18;
		}
		else
		{
			GPIO1->FIOSET = 1 << 18;
		}
	}
}

//****************************************************************************
void SysTick_Handler(void)
{
	msTicks++;
}
