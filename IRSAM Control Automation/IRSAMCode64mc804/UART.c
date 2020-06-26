#include <p33FJ64MC804.h>
#include "UART.h"

void TRANSMIT_C1(unsigned char value)
{
	while(!U1STAbits.TRMT);
	U1TXREG = value;
	while(!U1STAbits.TRMT);
	_U1RXIF=0;
}

void TRANSMIT_C2(unsigned char value)
{
	while(!U2STAbits.TRMT);
	U2TXREG = value;
	while(!U2STAbits.TRMT);
	_U2RXIF=0;
}

unsigned char GET_C1(void)
{
	if(U1STAbits.FERR==1)
	{}
	if(U1STAbits.OERR==1)
	{
		U1STAbits.OERR==0;
	}
	if(U1STAbits.URXDA==1)
		_U1RXIF = 0;
	return U1RXREG;
}

unsigned char GET_C2(void)
{

	if(U2STAbits.FERR==1)
	{}
	if(U2STAbits.OERR==1)
	{
		U2STAbits.OERR==0;
	}
	if(U2STAbits.URXDA==1)

	_U2RXIF = 0;
	return U2RXREG;


/*
	while (_U2RXIF==0);
	_U2RXIF = 0;
	return U2RXREG;
*/
}

void UART_LCD_CONFIG()
{
	TRISBbits.TRISB7 = 1; // for OLED            rx1 RP7/RB5/p43
	TRISBbits.TRISB8 = 0; // for OLED            tx1 RP8/RB8/p44

	RPOR4bits.RP8R = 3;
	RPINR18bits.U1RXR = 7;

	U1BRG  = BRGVAL1;
	_U1RXIP = 0;
	_U1RXIF = 0;
    _U1RXIE = 0;
	U1MODE = 0x8000;
	U1STA  = 0x0440;
}

void UART_SABERTOOTH_CONFIG()
{
	TRISBbits.TRISB5 = 0; // for sabertooth      tx1 RP5/RB5/p41
	RPOR2bits.RP5R = 3;	


	U1BRG  = BRGVAL1;
	_U1RXIP = 0;
	_U1RXIF = 0;
    _U1RXIE = 0;
	U1MODE = 0x8000;
	U1STA  = 0x0440;
}


void UART_TRANSCEIVER_CONFIG()
{
	TRISCbits.TRISC4 = 1; // for transceiver     rx1 RP	20/RC4/p37
	TRISCbits.TRISC3 = 0; // for tranceiver      tx1 RP19/RC3/p36
	
	RPOR9bits.RP19R = 3;	
	RPINR18bits.U1RXR = 20;

	U1BRG  = BRGVAL1;
	_U1RXIP = 0;
	_U1RXIF = 0;
    _U1RXIE = 0;
	U1MODE = 0x8000;
	U1STA  = 0x0440;
}



void UART_MAGNETOMETER_CONFIG()
{
	TRISCbits.TRISC2 = 0; // for magnetometer    tx2 RP18/RC2/p27
	TRISBbits.TRISB4 = 1; // for magnetometer    rx2 RP4/RB4/p33

	RPOR9bits.RP18R = 5;	
	RPINR19bits.U2RXR = 4;

	U2BRG  = BRGVAL2;
	_U2RXIP = 0;
	_U2RXIF = 0;
    _U2RXIE = 0;
	U2MODE = 0x8000;
	U2STA  = 0x0440;
}

void UART_GP_CONFIG()
{
	TRISCbits.TRISC5 = 0; // for General Purpose tx1 RP21/RC4/p38
	RPINR18bits.U1CTSR = 21;

	U1BRG  = BRGVAL1;
	_U1RXIP = 0;
	_U1RXIF = 0;
    _U1RXIE = 0;
	U1MODE = 0x8000;
	U1STA  = 0x0440;
}
