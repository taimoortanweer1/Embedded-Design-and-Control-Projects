	#include <p33FJ64MC804.h>
	#include <libpic30.h>	
	//#define XTFREQ          7370000         //FRC frequency 
	#define FCY             39613000        //Instruction Cycle Frequency
	#define ENABLE PORTAbits.RA0
	#define B PORTAbits.RA1       	      
	#define C PORTAbits.RA4 
	#define D PORTBbits.RB11
	#define BAUDRATE         9600		      
	#define BRGVAL          ((FCY/BAUDRATE)/16)-1
	#define BAUDRATE2         9600		      
	#define BRGVAL2          ((FCY/BAUDRATE2)/16)-1  
	void CONFIGURATIONS(void);


	void INIT_SABERTOOTH();
	void FORWARD1(char address, char speed);
    void FORWARD2(char address, char speed);
    void BACKWARD1(char address, char speed);
    void BACKWARD2(char address, char speed);

	void INIT_UART_START(void);
	
	void INIT_PINS(void);
	void INIT_UART1(void);

	void TRANSMIT_C1(unsigned char value);
	void INIT_UART2(void);
	void TRANSMIT_C2(unsigned char value);
	unsigned char GET_C2(void);
	unsigned char GET_PS2(unsigned char value);
	void GET_PS2_ALL(void);
	void INIT_TEST_PINS(void);
	void timer1_interupt_config();


//*******************PS2 BUTTON VARIABLES********************
	unsigned char L_UP_VALUE = 0;
	unsigned char L_DOWN_VALUE = 0;
	
	unsigned char L_RIGHT_VALUE = 0;
	unsigned char L_LEFT_VALUE = 0;

	unsigned char R_RIGHT_VALUE = 0;
	unsigned char R_LEFT_VALUE = 0;

	unsigned char R_UP_VALUE = 0;
	unsigned char R_DOWN_VALUE = 0;
	
	unsigned char LJ2 = 0;
	unsigned char RJ2 = 0;
		
	unsigned char LJ1 = 0;
	unsigned char RJ1 = 0;
	
	unsigned char CROSS = 0;
	unsigned char TRIANGLE=0;
	unsigned char SQUARE=0;
	unsigned char CIRCLE=0;


	unsigned char UP = 0;
	unsigned char DOWN = 0;
	unsigned char LEFT = 0;
	unsigned char RIGHT = 0;
	//***********************************************************

int main(void)
{
	AD1PCFGL = 0xFFFF;		// Make analog pins digital 
	CONFIGURATIONS();
	__delay32(2000000000000); //100mSEC delay
//	INIT_UART1();
//	INIT_UART1();
//	INIT_UART1();
	INIT_UART2();
	
	__delay32(400000000); //100mSEC delay

	INIT_SABERTOOTH();

	
	__delay32(400000000); //100mSEC delay

	
	
	FORWARD1(128,120); 
	FORWARD2(128,120);

} 
	

//////////////////////////////FUNCTIONS////////////////////////////////////////

	
	void CONFIGURATIONS(void)
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

	void INIT_SABERTOOTH(void)
	{
	
	TRANSMIT_C2(0xAA); //Autobauding character to Sabertooth
	__delay32(2000000); //100mSEC delay
	
	}	
	void INIT_UART2(void)
	{
	
	//	RPINR19 = 4;				// Make Pin RP2 U2RX
		RPOR2bits.RP5R = 5;		// Make Pin Rp3 U2TX
		TRISBbits.TRISB5 = 0;


		AD1PCFGL = 0xFFFF;		// Make analog pins digital 
		U2BRG  = BRGVAL2;
		U2MODE = 0x8000; /* Reset UART to 8-n-1, alt pins, and enable */
		U2STA  = 0x0440; /* Reset status register and enable TX & RX*/
	
	}
	
	
	void INIT_UART1()
	{
	
		TRISBbits.TRISB8 = 1;   //input
		TRISBbits.TRISB9 = 0;	//output
		
		RPOR4bits.RP9R = 3;		// Make Pin RP9 U1TX
		RPINR18bits.U1RXR = 8;
	
	//	AD1PCFGL = 0x03C0;		// Make analog pins digital 
		U1BRG  = BRGVAL;
		U1MODE = 0x8000; /* Reset UART to 8-n-1, alt pins, and enable */
		U1STA  = 0x0440; /* Reset status register and enable TX & RX*/

	}	
	void TRANSMIT_C1(unsigned char value)
	{
		while(!U1STAbits.TRMT);
		U1TXREG = value;
		while(!U1STAbits.TRMT);
		_U1RXIF=0;					// Clear UART RX Interrupt Flag*/
	
	}
	
	void TRANSMIT_C2(unsigned char value)
	{
		while(!U2STAbits.TRMT);
		U2TXREG = value;
		__delay32(100); //Little Delay
		while(!U2STAbits.TRMT);
		_U2RXIF=0;
		__delay32(100); //Little Delay
	}
	
	unsigned char GET_C1(void)
	{
		__delay32(100); //Little Delay
		while (_U1RXIF==0);			// Wait and Receive One Character
		_U1RXIF=0;
		return U1RXREG;
		__delay32(100); //Little Delay
	}
	
	unsigned char GET_PS2(unsigned char value)
	{
	TRANSMIT_C1(value);
	return GET_C1();
	
	}
	
	void GET_PS2_ALL(void)
	{
	
	L_UP_VALUE = GET_PS2(20);
	L_DOWN_VALUE = GET_PS2(21);
    L_RIGHT_VALUE = GET_PS2(23);
	L_LEFT_VALUE = GET_PS2(22);

	R_UP_VALUE = GET_PS2(24);
	R_DOWN_VALUE = GET_PS2(25);
 	R_RIGHT_VALUE = GET_PS2(26);
	R_LEFT_VALUE = GET_PS2(27);

	TRIANGLE =GET_PS2(12);
	CIRCLE=GET_PS2(13);
	SQUARE=GET_PS2(15);

	LJ2 = GET_PS2(8);
	RJ2 = GET_PS2(9);

	LJ1 = GET_PS2(10);
	RJ1 = GET_PS2(11);
	
	UP = GET_PS2(4);
	DOWN = GET_PS2(6);
	LEFT = GET_PS2(7);
	RIGHT = GET_PS2(5);
	
	}
	
	void FORWARD1(char address, char speed)
	{
	TRANSMIT_C2(address);
	TRANSMIT_C2(0); //drive motor 1 forward command
	TRANSMIT_C2(speed);
	TRANSMIT_C2((address + 0 + speed) & 0b01111111);
	}

//////////////////////////////////////////////// FORWARD 2 //////////////////////////////////////////
	
	void FORWARD2(char address, char speed)
	{
	TRANSMIT_C2(address);
	TRANSMIT_C2(4); //drive motor 2 forward command
	TRANSMIT_C2(speed);
	TRANSMIT_C2((address + 4 + speed) & 0b01111111);
	}

//////////////////////////////////////////////// BACKWARD 1 //////////////////////////////////////////
	
	void BACKWARD1(char address, char speed)
	{
	TRANSMIT_C2(address);
	TRANSMIT_C2(1); //drive motor 1 backwards command
	TRANSMIT_C2(speed);
	TRANSMIT_C2((address + 1 + speed) & 0b01111111);
	}

//////////////////////////////////////////////// BACKWARD 2 //////////////////////////////////////////
	
void BACKWARD2(char address, char speed)
{
	TRANSMIT_C2(address);
	TRANSMIT_C2(5);//drive motor 2 backwards command
	TRANSMIT_C2(speed);
	TRANSMIT_C2((address + 5 + speed) & 0b01111111);
}
