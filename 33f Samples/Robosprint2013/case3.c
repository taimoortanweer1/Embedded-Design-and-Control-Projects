#include<p33fj64mc802.h>
#include<libpic30.h>
#pragma code WDT=OFF
float error=0;
#define pwm1 OC1RS
#define fr PORTAbits.RA0
#define fl PORTAbits.RA1
#define r PORTBbits.RB2
#define l PORTBbits.RB3
#define br PORTAbits.RA2
#define bl PORTAbits.RA3
#define s2 PORTAbits.RA4
#define grip PORTBbits.RB4
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
   TRISAbits.TRISA0=1;   //For Configuring Sensors
   TRISAbits.TRISA1=1;
   TRISBbits.TRISB2=1;
   TRISBbits.TRISB3=1;
   TRISAbits.TRISA2=1;
   TRISAbits.TRISA3=1;
   TRISAbits.TRISA4=1;
   TRISBbits.TRISB4=0;
   TRISBbits.TRISB6=1;
   TRISBbits.TRISB8=1;
   TRISBbits.TRISB11=1;
   TRISBbits.TRISB12=1;
   TRISBbits.TRISB10=0;  // output for PWM 
   TRISBbits.TRISB14=0;
   TRISBbits.TRISB13=0;
   TRISBbits.TRISB15=0;
   TRISBbits.TRISB10=0;
   TRISBbits.TRISB9=0;    
   P1TCON=0x0000;
   P2TCON=0x0000;
   P1TPER = 65200;    // 1 KHz
   P2TPER = 65200;	// 1 KHz
   PWM1CON1bits.PMOD1=1;  //INVERT PWM
   PWM1CON1bits.PMOD2=1;
   PWM1CON1bits.PMOD3=1;
   PWM2CON1bits.PMOD1=1;
   PWM1CON1bits.PEN1H=1;
   PWM1CON1bits.PEN3H=1;
   PWM1CON1bits.PEN2L=1;
   PWM2CON1bits.PEN1L=1;
   P1OVDCONbits.POVD1H=1;
   P1OVDCONbits.POVD2L=1;
   P1OVDCONbits.POVD3H=1;
   P2OVDCONbits.POVD1L=1;
   P1OVDCONbits.POUT1H=1;
   P1OVDCONbits.POUT2L=1;
   P1OVDCONbits.POUT3H=1;
   P2OVDCONbits.POUT1L=1;
   P1TMR=0; 
   P2TMR=0;


   RPINR14bits.QEA1R=6;    //	pin: 15		
   RPINR14bits.QEB1R=8;    //   pin: 16

   RPINR16bits.QEA2R=11;    //	pin: 22		
   RPINR16bits.QEB2R=12;    //   pin: 23
}
void tyre1(float a)
{     P1DC1=P1TPER*2*(a);    	
 	  P1TCONbits.PTEN = 1;
}
void tyre2(float a){
     P1DC2=P1TPER*2*(a);	 
P1TCONbits.PTEN = 1;
}
void tyre3(float a)
{     P1DC3=P1TPER*2*(a);     
      P1TCONbits.PTEN = 1;
}
void tyre4(float a)
{     P2DC1=P2TPER*2*(a);     
       P2TCONbits.PTEN = 1; 
}

void ENCODER1(unsigned int maxcount1) 
{
    MAX1CNT=maxcount1;
	POS1CNT=100;
	QEI1CON= 0X0000;
	QEI1CONbits.PCDOUT=1;
	QEI1CONbits.SWPAB=1;       
	QEI1CONbits.QEIM=7;
}
void ENCODER1_bk(unsigned int maxcount1) 
{
    MAX1CNT=maxcount1;
	POS1CNT=100;
	QEI1CON= 0X0000;
	QEI1CONbits.PCDOUT=1;
	QEI1CONbits.SWPAB=0;       
	QEI1CONbits.QEIM=7;
}

void ENCODER2(unsigned int maxcount2) 
{
    MAX2CNT=maxcount2;
    POS2CNT=100;
	QEI2CON= 0X0000;
    QEI2CONbits.PCDOUT=1;
	QEI2CONbits.SWPAB=0;  
	QEI2CONbits.QEIM=7;	
}void ENCODER2_bk(unsigned int maxcount2) 
{
    MAX2CNT=maxcount2;
    POS2CNT=100;
	QEI2CON= 0X0000;
    QEI2CONbits.PCDOUT=1;
	QEI2CONbits.SWPAB=1;  
	QEI2CONbits.QEIM=7;	
}    void main()
{ 
  clk();  
  
  config();
  ENCODER1(65535);
  ENCODER2(65535);

while(1)
{
	  tyre1(0.45);//45 deg left
      tyre2(0.85);
      tyre3(0.93);
      tyre4(0.45);
if(POS2CNT>=9350)
{
	  tyre1(0.50);//stop
      tyre2(0.50);
      tyre3(0.50);
      tyre4(0.50);
	  POS2CNT=0;

/////////
__delay32(10000000);
break;
}
}
/*
while(1)
{
/*
	  tyre1(0.20);//stop
      tyre2(0.65);
      tyre3(0.75);
      tyre4(0.20);
	  
      tyre1(0.20);//stop
      tyre2(0.73);
      tyre3(0.90);
      tyre4(0.20);
	  
		if(POS2CNT>=4100)//2900//3400
		{
 	 	 tyre1(0.50);//stop
     	 tyre2(0.50);
     	 tyre3(0.50);
    	  tyre4(0.50);
        POS2CNT=0;
			__delay32(10000000);
			break;
		}
}
*/
while(1)
{
		tyre1(0.70);//stop
     	 tyre2(0.70);
     	 tyre3(0.70);
    	  tyre4(0.70);
if(POS2CNT>=2100)
{
         tyre1(0.50);//stop
     	 tyre2(0.50);
     	 tyre3(0.50);
    	 tyre4(0.50);

__delay32(20000000);
grip=1;

__delay32(20000000);
POS2CNT=0;
POS1CNT=0;
break;
}
}
ENCODER1(65535);
while(1)
{
	  tyre1(0.90);//stop
      tyre2(0.38);
      tyre3(0.38);
      tyre4(0.90);
if(POS1CNT>=10800)
{
		tyre1(0.50);//stop
     	 tyre2(0.50);
     	 tyre3(0.50);
    	  tyre4(0.50);
__delay32(10000000);

POS1CNT=0;
break;
}


}
ENCODER2(65535);
while(1)
{
		tyre1(0.70);//stop
     	 tyre2(0.70);
     	 tyre3(0.70);
    	  tyre4(0.70);
if(POS2CNT>=400)
{
         tyre1(0.50);//stop
     	 tyre2(0.50);
     	 tyre3(0.50);
    	 tyre4(0.50);
__delay32(20000000);
grip=0;

         tyre1(0.50);//stop
     	 tyre2(0.50);
     	 tyre3(0.50);
    	 tyre4(0.50);


__delay32(20000000);
POS2CNT=0;
POS1CNT=0;
break;
}
}
ENCODER1_bk(65535);
while(1)
{
		tyre1(0.30);//stop
     	 tyre2(0.30);
     	 tyre3(0.30);
    	  tyre4(0.30);

if(POS1CNT>=1200)//
{
		 tyre1(0.45);//stop
     	 tyre2(0.45);
     	 tyre3(0.45);
    	 tyre4(0.45);

__delay32(20000000);
		 tyre1(0.50);//stop
     	 tyre2(0.50);
     	 tyre3(0.50);
    	 tyre4(0.50);

__delay32(20000000);
	POS1CNT=0;
	POS2CNT=0;
break;

}

}
ENCODER2_bk(65535);
while(1)
{
		tyre1(0.70);//stop
     	 tyre2(0.70);
     	 tyre3(0.30);
    	  tyre4(0.30);

if(POS2CNT>=2600)//
{
		 tyre1(0.50);//stop
     	 tyre2(0.50);
     	 tyre3(0.50);
    	 tyre4(0.50);

__delay32(20000000);
	POS1CNT=0;
	POS2CNT=0;
break;

}

}
ENCODER2(65535);
while(1)
{

		 tyre1(0.60);//stop
     	 tyre2(0.60);
     	 tyre3(0.60);
    	 tyre4(0.60);
if(POS2CNT>=800)
{
         tyre1(0.50);//stop
     	 tyre2(0.50);
     	 tyre3(0.50);
    	 tyre4(0.50);
__delay32(200000);




POS2CNT=0;
POS1CNT=0;
break;
}
}

ENCODER2(65535);
while(1)
{

		 tyre1(0.80);//stop
     	 tyre2(0.80);
     	 tyre3(0.80);
    	 tyre4(0.80);
if(POS2CNT>=6300)
{
         tyre1(0.50);//stop
     	 tyre2(0.50);
     	 tyre3(0.50);
    	 tyre4(0.50);

__delay32(20000000);




POS2CNT=0;
POS1CNT=0;
break;
}
}
while(1)
{

		 tyre1(0.60);//stop
     	 tyre2(0.60);
     	 tyre3(0.60);
    	 tyre4(0.60);
if(POS2CNT>=800)
{
         tyre1(0.50);//stop
     	 tyre2(0.50);
     	 tyre3(0.50);
    	 tyre4(0.50);
__delay32(200000);




POS2CNT=0;
POS1CNT=0;
break;
}
}
ENCODER2_bk(65535);
while(1)
{
/*
	  tyre1(0.20);//stop
      tyre2(0.65);
      tyre3(0.75);
      tyre4(0.20);
	  */
      tyre1(0.90);//stop
      tyre2(0.20);
      tyre3(0.20);
      tyre4(0.80);
	  
		if(POS2CNT>=4000)//2900//3400
		{
 	 	 tyre1(0.50);//stop
     	 tyre2(0.50);
     	 tyre3(0.50);
    	  tyre4(0.50);
        POS2CNT=0;
			__delay32(10000000);
			break;
		}
}

ENCODER2(65535);
while(1)
{
		tyre1(0.70);//stop
     	 tyre2(0.70);
     	 tyre3(0.70);
    	  tyre4(0.70);
if(POS2CNT>=3300)
{
         tyre1(0.50);//stop
     	 tyre2(0.50);
     	 tyre3(0.50);
    	 tyre4(0.50);

__delay32(20000000);
grip=1;
__delay32(20000000);
		 tyre1(0.50);//stop
     	 tyre2(0.50);
     	 tyre3(0.50);
    	 tyre4(0.50);

__delay32(20000000);
POS2CNT=0;
POS1CNT=0;
break;
}
}
ENCODER1_bk(65535);
while(1)
{
		tyre1(0.30);//stop
     	 tyre2(0.30);
     	 tyre3(0.30);
    	  tyre4(0.30);

if(POS1CNT>=7100)//
{
		 tyre1(0.45);//stop
     	 tyre2(0.45);
     	 tyre3(0.45);
    	 tyre4(0.45);

__delay32(20000000);
		 tyre1(0.50);//stop
     	 tyre2(0.50);
     	 tyre3(0.50);
    	 tyre4(0.50);

__delay32(20000000);
	POS1CNT=0;
	POS2CNT=0;
break;

}

}
ENCODER2(65535);
while(1)
{
		tyre1(0.30);//stop
     	 tyre2(0.30);
     	 tyre3(0.70);
    	  tyre4(0.70);

if(POS2CNT>=2300)//
{
		 tyre1(0.50);//stop
     	 tyre2(0.50);
     	 tyre3(0.50);
    	 tyre4(0.50);
__delay32(20000000);
	POS1CNT=0;
	POS2CNT=0;
break;

}

}

ENCODER2(65535);
while(1)
{
		tyre1(0.80);//stop
     	 tyre2(0.80);
     	 tyre3(0.78);
    	  tyre4(0.78);
if(POS2CNT>=8500)
{
         tyre1(0.50);//stop
     	 tyre2(0.50);
     	 tyre3(0.50);
    	 tyre4(0.50);
__delay32(20000000);
grip=0;
__delay32(20000000);
         tyre1(0.50);//stop
     	 tyre2(0.50);
     	 tyre3(0.50);
    	 tyre4(0.50);
while(1);
__delay32(20000000);
POS2CNT=0;
POS1CNT=0;
break;
}
}
}