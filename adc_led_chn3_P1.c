#include<lpc214x.h>
#include"delay.h" // Add delay.h file to the Project Folder and then Compile the Project

void adc_ini(void);
unsigned int adc_data;

int main()
  {
        PINSEL2=0X00000000;
		IODIR1=0XFFFFFFFF;
		adc_ini();
	
		while(1)
	    {
		    AD0CR = 0x00200700;  //CLKDIV=(PCLK)/8, BURST=0, CLKS=11clks/10bits, PDN=1
			AD0CR|=0x00000008; //Channel 3
			AD0CR |= (1<<24);			//Start Conversion
			while(!(AD0GDR & 0x80000000));
			adc_data = (AD0GDR >> 6)& 0x3FF; //Read 10 bit ADC Data ie RESULT = 10 Bit Data (15:6)
			IOPIN1 = adc_data<<16;
			AD0CR &= 0xF8FFFFFF; //Deactivate ADC Module (No Start) ie START = 000 (Bits 26:24)
			delay_ms(10000);
	    }
  }


void adc_ini()
  {
	PINSEL1 &= 0xDFFFFFFF; //P0.30 is Configured as ADC Pin AD0.3 (PINSEL1<29> = 0)
	PINSEL1 |= 0x10000000; //P0.30 is Configured as ADC Pin AD0.3 (PINSEL1<28> = 1)
	PCONP |= (unsigned long)(0x00000001) << 12;	// Enable Power/Clock to ADC0
	
  }