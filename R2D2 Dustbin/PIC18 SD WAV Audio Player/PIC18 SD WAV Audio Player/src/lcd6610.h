#ifndef _LCD6610
#define _LCD6610

#define	LCD_RESET		LATAbits.LATA0
#define	LCD_DATA		LATAbits.LATA1
#define LCD_CLK			LATAbits.LATA2
#define	LCD_CE			LATAbits.LATA3
#define	LCD_Backlight	LATAbits.LATA5
#define LCD_TRIS()		TRISA &= 0b11010000

#define	Backlight_On()	LCD_Backlight = 1
#define	Backlight_Off()	LCD_Backlight = 0

#define BIT7 0b10000000
#define BIT6 0b01000000
#define BIT5 0b00100000
#define BIT4 0b00010000
#define BIT3 0b00001000
#define BIT2 0b00000100
#define BIT1 0b00000010
#define BIT0 0b00000001

#define LCD_TCMD	0
#define	LCD_TDATA	1

#define LCD_NOP          0x00  //no operation
#define SWRESET      0x01  //software reset
#define BSTROFF      0x02  //booster voltage off
#define BSTRON       0x03  //booster voltage on
#define SLEEP_IN     0x10
#define SLEEP_OUT    0x11
#define INVOFF       0x20  //display inversion off
#define INVON        0x21  //display inversion on
#define DISPOFF      0x28  //display off
#define DISPON       0x29  //display on
#define DALO         0x22  //all pixel off
#define SETCON       0x25  //set contrast
#define CASET        0x2A  //column address set; X address
#define PASET        0x2B  //page address set; Y address
#define RAMWR        0x2C  //memory write
#define RGBSET       0x2D  //colour set

#define MADCTL       0x36  //memory data access control
#define COLMOD       0x3A  //interface pixel format

#define  COLOR_8_BIT    0x02
#define  COLOR_12_BIT   0x03
#define  COLOR_16_BIT   0x05

//#define CMD    0
//#define DATA   1

#define LCD_BLUE        0x03
#define LCD_YELLOW      0xFC
#define LCD_RED         0XE0
#define LCD_GREEN       0X1C
#define LCD_BLACK       0X00
#define LCD_WHITE       0XFF
#define LCD_BRIGHTGREEN 0X3D
#define LCD_DARKGREEN   0X14
#define LCD_DARKRED     0XA0
#define LCD_DARKBLUE    0X02
#define LCD_BRIGHTBLUE  0X1F
#define LCD_ORANGE      0XF8

typedef unsigned char	BYTE;

unsigned char lcd_str_width(const unsigned char *c);
void lcd_send(BYTE a, BYTE cmd);
void lcd_init(void);
void lcd_putch(BYTE c, BYTE fColor, BYTE bColor);
void lcd_text(const char *s, BYTE x, BYTE y, BYTE fColor, BYTE bColor);
void lcd_text2( char *s, BYTE x, BYTE y, BYTE fColor, BYTE bColor);


void color_fill(BYTE x1, BYTE x2, BYTE y1, BYTE y2, BYTE color);

#define lcd_clear()	color_fill(0, 131, 0, 131, LCD_GREEN)

#endif	// _LCD6610	
