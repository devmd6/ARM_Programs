#include <LPC21XX.H>
char switchStatus;
int main (void)
{
	PINSEL0 = 0x00000000;
	IO0DIR  &= 0xFFFFFFFE; //P0.0 - switch
	IO0DIR  |= 0x00000002; //P0.1 - led
	IO0CLR  = 0xFFFFFFFF;
	while (1)
	{
	switchStatus = (IOPIN0 & 0x01);
	  if(switchStatus==1)
		  {
		  	IOSET0 = 2;
		  } 				
		  else
		   {
			IOCLR0 = 2;		   	
		   }	
	}
}

