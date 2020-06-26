
#include <htc.h>
#include <xc.h>
#include <string.h>
#include <pic18f2550.h>
#include <math.h>
#include <delays.h>

#define _XTAL_FREQ 8000000

// CONFIG1L
#pragma config PLLDIV = 12      // PLL Prescaler Selection bits (Divide by 12 (48 MHz oscillator input))
#pragma config CPUDIV = OSC1_PLL2// System Clock Postscaler Selection bits ([Primary Oscillator Src: /1][96 MHz PLL Src: /2])
#pragma config USBDIV = 2       // USB Clock Selection bit (used in Full-Speed USB mode only; UCFG:FSEN = 1) (USB clock source comes from the 96 MHz PLL divided by 2)

// CONFIG1H
#pragma config FOSC = INTOSC_HS // Oscillator Selection bits (Internal oscillator, HS oscillator used by USB (INTHS))
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = OFF       // Internal/External Oscillator Switchover bit (Oscillator Switchover mode disabled)

// CONFIG2L
#pragma config PWRT = OFF       // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOR = OFF         // Brown-out Reset Enable bits (Brown-out Reset enabled in hardware only (SBOREN is disabled))
#pragma config BORV = 3         // Brown-out Reset Voltage bits (Minimum setting)
#pragma config VREGEN = OFF     // USB Voltage Regulator Enable bit (USB voltage regulator disabled)

// CONFIG2H
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))
#pragma config WDTPS = 32768    // Watchdog Timer Postscale Select bits (1:32768)

// CONFIG3H
#pragma config CCP2MX = ON      // CCP2 MUX bit (CCP2 input/output is multiplexed with RC1)
#pragma config PBADEN = ON      // PORTB A/D Enable bit (PORTB<4:0> pins are configured as analog input channels on Reset)
#pragma config LPT1OSC = OFF    // Low-Power Timer 1 Oscillator Enable bit (Timer1 configured for higher power operation)
#pragma config MCLRE = OFF      // MCLR Pin Enable bit (RE3 input pin enabled; MCLR pin disabled)

// CONFIG4L
#pragma config STVREN = ON      // Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
#pragma config LVP = OFF        // Single-Supply ICSP Enable bit (Single-Supply ICSP disabled)
#pragma config XINST = OFF      // Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode disabled (Legacy mode))

// CONFIG5L
#pragma config CP0 = OFF        // Code Protection bit (Block 0 (000800-001FFFh) is not code-protected)
#pragma config CP1 = OFF        // Code Protection bit (Block 1 (002000-003FFFh) is not code-protected)
#pragma config CP2 = OFF        // Code Protection bit (Block 2 (004000-005FFFh) is not code-protected)
#pragma config CP3 = OFF        // Code Protection bit (Block 3 (006000-007FFFh) is not code-protected)

// CONFIG5H
#pragma config CPB = OFF        // Boot Block Code Protection bit (Boot block (000000-0007FFh) is not code-protected)
#pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM is not code-protected)

// CONFIG6L
#pragma config WRT0 = OFF       // Write Protection bit (Block 0 (000800-001FFFh) is not write-protected)
#pragma config WRT1 = OFF       // Write Protection bit (Block 1 (002000-003FFFh) is not write-protected)
#pragma config WRT2 = OFF       // Write Protection bit (Block 2 (004000-005FFFh) is not write-protected)
#pragma config WRT3 = OFF       // Write Protection bit (Block 3 (006000-007FFFh) is not write-protected)

// CONFIG6H
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) are not write-protected)
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot block (000000-0007FFh) is not write-protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM is not write-protected)

// CONFIG7L
#pragma config EBTR0 = OFF      // Table Read Protection bit (Block 0 (000800-001FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR1 = OFF      // Table Read Protection bit (Block 1 (002000-003FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR2 = OFF      // Table Read Protection bit (Block 2 (004000-005FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR3 = OFF      // Table Read Protection bit (Block 3 (006000-007FFFh) is not protected from table reads executed in other blocks)

// CONFIG7H
#pragma config EBTRB = OFF      // Boot Block Table Read Protection bit (Boot block (000000-0007FFh) is not protected from table reads executed in other blocks)


unsigned int PE1        = 0;
unsigned int NE1        = 0;

unsigned int PE2        = 0;
unsigned int NE2        = 0;

unsigned int FLAG1      = 0;
unsigned int FLAG2      = 0;

unsigned int DIST1      = 0;
unsigned int DIST2      = 0;

unsigned int TIME1_T1   = 0;
unsigned int TIME1_T2   = 0;

unsigned int TIME2_T1   = 0;
unsigned int TIME2_T2   = 0;

unsigned int DIFF_TIME1 = 0;
unsigned int DIFF_TIME2 = 0;

unsigned int TRIG_P1    = 0;
unsigned int TRIG_P2    = 0;

unsigned int  ON        = 0;

unsigned int  F1        = 0;
unsigned int  F2        = 0;

unsigned long int  DATA1		= 0;
unsigned long int  DATA2		= 0;

unsigned int  COUNT1  	= 0;
unsigned int  COUNT2  	= 0;

unsigned int  AVG_COUNT1  	= 0;
unsigned int  AVG_COUNT2  	= 0;

unsigned long int  AVG_DATA1 = 0;
unsigned long int  AVG_DATA2	 = 0;

unsigned int  THRES1  	= 0;
unsigned int  THRES2  	= 0;

void interrupt isr()
{


	if(PIR1bits.CCP1IF)
	{	
	
		if(PE1==1)
		{	
			FLAG1 = 0;
			TIME1_T1 = (CCPR1L | (CCPR1H<<8));
			PE1 = 0;
			CCP1CON=0x04; // Capture every falling edge
		}
	    else
		{
			PE1 = 1;
			PIE1bits.CCP1IE=0;
			PIE2bits.CCP2IE=0;
			TIME1_T2   = (CCPR1L | (CCPR1H<<8));
			DIFF_TIME1 = TIME1_T2 - TIME1_T1 + 1;
	
			CCP1CON    = 0x05;// Capture every falling edge
			//DIFF_TIME1 = (DIFF_TIME1*4)/3;
			//DIST1      = (DIFF_TIME1*17)/1000;
			DIST1      = DIFF_TIME1;
			FLAG1      = 1;

		//	PIE1bits.CCP1IE=1;
		//	PIR1bits.CCP1IF=0;

		}	
	PIR1bits.CCP1IF=0;
	}

    //*************


/*
	if(PIR2bits.CCP2IF)
	{
		if(PE2==1)
		{
			FLAG2 = 0;
			PE2   = 0;
			TIME2_T1 = (CCPR1L | (CCPR1H<<8));
			CCP2CON  = 0x04; // Capture every falling edge
		}
	    else
		{
			PIE1bits.CCP1IE=0;
			PIE2bits.CCP2IE=0;
			PE2 = 1;
			TIME2_T2   = (CCPR2L | (CCPR2H<<8));
			DIFF_TIME2 = TIME2_T2 - TIME2_T1 + 1;
			
			CCP2CON    =  0x05; // Capture every rising edge
			//DIFF_TIME2 = (DIFF_TIME2*4)/3;
			//DIST2 = (DIFF_TIME2*17)/1000;
			DIST2 = DIFF_TIME2;

			PIR2bits.CCP2IF=0;			
	
			FLAG2 = 1;
		}
	
	PIR2bits.CCP2IF=0;
	}
*/
}

void TRIGGERING_SONAR()
{
PORTAbits.RA3 = 1;
for(TRIG_P1 = 0 ; TRIG_P1 < 5 ; TRIG_P1++);
PORTAbits.RA3 = 0;

PORTAbits.RA5 = 1;
for(TRIG_P2 = 0 ; TRIG_P2 < 5 ; TRIG_P2++);
PORTAbits.RA5 = 0;
}

void main()
{
ADCON1 = 0xFF; // Configure AN pins as digital
//**************
TRISCbits.TRISC2 = 1;  //ccp1//Echo1
TRISCbits.TRISC1 = 1;  //ccp2//Echo2

//**************
TRISAbits.TRISA1 = 0;  //PlayE
TRISAbits.TRISA3 = 0;  //trigger1
TRISAbits.TRISA5 = 0;  //trigger2
TRISAbits.TRISA4 = 0;  //LED Relay

//**************
PORTA = 0x00;
PORTC = 0x00;
//**************

CCP1CON = 0x05; 	  // Capture every rising edge
CCP2CON = 0x05;       // Capture every rising edge

INTCONbits.GIE  = 1;
INTCONbits.PEIE = 1;

PIE1bits.CCP1IE = 1;
PIR1bits.CCP1IF = 0;

PIE2bits.CCP2IE = 0;
PIR2bits.CCP2IF = 0;

T1CON   = 0x21;      //prescale by 2

//**************    //initial triggering
//TRIGGERING_SONAR();
//**************

while(1)
{

if(FLAG1 == 0 && FLAG2 == 0)
TRIGGERING_SONAR();

/*
if(FLAG2 == 1)
{
		COUNT2++;
		if(COUNT2 > 50 && COUNT2 < 1050)
		{DATA2 = DATA2 + DIST2;}
	
		else if (COUNT2 > 1050 && F2 == 0)
		{
		THRES2 = DATA2/1000;
		F2 = 1;
		}	
	
		if(AVG_COUNT2 < 3 && F2 == 1)
		{
			F2 = 1;
			
			if(DIST2 > 50)
			{
			AVG_DATA2 = AVG_DATA2 + DIST2;
			AVG_COUNT2++;
			}
		}
			
		if(AVG_COUNT2 > 2 && F2 == 1)
		{
		F2 = 1;
		AVG_DATA2 = AVG_DATA2/3;

		if(AVG_DATA2 < 150 && AVG_DATA2 > 70)
		{
		//PORTAbits.RA1 = 1;
		PORTAbits.RA4 = 1;
		//for(ON = 0 ; ON < 1000 ; ON++);
		Delay1KTCYx(50);
		PORTAbits.RA4 = 0;
		PORTAbits.RA1 = 0;
		FLAG2=0;
		AVG_DATA2 = 0;	
		AVG_COUNT2 = 0;
		}
		AVG_DATA2 = 0;	
		AVG_COUNT2 = 0;
		}
	
		PIE2bits.CCP2IE = 1;
		TRIGGERING_SONAR();		
//		COUNT2++;
//		if(COUNT2 > 3 && COUNT2 < 1000)
//		{DATA2 = DATA2 + DIST2;}
//	
//		else if (COUNT2 > 1000 && F2 == 0)
//		{
//		THRES2 = DATA2/1000;
//		F2 = 1;
//		}	
//	
//		if(DIST2 < 95 && COUNT2 > 1000)
//		{
//		//PORTAbits.RA1 = 1;
//		PORTAbits.RA4 = 1;
//		//for(ON = 0 ; ON < 1000 ; ON++);
//		Delay1KTCYx(50);
//		PORTAbits.RA4 = 0;
//		PORTAbits.RA1 = 0;
//		FLAG2=0;
//		}
//		PIE2bits.CCP2IE = 1;
//		TRIGGERING_SONAR();		
}
*/
if(FLAG1 == 1)
{		
		COUNT1++;
		if(COUNT1 > 40 && COUNT1 < 1050)
		{DATA1 = DATA1 + DIST1;}
	
		else if(COUNT1 > 1050 && F1 == 0)
		{
		THRES1 = DATA1/1000;
		THRES1 = THRES1 * 0.8;
		F1 = 1;
		}

		
		if(DIST1 < 20 && COUNT1 > 1050)
		{
		//PORTAbits.RA1 = 1;
		PORTAbits.RA4 = 1;
		//for(ON = 0 ; ON < 1000; ON++);
		Delay1KTCYx(50);
		PORTAbits.RA4 = 0;
		PORTAbits.RA1 = 0;
		FLAG1=0;
		}
		PIE1bits.CCP1IE = 1;
		TRIGGERING_SONAR();	
		
}

}
}