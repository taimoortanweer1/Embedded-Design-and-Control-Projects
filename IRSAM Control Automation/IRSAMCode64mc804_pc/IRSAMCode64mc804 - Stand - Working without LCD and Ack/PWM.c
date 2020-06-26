#include<p33fj64mc804.h>
#include<libpic30.h>
#pragma code WDT=OFF
#define pwm1 OC1RS
#define MOTOR_PWM_FREQ 500
#define FCY 40000000UL

float error=0;




void PWM_CONFIG()
{ 
 
   
    TRISCbits.TRISC6 = 0;
    TRISCbits.TRISC7 = 0;
	P1TCON = 0x0000;
    P2TCONbits.PTCKPS = 2;//postscaler 16
    P2TPER = 5580;  //2480//1khz     //5580;//430Hz
    PWM2CON1bits.PMOD1 = 1;
    PWM2CON1bits.PEN1L = 0;
   	PWM2CON1bits.PEN1H = 1;
    P2TMR = 0;

 //   P2DC1 = P2TPER*2*(0.50);
 //   P2TMR = 0;
 //   P2TCONbits.PTEN = 1;

}

void PWM_SERVO1_CONFIG()
{ 
   AD1PCFGL=0xFFFF;
   PR2=0;
   TMR2=0; 
   OC1CON=0x0006; // PWM mode without fault protection
   // output for PWM 
   P1TCON=0x0000;
   P2TCON=0x0000;
   P1TCONbits.PTCKPS = 3; //post scalar 16	 
   P1TPER = 625;    // 1 KHz
   //P2TPER = 65200;	// 1 KHz
   P2TPER = 625;	// 1 KHz
   PWM2CON1bits.PMOD1 = 1;
   PWM2CON1bits.PEN1H = 1;
   P2OVDCONbits.POVD1H= 1;
   P2OVDCONbits.POUT1H= 1;
   PWM2CON1bits.PMOD1 = 0;
   PWM2CON1bits.PEN1L = 0;
   P2OVDCONbits.POVD1L= 0;
   P2OVDCONbits.POUT1L= 0;
   P1TMR=0; 
   P2TMR=0;
}
void PWM_SERVO2_CONFIG()
{ 
 //  AD1PCFGL=0xFFFF;
   PR2=65200;
   TMR2=0; 
  // OC1CON=0x0006; // PWM mode without fault protection
   // output for PWM 
   //P1TCON=0x0000;
   P2TCON=0x0000;  
   
 //  P1TPER = 65200;    // 1 KHz
   P2TPER = 85000;    // 1 KHz

   PWM2CON1bits.PMOD1 = 1;
   PWM2CON1bits.PEN1H = 0;
   P2OVDCONbits.POVD1H= 0;
   P2OVDCONbits.POUT1H= 0;
   PWM2CON1bits.PMOD1 = 0;
   PWM2CON1bits.PEN1L = 1;
   P2OVDCONbits.POVD1L= 1;
   P2OVDCONbits.POUT1L= 1;
   //P1TMR=0; 
   P2TMR=0;
}

void PWM_DUTY_CYCLE(float a)
{ 	
    P2DC1 = P2TPER*2*(0.50);
  	//P2TMR = 0;
    P2TCONbits.PTEN = 1;

}
