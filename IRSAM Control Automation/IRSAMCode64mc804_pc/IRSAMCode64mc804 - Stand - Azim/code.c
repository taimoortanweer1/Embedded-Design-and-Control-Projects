#include <p33FJ64MC804.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "UART.h"
#include "SABERTOOTH.h"
#include "clock.h"
#include "lcd.h"

#define LINK  PORTBbits.RB10
#define POWER PORTBbits.RB9

volatile double g_standAzimuth;
volatile double g_standPitch;
volatile double g_standRange;
volatile double g_BinoAzimuth;
volatile double g_BinoPitch;
volatile double g_BinoRange;

///**********************************
char arr,data[100],read;
unsigned int j=0,flag2=0,fire=0,count0=0,count1=0,c1=0,c0=0;
unsigned long int	AZIMUTH=0;
signed long int PITCH=0;
float ref2=0,azz;
signed int pit,azz1,pit1; 
//************************************

int COUNT = 0;

void PIN_INITIALIZATION(void);
void HMC3500_BINO();
//void func_all(unsigned int value);
void control(float KP , float KI);

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

POWER = 1;

while(1)
{

//control(15,.00000000005);
control(10,0.00000000001);
			
rec = '1';


}
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
	TRISBbits.TRISB13 = 0; // error                  RP13/RB13/p11

	//Servo
	TRISCbits.TRISC8 = 0; // servo1                   RP9/RB9/p1
	TRISCbits.TRISC9 = 0; // servo2                 RP10/RB10/p8
	
}

void control(float KP , float KI)
{
int P_COMPENSATION = 0;
unsigned int I_GAIN = 0;
int SPEED = 0;
static float I_ERROR = 0;
static float ERROR_SPEED = 0;
static float ERROR_ANGLE = 0;
static float INTEGRAL = 0;

POWER=0;
while(1)
	{
		GET_BINO_COMPASS();
		GET_STAND_COMPASS();                     
		
		ERROR_ANGLE = g_BinoAzimuth - g_standAzimuth + 10;
		I_ERROR = I_ERROR + ERROR_ANGLE*KI;		
	
		ERROR_SPEED = ((abs(ERROR_ANGLE)/360.000)*127.00)*KP + I_ERROR; 
		if(abs(ERROR_SPEED) > 127)	
		{
		ERROR_SPEED = 127;
		}		
	

		if(abs(ERROR_ANGLE) < 3)	
		ERROR_SPEED = 0;
				
		if(ERROR_ANGLE>3)
		{
			BACKWARD1(128,ERROR_SPEED);
			BACKWARD2(128,ERROR_SPEED);				
		}		
		if(ERROR_ANGLE<-3)
		{
			FORWARD1(128,ERROR_SPEED);
			FORWARD2(128,ERROR_SPEED);
		}							    
	}
}


void func_all(unsigned int value)
{
	  int err = 0,  P_Term = 0,I_State=0 ,val=0;
	 // float kp=3.9;  //5.8 .......... 4.4
	  float kp=4;
      //float ki= .00000003, I_Term=0 ; //.000025 ........ .00002
	  float ki= .0000000002, I_Term=0 ; //.000025 ........ .00002
      signed int dif=0;
      unsigned int flag=0, ch=0;
      int error=0;
    
while(1)
{
/*
   if(in==1)
           {
                   break;
           } 
*/
	err    = dif;   // Error term obtained by subtracting feedback from desired value
	P_Term = err * kp;           //  Proportional gain
    I_State= I_State + err;     //   Accumalted Error

    if (I_State >=500)
	I_State=500;
    if (I_State <=-500)
	I_State=-500;

    I_Term = I_State * ki;     //    Integral gain


    val   = P_Term + I_Term;  ///////// Value for PWM /////

          if(flag==1 && count1==1)
     {  
              count1=0;
              count0=0;
              c1=1;
              c0=0;
 if(val > 115)
	  {
                     BACKWARD1(128, 115);  
                     BACKWARD2(128,115);
	   }
	
  else if(val<=115)
      {       
                      //BACKWARD1(128, val);
                      //BACKWARD2(128,val);
      } 	

}
	 else if(flag==0 && count0==1)
	  {
		       count0=0;
               count1=0;
               c0=1;
               c1=0;
              if(val > 115)
	                {                      
					    FORWARD1(128, 115);
				        FORWARD2(128,115);               
                    }

              else if(val<=115)
                    {
				        FORWARD1(128, val);      
				        FORWARD2(128,val);              
                    } 
	   }

/////////// Angle Check ///////
	GET_BINO_COMPASS();
	GET_STAND_COMPASS();                     
                             azz = g_standAzimuth;
							 azz1= g_BinoAzimuth; 	
                            dif=azz-azz1;
  /*                        
                 if(in==1)
           {
                   break;
           }
   */                       

                 if(dif>0)
                           {
                                   if(dif>180)
                                       {
												dif=360-(azz-azz1);
                                                flag=0;
                                           count0=count0+1;
                                               count1=0;
                                       }
                                      else 
                                       {
                                                flag=1;
                                                 count1=count1+1;
                                                        count0=0;
                                       }

                           }

                  else if(dif<0)
                           {
                                     dif=-1*dif;

                                      if(dif>180)
                                       {
                                
												dif=360-(azz1-azz);
								                  flag=1;
                                                  count1=count1+1;
                                               count0=0;
                                       }
                                      else 
                                       {
                                                flag=0;
                                                  count0=count0+1;
                                                   count1=0;
                                       }                            
                           }     
}
}





















