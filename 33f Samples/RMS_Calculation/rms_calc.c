#include <p33FJ64MC804.h>
#include <math.h>

void ADC_CONFIG();
int READ_ADC();

void main()
{
int V_samples[100];
int I_samples[100];
int COUNT = 0;

while(1)
{
	
}

}

void ADC_CONFIG()
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

