#define FCY				39613000

#define BAUDRATE1		9600	      
#define BRGVAL1			((FCY/BAUDRATE1)/16)-1

#define BAUDRATE2		9600
#define BRGVAL2			((FCY/BAUDRATE2)/16)-1

void TRANSMIT_C1(unsigned char value);
void TRANSMIT_C2(unsigned char value);
unsigned char GET_C1(void);
unsigned char GET_C2(void);
void UART_01(void);
void UART_02(void);
