/*
  Stepper motor interfacing with LPC2148(ARM7)
  http://www.electronicwings.com/arm7/stepper-motor-interfacing-with-lpc2148
*/

#include <lpc214x.h>
#include <stdint.h>
uint8_t i,j;

void delay_ms(uint16_t j)
{
    uint16_t x,i;
	for(i=0;i<j;i++)
	{
    for(x=0; x<6000; x++);    /* loop to generate 1 milisecond delay with Cclk = 60MHz */
	}
}

int main (void)
{
	IO0DIR = (IO0DIR | 0x0000000F);	/* Configure P0.0-P0.3 as output(used for controlling stepper motor) */
	while(1)
	{
	
		//	for( j = 0; j<12; j++ )	
		//	{
				IO0PIN = 1<<0;
				delay_ms(500);
				
				IO0PIN = 1<<1;
				delay_ms(500);
				
				IO0PIN = 1<<2;
				delay_ms(500);
				
				IO0PIN = 1<<3;
				delay_ms(500);

				IO0PIN = 1<<3;
				delay_ms(500);
				
				IO0PIN = 1<<2;
				delay_ms(500);
				
				IO0PIN = 1<<1;
				delay_ms(500);
				
				IO0PIN = 1<<0;
				delay_ms(500);
		//	}
		
		//	while(1);
	}
}
