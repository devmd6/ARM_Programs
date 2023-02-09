#include <LPC21XX.h>
int wait(unsigned int w)
{
	unsigned int a,b;
	for(a=0;a<w;a++)
		for(b=0;b<200;b++);
}
int main()
 {
   PINSEL0 = 0x00000000;
   IODIR0 = 0XFFFFFFFF;
   while(1)
   {
          IOPIN0 = 0XFC;
		  wait(5000);
		  IOPIN0 = 0X60;
		  wait(5000);
		  IOPIN0 = 0XDA;
		  wait(5000);
		  IOPIN0 = 0XF2;
		  wait(5000);
		  IOPIN0 = 0X66;
		  wait(5000);
		  IOPIN0 = 0XB6;
		  wait(5000);
		  IOPIN0 = 0XBE;
		  wait(5000);
		  IOPIN0 = 0XE0;
		  wait(5000);
		  IOPIN0 = 0XFE;
		  wait(5000);
		  IOPIN0 = 0XF6;
		  wait(5000);
	  	 
	}
 }
 