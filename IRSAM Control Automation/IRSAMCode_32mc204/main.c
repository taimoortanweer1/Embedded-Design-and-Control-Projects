#include <p33FJ64MC204.h>
#include <stdlib.h>
#include <string.h>
#include "UART.h"
#include "SABERTOOTH.h"
#include "clock.h"
#include "lcd.h"


volatile double g_standAzimuth;
volatile double g_standPitch;
volatile double g_BinoAzimuth;
volatile double g_BinoPitch;
volatile double g_BinoRange;


void PIN_INITIALIZATION(void);


void main()
{
CLOCK_CONFIGURATION();
PIN_INITIALIZATION();
}



void PIN_INITIALIZATION(void)
{
	//ANALOG TO DIGITAL PIN CONFIG
	AD1PCFGL = 0xFFFF;

	// UART I/Os 
	TRISCbits.TRISC5 = 0; // for General Purpose tx1 RP21/RC4/p38
	TRISBbits.TRISB5 = 0; // for sabertooth      tx1 RP5/RB5/p41
    TRISBbits.TRISB7 = 1; // for OLED            rx1 RP7/RB5/p43
	TRISBbits.TRISB8 = 0; // for OLED            tx1 RP8/RB8/p44
	TRISCbits.TRISC2 = 0; // for compass         tx2 RP18/RC2/p27
	TRISBbits.TRISB4 = 1; // for compass         rx2 RP4/RB4/p33
	TRISCbits.TRISC4 = 1; // for transceiver     rx1 RP	20/RC4/p37
	TRISCbits.TRISC3 = 0; // for tranceiver      tx1 RP19/RC3/p36

	// Limit Switch GP I/Os 
	TRISCbits.TRISC6 = 1; // for LM up               RP22/RC6/p2
	TRISCbits.TRISC7 = 1; // for LM down             RP23/RC7/p3

    //Encoders GP I/Os
	TRISBbits.TRISB2 = 0; // for e1                  RP2/RB2/p23
	TRISBbits.TRISB3 = 0; // for e2                  RP3/RB3/p24
	TRISCbits.TRISC0 = 0; // for e3                  RP16/RC0/p25
	TRISCbits.TRISC1 = 0; // for e4                  RP17/RC1/p26

	//LEDs Status
	TRISBbits.TRISB9 = 0; // power                   RP9/RB9/p1
	TRISBbits.TRISB10 = 0; // link                 RP10/RB10/p8
	TRISCbits.TRISC1 = 0; // error                  RP17/RC1/p26

	//Servo
	TRISCbits.TRISC8 = 0; // servo1                   RP9/RB9/p1
	TRISCbits.TRISC9 = 0; // servo2                 RP10/RB10/p8
	
}

