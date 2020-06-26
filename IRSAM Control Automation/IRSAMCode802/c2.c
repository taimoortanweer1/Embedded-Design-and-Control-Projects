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

    #define in PORTBbits.RB10

    
	void clk(void);
    void configuration();
    void UART_BINOCULAR();
    void UART_CAMPUS();
    unsigned char GET_C1(void);
    unsigned char GET_C2(void);
    void TRANSMIT_C1(unsigned char value);
    void TRANSMIT_C2(unsigned char value);

    void INIT_SABERTOOTH();
    void INIT_UART_START(void);
    void TRANSMIT_C1(unsigned char value);
    void FORWARD1(char address, char speed);
    void FORWARD2(char address, char speed);
    void BACKWARD1(char address, char speed);
    void BACKWARD2(char address, char speed);

    void HMC3500();
    void HMC3500_BINO();
    void HMC3500_end();
    void func_all(unsigned int value);
    
    char arr,data[100],read;
    unsigned int j=0,flag2=0,fire=0,count0=0,count1=0,c1=0,c0=0;
    unsigned long int	AZIMUTH=0;
    signed long int PITCH=0;
    float ref2=0,azz;
    signed int pit,azz1,pit1; 
   
   

    void __attribute__((__interrupt__, no_auto_psv)) _U1RXInterrupt(void)
    {

   
	   arr=GET_C1();

    }
   void __attribute__((__interrupt__, no_auto_psv)) _U2RXInterrupt(void)
   {

   
	read = GET_C2();
	
  }


    int main(void)
     {
   
         
       clk();
   
       configuration();
  
       
      func_all(5);
 FORWARD1(128,0);     
				               FORWARD2(128,0);
while(1);
      __delay32(10000);
                      HMC3500_end();
                      
                      

             if(c0==1)
                 {
                         azz=azz1-10;
                               if(azz<0)
                                      {
                                                          azz=360+azz;
                                                         if(azz<357)
                                                               {
                                                                     azz=azz-2;
                                                               }
                                      } 
                               if(azz<3)
                                      {
                                              azz=azz+2;
                                      }   
                               FORWARD1(128,115);   // 60...55...40     
				               FORWARD2(128,115);
                          while(1)
                               {
                            
                                   HMC3500_end(); 
                                    
                                                 if(azz-2<=azz1 && azz1<=azz+2)
                                                       break;
                                    
                               }
                              FORWARD1(128,0);   // 60...55...40     
				               FORWARD2(128,0);
                 }

            if(c1==1)
                {
                       azz=azz1+10;  

                                          if(azz>360)
                                     {
                                                 azz=azz-360;
                                               if(azz<3)
                                                  {
                                                         azz=azz+2;
                                                  } 
                                     } 
                                if(azz>357)
                                      {
                                            azz=azz-2;
                                      } 

                             BACKWARD1(128,115);       
				             BACKWARD2(128,115);
                             while(1)
                             {
                                
                                
                              HMC3500_end();
                                    if(azz-2<=azz1 && azz1<=azz+2)
                                         {
                                             break;
                                         } 
                             
                             }
                             BACKWARD1(128,0);       
				             BACKWARD2(128,0);
                }
 
    while(1);
     
      return(0);
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


    /////////////////////////////////////////////////////////////// CONFIGURATION //////////////////////////////////////////////////////////////

	 void configuration()
	{
           
	   
 
	__delay32(6000000);
	__delay32(6000000);
	__delay32(6000000);
	__delay32(6000000);
	__delay32(6000000);
	__delay32(6000000);
	__delay32(6000000);
	__delay32(6000000);
	
	__delay32(6000000);
	
   __delay32(6000000);
   __delay32(6000000);

       
   

     UART_CAMPUS ();
	
     UART_BINOCULAR();
 
     INIT_SABERTOOTH();

     TRISBbits.TRISB10=1;
	  
	}


    ///////////////////////////////////////////////////////////// INITIALIZING UART 1 ////////////////////////////////////////////////////////
   	void UART_CAMPUS()                     
    {	
	RPINR18 = 4;	                      ///////////////////////////////// Receive ///////////////////////////////// 	
	RPOR2bits.RP5R = 3;	                  ///////////////////////////////// Transmit ///////////////////////////////// 
	//	RPOR6bits.RP13R = 3;	
	TRISBbits.TRISB4 = 1;                 ///////////////////////////////// Receive ///////////////////////////////// 
	TRISBbits.TRISB5=  0;                 ///////////////////////////////// Transmit /////////////////////////////////

	U1BRG  = BRGVAL;

	_U1RXIP = 7;	
	_U1RXIF = 0;
    _U1RXIE = 1;

	U1MODE = 0x8000; 
	U1STA  = 0x0440; 
    }

   ///////////////////////////////////////////////////////// TRANSMIT FUNCTION FOR UART 1 //////////////////////////////////////////

    void TRANSMIT_C1(unsigned char value)
    {
	while(!U1STAbits.TRMT);
	U1TXREG = value;
	while(!U1STAbits.TRMT);
	_U1RXIF=0;			 	         /////////////////////////Clear UART RX Interrupt Flag /////////////////////////////////////
    }


    ///////////////////////////////////////////////////// RECEIVE FUNCTION FOR UART 1 ///////////////////////////////////////////////////

    unsigned char GET_C1(void)
    {
	while (_U1RXIF==0);			         /////////////////////////// Wait and Receive One Character ///////////////////////////////
	_U1RXIF = 0;
    return U1RXREG;
    }


 	void UART_BINOCULAR()           ///////////////////// serial 1 controller 2 //////////////////////
{	
	RPINR19 = 12;	// = 9 acceptable		

	
	RPOR6bits.RP13R = 5;

	TRISBbits.TRISB12 = 1; //7
    TRISBbits.TRISB13=0; //6

	U2BRG  = BRGVAL;

	_U2RXIP = 7;	
	_U2RXIF = 0;
    _U2RXIE = 1;

	U2MODE = 0x8000; 	
	U2STA  = 0x0440; 
		
}

////////////////////////////////////////////////////// TRANSMIT FUNCTION FOR UART 2 /////////////////////////////////////////////////

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

////////////////////////////////////////////////// Sabetooth UART /////////////////////////////////////////////////////

	void INIT_UART_START()
	{
	
	//	RPINR19 = 10;			// Make Pin RP9 U1RX
		RPOR6bits.RP13R = 3;		// Make Pin RP8 U1TX
		
	//	TRISBbits.TRISB9 = 1;
		TRISBbits.TRISB13 = 0;
	
	//	AD1PCFGL = 0x03C0;		// Make analog pins digital 
		U1BRG  = BRGVAL;

		U1MODE = 0x8000; /* Reset UART to 8-n-1, alt pins, and enable */
		U1STA  = 0x0440; /* Reset status register and enable TX & RX*/
	
	
	}

/////////////////////////////////////////////////// INITIALIZING SABERTOOTH ////////////////////////////////////////////////////////////////

 void INIT_SABERTOOTH(void)
	{
	
	TRANSMIT_C2(0xAA); //Autobauding character to Sabertooth
	__delay32(2000000); //100mSEC delay
	
	}

//////////////////////////////////////////////// FORWARD 1 //////////////////////////////////////////

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










/////////////////////////////////////////////////////// HMC3500 FUNCTION ///////////////////////////////////////////////////////////
void HMC3500()
  {

    unsigned int i=0;
    unsigned char MY_STRING[1000]; 

       _U1RXIE = 0;
   

    while(GET_C1()!= 13)
        {
      if(in==1)
           { 
               break;
           } 
     }
       
	while(i<11 && in==0)
	{
	MY_STRING[i]=GET_C1();
	i++;
           
             
	}
	i=0;
			AZIMUTH = ((unsigned int)MY_STRING[9]*(unsigned int)256);
			AZIMUTH = AZIMUTH+(unsigned int)MY_STRING[8];
			AZIMUTH = AZIMUTH*(unsigned int)1000;
			AZIMUTH = (AZIMUTH/(unsigned int)65535);
			AZIMUTH = AZIMUTH*(unsigned int)360;
			//AZIMUTH = AZIMUTH/(unsigned int)1000;
              azz1=AZIMUTH/(float)1000;

		
    i=0;

             _U1RXIE = 1;

  }


void HMC3500_end()
  {

    unsigned int i=0;
    unsigned char MY_STRING[1000]; 

       _U1RXIE = 0;
   

    while(GET_C1()!= 13);
                
        
	while(i<11)
	{
	MY_STRING[i]=GET_C1();
	i++;
	}
	i=0;
			AZIMUTH = ((unsigned int)MY_STRING[9]*(unsigned int)256);
			AZIMUTH = AZIMUTH+(unsigned int)MY_STRING[8];
			AZIMUTH = AZIMUTH*(unsigned int)1000;
			AZIMUTH = (AZIMUTH/(unsigned int)65535);
			AZIMUTH = AZIMUTH*(unsigned int)360;
			//AZIMUTH = AZIMUTH/(unsigned int)1000;
              azz1=AZIMUTH/(float)1000;

		
    i=0;

             _U1RXIE = 1;

  }

 void HMC3500_BINO()
  {

    unsigned int i=0;
    char str1[5],str2[5]; 

    _U2RXIE = 0;
  

   while(GET_C2()!= 'H');
      
            
	while(i<6)
	{
	str1[i]=GET_C2();
	i++;
          
	}



			azz=atof(str1);
          
    i=0;

_U2RXIE = 1;

  }





void func_all(unsigned int value)
{
	  int err = 0,  P_Term = 0,I_State=0 ,val=0;
	  float kp=3.9;  //5.8 .......... 4.4
      float ki= .00000003, I_Term=0 ; //.000025 ........ .00002
      signed int dif=0;
      unsigned int flag=0, ch=0;
     
    

		   
  
while(1)
{

   if(in==1)
           {
                   break;
           } 
	err    = dif;   // Error term obtained by subtracting feedback from desired value

	P_Term = err * kp;           //  Proportional gain

    I_State= I_State + err;     //   Accumalted Error

    if (I_State >=500)
	I_State=500;
    if (I_State <=-500)
	I_State=-500;

    I_Term = I_State * ki;     //    Integral gain


    val   = P_Term + I_Term;            /////////////////////////////// Value for PWM //////////////////////////////

          if(flag==1 && count1==1)
     {  
              count1=0;
              count0=0;
              c1=1;
              c0=0;
 if(val > 115)
	  {

	 

                     BACKWARD1(128, 115);            /////////////////////////////////////// Move Backwards /////////////////////////////////
                     BACKWARD2(128,115);
       
	   }
	
  else if(val<=115)
      {
       
          
                      BACKWARD1(128, val);          ////////////////////////////////////// Move Backwards /////////////////////////////////
                      BACKWARD2(128,val);
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
                             
					    FORWARD1(128, 115);       /////////////////////////////// Move Forward /////////////////////////////////
				        FORWARD2(128,115);

                
                          
                    }

              else if(val<=115)
                    {
                
                     
				        FORWARD1(128, val);      ////////////////////////////// Move Forwrd /////////////////////////////////
				        FORWARD2(128,val);
				                   
                    } 
		
	   }



   ///////////////////////////////////////////////////////////////////////// Angle Check /////////////////////////////////////////////////////////////////// 
	                  
     // __delay32(900000);
                             HMC3500_BINO();
                                       
				             HMC3500();
                                   
                             dif=azz-azz1;
                          
                 if(in==1)
           {
                   break;
           }
                          

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




