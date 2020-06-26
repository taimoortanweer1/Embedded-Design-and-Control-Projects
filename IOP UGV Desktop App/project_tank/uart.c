#include <p33FJ64MC802.h>
#include "uart.h"

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
	while (_U1RXIF==0);
	_U1RXIF = 0;
	return U1RXREG;
}

unsigned char GET_C2(void)
{
	while (_U2RXIF==0);
	_U2RXIF = 0;
	return U2RXREG;
}

void UART_01()
{
	RPINR18 = 4;
	RPOR2bits.RP5R = 3;

	TRISBbits.TRISB4 = 1;
	TRISBbits.TRISB5 = 0;

	U1BRG  = BRGVAL1;

	_U1RXIP = 0;
	_U1RXIF = 0;
    _U1RXIE = 0;

	U1MODE = 0x8000;
	U1STA  = 0x0440;
}

void UART_02()
{
    RPINR19 = 14;
	RPOR7bits.RP15R = 5;
			
    TRISBbits.TRISB14 = 1;
	TRISBbits.TRISB15 = 0;
		
	U2BRG  = BRGVAL2;

	IPC7bits.U2RXIP = 0;	
	IFS1bits.U2RXIF = 0;
	IEC1bits.U2RXIE = 0;

	U2MODE = 0x8000; 	
	U2STA  = 0x0440;
}
