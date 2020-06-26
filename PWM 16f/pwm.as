opt subtitle "HI-TECH Software Omniscient Code Generator (Lite mode) build 10920"

opt pagewidth 120

	opt lm

	processor	16F1946
clrc	macro
	bcf	3,0
	endm
clrz	macro
	bcf	3,2
	endm
setc	macro
	bsf	3,0
	endm
setz	macro
	bsf	3,2
	endm
skipc	macro
	btfss	3,0
	endm
skipz	macro
	btfss	3,2
	endm
skipnc	macro
	btfsc	3,0
	endm
skipnz	macro
	btfsc	3,2
	endm
indf	equ	0
indf0	equ	0
indf1	equ	1
pc	equ	2
pcl	equ	2
status	equ	3
fsr0l	equ	4
fsr0h	equ	5
fsr1l	equ	6
fsr1h	equ	7
bsr	equ	8
wreg	equ	9
intcon	equ	11
c	equ	1
z	equ	0
pclath	equ	10
	FNROOT	_main
	FNCALL	intlevel1,_isr
	global	intlevel1
	FNROOT	intlevel1
	global	_count
	global	_flag
	global	_TMR1
psect	intentry,class=CODE,delta=2
global __pintentry
__pintentry:
_TMR1	set	22
	global	_INTCONbits
_INTCONbits	set	11
	global	_PIR1bits
_PIR1bits	set	17
	global	_PIR2bits
_PIR2bits	set	18
	global	_T1CON
_T1CON	set	24
	global	_T1CONbits
_T1CONbits	set	24
	global	_CARRY
_CARRY	set	24
	global	_GIE
_GIE	set	95
	global	_PIE2bits
_PIE2bits	set	146
	global	_TRISCbits
_TRISCbits	set	142
	global	_APFCONbits
_APFCONbits	set	285
	global	_EEADR
_EEADR	set	401
	global	_EECON1
_EECON1	set	405
	global	_EECON2
_EECON2	set	406
	global	_EEDATA
_EEDATA	set	403
	global	_RD
_RD	set	3240
	global	_WR
_WR	set	3241
	global	_WREN
_WREN	set	3242
	global	_CCP2CONbits
_CCP2CONbits	set	666
	global	_CCPR1L
_CCPR1L	set	657
	file	"pwm.as"
	line	#
psect cinit,class=CODE,delta=2
global start_initialization
start_initialization:

psect	bssCOMMON,class=COMMON,space=1
global __pbssCOMMON
__pbssCOMMON:
_count:
       ds      2

_flag:
       ds      1

; Clear objects allocated to COMMON
psect cinit,class=CODE,delta=2
	global __pbssCOMMON
	clrf	((__pbssCOMMON)+0)&07Fh
	clrf	((__pbssCOMMON)+1)&07Fh
	clrf	((__pbssCOMMON)+2)&07Fh
psect cinit,class=CODE,delta=2
global end_of_initialization

;End of C runtime variable initialization code

end_of_initialization:
movlb 0
ljmp _main	;jump to C main() function
psect	cstackCOMMON,class=COMMON,space=1
global __pcstackCOMMON
__pcstackCOMMON:
	global	?_isr
?_isr:	; 0 bytes @ 0x0
	global	??_isr
??_isr:	; 0 bytes @ 0x0
	global	?_main
?_main:	; 0 bytes @ 0x0
	ds	3
	global	??_main
??_main:	; 0 bytes @ 0x3
;;Data sizes: Strings 0, constant 0, data 0, bss 3, persistent 0 stack 0
;;Auto spaces:   Size  Autos    Used
;; COMMON          14      3       6
;; BANK0           80      0       0
;; BANK1           80      0       0
;; BANK2           80      0       0
;; BANK3           80      0       0
;; BANK4           80      0       0
;; BANK5           80      0       0
;; BANK6           16      0       0

;;
;; Pointer list with targets:



;;
;; Critical Paths under _main in COMMON
;;
;;   None.
;;
;; Critical Paths under _isr in COMMON
;;
;;   None.
;;
;; Critical Paths under _main in BANK0
;;
;;   None.
;;
;; Critical Paths under _isr in BANK0
;;
;;   None.
;;
;; Critical Paths under _main in BANK1
;;
;;   None.
;;
;; Critical Paths under _isr in BANK1
;;
;;   None.
;;
;; Critical Paths under _main in BANK2
;;
;;   None.
;;
;; Critical Paths under _isr in BANK2
;;
;;   None.
;;
;; Critical Paths under _main in BANK3
;;
;;   None.
;;
;; Critical Paths under _isr in BANK3
;;
;;   None.
;;
;; Critical Paths under _main in BANK4
;;
;;   None.
;;
;; Critical Paths under _isr in BANK4
;;
;;   None.
;;
;; Critical Paths under _main in BANK5
;;
;;   None.
;;
;; Critical Paths under _isr in BANK5
;;
;;   None.
;;
;; Critical Paths under _main in BANK6
;;
;;   None.
;;
;; Critical Paths under _isr in BANK6
;;
;;   None.

;;
;;Main: autosize = 0, tempsize = 0, incstack = 0, save=0
;;

;;
;;Call Graph Tables:
;;
;; ---------------------------------------------------------------------------------
;; (Depth) Function   	        Calls       Base Space   Used Autos Params    Refs
;; ---------------------------------------------------------------------------------
;; (0) _main                                                 0     0      0       0
;; ---------------------------------------------------------------------------------
;; Estimated maximum stack depth 0
;; ---------------------------------------------------------------------------------
;; (Depth) Function   	        Calls       Base Space   Used Autos Params    Refs
;; ---------------------------------------------------------------------------------
;; (1) _isr                                                  3     3      0       0
;;                                              0 COMMON     3     3      0
;; ---------------------------------------------------------------------------------
;; Estimated maximum stack depth 1
;; ---------------------------------------------------------------------------------

;; Call Graph Graphs:

;; _main (ROOT)
;;
;; _isr (ROOT)
;;

;; Address spaces:

;;Name               Size   Autos  Total    Cost      Usage
;;BIGRAM             1F0      0       0       0        0.0%
;;EEDATA             100      0       0       0        0.0%
;;NULL                 0      0       0       0        0.0%
;;CODE                 0      0       0       0        0.0%
;;BITCOMMON            E      0       0       1        0.0%
;;BITSFR0              0      0       0       1        0.0%
;;SFR0                 0      0       0       1        0.0%
;;COMMON               E      3       6       2       42.9%
;;BITSFR1              0      0       0       2        0.0%
;;SFR1                 0      0       0       2        0.0%
;;BITSFR2              0      0       0       3        0.0%
;;SFR2                 0      0       0       3        0.0%
;;STACK                0      0       0       3        0.0%
;;BITSFR3              0      0       0       4        0.0%
;;SFR3                 0      0       0       4        0.0%
;;ABS                  0      0       6       4        0.0%
;;BITBANK0            50      0       0       5        0.0%
;;BITSFR4              0      0       0       5        0.0%
;;SFR4                 0      0       0       5        0.0%
;;BANK0               50      0       0       6        0.0%
;;BITSFR5              0      0       0       6        0.0%
;;SFR5                 0      0       0       6        0.0%
;;BITBANK1            50      0       0       7        0.0%
;;BITSFR6              0      0       0       7        0.0%
;;SFR6                 0      0       0       7        0.0%
;;BANK1               50      0       0       8        0.0%
;;BITSFR7              0      0       0       8        0.0%
;;SFR7                 0      0       0       8        0.0%
;;BITBANK2            50      0       0       9        0.0%
;;BITSFR8              0      0       0       9        0.0%
;;SFR8                 0      0       0       9        0.0%
;;BANK2               50      0       0      10        0.0%
;;BITSFR9              0      0       0      10        0.0%
;;SFR9                 0      0       0      10        0.0%
;;BITBANK3            50      0       0      11        0.0%
;;BITSFR10             0      0       0      11        0.0%
;;SFR10                0      0       0      11        0.0%
;;BANK3               50      0       0      12        0.0%
;;BITSFR11             0      0       0      12        0.0%
;;SFR11                0      0       0      12        0.0%
;;BITBANK4            50      0       0      13        0.0%
;;BITSFR12             0      0       0      13        0.0%
;;SFR12                0      0       0      13        0.0%
;;BANK4               50      0       0      14        0.0%
;;BITSFR13             0      0       0      14        0.0%
;;SFR13                0      0       0      14        0.0%
;;BITBANK5            50      0       0      15        0.0%
;;BITSFR14             0      0       0      15        0.0%
;;SFR14                0      0       0      15        0.0%
;;BANK5               50      0       0      16        0.0%
;;BITSFR15             0      0       0      16        0.0%
;;SFR15                0      0       0      16        0.0%
;;BITBANK6            10      0       0      17        0.0%
;;BITSFR16             0      0       0      17        0.0%
;;SFR16                0      0       0      17        0.0%
;;BANK6               10      0       0      18        0.0%
;;BITSFR17             0      0       0      18        0.0%
;;SFR17                0      0       0      18        0.0%
;;BITSFR18             0      0       0      19        0.0%
;;SFR18                0      0       0      19        0.0%
;;DATA                 0      0       6      19        0.0%
;;BITSFR19             0      0       0      20        0.0%
;;SFR19                0      0       0      20        0.0%
;;BITSFR20             0      0       0      21        0.0%
;;SFR20                0      0       0      21        0.0%
;;BITSFR21             0      0       0      22        0.0%
;;SFR21                0      0       0      22        0.0%
;;BITSFR22             0      0       0      23        0.0%
;;SFR22                0      0       0      23        0.0%
;;BITSFR23             0      0       0      24        0.0%
;;SFR23                0      0       0      24        0.0%
;;BITSFR24             0      0       0      25        0.0%
;;SFR24                0      0       0      25        0.0%
;;BITSFR25             0      0       0      26        0.0%
;;SFR25                0      0       0      26        0.0%
;;BITSFR26             0      0       0      27        0.0%
;;SFR26                0      0       0      27        0.0%
;;BITSFR27             0      0       0      28        0.0%
;;SFR27                0      0       0      28        0.0%
;;BITSFR28             0      0       0      29        0.0%
;;SFR28                0      0       0      29        0.0%
;;BITSFR29             0      0       0      30        0.0%
;;SFR29                0      0       0      30        0.0%
;;BITSFR30             0      0       0      31        0.0%
;;SFR30                0      0       0      31        0.0%
;;BITSFR31             0      0       0      32        0.0%
;;SFR31                0      0       0      32        0.0%

	global	_main
psect	maintext,global,class=CODE,delta=2
global __pmaintext
__pmaintext:

;; *************** function _main *****************
;; Defined at:
;;		line 29 in file "C:\Program Files (x86)\Microchip\MPLAB C30\support\dsPIC33F\gld\pwm.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 17F/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       0       0       0       0       0       0       0
;;      Locals:         0       0       0       0       0       0       0       0
;;      Temps:          0       0       0       0       0       0       0       0
;;      Totals:         0       0       0       0       0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels required when called:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		Startup code after reset
;; This function uses a non-reentrant model
;;
psect	maintext
	file	"C:\Program Files (x86)\Microchip\MPLAB C30\support\dsPIC33F\gld\pwm.c"
	line	29
	global	__size_of_main
	__size_of_main	equ	__end_of_main-_main
	
_main:	
	opt	stack 15
; Regs used in _main: [wreg+status,2+status,0]
	line	49
	
l5664:	
;pwm.c: 49: TRISCbits.TRISC1 = 1;
	movlb 1	; select bank1
	bsf	(142)^080h,1	;volatile
	line	50
;pwm.c: 50: APFCONbits.CCP2SEL=0;
	movlb 2	; select bank2
	bcf	(285)^0100h,2	;volatile
	line	51
	
l5666:	
;pwm.c: 51: CCP2CONbits.CCP2M = 0b00000101;
	movlb 5	; select bank5
	movf	(666)^0280h,w	;volatile
	andlw	not (((1<<4)-1)<<0)
	iorlw	(05h & ((1<<4)-1))<<0
	movwf	(666)^0280h	;volatile
	line	52
	
l5668:	
;pwm.c: 52: PIR1bits.TMR2IF = 0;
	movlb 0	; select bank0
	bcf	(17),1	;volatile
	line	53
	
l5670:	
;pwm.c: 53: PIE2bits.CCP2IE = 1;
	movlb 1	; select bank1
	bsf	(146)^080h,0	;volatile
	line	54
	
l5672:	
;pwm.c: 54: INTCONbits.GIE = 1;
	bsf	(11),7	;volatile
	line	55
	
l5674:	
;pwm.c: 55: INTCONbits.PEIE = 1;
	bsf	(11),6	;volatile
	line	57
	
l5676:	
;pwm.c: 57: T1CON = 0x00;
	movlb 0	; select bank0
	clrf	(24)	;volatile
	goto	l2753
	line	58
;pwm.c: 58: while(1);
	
l2752:	
	
l2753:	
	goto	l2753
	
l2754:	
	line	59
	
l2755:	
	global	start
	ljmp	start
	opt stack 0
GLOBAL	__end_of_main
	__end_of_main:
;; =============== function _main ends ============

	signat	_main,88
	global	_isr
psect	intentry

;; *************** function _isr *****************
;; Defined at:
;;		line 7 in file "C:\Program Files (x86)\Microchip\MPLAB C30\support\dsPIC33F\gld\pwm.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       0       0       0       0       0       0       0
;;      Locals:         0       0       0       0       0       0       0       0
;;      Temps:          3       0       0       0       0       0       0       0
;;      Totals:         3       0       0       0       0       0       0       0
;;Total ram usage:        3 bytes
;; Hardware stack levels used:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		Interrupt level 1
;; This function uses a non-reentrant model
;;
psect	intentry
	file	"C:\Program Files (x86)\Microchip\MPLAB C30\support\dsPIC33F\gld\pwm.c"
	line	7
	global	__size_of_isr
	__size_of_isr	equ	__end_of_isr-_isr
	
_isr:	
	opt	stack 15
; Regs used in _isr: [wreg+status,2+status,0]
psect	intentry
	pagesel	$
	movlb 0	; select bank0
	movf	btemp+1,w
	movwf	(??_isr+2)
	line	8
	
i1l5642:	
;pwm.c: 8: if(flag == 0)
	movf	(_flag),f
	skipz
	goto	u1_21
	goto	u1_20
u1_21:
	goto	i1l5654
u1_20:
	line	10
	
i1l5644:	
;pwm.c: 9: {
;pwm.c: 10: T1CONbits.TMR1ON = 1;
	bsf	(24),0	;volatile
	line	11
	
i1l5646:	
;pwm.c: 11: TMR1 = 0;
	clrf	(22)	;volatile
	clrf	(22+1)	;volatile
	line	13
	
i1l5648:	
;pwm.c: 13: PIR2bits.CCP2IF = 0;
	bcf	(18),0	;volatile
	line	14
	
i1l5650:	
;pwm.c: 14: count = CCPR1L;
	movlb 5	; select bank5
	movf	(657)^0280h,w	;volatile
	movwf	(??_isr+0)+0
	clrf	(??_isr+0)+0+1
	movf	0+(??_isr+0)+0,w
	movwf	(_count)
	movf	1+(??_isr+0)+0,w
	movwf	(_count+1)
	line	15
	
i1l5652:	
;pwm.c: 15: PIR2bits.CCP2IF = 0;
	movlb 0	; select bank0
	bcf	(18),0	;volatile
	goto	i1l5654
	line	16
	
i1l2747:	
	line	17
	
i1l5654:	
;pwm.c: 16: }
;pwm.c: 17: if(flag == 1)
	movf	(_flag),w
	xorlw	01h&0ffh
	skipz
	goto	u2_21
	goto	u2_20
u2_21:
	goto	i1l5662
u2_20:
	line	19
	
i1l5656:	
;pwm.c: 18: {
;pwm.c: 19: count = TMR1;
	movf	(22+1),w	;volatile
	clrf	(_count+1)	;volatile
	addwf	(_count+1)	;volatile
	movf	(22),w	;volatile
	clrf	(_count)	;volatile
	addwf	(_count)	;volatile

	line	20
	
i1l5658:	
;pwm.c: 20: flag = 0;
	clrf	(_flag)
	line	21
	
i1l5660:	
;pwm.c: 21: PIR2bits.CCP2IF = 0;
	bcf	(18),0	;volatile
	goto	i1l5662
	line	22
	
i1l2748:	
	line	23
	
i1l5662:	
;pwm.c: 22: }
;pwm.c: 23: flag = !flag;
	movf	(_flag),w
	xorlw	0&0ffh
	movlw	0
	skipnz
	movlw	1
	movwf	(??_isr+0)+0
	movf	(??_isr+0)+0,w
	movwf	(_flag)
	line	25
	
i1l2749:	
	movf	(??_isr+2),w
	movwf	btemp+1
	retfie
	opt stack 0
GLOBAL	__end_of_isr
	__end_of_isr:
;; =============== function _isr ends ============

	signat	_isr,88
psect	intentry
	global	btemp
	btemp set 07Eh

	DABS	1,126,2	;btemp
	global	wtemp0
	wtemp0 set btemp
	end
