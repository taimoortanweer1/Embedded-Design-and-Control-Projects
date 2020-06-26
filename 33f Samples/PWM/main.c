#include<p33fj64mc802.h>
#include<libpic30.h>
#pragma code WDT=OFF
float error=0;
#define pwm1 OC1RS

#define RL       PORTBbits.RB13
#define SPEED    PORTBbits.RB14
#define ON_OFF   PORTBbits.RB15

#define PWM      PORTBbits.RB8
#define DIR_1    PORTBbits.RB13
#define DIR_2    PORTBbits.RB14


void msdelay(char a);
void config();
void clk();
void tyre4(float pwm);    

void main()
{ 
clk();    
config(); 
 
while(1)
	PORTB=0xFFFF;
{
			DIR_1 = 1;
			DIR_2 = 1;
		//	tyre4(.9f);
while(1);
//			DIR_1 = 1;
//			DIR_2 = 0;
//			tyre4(0.90);
}
//  while(ON_OFF==1)
//	{
//		if(RL==1 && SPEED ==1)
//		{
//			DIR_1 = 1;
//			DIR_2 = 0;
//			tyre4(0.90);
//		}
//		if(RL==1 && SPEED ==0)
//		{
//			DIR_1 = 1;
//			DIR_2 = 0;
//			tyre4(0.40);
//		}
//		if(RL==0 && SPEED ==1)
//		{
//			DIR_1 = 0;
//			DIR_2 = 1;
//			tyre4(0.80);
//		}
//		if(RL==0 && SPEED ==0)
//		{
//			DIR_1 = 0;
//			DIR_2 = 1;
//			tyre4(0.40);
//		}
//	}
//
//		tyre4(0.00);
//		DIR_1 = 0;
//		DIR_2 = 0;
//}  

}
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
	TRISBbits.TRISB8=0;
    TRISBbits.TRISB2=0;
    TRISBbits.TRISB3=0;
	TRISBbits.TRISB13=0;
	TRISBbits.TRISB14=0;
	TRISBbits.TRISB15=1;
   
    
    PR2=65200;
    TMR2=0; 
    OC1CON=0x0006; // PWM mode without fault protection
    // output for PWM 
   
   P1TCON=0x0000;
   P2TCON=0x0000;
   P1TPER = 65200;    // 1 KHz
   P2TPER = 65200;  	// 1 KHz

   PWM2CON1bits.PMOD1=1;
   PWM2CON1bits.PEN1H=1;
   P2OVDCONbits.POVD1H=1;
   P2OVDCONbits.POUT1H=1;
   PWM2CON1bits.PMOD1=0;
   PWM2CON1bits.PEN1L=0;
   P2OVDCONbits.POVD1L=0;
   P2OVDCONbits.POUT1L=0;
   P1TMR=0; 
   P2TMR=0;
}

void tyre4(float a)
{     P2DC1=P2TPER*2*(a);     
       P2TCONbits.PTEN = 1; 
}
