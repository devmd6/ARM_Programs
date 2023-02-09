#include<lpc213x.h>
int main()
{
PINSEL1=0x00000400; // P0.21 Pin of PORT0 as PWM
///*Configure the PLL block and set the CCLK and PCLK at 60 MHz */
PWMPCR=0x00; // Single Edge PWM Mode
PWMPR=60000-1; // Resolution of PWM is set at 1 mS
PWMMR0=10; // Period of PWM is 10 mS
PWMMCR= (1<<1); // PWMTC is reset on match with PWMMR0
PWMLER= (1<<5)| (1<<0); // Update Match Registers PWMMR0 and PWMMR5
PWMPCR= (1<<13); // Enable PWM5 output
PWMTCR= (1<<1); // Reset PWM TC and PWM PR
PWMTCR= (1<<0)| (1<<3); // Enable PWM Timer Counters and PWM Mode

PWMMR5=1; //Duty Cycle 1ms
PWMLER= (1<<5); // Update Match Registers PWMMR5
while (1);
}