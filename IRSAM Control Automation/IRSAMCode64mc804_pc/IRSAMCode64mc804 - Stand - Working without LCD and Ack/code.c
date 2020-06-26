#include <p33FJ64MC804.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "UART.h"
#include "SABERTOOTH.h"
#include "clock.h"
#include "lcd.h"
#include "PWM.h"
#define LINK  PORTBbits.RB10
#define POWER PORTBbits.RB9
#define MIN    0.05
#define NEUTRAL 0.075
#define MAX     0.1

volatile double g_standAzimuth;
volatile double g_standPitch;
volatile double g_standRange;
volatile double g_BinoAzimuth;
volatile double g_BinoPitch;
volatile double g_BinoRange;
volatile char   g_BinoButton[3];
extern volatile char g_standStatus;

//*********** PI Variables *************8
static float I_ERROR_AZIM = 0;
static float ERROR_SPEED_AZIM = 0;
static float ERROR_ANGLE_AZIM = 0;

static float I_ERROR_PITCH = 0;
static float ERROR_SPEED_PITCH = 0;
static float ERROR_ANGLE_PITCH = 0;

//**************** functions ********************
void pwm1(float pos);
void pwm2(float pos);
void PIN_INITIALIZATION(void);
void control(float KP_AZIM , float KI_AZIM , float KP_PITCH , float KI_PITCH);
//************************************
void main()
{
char rec = '0';
char r;

CLOCK_CONFIGURATION();
PIN_INITIALIZATION();
UART_SABERTOOTH_AZIM_CONFIG();
INIT_SABERTOOTH();


UART_MAGNETOMETER_CONFIG();
UART_TRANSCEIVER_CONFIG();
//

while(1)
{
control(10,0.00000000001,2.5,0.00000000001);  
TRANSMIT_C1(g_standStatus);
rec = '1';

if(g_BinoButton[0] == 1)
{
	pwm2(MIN);
}
else if (g_BinoButton[1] == 1)
{
	pwm2(MAX);
}
else
{
pwm2(NEUTRAL);
__delay32(10000);
pwm2(0);
}

}
}


void PIN_INITIALIZATION(void)
{
	//ANALOG TO DIGITAL PIN CONFIG
	AD1PCFGL = 0xFFFF;
	
	// UART I/Os 
	TRISCbits.TRISC5 = 0; // for General Purpose     RP21/RC4/p38
	TRISBbits.TRISB5 = 0; // for sabertooth      tx2 RP5/RB5/p41
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


	TRISCbits.TRISC8 = 0; // servo1                   RP9/RB9/p1
	TRISCbits.TRISC9 = 0; // servo2                 RP10/RB10/p8
	
    //servo_by zain
	TRISCbits.TRISC6 = 0; // servo1                   RP9/RB9/p1
	TRISCbits.TRISC7 = 0; // servo2                 RP10/RB10/p8

	
}
void pwm1(float pos)
{
    TRISCbits.TRISC6 = 0;
    TRISCbits.TRISC7 = 0;
	P1TCON = 0x0000;
    //P2TCONbits.PTCKPS = 2;//postscaler 16
    //P2TPER = 5580;  //2480//1khz     //5580;//430Hz
     P2TCONbits.PTCKPS = 3;//postscaler 64
     P2TPER = 12350;  //20ms
    PWM2CON1bits.PMOD1 = 1;
    PWM2CON1bits.PEN1L = 0;
   	PWM2CON1bits.PEN1H = 1;
    P2DC1 = P2TPER*2*(pos);
	//0.15 = 3ms
    //0.1  = 2ms
    //0,075 = 1.5ms
    //0.05 = 1ms 
  	P2TMR = 0;
    P2TCONbits.PTEN = 1;
}

void pwm2(float pos)
{
    TRISCbits.TRISC6 = 0;
    TRISCbits.TRISC7 = 0;
	P1TCON = 0x0000;
    P2TCONbits.PTCKPS = 3;//postscaler 16
    P2TPER = 12350;  //2480//1khz     //5580;//430Hz
    PWM2CON1bits.PMOD1 = 1;
    PWM2CON1bits.PEN1L = 1;
   	PWM2CON1bits.PEN1H = 0;
    P2DC1 = P2TPER*2*(pos);
  	P2TMR = 0;
    P2TCONbits.PTEN = 1;
}
void control(float KP_AZIM , float KI_AZIM , float KP_PITCH , float KI_PITCH)
{

    	// Getting new samples	
		GET_BINO_COMPASS();
		GET_STAND_COMPASS();                     
        		
		//calculating errors
		ERROR_ANGLE_AZIM = g_BinoAzimuth - g_standAzimuth + 10; 
		//10 is offset in stand
		I_ERROR_AZIM = I_ERROR_AZIM + ERROR_ANGLE_AZIM*KI_AZIM;		
	
		ERROR_ANGLE_PITCH = g_BinoPitch - g_standPitch;
		I_ERROR_PITCH = I_ERROR_PITCH + ERROR_ANGLE_PITCH*KI_PITCH;		
	
		//output Speed calculation	
		ERROR_SPEED_AZIM = ((abs(ERROR_ANGLE_AZIM)/360.000)*127.00)*KP_AZIM + I_ERROR_AZIM; 
		if(abs(ERROR_SPEED_AZIM) > 127)	
		{
			ERROR_SPEED_AZIM = 127;
		}		
	
		ERROR_SPEED_PITCH = ((abs(ERROR_ANGLE_PITCH)/90.000)*110.00)*KP_PITCH + I_ERROR_PITCH; 
		if(abs(ERROR_SPEED_PITCH) > 90)	
		{
			ERROR_SPEED_PITCH = 90;
		}		
	
		if(abs(ERROR_ANGLE_AZIM) < 1)	
		ERROR_SPEED_AZIM = 0;
				
		if(ERROR_ANGLE_AZIM>1)
		{
			if(ERROR_ANGLE_AZIM<180)
			{
			BACKWARD1(128,ERROR_SPEED_AZIM);
			BACKWARD2(128,ERROR_SPEED_AZIM);				
			}
			else if(ERROR_ANGLE_AZIM>180)
			{
			FORWARD1(128,ERROR_SPEED_AZIM);
			FORWARD2(128,ERROR_SPEED_AZIM);
			}
		}		
		if(ERROR_ANGLE_AZIM<-1)
		{
			if(ERROR_ANGLE_AZIM>-180)
			{
			FORWARD1(128,ERROR_SPEED_AZIM);
			FORWARD2(128,ERROR_SPEED_AZIM);
   			}
			else if(ERROR_ANGLE_AZIM<-180)         
			{
			BACKWARD1(128,ERROR_SPEED_AZIM);
			BACKWARD2(128,ERROR_SPEED_AZIM);				
			}
		}							    

		if(abs(ERROR_ANGLE_PITCH) < 1)	
		ERROR_SPEED_PITCH = 0;
				
		if(abs(ERROR_ANGLE_PITCH) < 3 && abs(ERROR_ANGLE_AZIM) < 3)
		{
			g_standStatus='a';			
		}
		else
		{
			g_standStatus='b';		
		}

		if(ERROR_ANGLE_PITCH>1)
		{
			FORWARD1(129,ERROR_SPEED_PITCH);
			FORWARD2(129,ERROR_SPEED_PITCH);
							
		}		
		if(ERROR_ANGLE_PITCH<-1)
		{
			BACKWARD1(129,ERROR_SPEED_PITCH);
			BACKWARD2(129,ERROR_SPEED_PITCH);
		}				
				    
	
}






















