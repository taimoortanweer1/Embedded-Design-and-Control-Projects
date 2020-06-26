#include <p33FJ32MC204.h>

void CLOCK_CONFIGURATION(void)
{	
	//Configure Oscillator to operate the device at 40Mhz
	//Fosc= Fin*M/(N1*N2), Fcy=Fosc/2
	//Fosc= 7.37*43/(2*2)=79.23MHz

	PLLFBD=41;				// M=43
	CLKDIVbits.PLLPOST=0;	// N1=2
	CLKDIVbits.PLLPRE=0;	// N2=2
	RCONbits.SWDTEN=0;			//Disable Watch Dog Timer	
	while(OSCCONbits.LOCK!=1);	//Wait for PLL to lock
}