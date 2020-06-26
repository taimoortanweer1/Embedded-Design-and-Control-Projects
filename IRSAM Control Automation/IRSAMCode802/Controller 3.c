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
    void TRANSMIT_C1(unsigned char value);

    void INIT_SABERTOOTH();
    void FORWARD1(char address, char speed);
    void FORWARD2(char address, char speed);
    void BACKWARD1(char address, char speed);
    void BACKWARD2(char address, char speed);

    void funcn(unsigned int val);
    void HMC3500();
 
    char arr,data[100],read;
    unsigned int j=0,flag2=0;
    unsigned long int	AZIMUTH=0;
    signed long int PITCH=0;
    float azz,pit,ref2=0;
    
   
   

    void __attribute__((__interrupt__, no_auto_psv)) _U1RXInterrupt(void)
    {

   
	arr = GET_C1();

    }

      void __attribute__((__interrupt__, no_auto_psv)) _U2RXInterrupt(void)
   {

      read = GET_C2();
	
   }


    int main(void)
     {
        unsigned int y=0,i,s;
       char str1[30],str2[5],str[30];

       clk();
       configuration();

    


                     HMC3500();
                     ref2=pit;
                     func_all(200);
                     while(1);


     FORWARD2(128, 30);        ////////// down
      funcn(8129);
     FORWARD2(128, 0);
       while(1);
      
      while(1)
        {
                        
                       HMC3500();
                       ref2=azz;
                     if(pit>=60)
                
                        break;
        }       
      BACKWARD2(128, 0);
          __delay32(30000000);

      FORWARD2(128, 30);        ////////// down
      
      while(1)
        {
                        
                       HMC3500();
                       ref2=azz;
                     if(pit<=5)
                
                        break;
        }       
      FORWARD2(128, 0);
        __delay32(30000000);

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
	__delay32(6000000);
	__delay32(6000000);
	__delay32(6000000);
		__delay32(6000000);
	

    UART_BINOCULAR();
 
   //INIT_UART_START();
      
   INIT_SABERTOOTH();

    __delay32(6000000);
	__delay32(6000000);

    UART_CAMPUS();
      
	
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
	//RPINR19 = 12;	// = 9 acceptable		
//	RPOR5bits.RP11R = 5;
	
	RPOR6bits.RP13R = 5;

	//TRISBbits.TRISB12 = 1; //7
	TRISBbits.TRISB13=0; //6
	//TRISBbits.TRISB11=0;  //6
	U2BRG  = BRGVAL;

	_U2RXIP = 7;	
	_U2RXIF = 0;
    _U2RXIE = 0;

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
    j++;
    data[j]=U2RXREG;
     _U2RXIF==0;
	return U2RXREG;
}

  /////////////////////////////////////////////////////// HMC3500 FUNCTION ///////////////////////////////////////////////////////////
void HMC3500()
  {

    unsigned int i=0;
    unsigned char MY_STRING[1000]; 

       _U1RXIE = 0;
   

    while(GET_C1()!= 13);
	while(i<23)
	{
	MY_STRING[i]=GET_C1();
	i++;
	}
	i=0;
			/*AZIMUTH = ((unsigned int)MY_STRING[9]*(unsigned int)256);
			AZIMUTH = AZIMUTH+(unsigned int)MY_STRING[8];
			AZIMUTH = AZIMUTH*(unsigned int)1000;
			AZIMUTH = (AZIMUTH/(unsigned int)65535);
			AZIMUTH = AZIMUTH*(unsigned int)360;
			//AZIMUTH = AZIMUTH/(unsigned int)1000;
              azz=AZIMUTH/(float)1000;
              */
			PITCH = ((unsigned int)MY_STRING[7]*(unsigned int)256);
			PITCH = PITCH+(unsigned int)MY_STRING[6];
			PITCH = PITCH*(unsigned int)1000;
            PITCH = (PITCH/(unsigned int)65535);
			PITCH = PITCH*(unsigned int)360;
			//PITCH = PITCH/(unsigned int)1000;
              pit=PITCH/(float)1000;
    i=0;

             _U1RXIE = 1;

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
	 int err = 0,  P_Term = 0,I_State=0 ,val=0,check=0;
	 float kp=.08;
     float ki= .0005, I_Term=0 ;
      float ref=0,angle=0,diff=0,count=0;
      char str[20],str2[5]; 
      unsigned int i,flag3=0,y=0;
     
    

		    QEI2CONbits.QEIM=0;              //////////////// Shutdown encoder //////////////////
		    IFS4bits.QEI2IF=0;               /////////////// Reset Intrrupt Flag ////////////////

		    RPINR16bits.QEA2R=15;            /////////////// Map pins for Encoder //////////////
		    RPINR16bits.QEB2R=14;
		
		    TRISBbits.TRISB14=1;             ////////////// Setting pins as input ///////////////
		    TRISBbits.TRISB15=1;



	        MAX2CNT=35000;  ///5800          /////////// Max value to be compared to /////////////////
	        POS2CNT=200;                     ////////// Intial value for Position count //////////////
	        IFS3bits.QEI1IF=0;               /////////////// Reset Intrrupt Flag /////////////////////
	        QEI2CON= 0X0000;                 ////////////// Initialize Control Register //////////////    
	
	        QEI2CONbits.PCDOUT=1;
	        QEI2CONbits.SWPAB=1;             ///////////////// Set Direction ////////////////////////
	   
     
        
        	QEI2CONbits.QEIM=7;              ///////////////// Start Encoder ///////////////////////
                          ref=ref2;
                 
    
  
while(1)
{
 
     
   
	err    = (value) - POS2CNT;   // Error term obtained by subtracting feedback from desired value
	P_Term = err * kp;           //  Proportional gain

    I_State= I_State + err;     //   Accumalted Error

    if (I_State >=1500)
	I_State=1500;
    if (I_State <=-1500)
	I_State=-1500;

    I_Term = I_State * ki;     //    Integral gain


    val   = P_Term+ I_Term;            /////////////////////////////// Value for PWM //////////////////////////////

            //if(val<10 && val>-10)
              //break;

  

   if(val > 28)
	  {

	   
                     BACKWARD2(128,28);
	  }
	
  else if(val<=28)
      {
        
        BACKWARD2(128,val);
      } 	


	 else if(val < 0)
	  {
		       val = -1 * val;
             
              if(val > 28)
	                {
                   
                     FORWARD2(128,28);
                    }

              else if(val<=28)
                    {
                      
                         FORWARD2(128,val);
                    } 
		
	  } 
     



  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


                     HMC3500();
                      
                     if(pit<4 || pit>55)
                         {
                                     FORWARD2(128,0);

                                          while(1)
                                            {
                                                            HMC3500();

                                                            if(pit>4 && pit<55)
                                                                  break;

                                            }                     
                         } 
                    angle=pit;
                    diff=angle-ref;
                 
                    if(diff<-150)                     //////// CASE FOR ANGLE GOING FROM 360 TO 0
                       {
                               diff=diff+360;
                              flag2=1;

                       }

                  else if(diff>150)               ///////// CASE OF ANGLE GOING FROM 0 TO 360
                       {
                               diff=360-diff;
                              flag2=0;

                       }

                  else if(diff<0 && diff>-90)    ///////// CASE OF ANGLE SMALLER THEN REFRENCE
                       {
                               diff=-1*diff;
                               flag2=0;
                       }
                  else                          /////////// CASE OF ANGLE GREATER THEN REFRENCE
                       {
                               // diff=-1*diff;
                                  flag2=1;
                       }
                                  check=value-POS2CNT;
                                  count=diff*700;
                                  value=count+200;//+check;
                                  POS2CNT=200;
                                  ref=angle;
                                  I_State=0;

                         if(flag2==0)
                                    {
                                  count=diff*700;
                                  value=count+200;  
                                  ref2=angle;  
                                  I_State=0;    
                                
                                  funcn_all(value);
                              
                                    }

                      

             
   
}
   
       QEI2CONbits.QEIM=0;
       IFS4bits.QEI2IF=0;



}


void funcn_all(unsigned int value)
{
	 int err = 0,  P_Term = 0,I_State=0 ,val=0,check=0;
	 float kp=.08;
     float ki= .0005, I_Term=0 ;
      float ref=0,angle=0,diff=0,count=0;
      char str[20],str2[5]; 
      unsigned int i,flag3=0,y=0;
     
    

		    QEI2CONbits.QEIM=0;              //////////////// Shutdown encoder //////////////////
		    IFS4bits.QEI2IF=0;               /////////////// Reset Intrrupt Flag ////////////////

		    RPINR16bits.QEA2R=15;            /////////////// Map pins for Encoder //////////////
		    RPINR16bits.QEB2R=14;
		
		    TRISBbits.TRISB14=1;             ////////////// Setting pins as input ///////////////
		    TRISBbits.TRISB15=1;



	        MAX2CNT=35000;  ///5800          /////////// Max value to be compared to /////////////////
	        POS2CNT=200;                     ////////// Intial value for Position count //////////////
	        IFS3bits.QEI1IF=0;               /////////////// Reset Intrrupt Flag /////////////////////
	        QEI2CON= 0X0000;                 ////////////// Initialize Control Register //////////////    
	
	        QEI2CONbits.PCDOUT=1;
	        QEI2CONbits.SWPAB=0;             ///////////////// Set Direction ////////////////////////
	   
     
        
        	QEI2CONbits.QEIM=7;              ///////////////// Start Encoder ///////////////////////
                          ref=ref2;
                 
    
  
while(1)
{
 
     
   
	err    = (value) - POS2CNT;   // Error term obtained by subtracting feedback from desired value
	P_Term = err * kp;           //  Proportional gain

    I_State= I_State + err;     //   Accumalted Error

    if (I_State >=1500)
	I_State=1500;
    if (I_State <=-1500)
	I_State=-1500;

    I_Term = I_State * ki;     //    Integral gain


    val   = P_Term+ I_Term;            /////////////////////////////// Value for PWM //////////////////////////////

            //if(val<10 && val>-10)
              //break;

  

   if(val > 33)
	  {

	   
                     FORWARD2(128,33);
	  }
	
  else if(val<=33)
      {
        
        FORWARD2(128,val);
      } 	


	 else if(val < 0)
	  {
		       val = -1 * val;
             
              if(val > 33)
	                {
                   
                     BACKWARD2(128,33);
                    }

              else if(val<=33)
                    {
                      
                         BACKWARD2(128,val);
                    } 
		
	  } 
     



  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


                     HMC3500();
                               if(pit<4 || pit>55)
                         {
                                     FORWARD2(128,0);

                                          while(1)
                                            {
                                                            HMC3500();

                                                            if(pit>4 && pit<55)
                                                                  break;

                                            }                     
                         } 
                    
                  
                    angle=pit;
                    diff=angle-ref;
                 
                    if(diff<-150)                     //////// CASE FOR ANGLE GOING FROM 360 TO 0
                       {
                               diff=diff+360;
                               flag2=1;

                       }

                  else if(diff>150)               ///////// CASE OF ANGLE GOING FROM 0 TO 360
                       {
                               diff=360-diff;
                              flag2=0;

                       }

                  else if(diff<0 && diff>-90)    ///////// CASE OF ANGLE SMALLER THEN REFRENCE
                       {
                               diff=-1*diff;
                               flag2=0;
                       }
                  else                          /////////// CASE OF ANGLE GREATER THEN REFRENCE
                       {
                               // diff=-1*diff;
                                 flag2=1;
                       }
                                  check=value-POS2CNT;
                                  count=diff*700;
                                  value=count+200;//+check;
                                  POS2CNT=200;
                                  ref=angle;
                                  I_State=0;

                      
                                if(flag2==1)
                                 {
                                  count=diff*700;
                                  value=count+200;  
                                  ref2=angle;      
                                  I_State=0;
                                  
                                  func_all(value);
                              
                                  }
             
   
}
   
       QEI2CONbits.QEIM=0;
       IFS4bits.QEI2IF=0;



}

