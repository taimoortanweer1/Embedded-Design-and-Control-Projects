#include <p33FJ64MC804.h>
#include <stdlib.h>
#include <string.h>
#include "UART.h"
#include "SABERTOOTH.h"
#include "clock.h"
#include "lcd.h"

#define PowerLED	 PORTBbits.RB9
#define LineLED 	 PORTBbits.RB10
#define ErrorLED 	 PORTBbits.RB11
#define Buzzer		 PORTBbits.RB13

#define Servo1 		 PORTCbits.RC6
#define Servo2 		 PORTCbits.RC7
#define LimitUp 	 PORTCbits.RC8
#define LimitDown 	 PORTCbits.RC9

#define Encoder1A	 PORTBbits.RB2
#define Encoder1B 	 PORTBbits.RB3
#define Encoder2A 	 PORTCbits.RC0
#define Encoder2B 	 PORTCbits.RC1


volatile double    	 g_standAzimuth;
volatile double 	 g_standPitch;
volatile double 	 g_BinoAzimuth;
volatile double 	 g_BinoPitch;
volatile double 	 g_BinoRange;


void PIN_INITIALIZATION(void);


void main()
{
char rec = '0';
char r	 = '0';
char arr[10] = "taimoor";
int i = 0;

CLOCK_CONFIGURATION();
PIN_INITIALIZATION();
//UART_LCD_CONFIG();
UART_MAGNETOMETER_CONFIG();
UART_TRANSCEIVER_CONFIG();

while(1)
{	
	for (i=0;i<7;i++)
	{
 	//	TRANSMIT_C1(arr[i]);
 		//rec = GET_C1();
		GET_STAND_COMPASS();

 		r   ='s';
	}

}

}



void PIN_INITIALIZATION(void)
{
	//ANALOG TO DIGITAL PIN CONFIG
	AD1PCFGL = 0xFFFF;

	// UART I/Os 
	TRISBbits.TRISB13 = 0; // for buzzer tx1 RP13/RB13/p11
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
	TRISBbits.TRISB13 = 0; // error                  RP13/RB13/p11

	//Servo
	TRISCbits.TRISC8 = 0; // servo1                   RP9/RB9/p1
	TRISCbits.TRISC9 = 0; // servo2                 RP10/RB10/p8
	
}

