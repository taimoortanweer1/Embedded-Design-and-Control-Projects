#include <p33FJ64MC804.h>
#include <stdlib.h>
#include <string.h>
#include "UART.h"
#include "SABERTOOTH.h"
#include "clock.h"
#include "lcd.h"

#define LED1_S1 PORTBbits.RB10 
#define LED1_S2 PORTCbits.RC7
#define LED2_S1 PORTBbits.RB11 
#define LED2_S2 PORTBbits.RB9 
#define LED3_S1 PORTCbits.RC6
//#define LED3_S2

//#define ButA_T1
//#define ButA_T2

#define ButA_T1 PORTBbits.RB7
#define ButA_T2 PORTBbits.RB8
#define ButB_T1 PORTCbits.RC8
#define ButB_T2 PORTCbits.RC9
#define ButC_T1 PORTCbits.RC0 
#define ButC_T2 PORTCbits.RC1 
#define ButD_T1 PORTBbits.RB2 
#define ButD_T2 PORTBbits.RB3 

volatile double g_standAzimuth;
volatile double g_standPitch;
volatile double g_standRange;
volatile double g_BinoAzimuth;
volatile double g_BinoPitch;
volatile double g_BinoRange;
volatile char g_standStatus[3];

void PIN_INITIALIZATION(void);

void main()
{
char rec = '0';
char r;

CLOCK_CONFIGURATION();
PIN_INITIALIZATION();
UART_MAGNETOMETER_CONFIG();
UART_TRANSCEIVER_CONFIG();


ButB_T2=1;
ButC_T2=1;
ButD_T2=1;
ButA_T2=1;

while(1)
{
GET_STAND_COMPASS();
SEND_DATA();
//GET_STAND_STATUS();
LED1_S1 = ButB_T1 | ButC_T1  | ButD_T1 | ButA_T1;
r='s';
}

}



void PIN_INITIALIZATION(void)
{
	//ANALOG TO DIGITAL PIN CONFIG
	AD1PCFGL = 0xFF;
	AD1PCFGL = 0xFF;
	// UART I/Os 
	TRISCbits.TRISC5 = 0; // for General Purpose tx1 RP21/RC4/p38
	TRISBbits.TRISB5 = 0; // for sabertooth      tx1 RP5/RB5/p41
    
	
	TRISCbits.TRISC2 = 0; // for compass         tx2 RP18/RC2/p27
	TRISBbits.TRISB4 = 1; // for compass         rx2 RP4/RB4/p33
	TRISCbits.TRISC4 = 1; // for transceiver     rx1 RP	20/RC4/p37
	TRISCbits.TRISC3 = 0; // for tranceiver      tx1 RP19/RC3/p36

   
	TRISCbits.TRISC1 = 0; // error                  RP17/RC1/p26
	TRISBbits.TRISB13 = 0; // error                  RP13/RB13/p11
	
	TRISBbits.TRISB7 = 1; // buttonA T1
	TRISBbits.TRISB8 = 0; // buttonA T1

	TRISBbits.TRISB2 = 1; //buttonD T1
	TRISBbits.TRISB3 = 0; //buttonD T2

	TRISCbits.TRISC0 = 1; //buttonC T1
	TRISCbits.TRISC1 = 0; //buttonC T2

	TRISCbits.TRISC8 = 1; //buttonB T1
	TRISCbits.TRISC9 = 0; //buttonB T2
	
	TRISBbits.TRISB9  = 0; 
	TRISBbits.TRISB10 = 0;
	TRISBbits.TRISB11 = 0;

	TRISCbits.TRISC7 = 0;
	TRISCbits.TRISC6 = 0;
	

}

