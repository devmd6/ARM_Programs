#include <lpc21xx.h>

#define LCD (0xff<<8)
#define RS (1<<16)
#define RW (1<<17)
#define EN (1<<18)

#define col1 (1<<16)
#define col2 (1<<17)
#define col3 (1<<18)
#define col4 (1<<19)
#define row1 (1<<20)
#define row2 (1<<21)
#define row3 (1<<22)
#define row4 (1<<23)

void delay(unsigned int time);           // variable delay function

void lcd_ini(void);
void lcd_print(char *str);
void lcd_cmd(unsigned char command);
void lcd_dat(unsigned int data);

unsigned char keypad (void);
void keypad_delay(void);

int main (void)
   {
        PINSEL0 = 0x00000000;
        IODIR0 = 0Xffffffff;
        PINSEL1 = 0x00000000;
        IODIR1 = 0x00f00000;
        
        lcd_ini();
        lcd_print("Press any key");
        lcd_cmd(0xc0);

        while(1)
          {
                lcd_dat(keypad());
				keypad_delay();
          } 
        return 0;
   }

void keypad_delay(void)
   {
        unsigned int t1,t2;
        for(t1=0;t1<300;t1++)                 
                for(t2=0;t2<1275;t2++);
   }



unsigned char keypad (void)
   {
        unsigned char key;
        IOCLR1|=(row1|row2|row3|row4|col1|col2|col3|col4);
        while(1)
           {
                IOCLR1|=row1;
                IOSET1|=(row2|row3|row4);                     // first column = 0
                
                if((IOPIN1&col1)==0)
                   {
                        key='7';
                        keypad_delay();
                        return key;
                   }
                else if((IOPIN1&col2)==0)
                  {
                        key='8';
                        keypad_delay();
                        return key;
                  }
                else if((IOPIN1&col3)==0)
                  {
                        key='9';
                        keypad_delay();
                        return key;
                  }
                else if((IOPIN1&col4)==0)
                  {
                        key='/';
                        keypad_delay();
                        return key;
                  }
                
                IOCLR1|=row2;
                IOSET1|=(row1|row3|row4);                     //second column = 0
                
                if((IOPIN1&col1)==0)
                  {
                        key='4';
                        keypad_delay();
                        return key;
                  }
                else if((IOPIN1&col2)==0)
                  {
                        key='5';
                        keypad_delay();
                        return key;
                  }
                else if((IOPIN1&col3)==0)
                  {
                        key='6';
                        keypad_delay();
                        return key;
                  }
                else if((IOPIN1&col4)==0)
                  {
                        key='*';
                        keypad_delay();
                        return key;
                  }
                
                IOCLR1|=row3;
                IOSET1|=(row1|row2|row4);                     //third column = 0

                if((IOPIN1&col1)==0)
                  {
                        key='1';
                        keypad_delay();
                        return key;
                  }
                else if((IOPIN1&col2)==0)
                  {
                        key='2';
                        keypad_delay();
                        return key;
                  }
                else if((IOPIN1&col3)==0)
                  {
                        key='3';
                        keypad_delay();
                        return key;
                  }
                else if((IOPIN1&col4)==0)
                  {
                        key='-';
                        keypad_delay();
                        return key;
                  }
                
                IOCLR1|=row4;
                IOSET1|=(row1|row2|row3);                     //forth column = 0

                if((IOPIN1&col1)==0)
                  {
                        lcd_cmd(0x01);
                        keypad_delay();
                        
                  }
                else if((IOPIN1&col2)==0)
                  {
                        key='0';
                        keypad_delay();
                        return key;
                  }
                else if((IOPIN1&col3)==0)
                  {
                        key='=';
                        keypad_delay();
                        return key;
                  }
                else if((IOPIN1&col4)==0)
                  {
                        key='+';
                        keypad_delay();
                        return key;
                  }
          }
   }

void lcd_cmd(unsigned char command)
  {
        IO0CLR|=(RS|RW|EN|LCD);
        IO0SET|=(command<<8);
        IO0CLR|=RS;
        IO0CLR|=RW;
        IO0SET|=EN;
        delay(2);
        IO0CLR|=EN;
        delay(3);
  }
  
void lcd_dat(unsigned int data)        
  {
        IO0CLR|=(RS|RW|EN|LCD);
        IO0SET|=(data<<8);
        IO0SET|=RS;
        IO0CLR|=RW;
        IO0SET|=EN;
        delay(2);
        IO0CLR|=EN;
        delay(3);
  }

void lcd_print(char *str)
  {
        while(*str!='\0')
          {
                lcd_dat(*str);
                str++;
          }
  }

void lcd_ini(void)
  {
        delay(5);
        lcd_cmd(0X38);
        lcd_cmd(0X0f);
        lcd_cmd(0X06);
        lcd_cmd(0X01);
        delay(5);
        lcd_cmd(0X80);
  }

void delay(unsigned int time)           // variable delay function 
  {
        unsigned int t1,t2;
        for(t1=0;t1<time;t1++)       
                for(t2=0;t2<1275;t2++);
  }

