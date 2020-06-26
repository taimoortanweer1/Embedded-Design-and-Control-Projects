#include<p33fj256GP710.h>

#define F1 OC1RS
#define F2 OC2RS
#define F3 OC3RS
#define F4 OC4RS


void clk();
void pwm();
void config();
void adc_config();
int readADC();

int main(void)
{
clk();
pwm();
adc_config();
int ADCResult;
F1 = (1-0.50)*36850; //PWM at RD0
while(1)
{

ADCResult = readADC(); //AD0

//Do further actions
}


return 0;
}

void clk()
{
CLKDIVbits.PLLPRE=0;
CLKDIVbits.PLLPOST=0;
PLLFBD=40;
while(OSCCONbits.LOCK!=1);
}

void pwm()
{
TMR2 = 0;
PR2 = 36850;

T2CONbits.TON =1;

OC1CON=0x0006;
OC2CON=0x0006;
OC3CON=0x0006;
OC4CON=0x0006;
OC6CON=0x0006;
}

void config()
{

_PCFG16=1;
_PCFG17=1;
TRISG=0xffff;
TRISF=0xffff;
TRISA=0xffff;
TRISB=0xffff;
TRISD =0xffff;
AD1PCFGL = 0XFFFF;
AD2PCFGL = 0XFFFF;
AD1PCFGH = 0XFFFF;

/////////////// PWM pins
TRISDbits.TRISD0 = 0;
TRISDbits.TRISD1 = 0;
TRISDbits.TRISD2 = 0;
TRISDbits.TRISD3 = 0;
TRISDbits.TRISD4 = 0;
TRISDbits.TRISD5 = 0;
TRISDbits.TRISD6 = 0;
TRISDbits.TRISD7 = 0;

}

void adc_config()
{
TRISBbits.TRISB0 = 1;
//AN0 is the ADC Pin
AD1CON1bits.AD12B=1;
AD1PCFGL = 0XFFFC;
AD2PCFGL = 0XFFFF;
AD1PCFGH = 0XFFFF;
AD1CHS0bits.CH0SA=0;
AD1CON2bits.VCFG=0;
AD1CON3bits.ADCS=10;
AD1CON3bits.SAMC=31;
AD1CON2bits.CHPS=0;
AD1CON1bits.SSRC=7;
AD1CON1bits.FORM=0;
AD1CSSLbits.CSS1=1;
AD1CON1bits.ADON=1;



}

int readADC()
{

int Value = 0;

AD1CON1bits.ADON=1;
AD1CON1bits.SAMP = 1; //Start Sampling
while(!AD1CON1bits.DONE);
Value= ADC1BUF0; // Read the conversion result
AD1CON1bits.ADON=0;

return Value;

}

