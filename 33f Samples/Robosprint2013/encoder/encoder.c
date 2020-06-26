#include<p33fj64mc802.h>
#include<libpic30.h>     
#pragma code WDT=OFF

unsigned int count=0,a=0;

unsigned int d_rpm_fl=0, d_rpm_fr=0;
float pwm=0.5f;
float error=0, kp=0.001f, ki=0.04f, c_error=0, p_err=0, int_err=0; //0.001 0.04
float a_rpm=0, a_rpm2=0;
unsigned int pos=0, pos2=0;
float error2=0, c_error2=0, p_err2=0, int_err2=0;
unsigned int SUM_POS1 = 0, SUM_POS2 = 0;
unsigned int STOPVALUE = 0; 

#define pwm1 OC1RS

#define s1 PORTAbits.RA0
#define s2 PORTAbits.RA1
#define s3 PORTBbits.RB2
#define s4 PORTBbits.RB3
#define s5 PORTAbits.RA2
#define s6 PORTAbits.RA3
#define s7 PORTAbits.RA4
#define s8 PORTBbits.RB4

void clk()
{
	CLKDIVbits.PLLPRE=0;
	CLKDIVbits.PLLPOST=0;
	PLLFBD=41;
	while(OSCCONbits.LOCK!=1);
}

void config()
{
   AD1PCFGL=0xFFFF;

   PR2=1956;
   TMR2=0;   
   OC1CON=0x0006; 

   TRISAbits.TRISA0=1;   //For Configuring Sensors
   TRISAbits.TRISA1=1;
   TRISBbits.TRISB2=1;
   TRISBbits.TRISB3=1;
   TRISAbits.TRISA2=1;
   TRISAbits.TRISA3=1;
   TRISAbits.TRISA4=1;
   TRISBbits.TRISB4=1;

   RPOR4bits.RP8R=18;   //RB8 For PWM
   TRISBbits.TRISB8=0;

   TRISBbits.TRISB9=0;    //For PWM2L1
   TRISBbits.TRISB11=0;   //For PWM1L3
   TRISBbits.TRISB13=0;   //For PWM1L2
   TRISBbits.TRISB15=0;   //For PWM1L1
  
   P1TCON=0x0000;
   P2TCON=0x0000;

   P1TPER = 65533;    // 20 KHz
   P2TPER = 65533;	// 20 KHz
    
   PWM1CON1bits.PMOD1=1;
   PWM1CON1bits.PMOD2=1;
   PWM1CON1bits.PMOD3=1;

   PWM2CON1bits.PMOD1=1;
  
   PWM1CON1bits.PEN1L=1;
   PWM1CON1bits.PEN2L=1;
   PWM1CON1bits.PEN3L=1;

   PWM2CON1bits.PEN1L=1;
    
   P1OVDCONbits.POVD1L=1;  
   P1OVDCONbits.POVD2L=1;
   P1OVDCONbits.POVD3L=1;

   P2OVDCONbits.POVD1L=1;
   
   P1TMR=0;

   P2TMR=0;

   RPINR14bits.QEA1R=6;    //	pin: 15		
   RPINR14bits.QEB1R=7;    //	pin: 16	 			
   TRISBbits.TRISB6=1;
   TRISBbits.TRISB7=1;

   RPINR16bits.QEA2R=12;   //	pin: 23		
   RPINR16bits.QEB2R=14;   //   pin: 25				
   TRISBbits.TRISB12=1;
   TRISBbits.TRISB14=1;

   SRbits.IPL=0;           // To Enable Interrupts
   INTCON1bits.NSTDIS=0;
   IEC3bits.QEI1IE=1;
   IEC4bits.QEI2IE=1;
}

void tyre1(float a)
{
     P1DC1=P1TPER*2*(a);	//RB15   PWM1L3    Pin: 26
     P1TCONbits.PTEN = 1;
}

void tyre2(float a)
{
     P1DC2=P1TPER*2*(a);	//RB13   PWM1L2    Pin: 24
	 P1TCONbits.PTEN = 1;
}

void tyre3(float a)
{
     P1DC3=P1TPER*2*(a);	//RB11   PWM1L1    Pin: 22
     P1TCONbits.PTEN = 1;
}

void tyre4(float a)
{
     P2DC1=P2TPER*2*(a);	//RB9    PWM2L1    Pin: 18
     P2TCONbits.PTEN = 1; 
}

void tyre5(float a)   		//RB8
{
   pwm1=PR2*a;
   T2CONbits.TON=1;
}

void ENCODER1(unsigned int maxcount1) 
{
    MAX1CNT=maxcount1;
	POS1CNT=100;
	QEI1CON= 0X0000;
	QEI1CONbits.PCDOUT=1;
	QEI1CONbits.SWPAB=0;       
	QEI1CONbits.QEIM=7;
    IFS3bits.QEI1IF=0;
}

void ENCODER2(unsigned int maxcount2) 
{
    MAX2CNT=maxcount2;
    POS2CNT=100;
	QEI2CON= 0X0000;
    QEI2CONbits.PCDOUT=1;
	QEI2CONbits.SWPAB=1;  
	QEI2CONbits.QEIM=7;
    IFS4bits.QEI2IF=0;	
}
void __attribute__((__interrupt__, no_auto_psv)) _QEI1Interrupt()
{
   IFS3bits.QEI1IF=0;
   count++;
}

void __attribute__((__interrupt__, no_auto_psv)) _QEI2Interrupt()
{
    IFS4bits.QEI2IF=0;
    count++; 
}
void main()
{
  clk();
  config();
	ENCODER1(65530);
	
    ENCODER2(65530);

    tyre1(0.8);
    tyre2(0.8);
    tyre3(0.8);
  while(POS2CNT<65000);
while(1);

}
