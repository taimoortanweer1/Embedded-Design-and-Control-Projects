    #include <p33FJ64MC802.h>
	#include <libpic30.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
	
   
	#define FCY             39613000        //Instruction Cycle Frequency
	#define BAUDRATE         9600		      
	#define BRGVAL          ((FCY/BAUDRATE)/16)-1
	#define BAUDRATE2         19200	      
	#define BRGVAL2          ((FCY/BAUDRATE2)/16)-1  

    #define servo P1DC1

    
	void clk(void);





    void main()
       {
             clk();
             __delay32(60000000);
             __delay32(60000000);
             str();
             servo = (.035)*12500*2; // .0516
             //__delay32(60000000);
             //servo = (.112)*12500*2;
             while(1);

       }



///////////////////////////////////////////////////////////////////// CLOCK ///////////////////////////////////////////////////////////////////
	void clk(void)
	{
	
    	 // Configure Oscillator to operate the device at 40Mhz
	    // Fosc= Fin*M/(N1*N2), Fcy=Fosc/2
	   // Fosc= 7.37*43/(2*2)=79.23MHz
		PLLFBD=41;					// M=43
		CLKDIVbits.PLLPOST=0;		// N1=2
		CLKDIVbits.PLLPRE=0;		// N2=2
	

		RCONbits.SWDTEN=0;	               //////////////////////// Disable Watch Dog Timer //////////////////////////////////
	
	
		while(OSCCONbits.LOCK!=1) {};    /////////////////////////// Wait for PLL to lock  //////////////////////////////////
	}

 void str()
{

P1TMR=0X0000;
P1TPER=12500;
PWM1CON1bits.PMOD1=1;
PWM1CON1bits.PEN1H=1;
 




P1TCON=0x800C;


TRISBbits.TRISB14=0;


}

   
