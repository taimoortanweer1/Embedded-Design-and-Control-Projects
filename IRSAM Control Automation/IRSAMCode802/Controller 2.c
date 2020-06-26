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
    void func_all(unsigned int value);
    
    char arr,data[100],read;
    unsigned int j=0,flag2=0;
    unsigned long int	AZIMUTH=0;
    signed long int PITCH=0;
    float azz,pit,ref2=0,azz1,pit1;
    
   
   

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
       unsigned int y=0,i,s,flag=3;;
       char str1[30],str2[5],str[30];
       float dif=0,val=0;

       clk();
       
       configuration();

       HMC3500();
       HMC3500_BINO();
        

     dif=azz-azz1;

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

                     if(flag==0)
                          {              
                              FORWARD2(128, 80);      ////////////////////////////// Move Forwrd /////////////////////////////////
                              FORWARD1(128,80);
								      while(1)
								            {
								                 if(azz1>=azz-2  && azz1<azz+2)
								                   break; 
								
								                 HMC3500();    
								            } 

                             BACKWARD2(128, 30);      ////////////////////////////// Move Forwrd /////////////////////////////////
                             BACKWARD1(128, 30);
                             __delay32(10000000);__delay32(10000000);
                             FORWARD2(128, 0);      ////////////////////////////// Move Forwrd /////////////////////////////////
                             FORWARD1(128,0);
                          }  
    
                  
                              if(flag==1)
                          {              
                              BACKWARD2(128, 80);      ////////////////////////////// Move Forwrd /////////////////////////////////
                              BACKWARD1(128,80);
						      while(1)
						            {
						                 if(azz1>=azz-2  && azz1<azz+2)
						                   break; 
						
						                 HMC3500();    
						            } 

                             FORWARD2(128, 30);      ////////////////////////////// Move Forwrd /////////////////////////////////
                             FORWARD1(128, 30);
                             __delay32(10000000);__delay32(10000000);
                             BACKWARD2(128, 0);      ////////////////////////////// Move Forwrd /////////////////////////////////
                            BACKWARD1(128,0);
                          }  
    

               HMC3500_BINO();
               ref2=azz;
               funcn_all(200);

            while(1);

                        FORWARD2(128, 50);      ////////////////////////////// Move Forwrd /////////////////////////////////
                              FORWARD1(128,50);
                                  funcn(500);
                             FORWARD2(128, 0);      ////////////////////////////// Move Forwrd /////////////////////////////////
                             FORWARD1(128,0);
                                 val=dif*22;
                                  //fun(660);
                             while(1);
       HMC3500_BINO();

       HMC3500();
       
      dif=azz1-azz;

        if(dif<-150)                     //////// CASE FOR ANGLE GOING FROM 360 TO 0
                       {
                               dif=dif+360;
                               flag2=1;

                       }

                  else if(dif>150)               ///////// CASE OF ANGLE GOING FROM 0 TO 360
                       {
                               dif=360-dif;
                               flag2=0;

                       }

                  else if(dif<0 && dif>-90)    ///////// CASE OF ANGLE SMALLER THEN REFRENCE
                       {
                               dif=-1*dif;
                                   flag2=0;
                              
                       }
                  else                          /////////// CASE OF ANGLE GREATER THEN REFRENCE
                       {
                               flag2=1;
                       }

                               
                               
                                          
                                  
                                  val=dif*22;

                        if(flag2==1)
                                {

                              FORWARD2(128, 50);      ////////////////////////////// Move Forwrd /////////////////////////////////
                              FORWARD1(128,50);
                                  funcn(val);
                             FORWARD2(128, 0);      ////////////////////////////// Move Forwrd /////////////////////////////////
                             FORWARD1(128,0);
                                } 
                            if(flag2==0)
                                {

                              BACKWARD2(128, 50);      ////////////////////////////// Move Forwrd /////////////////////////////////
                              BACKWARD1(128,50);
                                  func(val);
                             BACKWARD2(128, 0);      ////////////////////////////// Move Forwrd /////////////////////////////////
                             BACKWARD1(128,0);
                                } 
                                while(1);
















     while(1)
{
                  
       ref2=azz;
}				    
            funcn_all(200); //7920

     
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
 
   INIT_SABERTOOTH();
       
    __delay32(6000000);
	__delay32(6000000);

    UART_CAMPUS();
	
	  
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
//	RPOR5bits.RP11R = 5;
	
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
   

    while(GET_C1()!= 13);
	while(i<23)
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

		/*	PITCH = ((unsigned int)MY_STRING[7]*(unsigned int)256);
			PITCH = PITCH+(unsigned int)MY_STRING[6];
			PITCH = PITCH*(unsigned int)1000;
            PITCH = (PITCH/(unsigned int)65535);
			PITCH = PITCH*(unsigned int)360;
			//PITCH = PITCH/(unsigned int)1000;
              pit1=PITCH/(float)1000;*/
    i=0;

             _U1RXIE = 1;

  }

void HMC3500_BINO()
  {

    unsigned int i=0;
    unsigned char MY_STRING[1000]; 

       _U2RXIE = 0;
    //UART_BINOCULAR();

    while(GET_C2()!= 13);
	while(i<23)
	{
	MY_STRING[i]=GET_C2();
	i++;
	}
	i=0;
			AZIMUTH = ((unsigned int)MY_STRING[9]*(unsigned int)256);
			AZIMUTH = AZIMUTH+(unsigned int)MY_STRING[8];
			AZIMUTH = AZIMUTH*(unsigned int)1000;
			AZIMUTH = (AZIMUTH/(unsigned int)65535);
			AZIMUTH = AZIMUTH*(unsigned int)360;
			//AZIMUTH = AZIMUTH/(unsigned int)1000;
              azz=AZIMUTH/(float)1000;

		/*	PITCH = ((unsigned int)MY_STRING[7]*(unsigned int)256);
			PITCH = PITCH+(unsigned int)MY_STRING[6];
			PITCH = PITCH*(unsigned int)1000;
            PITCH = (PITCH/(unsigned int)65535);
			PITCH = PITCH*(unsigned int)360;
			//PITCH = PITCH/(unsigned int)1000;
              pit=PITCH/(float)1000;*/
    i=0;

             _U2RXIE = 1;

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
void func(unsigned int val)
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

void fun(unsigned int value)
{
	 int err = 0,  P_Term = 0,I_State=0 ,val=0,check;
	 float kp=.95;
     float ki= .001, I_Term=0 ;
      float ref=0,angle=0,diff=0,count=0;
      char str[20],str2[5]; 
      unsigned int i,flag3=0,s;
     
    

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


    val   = P_Term + I_Term;            /////////////////////////////// Value for PWM //////////////////////////////

            


   if(val > 115)
	  {

	                 BACKWARD2(128, 115);            /////////////////////////////////////// Move Backwards /////////////////////////////////
                     BACKWARD1(128,115);
	  }
	
  else if(val<=115)
      {
        
                      BACKWARD2(128, val);          ////////////////////////////////////// Move Backwards /////////////////////////////////
                      BACKWARD1(128,val);
      } 	


	 else if(val < 0)
	  {
		       val = -1 * val;
             
              if(val > 115)
	                {
                    FORWARD2(128, 115);      ////////////////////////////// Move Forwrd /////////////////////////////////
                    FORWARD1(128,115);
                    }

              else if(val<=115)
                    {
                                  FORWARD2(128, val);      ////////////////////////////// Move Forwrd /////////////////////////////////
                                  FORWARD1(128,val);
                    } 
		
	   }




                          
               
             
   
}
   
       QEI2CONbits.QEIM=0;
       IFS4bits.QEI2IF=0;



}




void func_all(unsigned int value)
{
	  int err = 0,  P_Term = 0,I_State=0 ,val=0,check;
	  float kp=.45;
      float ki= .0005, I_Term=0 ;
      float ref=0,angle=0,diff=0,count=0;
      char str[20],str2[5]; 
      unsigned int i,flag3=0,y=0,s=0;
     
    

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


    val   = P_Term + I_Term;            /////////////////////////////// Value for PWM //////////////////////////////

            


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


	 else if(val < 0)
	  {
		       val = -1 * val;
             
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




   ///////////////////////////////////////////////////////////////////////// Angle Check /////////////////////////////////////////////////////////////////// 
	                  
   
                             HMC3500_BINO();
				             
                               angle=azz;
                               diff=ref-angle;
                               

                                      

                   
                  
                      

                 if(diff<-180)                     //////// CASE FOR ANGLE GOING FROM 360 TO 0
                       {
                               diff=diff+360;
                               flag2=1;

                       }
                  else if(diff>180)               ///////// CASE OF ANGLE GOING FROM 0 TO 360
                       {
                               diff=360-diff;
                               flag2=0;

                       }

                  else if(diff>0 && diff<60)    ///////// CASE OF ANGLE SMALLER THEN REFRENCE
                       {
                              // diff=-1*diff;
                               flag2=1;
                       }
                  else                          /////////// CASE OF ANGLE GREATER THEN REFRENCE
                       {
                                 diff=-1*diff;
                                  flag2=0;
                       }

               
                    
                        
                                  check=value-POS2CNT;
                                  count=diff*22;
                                  value=count+200+check;
                                  POS2CNT=200;
                                  ref=angle;
                                  I_State=0;

                                if(flag2==0)
                                    {
                                  count=diff*22;
                                  value=count+200;  
                                  ref2=angle;  
                                  I_State=0;    
                                  j=0;
                                  funcn_all(value);
                              
                                    }
                                
                                 
                              
                      
                  
              j=0;
               
                  //}
             
   
}
   
       QEI2CONbits.QEIM=0;
       IFS4bits.QEI2IF=0;



}






void funcn_all(unsigned int value)
{
	 int err = 0,  P_Term = 0,I_State=0 ,val=0,check;
	 float kp=.6;
     float ki= .0002, I_Term=0 ;
      float ref=0,angle=0,diff=0,count=0;
      char str[20],str2[5]; 
      unsigned int i,flag3=0,s;
     
    

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


    val   = P_Term + I_Term;            /////////////////////////////// Value for PWM //////////////////////////////

            


   if(val > 110)
	  {

	                 BACKWARD2(128, 110);            /////////////////////////////////////// Move Backwards /////////////////////////////////
                     BACKWARD1(128,110);
	  }
	
  else if(val<=110)
      {
        
                      BACKWARD2(128, val);          ////////////////////////////////////// Move Backwards /////////////////////////////////
                      BACKWARD1(128,val);
      } 	


	 else if(val < 0)
	  {
		       val = -1 * val;
             
              if(val > 110)
	                {
                    FORWARD2(128, 110);      ////////////////////////////// Move Forwrd /////////////////////////////////
                    FORWARD1(128,110);
                    }

              else if(val<=110)
                    {
                                  FORWARD2(128, val);      ////////////////////////////// Move Forwrd /////////////////////////////////
                                  FORWARD1(128,val);
                    } 
		
	   }




   ///////////////////////////////////////////////////////////////////////// Angle Check /////////////////////////////////////////////////////////////////// 
	

				             HMC3500_BINO();
                               angle=azz;
                               diff=ref-angle;
                      

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
                                  count=diff*22;
                                  value=count+200+check;
                                  POS2CNT=200;
                                  ref=angle;
                                  I_State=0;
                                   
                              if(flag2==1)
                                 {
                                  count=diff*22;
                                  value=count+200;  
                                  ref2=angle;      
                                  I_State=0;
                                   j=0;
                                  func_all(value);
                              
                                  }
                                
                          
               
             
   
}
   
       QEI2CONbits.QEIM=0;
       IFS4bits.QEI2IF=0;



}
