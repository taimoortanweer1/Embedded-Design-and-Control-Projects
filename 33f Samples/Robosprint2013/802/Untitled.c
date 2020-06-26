#include<p33fj64mc802.h>
// fr			SWAP = 1
// br			SWAP = 1
// fl			SWAP = 0
// bl			SWAP = 0
// 34 counts per cm
#define FCY              39613000
#define BAUDRATE         9600		      
#define BRGVAL          ((FCY/BAUDRATE)/16)-1

void clk();
void config();
void pwm();
void delay();
void qei();
void timer20ms();
void ibtimer20ms();
void enableInterrupts(void);
void INIT_UART1();
void recv();

char m_data=0;
int quad_c=0,rpm_g=0,flag = 0,pos_cnt = 0,m_cnt = 0,d = 0,pos1=0,pos2=0;
float i_err_1=0,i_err_2=0,c_err_1=0,c_err_2=0,p_err_1=0,p_err_2=0,err=0,_pwm_1=0,_pwm_2=0,rpm_c=0,rpm_d=0;

void __attribute__((__interrupt__, no_auto_psv)) _T1Interrupt(void)
{

if(flag == 0)
{
	flag = 1;
	P1DC1 = P1TPER*2*(0.63);
    P1DC2 = P1DC1;
	POS1CNT = 30;
	return; 

}
//err = 0;

IFS0bits.T1IF = 0;
T1CONbits.TON = 0;
TMR1 = 0;

pos_cnt = pos_cnt + POS1CNT;

pos1 = POS1CNT;
err = (float)(m_cnt - pos1);
p_err_1 = (float)(m_cnt - pos1) * 0.001f;
c_err_1 = c_err_1 + err;
i_err_1 = c_err_1 * 0.0001f;

pos2 = POS2CNT;
err = (float)(m_cnt - pos2);
p_err_2 = (float)(m_cnt - pos2) * 0.001f;
c_err_2 = c_err_2 + err;
i_err_2 = c_err_2 * 0.0001f;

if(d == 0)
{
_pwm_1 = 0.60 + p_err_1 + i_err_1;
if(_pwm_1 < 0.60)
	_pwm_1 = 0.60;
else if(_pwm_1 > 0.80)
	_pwm_1 = 0.80;

_pwm_2 = 0.60 + p_err_2 + i_err_2;
if(_pwm_2 < 0.60)
	_pwm_2 = 0.60;
else if(_pwm_2 > 0.80)
	_pwm_2 = 0.80;
}

else if(d == 1)
{
_pwm_1 = 0.57 - p_err_1 - i_err_1;
if(_pwm_1 < 0.30)
	_pwm_1 = 0.30;
else if(_pwm_1 > 0.57)
	_pwm_1 = 0.57;

_pwm_2 = 0.57 - p_err_2 - i_err_2;
if(_pwm_2 < 0.30)
	_pwm_2 = 0.30;
else if(_pwm_2 > 0.57)
	_pwm_2 = 0.57;
}
//0.6235

/*
if(pos_cnt == (34 * 250))
{
	_pwm = 0.60;
	m_cnt = 0;
}
*/
if(m_cnt == 0)
{
	_pwm_1 = 0.60;
	_pwm_2 = 0.60;
}

P1DC1 = P1TPER*2*(_pwm_1);
P1DC2 = P1TPER*2*(_pwm_2);
POS1CNT = 0;
POS2CNT = 0;
T1CONbits.TON = 1;

}

int main(void)
{
	clk();
	config();
	pwm();
	//m_cnt = 30;
	//__delay32(5000);
	enableInterrupts();
    ibtimer20ms();
    //T1CONbits.TON = 1; 
	qei();
	INIT_UART1();
//	QEI1CONbits.SWPAB=1;
//	while(1);
	recv();

	while(1);

//	while(1);	
//	QEI1CONbits.SWPAB=1;	
/*	
	P1DC1 = P1TPER*2*(0.20);
    P1DC2 = P1DC1;
while(1);
	delay();
	delay();
	delay();
	while(1)
	{
		l = QEI1CONbits.UPDN;
		if(l == 1)
		{
			P1DC1 = P1TPER*2*(0.64);
    		P1DC2 = P1DC1;
			while(1);
		}
		if(l == 0)
		{
			P1DC1 = P1TPER*2*(0.60);
    		P1DC2 = P1DC1;
	*****		while(1);
		}
	}
*/


	return 0;
}


//////////////////////////////////////// CLK ///////////////////////
void clk()
{
	CLKDIVbits.PLLPRE=0;
	CLKDIVbits.PLLPOST=0;
	PLLFBD=41;
	while(OSCCONbits.LOCK!=1);
}

/////////////////////////////////////// CONFIGURATION ////////////////
void config()
{
    AD1PCFGL = 0x01FF;
}

/////////////////////////////////////// PWM ////////////////
void pwm()
{
    TRISBbits.TRISB13 = 0;
    TRISBbits.TRISB15 = 0;
    P1TCON = 0x0000;
    
    P1TCONbits.PTCKPS = 2;//postscaler 16
    P1TPER = 5580;//430Hz
    
    PWM1CON1bits.PMOD1 = 1;
    PWM1CON1bits.PMOD2 = 1;
    PWM1CON1bits.PEN1L = 1;
    PWM1CON1bits.PEN2L = 1;

    P1OVDCONbits.POVD1L = 1;
    P1OVDCONbits.POVD2L = 1;
	
    P1DC1 = P1TPER*2*(0.60);
    P1DC2 = P1DC1;
    P1TMR = 0;
    P1TCONbits.PTEN = 1;
	delay();
	delay();

}

/////////////////////////////////////// delay ////////////////
void delay()
{
int a,b,c;
for(a=0;a<33;a++)
	for(b=0;b<800;b++)
		for(c=0;c<800;c++);
}

/////////////////////////////////////// QEI ////////////////
void qei()
{
	// RB6 and RB7	//lf		lb
	//---------------------  QEI 1 --------------------//
	// I/O
	RPINR14bits.QEA1R=6;			
	RPINR14bits.QEB1R=7;					
	TRISBbits.TRISB6=1;
	TRISBbits.TRISB7=1;
	// register config
	MAX1CNT=65535;
	POS1CNT=100;
	QEI1CON= 0X0000;
	QEI1CONbits.PCDOUT=1;
	QEI1CONbits.SWPAB=1;		//lf = 1;	rf = 1;		lb = 1;		rb = 1;
	QEI1CONbits.QEIM=7;

	// RB8 and RB9	//rf		rb
	//---------------------  QEI 2 --------------------//
	// I/O
	RPINR16bits.QEA2R=8;			
	RPINR16bits.QEB2R=9;					
	TRISBbits.TRISB8=1;
	TRISBbits.TRISB9=1;
	// register config
	MAX2CNT=65535;
	POS2CNT=100;
	QEI2CON= 0X0000;
	QEI2CONbits.PCDOUT=1;
	QEI2CONbits.SWPAB=1;
	QEI2CONbits.QEIM=7;
	
}

/////////////////////////////////////// timer20ms() ////////////////
void timer20ms()
{


T3CONbits.TON = 0; 
T3CONbits.TCS = 0; 
T3CONbits.TGATE = 0; 
T3CONbits.TCKPS = 0b10; // prescaler=64
TMR3 = 0x00; 
PR3 = 31250;
 
while(1)
{
T3CONbits.TON = 1;
while(IFS0bits.T3IF == 0); 
T3CONbits.TON = 0;
IFS0bits.T3IF = 0;
TMR3 = 0x00;
//vp();


}

}

/////////////////////////////////////// ibtimer20ms() ////////////////
void ibtimer20ms()
{

T1CONbits.TON = 0; 
T1CONbits.TCS = 0; 
T1CONbits.TGATE = 0; 
T1CONbits.TCKPS = 0b10; 
TMR1 = 0x00; 
PR1 = 12500/2;  
IPC0bits.T1IP = 0x01; 
IFS0bits.T1IF = 0; 
IEC0bits.T1IE = 1; 


}

/////////////////////////////////////// enableInterrupts ////////////////
void enableInterrupts(void)
{
SRbits.IPL = 0;
INTCON1bits.NSTDIS = 0;
}

////////*************** INIT_UART ******////////
void INIT_UART1(void)
	{
		RPINR18bits.U1RXR = 2;		// Make Pin RP2 U1RX
		TRISBbits.TRISB2 = 1;	// MAKE PIN B2 AS INPUT
		AD1PCFGL = 0xFFFF;		// Make analog pins digital 
		U1BRG  = BRGVAL;
		U1MODE = 0x0000; 
		U1STA  = 0x0040; /* Reset status register and enable TX & RX*/
		U1MODEbits.UARTEN = 1;
	
	}

/////////////////////////////////////// recv
void recv()
{
//
int value;

while(1)
{
int flag = 0;
/* check for receive errors */

if(U1STAbits.FERR == 1)
{
continue;
}
/* must clear the overrun error to keep uart receiving */

if(U1STAbits.OERR == 1)
{
U1STAbits.OERR = 0;
continue;
}

if(U1STAbits.URXDA == 1)
{

//QEI1CONbits.SWPAB=0; //fr = *yes SWAP* = br 			fl= *no SWAP* = bl
m_data = U1RXREG;
value = m_data & 0b11100000;
if(value == 0b10000000 || value == 0b11100000)	// slave address
{
	value = m_data & 0b00010000;
	if(value == 0b00000000)// forward direction
		{
			QEI1CONbits.SWPAB=0;
			QEI2CONbits.SWPAB=0;
			d = 0;
			T1CONbits.TON = 0; 
			value = m_data & 0b00001111;
			m_cnt = value * 5;
			T1CONbits.TON = 1;
//			i_err_1 = 0;i_err_2 = 0;
//			p_err_1 = 0;p_err_2 = 0;
//			m_data = 0;

		}
	
	if(value == 0b00010000)// backward direction
		{
			QEI1CONbits.SWPAB=1;
			QEI2CONbits.SWPAB=1;
			d = 1;
			if(flag == 0)
			{
					flag = 1;
					pos_cnt = 0;
			}
			T1CONbits.TON = 0; 
			value = m_data & 0b00001111;
			m_cnt = value * 5;
			T1CONbits.TON = 1;
//			i_err_1 = 0;i_err_2 = 0;
//			p_err_1 = 0;p_err_2 = 0;
//			m_data = 0;
		}
	
}

else if(value == 0b11000000)	// slave address
{
	pos_cnt = 0;
}

}//end of U1STAbits.URXDA

}// end of while		
	

}
