    #include <p33FJ64MC802.h>
	#include <libpic30.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
	
   
	#define FCY             39613000        //Instruction Cycle Frequency
	#define BAUDRATE         9600		      
	#define BRGVAL          ((FCY/BAUDRATE)/16)-1
	#define BAUDRATE2         38400  
	#define BRGVAL2          ((FCY/BAUDRATE2)/16)-1  

    
	void clk(void);
    void configuration();

    ///////////////////////////////////////////////////////////// Serial Functions ///////////////////////////////////////////////////////////
    
    void UART_BINOCULER();
    void UART_LCD();
    unsigned char GET_C1(void);
    unsigned char GET_C2(void); 
    void TRANSMIT_C1(unsigned char value);
    void TRANSMIT_C2(unsigned char value);

    void setting_lcd();
    void display_window();
    void display_window2();
    void print_care();
    void print_start();
    void button();
    void enable_touch();
    void detect_region();
    void detect_region2();
    void func_button();
    void display_black1();
    void display_black2();
    void displayr_black1();
    void displayr_black2();
    
   

    void HMC3500();
    void HMC3500_BINO();

    void initial_pic();
    void manual();
    void start();
    void back();
    

    char arr,data[100];
    unsigned int j=0,a=0,q=0;
    unsigned int read=0,read1=0,readx=0,ready=0,readx1=0,ready1=0;
    unsigned long int	AZIMUTH=0;//	PITCH=0;
    signed long int PITCH=0;
    float azz,pit;

 


    void __attribute__((__interrupt__, no_auto_psv)) _U1RXInterrupt(void)
    {

   
	   arr=GET_C1();

    }

   void __attribute__((__interrupt__, no_auto_psv)) _U2RXInterrupt(void)
   {

   
	read = GET_C2();
	
  }


  ///////////////////////////////////////////////////////////////////////// Main ///////////////////////////////////////////////////////////////////


   int main()
    {
         clk();

      
         configuration();
  
 /*while(1)
    {
           
                  // if(arr=='b')
                       // {
                                 TRANSMIT_C1('g');
                    //                    arr=0;
                        //} 
    }
   */       
         setting_lcd();
         start();  
 
        

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
      PORTB = 0x0000;
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
    __delay32(6000000);
    __delay32(6000000);
    __delay32(6000000);
    __delay32(6000000);



     UART_LCD();
   
    UART_BINOCULER();

   	__delay32(6000000);
	__delay32(6000000);
	__delay32(6000000);

	U1STAbits.OERR = 0;
		 
	}


   ///////////////////////////////////////////////////////////// INITIALIZING UART 1 ////////////////////////////////////////////////////////
   	void UART_BINOCULER()                     
    {	
	RPINR18 = 4;	                      ///////////////////////////////// Receive ///////////////////////////////// 	
	RPOR2bits.RP5R = 3;	                  ///////////////////////////////// Transmit ///////////////////////////////// 
		
	TRISBbits.TRISB4 = 1;                 ///////////////////////////////// Receive ///////////////////////////////// 
	TRISBbits.TRISB5=  0;                 ///////////////////////////////// Transmit /////////////////////////////////
	
	U1BRG  = BRGVAL;

	_U1RXIP = 7;	
	_U1RXIF = 0;
    _U1RXIE = 1;

	U1MODE = 0x8000; 	
	U1STA  = 0x0440; 
    }
    ///////////////////////////////////////////////////////////// INITIALIZING UART 2 ////////////////////////////////////////////////////////
   	void UART_LCD()                     
    {	
		    RPINR19 = 14;                
	        RPOR7bits.RP15R = 5;	                  ///////////////////////////////// Transmit ///////////////////////////////// 
					
		    TRISBbits.TRISB14 = 1;		// MAKE PIN B10 AS INPUT
			TRISBbits.TRISB15=  0;                 ///////////////////////////////// Transmit /////////////////////////////////
	        		
			U2BRG  = BRGVAL;
		
			IPC7bits.U2RXIP = 7;	
			IFS1bits.U2RXIF = 0;
			IEC1bits.U2RXIE = 1;
		
			U2MODE = 0x8000; 	
			U2STA  = 0x0440; 
    }

    	void UART_LCD2()                     
    {	
		    RPINR19 = 14;                
	        RPOR7bits.RP15R = 5;	                  ///////////////////////////////// Transmit ///////////////////////////////// 
					
		    TRISBbits.TRISB13 = 1;		// MAKE PIN B10 AS INPUT
			TRISBbits.TRISB15=  0;                 ///////////////////////////////// Transmit /////////////////////////////////
	        		
			U2BRG  = BRGVAL;
		
			IPC7bits.U2RXIP = 7;	
			IFS1bits.U2RXIF = 0;
			IEC1bits.U2RXIE = 1;
		
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


    ///////////////////////////////////////////////////// RECEIVE FUNCTION FOR UART 1 ///////////////////////////////////////////////////

    unsigned char GET_C1(void)
    {
	while (_U1RXIF==0);			         /////////////////////////// Wait and Receive One Character ///////////////////////////////
	_U1RXIF = 0;
    return U1RXREG;
    }



   //////////////////////////////////////////////////// RECEIVE FUNCTION FOR UART 2 /////////////////////////////////////////////////////////

	unsigned char GET_C2(void)
	{
		while (IFS1bits.U2RXIF==0);			// Wait and Receive One Character
		IFS1bits.U2RXIF = 0;
		return U2RXREG;
	}

   ////////////////////////////////////////////////////// TRANSMIT FUNCTION FOR UART 2 /////////////////////////////////////////////////

   void TRANSMIT_C2(unsigned char value)
   {
	while(!U2STAbits.TRMT);
	U2TXREG = value;
	while(!U2STAbits.TRMT);
	_U2RXIF=0;				//Clear UART RX Interrupt Flag
   }
 
  /////////////////////////////////////////////////////// HMC3500 FUNCTION ///////////////////////////////////////////////////////////

 void HMC3500()
  {

    unsigned int i=0;
    unsigned char MY_STRING[1000]; 

    RPINR19 = 13;
    IEC1bits.U2RXIE = 0;

    while(GET_C2()!= 13);
	while(i<15)
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

			PITCH = ((unsigned int)MY_STRING[7]*(unsigned int)256);
			PITCH = PITCH+(unsigned int)MY_STRING[6];
			PITCH = PITCH*(unsigned int)1000;
            PITCH = (PITCH/(unsigned int)65535);
			PITCH = PITCH*(unsigned int)360;
			//PITCH = PITCH/(unsigned int)1000;
              pit=PITCH/(float)1000;
    i=0;

             RPINR19 = 14;
             IEC1bits.U2RXIE = 1;
             

  }

    void HMC3500_BINO()
  {

    unsigned int i=0;
    unsigned char MY_STRING[1000]; 

    _U1RXIE = 0;
  

   while(GET_C1()!= 13);
            
	while(i<15)
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
              azz=AZIMUTH/(float)1000;

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



  //////////////////////////////////////////////////////////// Setting The LCD /////////////////////////////////////////////////////////

   void setting_lcd()
   {
        TRANSMIT_C2('U');      /////////////////////////// Auto Baud Rate ///////////////////////////////////
           
        __delay32(5000000);
       /*a=0x51;
       TRANSMIT_C2(a);
        a=0x0A;
       TRANSMIT_C2(a);
      __delay32(50000000);
       //UART_LCD2(); 
     U2BRG  = BRGVAL2;
*/
	/*	a=0x59;               //////////////////////// Making Display Horizontal //////////////////////////////
		TRANSMIT_C2(a);
		a=0x04;
		TRANSMIT_C2(a);
		a=0x01;
		TRANSMIT_C2(a);
  */
        __delay32(8000000);
  

   } 



  /////////////////////////////////////////////////////////////// DISPLAY WINDOW OF LCD //////////////////////////////////////////

	void display_window()
	{
	
	a=0x72;              ////////////////////////// DISPLAY WINDOW ////////////////////////////////////
	TRANSMIT_C2(a);
	
	a=0x00;             ///////////////////////// HORIZONTAL START //////////////////////////////////
	TRANSMIT_C2(a);
	a=0x10;
	TRANSMIT_C2(a);
	a=0x00;             ///////////////////////// VERTICAL START //////////////////////////////////
	TRANSMIT_C2(a);
	a=0x06;  //06
	TRANSMIT_C2(a);
	
	a=0x00;            ///////////////////////// HORIZONTAL END //////////////////////////////////
	TRANSMIT_C2(a);
	a=0x74;
	TRANSMIT_C2(a);
	a=0x00;            ///////////////////////// VERTICAL END //////////////////////////////////
	TRANSMIT_C2(a);
	a=0xA6;
	TRANSMIT_C2(a);
	
	
	a=0xff;         ///////////// color
	TRANSMIT_C2(a);
	a=0xff;
	TRANSMIT_C2(a);

    __delay32(5000000);
	
	
	}


    /////////////////////////////////////////////////////////////// DISPLAY WINDOW 2 OF LCD //////////////////////////////////////////

	void display_window2()
	{
	
	a=0x72;              ////////////////////////// DISPLAY WINDOW ////////////////////////////////////
	TRANSMIT_C2(a);
	
	a=0x00;             ///////////////////////// HORIZONTAL START //////////////////////////////////
	TRANSMIT_C2(a);
	a=0x80;
	TRANSMIT_C2(a);
	a=0x00;             ///////////////////////// VERTICAL START //////////////////////////////////
	TRANSMIT_C2(a);
	a=0x06;
	TRANSMIT_C2(a);
	
	a=0x00;            ///////////////////////// HORIZONTAL END //////////////////////////////////
	TRANSMIT_C2(a);
	a=0xE4;
	TRANSMIT_C2(a);
	a=0x00;            ///////////////////////// VERTICAL END //////////////////////////////////
	TRANSMIT_C2(a);
	a=0xA6;
	TRANSMIT_C2(a);
	a=0xff;         ///////////// color
	TRANSMIT_C2(a);
	a=0xff;
	TRANSMIT_C2(a);

    __delay32(5000000);
	
	
	}

  



    //////////////////////////////////////////////////////////////////////// Print CARE //////////////////////////////////////////////////////

    void print_care()
    {

        a=0x74;              
    	TRANSMIT_C2(a);
        a=0x43;              
    	TRANSMIT_C2(a);
        a=0x01;             ///////////////////////// HORIZONTAL START //////////////////////////////////
		TRANSMIT_C2(a);
		a=0x00;
		TRANSMIT_C2(a);
		a=0x00;             ///////////////////////// VERTICAL START //////////////////////////////////
		TRANSMIT_C2(a);
		a=0x10;
		TRANSMIT_C2(a);
		a=0xFF;              
    	TRANSMIT_C2(a);
        a=0xFF;              
    	TRANSMIT_C2(a);
        a=0x05;              
    	TRANSMIT_C2(a);
	    a=0x05;              
    	TRANSMIT_C2(a);

	    __delay32(5000000);

	    a=0x74;              
    	TRANSMIT_C2(a);
        a=0x41;              
    	TRANSMIT_C2(a);
        a=0x01;             ///////////////////////// HORIZONTAL START //////////////////////////////////
		TRANSMIT_C2(a);
		a=0x00;
		TRANSMIT_C2(a);
		a=0x00;             ///////////////////////// VERTICAL START //////////////////////////////////
		TRANSMIT_C2(a);
		a=0x40;
		TRANSMIT_C2(a);
		a=0xFF;              
    	TRANSMIT_C2(a);
        a=0xFF;              
    	TRANSMIT_C2(a);
        a=0x05;              
    	TRANSMIT_C2(a);
	    a=0x05;              
    	TRANSMIT_C2(a);
	    
		__delay32(5000000);

	    a=0x74;              
    	TRANSMIT_C2(a);
        a=0x52;              
    	TRANSMIT_C2(a);
        a=0x01;             ///////////////////////// HORIZONTAL START //////////////////////////////////
		TRANSMIT_C2(a);
		a=0x00;
		TRANSMIT_C2(a);
		a=0x00;             ///////////////////////// VERTICAL START //////////////////////////////////
		TRANSMIT_C2(a);
		a=0x70;
		TRANSMIT_C2(a);
		a=0xFF;              
    	TRANSMIT_C2(a);
        a=0xFF;              
    	TRANSMIT_C2(a);
        a=0x05;              
    	TRANSMIT_C2(a);
	    a=0x05;              
    	TRANSMIT_C2(a);
	    
	    __delay32(5000000);

	    a=0x74;              
    	TRANSMIT_C2(a);
        a=0x45;              
    	TRANSMIT_C2(a);
        a=0x01;             ///////////////////////// HORIZONTAL START //////////////////////////////////
		TRANSMIT_C2(a);
		a=0x00;
		TRANSMIT_C2(a);
		a=0x00;             ///////////////////////// VERTICAL START //////////////////////////////////
		TRANSMIT_C2(a);
		a=0xA0;

		TRANSMIT_C2(a);
		a=0xFF;              
    	TRANSMIT_C2(a);
        a=0xFF;              
    	TRANSMIT_C2(a);
        a=0x05;              
    	TRANSMIT_C2(a);
	    a=0x05;              
    	TRANSMIT_C2(a);
        
		__delay32(5000000);
	}



//////////////////////////////////////////////////////////////// BUTTON FOR BACK ////////////////////////////////////////////////////////////////

void button()
{

a=0x72;              ////////////////////////// DISPLAY WINDOW ////////////////////////////////////
TRANSMIT_C2(a);

a=0x00;             ///////////////////////// HORIZONTAL START //////////////////////////////////
TRANSMIT_C2(a);
a=0x18;
TRANSMIT_C2(a);
a=0x00;             ///////////////////////// VERTICAL START //////////////////////////////////
TRANSMIT_C2(a);
a=0xB4;
TRANSMIT_C2(a);

a=0x00;            ///////////////////////// HORIZONTAL END //////////////////////////////////
TRANSMIT_C2(a);
a=0xD9;
TRANSMIT_C2(a);
a=0x00;            ///////////////////////// VERTICAL END //////////////////////////////////
TRANSMIT_C2(a);
a=0xEC;
TRANSMIT_C2(a);


a=0x00;            ////////////////////////////   COLOR   ///////////////////////////////////////
TRANSMIT_C2(a);
a=0x1f;
TRANSMIT_C2(a);

__delay32(1000000);
}

 void print_start()
    {

        a=0x74;              
    	TRANSMIT_C2(a);
         a=0x42;               
    	TRANSMIT_C2(a);
        a=0x00;             ///////////////////////// HORIZONTAL START //////////////////////////////////
		TRANSMIT_C2(a);
		a=0x40;
		TRANSMIT_C2(a);
		a=0x00;             ///////////////////////// VERTICAL START //////////////////////////////////
		TRANSMIT_C2(a);
		a=0xC0;
		TRANSMIT_C2(a);
		a=0xFF;              
    	TRANSMIT_C2(a);
        a=0xFF;              
    	TRANSMIT_C2(a);
        a=0x04;              
    	TRANSMIT_C2(a);
	    a=0x04;              
    	TRANSMIT_C2(a);

	    __delay32(5000000);

        a=0x74;              
    	TRANSMIT_C2(a);
         a=0x41;               
    	TRANSMIT_C2(a);
        a=0x00;             ///////////////////////// HORIZONTAL START //////////////////////////////////
		TRANSMIT_C2(a);
		a=0x60;
		TRANSMIT_C2(a);
		a=0x00;             ///////////////////////// VERTICAL START //////////////////////////////////
		TRANSMIT_C2(a);
		a=0xC0;
		TRANSMIT_C2(a);
		a=0xFF;              
    	TRANSMIT_C2(a);
        a=0xFF;              
    	TRANSMIT_C2(a);
        a=0x04;              
    	TRANSMIT_C2(a);
	    a=0x04;              
    	TRANSMIT_C2(a);

	    __delay32(5000000);

        a=0x74;              
    	TRANSMIT_C2(a);
         a=0x43;               
    	TRANSMIT_C2(a);
        a=0x00;             ///////////////////////// HORIZONTAL START //////////////////////////////////
		TRANSMIT_C2(a);
		a=0x80;
		TRANSMIT_C2(a);
		a=0x00;             ///////////////////////// VERTICAL START //////////////////////////////////
		TRANSMIT_C2(a);
		a=0xC0;
		TRANSMIT_C2(a);
		a=0xFF;              
    	TRANSMIT_C2(a);
        a=0xFF;              
    	TRANSMIT_C2(a);
        a=0x04;              
    	TRANSMIT_C2(a);
	    a=0x04;              
    	TRANSMIT_C2(a);

	    __delay32(5000000);

         a=0x74;              
    	TRANSMIT_C2(a);
        a=0x4B;              
    	TRANSMIT_C2(a);
        a=0x00;             ///////////////////////// HORIZONTAL START //////////////////////////////////
		TRANSMIT_C2(a);
		a=0xA0;
		TRANSMIT_C2(a);
		a=0x00;             ///////////////////////// VERTICAL START //////////////////////////////////
		TRANSMIT_C2(a);
		a=0xC0;
		TRANSMIT_C2(a);
		a=0xFF;              
    	TRANSMIT_C2(a);
        a=0xFF;              
    	TRANSMIT_C2(a);
        a=0x04;              
    	TRANSMIT_C2(a);
	    a=0x04;              
    	TRANSMIT_C2(a);

	 
	    __delay32(5000000);
  }

////////////////////////////////////////////////////////////// ENABLING TOUCH SCREEN /////////////////////////////////////////////////////

void enable_touch()
{

a=0x59; 
TRANSMIT_C2(a);
a=0x05;
TRANSMIT_C2(a);
a=0x00;
TRANSMIT_C2(a);
__delay32(10000000);
read=0;
__delay32(7000000);
}

void disable_touch()
{

a=0x59; 
TRANSMIT_C2(a);
a=0x05;
TRANSMIT_C2(a);
a=0x01;
TRANSMIT_C2(a);
__delay32(9000000);
}


////////////////////////////////////////////////////////////// FUNCTION TO DETECT TOUCH REGION ///////////////////////////////////////////////////

void detect_region()
{



a=0x6F;
TRANSMIT_C2(a);
a=0x00;
TRANSMIT_C2(a);
while(read==0);

readx=read;

while(read==readx);

readx1=read;

while(read==readx1);

ready=read;

 //__delay32(8000000);
 //disable_touch();
if(ready>185 && ready<242)
{


    
        
          if(readx>24 && readx<113)         ///////////////////////////////////// BUTTON 1 H / P / R ////////////////////////////////////////////////
			{ 

              readx=0;ready=0;
                 a=0x40;              ////////////////////////// DISPLAY WINDOW ////////////////////////////////////
            TRANSMIT_C2(a);

			a=0x6D;             ///////////////////////// HORIZONTAL START //////////////////////////////////
			TRANSMIT_C2(a);
			
			TRANSMIT_C2('1');
			
			
			TRANSMIT_C2('.');
			
			TRANSMIT_C2('G');
			                     
			TRANSMIT_C2('c');
			
			TRANSMIT_C2('i');
			a=0x00;
			TRANSMIT_C2(a);
			a=0x00;
			TRANSMIT_C2(a);
			a=0x00;
			TRANSMIT_C2(a);
			a=0x00;
			TRANSMIT_C2(a);
			a=0x00;
			TRANSMIT_C2(a);
			a=0x00;
			TRANSMIT_C2(a);
			a=0x00;
			TRANSMIT_C2(a);
			a=0x00;
			TRANSMIT_C2(a);
			a=0x00;
			TRANSMIT_C2(a);

             
             __delay32(25000000);

                enable_touch();
               
		         while(1)
		          {
                          read=0;
		                  detect_region2();
		                  
		          }
		             
          
         }  

        if(readx>124 && readx<220)
            {

                        __delay32(9000000);
                        TRANSMIT_C2('E');
                        __delay32(8000000);
                        a=0x59;               //////////////////////// Making Display Horizontal //////////////////////////////
						TRANSMIT_C2(a);
						a=0x04;
						TRANSMIT_C2(a);
						a=0x01;
						TRANSMIT_C2(a);
				        __delay32(800000);
	                    display_window();
				        display_window2();
				        print_care();
				        button();
				        print_start();
                        func_button();
	                    while(1);
				         
            } 
}       
}

void start()
{

         initial_pic();
         
         __delay32(30000000);
        
         enable_touch();

         while(1)
          {
                  detect_region();
                read=0;
          }



}


void detect_region2()
{

a=0x6F;
TRANSMIT_C2(a);
a=0x00;
TRANSMIT_C2(a);

while(read==0);

readx=read;

while(read==readx);

readx1=read;

while(read==readx1);

ready=read;



if(ready>1 && ready<80) 
{

    if(q==1)
      {
      if(readx>1 && readx<75)
          {
                q=0;
                 __delay32(10000000); 
                     a=0x40;              ////////////////////////// DISPLAY WINDOW ////////////////////////////////////
            TRANSMIT_C2(a);

			a=0x6D;             ///////////////////////// HORIZONTAL START //////////////////////////////////
			TRANSMIT_C2(a);
			
			TRANSMIT_C2('1');
			
			
			TRANSMIT_C2('.');
			
			TRANSMIT_C2('G');
			                     
			TRANSMIT_C2('c');
			
			TRANSMIT_C2('i');
			a=0x00;
			TRANSMIT_C2(a);
			a=0x00;
			TRANSMIT_C2(a);
			a=0x00;
			TRANSMIT_C2(a);
			a=0x00;
			TRANSMIT_C2(a);
			a=0x00;
			TRANSMIT_C2(a);
			a=0x00;
			TRANSMIT_C2(a);
			a=0x00;
			TRANSMIT_C2(a);
			a=0x00;
			TRANSMIT_C2(a);
			a=0x00;
			TRANSMIT_C2(a);

            __delay32(25000000);
   
    
  
         enable_touch();
         while(1)
          {
                  detect_region2();
                  read=0;
          }         
          }
      } 

     if(q>1)
      {
      if(readx>1 && readx<75)
          {
                
                 __delay32(10000000); 
                  if(q>0)
                   {
                    q=q-1;
                   } 
                 manual();
                     
          }
      }  
      if(readx>90 && readx<160)
          {
                 __delay32(10000000);
                 q=0;
                 start();
                 while(1);
          }
      if(readx>175 && readx<240)
          {
                 __delay32(10000000);
                   if(q<1)
                    {
                  q=q+1;
                    }
                 manual();
          }

 } 

      
}


void func_button()
{
unsigned int s=0,y=0;

char str[30],str1[30],str2[30],str3[30];          //////////////////////// DECLARING ARRAY ///////////////////////////////

__delay32(10000000);

a=0x73;                //////////////////////// DISPLAY HEADING ///////////////////////////////////////
TRANSMIT_C2(a); 
a=0x03;                //////////////////////// HORZONTAL START //////////////////////////////////////
TRANSMIT_C2(a);
a=0x01;                /////////////////////// VERTICAL START ///////////////////////////////////////
TRANSMIT_C2(a);
a=0x03;
TRANSMIT_C2(a);
a=0x00;
TRANSMIT_C2(a);
a=0x00;
TRANSMIT_C2(a);

TRANSMIT_C2('B');      /////////////////////// PRINTING //////////////////////////////////////////
TRANSMIT_C2('I');
TRANSMIT_C2('N');
TRANSMIT_C2('O');


a=0x00;              ///////////////////////// END OF STRING /////////////////////////////////////
TRANSMIT_C2(a);

__delay32(3500000);

a=0x73;                //////////////////////// DISPLAY HEADING ///////////////////////////////////////
TRANSMIT_C2(a); 
a=0x04;                //////////////////////// HORZONTAL START //////////////////////////////////////
TRANSMIT_C2(a);
a=0x04;                /////////////////////// VERTICAL START ///////////////////////////////////////
TRANSMIT_C2(a);
a=0x02;
TRANSMIT_C2(a);
a=0x00;
TRANSMIT_C2(a);
a=0x00;
TRANSMIT_C2(a);

TRANSMIT_C2('H');      /////////////////////// PRINTING //////////////////////////////////////////
TRANSMIT_C2('E');
TRANSMIT_C2('A');
TRANSMIT_C2('D');
TRANSMIT_C2('I');
TRANSMIT_C2('N');
TRANSMIT_C2('G');

a=0x00;              ///////////////////////// END OF STRING /////////////////////////////////////
TRANSMIT_C2(a);

__delay32(3500000);

a=0x73;                //////////////////////// DISPLAY HEADING ///////////////////////////////////////
TRANSMIT_C2(a); 
a=0x05;                //////////////////////// HORZONTAL START //////////////////////////////////////
TRANSMIT_C2(a);
a=0x08;                /////////////////////// VERTICAL START ///////////////////////////////////////
TRANSMIT_C2(a);
a=0x02;
TRANSMIT_C2(a);
a=0x00;
TRANSMIT_C2(a);
a=0x00;
TRANSMIT_C2(a);

TRANSMIT_C2('P');      /////////////////////// PRINTING //////////////////////////////////////////
TRANSMIT_C2('I');
TRANSMIT_C2('T');
TRANSMIT_C2('C');
TRANSMIT_C2('H');


a=0x00;              ///////////////////////// END OF STRING /////////////////////////////////////
TRANSMIT_C2(a);


__delay32(350000);

a=0x73;                //////////////////////// DISPLAY HEADING ///////////////////////////////////////
TRANSMIT_C2(a); 
a=0x0C;                //////////////////////// HORZONTAL START //////////////////////////////////////
TRANSMIT_C2(a);
a=0x01;                /////////////////////// VERTICAL START ///////////////////////////////////////
TRANSMIT_C2(a);
a=0x03;
TRANSMIT_C2(a);
a=0x00;
TRANSMIT_C2(a);
a=0x00;
TRANSMIT_C2(a);

TRANSMIT_C2('I');      /////////////////////// PRINTING //////////////////////////////////////////
TRANSMIT_C2('R');
TRANSMIT_C2('S');
TRANSMIT_C2('A');
TRANSMIT_C2('M');



a=0x00;              ///////////////////////// END OF STRING /////////////////////////////////////
TRANSMIT_C2(a);

__delay32(3500000);

a=0x73;                //////////////////////// DISPLAY HEADING ///////////////////////////////////////
TRANSMIT_C2(a); 
a=0x11;                //////////////////////// HORZONTAL START //////////////////////////////////////
TRANSMIT_C2(a);
a=0x04;                /////////////////////// VERTICAL START ///////////////////////////////////////
TRANSMIT_C2(a);
a=0x02;
TRANSMIT_C2(a);
a=0x00;
TRANSMIT_C2(a);
a=0x00;
TRANSMIT_C2(a);

TRANSMIT_C2('H');      /////////////////////// PRINTING //////////////////////////////////////////
TRANSMIT_C2('E');
TRANSMIT_C2('A');
TRANSMIT_C2('D');
TRANSMIT_C2('I');
TRANSMIT_C2('N');
TRANSMIT_C2('G');
a=0x00;              ///////////////////////// END OF STRING /////////////////////////////////////
TRANSMIT_C2(a);


__delay32(3500000);

a=0x73;                //////////////////////// DISPLAY HEADING ///////////////////////////////////////
TRANSMIT_C2(a); 
a=0x12;                //////////////////////// HORZONTAL START //////////////////////////////////////
TRANSMIT_C2(a);
a=0x08;                /////////////////////// VERTICAL START ///////////////////////////////////////
TRANSMIT_C2(a);
a=0x02;
TRANSMIT_C2(a);
a=0x00;
TRANSMIT_C2(a);
a=0x00;
TRANSMIT_C2(a);

TRANSMIT_C2('P');      /////////////////////// PRINTING //////////////////////////////////////////
TRANSMIT_C2('I');
TRANSMIT_C2('T');
TRANSMIT_C2('C');
TRANSMIT_C2('H');

a=0x00;              ///////////////////////// END OF STRING /////////////////////////////////////
TRANSMIT_C2(a);
  
while(1)
 {

  HMC3500_BINO();
   y = sprintf(str, "%f",azz);
   y= sprintf(str3, "%f",pit);

      
             HMC3500();
 y = sprintf(str1, "%f",azz);
 y= sprintf(str2, "%f",pit);

display_black1();
__delay32(3500);
a=0x73;             ///////////////////////////////////// PRINT HEADING /////////////////////////////////////////
TRANSMIT_C2(a);
a=0x03;
TRANSMIT_C2(a);
a=0x04;
TRANSMIT_C2(a);
a=0x03;
TRANSMIT_C2(a);
a=0x00;
TRANSMIT_C2(a);
TRANSMIT_C2(a);

for(s=0;s<=4;s++)
{
TRANSMIT_C2(str[s]);
}

a=0x00;
TRANSMIT_C2(a);      ////////////////////////////// END OF STRING //////////////////////////////////

__delay32(750000);   

display_black2();   
__delay32(3500);
a=0x73;             ///////////////////////////////////// PRINT HEADING /////////////////////////////////////////
TRANSMIT_C2(a);
a=0x03;
TRANSMIT_C2(a);
a=0x07;
TRANSMIT_C2(a);
a=0x03;
TRANSMIT_C2(a);
a=0x00;
TRANSMIT_C2(a);
TRANSMIT_C2(a);

for(s=0;s<=4;s++)
{
TRANSMIT_C2(str3[s]);
}

a=0x00;
TRANSMIT_C2(a);      ////////////////////////////// END OF STRING //////////////////////////////////


j=0;

__delay32(750000); //0

displayr_black1();
__delay32(3500);
     

a=0x73;             ///////////////////////////////////// PRINT HEADING /////////////////////////////////////////
TRANSMIT_C2(a);
a=0x0B;
TRANSMIT_C2(a);
a=0x04;
TRANSMIT_C2(a);
a=0x03;
TRANSMIT_C2(a);
a=0x00;
TRANSMIT_C2(a);
TRANSMIT_C2(a);

for(s=0;s<=5;s++)
{
TRANSMIT_C2(str1[s]);
}

a=0x00;
TRANSMIT_C2(a);      ////////////////////////////// END OF STRING //////////////////////////////////
__delay32(3500000);
displayr_black2();
__delay32(3500);


a=0x73;             ///////////////////////////////////// PRINT HEADING /////////////////////////////////////////
TRANSMIT_C2(a);
a=0x0B;
TRANSMIT_C2(a);
a=0x07;
TRANSMIT_C2(a);
a=0x03;
TRANSMIT_C2(a);
a=0x00;
TRANSMIT_C2(a);
TRANSMIT_C2(a);

for(s=0;s<=5;s++)
{
TRANSMIT_C2(str2[s]);
}

a=0x00;
TRANSMIT_C2(a);      ////////////////////////////// END OF STRING //////////////////////////////////
j=0;

 __delay32(500000);
  back();

__delay32(500000);



          }


}

void displayr_black1()

{

__delay32(10); 

a=0x72;              ////////////////////////// DISPLAY WINDOW ////////////////////////////////////
TRANSMIT_C2(a);

a=0x00;             ///////////////////////// HORIZONTAL START //////////////////////////////////
TRANSMIT_C2(a);
a=0x85;
TRANSMIT_C2(a);
a=0x00;             ///////////////////////// VERTICAL START //////////////////////////////////
TRANSMIT_C2(a);
a=0x40;
TRANSMIT_C2(a);

a=0x00;            ///////////////////////// HORIZONTAL END //////////////////////////////////
TRANSMIT_C2(a);
a=0xCB;
TRANSMIT_C2(a);
a=0x00;            ///////////////////////// VERTICAL END //////////////////////////////////
TRANSMIT_C2(a);
a=0x4D;
TRANSMIT_C2(a);


a=0xFF;         ///////////// color
TRANSMIT_C2(a);
a=0xFF;
TRANSMIT_C2(a);
__delay32(10000); 

}

void displayr_black2()

{

__delay32(10); 

a=0x72;              ////////////////////////// DISPLAY WINDOW ////////////////////////////////////
TRANSMIT_C2(a);

a=0x00;             ///////////////////////// HORIZONTAL START //////////////////////////////////
TRANSMIT_C2(a);
a=0x85;
TRANSMIT_C2(a);
a=0x00;             ///////////////////////// VERTICAL START //////////////////////////////////
TRANSMIT_C2(a);
a=0x70;
TRANSMIT_C2(a);

a=0x00;            ///////////////////////// HORIZONTAL END //////////////////////////////////
TRANSMIT_C2(a);
a=0xCB;
TRANSMIT_C2(a);
a=0x00;            ///////////////////////// VERTICAL END //////////////////////////////////
TRANSMIT_C2(a);
a=0x7D;
TRANSMIT_C2(a);


a=0xFF;         ///////////// color
TRANSMIT_C2(a);
a=0xFF;
TRANSMIT_C2(a);
__delay32(10000); 

}


void display_black1()

{

a=0x72;              ////////////////////////// DISPLAY WINDOW ////////////////////////////////////
TRANSMIT_C2(a);

a=0x00;             ///////////////////////// HORIZONTAL START //////////////////////////////////
TRANSMIT_C2(a);
a=0x24;
TRANSMIT_C2(a);
a=0x00;             ///////////////////////// VERTICAL START //////////////////////////////////
TRANSMIT_C2(a);
a=0x40;
TRANSMIT_C2(a);

a=0x00;            ///////////////////////// HORIZONTAL END //////////////////////////////////
TRANSMIT_C2(a);
a=0x5F;
TRANSMIT_C2(a);
a=0x00;            ///////////////////////// VERTICAL END //////////////////////////////////
TRANSMIT_C2(a);
a=0x4D;
TRANSMIT_C2(a);


a=0xFF;         ///////////// color
TRANSMIT_C2(a);
a=0xFF;
TRANSMIT_C2(a);
__delay32(10); 
}

void display_black2()

{

a=0x72;              ////////////////////////// DISPLAY WINDOW ////////////////////////////////////
TRANSMIT_C2(a);

a=0x00;             ///////////////////////// HORIZONTAL START //////////////////////////////////
TRANSMIT_C2(a);
a=0x24;
TRANSMIT_C2(a);
a=0x00;             ///////////////////////// VERTICAL START //////////////////////////////////
TRANSMIT_C2(a);
a=0x70;
TRANSMIT_C2(a);

a=0x00;            ///////////////////////// HORIZONTAL END //////////////////////////////////
TRANSMIT_C2(a);
a=0x5F;
TRANSMIT_C2(a);
a=0x00;            ///////////////////////// VERTICAL END //////////////////////////////////
TRANSMIT_C2(a);
a=0x7D;
TRANSMIT_C2(a);


a=0xFF;         ///////////// color
TRANSMIT_C2(a);
a=0xFF;
TRANSMIT_C2(a);
__delay32(10); 
}



void manual()
{
                    __delay32(100000); 
                  disable_touch();
         
             if(q==1)
               {
            a=0x40;              ////////////////////////// DISPLAY WINDOW ////////////////////////////////////
            TRANSMIT_C2(a);

			a=0x6D;             ///////////////////////// HORIZONTAL START //////////////////////////////////
			TRANSMIT_C2(a);
			
			TRANSMIT_C2('2');
			
			
			TRANSMIT_C2('.');
			
			TRANSMIT_C2('G');
			                     
			TRANSMIT_C2('c');
			
			TRANSMIT_C2('i');
			a=0x00;
			TRANSMIT_C2(a);
			a=0x00;
			TRANSMIT_C2(a);
			a=0x00;
			TRANSMIT_C2(a);
			a=0x00;
			TRANSMIT_C2(a);
			a=0x00;
			TRANSMIT_C2(a);
			a=0x00;
			TRANSMIT_C2(a);
			a=0x00;
			TRANSMIT_C2(a);
			a=0x00;
			TRANSMIT_C2(a);
			a=0x00;
			TRANSMIT_C2(a);
             
              }
            

           
         


        
     __delay32(25000000);
   
    
  
         enable_touch();
         while(1)
          {
                  detect_region2();
                  read=0;
          }



}

void initial_pic()
{
          __delay32(10000000);


             a=0x40;              ////////////////////////// DISPLAY WINDOW ////////////////////////////////////
            TRANSMIT_C2(a);

			a=0x6D;             ///////////////////////// HORIZONTAL START //////////////////////////////////
			TRANSMIT_C2(a);
			
			TRANSMIT_C2('A');
			
			
			TRANSMIT_C2('.');
			
			TRANSMIT_C2('G');
			                     
			TRANSMIT_C2('c');
			
			TRANSMIT_C2('i');
			a=0x00;
			TRANSMIT_C2(a);
			a=0x00;
			TRANSMIT_C2(a);
			a=0x00;
			TRANSMIT_C2(a);
			a=0x00;
			TRANSMIT_C2(a);
			a=0x00;
			TRANSMIT_C2(a);
			a=0x00;
			TRANSMIT_C2(a);
			a=0x00;
			TRANSMIT_C2(a);
			a=0x00;
			TRANSMIT_C2(a);
			a=0x00;
			TRANSMIT_C2(a);

}


void back()
{

enable_touch();
__delay32(5000000);

a=0x6F;
TRANSMIT_C2(a);
a=0x04;
TRANSMIT_C2(a);


__delay32(1000000);

a=0x6F;
TRANSMIT_C2(a);
a=0x05;
TRANSMIT_C2(a);

__delay32(900000);
readx=read;

__delay32(900000);
//while(read==readx);

readx1=read;
__delay32(900000);
//while(read==readx1);

ready=read;
__delay32(900000);

if(readx>24 && readx<217)
{

     if(ready>180 && ready<236) 
			{ 
             
			     __delay32(10000000);
                 a=0x59;               //////////////////////// Making Display Horizontal //////////////////////////////
				TRANSMIT_C2(a);
				a=0x04;
				TRANSMIT_C2(a);
				a=0x03;
				TRANSMIT_C2(a);
                __delay32(5000000);
                disable_touch();
               __delay32(10000000);
               start();

                     
            }
__delay32(5000000);
disable_touch();

}        

read=0;

}
