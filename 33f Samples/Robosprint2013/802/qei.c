#include<p33fj64mc802.h>
#include<libpic30.h>     
#pragma code WDT=OFF

/*unsigned int d_rpm_fl=0, d_rpm_fr=0;
float pwm=0.5f;
float error=0, kp=0.001f, ki=0.01f, c_error=0, p_err=0, int_err=0; //0.001 0.04
float a_rpm=0, a_rpm2=0;
unsigned int pos=0, pos2=0;
float error2=0, c_error2=0, p_err2=0, int_err2=0;
unsigned int SUM_POS1 = 0, SUM_POS2 = 0;
unsigned int STOPVALUE = 0;*/ 

float u=0,kp=0.1;
signed int err=0;
unsigned int stp=0;

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

   PR2=2000;
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

   P1TPER = 2000;    // 20 KHz
   P2TPER = 2000;	// 20 KHz
    
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

void qei()
{
    MAX1CNT=65535;
	POS1CNT=100;
	QEI1CON= 0X0000;
	QEI1CONbits.PCDOUT=1;
    QEI1CONbits.UPDN=0;
	QEI1CONbits.SWPAB=0;	
	QEI1CONbits.QEIM=7;
    IFS3bits.QEI1IF=0;

	MAX2CNT=65535;
	POS2CNT=100;
	QEI2CON= 0X0000;
	QEI2CONbits.PCDOUT=1;
    QEI2CONbits.UPDN=0;
	QEI2CONbits.SWPAB=1;
	QEI2CONbits.QEIM=4;
    IFS4bits.QEI2IF=0;
}

void imtimer20ms(void)
{
	T1CONbits.TON = 0; 
	T1CONbits.TCS = 0; 
	T1CONbits.TGATE = 0; 
	T1CONbits.TCKPS = 0b10; 
	TMR1 = 0x00; 
	PR1 = 12500;  
	IPC0bits.T1IP = 0x01;  
}

void timer1on(void)
{
	T1CONbits.TON = 1;
    IFS0bits.T1IF=0;
	IEC0bits.T1IE=1; 
	TMR1 = 0x00;
}

void timer1off(void)
{
	T1CONbits.TON = 0;
	IEC0bits.T1IE=0; 
	TMR1 = 0x00;
}

void encoder()
{
  timer1off();
  timer1on();
  if(POS1CNT>=stp)
  {
    tyre1(0.5);
    tyre2(0.5);
    tyre3(0.5);
    while(1);
  }
  if(POS1CNT==POS2CNT)
  {
    err=0;
    u=kp*err;
    tyre1(0.6);
    tyre2(0.6+u);
    tyre3(0.5);
    while(POS1CNT==POS2CNT);
  }
  if(POS1CNT!=POS2CNT)
  {
    if(POS1CNT>POS2CNT)
    {
      err=1;
      u=kp*err;
      tyre1(0.6);
      tyre2(0.6+u);
      tyre3(0.5);
      while(POS1CNT>POS2CNT);
    }   
    if(POS1CNT<POS2CNT)
    {
      err=-1;
      u=kp*err;
      tyre1(0.6);
      tyre2(0.6+u);
      tyre3(0.5);
      while(POS1CNT<POS2CNT);
    }
  } 
}

void __attribute__((__interrupt__, no_auto_psv)) _T1Interrupt(void)
{
    encoder();
}

/*void ENCODER1(unsigned int maxcount1) 
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
	QEI2CONbits.SWPAB=1;  
	QEI2CONbits.QEIM=7;	
}

void SET_INTR_20MS(void)
{
	T1CONbits.TON = 0; 
	T1CONbits.TCS = 0; 
	T1CONbits.TGATE = 0; 
	T1CONbits.TCKPS = 0b10; 
	TMR1 = 0x00; 
	PR1 = 12500;  
	IPC0bits.T1IP = 0x01;  
}

void TIMER1_ON(void)
{
	T1CONbits.TON = 1;
	IEC0bits.T1IE=1; 
	TMR1 = 0x00;
}

void TIMER1_OFF(void)
{
	T1CONbits.TON = 0;
	IEC0bits.T1IE=0; 
	TMR1 = 0x00;
}

void pi_rpmfl(int d_rpm_fl)
{
	a_rpm2=3*pos;
	error=(float)(d_rpm_fl - a_rpm2);
	p_err = (float)(error * kp);
	c_error=c_error+error;
	int_err=(float)(c_error*ki);
	pwm= (float)(.55 + (p_err+int_err)/100);

	if(pwm>0.65)
	{
		pwm=0.65;
}
	tyre1(pwm);
}

void pi_rpmfr(int d_rpm_fr)
{
	a_rpm=pos2*3;
	error2=(float)(d_rpm_fr - a_rpm);
	p_err2 = (float)(error2 * kp);
	c_error2=c_error2+error2;
	int_err2=(float)(c_error2*ki);
	pwm=(float)(0.57 + (p_err2+int_err2)/1000);
   
	if(pwm>0.65)
	{
		pwm=0.65;
	}

	tyre2(pwm);
}

void FLUSH_PI(void)
{
	error=0,c_error=0,p_err=0,int_err=0; 
	a_rpm=0,a_rpm2=0;
	error2=0,c_error2=0,p_err2=0,int_err2=0;
}

void __attribute__((__interrupt__, no_auto_psv)) _T1Interrupt(void)
{
	if (T1CONbits.TON != 1)
	return;
	IFS0bits.T1IF = 0;
	T1CONbits.TON = 0;
	TMR1 = 0;
	pos2=POS2CNT-100;
	pos=POS1CNT-100;
	TMR1 = 0;
	SUM_POS1 += POS1CNT-100;
	if(d_rpm_fr==0||d_rpm_fl==0 || (SUM_POS1 >= STOPVALUE))
	{
		tyre1(0.5);
		tyre2(0.5);
		SUM_POS1 = 0;
		TIMER1_OFF();
		FLUSH_PI();
	}
	else
	{
		pi_rpmfr(d_rpm_fr);
		pi_rpmfl(d_rpm_fl);
	}
	POS1CNT=100;
	POS2CNT=100;
	T1CONbits.TON = 1;
}*/

void pi()
{
   float u=0,kp=0.04;
   signed int err=0;
   while(1)
   {
    if((s1==1)&&(s2==1)&&(s3==1)&&(s4==1)&&(s5==1)&&(s6==1)&&(s7==1)&&(s8==1))
    {
      tyre1(0.62);
      tyre2(0.6375);
      tyre3(0.5);
     while((s1==1)&&(s2==1)&&(s3==1)&&(s4==1)&&(s5==1)&&(s6==1)&&(s7==1)&&(s8==1));
    }
    if((s1==0)&&(s2==0)&&(s3==0)&&(s4==1)&&(s5==1)&&(s6==0)&&(s7==0)&&(s8==0))
    {
      err=0;
      u=kp*err; 
      tyre1(0.62);
      tyre2(0.6375);
      tyre3(0.5);
      while((s1==0)&&(s2==0)&&(s3==0)&&(s4==1)&&(s5==1)&&(s6==0)&&(s7==0)&&(s8==0));
    }
    if((s1==0)&&(s2==0)&&(s3==0)&&(s4==0)&&(s5==1)&&(s6==0)&&(s7==0)&&(s8==0))
    {
      err=-1;
      u=kp*err; 
      tyre1(0.62+u);
      tyre2(0.6375);
      tyre3(0.5);
     while((s1==0)&&(s2==0)&&(s3==0)&&(s4==0)&&(s5==1)&&(s6==0)&&(s7==0)&&(s8==0));
    }
    if((s1==0)&&(s2==0)&&(s3==0)&&(s4==0)&&(s5==1)&&(s6==1)&&(s7==0)&&(s8==0))
    {
      err=-2; 
      u=kp*err; 
      tyre1(0.62+u);
      tyre2(0.6375);
      tyre3(0.5);
      while((s1==0)&&(s2==0)&&(s3==0)&&(s4==0)&&(s5==1)&&(s6==1)&&(s7==0)&&(s8==0));
    }
    if((s1==0)&&(s2==0)&&(s3==0)&&(s4==0)&&(s5==0)&&(s6==1)&&(s7==0)&&(s8==0))
    {
      err=-3;
      u=kp*err; 
      tyre1(0.62+u);
      tyre2(0.6375);
      tyre3(0.5);
     while((s1==0)&&(s2==0)&&(s3==0)&&(s4==0)&&(s5==0)&&(s6==1)&&(s7==0)&&(s8==0));
    }
    if((s1==0)&&(s2==0)&&(s3==0)&&(s4==0)&&(s5==0)&&(s6==1)&&(s7==1)&&(s8==0))
    {
      err=-4;
      u=kp*err; 
      tyre1(0.62+u);
      tyre2(0.6375);
      tyre3(0.5);
      while((s1==0)&&(s2==0)&&(s3==0)&&(s4==0)&&(s5==0)&&(s6==1)&&(s7==1)&&(s8==0));
    }
    if((s1==0)&&(s2==0)&&(s3==0)&&(s4==0)&&(s5==0)&&(s6==0)&&(s7==1)&&(s8==0))
    {
      err=-5; 
      u=kp*err; 
      tyre1(0.62+u);
      tyre2(0.6375);
      tyre3(0.5);
      while((s1==0)&&(s2==0)&&(s3==0)&&(s4==0)&&(s5==0)&&(s6==0)&&(s7==1)&&(s8==0));
    }
    if((s1==0)&&(s2==0)&&(s3==0)&&(s4==0)&&(s5==0)&&(s6==0)&&(s7==1)&&(s8==1))
    {
      err=-6;
      u=kp*err; 
      tyre1(0.62+u);
      tyre2(0.6375);
      tyre3(0.5);
      while((s1==0)&&(s2==0)&&(s3==0)&&(s4==0)&&(s5==0)&&(s6==0)&&(s7==1)&&(s8==1));
    }
    if((s1==0)&&(s2==0)&&(s3==0)&&(s4==0)&&(s5==0)&&(s6==0)&&(s7==0)&&(s8==1))
    {
      err=-7;
      u=kp*err; 
      tyre1(0.62+u);
      tyre2(0.6375);
      tyre3(0.5);
      while((s1==0)&&(s2==0)&&(s3==0)&&(s4==0)&&(s5==0)&&(s6==0)&&(s7==0)&&(s8==1));
    }
    if((s1==0)&&(s2==0)&&(s3==0)&&(s4==1)&&(s5==0)&&(s6==0)&&(s7==0)&&(s8==0))
    {
      err=1;
      u=kp*err; 
      tyre1(0.62);
      tyre2(0.6375-u);
      tyre3(0.5);
      while((s1==0)&&(s2==0)&&(s3==0)&&(s4==1)&&(s5==0)&&(s6==0)&&(s7==0)&&(s8==0));
    }
    if((s1==0)&&(s2==0)&&(s3==1)&&(s4==1)&&(s5==0)&&(s6==0)&&(s7==0)&&(s8==0))
    {
      err=2; 
      u=kp*err; 
      tyre1(0.62);
      tyre2(0.6375-u);
      tyre3(0.5);
      while((s1==0)&&(s2==0)&&(s3==1)&&(s4==1)&&(s5==0)&&(s6==0)&&(s7==0)&&(s8==0));
    }
    if((s1==0)&&(s2==0)&&(s3==1)&&(s4==0)&&(s5==0)&&(s6==0)&&(s7==0)&&(s8==0))
    {
      err=3;
      u=kp*err; 
      tyre1(0.62);
      tyre2(0.6375-u);
      tyre3(0.5);
      while((s1==0)&&(s2==0)&&(s3==1)&&(s4==0)&&(s5==0)&&(s6==0)&&(s7==0)&&(s8==0));
    }
    if((s1==0)&&(s2==1)&&(s3==1)&&(s4==0)&&(s5==0)&&(s6==0)&&(s7==0)&&(s8==0))
    {
      err=4;
      u=kp*err; 
      tyre1(0.62);
      tyre2(0.6375-u);
      tyre3(0.5);
      while((s1==0)&&(s2==1)&&(s3==1)&&(s4==0)&&(s5==0)&&(s6==0)&&(s7==0)&&(s8==0));
    }
    if((s1==0)&&(s2==1)&&(s3==0)&&(s4==0)&&(s5==0)&&(s6==0)&&(s7==0)&&(s8==0))
    {
      err=5; 
      u=kp*err; 
      tyre1(0.62);
      tyre2(0.6375-u);
      tyre3(0.5);
      while((s1==0)&&(s2==1)&&(s3==0)&&(s4==0)&&(s5==0)&&(s6==0)&&(s7==0)&&(s8==0));
    }
    if((s1==1)&&(s2==1)&&(s3==0)&&(s4==0)&&(s5==0)&&(s6==0)&&(s7==0)&&(s8==0))
    {
      err=6;
      u=kp*err; 
      tyre1(0.62);
      tyre2(0.6375-u);
      tyre3(0.5);
      while((s1==1)&&(s2==1)&&(s3==0)&&(s4==0)&&(s5==0)&&(s6==0)&&(s7==0)&&(s8==0));
    }
    if((s1==1)&&(s2==0)&&(s3==0)&&(s4==0)&&(s5==0)&&(s6==0)&&(s7==0)&&(s8==0))
    {
      err=7;
      u=kp*err; 
      tyre1(0.62);
      tyre2(0.6375-u);
      tyre3(0.5);
      while((s1==1)&&(s2==0)&&(s3==0)&&(s4==0)&&(s5==0)&&(s6==0)&&(s7==0)&&(s8==0));
    }
    if((s1==0)&&(s2==0)&&(s3==0)&&(s4==0)&&(s5==0)&&(s6==0)&&(s7==0)&&(s8==0))
    {
      tyre1(0.5);
      tyre2(0.5);
      tyre3(0.5);
     while((s1==0)&&(s2==0)&&(s3==0)&&(s4==0)&&(s5==0)&&(s6==0)&&(s7==0)&&(s8==0));
    }
  }  
}

void main()
{
  clk();
  config();
  //qei();
  //imtimer20ms();
  //stp=5000;
  //timer1on();
  tyre1(0.9);
  tyre2(0.9);
  tyre3(0.9);
  while(1);
}