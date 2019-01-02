#ifndef	_HTC_H_
#warning Header file pic16f1937.h included directly. Use #include <htc.h> instead.
#endif

/* header file for the MICROCHIP PIC microcontroller
 *  16F1937
 */


#ifndef __PIC16F1937_H
#define __PIC16F1937_H

//
// Configuration mask definitions
//


// Config Register: CONFIG1
#define CONFIG1              0x8007
// Oscillator Selection
// ECH, External Clock, High Power Mode (4-32 MHz): device clock supplied to CLKIN pin
#define FOSC_ECH             0xFFFF
// ECM, External Clock, Medium Power Mode (0.5-4 MHz): device clock supplied to CLKIN pin
#define FOSC_ECM             0xFFFE
// ECL, External Clock, Low Power Mode (0-0.5 MHz): device clock supplied to CLKIN pin
#define FOSC_ECL             0xFFFD
// INTOSC oscillator: I/O function on CLKIN pin
#define FOSC_INTOSC          0xFFFC
// EXTRC oscillator: External RC circuit connected to CLKIN pin
#define FOSC_EXTRC           0xFFFB
// HS Oscillator, High-speed crystal/resonator connected between OSC1 and OSC2 pins
#define FOSC_HS              0xFFFA
// XT Oscillator, Crystal/resonator connected between OSC1 and OSC2 pins
#define FOSC_XT              0xFFF9
// LP Oscillator, Low-power crystal connected between OSC1 and OSC2 pins
#define FOSC_LP              0xFFF8
// Watchdog Timer Enable
// WDT enabled
#define WDTE_ON              0xFFFF
// WDT enabled while running and disabled in Sleep
#define WDTE_NSLEEP          0xFFF7
// WDT controlled by the SWDTEN bit in the WDTCON register
#define WDTE_SWDTEN          0xFFEF
// WDT disabled
#define WDTE_OFF             0xFFE7
// Power-up Timer Enable
// PWRT disabled
#define PWRTE_OFF            0xFFFF
// PWRT enabled
#define PWRTE_ON             0xFFDF
// MCLR Pin Function Select
// MCLR/VPP pin function is MCLR
#define MCLRE_ON             0xFFFF
// MCLR/VPP pin function is digital input
#define MCLRE_OFF            0xFFBF
// Flash Program Memory Code Protection
// Program memory code protection is disabled
#define CP_OFF               0xFFFF
// Program memory code protection is enabled
#define CP_ON                0xFF7F
// Data Memory Code Protection
// Data memory code protection is disabled
#define CPD_OFF              0xFFFF
// Data memory code protection is enabled
#define CPD_ON               0xFEFF
// Brown-out Reset Enable
// Brown-out Reset enabled
#define BOREN_ON             0xFFFF
// Brown-out Reset enabled while running and disabled in Sleep
#define BOREN_NSLEEP         0xFDFF
// Brown-out Reset controlled by the SBOREN bit in the BORCON register
#define BOREN_SBODEN         0xFBFF
// Brown-out Reset disabled
#define BOREN_OFF            0xF9FF
// Clock Out Enable
// CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin
#define CLKOUTEN_OFF         0xFFFF
// CLKOUT function is enabled on the CLKOUT pin
#define CLKOUTEN_ON          0xF7FF
// Internal/External Switchover
// Internal/External Switchover mode is enabled
#define IESO_ON              0xFFFF
// Internal/External Switchover mode is disabled
#define IESO_OFF             0xEFFF
// Fail-Safe Clock Monitor Enable
// Fail-Safe Clock Monitor is enabled
#define FCMEN_ON             0xFFFF
// Fail-Safe Clock Monitor is disabled
#define FCMEN_OFF            0xDFFF


// Config Register: CONFIG2
#define CONFIG2              0x8008
// Flash Memory Self-Write Protection
// Write protection off
#define WRT_OFF              0xFFFF
// 000h to 1FFh write protected, 200h to 1FFFh may be modified by EECON control
#define WRT_BOOT             0xFFFE
// 000h to FFFh write protected, 1000h to 1FFFh may be modified by EECON control
#define WRT_HALF             0xFFFD
// 000h to 1FFFh write protected, no addresses may be modified by EECON control
#define WRT_ALL              0xFFFC
// Voltage Regulator Capacitor Enable
// All VCAP pin functionality is disabled
#define VCAPEN_OFF           0xFFFF
// VCAP functionality is enabled on RA6
#define VCAPEN_RA6           0xFFEF
// VCAP functionality is enabled on RA5
#define VCAPEN_RA5           0xFFDF
// VCAP functionality is enabled on RA0
#define VCAPEN_RA0           0xFFCF
// PLL Enable
// 4x PLL enabled
#define PLLEN_ON             0xFFFF
// 4x PLL disabled
#define PLLEN_OFF            0xFEFF
// Stack Overflow/Underflow Reset Enable
// Stack Overflow or Underflow will cause a Reset
#define STVREN_ON            0xFFFF
// Stack Overflow or Underflow will not cause a Reset
#define STVREN_OFF           0xFDFF
// Brown-out Reset Voltage Selection
// Brown-out Reset Voltage (VBOR) set to 1.9 V
#define BORV_19              0xFFFF
// Brown-out Reset Voltage (VBOR) set to 2.5 V
#define BORV_25              0xFBFF
// Low-Voltage Programming Enable
// Low-voltage programming enabled
#define LVP_ON               0xFFFF
// High-voltage on MCLR/VPP must be used for programming
#define LVP_OFF              0xDFFF


//
// Special function register definitions
//


// Register: INDF0
volatile unsigned char           INDF0               @ 0x000;
// bit and bitfield definitions

// Register: INDF1
volatile unsigned char           INDF1               @ 0x001;
// bit and bitfield definitions

// Register: PCL
volatile unsigned char           PCL                 @ 0x002;
// bit and bitfield definitions

// Register: STATUS
volatile unsigned char           STATUS              @ 0x003;
// bit and bitfield definitions
volatile bit CARRY               @ ((unsigned)&STATUS*8)+0;
volatile bit DC                  @ ((unsigned)&STATUS*8)+1;
volatile bit ZERO                @ ((unsigned)&STATUS*8)+2;
volatile bit nPD                 @ ((unsigned)&STATUS*8)+3;
volatile bit nTO                 @ ((unsigned)&STATUS*8)+4;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	C                   : 1;
        unsigned	DC                  : 1;
        unsigned	Z                   : 1;
        unsigned	nPD                 : 1;
        unsigned	nTO                 : 1;
        unsigned	                    : 2;
        unsigned	: 1;
    };
} STATUSbits @ 0x003;
#endif
// bit and bitfield definitions

// Register: FSR0L
volatile unsigned char           FSR0L               @ 0x004;
// bit and bitfield definitions

// Register: FSR0H
volatile unsigned char           FSR0H               @ 0x005;
// bit and bitfield definitions

// Register: FSR0
volatile unsigned int            FSR0                @ 0x004;
// bit and bitfield definitions

// Register: FSR1L
volatile unsigned char           FSR1L               @ 0x006;
// bit and bitfield definitions

// Register: FSR1H
volatile unsigned char           FSR1H               @ 0x007;
// bit and bitfield definitions

// Register: FSR1
volatile unsigned int            FSR1                @ 0x006;

// Register: BSR
volatile unsigned char           BSR                 @ 0x008;
// bit and bitfield definitions
volatile bit BSR0                @ ((unsigned)&BSR*8)+0;
volatile bit BSR1                @ ((unsigned)&BSR*8)+1;
volatile bit BSR2                @ ((unsigned)&BSR*8)+2;
volatile bit BSR3                @ ((unsigned)&BSR*8)+3;
volatile bit BSR4                @ ((unsigned)&BSR*8)+4;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	BSR0                : 1;
        unsigned	BSR1                : 1;
        unsigned	BSR2                : 1;
        unsigned	BSR3                : 1;
        unsigned	BSR4                : 1;
    };
    struct {
        unsigned	BSR                 : 5;
    };
} BSRbits @ 0x008;
#endif

// Register: WREG
volatile unsigned char           WREG                @ 0x009;
// bit and bitfield definitions

// Register: PCLATH
volatile unsigned char           PCLATH              @ 0x00A;
// bit and bitfield definitions
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	PCLATH              : 7;
    };
} PCLATHbits @ 0x00A;
#endif

// Register: INTCON
volatile unsigned char           INTCON              @ 0x00B;
// bit and bitfield definitions
volatile bit IOCIF               @ ((unsigned)&INTCON*8)+0;
volatile bit INTF                @ ((unsigned)&INTCON*8)+1;
volatile bit TMR0IF              @ ((unsigned)&INTCON*8)+2;
volatile bit IOCIE               @ ((unsigned)&INTCON*8)+3;
volatile bit INTE                @ ((unsigned)&INTCON*8)+4;
volatile bit TMR0IE              @ ((unsigned)&INTCON*8)+5;
volatile bit PEIE                @ ((unsigned)&INTCON*8)+6;
volatile bit GIE                 @ ((unsigned)&INTCON*8)+7;
volatile bit T0IF                @ ((unsigned)&INTCON*8)+2;
volatile bit T0IE                @ ((unsigned)&INTCON*8)+5;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	IOCIF               : 1;
        unsigned	INTF                : 1;
        unsigned	TMR0IF              : 1;
        unsigned	IOCIE               : 1;
        unsigned	INTE                : 1;
        unsigned	TMR0IE              : 1;
        unsigned	PEIE                : 1;
        unsigned	GIE                 : 1;
    };
    struct {
        unsigned	                    : 2;
        unsigned	T0IF                : 1;
        unsigned	: 2;
        unsigned	T0IE                : 1;
    };
} INTCONbits @ 0x00B;
#endif

// Register: PORTA
volatile unsigned char           PORTA               @ 0x00C;
// bit and bitfield definitions
volatile bit RA0                 @ ((unsigned)&PORTA*8)+0;
volatile bit RA1                 @ ((unsigned)&PORTA*8)+1;
volatile bit RA2                 @ ((unsigned)&PORTA*8)+2;
volatile bit RA3                 @ ((unsigned)&PORTA*8)+3;
volatile bit RA4                 @ ((unsigned)&PORTA*8)+4;
volatile bit RA5                 @ ((unsigned)&PORTA*8)+5;
volatile bit RA6                 @ ((unsigned)&PORTA*8)+6;
volatile bit RA7                 @ ((unsigned)&PORTA*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	RA0                 : 1;
        unsigned	RA1                 : 1;
        unsigned	RA2                 : 1;
        unsigned	RA3                 : 1;
        unsigned	RA4                 : 1;
        unsigned	RA5                 : 1;
        unsigned	RA6                 : 1;
        unsigned	RA7                 : 1;
    };
} PORTAbits @ 0x00C;
#endif

// Register: PORTB
volatile unsigned char           PORTB               @ 0x00D;
// bit and bitfield definitions
volatile bit RB0                 @ ((unsigned)&PORTB*8)+0;
volatile bit RB1                 @ ((unsigned)&PORTB*8)+1;
volatile bit RB2                 @ ((unsigned)&PORTB*8)+2;
volatile bit RB3                 @ ((unsigned)&PORTB*8)+3;
volatile bit RB4                 @ ((unsigned)&PORTB*8)+4;
volatile bit RB5                 @ ((unsigned)&PORTB*8)+5;
volatile bit RB6                 @ ((unsigned)&PORTB*8)+6;
volatile bit RB7                 @ ((unsigned)&PORTB*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	RB0                 : 1;
        unsigned	RB1                 : 1;
        unsigned	RB2                 : 1;
        unsigned	RB3                 : 1;
        unsigned	RB4                 : 1;
        unsigned	RB5                 : 1;
        unsigned	RB6                 : 1;
        unsigned	RB7                 : 1;
    };
} PORTBbits @ 0x00D;
#endif

// Register: PORTC
volatile unsigned char           PORTC               @ 0x00E;
// bit and bitfield definitions
volatile bit RC0                 @ ((unsigned)&PORTC*8)+0;
volatile bit RC1                 @ ((unsigned)&PORTC*8)+1;
volatile bit RC2                 @ ((unsigned)&PORTC*8)+2;
volatile bit RC3                 @ ((unsigned)&PORTC*8)+3;
volatile bit RC4                 @ ((unsigned)&PORTC*8)+4;
volatile bit RC5                 @ ((unsigned)&PORTC*8)+5;
volatile bit RC6                 @ ((unsigned)&PORTC*8)+6;
volatile bit RC7                 @ ((unsigned)&PORTC*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	RC0                 : 1;
        unsigned	RC1                 : 1;
        unsigned	RC2                 : 1;
        unsigned	RC3                 : 1;
        unsigned	RC4                 : 1;
        unsigned	RC5                 : 1;
        unsigned	RC6                 : 1;
        unsigned	RC7                 : 1;
    };
} PORTCbits @ 0x00E;
#endif

// Register: PORTD
volatile unsigned char           PORTD               @ 0x00F;
// bit and bitfield definitions
volatile bit RD0                 @ ((unsigned)&PORTD*8)+0;
volatile bit RD1                 @ ((unsigned)&PORTD*8)+1;
volatile bit RD2                 @ ((unsigned)&PORTD*8)+2;
volatile bit RD3                 @ ((unsigned)&PORTD*8)+3;
volatile bit RD4                 @ ((unsigned)&PORTD*8)+4;
volatile bit RD5                 @ ((unsigned)&PORTD*8)+5;
volatile bit RD6                 @ ((unsigned)&PORTD*8)+6;
volatile bit RD7                 @ ((unsigned)&PORTD*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	RD0                 : 1;
        unsigned	RD1                 : 1;
        unsigned	RD2                 : 1;
        unsigned	RD3                 : 1;
        unsigned	RD4                 : 1;
        unsigned	RD5                 : 1;
        unsigned	RD6                 : 1;
        unsigned	RD7                 : 1;
    };
} PORTDbits @ 0x00F;
#endif

// Register: PORTE
volatile unsigned char           PORTE               @ 0x010;
// bit and bitfield definitions
volatile bit RE0                 @ ((unsigned)&PORTE*8)+0;
volatile bit RE1                 @ ((unsigned)&PORTE*8)+1;
volatile bit RE2                 @ ((unsigned)&PORTE*8)+2;
volatile bit RE3                 @ ((unsigned)&PORTE*8)+3;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	RE0                 : 1;
        unsigned	RE1                 : 1;
        unsigned	RE2                 : 1;
        unsigned	RE3                 : 1;
    };
} PORTEbits @ 0x010;
#endif

// Register: PIR1
volatile unsigned char           PIR1                @ 0x011;
// bit and bitfield definitions
// TMR1 Overflow Interrupt Flag bit
volatile bit TMR1IF              @ ((unsigned)&PIR1*8)+0;
// TMR2 to PR2 Match Interrupt Flag bit
volatile bit TMR2IF              @ ((unsigned)&PIR1*8)+1;
// CCP1 Interrupt Flag bit
volatile bit CCP1IF              @ ((unsigned)&PIR1*8)+2;
// Master Synchronous Serial Port (MSSP) Interrupt Flag bit
volatile bit SSPIF               @ ((unsigned)&PIR1*8)+3;
// EUSART Transmit Interrupt Flag bit
volatile bit TXIF                @ ((unsigned)&PIR1*8)+4;
// EUSART Receive Interrupt Flag bit
volatile bit RCIF                @ ((unsigned)&PIR1*8)+5;
// A/D Converter Interrupt Flag bit
volatile bit ADIF                @ ((unsigned)&PIR1*8)+6;
// Timer1 Gate Interrupt Flag bit
volatile bit TMR1GIF             @ ((unsigned)&PIR1*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	TMR1IF              : 1;
        unsigned	TMR2IF              : 1;
        unsigned	CCP1IF              : 1;
        unsigned	SSPIF               : 1;
        unsigned	TXIF                : 1;
        unsigned	RCIF                : 1;
        unsigned	ADIF                : 1;
        unsigned	TMR1GIF             : 1;
    };
} PIR1bits @ 0x011;
#endif

// Register: PIR2
volatile unsigned char           PIR2                @ 0x012;
// bit and bitfield definitions
volatile bit CCP2IF              @ ((unsigned)&PIR2*8)+0;
volatile bit LCDIF               @ ((unsigned)&PIR2*8)+2;
volatile bit BCLIF               @ ((unsigned)&PIR2*8)+3;
volatile bit EEIF                @ ((unsigned)&PIR2*8)+4;
volatile bit C1IF                @ ((unsigned)&PIR2*8)+5;
volatile bit C2IF                @ ((unsigned)&PIR2*8)+6;
volatile bit OSFIF               @ ((unsigned)&PIR2*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	CCP2IF              : 1;
        unsigned	                    : 1;
        unsigned	LCDIF               : 1;
        unsigned	BCLIF               : 1;
        unsigned	EEIF                : 1;
        unsigned	C1IF                : 1;
        unsigned	C2IF                : 1;
        unsigned	OSFIF               : 1;
    };
} PIR2bits @ 0x012;
#endif

// Register: PIR3
volatile unsigned char           PIR3                @ 0x013;
// bit and bitfield definitions
volatile bit TMR4IF              @ ((unsigned)&PIR3*8)+1;
volatile bit TMR6IF              @ ((unsigned)&PIR3*8)+3;
volatile bit CCP3IF              @ ((unsigned)&PIR3*8)+4;
volatile bit CCP4IF              @ ((unsigned)&PIR3*8)+5;
volatile bit CCP5IF              @ ((unsigned)&PIR3*8)+6;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	                    : 1;
        unsigned	TMR4IF              : 1;
        unsigned	: 1;
        unsigned	TMR6IF              : 1;
        unsigned	CCP3IF              : 1;
        unsigned	CCP4IF              : 1;
        unsigned	CCP5IF              : 1;
    };
} PIR3bits @ 0x013;
#endif

// Register: TMR0
volatile unsigned char           TMR0                @ 0x015;
// bit and bitfield definitions
// bit and bitfield definitions

// Register: TMR1L
volatile unsigned char           TMR1L               @ 0x016;
// bit and bitfield definitions

// Register: TMR1H
volatile unsigned char           TMR1H               @ 0x017;
// bit and bitfield definitions

// Register: TMR1
volatile unsigned int            TMR1                @ 0x016;

// Register: T1CON
volatile unsigned char           T1CON               @ 0x018;
// bit and bitfield definitions
volatile bit TMR1ON              @ ((unsigned)&T1CON*8)+0;
volatile bit nT1SYNC             @ ((unsigned)&T1CON*8)+2;
volatile bit T1OSCEN             @ ((unsigned)&T1CON*8)+3;
volatile bit T1CKPS0             @ ((unsigned)&T1CON*8)+4;
volatile bit T1CKPS1             @ ((unsigned)&T1CON*8)+5;
volatile bit TMR1CS0             @ ((unsigned)&T1CON*8)+6;
volatile bit TMR1CS1             @ ((unsigned)&T1CON*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	TMR1ON              : 1;
        unsigned	                    : 1;
        unsigned	nT1SYNC             : 1;
        unsigned	T1OSCEN             : 1;
        unsigned	T1CKPS0             : 1;
        unsigned	T1CKPS1             : 1;
        unsigned	TMR1CS0             : 1;
        unsigned	TMR1CS1             : 1;
    };
    struct {
        unsigned	: 4;
        unsigned	T1CKPS              : 2;
        unsigned	TMR1CS              : 2;
    };
} T1CONbits @ 0x018;
#endif

// Register: T1GCON
volatile unsigned char           T1GCON              @ 0x019;
// bit and bitfield definitions
volatile bit T1GSS0              @ ((unsigned)&T1GCON*8)+0;
volatile bit T1GSS1              @ ((unsigned)&T1GCON*8)+1;
volatile bit T1GVAL              @ ((unsigned)&T1GCON*8)+2;
volatile bit T1GGO               @ ((unsigned)&T1GCON*8)+3;
volatile bit T1GSPM              @ ((unsigned)&T1GCON*8)+4;
volatile bit T1GTM               @ ((unsigned)&T1GCON*8)+5;
volatile bit T1GPOL              @ ((unsigned)&T1GCON*8)+6;
volatile bit TMR1GE              @ ((unsigned)&T1GCON*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	T1GSS0              : 1;
        unsigned	T1GSS1              : 1;
        unsigned	T1GVAL              : 1;
        unsigned	T1GGO               : 1;
        unsigned	T1GSPM              : 1;
        unsigned	T1GTM               : 1;
        unsigned	T1GPOL              : 1;
        unsigned	TMR1GE              : 1;
    };
    struct {
        unsigned	T1GSS               : 2;
    };
} T1GCONbits @ 0x019;
#endif

// Register: TMR2
volatile unsigned char           TMR2                @ 0x01A;
// bit and bitfield definitions

// Register: PR2
volatile unsigned char           PR2                 @ 0x01B;
// bit and bitfield definitions

// Register: T2CON
volatile unsigned char           T2CON               @ 0x01C;
// bit and bitfield definitions
volatile bit T2CKPS0             @ ((unsigned)&T2CON*8)+0;
volatile bit T2CKPS1             @ ((unsigned)&T2CON*8)+1;
volatile bit TMR2ON              @ ((unsigned)&T2CON*8)+2;
volatile bit T2OUTPS0            @ ((unsigned)&T2CON*8)+3;
volatile bit T2OUTPS1            @ ((unsigned)&T2CON*8)+4;
volatile bit T2OUTPS2            @ ((unsigned)&T2CON*8)+5;
volatile bit T2OUTPS3            @ ((unsigned)&T2CON*8)+6;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	T2CKPS0             : 1;
        unsigned	T2CKPS1             : 1;
        unsigned	TMR2ON              : 1;
        unsigned	T2OUTPS0            : 1;
        unsigned	T2OUTPS1            : 1;
        unsigned	T2OUTPS2            : 1;
        unsigned	T2OUTPS3            : 1;
    };
    struct {
        unsigned	T2CKPS              : 2;
        unsigned	                    : 1;
        unsigned	T2OUTPS             : 4;
    };
} T2CONbits @ 0x01C;
#endif

// Register: CPSCON0
volatile unsigned char           CPSCON0             @ 0x01E;
// bit and bitfield definitions
volatile bit T0XCS               @ ((unsigned)&CPSCON0*8)+0;
volatile bit CPSOUT              @ ((unsigned)&CPSCON0*8)+1;
volatile bit CPSRNG0             @ ((unsigned)&CPSCON0*8)+2;
volatile bit CPSRNG1             @ ((unsigned)&CPSCON0*8)+3;
volatile bit CPSON               @ ((unsigned)&CPSCON0*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	T0XCS               : 1;
        unsigned	CPSOUT              : 1;
        unsigned	CPSRNG0             : 1;
        unsigned	CPSRNG1             : 1;
        unsigned	                    : 3;
        unsigned	CPSON               : 1;
    };
    struct {
        unsigned	: 2;
        unsigned	CPSRNG              : 2;
    };
} CPSCON0bits @ 0x01E;
#endif

// Register: CPSCON1
volatile unsigned char           CPSCON1             @ 0x01F;
// bit and bitfield definitions
volatile bit CPSCH0              @ ((unsigned)&CPSCON1*8)+0;
volatile bit CPSCH1              @ ((unsigned)&CPSCON1*8)+1;
volatile bit CPSCH2              @ ((unsigned)&CPSCON1*8)+2;
volatile bit CPSCH3              @ ((unsigned)&CPSCON1*8)+3;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	CPSCH0              : 1;
        unsigned	CPSCH1              : 1;
        unsigned	CPSCH2              : 1;
        unsigned	CPSCH3              : 1;
    };
    struct {
        unsigned	CPSCH               : 4;
    };
} CPSCON1bits @ 0x01F;
#endif

//
// Special function register definitions: Bank 1
//


// Register: TRISA
// PORTA Data Direction Control Register
volatile unsigned char           TRISA               @ 0x08C;
// bit and bitfield definitions
volatile bit TRISA0              @ ((unsigned)&TRISA*8)+0;
volatile bit TRISA1              @ ((unsigned)&TRISA*8)+1;
volatile bit TRISA2              @ ((unsigned)&TRISA*8)+2;
volatile bit TRISA3              @ ((unsigned)&TRISA*8)+3;
volatile bit TRISA4              @ ((unsigned)&TRISA*8)+4;
volatile bit TRISA5              @ ((unsigned)&TRISA*8)+5;
volatile bit TRISA6              @ ((unsigned)&TRISA*8)+6;
volatile bit TRISA7              @ ((unsigned)&TRISA*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	TRISA0              : 1;
        unsigned	TRISA1              : 1;
        unsigned	TRISA2              : 1;
        unsigned	TRISA3              : 1;
        unsigned	TRISA4              : 1;
        unsigned	TRISA5              : 1;
        unsigned	TRISA6              : 1;
        unsigned	TRISA7              : 1;
    };
} TRISAbits @ 0x08C;
#endif

// Register: TRISB
// PORTB Data Direction Control Register
volatile unsigned char           TRISB               @ 0x08D;
// bit and bitfield definitions
volatile bit TRISB0              @ ((unsigned)&TRISB*8)+0;
volatile bit TRISB1              @ ((unsigned)&TRISB*8)+1;
volatile bit TRISB2              @ ((unsigned)&TRISB*8)+2;
volatile bit TRISB3              @ ((unsigned)&TRISB*8)+3;
volatile bit TRISB4              @ ((unsigned)&TRISB*8)+4;
volatile bit TRISB5              @ ((unsigned)&TRISB*8)+5;
volatile bit TRISB6              @ ((unsigned)&TRISB*8)+6;
volatile bit TRISB7              @ ((unsigned)&TRISB*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	TRISB0              : 1;
        unsigned	TRISB1              : 1;
        unsigned	TRISB2              : 1;
        unsigned	TRISB3              : 1;
        unsigned	TRISB4              : 1;
        unsigned	TRISB5              : 1;
        unsigned	TRISB6              : 1;
        unsigned	TRISB7              : 1;
    };
} TRISBbits @ 0x08D;
#endif

// Register: TRISC
// PORTC Data Direction Control Register
volatile unsigned char           TRISC               @ 0x08E;
// bit and bitfield definitions
volatile bit TRISC0              @ ((unsigned)&TRISC*8)+0;
volatile bit TRISC1              @ ((unsigned)&TRISC*8)+1;
volatile bit TRISC2              @ ((unsigned)&TRISC*8)+2;
volatile bit TRISC3              @ ((unsigned)&TRISC*8)+3;
volatile bit TRISC4              @ ((unsigned)&TRISC*8)+4;
volatile bit TRISC5              @ ((unsigned)&TRISC*8)+5;
volatile bit TRISC6              @ ((unsigned)&TRISC*8)+6;
volatile bit TRISC7              @ ((unsigned)&TRISC*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	TRISC0              : 1;
        unsigned	TRISC1              : 1;
        unsigned	TRISC2              : 1;
        unsigned	TRISC3              : 1;
        unsigned	TRISC4              : 1;
        unsigned	TRISC5              : 1;
        unsigned	TRISC6              : 1;
        unsigned	TRISC7              : 1;
    };
} TRISCbits @ 0x08E;
#endif

// Register: TRISD
// PORTD Data Direction Control Register
volatile unsigned char           TRISD               @ 0x08F;
// bit and bitfield definitions
volatile bit TRISD0              @ ((unsigned)&TRISD*8)+0;
volatile bit TRISD1              @ ((unsigned)&TRISD*8)+1;
volatile bit TRISD2              @ ((unsigned)&TRISD*8)+2;
volatile bit TRISD3              @ ((unsigned)&TRISD*8)+3;
volatile bit TRISD4              @ ((unsigned)&TRISD*8)+4;
volatile bit TRISD5              @ ((unsigned)&TRISD*8)+5;
volatile bit TRISD6              @ ((unsigned)&TRISD*8)+6;
volatile bit TRISD7              @ ((unsigned)&TRISD*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	TRISD0              : 1;
        unsigned	TRISD1              : 1;
        unsigned	TRISD2              : 1;
        unsigned	TRISD3              : 1;
        unsigned	TRISD4              : 1;
        unsigned	TRISD5              : 1;
        unsigned	TRISD6              : 1;
        unsigned	TRISD7              : 1;
    };
} TRISDbits @ 0x08F;
#endif

// Register: TRISE
volatile unsigned char           TRISE               @ 0x090;
// bit and bitfield definitions
volatile bit TRISE0              @ ((unsigned)&TRISE*8)+0;
volatile bit TRISE1              @ ((unsigned)&TRISE*8)+1;
volatile bit TRISE2              @ ((unsigned)&TRISE*8)+2;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	TRISE0              : 1;
        unsigned	TRISE1              : 1;
        unsigned	TRISE2              : 1;
        unsigned	                    : 1;
    };
} TRISEbits @ 0x090;
#endif

// Register: PIE1
// Peripheral Interrupt Enable Register 1
volatile unsigned char           PIE1                @ 0x091;
// bit and bitfield definitions
// TMR1 Overflow Interrupt Enable bit
volatile bit TMR1IE              @ ((unsigned)&PIE1*8)+0;
// TMR2 to PR2 Match Interrupt Enable bit
volatile bit TMR2IE              @ ((unsigned)&PIE1*8)+1;
// CCP1 Interrupt Enable bit
volatile bit CCP1IE              @ ((unsigned)&PIE1*8)+2;
// Master Synchronous Serial Port (MSSP) Interrupt Enable bit
volatile bit SSPIE               @ ((unsigned)&PIE1*8)+3;
// EUSART Transmit Interrupt Enable bit
volatile bit TXIE                @ ((unsigned)&PIE1*8)+4;
// EUSART Receive Interrupt Enable bit
volatile bit RCIE                @ ((unsigned)&PIE1*8)+5;
// A/D Converter Interrupt Enable bit
volatile bit ADIE                @ ((unsigned)&PIE1*8)+6;
// Timer1 Gate Interrupt Enable bit
volatile bit TMR1GIE             @ ((unsigned)&PIE1*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	TMR1IE              : 1;
        unsigned	TMR2IE              : 1;
        unsigned	CCP1IE              : 1;
        unsigned	SSPIE               : 1;
        unsigned	TXIE                : 1;
        unsigned	RCIE                : 1;
        unsigned	ADIE                : 1;
        unsigned	TMR1GIE             : 1;
    };
} PIE1bits @ 0x091;
#endif

// Register: PIE2
// Peripheral Interrupt Enable Register 2
volatile unsigned char           PIE2                @ 0x092;
// bit and bitfield definitions
// CCP2 Interrupt Enable bit
volatile bit CCP2IE              @ ((unsigned)&PIE2*8)+0;
// LCD Module Interrupt Enable bit
volatile bit LCDIE               @ ((unsigned)&PIE2*8)+2;
// MSSP Bus Collision Interrupt Interrupt Enable bit
volatile bit BCLIE               @ ((unsigned)&PIE2*8)+3;
// EEPROM Write Completion Interrupt Enable bit
volatile bit EEIE                @ ((unsigned)&PIE2*8)+4;
// Comparator C1 Interrupt Enable bit
volatile bit C1IE                @ ((unsigned)&PIE2*8)+5;
// Comparator C2 Interrupt Enable bit
volatile bit C2IE                @ ((unsigned)&PIE2*8)+6;
// CCP2 Interrupt Enable bit
volatile bit OSFIE               @ ((unsigned)&PIE2*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	CCP2IE              : 1;
        unsigned	                    : 1;
        unsigned	LCDIE               : 1;
        unsigned	BCLIE               : 1;
        unsigned	EEIE                : 1;
        unsigned	C1IE                : 1;
        unsigned	C2IE                : 1;
        unsigned	OSFIE               : 1;
    };
} PIE2bits @ 0x092;
#endif

// Register: PIE3
// Peripheral Interrupt Enable Register 3
volatile unsigned char           PIE3                @ 0x093;
// bit and bitfield definitions
// TMR4 to PR4 Match Interrupt Enable bit
volatile bit TMR4IE              @ ((unsigned)&PIE3*8)+1;
// TMR6 to PR6 Match Interrupt Enable bit
volatile bit TMR6IE              @ ((unsigned)&PIE3*8)+3;
// CCP3 Interrupt Enable bit
volatile bit CCP3IE              @ ((unsigned)&PIE3*8)+4;
// CCP4 Interrupt Enable bit
volatile bit CCP4IE              @ ((unsigned)&PIE3*8)+5;
// CCP5 Interrupt Enable bit
volatile bit CCP5IE              @ ((unsigned)&PIE3*8)+6;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	                    : 1;
        unsigned	TMR4IE              : 1;
        unsigned	: 1;
        unsigned	TMR6IE              : 1;
        unsigned	CCP3IE              : 1;
        unsigned	CCP4IE              : 1;
        unsigned	CCP5IE              : 1;
    };
} PIE3bits @ 0x093;
#endif

// Register: OPTION_REG
// Option Register
volatile unsigned char           OPTION_REG          @ 0x095;
// bit and bitfield definitions
// Prescaler Rate Select bits
volatile bit PS0                 @ ((unsigned)&OPTION_REG*8)+0;
// Prescaler Rate Select bits
volatile bit PS1                 @ ((unsigned)&OPTION_REG*8)+1;
// Prescaler Rate Select bits
volatile bit PS2                 @ ((unsigned)&OPTION_REG*8)+2;
// Prescaler Active bit
volatile bit PSA                 @ ((unsigned)&OPTION_REG*8)+3;
// TMR0 Source Edge Select bit
volatile bit TMR0SE              @ ((unsigned)&OPTION_REG*8)+4;
// TMR0 Clock Source Select bit
volatile bit TMR0CS              @ ((unsigned)&OPTION_REG*8)+5;
// Interrupt Edge Select bit
volatile bit INTEDG              @ ((unsigned)&OPTION_REG*8)+6;
// Weak Pull-up Enable bit
volatile bit nWPUEN              @ ((unsigned)&OPTION_REG*8)+7;
volatile bit T0SE                @ ((unsigned)&OPTION_REG*8)+4;
volatile bit T0CS                @ ((unsigned)&OPTION_REG*8)+5;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	PS0                 : 1;
        unsigned	PS1                 : 1;
        unsigned	PS2                 : 1;
        unsigned	PSA                 : 1;
        unsigned	TMR0SE              : 1;
        unsigned	TMR0CS              : 1;
        unsigned	INTEDG              : 1;
        unsigned	nWPUEN              : 1;
    };
    struct {
        unsigned	PS                  : 3;
        unsigned	                    : 1;
        unsigned	T0SE                : 1;
        unsigned	T0CS                : 1;
    };
} OPTION_REGbits @ 0x095;
#endif

// Register: PCON
// Power Control Register
volatile unsigned char           PCON                @ 0x096;
// bit and bitfield definitions
// Brown-out Reset Status bit
volatile bit nBOR                @ ((unsigned)&PCON*8)+0;
// Power-on Reset Status bit
volatile bit nPOR                @ ((unsigned)&PCON*8)+1;
// RESET Instruction Flag bit
volatile bit nRI                 @ ((unsigned)&PCON*8)+2;
// MCLR Reset Flag bit
volatile bit nRMCLR              @ ((unsigned)&PCON*8)+3;
// Stack Underflow Flag bit
volatile bit STKUNF              @ ((unsigned)&PCON*8)+6;
// Stack Overflow Flag bit
volatile bit STKOVF              @ ((unsigned)&PCON*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	nBOR                : 1;
        unsigned	nPOR                : 1;
        unsigned	nRI                 : 1;
        unsigned	nRMCLR              : 1;
        unsigned	                    : 1;
        unsigned	: 1;
        unsigned	STKUNF              : 1;
        unsigned	STKOVF              : 1;
    };
} PCONbits @ 0x096;
#endif

// Register: WDTCON
// Watchdog Timer Control Register
volatile unsigned char           WDTCON              @ 0x097;
// bit and bitfield definitions
// Software Enable/Disable for Watch Dog Timer bit
volatile bit SWDTEN              @ ((unsigned)&WDTCON*8)+0;
// Watchdog Timer Period Select bits
volatile bit WDTPS0              @ ((unsigned)&WDTCON*8)+1;
// Watchdog Timer Period Select bits
volatile bit WDTPS1              @ ((unsigned)&WDTCON*8)+2;
// Watchdog Timer Period Select bits
volatile bit WDTPS2              @ ((unsigned)&WDTCON*8)+3;
// Watchdog Timer Period Select bits
volatile bit WDTPS3              @ ((unsigned)&WDTCON*8)+4;
// Watchdog Timer Period Select bits
volatile bit WDTPS4              @ ((unsigned)&WDTCON*8)+5;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	SWDTEN              : 1;
        unsigned	WDTPS0              : 1;
        unsigned	WDTPS1              : 1;
        unsigned	WDTPS2              : 1;
        unsigned	WDTPS3              : 1;
        unsigned	WDTPS4              : 1;
    };
    struct {
        unsigned	                    : 1;
        unsigned	WDTPS               : 5;
    };
} WDTCONbits @ 0x097;
#endif

// Register: OSCTUNE
// Oscillator Tuning Register
volatile unsigned char           OSCTUNE             @ 0x098;
// bit and bitfield definitions
// Frequency Tuning bits
volatile bit TUN0                @ ((unsigned)&OSCTUNE*8)+0;
// Frequency Tuning bits
volatile bit TUN1                @ ((unsigned)&OSCTUNE*8)+1;
// Frequency Tuning bits
volatile bit TUN2                @ ((unsigned)&OSCTUNE*8)+2;
// Frequency Tuning bits
volatile bit TUN3                @ ((unsigned)&OSCTUNE*8)+3;
// Frequency Tuning bits
volatile bit TUN4                @ ((unsigned)&OSCTUNE*8)+4;
// Frequency Tuning bits
volatile bit TUN5                @ ((unsigned)&OSCTUNE*8)+5;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	TUN0                : 1;
        unsigned	TUN1                : 1;
        unsigned	TUN2                : 1;
        unsigned	TUN3                : 1;
        unsigned	TUN4                : 1;
        unsigned	TUN5                : 1;
    };
    struct {
        unsigned	TUN                 : 6;
    };
} OSCTUNEbits @ 0x098;
#endif

// Register: OSCCON
// Oscillator Control Register
volatile unsigned char           OSCCON              @ 0x099;
// bit and bitfield definitions
// System clock select bit
volatile bit SCS0                @ ((unsigned)&OSCCON*8)+0;
// System clock select bit
volatile bit SCS1                @ ((unsigned)&OSCCON*8)+1;
// Internal Oscillator Frequency Select bits
volatile bit IRCF0               @ ((unsigned)&OSCCON*8)+3;
// Internal Oscillator Frequency Select bits
volatile bit IRCF1               @ ((unsigned)&OSCCON*8)+4;
// Internal Oscillator Frequency Select bits
volatile bit IRCF2               @ ((unsigned)&OSCCON*8)+5;
// Internal Oscillator Frequency Select bits
volatile bit IRCF3               @ ((unsigned)&OSCCON*8)+6;
// Software PLL Enable bit
volatile bit SPLLEN              @ ((unsigned)&OSCCON*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	SCS0                : 1;
        unsigned	SCS1                : 1;
        unsigned	                    : 1;
        unsigned	IRCF0               : 1;
        unsigned	IRCF1               : 1;
        unsigned	IRCF2               : 1;
        unsigned	IRCF3               : 1;
        unsigned	SPLLEN              : 1;
    };
    struct {
        unsigned	SCS                 : 2;
        unsigned	: 1;
        unsigned	IRCF                : 4;
    };
} OSCCONbits @ 0x099;
#endif

// Register: OSCSTAT
// Oscillator Status Register
volatile unsigned char           OSCSTAT             @ 0x09A;
// bit and bitfield definitions
// Low Freqency Internal Oscillator Ready bit
volatile bit HFIOFS              @ ((unsigned)&OSCSTAT*8)+0;
// Low Freqency Internal Oscillator Ready bit
volatile bit LFIOFR              @ ((unsigned)&OSCSTAT*8)+1;
// Medium Freqency Internal Oscillator Ready bit
volatile bit MFIOFR              @ ((unsigned)&OSCSTAT*8)+2;
// High Freqency Internal Oscillator Status Locked bit
volatile bit HFIOFL              @ ((unsigned)&OSCSTAT*8)+3;
// High Freqency Internal Oscillator Ready bit
volatile bit HFIOFR              @ ((unsigned)&OSCSTAT*8)+4;
// Oscillator Start-up Time-out Status bit
volatile bit OSTS                @ ((unsigned)&OSCSTAT*8)+5;
// 4x PLL Ready bit
volatile bit PLLR                @ ((unsigned)&OSCSTAT*8)+6;
// Timer1 Oscillator Ready bit
volatile bit T1OSCR              @ ((unsigned)&OSCSTAT*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	HFIOFS              : 1;
        unsigned	LFIOFR              : 1;
        unsigned	MFIOFR              : 1;
        unsigned	HFIOFL              : 1;
        unsigned	HFIOFR              : 1;
        unsigned	OSTS                : 1;
        unsigned	PLLR                : 1;
        unsigned	T1OSCR              : 1;
    };
} OSCSTATbits @ 0x09A;
#endif
// bit and bitfield definitions

// Register: ADRESL
// A/D Result Register LSB
volatile unsigned char           ADRESL              @ 0x09B;
// bit and bitfield definitions

// Register: ADRESH
// A/D Result Register MSB
volatile unsigned char           ADRESH              @ 0x09C;
// bit and bitfield definitions

// Register: ADRES
volatile unsigned int            ADRES               @ 0x09B;

// Register: ADCON0
// Analog-to-Digital Control Register 0
volatile unsigned char           ADCON0              @ 0x09D;
// bit and bitfield definitions
// A/D Module Enable bit
volatile bit ADON                @ ((unsigned)&ADCON0*8)+0;
// A/D Conversion Status bit
volatile bit GO_nDONE            @ ((unsigned)&ADCON0*8)+1;
// Analog Channel Select bits
volatile bit CHS0                @ ((unsigned)&ADCON0*8)+2;
// Analog Channel Select bits
volatile bit CHS1                @ ((unsigned)&ADCON0*8)+3;
// Analog Channel Select bits
volatile bit CHS2                @ ((unsigned)&ADCON0*8)+4;
// Analog Channel Select bits
volatile bit CHS3                @ ((unsigned)&ADCON0*8)+5;
// Analog Channel Select bits
volatile bit CHS4                @ ((unsigned)&ADCON0*8)+6;
// A/D Conversion Status bit
volatile bit ADGO                @ ((unsigned)&ADCON0*8)+1;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	ADON                : 1;
        unsigned	GO_nDONE            : 1;
        unsigned	CHS0                : 1;
        unsigned	CHS1                : 1;
        unsigned	CHS2                : 1;
        unsigned	CHS3                : 1;
        unsigned	CHS4                : 1;
        unsigned	                    : 1;
    };
    struct {
        unsigned	: 1;
        unsigned	ADGO                : 1;
        unsigned	CHS                 : 5;
    };
} ADCON0bits @ 0x09D;
#endif

// Register: ADCON1
// Analog-to-Digital Control Register 1
volatile unsigned char           ADCON1              @ 0x09E;
// bit and bitfield definitions
// A/D Positive Voltage Reference Configuration
volatile bit ADPREF0             @ ((unsigned)&ADCON1*8)+0;
// A/D Positive Voltage Reference Configuration
volatile bit ADPREF1             @ ((unsigned)&ADCON1*8)+1;
// A/D Negative Voltage Reference Configuration
volatile bit ADNREF              @ ((unsigned)&ADCON1*8)+2;
// A/D Conversion Clock Select bits
volatile bit ADCS0               @ ((unsigned)&ADCON1*8)+4;
// A/D Conversion Clock Select bits
volatile bit ADCS1               @ ((unsigned)&ADCON1*8)+5;
// A/D Conversion Clock Select bits
volatile bit ADCS2               @ ((unsigned)&ADCON1*8)+6;
// A/D Result Format Select bit
volatile bit ADFM                @ ((unsigned)&ADCON1*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	ADPREF0             : 1;
        unsigned	ADPREF1             : 1;
        unsigned	ADNREF              : 1;
        unsigned	                    : 1;
        unsigned	ADCS0               : 1;
        unsigned	ADCS1               : 1;
        unsigned	ADCS2               : 1;
        unsigned	ADFM                : 1;
    };
    struct {
        unsigned	ADPREF              : 2;
        unsigned	: 2;
        unsigned	ADCS                : 3;
    };
} ADCON1bits @ 0x09E;
#endif

//
// Special function register definitions: Bank 2
//


// Register: LATA
volatile unsigned char           LATA                @ 0x10C;
// bit and bitfield definitions
volatile bit LATA0               @ ((unsigned)&LATA*8)+0;
volatile bit LATA1               @ ((unsigned)&LATA*8)+1;
volatile bit LATA2               @ ((unsigned)&LATA*8)+2;
volatile bit LATA3               @ ((unsigned)&LATA*8)+3;
volatile bit LATA4               @ ((unsigned)&LATA*8)+4;
volatile bit LATA5               @ ((unsigned)&LATA*8)+5;
volatile bit LATA6               @ ((unsigned)&LATA*8)+6;
volatile bit LATA7               @ ((unsigned)&LATA*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	LATA0               : 1;
        unsigned	LATA1               : 1;
        unsigned	LATA2               : 1;
        unsigned	LATA3               : 1;
        unsigned	LATA4               : 1;
        unsigned	LATA5               : 1;
        unsigned	LATA6               : 1;
        unsigned	LATA7               : 1;
    };
} LATAbits @ 0x10C;
#endif

// Register: LATB
volatile unsigned char           LATB                @ 0x10D;
// bit and bitfield definitions
volatile bit LATB0               @ ((unsigned)&LATB*8)+0;
volatile bit LATB1               @ ((unsigned)&LATB*8)+1;
volatile bit LATB2               @ ((unsigned)&LATB*8)+2;
volatile bit LATB3               @ ((unsigned)&LATB*8)+3;
volatile bit LATB4               @ ((unsigned)&LATB*8)+4;
volatile bit LATB5               @ ((unsigned)&LATB*8)+5;
volatile bit LATB6               @ ((unsigned)&LATB*8)+6;
volatile bit LATB7               @ ((unsigned)&LATB*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	LATB0               : 1;
        unsigned	LATB1               : 1;
        unsigned	LATB2               : 1;
        unsigned	LATB3               : 1;
        unsigned	LATB4               : 1;
        unsigned	LATB5               : 1;
        unsigned	LATB6               : 1;
        unsigned	LATB7               : 1;
    };
} LATBbits @ 0x10D;
#endif

// Register: LATC
volatile unsigned char           LATC                @ 0x10E;
// bit and bitfield definitions
volatile bit LATC0               @ ((unsigned)&LATC*8)+0;
volatile bit LATC1               @ ((unsigned)&LATC*8)+1;
volatile bit LATC2               @ ((unsigned)&LATC*8)+2;
volatile bit LATC3               @ ((unsigned)&LATC*8)+3;
volatile bit LATC4               @ ((unsigned)&LATC*8)+4;
volatile bit LATC5               @ ((unsigned)&LATC*8)+5;
volatile bit LATC6               @ ((unsigned)&LATC*8)+6;
volatile bit LATC7               @ ((unsigned)&LATC*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	LATC0               : 1;
        unsigned	LATC1               : 1;
        unsigned	LATC2               : 1;
        unsigned	LATC3               : 1;
        unsigned	LATC4               : 1;
        unsigned	LATC5               : 1;
        unsigned	LATC6               : 1;
        unsigned	LATC7               : 1;
    };
} LATCbits @ 0x10E;
#endif

// Register: LATD
volatile unsigned char           LATD                @ 0x10F;
// bit and bitfield definitions
volatile bit LATD0               @ ((unsigned)&LATD*8)+0;
volatile bit LATD1               @ ((unsigned)&LATD*8)+1;
volatile bit LATD2               @ ((unsigned)&LATD*8)+2;
volatile bit LATD3               @ ((unsigned)&LATD*8)+3;
volatile bit LATD4               @ ((unsigned)&LATD*8)+4;
volatile bit LATD5               @ ((unsigned)&LATD*8)+5;
volatile bit LATD6               @ ((unsigned)&LATD*8)+6;
volatile bit LATD7               @ ((unsigned)&LATD*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	LATD0               : 1;
        unsigned	LATD1               : 1;
        unsigned	LATD2               : 1;
        unsigned	LATD3               : 1;
        unsigned	LATD4               : 1;
        unsigned	LATD5               : 1;
        unsigned	LATD6               : 1;
        unsigned	LATD7               : 1;
    };
} LATDbits @ 0x10F;
#endif

// Register: LATE
volatile unsigned char           LATE                @ 0x110;
// bit and bitfield definitions
volatile bit LATE0               @ ((unsigned)&LATE*8)+0;
volatile bit LATE1               @ ((unsigned)&LATE*8)+1;
volatile bit LATE2               @ ((unsigned)&LATE*8)+2;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	LATE0               : 1;
        unsigned	LATE1               : 1;
        unsigned	LATE2               : 1;
        unsigned	                    : 1;
    };
    struct {
        unsigned	LATE                : 3;
        unsigned	: 5;
    };
} LATEbits @ 0x110;
#endif

// Register: CM1CON0
volatile unsigned char           CM1CON0             @ 0x111;
// bit and bitfield definitions
// Comparator Output Synchronous Mode bit
volatile bit C1SYNC              @ ((unsigned)&CM1CON0*8)+0;
// Comparator Hysteresis Enable bit
volatile bit C1HYS               @ ((unsigned)&CM1CON0*8)+1;
// Comparator Speed/Power Select bit
volatile bit C1SP                @ ((unsigned)&CM1CON0*8)+2;
// Comparator Output Polarity Select bit
volatile bit C1POL               @ ((unsigned)&CM1CON0*8)+4;
// Comparator Output Enable bit
volatile bit C1OE                @ ((unsigned)&CM1CON0*8)+5;
// Comparator Output bit
volatile bit C1OUT               @ ((unsigned)&CM1CON0*8)+6;
// Comparator Enable bit
volatile bit C1ON                @ ((unsigned)&CM1CON0*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	C1SYNC              : 1;
        unsigned	C1HYS               : 1;
        unsigned	C1SP                : 1;
        unsigned	                    : 1;
        unsigned	C1POL               : 1;
        unsigned	C1OE                : 1;
        unsigned	C1OUT               : 1;
        unsigned	C1ON                : 1;
    };
} CM1CON0bits @ 0x111;
#endif

// Register: CM1CON1
volatile unsigned char           CM1CON1             @ 0x112;
// bit and bitfield definitions
// Comparator Negative Input Channel Select bits
volatile bit C1NCH0              @ ((unsigned)&CM1CON1*8)+0;
// Comparator Negative Input Channel Select bits
volatile bit C1NCH1              @ ((unsigned)&CM1CON1*8)+1;
// Comparator Positive Input Channel Select bits
volatile bit C1PCH0              @ ((unsigned)&CM1CON1*8)+4;
// Comparator Positive Input Channel Select bits
volatile bit C1PCH1              @ ((unsigned)&CM1CON1*8)+5;
// Comparator Interrupt on Negative going edge Enable bits
volatile bit C1INTN              @ ((unsigned)&CM1CON1*8)+6;
// Comparator Interrupt on Positive going edge Enable bits
volatile bit C1INTP              @ ((unsigned)&CM1CON1*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	C1NCH0              : 1;
        unsigned	C1NCH1              : 1;
        unsigned	                    : 2;
        unsigned	C1PCH0              : 1;
        unsigned	C1PCH1              : 1;
        unsigned	C1INTN              : 1;
        unsigned	C1INTP              : 1;
    };
    struct {
        unsigned	C1NCH               : 2;
        unsigned	: 2;
        unsigned	C1PCH               : 2;
    };
} CM1CON1bits @ 0x112;
#endif

// Register: CM2CON0
volatile unsigned char           CM2CON0             @ 0x113;
// bit and bitfield definitions
volatile bit C2SYNC              @ ((unsigned)&CM2CON0*8)+0;
volatile bit C2HYS               @ ((unsigned)&CM2CON0*8)+1;
volatile bit C2SP                @ ((unsigned)&CM2CON0*8)+2;
volatile bit C2POL               @ ((unsigned)&CM2CON0*8)+4;
volatile bit C2OE                @ ((unsigned)&CM2CON0*8)+5;
volatile bit C2OUT               @ ((unsigned)&CM2CON0*8)+6;
volatile bit C2ON                @ ((unsigned)&CM2CON0*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	C2SYNC              : 1;
        unsigned	C2HYS               : 1;
        unsigned	C2SP                : 1;
        unsigned	                    : 1;
        unsigned	C2POL               : 1;
        unsigned	C2OE                : 1;
        unsigned	C2OUT               : 1;
        unsigned	C2ON                : 1;
    };
} CM2CON0bits @ 0x113;
#endif

// Register: CM2CON1
volatile unsigned char           CM2CON1             @ 0x114;
// bit and bitfield definitions
// Comparator Negative Input Channel Select bits
volatile bit C2NCH0              @ ((unsigned)&CM2CON1*8)+0;
// Comparator Negative Input Channel Select bits
volatile bit C2NCH1              @ ((unsigned)&CM2CON1*8)+1;
// Comparator Positive Input Channel Select bits
volatile bit C2PCH0              @ ((unsigned)&CM2CON1*8)+4;
// Comparator Positive Input Channel Select bits
volatile bit C2PCH1              @ ((unsigned)&CM2CON1*8)+5;
// Comparator Interrupt on Negative going edge Enable bits
volatile bit C2INTN              @ ((unsigned)&CM2CON1*8)+6;
// Comparator Interrupt on Positive going edge Enable bits
volatile bit C2INTP              @ ((unsigned)&CM2CON1*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	C2NCH0              : 1;
        unsigned	C2NCH1              : 1;
        unsigned	                    : 2;
        unsigned	C2PCH0              : 1;
        unsigned	C2PCH1              : 1;
        unsigned	C2INTN              : 1;
        unsigned	C2INTP              : 1;
    };
    struct {
        unsigned	C2NCH               : 2;
        unsigned	: 2;
        unsigned	C2PCH               : 2;
    };
} CM2CON1bits @ 0x114;
#endif

// Register: CMOUT
// Comparator Output Register
volatile unsigned char           CMOUT               @ 0x115;
// bit and bitfield definitions
volatile bit MC1OUT              @ ((unsigned)&CMOUT*8)+0;
volatile bit MC2OUT              @ ((unsigned)&CMOUT*8)+1;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	MC1OUT              : 1;
        unsigned	MC2OUT              : 1;
    };
} CMOUTbits @ 0x115;
#endif

// Register: BORCON
// Brown-out Reset Control Register
volatile unsigned char           BORCON              @ 0x116;
// bit and bitfield definitions
// Brown-out Reset Circuit Ready Status bit
volatile bit BORRDY              @ ((unsigned)&BORCON*8)+0;
// Software Brown Out Reset Enable bit
volatile bit SBOREN              @ ((unsigned)&BORCON*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	BORRDY              : 1;
        unsigned	                    : 6;
        unsigned	SBOREN              : 1;
    };
} BORCONbits @ 0x116;
#endif

// Register: FVRCON
// Voltage Reference Control Register 0
volatile unsigned char           FVRCON              @ 0x117;
// bit and bitfield definitions
// A/D Converter Fixed Voltage Reference Selection
volatile bit ADFVR0              @ ((unsigned)&FVRCON*8)+0;
// A/D Converter Fixed Voltage Reference Selection
volatile bit ADFVR1              @ ((unsigned)&FVRCON*8)+1;
// Comparator and D/A Converter Fixed Voltage Reference Selection
volatile bit CDAFVR0             @ ((unsigned)&FVRCON*8)+2;
// Comparator and D/A Converter Fixed Voltage Reference Selection
volatile bit CDAFVR1             @ ((unsigned)&FVRCON*8)+3;
// Fixed Voltage Reference Ready Flag
volatile bit FVRRDY              @ ((unsigned)&FVRCON*8)+6;
// Fixed Voltage Reference Enable
volatile bit FVREN               @ ((unsigned)&FVRCON*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	ADFVR0              : 1;
        unsigned	ADFVR1              : 1;
        unsigned	CDAFVR0             : 1;
        unsigned	CDAFVR1             : 1;
        unsigned	                    : 1;
        unsigned	: 1;
        unsigned	FVRRDY              : 1;
        unsigned	FVREN               : 1;
    };
    struct {
        unsigned	ADFVR               : 2;
        unsigned	CDAFVR              : 2;
    };
} FVRCONbits @ 0x117;
#endif

// Register: DACCON0
// Voltage Reference Control Register 1
volatile unsigned char           DACCON0             @ 0x118;
// bit and bitfield definitions
// DAC1 Negative Source Select bits
volatile bit DACNSS              @ ((unsigned)&DACCON0*8)+0;
// DAC1 Positive Source Select bits
volatile bit DACPSS0             @ ((unsigned)&DACCON0*8)+2;
// DAC1 Positive Source Select bits
volatile bit DACPSS1             @ ((unsigned)&DACCON0*8)+3;
// DAC1 Voltage Output Enable bit
volatile bit DACOE               @ ((unsigned)&DACCON0*8)+5;
// DAC 1 Low Power Voltage State Select bit
volatile bit DACLPS              @ ((unsigned)&DACCON0*8)+6;
// DAC 1 Enable bit
volatile bit DACEN               @ ((unsigned)&DACCON0*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	DACNSS              : 1;
        unsigned	                    : 1;
        unsigned	DACPSS0             : 1;
        unsigned	DACPSS1             : 1;
        unsigned	: 1;
        unsigned	DACOE               : 1;
        unsigned	DACLPS              : 1;
        unsigned	DACEN               : 1;
    };
    struct {
        unsigned	: 2;
        unsigned	DACPSS              : 2;
    };
} DACCON0bits @ 0x118;
#endif

// Register: DACCON1
// Voltage Reference Control Register 2
volatile unsigned char           DACCON1             @ 0x119;
// bit and bitfield definitions
// DAC1 Voltage Output Select bits
volatile bit DACR0               @ ((unsigned)&DACCON1*8)+0;
// DAC1 Voltage Output Select bits
volatile bit DACR1               @ ((unsigned)&DACCON1*8)+1;
// DAC1 Voltage Output Select bits
volatile bit DACR2               @ ((unsigned)&DACCON1*8)+2;
// DAC1 Voltage Output Select bits
volatile bit DACR3               @ ((unsigned)&DACCON1*8)+3;
// DAC1 Voltage Output Select bits
volatile bit DACR4               @ ((unsigned)&DACCON1*8)+4;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	DACR0               : 1;
        unsigned	DACR1               : 1;
        unsigned	DACR2               : 1;
        unsigned	DACR3               : 1;
        unsigned	DACR4               : 1;
        unsigned	                    : 1;
    };
    struct {
        unsigned	DACR                : 5;
    };
} DACCON1bits @ 0x119;
#endif

// Register: SRCON0
// SR Latch Control Register 0
volatile unsigned char           SRCON0              @ 0x11A;
// bit and bitfield definitions
// Pulse Reset Input of the SR Latch
volatile bit SRPR                @ ((unsigned)&SRCON0*8)+0;
// Pulse Set Input of the SR Latch
volatile bit SRPS                @ ((unsigned)&SRCON0*8)+1;
// SR Latch Q Output Enable bit
volatile bit SRNQEN              @ ((unsigned)&SRCON0*8)+2;
// SR Latch Q Output Enable bit
volatile bit SRQEN               @ ((unsigned)&SRCON0*8)+3;
// SR Latch Clock divider bits
volatile bit SRCLK0              @ ((unsigned)&SRCON0*8)+4;
// SR Latch Clock divider bits
volatile bit SRCLK1              @ ((unsigned)&SRCON0*8)+5;
// SR Latch Clock divider bits
volatile bit SRCLK2              @ ((unsigned)&SRCON0*8)+6;
// SR Latch Enable bit
volatile bit SRLEN               @ ((unsigned)&SRCON0*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	SRPR                : 1;
        unsigned	SRPS                : 1;
        unsigned	SRNQEN              : 1;
        unsigned	SRQEN               : 1;
        unsigned	SRCLK0              : 1;
        unsigned	SRCLK1              : 1;
        unsigned	SRCLK2              : 1;
        unsigned	SRLEN               : 1;
    };
    struct {
        unsigned	                    : 4;
        unsigned	SRCLK               : 3;
    };
} SRCON0bits @ 0x11A;
#endif

// Register: SRCON1
// SR Latch Control Register 1
volatile unsigned char           SRCON1              @ 0x11B;
// bit and bitfield definitions
// SR Latch C1 Reset Enable bit
volatile bit SRRC1E              @ ((unsigned)&SRCON1*8)+0;
// SR Latch C2 Reset Enable bit
volatile bit SRRC2E              @ ((unsigned)&SRCON1*8)+1;
// SR Latch Reset Clock Enable bit
volatile bit SRRCKE              @ ((unsigned)&SRCON1*8)+2;
// SR Latch Peripheral Reset Enable bit
volatile bit SRRPE               @ ((unsigned)&SRCON1*8)+3;
// SR Latch C1 Set Enable bit
volatile bit SRSC1E              @ ((unsigned)&SRCON1*8)+4;
// SR Latch C2 Set Enable bit
volatile bit SRSC2E              @ ((unsigned)&SRCON1*8)+5;
// SR Latch Set Clock Enable bit
volatile bit SRSCKE              @ ((unsigned)&SRCON1*8)+6;
// SR Latch Peripheral Set Enable bit
volatile bit SRSPE               @ ((unsigned)&SRCON1*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	SRRC1E              : 1;
        unsigned	SRRC2E              : 1;
        unsigned	SRRCKE              : 1;
        unsigned	SRRPE               : 1;
        unsigned	SRSC1E              : 1;
        unsigned	SRSC2E              : 1;
        unsigned	SRSCKE              : 1;
        unsigned	SRSPE               : 1;
    };
} SRCON1bits @ 0x11B;
#endif

// Register: APFCON
// Alternate Pin Function Control Register
volatile unsigned char           APFCON              @ 0x11D;
// bit and bitfield definitions
// CCP2 Input/Output Pin Selection
volatile bit CCP2SEL             @ ((unsigned)&APFCON*8)+0;
// SS Input Pin Selection
volatile bit SSSEL               @ ((unsigned)&APFCON*8)+1;
// Comparator 2 Output Pin Selection
volatile bit C2OUTSEL            @ ((unsigned)&APFCON*8)+2;
// SR Latch nQ Output Pin Selection
volatile bit SRNQSEL             @ ((unsigned)&APFCON*8)+3;
// CCP2 PWM B Output Pin Selection
volatile bit P2BSEL              @ ((unsigned)&APFCON*8)+4;
// Timer1 Gate Input Pin Selection
volatile bit T1GSEL              @ ((unsigned)&APFCON*8)+5;
// CCP3 Input/Output Pin Selection
volatile bit CCP3SEL             @ ((unsigned)&APFCON*8)+6;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	CCP2SEL             : 1;
        unsigned	SSSEL               : 1;
        unsigned	C2OUTSEL            : 1;
        unsigned	SRNQSEL             : 1;
        unsigned	P2BSEL              : 1;
        unsigned	T1GSEL              : 1;
        unsigned	CCP3SEL             : 1;
    };
} APFCONbits @ 0x11D;
#endif

//
// Special function register definitions: Bank 3
//


// Register: ANSELA
volatile unsigned char           ANSELA              @ 0x18C;
// bit and bitfield definitions
volatile bit ANSA0               @ ((unsigned)&ANSELA*8)+0;
volatile bit ANSA1               @ ((unsigned)&ANSELA*8)+1;
volatile bit ANSA2               @ ((unsigned)&ANSELA*8)+2;
volatile bit ANSA3               @ ((unsigned)&ANSELA*8)+3;
volatile bit ANSA4               @ ((unsigned)&ANSELA*8)+4;
volatile bit ANSA5               @ ((unsigned)&ANSELA*8)+5;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	ANSA0               : 1;
        unsigned	ANSA1               : 1;
        unsigned	ANSA2               : 1;
        unsigned	ANSA3               : 1;
        unsigned	ANSA4               : 1;
        unsigned	ANSA5               : 1;
        unsigned	                    : 1;
        unsigned	: 1;
    };
    struct {
        unsigned	ANSELA              : 6;
    };
} ANSELAbits @ 0x18C;
#endif

// Register: ANSELB
volatile unsigned char           ANSELB              @ 0x18D;
// bit and bitfield definitions
volatile bit ANSB0               @ ((unsigned)&ANSELB*8)+0;
volatile bit ANSB1               @ ((unsigned)&ANSELB*8)+1;
volatile bit ANSB2               @ ((unsigned)&ANSELB*8)+2;
volatile bit ANSB3               @ ((unsigned)&ANSELB*8)+3;
volatile bit ANSB4               @ ((unsigned)&ANSELB*8)+4;
volatile bit ANSB5               @ ((unsigned)&ANSELB*8)+5;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	ANSB0               : 1;
        unsigned	ANSB1               : 1;
        unsigned	ANSB2               : 1;
        unsigned	ANSB3               : 1;
        unsigned	ANSB4               : 1;
        unsigned	ANSB5               : 1;
        unsigned	                    : 2;
    };
    struct {
        unsigned	ANSELB              : 6;
    };
} ANSELBbits @ 0x18D;
#endif

// Register: ANSELD
volatile unsigned char           ANSELD              @ 0x18F;
// bit and bitfield definitions
volatile bit ANSD0               @ ((unsigned)&ANSELD*8)+0;
volatile bit ANSD1               @ ((unsigned)&ANSELD*8)+1;
volatile bit ANSD2               @ ((unsigned)&ANSELD*8)+2;
volatile bit ANSD3               @ ((unsigned)&ANSELD*8)+3;
volatile bit ANSD4               @ ((unsigned)&ANSELD*8)+4;
volatile bit ANSD5               @ ((unsigned)&ANSELD*8)+5;
volatile bit ANSD6               @ ((unsigned)&ANSELD*8)+6;
volatile bit ANSD7               @ ((unsigned)&ANSELD*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	ANSD0               : 1;
        unsigned	ANSD1               : 1;
        unsigned	ANSD2               : 1;
        unsigned	ANSD3               : 1;
        unsigned	ANSD4               : 1;
        unsigned	ANSD5               : 1;
        unsigned	ANSD6               : 1;
        unsigned	ANSD7               : 1;
    };
} ANSELDbits @ 0x18F;
#endif

// Register: ANSELE
volatile unsigned char           ANSELE              @ 0x190;
// bit and bitfield definitions
volatile bit ANSE0               @ ((unsigned)&ANSELE*8)+0;
volatile bit ANSE1               @ ((unsigned)&ANSELE*8)+1;
volatile bit ANSE2               @ ((unsigned)&ANSELE*8)+2;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	ANSE0               : 1;
        unsigned	ANSE1               : 1;
        unsigned	ANSE2               : 1;
        unsigned	                    : 5;
    };
    struct {
        unsigned	ANSELE              : 3;
    };
} ANSELEbits @ 0x190;
#endif
// bit and bitfield definitions

// Register: EEADRL
volatile unsigned char           EEADRL              @ 0x191;
// bit and bitfield definitions

// Register: EEADRH
volatile unsigned char           EEADRH              @ 0x192;
// bit and bitfield definitions
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	EEADRH              : 7;
    };
} EEADRHbits @ 0x192;
#endif

// Register: EEADR
volatile unsigned int            EEADR               @ 0x191;
// bit and bitfield definitions

// Register: EEDATL
volatile unsigned char           EEDATL              @ 0x193;
volatile unsigned char           EEDATA              @ 0x193;
// bit and bitfield definitions

// Register: EEDATH
volatile unsigned char           EEDATH              @ 0x194;
// bit and bitfield definitions
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	EEDATH              : 6;
    };
} EEDATHbits @ 0x194;
#endif

// Register: EEDAT
volatile unsigned int            EEDAT               @ 0x193;

// Register: EECON1
volatile unsigned char           EECON1              @ 0x195;
// bit and bitfield definitions
// Read Control bit
volatile bit RD                  @ ((unsigned)&EECON1*8)+0;
// Write Control bit
volatile bit WR                  @ ((unsigned)&EECON1*8)+1;
// Program/Erase Enable bit
volatile bit WREN                @ ((unsigned)&EECON1*8)+2;
// Sequence Error Flag bit
volatile bit WRERR               @ ((unsigned)&EECON1*8)+3;
// Program FLASH Erase Enable bit
volatile bit FREE                @ ((unsigned)&EECON1*8)+4;
// Load Write Latches Only bit
volatile bit LWLO                @ ((unsigned)&EECON1*8)+5;
// FLASH Program / Data EEPROM or Configuration Select bit
volatile bit CFGS                @ ((unsigned)&EECON1*8)+6;
// FLASH Program / Data EEPROM Memory Select bit
volatile bit EEPGD               @ ((unsigned)&EECON1*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	RD                  : 1;
        unsigned	WR                  : 1;
        unsigned	WREN                : 1;
        unsigned	WRERR               : 1;
        unsigned	FREE                : 1;
        unsigned	LWLO                : 1;
        unsigned	CFGS                : 1;
        unsigned	EEPGD               : 1;
    };
} EECON1bits @ 0x195;
#endif

// Register: EECON2
volatile unsigned char           EECON2              @ 0x196;
// bit and bitfield definitions

// Register: RCREG
volatile unsigned char           RCREG               @ 0x199;
// bit and bitfield definitions

// Register: TXREG
volatile unsigned char           TXREG               @ 0x19A;
// bit and bitfield definitions

// Register: SPBRGL
volatile unsigned char           SPBRGL              @ 0x19B;
volatile unsigned char           SPBRG               @ 0x19B;
// bit and bitfield definitions

// Register: SPBRGH
volatile unsigned char           SPBRGH              @ 0x19C;
// bit and bitfield definitions

// Register: RCSTA
// Receive Status and Control Register
volatile unsigned char           RCSTA               @ 0x19D;
// bit and bitfield definitions
// 9th bit of received data (can be parity bit)
volatile bit RX9D                @ ((unsigned)&RCSTA*8)+0;
// Overrun Error bit
volatile bit OERR                @ ((unsigned)&RCSTA*8)+1;
// Framing Error bit
volatile bit FERR                @ ((unsigned)&RCSTA*8)+2;
// Address Detect Enable bit
volatile bit ADDEN               @ ((unsigned)&RCSTA*8)+3;
// Continuous Receive Enable bit
volatile bit CREN                @ ((unsigned)&RCSTA*8)+4;
// Single Receive Enable bit
volatile bit SREN                @ ((unsigned)&RCSTA*8)+5;
// 9-bit Receive Enable bit
volatile bit RX9                 @ ((unsigned)&RCSTA*8)+6;
// Serial Port Enable bit
volatile bit SPEN                @ ((unsigned)&RCSTA*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	RX9D                : 1;
        unsigned	OERR                : 1;
        unsigned	FERR                : 1;
        unsigned	ADDEN               : 1;
        unsigned	CREN                : 1;
        unsigned	SREN                : 1;
        unsigned	RX9                 : 1;
        unsigned	SPEN                : 1;
    };
} RCSTAbits @ 0x19D;
#endif

// Register: TXSTA
// Transmit Status and Control Register
volatile unsigned char           TXSTA               @ 0x19E;
// bit and bitfield definitions
// 9th bit of transmit data; can be used as parity bit
volatile bit TX9D                @ ((unsigned)&TXSTA*8)+0;
// Transmit Operation Idle Status bit
volatile bit TRMT                @ ((unsigned)&TXSTA*8)+1;
// High Baud Rate Select bit
volatile bit BRGH                @ ((unsigned)&TXSTA*8)+2;
// Send BREAK character bit
volatile bit SENDB               @ ((unsigned)&TXSTA*8)+3;
// USART Mode Select bit
volatile bit SYNC                @ ((unsigned)&TXSTA*8)+4;
// Transmit Enable bit
volatile bit TXEN                @ ((unsigned)&TXSTA*8)+5;
// 9-bit Transmit Enable bit
volatile bit TX9                 @ ((unsigned)&TXSTA*8)+6;
// Clock Source Select bit
volatile bit CSRC                @ ((unsigned)&TXSTA*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	TX9D                : 1;
        unsigned	TRMT                : 1;
        unsigned	BRGH                : 1;
        unsigned	SENDB               : 1;
        unsigned	SYNC                : 1;
        unsigned	TXEN                : 1;
        unsigned	TX9                 : 1;
        unsigned	CSRC                : 1;
    };
} TXSTAbits @ 0x19E;
#endif

// Register: BAUDCON
// Baud Rate Control Register
volatile unsigned char           BAUDCON             @ 0x19F;
// bit and bitfield definitions
// Auto-Baud Detect Enable bit
volatile bit ABDEN               @ ((unsigned)&BAUDCON*8)+0;
// Wake-Up Enable bit
volatile bit WUE                 @ ((unsigned)&BAUDCON*8)+1;
// 16-bit Baud Rate Register enable bit
volatile bit BRG16               @ ((unsigned)&BAUDCON*8)+3;
// Clock/Transmit Polarity Select bit
volatile bit SCKP                @ ((unsigned)&BAUDCON*8)+4;
// Receive Operation Idle Status bit
volatile bit RCIDL               @ ((unsigned)&BAUDCON*8)+6;
// BRG Rollover Status bit
volatile bit ABDOVF              @ ((unsigned)&BAUDCON*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	ABDEN               : 1;
        unsigned	WUE                 : 1;
        unsigned	                    : 1;
        unsigned	BRG16               : 1;
        unsigned	SCKP                : 1;
        unsigned	: 1;
        unsigned	RCIDL               : 1;
        unsigned	ABDOVF              : 1;
    };
} BAUDCONbits @ 0x19F;
#endif

//
// Special function register definitions: Bank 4
//


// Register: WPUB
volatile unsigned char           WPUB                @ 0x20D;
// bit and bitfield definitions
volatile bit WPUB0               @ ((unsigned)&WPUB*8)+0;
volatile bit WPUB1               @ ((unsigned)&WPUB*8)+1;
volatile bit WPUB2               @ ((unsigned)&WPUB*8)+2;
volatile bit WPUB3               @ ((unsigned)&WPUB*8)+3;
volatile bit WPUB4               @ ((unsigned)&WPUB*8)+4;
volatile bit WPUB5               @ ((unsigned)&WPUB*8)+5;
volatile bit WPUB6               @ ((unsigned)&WPUB*8)+6;
volatile bit WPUB7               @ ((unsigned)&WPUB*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	WPUB0               : 1;
        unsigned	WPUB1               : 1;
        unsigned	WPUB2               : 1;
        unsigned	WPUB3               : 1;
        unsigned	WPUB4               : 1;
        unsigned	WPUB5               : 1;
        unsigned	WPUB6               : 1;
        unsigned	WPUB7               : 1;
    };
} WPUBbits @ 0x20D;
#endif

// Register: WPUE
volatile unsigned char           WPUE                @ 0x210;
// bit and bitfield definitions
volatile bit WPUE3               @ ((unsigned)&WPUE*8)+3;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	                    : 3;
        unsigned	WPUE3               : 1;
    };
} WPUEbits @ 0x210;
#endif

// Register: SSPBUF
volatile unsigned char           SSPBUF              @ 0x211;
// bit and bitfield definitions

// Register: SSPADD
volatile unsigned char           SSPADD              @ 0x212;
// bit and bitfield definitions

// Register: SSPMSK
volatile unsigned char           SSPMSK              @ 0x213;
// bit and bitfield definitions

// Register: SSPSTAT
volatile unsigned char           SSPSTAT             @ 0x214;
// bit and bitfield definitions
volatile bit BF                  @ ((unsigned)&SSPSTAT*8)+0;
volatile bit UA                  @ ((unsigned)&SSPSTAT*8)+1;
volatile bit R_nW                @ ((unsigned)&SSPSTAT*8)+2;
volatile bit S                   @ ((unsigned)&SSPSTAT*8)+3;
volatile bit P                   @ ((unsigned)&SSPSTAT*8)+4;
volatile bit D_nA                @ ((unsigned)&SSPSTAT*8)+5;
volatile bit CKE                 @ ((unsigned)&SSPSTAT*8)+6;
volatile bit SMP                 @ ((unsigned)&SSPSTAT*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	BF                  : 1;
        unsigned	UA                  : 1;
        unsigned	R_nW                : 1;
        unsigned	S                   : 1;
        unsigned	P                   : 1;
        unsigned	D_nA                : 1;
        unsigned	CKE                 : 1;
        unsigned	SMP                 : 1;
    };
} SSPSTATbits @ 0x214;
#endif

// Register: SSPCON1
volatile unsigned char           SSPCON1             @ 0x215;
volatile unsigned char           SSPCON              @ 0x215;
// bit and bitfield definitions
volatile bit SSPM0               @ ((unsigned)&SSPCON1*8)+0;
volatile bit SSPM1               @ ((unsigned)&SSPCON1*8)+1;
volatile bit SSPM2               @ ((unsigned)&SSPCON1*8)+2;
volatile bit SSPM3               @ ((unsigned)&SSPCON1*8)+3;
volatile bit CKP                 @ ((unsigned)&SSPCON1*8)+4;
volatile bit SSPEN               @ ((unsigned)&SSPCON1*8)+5;
volatile bit SSPOV               @ ((unsigned)&SSPCON1*8)+6;
volatile bit WCOL                @ ((unsigned)&SSPCON1*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	SSPM0               : 1;
        unsigned	SSPM1               : 1;
        unsigned	SSPM2               : 1;
        unsigned	SSPM3               : 1;
        unsigned	CKP                 : 1;
        unsigned	SSPEN               : 1;
        unsigned	SSPOV               : 1;
        unsigned	WCOL                : 1;
    };
} SSPCON1bits @ 0x215;
#endif

// Register: SSPCON2
volatile unsigned char           SSPCON2             @ 0x216;
// bit and bitfield definitions
volatile bit SEN                 @ ((unsigned)&SSPCON2*8)+0;
volatile bit RSEN                @ ((unsigned)&SSPCON2*8)+1;
volatile bit PEN                 @ ((unsigned)&SSPCON2*8)+2;
volatile bit RCEN                @ ((unsigned)&SSPCON2*8)+3;
volatile bit ACKEN               @ ((unsigned)&SSPCON2*8)+4;
volatile bit ACKDT               @ ((unsigned)&SSPCON2*8)+5;
volatile bit ACKSTAT             @ ((unsigned)&SSPCON2*8)+6;
volatile bit GCEN                @ ((unsigned)&SSPCON2*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	SEN                 : 1;
        unsigned	RSEN                : 1;
        unsigned	PEN                 : 1;
        unsigned	RCEN                : 1;
        unsigned	ACKEN               : 1;
        unsigned	ACKDT               : 1;
        unsigned	ACKSTAT             : 1;
        unsigned	GCEN                : 1;
    };
} SSPCON2bits @ 0x216;
#endif

// Register: SSPCON3
volatile unsigned char           SSPCON3             @ 0x217;
// bit and bitfield definitions
volatile bit DHEN                @ ((unsigned)&SSPCON3*8)+0;
volatile bit AHEN                @ ((unsigned)&SSPCON3*8)+1;
volatile bit SBCDE               @ ((unsigned)&SSPCON3*8)+2;
volatile bit SDAHT               @ ((unsigned)&SSPCON3*8)+3;
volatile bit BOEN                @ ((unsigned)&SSPCON3*8)+4;
volatile bit SCIE                @ ((unsigned)&SSPCON3*8)+5;
volatile bit PCIE                @ ((unsigned)&SSPCON3*8)+6;
volatile bit ACKTIM              @ ((unsigned)&SSPCON3*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	DHEN                : 1;
        unsigned	AHEN                : 1;
        unsigned	SBCDE               : 1;
        unsigned	SDAHT               : 1;
        unsigned	BOEN                : 1;
        unsigned	SCIE                : 1;
        unsigned	PCIE                : 1;
        unsigned	ACKTIM              : 1;
    };
} SSPCON3bits @ 0x217;
#endif

//
// Special function register definitions: Bank 5
//


// Register: CCPR1L
volatile unsigned char           CCPR1L              @ 0x291;
// bit and bitfield definitions

// Register: CCPR1H
volatile unsigned char           CCPR1H              @ 0x292;
// bit and bitfield definitions

// Register: CCP1CON
volatile unsigned char           CCP1CON             @ 0x293;
// bit and bitfield definitions
volatile bit CCP1M0              @ ((unsigned)&CCP1CON*8)+0;
volatile bit CCP1M1              @ ((unsigned)&CCP1CON*8)+1;
volatile bit CCP1M2              @ ((unsigned)&CCP1CON*8)+2;
volatile bit CCP1M3              @ ((unsigned)&CCP1CON*8)+3;
volatile bit DC1B0               @ ((unsigned)&CCP1CON*8)+4;
volatile bit DC1B1               @ ((unsigned)&CCP1CON*8)+5;
volatile bit P1M0                @ ((unsigned)&CCP1CON*8)+6;
volatile bit P1M1                @ ((unsigned)&CCP1CON*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	CCP1M0              : 1;
        unsigned	CCP1M1              : 1;
        unsigned	CCP1M2              : 1;
        unsigned	CCP1M3              : 1;
        unsigned	DC1B0               : 1;
        unsigned	DC1B1               : 1;
        unsigned	P1M0                : 1;
        unsigned	P1M1                : 1;
    };
    struct {
        unsigned	CCP1M               : 4;
        unsigned	DC1B                : 2;
        unsigned	P1M                 : 2;
    };
} CCP1CONbits @ 0x293;
#endif

// Register: PWM1CON
volatile unsigned char           PWM1CON             @ 0x294;
// bit and bitfield definitions
volatile bit P1DC0               @ ((unsigned)&PWM1CON*8)+0;
volatile bit P1DC1               @ ((unsigned)&PWM1CON*8)+1;
volatile bit P1DC2               @ ((unsigned)&PWM1CON*8)+2;
volatile bit P1DC3               @ ((unsigned)&PWM1CON*8)+3;
volatile bit P1DC4               @ ((unsigned)&PWM1CON*8)+4;
volatile bit P1DC5               @ ((unsigned)&PWM1CON*8)+5;
volatile bit P1DC6               @ ((unsigned)&PWM1CON*8)+6;
volatile bit P1RSEN              @ ((unsigned)&PWM1CON*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	P1DC0               : 1;
        unsigned	P1DC1               : 1;
        unsigned	P1DC2               : 1;
        unsigned	P1DC3               : 1;
        unsigned	P1DC4               : 1;
        unsigned	P1DC5               : 1;
        unsigned	P1DC6               : 1;
        unsigned	P1RSEN              : 1;
    };
} PWM1CONbits @ 0x294;
#endif

// Register: CCP1AS
volatile unsigned char           CCP1AS              @ 0x295;
volatile unsigned char           ECCP1AS             @ 0x295;
// bit and bitfield definitions
volatile bit PSS1BD0             @ ((unsigned)&CCP1AS*8)+0;
volatile bit PSS1BD1             @ ((unsigned)&CCP1AS*8)+1;
volatile bit PSS1AC0             @ ((unsigned)&CCP1AS*8)+2;
volatile bit PSS1AC1             @ ((unsigned)&CCP1AS*8)+3;
volatile bit CCP1AS0             @ ((unsigned)&CCP1AS*8)+4;
volatile bit CCP1AS1             @ ((unsigned)&CCP1AS*8)+5;
volatile bit CCP1AS2             @ ((unsigned)&CCP1AS*8)+6;
volatile bit CCP1ASE             @ ((unsigned)&CCP1AS*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	PSS1BD0             : 1;
        unsigned	PSS1BD1             : 1;
        unsigned	PSS1AC0             : 1;
        unsigned	PSS1AC1             : 1;
        unsigned	CCP1AS0             : 1;
        unsigned	CCP1AS1             : 1;
        unsigned	CCP1AS2             : 1;
        unsigned	CCP1ASE             : 1;
    };
} CCP1ASbits @ 0x295;
#endif

// Register: PSTR1CON
volatile unsigned char           PSTR1CON            @ 0x296;
// bit and bitfield definitions
volatile bit STR1A               @ ((unsigned)&PSTR1CON*8)+0;
volatile bit STR1B               @ ((unsigned)&PSTR1CON*8)+1;
volatile bit STR1C               @ ((unsigned)&PSTR1CON*8)+2;
volatile bit STR1D               @ ((unsigned)&PSTR1CON*8)+3;
volatile bit STR1SYNC            @ ((unsigned)&PSTR1CON*8)+4;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	STR1A               : 1;
        unsigned	STR1B               : 1;
        unsigned	STR1C               : 1;
        unsigned	STR1D               : 1;
        unsigned	STR1SYNC            : 1;
    };
} PSTR1CONbits @ 0x296;
#endif

// Register: CCPR2L
volatile unsigned char           CCPR2L              @ 0x298;
// bit and bitfield definitions

// Register: CCPR2H
volatile unsigned char           CCPR2H              @ 0x299;
// bit and bitfield definitions

// Register: CCP2CON
volatile unsigned char           CCP2CON             @ 0x29A;
// bit and bitfield definitions
volatile bit CCP2M0              @ ((unsigned)&CCP2CON*8)+0;
volatile bit CCP2M1              @ ((unsigned)&CCP2CON*8)+1;
volatile bit CCP2M2              @ ((unsigned)&CCP2CON*8)+2;
volatile bit CCP2M3              @ ((unsigned)&CCP2CON*8)+3;
volatile bit DC2B0               @ ((unsigned)&CCP2CON*8)+4;
volatile bit DC2B1               @ ((unsigned)&CCP2CON*8)+5;
volatile bit P2M0                @ ((unsigned)&CCP2CON*8)+6;
volatile bit P2M1                @ ((unsigned)&CCP2CON*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	CCP2M0              : 1;
        unsigned	CCP2M1              : 1;
        unsigned	CCP2M2              : 1;
        unsigned	CCP2M3              : 1;
        unsigned	DC2B0               : 1;
        unsigned	DC2B1               : 1;
        unsigned	P2M0                : 1;
        unsigned	P2M1                : 1;
    };
} CCP2CONbits @ 0x29A;
#endif

// Register: PWM2CON
volatile unsigned char           PWM2CON             @ 0x29B;
// bit and bitfield definitions
volatile bit P2DC0               @ ((unsigned)&PWM2CON*8)+0;
volatile bit P2DC1               @ ((unsigned)&PWM2CON*8)+1;
volatile bit P2DC2               @ ((unsigned)&PWM2CON*8)+2;
volatile bit P2DC3               @ ((unsigned)&PWM2CON*8)+3;
volatile bit P2DC4               @ ((unsigned)&PWM2CON*8)+4;
volatile bit P2DC5               @ ((unsigned)&PWM2CON*8)+5;
volatile bit P2DC6               @ ((unsigned)&PWM2CON*8)+6;
volatile bit P2RSEN              @ ((unsigned)&PWM2CON*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	P2DC0               : 1;
        unsigned	P2DC1               : 1;
        unsigned	P2DC2               : 1;
        unsigned	P2DC3               : 1;
        unsigned	P2DC4               : 1;
        unsigned	P2DC5               : 1;
        unsigned	P2DC6               : 1;
        unsigned	P2RSEN              : 1;
    };
} PWM2CONbits @ 0x29B;
#endif

// Register: CCP2AS
volatile unsigned char           CCP2AS              @ 0x29C;
volatile unsigned char           ECCP2AS             @ 0x29C;
// bit and bitfield definitions
volatile bit PSS2BD0             @ ((unsigned)&CCP2AS*8)+0;
volatile bit PSS2BD1             @ ((unsigned)&CCP2AS*8)+1;
volatile bit PSS2AC0             @ ((unsigned)&CCP2AS*8)+2;
volatile bit PSS2AC1             @ ((unsigned)&CCP2AS*8)+3;
volatile bit CCP2AS0             @ ((unsigned)&CCP2AS*8)+4;
volatile bit CCP2AS1             @ ((unsigned)&CCP2AS*8)+5;
volatile bit CCP2AS2             @ ((unsigned)&CCP2AS*8)+6;
volatile bit CCP2ASE             @ ((unsigned)&CCP2AS*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	PSS2BD0             : 1;
        unsigned	PSS2BD1             : 1;
        unsigned	PSS2AC0             : 1;
        unsigned	PSS2AC1             : 1;
        unsigned	CCP2AS0             : 1;
        unsigned	CCP2AS1             : 1;
        unsigned	CCP2AS2             : 1;
        unsigned	CCP2ASE             : 1;
    };
} CCP2ASbits @ 0x29C;
#endif

// Register: PSTR2CON
volatile unsigned char           PSTR2CON            @ 0x29D;
// bit and bitfield definitions
volatile bit STR2A               @ ((unsigned)&PSTR2CON*8)+0;
volatile bit STR2B               @ ((unsigned)&PSTR2CON*8)+1;
volatile bit STR2C               @ ((unsigned)&PSTR2CON*8)+2;
volatile bit STR2D               @ ((unsigned)&PSTR2CON*8)+3;
volatile bit STR2SYNC            @ ((unsigned)&PSTR2CON*8)+4;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	STR2A               : 1;
        unsigned	STR2B               : 1;
        unsigned	STR2C               : 1;
        unsigned	STR2D               : 1;
        unsigned	STR2SYNC            : 1;
    };
} PSTR2CONbits @ 0x29D;
#endif

// Register: CCPTMRS0
volatile unsigned char           CCPTMRS0            @ 0x29E;
// bit and bitfield definitions
volatile bit C1TSEL0             @ ((unsigned)&CCPTMRS0*8)+0;
volatile bit C1TSEL1             @ ((unsigned)&CCPTMRS0*8)+1;
volatile bit C2TSEL0             @ ((unsigned)&CCPTMRS0*8)+2;
volatile bit C2TSEL1             @ ((unsigned)&CCPTMRS0*8)+3;
volatile bit C3TSEL0             @ ((unsigned)&CCPTMRS0*8)+4;
volatile bit C3TSEL1             @ ((unsigned)&CCPTMRS0*8)+5;
volatile bit C4TSEL0             @ ((unsigned)&CCPTMRS0*8)+6;
volatile bit C4TSEL1             @ ((unsigned)&CCPTMRS0*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	C1TSEL0             : 1;
        unsigned	C1TSEL1             : 1;
        unsigned	C2TSEL0             : 1;
        unsigned	C2TSEL1             : 1;
        unsigned	C3TSEL0             : 1;
        unsigned	C3TSEL1             : 1;
        unsigned	C4TSEL0             : 1;
        unsigned	C4TSEL1             : 1;
    };
} CCPTMRS0bits @ 0x29E;
#endif

// Register: CCPTMRS1
volatile unsigned char           CCPTMRS1            @ 0x29F;
// bit and bitfield definitions
volatile bit C5TSEL0             @ ((unsigned)&CCPTMRS1*8)+0;
volatile bit C5TSEL1             @ ((unsigned)&CCPTMRS1*8)+1;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	C5TSEL0             : 1;
        unsigned	C5TSEL1             : 1;
    };
} CCPTMRS1bits @ 0x29F;
#endif

//
// Special function register definitions: Bank 6
//


// Register: CCPR3L
volatile unsigned char           CCPR3L              @ 0x311;
// bit and bitfield definitions

// Register: CCPR3H
volatile unsigned char           CCPR3H              @ 0x312;
// bit and bitfield definitions

// Register: CCP3CON
volatile unsigned char           CCP3CON             @ 0x313;
// bit and bitfield definitions
volatile bit CCP3M0              @ ((unsigned)&CCP3CON*8)+0;
volatile bit CCP3M1              @ ((unsigned)&CCP3CON*8)+1;
volatile bit CCP3M2              @ ((unsigned)&CCP3CON*8)+2;
volatile bit CCP3M3              @ ((unsigned)&CCP3CON*8)+3;
volatile bit DC3B0               @ ((unsigned)&CCP3CON*8)+4;
volatile bit DC3B1               @ ((unsigned)&CCP3CON*8)+5;
volatile bit P3M0                @ ((unsigned)&CCP3CON*8)+6;
volatile bit P3M1                @ ((unsigned)&CCP3CON*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	CCP3M0              : 1;
        unsigned	CCP3M1              : 1;
        unsigned	CCP3M2              : 1;
        unsigned	CCP3M3              : 1;
        unsigned	DC3B0               : 1;
        unsigned	DC3B1               : 1;
        unsigned	P3M0                : 1;
        unsigned	P3M1                : 1;
    };
} CCP3CONbits @ 0x313;
#endif

// Register: PWM3CON
volatile unsigned char           PWM3CON             @ 0x314;
// bit and bitfield definitions
volatile bit P3DC0               @ ((unsigned)&PWM3CON*8)+0;
volatile bit P3DC1               @ ((unsigned)&PWM3CON*8)+1;
volatile bit P3DC2               @ ((unsigned)&PWM3CON*8)+2;
volatile bit P3DC3               @ ((unsigned)&PWM3CON*8)+3;
volatile bit P3DC4               @ ((unsigned)&PWM3CON*8)+4;
volatile bit P3DC5               @ ((unsigned)&PWM3CON*8)+5;
volatile bit P3DC6               @ ((unsigned)&PWM3CON*8)+6;
volatile bit P3RSEN              @ ((unsigned)&PWM3CON*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	P3DC0               : 1;
        unsigned	P3DC1               : 1;
        unsigned	P3DC2               : 1;
        unsigned	P3DC3               : 1;
        unsigned	P3DC4               : 1;
        unsigned	P3DC5               : 1;
        unsigned	P3DC6               : 1;
        unsigned	P3RSEN              : 1;
    };
} PWM3CONbits @ 0x314;
#endif

// Register: CCP3AS
volatile unsigned char           CCP3AS              @ 0x315;
volatile unsigned char           ECCP3AS             @ 0x315;
// bit and bitfield definitions
volatile bit PSS3BD0             @ ((unsigned)&CCP3AS*8)+0;
volatile bit PSS3BD1             @ ((unsigned)&CCP3AS*8)+1;
volatile bit PSS3AC0             @ ((unsigned)&CCP3AS*8)+2;
volatile bit PSS3AC1             @ ((unsigned)&CCP3AS*8)+3;
volatile bit CCP3AS0             @ ((unsigned)&CCP3AS*8)+4;
volatile bit CCP3AS1             @ ((unsigned)&CCP3AS*8)+5;
volatile bit CCP3AS2             @ ((unsigned)&CCP3AS*8)+6;
volatile bit CCP3ASE             @ ((unsigned)&CCP3AS*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	PSS3BD0             : 1;
        unsigned	PSS3BD1             : 1;
        unsigned	PSS3AC0             : 1;
        unsigned	PSS3AC1             : 1;
        unsigned	CCP3AS0             : 1;
        unsigned	CCP3AS1             : 1;
        unsigned	CCP3AS2             : 1;
        unsigned	CCP3ASE             : 1;
    };
} CCP3ASbits @ 0x315;
#endif

// Register: PSTR3CON
volatile unsigned char           PSTR3CON            @ 0x316;
// bit and bitfield definitions
volatile bit STR3A               @ ((unsigned)&PSTR3CON*8)+0;
volatile bit STR3B               @ ((unsigned)&PSTR3CON*8)+1;
volatile bit STR3C               @ ((unsigned)&PSTR3CON*8)+2;
volatile bit STR3D               @ ((unsigned)&PSTR3CON*8)+3;
volatile bit STR3SYNC            @ ((unsigned)&PSTR3CON*8)+4;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	STR3A               : 1;
        unsigned	STR3B               : 1;
        unsigned	STR3C               : 1;
        unsigned	STR3D               : 1;
        unsigned	STR3SYNC            : 1;
    };
} PSTR3CONbits @ 0x316;
#endif

// Register: CCPR4L
volatile unsigned char           CCPR4L              @ 0x318;
// bit and bitfield definitions

// Register: CCPR4H
volatile unsigned char           CCPR4H              @ 0x319;
// bit and bitfield definitions

// Register: CCP4CON
volatile unsigned char           CCP4CON             @ 0x31A;
// bit and bitfield definitions
volatile bit CCP4M0              @ ((unsigned)&CCP4CON*8)+0;
volatile bit CCP4M1              @ ((unsigned)&CCP4CON*8)+1;
volatile bit CCP4M2              @ ((unsigned)&CCP4CON*8)+2;
volatile bit CCP4M3              @ ((unsigned)&CCP4CON*8)+3;
volatile bit DC4B0               @ ((unsigned)&CCP4CON*8)+4;
volatile bit DC4B1               @ ((unsigned)&CCP4CON*8)+5;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	CCP4M0              : 1;
        unsigned	CCP4M1              : 1;
        unsigned	CCP4M2              : 1;
        unsigned	CCP4M3              : 1;
        unsigned	DC4B0               : 1;
        unsigned	DC4B1               : 1;
        unsigned	                    : 2;
    };
} CCP4CONbits @ 0x31A;
#endif

// Register: CCPR5L
volatile unsigned char           CCPR5L              @ 0x31C;
// bit and bitfield definitions

// Register: CCPR5H
volatile unsigned char           CCPR5H              @ 0x31D;
// bit and bitfield definitions

// Register: CCP5CON
volatile unsigned char           CCP5CON             @ 0x31E;
// bit and bitfield definitions
volatile bit CCP5M0              @ ((unsigned)&CCP5CON*8)+0;
volatile bit CCP5M1              @ ((unsigned)&CCP5CON*8)+1;
volatile bit CCP5M2              @ ((unsigned)&CCP5CON*8)+2;
volatile bit CCP5M3              @ ((unsigned)&CCP5CON*8)+3;
volatile bit DC5B0               @ ((unsigned)&CCP5CON*8)+4;
volatile bit DC5B1               @ ((unsigned)&CCP5CON*8)+5;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	CCP5M0              : 1;
        unsigned	CCP5M1              : 1;
        unsigned	CCP5M2              : 1;
        unsigned	CCP5M3              : 1;
        unsigned	DC5B0               : 1;
        unsigned	DC5B1               : 1;
        unsigned	                    : 2;
    };
} CCP5CONbits @ 0x31E;
#endif

//
// Special function register definitions: Bank 7
//


// Register: IOCBP
// Interrupt-On-Change Positive Edge Register
volatile unsigned char           IOCBP               @ 0x394;
// bit and bitfield definitions
volatile bit IOCBP0              @ ((unsigned)&IOCBP*8)+0;
volatile bit IOCBP1              @ ((unsigned)&IOCBP*8)+1;
volatile bit IOCBP2              @ ((unsigned)&IOCBP*8)+2;
volatile bit IOCBP3              @ ((unsigned)&IOCBP*8)+3;
volatile bit IOCBP4              @ ((unsigned)&IOCBP*8)+4;
volatile bit IOCBP5              @ ((unsigned)&IOCBP*8)+5;
volatile bit IOCBP6              @ ((unsigned)&IOCBP*8)+6;
volatile bit IOCBP7              @ ((unsigned)&IOCBP*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	IOCBP0              : 1;
        unsigned	IOCBP1              : 1;
        unsigned	IOCBP2              : 1;
        unsigned	IOCBP3              : 1;
        unsigned	IOCBP4              : 1;
        unsigned	IOCBP5              : 1;
        unsigned	IOCBP6              : 1;
        unsigned	IOCBP7              : 1;
    };
} IOCBPbits @ 0x394;
#endif

// Register: IOCBN
// Interrupt-On-Change Negative Edge Register
volatile unsigned char           IOCBN               @ 0x395;
// bit and bitfield definitions
volatile bit IOCBN0              @ ((unsigned)&IOCBN*8)+0;
volatile bit IOCBN1              @ ((unsigned)&IOCBN*8)+1;
volatile bit IOCBN2              @ ((unsigned)&IOCBN*8)+2;
volatile bit IOCBN3              @ ((unsigned)&IOCBN*8)+3;
volatile bit IOCBN4              @ ((unsigned)&IOCBN*8)+4;
volatile bit IOCBN5              @ ((unsigned)&IOCBN*8)+5;
volatile bit IOCBN6              @ ((unsigned)&IOCBN*8)+6;
volatile bit IOCBN7              @ ((unsigned)&IOCBN*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	IOCBN0              : 1;
        unsigned	IOCBN1              : 1;
        unsigned	IOCBN2              : 1;
        unsigned	IOCBN3              : 1;
        unsigned	IOCBN4              : 1;
        unsigned	IOCBN5              : 1;
        unsigned	IOCBN6              : 1;
        unsigned	IOCBN7              : 1;
    };
} IOCBNbits @ 0x395;
#endif

// Register: IOCBF
// Interrupt-On-Change Flag Register
volatile unsigned char           IOCBF               @ 0x396;
// bit and bitfield definitions
volatile bit IOCBF0              @ ((unsigned)&IOCBF*8)+0;
volatile bit IOCBF1              @ ((unsigned)&IOCBF*8)+1;
volatile bit IOCBF2              @ ((unsigned)&IOCBF*8)+2;
volatile bit IOCBF3              @ ((unsigned)&IOCBF*8)+3;
volatile bit IOCBF4              @ ((unsigned)&IOCBF*8)+4;
volatile bit IOCBF5              @ ((unsigned)&IOCBF*8)+5;
volatile bit IOCBF6              @ ((unsigned)&IOCBF*8)+6;
volatile bit IOCBF7              @ ((unsigned)&IOCBF*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	IOCBF0              : 1;
        unsigned	IOCBF1              : 1;
        unsigned	IOCBF2              : 1;
        unsigned	IOCBF3              : 1;
        unsigned	IOCBF4              : 1;
        unsigned	IOCBF5              : 1;
        unsigned	IOCBF6              : 1;
        unsigned	IOCBF7              : 1;
    };
} IOCBFbits @ 0x396;
#endif

//
// Special function register definitions: Bank 8
//


// Register: TMR4
volatile unsigned char           TMR4                @ 0x415;
// bit and bitfield definitions

// Register: PR4
volatile unsigned char           PR4                 @ 0x416;
// bit and bitfield definitions

// Register: T4CON
// Timer2 Control Register
volatile unsigned char           T4CON               @ 0x417;
// bit and bitfield definitions
// Timer2 Clock Prescale Select bits
volatile bit T4CKPS0             @ ((unsigned)&T4CON*8)+0;
// Timer2 Clock Prescale Select bits
volatile bit T4CKPS1             @ ((unsigned)&T4CON*8)+1;
// Timer2 On bit
volatile bit TMR4ON              @ ((unsigned)&T4CON*8)+2;
// Timer2 Output Postscaler Select bits
volatile bit T4OUTPS0            @ ((unsigned)&T4CON*8)+3;
// Timer2 Output Postscaler Select bits
volatile bit T4OUTPS1            @ ((unsigned)&T4CON*8)+4;
// Timer2 Output Postscaler Select bits
volatile bit T4OUTPS2            @ ((unsigned)&T4CON*8)+5;
// Timer2 Output Postscaler Select bits
volatile bit T4OUTPS3            @ ((unsigned)&T4CON*8)+6;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	T4CKPS0             : 1;
        unsigned	T4CKPS1             : 1;
        unsigned	TMR4ON              : 1;
        unsigned	T4OUTPS0            : 1;
        unsigned	T4OUTPS1            : 1;
        unsigned	T4OUTPS2            : 1;
        unsigned	T4OUTPS3            : 1;
        unsigned	                    : 1;
    };
    struct {
        unsigned	T4CKPS              : 2;
        unsigned	: 1;
        unsigned	T4OUTPS             : 4;
    };
} T4CONbits @ 0x417;
#endif

// Register: TMR6
volatile unsigned char           TMR6                @ 0x41C;
// bit and bitfield definitions

// Register: PR6
volatile unsigned char           PR6                 @ 0x41D;
// bit and bitfield definitions

// Register: T6CON
// Timer2 Control Register
volatile unsigned char           T6CON               @ 0x41E;
// bit and bitfield definitions
// Timer2 Clock Prescale Select bits
volatile bit T6CKPS0             @ ((unsigned)&T6CON*8)+0;
// Timer2 Clock Prescale Select bits
volatile bit T6CKPS1             @ ((unsigned)&T6CON*8)+1;
// Timer2 On bit
volatile bit TMR6ON              @ ((unsigned)&T6CON*8)+2;
// Timer2 Output Postscaler Select bits
volatile bit T6OUTPS0            @ ((unsigned)&T6CON*8)+3;
// Timer2 Output Postscaler Select bits
volatile bit T6OUTPS1            @ ((unsigned)&T6CON*8)+4;
// Timer2 Output Postscaler Select bits
volatile bit T6OUTPS2            @ ((unsigned)&T6CON*8)+5;
// Timer2 Output Postscaler Select bits
volatile bit T6OUTPS3            @ ((unsigned)&T6CON*8)+6;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	T6CKPS0             : 1;
        unsigned	T6CKPS1             : 1;
        unsigned	TMR6ON              : 1;
        unsigned	T6OUTPS0            : 1;
        unsigned	T6OUTPS1            : 1;
        unsigned	T6OUTPS2            : 1;
        unsigned	T6OUTPS3            : 1;
        unsigned	                    : 1;
    };
    struct {
        unsigned	T6CKPS              : 2;
        unsigned	: 1;
        unsigned	T6OUTPS             : 4;
    };
} T6CONbits @ 0x41E;
#endif

//
// Special function register definitions: Bank 15
//


// Register: LCDCON
// LCD Control Register
volatile unsigned char           LCDCON              @ 0x791;
// bit and bitfield definitions
// Commons Selection bits
volatile bit LMUX0               @ ((unsigned)&LCDCON*8)+0;
// Commons Selection bits
volatile bit LMUX1               @ ((unsigned)&LCDCON*8)+1;
// Clock Source bits
volatile bit CS0                 @ ((unsigned)&LCDCON*8)+2;
// Clock Source bits
volatile bit CS1                 @ ((unsigned)&LCDCON*8)+3;
// Write Failed Error bit
volatile bit WERR                @ ((unsigned)&LCDCON*8)+5;
// LCD Display Sleep-Enabled bit
volatile bit SLPEN               @ ((unsigned)&LCDCON*8)+6;
// LCD Module Enable bit
volatile bit LCDEN               @ ((unsigned)&LCDCON*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	LMUX0               : 1;
        unsigned	LMUX1               : 1;
        unsigned	CS0                 : 1;
        unsigned	CS1                 : 1;
        unsigned	                    : 1;
        unsigned	WERR                : 1;
        unsigned	SLPEN               : 1;
        unsigned	LCDEN               : 1;
    };
    struct {
        unsigned	LMUX                : 2;
        unsigned	CS                  : 2;
    };
} LCDCONbits @ 0x791;
#endif

// Register: LCDPS
// LCD Phase Register
volatile unsigned char           LCDPS               @ 0x792;
// bit and bitfield definitions
// LCD Prescaler Selection bits
volatile bit LP0                 @ ((unsigned)&LCDPS*8)+0;
// LCD Prescaler Selection bits
volatile bit LP1                 @ ((unsigned)&LCDPS*8)+1;
// LCD Prescaler Selection bits
volatile bit LP2                 @ ((unsigned)&LCDPS*8)+2;
// LCD Prescaler Selection bits
volatile bit LP3                 @ ((unsigned)&LCDPS*8)+3;
// Write Allow bit
volatile bit WA                  @ ((unsigned)&LCDPS*8)+4;
// LCD Active bit
volatile bit LCDA                @ ((unsigned)&LCDPS*8)+5;
// Bias Mode Selection bit
volatile bit BIASMD              @ ((unsigned)&LCDPS*8)+6;
// Waveform Type bit
volatile bit WFT                 @ ((unsigned)&LCDPS*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	LP0                 : 1;
        unsigned	LP1                 : 1;
        unsigned	LP2                 : 1;
        unsigned	LP3                 : 1;
        unsigned	WA                  : 1;
        unsigned	LCDA                : 1;
        unsigned	BIASMD              : 1;
        unsigned	WFT                 : 1;
    };
    struct {
        unsigned	LP                  : 4;
    };
} LCDPSbits @ 0x792;
#endif

// Register: LCDREF
// LCD Reference Voltage Control Register
volatile unsigned char           LCDREF              @ 0x793;
// bit and bitfield definitions
// VLCD1 pin enable bit
volatile bit VLCD1PE             @ ((unsigned)&LCDREF*8)+1;
// VLCD2 pin enable bit
volatile bit VLCD2PE             @ ((unsigned)&LCDREF*8)+2;
// VLCD3 pin enable bit
volatile bit VLCD3PE             @ ((unsigned)&LCDREF*8)+3;
// LCD Internal Reference Ladder Idle Enable bit
volatile bit LCDIRI              @ ((unsigned)&LCDREF*8)+5;
// LCD Internal Reference Source bit
volatile bit LCDIRS              @ ((unsigned)&LCDREF*8)+6;
// LCD Internal Reference Enable bit
volatile bit LCDIRE              @ ((unsigned)&LCDREF*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	                    : 1;
        unsigned	VLCD1PE             : 1;
        unsigned	VLCD2PE             : 1;
        unsigned	VLCD3PE             : 1;
        unsigned	: 1;
        unsigned	LCDIRI              : 1;
        unsigned	LCDIRS              : 1;
        unsigned	LCDIRE              : 1;
    };
} LCDREFbits @ 0x793;
#endif

// Register: LCDCST
// LCD Contrast Control Register
volatile unsigned char           LCDCST              @ 0x794;
// bit and bitfield definitions
// LCD Contrast Control bits
volatile bit LCDCST0             @ ((unsigned)&LCDCST*8)+0;
// LCD Contrast Control bits
volatile bit LCDCST1             @ ((unsigned)&LCDCST*8)+1;
// LCD Contrast Control bits
volatile bit LCDCST2             @ ((unsigned)&LCDCST*8)+2;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	LCDCST0             : 1;
        unsigned	LCDCST1             : 1;
        unsigned	LCDCST2             : 1;
    };
    struct {
        unsigned	LCDCST              : 3;
    };
} LCDCSTbits @ 0x794;
#endif

// Register: LCDRL
// LCD Reference Voltage Control Register
volatile unsigned char           LCDRL               @ 0x795;
// bit and bitfield definitions
// LCD Reference Ladder A Time interval control bits
volatile bit LRLAT0              @ ((unsigned)&LCDRL*8)+0;
// LCD Reference Ladder A Time interval control bits
volatile bit LRLAT1              @ ((unsigned)&LCDRL*8)+1;
// LCD Reference Ladder A Time interval control bits
volatile bit LRLAT2              @ ((unsigned)&LCDRL*8)+2;
// LCD Reference Ladder B Time Power Control bits
volatile bit LRLBP0              @ ((unsigned)&LCDRL*8)+4;
// LCD Reference Ladder B Time Power Control bits
volatile bit LRLBP1              @ ((unsigned)&LCDRL*8)+5;
// LCD Reference Ladder A Time Power Control bits
volatile bit LRLAP0              @ ((unsigned)&LCDRL*8)+6;
// LCD Reference Ladder A Time Power Control bits
volatile bit LRLAP1              @ ((unsigned)&LCDRL*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	LRLAT0              : 1;
        unsigned	LRLAT1              : 1;
        unsigned	LRLAT2              : 1;
        unsigned	                    : 1;
        unsigned	LRLBP0              : 1;
        unsigned	LRLBP1              : 1;
        unsigned	LRLAP0              : 1;
        unsigned	LRLAP1              : 1;
    };
    struct {
        unsigned	LRLAT               : 3;
        unsigned	: 1;
        unsigned	LRLBP               : 2;
        unsigned	LRLAP               : 2;
    };
} LCDRLbits @ 0x795;
#endif

// Register: LCDSE0
volatile unsigned char           LCDSE0              @ 0x798;
// bit and bitfield definitions
volatile bit SEG0                @ ((unsigned)&LCDSE0*8)+0;
volatile bit SEG1                @ ((unsigned)&LCDSE0*8)+1;
volatile bit SEG2                @ ((unsigned)&LCDSE0*8)+2;
volatile bit SEG3                @ ((unsigned)&LCDSE0*8)+3;
volatile bit SEG4                @ ((unsigned)&LCDSE0*8)+4;
volatile bit SEG5                @ ((unsigned)&LCDSE0*8)+5;
volatile bit SEG6                @ ((unsigned)&LCDSE0*8)+6;
volatile bit SEG7                @ ((unsigned)&LCDSE0*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	SEG0                : 1;
        unsigned	SEG1                : 1;
        unsigned	SEG2                : 1;
        unsigned	SEG3                : 1;
        unsigned	SEG4                : 1;
        unsigned	SEG5                : 1;
        unsigned	SEG6                : 1;
        unsigned	SEG7                : 1;
    };
} LCDSE0bits @ 0x798;
#endif

// Register: LCDSE1
volatile unsigned char           LCDSE1              @ 0x799;
// bit and bitfield definitions
volatile bit SEG8                @ ((unsigned)&LCDSE1*8)+0;
volatile bit SEG9                @ ((unsigned)&LCDSE1*8)+1;
volatile bit SEG10               @ ((unsigned)&LCDSE1*8)+2;
volatile bit SEG11               @ ((unsigned)&LCDSE1*8)+3;
volatile bit SEG12               @ ((unsigned)&LCDSE1*8)+4;
volatile bit SEG13               @ ((unsigned)&LCDSE1*8)+5;
volatile bit SEG14               @ ((unsigned)&LCDSE1*8)+6;
volatile bit SEG15               @ ((unsigned)&LCDSE1*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	SEG8                : 1;
        unsigned	SEG9                : 1;
        unsigned	SEG10               : 1;
        unsigned	SEG11               : 1;
        unsigned	SEG12               : 1;
        unsigned	SEG13               : 1;
        unsigned	SEG14               : 1;
        unsigned	SEG15               : 1;
    };
} LCDSE1bits @ 0x799;
#endif

// Register: LCDSE2
volatile unsigned char           LCDSE2              @ 0x79A;
// bit and bitfield definitions
volatile bit SEG16               @ ((unsigned)&LCDSE2*8)+0;
volatile bit SEG17               @ ((unsigned)&LCDSE2*8)+1;
volatile bit SEG18               @ ((unsigned)&LCDSE2*8)+2;
volatile bit SEG19               @ ((unsigned)&LCDSE2*8)+3;
volatile bit SEG20               @ ((unsigned)&LCDSE2*8)+4;
volatile bit SEG21               @ ((unsigned)&LCDSE2*8)+5;
volatile bit SEG22               @ ((unsigned)&LCDSE2*8)+6;
volatile bit SEG23               @ ((unsigned)&LCDSE2*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	SEG16               : 1;
        unsigned	SEG17               : 1;
        unsigned	SEG18               : 1;
        unsigned	SEG19               : 1;
        unsigned	SEG20               : 1;
        unsigned	SEG21               : 1;
        unsigned	SEG22               : 1;
        unsigned	SEG23               : 1;
    };
} LCDSE2bits @ 0x79A;
#endif

// Register: LCDDATA0
volatile unsigned char           LCDDATA0            @ 0x7A0;
// bit and bitfield definitions
volatile bit SEG0COM0            @ ((unsigned)&LCDDATA0*8)+0;
volatile bit SEG1COM0            @ ((unsigned)&LCDDATA0*8)+1;
volatile bit SEG2COM0            @ ((unsigned)&LCDDATA0*8)+2;
volatile bit SEG3COM0            @ ((unsigned)&LCDDATA0*8)+3;
volatile bit SEG4COM0            @ ((unsigned)&LCDDATA0*8)+4;
volatile bit SEG5COM0            @ ((unsigned)&LCDDATA0*8)+5;
volatile bit SEG6COM0            @ ((unsigned)&LCDDATA0*8)+6;
volatile bit SEG7COM0            @ ((unsigned)&LCDDATA0*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	SEG0COM0            : 1;
        unsigned	SEG1COM0            : 1;
        unsigned	SEG2COM0            : 1;
        unsigned	SEG3COM0            : 1;
        unsigned	SEG4COM0            : 1;
        unsigned	SEG5COM0            : 1;
        unsigned	SEG6COM0            : 1;
        unsigned	SEG7COM0            : 1;
    };
} LCDDATA0bits @ 0x7A0;
#endif

// Register: LCDDATA1
volatile unsigned char           LCDDATA1            @ 0x7A1;
// bit and bitfield definitions
volatile bit SEG8COM0            @ ((unsigned)&LCDDATA1*8)+0;
volatile bit SEG9COM0            @ ((unsigned)&LCDDATA1*8)+1;
volatile bit SEG10COM0           @ ((unsigned)&LCDDATA1*8)+2;
volatile bit SEG11COM0           @ ((unsigned)&LCDDATA1*8)+3;
volatile bit SEG12COM0           @ ((unsigned)&LCDDATA1*8)+4;
volatile bit SEG13COM0           @ ((unsigned)&LCDDATA1*8)+5;
volatile bit SEG14COM0           @ ((unsigned)&LCDDATA1*8)+6;
volatile bit SEG15COM0           @ ((unsigned)&LCDDATA1*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	SEG8COM0            : 1;
        unsigned	SEG9COM0            : 1;
        unsigned	SEG10COM0           : 1;
        unsigned	SEG11COM0           : 1;
        unsigned	SEG12COM0           : 1;
        unsigned	SEG13COM0           : 1;
        unsigned	SEG14COM0           : 1;
        unsigned	SEG15COM0           : 1;
    };
} LCDDATA1bits @ 0x7A1;
#endif

// Register: LCDDATA2
volatile unsigned char           LCDDATA2            @ 0x7A2;
// bit and bitfield definitions
volatile bit SEG16COM0           @ ((unsigned)&LCDDATA2*8)+0;
volatile bit SEG17COM0           @ ((unsigned)&LCDDATA2*8)+1;
volatile bit SEG18COM0           @ ((unsigned)&LCDDATA2*8)+2;
volatile bit SEG19COM0           @ ((unsigned)&LCDDATA2*8)+3;
volatile bit SEG20COM0           @ ((unsigned)&LCDDATA2*8)+4;
volatile bit SEG21COM0           @ ((unsigned)&LCDDATA2*8)+5;
volatile bit SEG22COM0           @ ((unsigned)&LCDDATA2*8)+6;
volatile bit SEG23COM0           @ ((unsigned)&LCDDATA2*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	SEG16COM0           : 1;
        unsigned	SEG17COM0           : 1;
        unsigned	SEG18COM0           : 1;
        unsigned	SEG19COM0           : 1;
        unsigned	SEG20COM0           : 1;
        unsigned	SEG21COM0           : 1;
        unsigned	SEG22COM0           : 1;
        unsigned	SEG23COM0           : 1;
    };
} LCDDATA2bits @ 0x7A2;
#endif

// Register: LCDDATA3
volatile unsigned char           LCDDATA3            @ 0x7A3;
// bit and bitfield definitions
volatile bit SEG0COM1            @ ((unsigned)&LCDDATA3*8)+0;
volatile bit SEG1COM1            @ ((unsigned)&LCDDATA3*8)+1;
volatile bit SEG2COM1            @ ((unsigned)&LCDDATA3*8)+2;
volatile bit SEG3COM1            @ ((unsigned)&LCDDATA3*8)+3;
volatile bit SEG4COM1            @ ((unsigned)&LCDDATA3*8)+4;
volatile bit SEG5COM1            @ ((unsigned)&LCDDATA3*8)+5;
volatile bit SEG6COM1            @ ((unsigned)&LCDDATA3*8)+6;
volatile bit SEG7COM1            @ ((unsigned)&LCDDATA3*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	SEG0COM1            : 1;
        unsigned	SEG1COM1            : 1;
        unsigned	SEG2COM1            : 1;
        unsigned	SEG3COM1            : 1;
        unsigned	SEG4COM1            : 1;
        unsigned	SEG5COM1            : 1;
        unsigned	SEG6COM1            : 1;
        unsigned	SEG7COM1            : 1;
    };
} LCDDATA3bits @ 0x7A3;
#endif

// Register: LCDDATA4
volatile unsigned char           LCDDATA4            @ 0x7A4;
// bit and bitfield definitions
volatile bit SEG8COM1            @ ((unsigned)&LCDDATA4*8)+0;
volatile bit SEG9COM1            @ ((unsigned)&LCDDATA4*8)+1;
volatile bit SEG10COM1           @ ((unsigned)&LCDDATA4*8)+2;
volatile bit SEG11COM1           @ ((unsigned)&LCDDATA4*8)+3;
volatile bit SEG12COM1           @ ((unsigned)&LCDDATA4*8)+4;
volatile bit SEG13COM1           @ ((unsigned)&LCDDATA4*8)+5;
volatile bit SEG14COM1           @ ((unsigned)&LCDDATA4*8)+6;
volatile bit SEG15COM1           @ ((unsigned)&LCDDATA4*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	SEG8COM1            : 1;
        unsigned	SEG9COM1            : 1;
        unsigned	SEG10COM1           : 1;
        unsigned	SEG11COM1           : 1;
        unsigned	SEG12COM1           : 1;
        unsigned	SEG13COM1           : 1;
        unsigned	SEG14COM1           : 1;
        unsigned	SEG15COM1           : 1;
    };
} LCDDATA4bits @ 0x7A4;
#endif

// Register: LCDDATA5
volatile unsigned char           LCDDATA5            @ 0x7A5;
// bit and bitfield definitions
volatile bit SEG16COM1           @ ((unsigned)&LCDDATA5*8)+0;
volatile bit SEG17COM1           @ ((unsigned)&LCDDATA5*8)+1;
volatile bit SEG18COM1           @ ((unsigned)&LCDDATA5*8)+2;
volatile bit SEG19COM1           @ ((unsigned)&LCDDATA5*8)+3;
volatile bit SEG20COM1           @ ((unsigned)&LCDDATA5*8)+4;
volatile bit SEG21COM1           @ ((unsigned)&LCDDATA5*8)+5;
volatile bit SEG22COM1           @ ((unsigned)&LCDDATA5*8)+6;
volatile bit SEG23COM1           @ ((unsigned)&LCDDATA5*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	SEG16COM1           : 1;
        unsigned	SEG17COM1           : 1;
        unsigned	SEG18COM1           : 1;
        unsigned	SEG19COM1           : 1;
        unsigned	SEG20COM1           : 1;
        unsigned	SEG21COM1           : 1;
        unsigned	SEG22COM1           : 1;
        unsigned	SEG23COM1           : 1;
    };
} LCDDATA5bits @ 0x7A5;
#endif

// Register: LCDDATA6
volatile unsigned char           LCDDATA6            @ 0x7A6;
// bit and bitfield definitions
volatile bit SEG0COM2            @ ((unsigned)&LCDDATA6*8)+0;
volatile bit SEG1COM2            @ ((unsigned)&LCDDATA6*8)+1;
volatile bit SEG2COM2            @ ((unsigned)&LCDDATA6*8)+2;
volatile bit SEG3COM2            @ ((unsigned)&LCDDATA6*8)+3;
volatile bit SEG4COM2            @ ((unsigned)&LCDDATA6*8)+4;
volatile bit SEG5COM2            @ ((unsigned)&LCDDATA6*8)+5;
volatile bit SEG6COM2            @ ((unsigned)&LCDDATA6*8)+6;
volatile bit SEG7COM2            @ ((unsigned)&LCDDATA6*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	SEG0COM2            : 1;
        unsigned	SEG1COM2            : 1;
        unsigned	SEG2COM2            : 1;
        unsigned	SEG3COM2            : 1;
        unsigned	SEG4COM2            : 1;
        unsigned	SEG5COM2            : 1;
        unsigned	SEG6COM2            : 1;
        unsigned	SEG7COM2            : 1;
    };
} LCDDATA6bits @ 0x7A6;
#endif

// Register: LCDDATA7
volatile unsigned char           LCDDATA7            @ 0x7A7;
// bit and bitfield definitions
volatile bit SEG8COM2            @ ((unsigned)&LCDDATA7*8)+0;
volatile bit SEG9COM2            @ ((unsigned)&LCDDATA7*8)+1;
volatile bit SEG10COM2           @ ((unsigned)&LCDDATA7*8)+2;
volatile bit SEG11COM2           @ ((unsigned)&LCDDATA7*8)+3;
volatile bit SEG12COM2           @ ((unsigned)&LCDDATA7*8)+4;
volatile bit SEG13COM2           @ ((unsigned)&LCDDATA7*8)+5;
volatile bit SEG14COM2           @ ((unsigned)&LCDDATA7*8)+6;
volatile bit SEG15COM2           @ ((unsigned)&LCDDATA7*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	SEG8COM2            : 1;
        unsigned	SEG9COM2            : 1;
        unsigned	SEG10COM2           : 1;
        unsigned	SEG11COM2           : 1;
        unsigned	SEG12COM2           : 1;
        unsigned	SEG13COM2           : 1;
        unsigned	SEG14COM2           : 1;
        unsigned	SEG15COM2           : 1;
    };
} LCDDATA7bits @ 0x7A7;
#endif

// Register: LCDDATA8
volatile unsigned char           LCDDATA8            @ 0x7A8;
// bit and bitfield definitions
volatile bit SEG16COM2           @ ((unsigned)&LCDDATA8*8)+0;
volatile bit SEG17COM2           @ ((unsigned)&LCDDATA8*8)+1;
volatile bit SEG18COM2           @ ((unsigned)&LCDDATA8*8)+2;
volatile bit SEG19COM2           @ ((unsigned)&LCDDATA8*8)+3;
volatile bit SEG20COM2           @ ((unsigned)&LCDDATA8*8)+4;
volatile bit SEG21COM2           @ ((unsigned)&LCDDATA8*8)+5;
volatile bit SEG22COM2           @ ((unsigned)&LCDDATA8*8)+6;
volatile bit SEG23COM2           @ ((unsigned)&LCDDATA8*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	SEG16COM2           : 1;
        unsigned	SEG17COM2           : 1;
        unsigned	SEG18COM2           : 1;
        unsigned	SEG19COM2           : 1;
        unsigned	SEG20COM2           : 1;
        unsigned	SEG21COM2           : 1;
        unsigned	SEG22COM2           : 1;
        unsigned	SEG23COM2           : 1;
    };
} LCDDATA8bits @ 0x7A8;
#endif

// Register: LCDDATA9
volatile unsigned char           LCDDATA9            @ 0x7A9;
// bit and bitfield definitions
volatile bit SEG0COM3            @ ((unsigned)&LCDDATA9*8)+0;
volatile bit SEG1COM3            @ ((unsigned)&LCDDATA9*8)+1;
volatile bit SEG2COM3            @ ((unsigned)&LCDDATA9*8)+2;
volatile bit SEG3COM3            @ ((unsigned)&LCDDATA9*8)+3;
volatile bit SEG4COM3            @ ((unsigned)&LCDDATA9*8)+4;
volatile bit SEG5COM3            @ ((unsigned)&LCDDATA9*8)+5;
volatile bit SEG6COM3            @ ((unsigned)&LCDDATA9*8)+6;
volatile bit SEG7COM3            @ ((unsigned)&LCDDATA9*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	SEG0COM3            : 1;
        unsigned	SEG1COM3            : 1;
        unsigned	SEG2COM3            : 1;
        unsigned	SEG3COM3            : 1;
        unsigned	SEG4COM3            : 1;
        unsigned	SEG5COM3            : 1;
        unsigned	SEG6COM3            : 1;
        unsigned	SEG7COM3            : 1;
    };
} LCDDATA9bits @ 0x7A9;
#endif

// Register: LCDDATA10
volatile unsigned char           LCDDATA10           @ 0x7AA;
// bit and bitfield definitions
volatile bit SEG8COM3            @ ((unsigned)&LCDDATA10*8)+0;
volatile bit SEG9COM3            @ ((unsigned)&LCDDATA10*8)+1;
volatile bit SEG10COM3           @ ((unsigned)&LCDDATA10*8)+2;
volatile bit SEG11COM3           @ ((unsigned)&LCDDATA10*8)+3;
volatile bit SEG12COM3           @ ((unsigned)&LCDDATA10*8)+4;
volatile bit SEG13COM3           @ ((unsigned)&LCDDATA10*8)+5;
volatile bit SEG14COM3           @ ((unsigned)&LCDDATA10*8)+6;
volatile bit SEG15COM3           @ ((unsigned)&LCDDATA10*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	SEG8COM3            : 1;
        unsigned	SEG9COM3            : 1;
        unsigned	SEG10COM3           : 1;
        unsigned	SEG11COM3           : 1;
        unsigned	SEG12COM3           : 1;
        unsigned	SEG13COM3           : 1;
        unsigned	SEG14COM3           : 1;
        unsigned	SEG15COM3           : 1;
    };
} LCDDATA10bits @ 0x7AA;
#endif

// Register: LCDDATA11
volatile unsigned char           LCDDATA11           @ 0x7AB;
// bit and bitfield definitions
volatile bit SEG16COM3           @ ((unsigned)&LCDDATA11*8)+0;
volatile bit SEG17COM3           @ ((unsigned)&LCDDATA11*8)+1;
volatile bit SEG18COM3           @ ((unsigned)&LCDDATA11*8)+2;
volatile bit SEG19COM3           @ ((unsigned)&LCDDATA11*8)+3;
volatile bit SEG20COM3           @ ((unsigned)&LCDDATA11*8)+4;
volatile bit SEG21COM3           @ ((unsigned)&LCDDATA11*8)+5;
volatile bit SEG22COM3           @ ((unsigned)&LCDDATA11*8)+6;
volatile bit SEG23COM3           @ ((unsigned)&LCDDATA11*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	SEG16COM3           : 1;
        unsigned	SEG17COM3           : 1;
        unsigned	SEG18COM3           : 1;
        unsigned	SEG19COM3           : 1;
        unsigned	SEG20COM3           : 1;
        unsigned	SEG21COM3           : 1;
        unsigned	SEG22COM3           : 1;
        unsigned	SEG23COM3           : 1;
    };
} LCDDATA11bits @ 0x7AB;
#endif

//
// Special function register definitions: Bank 31
//


// Register: STATUS_SHAD
volatile unsigned char           STATUS_SHAD         @ 0xFE4;
// bit and bitfield definitions
volatile bit C_SHAD              @ ((unsigned)&STATUS_SHAD*8)+0;
volatile bit DC_SHAD             @ ((unsigned)&STATUS_SHAD*8)+1;
volatile bit Z_SHAD              @ ((unsigned)&STATUS_SHAD*8)+2;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	C_SHAD              : 1;
        unsigned	DC_SHAD             : 1;
        unsigned	Z_SHAD              : 1;
    };
} STATUS_SHADbits @ 0xFE4;
#endif

// Register: WREG_SHAD
volatile unsigned char           WREG_SHAD           @ 0xFE5;
// bit and bitfield definitions

// Register: BSR_SHAD
volatile unsigned char           BSR_SHAD            @ 0xFE6;
// bit and bitfield definitions
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	BSR_SHAD            : 5;
    };
} BSR_SHADbits @ 0xFE6;
#endif

// Register: PCLATH_SHAD
volatile unsigned char           PCLATH_SHAD         @ 0xFE7;
// bit and bitfield definitions
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	PCLATH_SHAD         : 7;
    };
} PCLATH_SHADbits @ 0xFE7;
#endif

// Register: FSR0L_SHAD
volatile unsigned char           FSR0L_SHAD          @ 0xFE8;
// bit and bitfield definitions

// Register: FSR0H_SHAD
volatile unsigned char           FSR0H_SHAD          @ 0xFE9;
// bit and bitfield definitions

// Register: FSR1L_SHAD
volatile unsigned char           FSR1L_SHAD          @ 0xFEA;
// bit and bitfield definitions

// Register: FSR1H_SHAD
volatile unsigned char           FSR1H_SHAD          @ 0xFEB;
// bit and bitfield definitions

// Register: STKPTR
// Current Stack pointer
volatile unsigned char           STKPTR              @ 0xFED;
// bit and bitfield definitions
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	STKPTR              : 5;
    };
} STKPTRbits @ 0xFED;
#endif

// Register: TOSL
// Top of Stack Low byte
volatile unsigned char           TOSL                @ 0xFEE;
// bit and bitfield definitions

// Register: TOSH
// Top of Stack High byte
volatile unsigned char           TOSH                @ 0xFEF;
// bit and bitfield definitions
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	TOSH                : 7;
    };
} TOSHbits @ 0xFEF;
#endif

#endif
