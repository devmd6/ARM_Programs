#include <LPC21XX.h>
int wait(unsigned int w)
{
	unsigned int a,b;
	for(a=0;a<w;a++)
		for(b=0;b<200;b++);
}
int main()
 {
   PINSEL2 = 0x00000000;
   IODIR1 = 0XFFFFFFFF;
   while(1)
   {
          IOPIN1 = 0X000A0000;
		  wait(25000);
	  	  IOPIN1 = 0X00050000;
		  wait(25000);
	}
 }
 