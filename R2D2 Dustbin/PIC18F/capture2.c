#include <htc.h>
#include <xc.h>
#include <string.h>
#include <pic18f2550.h>
#include <math.h>

#define _XTAL_FREQ 48000000
//#define _XTAL_FREQ 10000000


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

int myabs( int num );
char edge1=0,capture1=0;
char edge2=0,capture2=0;

int told1,tnew1,tword1;
int temp1=0,dist1=0;

int told2,tnew2,tword2;
int temp2=0,dist2=0;

void interrupt isr()
{
	if(PIR1bits.CCP1IF)
	{
		if(edge1==0)
		{
			CCP1CON=0x05; // Capture every rising edge
			//told = 256*CCPR1H+CCPR1L;
			told1 = (CCPR1L | (CCPR1H<<8));
			edge1=1;
		}
	    else
		{
			//tnew=256*CCPR1H+CCPR1L;
			tnew1 = (CCPR1L | (CCPR1H<<8));
			capture1=1;
			edge1=0;
		}	
	PIR1bits.CCP1IF=0;
	}

	if(PIR2bits.CCP2IF)
	{
		if(edge2==0)
		{
			CCP2CON=0x05; // Capture every rising edge
			//told = 256*CCPR1H+CCPR1L;
			told2 = (CCPR2L | (CCPR2H<<8));
			edge2=1;
		}
	    else
		{
			//tnew=256*CCPR1H+CCPR1L;
			tnew2 = (CCPR2L | (CCPR2H<<8));
			capture2=1;
			edge2=0;
		}	
	PIR2bits.CCP2IF=0;
	}
}

int calculate_distance_2()
{	
	if(capture2==1)
	{
		PIE2bits.CCP2IE=0;
		capture2=0;
		tword2=~told2+tnew2+1;
		CCP2CON=0x04;
		temp2= (tword2*4)/3;
		dist2= (temp2*17)/1000;

		//delay_ms(100);
		PIE2bits.CCP2IE=1;
		PIR2bits.CCP2IF=0;
	return(dist2);
	}
}

int calculate_distance_1()
{	

	if(capture1==1)
	{
		PIE1bits.CCP1IE=0;
		capture1=0;
		tword1=~told1+tnew1+1;
		CCP1CON=0x04;
		temp1= (tword1*4)/3;
		dist1= (temp1*17)/1000;
		//dist1 = myabs(dist1);
		//delay_ms(100);
		PIE1bits.CCP1IE=1;
		PIR1bits.CCP1IF=0;
	return(dist1);
	}
}

int myabs( int num )
{
	int a = num;
	if (a>=0)
		return a;
	else
		return a*-1;
}

void main()
{
int b = 0 , a = 0 , c1=0,c2=0;
ADCON1 = 0xFF; // Configure AN pins as digital
//ADCON0 = 0x0F;
TRISCbits.TRISC2 = 1;  //ccp1//Echo1
TRISCbits.TRISC1 = 1;  //ccp2//Echo2

//****************
TRISCbits.TRISC0 = 0; //Trigger2 CCP2 left 'b'
//****************

TRISAbits.TRISA4 = 0;  //Trigger1
//TRISAbits.TRISA5 = 0;  

TRISAbits.TRISA1 = 0;  //PlayE
PORTA = 0x00;
PORTC = 0x00;
PORTAbits.RA1 = 0;

CCP1CON = 0x04; // Capture every falling edge
CCP2CON = 0x04; // Capture every falling edge

T1CON   = 0x21;

INTCONbits.GIE  = 1;
INTCONbits.PEIE = 1;

PIE1bits.CCP1IE = 1;
PIR1bits.CCP1IF = 0;

PIE2bits.CCP2IE = 1;
PIR2bits.CCP2IF = 0;

PORTAbits.RA1 = 0;
while(1)
{
PORTAbits.RA4 = 1;
PORTCbits.RC0 = 1;
for(c1 = 0 ; c1 < 50 ; c1++);
PORTAbits.RA4 = 0;
PORTCbits.RC0 = 0;

for(c1 = 0 ; c1 < 1000 ; c1++);
b = calculate_distance_1();


for(c1 = 0 ; c1 < 1000 ; c1++);
a = calculate_distance_2();


if(a > 7 || b > 6)
{
PORTAbits.RA1 = 1;
for(c1 = 0 ; c1 < 10 ; c1++);
b=0;
a=0;
PORTAbits.RA1 = 0;
}

}

}