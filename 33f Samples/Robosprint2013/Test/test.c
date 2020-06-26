#include<p33fj64mc802.h>
#include<libpic30.h>
#pragma code WDT=OFF
void clk()
{	
    CLKDIVbits.PLLPRE=0;   ////"PLL TO INCREASE OR DECREASE FREQ"
	CLKDIVbits.PLLPOST=0;  ////POST SCALER AND PRESCALER=0
	PLLFBD=41;             //// PUTTING VALUE Fosc=Fin*M/n1*n2   ///freq=Fosc/2 
	while(OSCCONbits.LOCK!=1);
}
void main()
{
clk();
 AD1PCFGL=0xFFFF;
TRISBbits.TRISB9=0;
TRISBbits.TRISB8=0;
while(1)
{
PORTBbits.RB9=0;
PORTBbits.RB8=0;
__delay32(10000000);
PORTBbits.RB9=1;
PORTBbits.RB8=1;
}
}