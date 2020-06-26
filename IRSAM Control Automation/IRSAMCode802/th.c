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

    
	void clk(void);
    void configuration();
    unsigned char GET_C1(void);
    unsigned char GET_C2(void);
    void UART_CAMPUS(); 
    void UART_BINOCULAR();
    void TRANSMIT_C1(unsigned char value);

    void INIT_SABERTOOTH();
    void FORWARD1(char address, char speed);
    void FORWARD2(char address, char speed);
    void BACKWARD1(char address, char speed);
    void BACKWARD2(char address, char speed);

    void funcn(unsigned int val);
    void func_all(unsigned int value);
    void HMC3500();
    void HMC3500_end();
   
    void str();
 
    char arr,data[100],read;
    unsigned int j=0,flag2=0,fire=0;
    unsigned long int	AZIMUTH=0;
    signed long int PITCH=0;
    float ref2=0,pit;
	signed int azz,pit1;    
    
    #define servo P1DC1
    #define in PORTBbits.RB10
   
   

    void __attribute__((__interrupt__, no_auto_psv)) _U1RXInterrupt(void)
    {

   
	arr = GET_C1();

    }

      void __attribute__((__interrupt__, no_auto_psv)) _U2RXInterrupt(void)
   {

      read = GET_C2();
	
   }


    void main(void)
 {
      
   unsigned int h=0;

       clk();
       
       configuration();


        func_all(5);
      /*  __delay32(10000);
           HMC3500_end();
          if(pit1<56)
                {
                       FORWARD1(128,45);
                       	__delay32(15000000);
                        __delay32(10000000);
                 } 
             FORWARD1(128,0);
            h=pit1+5;
         FORWARD1(128,45);
                 while(1)
                    {
                        HMC3500_end();
                          if(pit1>=60 || pit1>=h)
                              {
                                 FORWARD1(128,0); 
							        break;
                              } 
                    }
                 FORWARD1(128,0); 
           */
       __delay32(1000); 
       str();
       servo = (.0516)*12500*2; // .0516 .035
									   

 
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


    /////////////////////////////////////////////////////////////// CONFIGURATION //////////////////////////////////////////////////////////////

	 void configuration()
	{
     PORTB = 0x0000;

	//__delay32(6000000);
	//__delay32(6000000);
	//__delay32(6000000);
   	//__delay32(6000000);
	__delay32(6000000);
    __delay32(6000000);
 	__delay32(6000000);
	__delay32(6000000); 
  __delay32(6000000);
	__delay32(6000000);
   UART_BINOCULAR();
   INIT_SABERTOOTH();
 
   	  
       UART_CAMPUS();
         
	U1STAbits.OERR = 0;
   TRISBbits.TRISB10=1;
	}


     ///////////////////////////////////////////////////////////// INITIALIZING UART 1 ////////////////////////////////////////////////////////

   	void UART_CAMPUS()                 
    {	
	RPINR18 = 7;	// = 9 acceptable		
	RPOR3bits.RP6R = 3;	
		
	TRISBbits.TRISB7 = 1; //7
	TRISBbits.TRISB6=  0; //6
	
	U1BRG  = BRGVAL;

	_U1RXIP = 7;	
	_U1RXIF = 0;
       _U1RXIE = 1;

	U1MODE = 0x8000; 	
	U1STA  = 0x0440; 
	}

   	void UART_BINOCULAR()           ///////////////////// serial 1 controller 2 //////////////////////
{	
	RPINR19 = 5;	// = 9 acceptable		
//	RPOR5bits.RP11R = 5;
	
	RPOR6bits.RP12R = 5;

	TRISBbits.TRISB5 = 1; //7
	TRISBbits.TRISB12=0; //6
	//TRISBbits.TRISB11=0;  //6
	U2BRG  = BRGVAL;

	_U2RXIP = 7;	
	_U2RXIF = 0;
    _U2RXIE = 1;

	U2MODE = 0x8000; 	
	U2STA  = 0x0440; 
		
}


   ///////////////////////////////////////////////////////// TRANSMIT FUNCTION FOR UART 1 //////////////////////////////////////////

    void TRANSMIT_C1(unsigned char value)
    {
	while(!U1STAbits.TRMT);
	U1TXREG = value;
	while(!U1STAbits.TRMT);
	_U1RXIF=0;			 	         /////////////////////////Clear UART RX Interrupt Flag /////////////////////////////////////
    }

   ////////////////////////////////////////////////////// TRANSMIT FUNCTION FOR UART 2 /////////////////////////////////////////////////

void TRANSMIT_C2(unsigned char value)
{
	while(!U2STAbits.TRMT);
	U2TXREG = value;
	while(!U2STAbits.TRMT);
	_U2RXIF=0;				//Clear UART RX Interrupt Flag
}



    ///////////////////////////////////////////////////// RECEIVE FUNCTION FOR UART 1 ///////////////////////////////////////////////////

    unsigned char GET_C1(void)
    {
	while (_U1RXIF==0);			         /////////////////////////// Wait and Receive One Character ///////////////////////////////
	_U1RXIF = 0;
    return U1RXREG;
    }

unsigned char GET_C2(void)
{
	while (IFS1bits.U2RXIF==0);			// Wait and Receive One Character
	IFS1bits.U2RXIF = 0;
   
	return U2RXREG;
}

  /////////////////////////////////////////////////////// HMC3500 FUNCTION ///////////////////////////////////////////////////////////
void HMC3500()
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



			
			PITCH = ((unsigned int)MY_STRING[7]*(unsigned int)256);
			PITCH = PITCH+(unsigned int)MY_STRING[6];
			PITCH = PITCH*(unsigned int)1000;
            PITCH = (PITCH/(unsigned int)65535);
			PITCH = PITCH*(unsigned int)360;
			//PITCH = PITCH/(unsigned int)1000;
              pit1=PITCH/(unsigned int)1000;
             
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



			
			PITCH = ((unsigned int)MY_STRING[7]*(unsigned int)256);
			PITCH = PITCH+(unsigned int)MY_STRING[6];
			PITCH = PITCH*(unsigned int)1000;
            PITCH = (PITCH/(unsigned int)65535);
			PITCH = PITCH*(unsigned int)360;
			//PITCH = PITCH/(unsigned int)1000;
              pit1=PITCH/(unsigned int)1000;
             
    i=0;

             _U1RXIE = 1;

  }


 void HMC3500_BINO()
  {

    unsigned int i=0,s=0;
    char MY_STRING[8],str1[5],str2[5]; 

    _U2RXIE = 0;
  

   while(GET_C2()!= 'P');

      
            


  	while(i<6)
	{
	str2[i]=GET_C2();
	i++;
          
	}


            pit=atof(str2);
    i=0;

_U2RXIE = 1;

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





void funcn(unsigned int val)
{
             RPINR16bits.QEA2R=15;            /////////////// Map pins for Encoder //////////////
		    RPINR16bits.QEB2R=14;
		
		    TRISBbits.TRISB14=1;             ////////////// Setting pins as input ///////////////
		    TRISBbits.TRISB15=1;



        MAX2CNT=35000;  ///5800
     	POS2CNT=100;
       IFS3bits.QEI1IF=0;
        QEI2CON= 0X0000;

        QEI2CONbits.PCDOUT=1;
        QEI2CONbits.SWPAB=0;
      
    
        
      	QEI2CONbits.QEIM=7;
         
        while(POS2CNT<val);
     

           QEI2CONbits.QEIM=0;
           IFS4bits.QEI2IF=0;
        


}
void func_all(unsigned int value)
{
	  int err = 0,  P_Term = 0,I_State=0 ,val=0;
	  float kp=3.4; //4
      float ki= .00007, I_Term=0 ;//.00075
      signed int dif=0;
      unsigned int flag=0,check=1;
     
    

		   
  
while(1)
{

   
	err    = dif;   // Error term obtained by subtracting feedback from desired value

	P_Term = err * kp;           //  Proportional gain

    I_State= I_State + err;     //   Accumalted Error

    if (I_State >=1500)
	I_State=1500;
    if (I_State <=-1500)
	I_State=-1500;

    I_Term = I_State * ki;     //    Integral gain


    val   = P_Term + I_Term;            /////////////////////////////// Value for PWM //////////////////////////////

          if(flag==1)
     {  
 if(val > 35)
	  {

	    
 
          BACKWARD1(128,35);
	  }
	
  else if(val<=35)
      {
        
       
      
       BACKWARD1(128,val);
      } 	

}
	 else if(flag==0)
	  {
		      
             
              if(val > 35)
	                {
                   
                    
                          FORWARD1(128,35);
                    }

              else if(val<=35)
                    {
                                        
                                                      FORWARD1(128,val);
                    } 
		
	   }



   ///////////////////////////////////////////////////////////////////////// Angle Check /////////////////////////////////////////////////////////////////// 
	                  
   
                            
				             HMC3500();
                   if(in==1)
           { 
                FORWARD1(128,0);
               break;
           } 
                              HMC3500_BINO(); ///////here


                                     dif=pit-pit1;
          
      if(in==1)
           { 
                FORWARD1(128,0);
               break;
           } 
     

                     if((pit1<21 || pit1>45)&& check==0)
                         {
                                     BACKWARD1(128,0);
                                    

                                          while(1)
                                            {
                                                                        HMC3500_BINO(); //here
                                                                           if(in==1)
																	           { 
																	                FORWARD1(128,0);
																	               break;
																	           } 

                                                            if(pit>23 && pit<42)
                                                                 {
                                                                  
                                                                      check=1;
                                                                   break;
                                                                 } 

                                            }      
                            

                            dif=pit-pit1; 
                                               
                         } 
        if(in==1)
           { 
                FORWARD1(128,0);
               break;
           }

                                                      if(check==1)
                                                                 {
                                                                         if(pit1>23 && pit1<42)
                                                                                {
                                                                               		check=0;
                                                                               	}
                                                                   
                                                                 } 

                                                      if(pit1<8 || pit1>60)
                                                               {
                                                                     check=0;
                                                               } 
                                                           
                   
                             
                 if(dif>0)
                           {
                                   if(dif>180)
                                       {
                                                flag=1;
                                       }
                                      else 
                                       {
                                                flag=0;
                                       }

                           }

                  else if(dif<0)
                           {
                                     dif=-1*dif;
                                      if(dif>180)
                                       {
                                                flag=0;
                                       }
                                      else 
                                       {
                                                flag=1;
                                       }
                            

                           }         
    
   
}
   
   





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


