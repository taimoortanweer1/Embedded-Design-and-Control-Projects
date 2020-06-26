#include <p33FJ64MC804.h>
#include <libpic30.h>

void clk(void);
void init_uart(void);

#define FCY             39613000
#define BAUDRATE         9600		      
#define BRGVAL          ((FCY/BAUDRATE)/16)-1 

void INIT_UART1(void);
void TRANSMIT_C1(unsigned char value);
unsigned char GET_C1(void);

void INIT_UART2(void);
unsigned char GET_C2(void);
void TRANSMIT_C2(unsigned char value);

void INIT_SABERTOOTH(void);

void FORWARD1(char address, char speed);
void FORWARD2(char address, char speed);
void BACKWARD1(char address, char speed);
void BACKWARD2(char address, char speed);

unsigned char GET_PS2(unsigned char value);

///////***********   PS2 Protocols *************/////////

#define	p_select		0
#define p_joyl			1
#define p_joyr			2
#define p_start			3
#define p_up			4
#define p_right			5
#define p_down			6
#define p_left			7
#define	p_l2			8
#define	p_r2			9
#define p_l1			10
#define p_r1			11
#define p_triangle		12
#define p_circle		13
#define p_cross			14
#define	p_square		15
#define p_joy_lx		16
#define	p_joy_ly		17
#define p_joy_rx		18
#define p_joy_ry		19
#define p_joy_lu		20
#define p_joy_ld		21
#define p_joy_ll		22
#define p_joy_lr		23
#define p_joy_ru		24
#define p_joy_rd		25
#define p_joy_rl		26
#define p_joy_rr		27

#define	p_con_status	28
#define p_motor1		29
#define p_motor2		30


int main()
{
	clk();
//	INIT_UART1();
	INIT_UART2(); /// For Sabertooth

	INIT_SABERTOOTH();
	__delay32(400000000);

	FORWARD2(128,80);
	FORWARD1(128,80);

	while(1);
	
}



///////////////////////////////////////////////////////////// INITIALIZING UART 1 ////////////////////////////////////////////////////////

void INIT_UART1(void)
{
	_U1RXR = 7;
	RPOR4bits.RP8R = 3;			// Make Pin Rp5 U1TX                                                                                                                                                                                                                                                                                                                                           
	TRISBbits.TRISB8 = 0;		// Tx
	TRISBbits.TRISB7 = 1;		// Rx
	AD1PCFGL = 0xFFFF;			// Make analog pins digital 
	U1BRG  = BRGVAL;
	U1MODE = 0x8000; /* Reset UART to 8-n-1, alt pins, and enable */
	U1STA  = 0x0440; /* Reset status register and enable TX & RX*/
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

void TRANSMIT_C1(unsigned char value)
{
	while(!U1STAbits.TRMT);
	U1TXREG = value;
	while(!U1STAbits.TRMT);
	_U1RXIF=0;
}
    ///////////////////////////////////////////////////// RECEIVE FUNCTION FOR UART 1 ///////////////////////////////////////////////////

unsigned char GET_C1(void)//////////////////////////////////////////////////////////////
{
	if(U1STAbits.OERR == 1)
	{
		U1STAbits.OERR = 0;	
	}	
	while ((_U1RXIF == 0));
	_U1RXIF = 0;
	return U1RXREG;
}

void TRANSMIT_C2(unsigned char value)
{
	while(!U2STAbits.TRMT);
	U2TXREG = value;
	while(!U2STAbits.TRMT);
	_U2RXIF=0;				//Clear UART RX Interrupt Flag
}

//////////////////////////////////////////////////// RECEIVE FUNCTION FOR UART 2 /////////////////////////////////////////////////////////

unsigned char GET_C2(void)
{
		while (IFS1bits.U2RXIF==0);			// Wait and Receive One Character
		IFS1bits.U2RXIF = 0;
		return U2RXREG;
}

void INIT_UART2(void)
{			
	TRISBbits.TRISB5 = 0;
	RPOR2bits.RP5R = 3;

	U2BRG  = BRGVAL;
	U2MODE = 0x8000; /* Reset UART to 8-n-1, alt pins, and enable */
	U2STA  = 0x0440; /* Reset status register and enable TX & RX*/
}

 void INIT_SABERTOOTH(void)
{
	__delay32(20000000); //100mSEC delay
	TRANSMIT_C2(0xAA); //Autobauding character to Sabertooth
	__delay32(20000000); //100mSEC delay
}

//////////////////////////////////////////////// FORWARD 1 //////////////////////////////////////////

	void FORWARD1(char address, char speed)
	{
	char ad=0;
	ad=address & 0b00000011;
	TRANSMIT_C2(0b00010100 | ad);
	__delay32(100);
	TRANSMIT_C2(speed | 0b10000000);
	}

//////////////////////////////////////////////// FORWARD 2 //////////////////////////////////////////
	
	void FORWARD2(char address, char speed)
	{
	char ad=0;
	ad=address & 0b00000011;
	TRANSMIT_C2(0b00101000 | ad);
	__delay32(100);
	TRANSMIT_C2(speed | 0b10000000);
	}

//////////////////////////////////////////////// BACKWARD 1 //////////////////////////////////////////
	
	void BACKWARD1(char address, char speed)
	{
	char ad=0;
	ad=address & 0b00000011;
	TRANSMIT_C2(0b00000100 | ad);
	__delay32(100);
	TRANSMIT_C2(speed | 0b10000000);
	}

//////////////////////////////////////////////// BACKWARD 2 //////////////////////////////////////////
	
	void BACKWARD2(char address, char speed)
	{
	char ad=0;
	ad=address & 0b00000011;
	TRANSMIT_C2(0b00001000 | ad);
	__delay32(100);
	TRANSMIT_C2(speed | 0b10000000);
	}

/////////// PS2 READING FUNCTION //////////
	
unsigned char GET_PS2(unsigned char value)
{
	TRANSMIT_C1(value);
	return GET_C1();
}

