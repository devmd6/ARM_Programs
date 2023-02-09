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
          IOSET1 = 0XFFFFFFFF;
		   wait(25000);
	  	   IOCLR1 = 0XFFFFFFFF; 
		   wait(25000);
	}
 }
 