#include "LPC17xx.h"
#include "system_LPC17xx.h"

volatile uint32_t msTicks = 0; // counter for 1ms SysTicks

//====================================================================================
void main()
{
	uint32_t timer_mark;
	
	// Init on-board LED as output
	GPIO1->FIODIR |= 1 << 18;
	
	// Init SysTick
	SysTick_Config(SystemFrequency / 1000);				// Generate interrupt every 1 ms
	
	for (;;)
	{
		timer_mark = msTicks;					// Take timer snapshot 
		while(msTicks < (timer_mark + 100));	// Wait until 100ms has passed
		GPIO1->FIOCLR = 1 << 18;				// Turn the LED off
	
		timer_mark = msTicks;					// Take timer snapshot 
		while(msTicks < (timer_mark + 100));	// Wait until 100ms has passed
		GPIO1->FIOSET = 1 << 18;				// Turn the LED on
	}
}

//====================================================================================
void SysTick_Handler(void)
{
	msTicks++;
}
