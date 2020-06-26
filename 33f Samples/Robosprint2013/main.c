#include<p33fj64mc804.h>
#include<libpic30.h>
#pragma code WDT=OFF
float error=0;
#define pwm1 OC1RS
void msdelay(char a);
void clk()
{	
    CLKDIVbits.PLLPRE=0;   ////"PLL TO INCREASE OR DECREASE FREQ"
	CLKDIVbits.PLLPOST=0;  ////POST SCALER AND PRESCALER=0
	PLLFBD=41;             //// PUTTING VALUE Fosc=Fin*M/n1*n2   ///freq=Fosc/2 
	while(OSCCONbits.LOCK!=1);
}
void config()
{ 
   AD1PCFGL=0xFFFF;
   PR2=65200;
   TMR2=0; 
   OC1CON=0x0006; // PWM mode without fault protection
   // output for PWM 
   TRISBbits.TRISB14=0;
  
   TRISBbits.TRISB15=0;
   P1TCON=0x0000;
   P2TCON=0x0000;
   P1TPER = 65200;    // 1 KHz
   P2TPER = 65200;	// 1 KHz

   PWM2CON1bits.PMOD1=1;
   PWM2CON1bits.PEN1H=1;
   P2OVDCONbits.POVD1H=1;
   P2OVDCONbits.POUT1H=1;
   P1TMR=0; 
   P2TMR=0;


}

void tyre4(float a)
{     P2DC1=P2TPER*2*(a);     
       P2TCONbits.PTEN = 1; 
}
    void main()
{ 
  clk();  
  
  config();


      tyre4(0.20);
while(1);
}