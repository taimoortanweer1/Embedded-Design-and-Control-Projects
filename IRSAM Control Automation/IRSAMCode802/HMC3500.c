#include <p33fj64mc802.h>
#include <libpic30.h>

#define LED 		PORTDbits.RD5
#define FCY			39613000	//Instruction Cycle Frequency
#define BAUDRATE1	9600
#define BRGVAL1		((FCY/BAUDRATE1)/16)-1

#define BAUDRATE2	19200
#define BRGVAL2		((FCY/BAUDRATE2)/16)-1
	
void CONFIGURATIONS(void);
void INITIALIZATION(void);

void INIT_UART1(void);
void TRANSMIT_C1(unsigned char value);
unsigned char GET_C1(void);

void INIT_UART2(void);
void TRANSMIT_C2(unsigned char value);
unsigned char GET_C2(void);
unsigned long int	AZIMUTH=0,	PITCH=0;
unsigned char read=0 , arr=0;
unsigned int b=0,flag=0,u;


    void __attribute__((__interrupt__, no_auto_psv)) _U1RXInterrupt(void)
    {

   
	arr = GET_C1();

    }

   void __attribute__((__interrupt__, no_auto_psv)) _U2RXInterrupt(void)
   {

   
	read = GET_C2();
	
  }

int main( void )
{

unsigned int i=0,j=0,k=0;
unsigned char MY_STRING[1000]; 

	CONFIGURATIONS();
//	INITIALIZATION();

	__delay32(6000000);
	__delay32(6000000);
	__delay32(6000000);
	__delay32(6000000);
	__delay32(6000000);
	__delay32(6000000);
	__delay32(6000000);
	__delay32(6000000);
	__delay32(6000000);
	__delay32(6000000);
	__delay32(6000000);
	__delay32(6000000);
	__delay32(6000000);
	__delay32(6000000);
	__delay32(6000000);
	__delay32(6000000);
	__delay32(6000000);
	__delay32(6000000);
	__delay32(6000000);
    //UART_LCD();
INIT_UART1();
//INIT_UART2();
U1STAbits.OERR = 0;

while(1)
{
while(GET_C1()!= 13);
while(i<23)
{
MY_STRING[i]=GET_C1();
i++;
}
i=0;
			AZIMUTH = ((unsigned int)MY_STRING[9]*(unsigned int)256);
			AZIMUTH = AZIMUTH+(unsigned int)MY_STRING[8];
			AZIMUTH = AZIMUTH*(unsigned int)1000;
			AZIMUTH = (AZIMUTH/(unsigned int)65535);
			AZIMUTH = AZIMUTH*(unsigned int)360;
			AZIMUTH = AZIMUTH/(unsigned int)1000;

			PITCH = ((unsigned int)MY_STRING[6]*(unsigned int)256);
			PITCH = PITCH+(unsigned int)MY_STRING[7];
			PITCH = PITCH*(unsigned int)1000;
            PITCH = (PITCH/(unsigned int)65535);
			PITCH = PITCH*(unsigned int)360;
			PITCH = PITCH/(unsigned int)1000;

i=0;
}
}
void CONFIGURATIONS(void)
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

void INITIALIZATION(void)
{
	//ANALOG TO DIGITAL PIN CONFIG
	
	AD1PCFGL = 0xFFFF;

	//STATUS LED

	TRISBbits.TRISB15 = 0;

	//SETTING PINS - OUTPUT '0'

	TRISA = 0x0000;
	TRISB = 0x0000;

	//INITIALIZING PINS - WRITE '0'

	PORTA = 0x0000;
	PORTB = 0x0000;
}
void INIT_UART1()
{
//	TRISFbits.TRISF2 = 1;
//	TRISFbits.TRISF3 = 0;
//RPOR5bits.RP11R = 3;		// Make Pin RP11 U1TX
//TRISBbits.TRISB11 = 0;		// MAKE PIN B11 AS OUTPUT	

RPINR18 = 13;				// Make Pin RP10 U1RX
TRISBbits.TRISB13 = 1;		// MAKE PIN B10 AS INPUT	

	IPC2bits.U1RXIP = 7;	
	IFS0bits.U1RXIF = 0;
	IEC0bits.U1RXIE = 0;


	U1BRG  = BRGVAL1;
	U1MODE = 0x8000; /* Reset UART to 8-n-1, alt pins, and enable */
	U1STA  = 0x0440; /* Reset status register and enable TX & RX*/
}

  ///////////////////////////////////////////////////////////// INITIALIZING UART 2 ////////////////////////////////////////////////////////
   /*	void UART_LCD()                     
    {	
	RPINR19 = 14;	                      ///////////////////////////////// Receive ///////////////////////////////// 	
	RPOR7bits.RP15R = 5;	                  ///////////////////////////////// Transmit ///////////////////////////////// 
		
	TRISBbits.TRISB14 = 1;                 ///////////////////////////////// Receive ///////////////////////////////// 
	TRISBbits.TRISB15=  0;                 ///////////////////////////////// Transmit /////////////////////////////////
	
	U2BRG  = BRGVAL;

	IPC7bits.U2RXIP = 7;	
	IFS1bits.U2RXIF = 0;
	IEC1bits.U2RXIE = 1;

	U2MODE = 0x8000; 	
	U2STA  = 0x0440; 
    }
 */


void INIT_UART2()
{
//	TRISFbits.TRISF4 = 1;
//	TRISFbits.TRISF5 = 0;


		RPINR19 = 14;						// 	Make Pin RP13 U2RX
		RPOR7bits.RP15R = 5;				// 	Make Pin Rp15 U2TX

	IPC7bits.U2RXIP = 7;	
	IFS1bits.U2RXIF = 0;
	IEC1bits.U2RXIE = 1;

	U2BRG  = BRGVAL2;
	U2MODE = 0x8000; /* Reset UART to 8-n-1, alt pins, and enable */
	U2STA  = 0x0440; /* Reset status register and enable TX & RX*/
}

void TRANSMIT_C1(unsigned char value)
{
	while(!U1STAbits.TRMT);
	U1TXREG = value;
	while(!U1STAbits.TRMT);
	_U1RXIF=0;				//Clear UART RX Interrupt Flag
}

unsigned char GET_C1(void)
{
	while (_U1RXIF==0);		// Wait and Receive One Character
	_U1RXIF=0;
	return U1RXREG;
}



void TRANSMIT_C2(unsigned char value)
{
	while(!U2STAbits.TRMT);
	U2TXREG = value;
	while(!U2STAbits.TRMT);
	_U2RXIF=0;				//Clear UART RX Interrupt Flag
}

unsigned char GET_C2(void)
{
	while (_U2RXIF==0);		// Wait and Receive One Character
	_U2RXIF=0;
	return U2RXREG;
}