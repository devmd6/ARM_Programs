#include <LPC214x.H>        

void delay(int count)
{
  int j=0,i=0;

  for(j=0;j<count;j++)
  {
    /* At 60Mhz, the below loop introduces
    delay of 10 us */
    for(i=0;i<35;i++);
  }
}

int a;

int main (void)
  {                /* execution starts here                    */
   PINSEL0|= 0x00000005;           /* Enable RxD0 and TxD0                     */
  U0LCR = 0x83;                   /* 8 bits, no Parity, 1 Stop bit            */
  U0DLL = 97;                     /* 9600 Baud Rate @ 15MHz VPB Clock         */
  U0LCR = 0x03;                   /* DLAB = 0                                 */

  while(1)                           /* An embedded program does not stop */
   {
 	   	while(!(U0LSR & 0x01));
  		a=U0RBR;
		while(!(U0LSR & 0x20)); // Wait until UART1 ready to send character     
		U0THR = a;  // Send character
   }                               
}
