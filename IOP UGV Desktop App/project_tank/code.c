#include <p33FJ64MC802.h>
void clk(void);
void init_uart(void);

#define FCY             39613000
#define BAUDRATE         9600		      
#define BRGVAL          ((FCY/BAUDRATE)/16)-1 

int main()
{
	clk();
	init_uart();



while(1)
{
		
	sendchar('a');		
}

while(1);

}

void sendchar(unsigned char a )
{
	while(!U1STAbits.TRMT);
		U1TXREG = a;
	
}


void clk(void)
	{
	// Configure Oscillator to operate the device at 40Mhz
	// Fosc= Fin*M/(N1*N2), Fcy=Fosc/2
	// Fosc= 7.37*43/(2*2)=79.23MHz
		PLLFBD=41;					// M=43
		CLKDIVbits.PLLPOST=0;		// N1=2
		CLKDIVbits.PLLPRE=0;		// N2=2
		RCONbits.SWDTEN=0;// Disable Watch Dog Timer
		while(OSCCONbits.LOCK!=1) {};  // Wait for PLL to lock
	}

void init_uart(void)
{

	RPOR5bits.RP11R = 3;	
	U1BRG  = BRGVAL;
	U1MODE = 0x8000;  //enable uart
	U1STA  = 0x0440; // enable TX & RX*/

}