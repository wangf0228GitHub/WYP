opt subtitle "HI-TECH Software Omniscient Code Generator (PRO mode) build 6446"

opt pagewidth 120

	opt pm

	processor	16F1937
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
DABS 1,800,16	;_ATCommand_RxList
DABS 1,672,80	;_ATCommand_RxList
DABS 1,620,4	;_ATCommand_RxList
	FNCALL	_main,_InitSystem
	FNCALL	_main,___delay_20ms
	FNCALL	_main,_TestProc
	FNCALL	_main,_ReadTData
	FNCALL	_main,_CallProc
	FNCALL	_main,___bmul
	FNCALL	_main,_eeprom_write
	FNCALL	_TestProc,_LcdDisplayAll
	FNCALL	_TestProc,___delay_20ms
	FNCALL	_TestProc,_ReadTData
	FNCALL	_TestProc,_LcdDisplay_Err
	FNCALL	_TestProc,_CallTestProc
	FNCALL	_CallTestProc,_PowerON
	FNCALL	_CallTestProc,_CallTestSend
	FNCALL	_CallTestProc,_PowerDown
	FNCALL	_CallTestProc,_LcdDisplay_CurTemp
	FNCALL	_CallTestProc,___delay_20ms
	FNCALL	_CallTestProc,_LcdDisplay_Err
	FNCALL	_CallProc,_PowerON
	FNCALL	_CallProc,_CallSend
	FNCALL	_CallProc,_PowerDown
	FNCALL	_CallProc,_LcdDisplay_CurTemp
	FNCALL	_CallProc,___delay_20ms
	FNCALL	_CallProc,_LcdDisplay_Err
	FNCALL	_InitSystem,_InitMCU
	FNCALL	_InitSystem,_InitVariable
	FNCALL	_InitSystem,_DisplayInit
	FNCALL	_InitSystem,_ATCommand_Init
	FNCALL	_InitSystem,_OneWire_Reset
	FNCALL	_InitSystem,_TCN75_Init
	FNCALL	_InitSystem,_TCN75_SetConfig
	FNCALL	_InitSystem,___delay_20ms
	FNCALL	_InitSystem,_ReadTData
	FNCALL	_CallTestSend,_InitGPRS
	FNCALL	_CallTestSend,_ATCommand_SendCmd
	FNCALL	_CallTestSend,_strcpy
	FNCALL	_CallTestSend,___delay_20ms
	FNCALL	_CallTestSend,_InteractServer
	FNCALL	_CallTestSend,_strstr
	FNCALL	_CallSend,_InitGPRS
	FNCALL	_CallSend,___delay_20ms
	FNCALL	_CallSend,_ATCommand_SendCmd
	FNCALL	_CallSend,_strcpy
	FNCALL	_CallSend,_InteractServer
	FNCALL	_CallSend,_strstr
	FNCALL	_CallSend,_SaveRomData
	FNCALL	_ReadTData,_DS18X20_StartMeas
	FNCALL	_ReadTData,___delay_20ms
	FNCALL	_ReadTData,_DS18X20_ReadMeas
	FNCALL	_ReadTData,_TCN75_SetConfig
	FNCALL	_ReadTData,_TCN75_ReadReg
	FNCALL	_ReadTData,_LcdDisplay_CurTemp
	FNCALL	_InteractServer,_strcpy
	FNCALL	_InteractServer,_ATCommand_SendCmd
	FNCALL	_InteractServer,_Uart1_PutChar
	FNCALL	_InteractServer,_Uart1_PutString
	FNCALL	_InteractServer,_MakeTxTemperature
	FNCALL	_InteractServer,___bmul
	FNCALL	_InteractServer,_eeprom_read
	FNCALL	_InteractServer,_ATCommand_WaitData
	FNCALL	_InteractServer,___delay_20ms
	FNCALL	_InitGPRS,___delay_20ms
	FNCALL	_InitGPRS,_ATCommand_SendCmd
	FNCALL	_InitGPRS,_Uart1_PutChar
	FNCALL	_InitGPRS,_strstr
	FNCALL	_InitGPRS,_atoi
	FNCALL	_InitGPRS,_LcdDisplay_CSQ
	FNCALL	_PowerON,_PowerDown
	FNCALL	_PowerON,___delay_20ms
	FNCALL	_PowerON,_ATCommand_SendCmd
	FNCALL	_DS18X20_ReadMeas,_OneWire_Reset
	FNCALL	_DS18X20_ReadMeas,_OneWire_Command
	FNCALL	_DS18X20_ReadMeas,_OneWire_ReadByte
	FNCALL	_DS18X20_ReadMeas,_GetVerify_CRC8
	FNCALL	_DS18X20_StartMeas,_OneWire_Reset
	FNCALL	_DS18X20_StartMeas,_OneWire_Command
	FNCALL	_OneWire_Command,_OneWire_Reset
	FNCALL	_OneWire_Command,_OneWire_WriteByte
	FNCALL	_ATCommand_WaitData,_strstr
	FNCALL	_ATCommand_WaitData,_strcpy
	FNCALL	_ATCommand_SendCmd,_Uart1_PutString
	FNCALL	_ATCommand_SendCmd,_strstr
	FNCALL	_ATCommand_SendCmd,___delay_20ms
	FNCALL	_ATCommand_SendCmd,_strcpy
	FNCALL	_PowerDown,___delay_20ms
	FNCALL	_TCN75_ReadReg,_SimI2C_Start
	FNCALL	_TCN75_ReadReg,_SimI2C_SendByte
	FNCALL	_TCN75_ReadReg,_SimI2C_RecAck
	FNCALL	_TCN75_ReadReg,_SimI2C_ReadByte
	FNCALL	_TCN75_ReadReg,_SimI2C_Ack
	FNCALL	_TCN75_ReadReg,_SimI2C_NoAck
	FNCALL	_TCN75_ReadReg,_SimI2C_Stop
	FNCALL	_TCN75_SetConfig,_SimI2C_Start
	FNCALL	_TCN75_SetConfig,_SimI2C_SendByte
	FNCALL	_TCN75_SetConfig,_SimI2C_RecAck
	FNCALL	_TCN75_SetConfig,_SimI2C_Stop
	FNCALL	_InitVariable,_GetRomData
	FNCALL	_InitVariable,_SaveRomData
	FNCALL	_atoi,___wmul
	FNCALL	_atoi,_isdigit
	FNCALL	_Uart1_PutString,_Uart1_PutChar
	FNCALL	_strstr,_strlen
	FNCALL	_strstr,_strncmp
	FNCALL	_strstr,_strchr
	FNCALL	_TCN75_Init,_SimI2C_Init
	FNCALL	_ATCommand_Init,_strcpy
	FNCALL	_SaveRomData,_GetVerify_Sum
	FNCALL	_SaveRomData,_eeprom_write
	FNCALL	_GetRomData,_eeprom_read
	FNCALL	_GetRomData,_GetVerify_Sum
	FNCALL	_LcdDisplay_Err,___lbdiv
	FNCALL	_LcdDisplay_Err,___lbmod
	FNCALL	_LcdDisplay_Err,_LcdDisplayNum
	FNCALL	_LcdDisplay_CurTemp,___lbdiv
	FNCALL	_LcdDisplay_CurTemp,___lbmod
	FNCALL	_LcdDisplay_CurTemp,_LcdDisplayNum
	FNCALL	_LcdDisplay_CSQ,___lbdiv
	FNCALL	_LcdDisplay_CSQ,___lbmod
	FNCALL	_LcdDisplay_CSQ,_LcdDisplayNum
	FNCALL	_LcdDisplayAll,_LcdDisplayNum
	FNROOT	_main
	FNCALL	_highISR,_ATCommand_ProcRx
	FNCALL	_ATCommand_ProcRx,_isgraph
	FNCALL	intlevel1,_highISR
	global	intlevel1
	FNROOT	intlevel1
	global	_DpyNum
psect	idataBANK0,class=CODE,space=0,delta=2
global __pidataBANK0
__pidataBANK0:
	file	"F:\work\WYP\NBIoT\Display.c"
	line	5

;initializer for _DpyNum
	retlw	040h
	retlw	040h
	retlw	040h
	retlw	040h
	retlw	040h
	retlw	040h
	global	_SegCode
psect	stringtext,class=STRCODE,delta=2,reloc=256
global __pstringtext
__pstringtext:
	global    __stringtab
__stringtab:
	retlw	0
psect	stringtext
	file	"F:\work\WYP\NBIoT\Display.h"
	line	78
_SegCode:
	retlw	03Fh
	retlw	06h
	retlw	05Bh
	retlw	04Fh
	retlw	066h
	retlw	06Dh
	retlw	07Dh
	retlw	07h
	retlw	07Fh
	retlw	06Fh
	retlw	077h
	retlw	07Ch
	retlw	039h
	retlw	05Eh
	retlw	079h
	retlw	071h
	retlw	050h
	global	_DS18X20_ToDecicel
psect	stringtext
	file	"F:\work\WYP\NBIoT\DS18x20.h"
	line	68
_DS18X20_ToDecicel:
	retlw	0
	retlw	01h
	retlw	01h
	retlw	02h
	retlw	03h
	retlw	03h
	retlw	04h
	retlw	04h
	retlw	05h
	retlw	06h
	retlw	06h
	retlw	07h
	retlw	08h
	retlw	08h
	retlw	09h
	retlw	09h
	global	_SegCode
	global	_DS18X20_ToDecicel
	global	_TxTemperature
	global	_ATCommand_WaitACKTick
	global	_ATCommand_WaitACKTimes
	global	_CurTemp
	global	_SystemTick
	global	_TCN75_RegReadResualt
	global	_ATCommand_RetryTimes
	global	_CSQ
	global	_ErrState
	global	_TCN75_Config
	global	_TListIndex
	global	_gFlags
	global	_TList
	global	_MeasurementTick
	global	_NeedMeasurementTick
	global	_ATCommand_Clear
	global	_ATCommand_Flags
	global	_ATCommand_RxCount
	global	_RunTick
	global	_RomParams
	global	_TxErrDataIndex
	global	_ATCommand_RxList
	global	_ICCID
	global	_ATCommand_ErrString
	global	_ATCommand_OkString
	global	_DS18X20_Scratchpad
	global	_PR2
_PR2	set	27
	global	_T1CON
_T1CON	set	24
	global	_T2CON
_T2CON	set	28
	global	_TMR1H
_TMR1H	set	23
	global	_TMR1L
_TMR1L	set	22
	global	_CARRY
_CARRY	set	24
	global	_GIE
_GIE	set	95
	global	_PEIE
_PEIE	set	94
	global	_RB1
_RB1	set	105
	global	_RB2
_RB2	set	106
	global	_RB7
_RB7	set	111
	global	_RCIF
_RCIF	set	141
	global	_RD4
_RD4	set	124
	global	_RD6
_RD6	set	126
	global	_TMR1IF
_TMR1IF	set	136
	global	_TMR1ON
_TMR1ON	set	192
	global	_TMR2IF
_TMR2IF	set	137
	global	_TMR2ON
_TMR2ON	set	226
	global	_ADCON1
_ADCON1	set	158
	global	_RCIE
_RCIE	set	1165
	global	_TMR1IE
_TMR1IE	set	1160
	global	_TMR2IE
_TMR2IE	set	1161
	global	_TRISA3
_TRISA3	set	1123
	global	_TRISA4
_TRISA4	set	1124
	global	_TRISB1
_TRISB1	set	1129
	global	_TRISB2
_TRISB2	set	1130
	global	_TRISB7
_TRISB7	set	1135
	global	_TRISC6
_TRISC6	set	1142
	global	_TRISC7
_TRISC7	set	1143
	global	_TRISD4
_TRISD4	set	1148
	global	_TRISD5
_TRISD5	set	1149
	global	_TRISD6
_TRISD6	set	1150
	global	_TRISD7
_TRISD7	set	1151
	global	_nWPUEN
_nWPUEN	set	1199
	global	_LATA3
_LATA3	set	2147
	global	_LATA4
_LATA4	set	2148
	global	_LATB1
_LATB1	set	2153
	global	_LATD5
_LATD5	set	2173
	global	_LATD6
_LATD6	set	2174
	global	_LATD7
_LATD7	set	2175
	global	_ANSELA
_ANSELA	set	396
	global	_ANSELB
_ANSELB	set	397
	global	_ANSELD
_ANSELD	set	399
	global	_ANSELE
_ANSELE	set	400
	global	_EEADRL
_EEADRL	set	401
	global	_EECON1
_EECON1	set	405
	global	_EECON2
_EECON2	set	406
	global	_EEDATA
_EEDATA	set	403
	global	_RCREG
_RCREG	set	409
	global	_RCSTA
_RCSTA	set	413
	global	_SPBRG
_SPBRG	set	411
	global	_TXREG
_TXREG	set	410
	global	_TXSTA
_TXSTA	set	414
	global	_CREN
_CREN	set	3308
	global	_OERR
_OERR	set	3305
	global	_RD
_RD	set	3240
	global	_TRMT
_TRMT	set	3313
	global	_WR
_WR	set	3241
	global	_WREN
_WREN	set	3242
	global	_WPUB7
_WPUB7	set	4207
	global	_LCDCON
_LCDCON	set	1937
	global	_LCDCST
_LCDCST	set	1940
	global	_LCDDATA0
_LCDDATA0	set	1952
	global	_LCDDATA1
_LCDDATA1	set	1953
	global	_LCDDATA10
_LCDDATA10	set	1962
	global	_LCDDATA11
_LCDDATA11	set	1963
	global	_LCDDATA2
_LCDDATA2	set	1954
	global	_LCDDATA3
_LCDDATA3	set	1955
	global	_LCDDATA4
_LCDDATA4	set	1956
	global	_LCDDATA5
_LCDDATA5	set	1957
	global	_LCDDATA6
_LCDDATA6	set	1958
	global	_LCDDATA7
_LCDDATA7	set	1959
	global	_LCDDATA8
_LCDDATA8	set	1960
	global	_LCDDATA9
_LCDDATA9	set	1961
	global	_LCDPS
_LCDPS	set	1938
	global	_LCDREF
_LCDREF	set	1939
	global	_LCDRL
_LCDRL	set	1941
	global	_LCDSE0
_LCDSE0	set	1944
	global	_LCDSE1
_LCDSE1	set	1945
	global	_LCDSE2
_LCDSE2	set	1946
	global	_LCDEN
_LCDEN	set	15503
	global	_SEG11
_SEG11	set	15563
	global	_SEG11COM0
_SEG11COM0	set	15627
	global	_SEG11COM1
_SEG11COM1	set	15651
	global	_SEG11COM2
_SEG11COM2	set	15675
	global	_SEG11COM3
_SEG11COM3	set	15699
	global	_SEG16
_SEG16	set	15568
	global	_SEG16COM0
_SEG16COM0	set	15632
	global	_SEG16COM1
_SEG16COM1	set	15656
	global	_SEG16COM2
_SEG16COM2	set	15680
	global	_SEG16COM3
_SEG16COM3	set	15704
	global	_SEG21
_SEG21	set	15573
	global	_SEG21COM0
_SEG21COM0	set	15637
	global	_SEG21COM1
_SEG21COM1	set	15661
	global	_SEG21COM2
_SEG21COM2	set	15685
	global	_SEG21COM3
_SEG21COM3	set	15709
	global	_SEG22
_SEG22	set	15574
	global	_SEG22COM0
_SEG22COM0	set	15638
	global	_SEG22COM1
_SEG22COM1	set	15662
	global	_SEG22COM2
_SEG22COM2	set	15686
	global	_SEG22COM3
_SEG22COM3	set	15710
	global	_SEG23
_SEG23	set	15575
	global	_SEG23COM0
_SEG23COM0	set	15639
	global	_SEG23COM1
_SEG23COM1	set	15663
	global	_SEG23COM2
_SEG23COM2	set	15687
	global	_SEG23COM3
_SEG23COM3	set	15711
	global	_SEG3
_SEG3	set	15555
	global	_SEG3COM0
_SEG3COM0	set	15619
	global	_SEG3COM1
_SEG3COM1	set	15643
	global	_SEG3COM2
_SEG3COM2	set	15667
	global	_SEG3COM3
_SEG3COM3	set	15691
	global	_SEG5
_SEG5	set	15557
	global	_SEG5COM0
_SEG5COM0	set	15621
	global	_SEG5COM1
_SEG5COM1	set	15645
	global	_SEG5COM2
_SEG5COM2	set	15669
	global	_SEG5COM3
_SEG5COM3	set	15693
	global	_SEG6
_SEG6	set	15558
	global	_SEG6COM0
_SEG6COM0	set	15622
	global	_SEG6COM1
_SEG6COM1	set	15646
	global	_SEG6COM2
_SEG6COM2	set	15670
	global	_SEG6COM3
_SEG6COM3	set	15694
	global	_WA
_WA	set	15508
	global	_WERR
_WERR	set	15501
	
STR_3:	
	retlw	65	;'A'
	retlw	84	;'T'
	retlw	43	;'+'
	retlw	67	;'C'
	retlw	73	;'I'
	retlw	80	;'P'
	retlw	83	;'S'
	retlw	84	;'T'
	retlw	65	;'A'
	retlw	82	;'R'
	retlw	84	;'T'
	retlw	61	;'='
	retlw	34	;'"'
	retlw	84	;'T'
	retlw	67	;'C'
	retlw	80	;'P'
	retlw	34	;'"'
	retlw	44	;','
	retlw	34	;'"'
	retlw	119	;'w'
	retlw	119	;'w'
	retlw	119	;'w'
	retlw	46	;'.'
	retlw	119	;'w'
	retlw	108	;'l'
	retlw	119	;'w'
	retlw	100	;'d'
	retlw	106	;'j'
	retlw	99	;'c'
	retlw	121	;'y'
	retlw	46	;'.'
	retlw	99	;'c'
	retlw	111	;'o'
	retlw	109	;'m'
	retlw	34	;'"'
	retlw	44	;','
	retlw	34	;'"'
	retlw	49	;'1'
	retlw	50	;'2'
	retlw	49	;'1'
	retlw	50	;'2'
	retlw	56	;'8'
	retlw	34	;'"'
	retlw	0
	retlw	0
psect	stringtext
	
STR_35:	
	retlw	65	;'A'
	retlw	84	;'T'
	retlw	43	;'+'
	retlw	67	;'C'
	retlw	83	;'S'
	retlw	84	;'T'
	retlw	84	;'T'
	retlw	61	;'='
	retlw	34	;'"'
	retlw	85	;'U'
	retlw	78	;'N'
	retlw	73	;'I'
	retlw	77	;'M'
	retlw	50	;'2'
	retlw	77	;'M'
	retlw	46	;'.'
	retlw	78	;'N'
	retlw	74	;'J'
	retlw	77	;'M'
	retlw	50	;'2'
	retlw	77	;'M'
	retlw	65	;'A'
	retlw	80	;'P'
	retlw	78	;'N'
	retlw	34	;'"'
	retlw	44	;','
	retlw	34	;'"'
	retlw	34	;'"'
	retlw	44	;','
	retlw	34	;'"'
	retlw	34	;'"'
	retlw	0
	retlw	0
psect	stringtext
	
STR_36:	
	retlw	65	;'A'
	retlw	84	;'T'
	retlw	43	;'+'
	retlw	67	;'C'
	retlw	83	;'S'
	retlw	84	;'T'
	retlw	84	;'T'
	retlw	61	;'='
	retlw	34	;'"'
	retlw	67	;'C'
	retlw	77	;'M'
	retlw	77	;'M'
	retlw	84	;'T'
	retlw	77	;'M'
	retlw	34	;'"'
	retlw	44	;','
	retlw	34	;'"'
	retlw	34	;'"'
	retlw	44	;','
	retlw	34	;'"'
	retlw	34	;'"'
	retlw	0
	retlw	0
psect	stringtext
	
STR_6:	
	retlw	65	;'A'
	retlw	84	;'T'
	retlw	43	;'+'
	retlw	67	;'C'
	retlw	73	;'I'
	retlw	80	;'P'
	retlw	67	;'C'
	retlw	76	;'L'
	retlw	79	;'O'
	retlw	83	;'S'
	retlw	69	;'E'
	retlw	61	;'='
	retlw	49	;'1'
	retlw	0
	retlw	0
psect	stringtext
	
STR_4:	
	retlw	65	;'A'
	retlw	84	;'T'
	retlw	43	;'+'
	retlw	67	;'C'
	retlw	73	;'I'
	retlw	80	;'P'
	retlw	83	;'S'
	retlw	84	;'T'
	retlw	65	;'A'
	retlw	82	;'R'
	retlw	84	;'T'
	retlw	61	;'='
	retlw	63	;'?'
	retlw	0
	retlw	0
psect	stringtext
	
STR_1:	
	retlw	65	;'A'
	retlw	84	;'T'
	retlw	43	;'+'
	retlw	67	;'C'
	retlw	73	;'I'
	retlw	80	;'P'
	retlw	83	;'S'
	retlw	84	;'T'
	retlw	65	;'A'
	retlw	84	;'T'
	retlw	85	;'U'
	retlw	83	;'S'
	retlw	0
	retlw	0
psect	stringtext
	
STR_27:	
	retlw	65	;'A'
	retlw	84	;'T'
	retlw	43	;'+'
	retlw	67	;'C'
	retlw	78	;'N'
	retlw	77	;'M'
	retlw	73	;'I'
	retlw	61	;'='
	retlw	48	;'0'
	retlw	44	;','
	retlw	48	;'0'
	retlw	0
	retlw	0
psect	stringtext
	
STR_9:	
	retlw	65	;'A'
	retlw	84	;'T'
	retlw	43	;'+'
	retlw	67	;'C'
	retlw	73	;'I'
	retlw	80	;'P'
	retlw	83	;'S'
	retlw	69	;'E'
	retlw	78	;'N'
	retlw	68	;'D'
	retlw	0
	retlw	0
psect	stringtext
	
STR_7:	
	retlw	65	;'A'
	retlw	84	;'T'
	retlw	43	;'+'
	retlw	67	;'C'
	retlw	73	;'I'
	retlw	80	;'P'
	retlw	83	;'S'
	retlw	72	;'H'
	retlw	85	;'U'
	retlw	84	;'T'
	retlw	0
	retlw	0
psect	stringtext
	
STR_32:	
	retlw	43	;'+'
	retlw	67	;'C'
	retlw	71	;'G'
	retlw	82	;'R'
	retlw	69	;'E'
	retlw	71	;'G'
	retlw	58	;':'
	retlw	32	;' '
	retlw	48	;'0'
	retlw	44	;','
	retlw	49	;'1'
	retlw	0
psect	stringtext
	
STR_33:	
	retlw	43	;'+'
	retlw	67	;'C'
	retlw	71	;'G'
	retlw	82	;'R'
	retlw	69	;'E'
	retlw	71	;'G'
	retlw	58	;':'
	retlw	32	;' '
	retlw	48	;'0'
	retlw	44	;','
	retlw	53	;'5'
	retlw	0
psect	stringtext
	
STR_28:	
	retlw	65	;'A'
	retlw	84	;'T'
	retlw	43	;'+'
	retlw	67	;'C'
	retlw	77	;'M'
	retlw	71	;'G'
	retlw	70	;'F'
	retlw	61	;'='
	retlw	49	;'1'
	retlw	0
	retlw	0
psect	stringtext
	
STR_34:	
	retlw	65	;'A'
	retlw	84	;'T'
	retlw	43	;'+'
	retlw	67	;'C'
	retlw	79	;'O'
	retlw	76	;'L'
	retlw	80	;'P'
	retlw	61	;'='
	retlw	49	;'1'
	retlw	0
	retlw	0
psect	stringtext
	
STR_31:	
	retlw	65	;'A'
	retlw	84	;'T'
	retlw	43	;'+'
	retlw	67	;'C'
	retlw	71	;'G'
	retlw	82	;'R'
	retlw	69	;'E'
	retlw	71	;'G'
	retlw	63	;'?'
	retlw	0
	retlw	0
psect	stringtext
	
STR_2:	
	retlw	67	;'C'
	retlw	79	;'O'
	retlw	78	;'N'
	retlw	78	;'N'
	retlw	69	;'E'
	retlw	67	;'C'
	retlw	84	;'T'
	retlw	32	;' '
	retlw	79	;'O'
	retlw	75	;'K'
	retlw	0
psect	stringtext
	
STR_25:	
	retlw	65	;'A'
	retlw	84	;'T'
	retlw	43	;'+'
	retlw	73	;'I'
	retlw	67	;'C'
	retlw	67	;'C'
	retlw	73	;'I'
	retlw	68	;'D'
	retlw	0
	retlw	0
psect	stringtext
	
STR_37:	
	retlw	65	;'A'
	retlw	84	;'T'
	retlw	43	;'+'
	retlw	67	;'C'
	retlw	73	;'I'
	retlw	73	;'I'
	retlw	67	;'C'
	retlw	82	;'R'
	retlw	0
	retlw	0
psect	stringtext
	
STR_38:	
	retlw	65	;'A'
	retlw	84	;'T'
	retlw	43	;'+'
	retlw	67	;'C'
	retlw	73	;'I'
	retlw	70	;'F'
	retlw	83	;'S'
	retlw	82	;'R'
	retlw	0
	retlw	0
psect	stringtext
	
STR_10:	
	retlw	64	;'@'
	retlw	35	;'#'
	retlw	112	;'p'
	retlw	116	;'t'
	retlw	35	;'#'
	retlw	49	;'1'
	retlw	35	;'#'
	retlw	0
	retlw	0
psect	stringtext
	
STR_16:	
	retlw	64	;'@'
	retlw	35	;'#'
	retlw	112	;'p'
	retlw	116	;'t'
	retlw	35	;'#'
	retlw	50	;'2'
	retlw	35	;'#'
	retlw	0
	retlw	0
psect	stringtext
	
STR_13:	
	retlw	64	;'@'
	retlw	35	;'#'
	retlw	112	;'p'
	retlw	116	;'t'
	retlw	35	;'#'
	retlw	51	;'3'
	retlw	35	;'#'
	retlw	0
	retlw	0
psect	stringtext
	
STR_24:	
	retlw	65	;'A'
	retlw	84	;'T'
	retlw	43	;'+'
	retlw	67	;'C'
	retlw	73	;'I'
	retlw	77	;'M'
	retlw	73	;'I'
	retlw	0
	retlw	0
psect	stringtext
	
STR_26:	
	retlw	43	;'+'
	retlw	73	;'I'
	retlw	67	;'C'
	retlw	67	;'C'
	retlw	73	;'I'
	retlw	68	;'D'
	retlw	58	;':'
	retlw	32	;' '
	retlw	0
psect	stringtext
	
STR_29:	
	retlw	65	;'A'
	retlw	84	;'T'
	retlw	43	;'+'
	retlw	67	;'C'
	retlw	83	;'S'
	retlw	81	;'Q'
	retlw	0
	retlw	0
psect	stringtext
	
STR_30:	
	retlw	43	;'+'
	retlw	67	;'C'
	retlw	83	;'S'
	retlw	81	;'Q'
	retlw	58	;':'
	retlw	32	;' '
	retlw	0
psect	stringtext
	
STR_48:	
	retlw	69	;'E'
	retlw	82	;'R'
	retlw	82	;'R'
	retlw	79	;'O'
	retlw	82	;'R'
	retlw	0
psect	stringtext
	
STR_23:	
	retlw	65	;'A'
	retlw	84	;'T'
	retlw	69	;'E'
	retlw	49	;'1'
	retlw	0
	retlw	0
psect	stringtext
	
STR_20:	
	retlw	67	;'C'
	retlw	76	;'L'
	retlw	79	;'O'
	retlw	83	;'S'
	retlw	69	;'E'
	retlw	0
psect	stringtext
	
STR_12:	
	retlw	49	;'1'
	retlw	48	;'0'
	retlw	35	;'#'
	retlw	0
	retlw	0
psect	stringtext
	
STR_11:	
	retlw	54	;'6'
	retlw	48	;'0'
	retlw	35	;'#'
	retlw	0
	retlw	0
psect	stringtext
	
STR_22:	
	retlw	65	;'A'
	retlw	84	;'T'
	retlw	72	;'H'
	retlw	0
	retlw	0
psect	stringtext
	
STR_19:	
	retlw	36	;'$'
	retlw	79	;'O'
	retlw	75	;'K'
	retlw	35	;'#'
	retlw	0
psect	stringtext
	
STR_5:	
	retlw	35	;'#'
	retlw	75	;'K'
	retlw	79	;'O'
	retlw	36	;'$'
	retlw	0
psect	stringtext
	
STR_21:	
	retlw	65	;'A'
	retlw	84	;'T'
	retlw	0
	retlw	0
psect	stringtext
	
STR_49:	
	retlw	13
	retlw	0
	retlw	0
psect	stringtext
	
STR_8:	
	retlw	62	;'>'
	retlw	0
psect	stringtext
STR_51	equ	STR_48+0
STR_53	equ	STR_48+0
STR_41	equ	STR_2+0
STR_47	equ	STR_2+8
STR_50	equ	STR_2+8
STR_52	equ	STR_2+8
STR_44	equ	STR_5+0
STR_46	equ	STR_7+0
STR_39	equ	STR_21+0
STR_40	equ	STR_1+0
STR_43	equ	STR_4+0
STR_45	equ	STR_6+0
STR_14	equ	STR_11+0
STR_17	equ	STR_11+0
STR_15	equ	STR_12+0
STR_18	equ	STR_12+0
STR_42	equ	STR_3+0
	file	"BC28.as"
	line	#
psect cinit,class=CODE,delta=2
global start_initialization
start_initialization:

_ATCommand_RxList  equ     8588	;BIGRAM
psect	bssCOMMON,class=COMMON,space=1
global __pbssCOMMON
__pbssCOMMON:
_MeasurementTick:
       ds      2

_NeedMeasurementTick:
       ds      2

_ATCommand_Clear:
       ds      1

_ATCommand_Flags:
       ds      1

_ATCommand_RxCount:
       ds      1

psect	bssBANK0,class=BANK0,space=1
global __pbssBANK0
__pbssBANK0:
_TxTemperature:
       ds      4

_ATCommand_WaitACKTick:
       ds      2

_ATCommand_WaitACKTimes:
       ds      2

_CurTemp:
       ds      2

_SystemTick:
       ds      2

_TCN75_RegReadResualt:
       ds      2

_ATCommand_RetryTimes:
       ds      1

_CSQ:
       ds      1

_ErrState:
       ds      1

_TCN75_Config:
       ds      1

_TListIndex:
       ds      1

_gFlags:
       ds      1

_RomParams:
       ds      2

_TxErrDataIndex:
       ds      1

psect	dataBANK0,class=BANK0,space=1
global __pdataBANK0
__pdataBANK0:
	file	"F:\work\WYP\NBIoT\Display.c"
	line	5
_DpyNum:
       ds      6

psect	bssBANK1,class=BANK1,space=1
global __pbssBANK1
__pbssBANK1:
_RunTick:
       ds      2

_ICCID:
       ds      21

_ATCommand_ErrString:
       ds      15

_ATCommand_OkString:
       ds      15

_DS18X20_Scratchpad:
       ds      9

psect	bssBANK2,class=BANK2,space=1
global __pbssBANK2
__pbssBANK2:
_TList:
       ds      24

psect clrtext,class=CODE,delta=2
global clear_ram
;	Called with FSR0 containing the base address, and
;	btemp/btemp+1 has the size to clear
clear_ram:
	clrwdt			;clear the watchdog before getting into this loop
clrloop:
	clrf	indf0		;clear RAM location pointed to by FSR
	addfsr	0,1
	movlw	1
	subwf	btemp,f
	movlw	0
	subwfb btemp+1,f
	movf btemp+1,w
	iorwf btemp,w
	skipz
	goto clrloop	;have we reached the end yet?
	retlw	0		;all done for this memory range, return
; Clear objects allocated to BIGRAM
psect cinit,class=CODE,delta=2
	global __pbssBIGRAM
	movlw	low(__pbssBIGRAM)
	movwf	fsr0l
	movlw	high(__pbssBIGRAM)
	movwf	fsr0h
	movlw	low(064h)
	movwf	btemp
	movlw	high(064h)
	movwf	btemp+1
	fcall	clear_ram
; Clear objects allocated to COMMON
psect cinit,class=CODE,delta=2
	global __pbssCOMMON
	clrf	((__pbssCOMMON)+0)&07Fh
	clrf	((__pbssCOMMON)+1)&07Fh
	clrf	((__pbssCOMMON)+2)&07Fh
	clrf	((__pbssCOMMON)+3)&07Fh
	clrf	((__pbssCOMMON)+4)&07Fh
	clrf	((__pbssCOMMON)+5)&07Fh
	clrf	((__pbssCOMMON)+6)&07Fh
; Clear objects allocated to BANK0
psect cinit,class=CODE,delta=2
	global __pbssBANK0
	movlw	low(__pbssBANK0)
	movwf	fsr0l
	movlw	high(__pbssBANK0)
	movwf	fsr0h
	movlw	low(017h)
	movwf	btemp
	movlw	high(017h)
	movwf	btemp+1
	fcall	clear_ram
; Clear objects allocated to BANK1
psect cinit,class=CODE,delta=2
	global __pbssBANK1
	movlw	low(__pbssBANK1)
	movwf	fsr0l
	movlw	high(__pbssBANK1)
	movwf	fsr0h
	movlw	low(03Eh)
	movwf	btemp
	movlw	high(03Eh)
	movwf	btemp+1
	fcall	clear_ram
; Clear objects allocated to BANK2
psect cinit,class=CODE,delta=2
	global __pbssBANK2
	movlw	low(__pbssBANK2)
	movwf	fsr0l
	movlw	high(__pbssBANK2)
	movwf	fsr0h
	movlw	low(018h)
	movwf	btemp
	movlw	high(018h)
	movwf	btemp+1
	fcall	clear_ram
; Initialize objects allocated to BANK0
	global __pidataBANK0,__pdataBANK0
psect cinit,class=CODE,delta=2
	fcall	__pidataBANK0+0		;fetch initializer
	movwf	__pdataBANK0+0&07fh		
	fcall	__pidataBANK0+1		;fetch initializer
	movwf	__pdataBANK0+1&07fh		
	fcall	__pidataBANK0+2		;fetch initializer
	movwf	__pdataBANK0+2&07fh		
	fcall	__pidataBANK0+3		;fetch initializer
	movwf	__pdataBANK0+3&07fh		
	fcall	__pidataBANK0+4		;fetch initializer
	movwf	__pdataBANK0+4&07fh		
	fcall	__pidataBANK0+5		;fetch initializer
	movwf	__pdataBANK0+5&07fh		
psect cinit,class=CODE,delta=2
global end_of_initialization

;End of C runtime variable initialization code

end_of_initialization:
movlb 0
ljmp _main	;jump to C main() function
psect	cstackCOMMON,class=COMMON,space=1
global __pcstackCOMMON
__pcstackCOMMON:
	global	?_SaveRomData
?_SaveRomData:	; 0 bytes @ 0x0
	global	?_ATCommand_Init
?_ATCommand_Init:	; 0 bytes @ 0x0
	global	?_TCN75_Init
?_TCN75_Init:	; 0 bytes @ 0x0
	global	?_ReadTData
?_ReadTData:	; 0 bytes @ 0x0
	global	?_TestProc
?_TestProc:	; 0 bytes @ 0x0
	global	?_CallProc
?_CallProc:	; 0 bytes @ 0x0
	global	?_ATCommand_ProcRx
?_ATCommand_ProcRx:	; 0 bytes @ 0x0
	global	?_CallSend
?_CallSend:	; 0 bytes @ 0x0
	global	?_InitGPRS
?_InitGPRS:	; 0 bytes @ 0x0
	global	?_Uart1_PutChar
?_Uart1_PutChar:	; 0 bytes @ 0x0
	global	?_CallTestProc
?_CallTestProc:	; 0 bytes @ 0x0
	global	?_CallTestSend
?_CallTestSend:	; 0 bytes @ 0x0
	global	?_isgraph
?_isgraph:	; 1 bit 
	global	??_isgraph
??_isgraph:	; 0 bytes @ 0x0
	global	?_OneWire_WriteByte
?_OneWire_WriteByte:	; 0 bytes @ 0x0
	global	?_SimI2C_Init
?_SimI2C_Init:	; 0 bytes @ 0x0
	global	?_SimI2C_Start
?_SimI2C_Start:	; 0 bytes @ 0x0
	global	?_SimI2C_SendByte
?_SimI2C_SendByte:	; 0 bytes @ 0x0
	global	?_SimI2C_Ack
?_SimI2C_Ack:	; 0 bytes @ 0x0
	global	?_SimI2C_NoAck
?_SimI2C_NoAck:	; 0 bytes @ 0x0
	global	?_SimI2C_Stop
?_SimI2C_Stop:	; 0 bytes @ 0x0
	global	?_isdigit
?_isdigit:	; 1 bit 
	global	?_LcdDisplayNum
?_LcdDisplayNum:	; 0 bytes @ 0x0
	global	?_LcdDisplayAll
?_LcdDisplayAll:	; 0 bytes @ 0x0
	global	?_LcdDisplay_CSQ
?_LcdDisplay_CSQ:	; 0 bytes @ 0x0
	global	?_LcdDisplay_CurTemp
?_LcdDisplay_CurTemp:	; 0 bytes @ 0x0
	global	?_LcdDisplay_Err
?_LcdDisplay_Err:	; 0 bytes @ 0x0
	global	?_DisplayInit
?_DisplayInit:	; 0 bytes @ 0x0
	global	?_InitMCU
?_InitMCU:	; 0 bytes @ 0x0
	global	?_InitVariable
?_InitVariable:	; 0 bytes @ 0x0
	global	?_InitSystem
?_InitSystem:	; 0 bytes @ 0x0
	global	?_main
?_main:	; 0 bytes @ 0x0
	global	?_highISR
?_highISR:	; 0 bytes @ 0x0
	global	?_GetRomData
?_GetRomData:	; 1 bytes @ 0x0
	global	?_OneWire_Reset
?_OneWire_Reset:	; 1 bytes @ 0x0
	global	?_TCN75_SetConfig
?_TCN75_SetConfig:	; 1 bytes @ 0x0
	global	?_DS18X20_StartMeas
?_DS18X20_StartMeas:	; 1 bytes @ 0x0
	global	?_DS18X20_ReadMeas
?_DS18X20_ReadMeas:	; 1 bytes @ 0x0
	global	?_TCN75_ReadReg
?_TCN75_ReadReg:	; 1 bytes @ 0x0
	global	?_PowerON
?_PowerON:	; 1 bytes @ 0x0
	global	?_PowerDown
?_PowerDown:	; 1 bytes @ 0x0
	global	?_InteractServer
?_InteractServer:	; 1 bytes @ 0x0
	global	?_eeprom_read
?_eeprom_read:	; 1 bytes @ 0x0
	global	?_ATCommand_WaitData
?_ATCommand_WaitData:	; 1 bytes @ 0x0
	global	?_OneWire_Command
?_OneWire_Command:	; 1 bytes @ 0x0
	global	?_OneWire_ReadByte
?_OneWire_ReadByte:	; 1 bytes @ 0x0
	global	?_SimI2C_RecAck
?_SimI2C_RecAck:	; 1 bytes @ 0x0
	global	?_SimI2C_ReadByte
?_SimI2C_ReadByte:	; 1 bytes @ 0x0
	global	_isgraph$31845
_isgraph$31845:	; 1 bytes @ 0x0
	ds	1
	global	isgraph@c
isgraph@c:	; 1 bytes @ 0x1
	ds	1
	global	??_ATCommand_ProcRx
??_ATCommand_ProcRx:	; 0 bytes @ 0x2
	ds	3
	global	ATCommand_ProcRx@rx
ATCommand_ProcRx@rx:	; 1 bytes @ 0x5
	ds	1
	global	??_highISR
??_highISR:	; 0 bytes @ 0x6
	global	highISR@rx
highISR@rx:	; 1 bytes @ 0x6
	ds	1
psect	cstackBANK0,class=BANK0,space=1
global __pcstackBANK0
__pcstackBANK0:
	global	??_OneWire_Reset
??_OneWire_Reset:	; 0 bytes @ 0x0
	global	??_TCN75_Init
??_TCN75_Init:	; 0 bytes @ 0x0
	global	?___delay_20ms
?___delay_20ms:	; 0 bytes @ 0x0
	global	?_eeprom_write
?_eeprom_write:	; 0 bytes @ 0x0
	global	??_Uart1_PutChar
??_Uart1_PutChar:	; 0 bytes @ 0x0
	global	?_MakeTxTemperature
?_MakeTxTemperature:	; 0 bytes @ 0x0
	global	??_eeprom_read
??_eeprom_read:	; 0 bytes @ 0x0
	global	??_OneWire_ReadByte
??_OneWire_ReadByte:	; 0 bytes @ 0x0
	global	??_OneWire_WriteByte
??_OneWire_WriteByte:	; 0 bytes @ 0x0
	global	??_SimI2C_Init
??_SimI2C_Init:	; 0 bytes @ 0x0
	global	??_SimI2C_Start
??_SimI2C_Start:	; 0 bytes @ 0x0
	global	??_SimI2C_SendByte
??_SimI2C_SendByte:	; 0 bytes @ 0x0
	global	??_SimI2C_RecAck
??_SimI2C_RecAck:	; 0 bytes @ 0x0
	global	??_SimI2C_ReadByte
??_SimI2C_ReadByte:	; 0 bytes @ 0x0
	global	??_SimI2C_Ack
??_SimI2C_Ack:	; 0 bytes @ 0x0
	global	??_SimI2C_NoAck
??_SimI2C_NoAck:	; 0 bytes @ 0x0
	global	??_SimI2C_Stop
??_SimI2C_Stop:	; 0 bytes @ 0x0
	global	??_isdigit
??_isdigit:	; 0 bytes @ 0x0
	global	??_LcdDisplayNum
??_LcdDisplayNum:	; 0 bytes @ 0x0
	global	??_LcdDisplayAll
??_LcdDisplayAll:	; 0 bytes @ 0x0
	global	??_DisplayInit
??_DisplayInit:	; 0 bytes @ 0x0
	global	??_InitMCU
??_InitMCU:	; 0 bytes @ 0x0
	global	?_strcpy
?_strcpy:	; 1 bytes @ 0x0
	global	?_GetVerify_Sum
?_GetVerify_Sum:	; 1 bytes @ 0x0
	global	?_GetVerify_CRC8
?_GetVerify_CRC8:	; 1 bytes @ 0x0
	global	?___bmul
?___bmul:	; 1 bytes @ 0x0
	global	?___lbdiv
?___lbdiv:	; 1 bytes @ 0x0
	global	?___lbmod
?___lbmod:	; 1 bytes @ 0x0
	global	?_strlen
?_strlen:	; 2 bytes @ 0x0
	global	?_strchr
?_strchr:	; 2 bytes @ 0x0
	global	?___wmul
?___wmul:	; 2 bytes @ 0x0
	global	LcdDisplayAll@x
LcdDisplayAll@x:	; 1 bytes @ 0x0
	global	Uart1_PutChar@c
Uart1_PutChar@c:	; 1 bytes @ 0x0
	global	SimI2C_RecAck@t
SimI2C_RecAck@t:	; 1 bytes @ 0x0
	global	SimI2C_SendByte@data
SimI2C_SendByte@data:	; 1 bytes @ 0x0
	global	SimI2C_ReadByte@data
SimI2C_ReadByte@data:	; 1 bytes @ 0x0
	global	eeprom_write@value
eeprom_write@value:	; 1 bytes @ 0x0
	global	_isdigit$31842
_isdigit$31842:	; 1 bytes @ 0x0
	global	___bmul@multiplicand
___bmul@multiplicand:	; 1 bytes @ 0x0
	global	___lbdiv@divisor
___lbdiv@divisor:	; 1 bytes @ 0x0
	global	___lbmod@divisor
___lbmod@divisor:	; 1 bytes @ 0x0
	global	MakeTxTemperature@T
MakeTxTemperature@T:	; 2 bytes @ 0x0
	global	___delay_20ms@x
___delay_20ms@x:	; 2 bytes @ 0x0
	global	GetVerify_Sum@Count
GetVerify_Sum@Count:	; 2 bytes @ 0x0
	global	GetVerify_CRC8@Count
GetVerify_CRC8@Count:	; 2 bytes @ 0x0
	global	strcpy@from
strcpy@from:	; 2 bytes @ 0x0
	global	___wmul@multiplier
___wmul@multiplier:	; 2 bytes @ 0x0
	global	strchr@ptr
strchr@ptr:	; 2 bytes @ 0x0
	global	strlen@s
strlen@s:	; 2 bytes @ 0x0
	ds	1
	global	??_eeprom_write
??_eeprom_write:	; 0 bytes @ 0x1
	global	?_Uart1_PutString
?_Uart1_PutString:	; 0 bytes @ 0x1
	global	??___bmul
??___bmul:	; 0 bytes @ 0x1
	global	??___lbdiv
??___lbdiv:	; 0 bytes @ 0x1
	global	??___lbmod
??___lbmod:	; 0 bytes @ 0x1
	global	OneWire_Reset@Retry
OneWire_Reset@Retry:	; 1 bytes @ 0x1
	global	OneWire_WriteByte@val
OneWire_WriteByte@val:	; 1 bytes @ 0x1
	global	OneWire_ReadByte@b
OneWire_ReadByte@b:	; 1 bytes @ 0x1
	global	SimI2C_SendByte@t
SimI2C_SendByte@t:	; 1 bytes @ 0x1
	global	SimI2C_ReadByte@i
SimI2C_ReadByte@i:	; 1 bytes @ 0x1
	global	eeprom_write@addr
eeprom_write@addr:	; 1 bytes @ 0x1
	global	isdigit@c
isdigit@c:	; 1 bytes @ 0x1
	global	___bmul@product
___bmul@product:	; 1 bytes @ 0x1
	global	___lbdiv@dividend
___lbdiv@dividend:	; 1 bytes @ 0x1
	global	Uart1_PutString@pString
Uart1_PutString@pString:	; 2 bytes @ 0x1
	ds	1
	global	??___delay_20ms
??___delay_20ms:	; 0 bytes @ 0x2
	global	??_strcpy
??_strcpy:	; 0 bytes @ 0x2
	global	??_MakeTxTemperature
??_MakeTxTemperature:	; 0 bytes @ 0x2
	global	??_GetVerify_Sum
??_GetVerify_Sum:	; 0 bytes @ 0x2
	global	??_GetVerify_CRC8
??_GetVerify_CRC8:	; 0 bytes @ 0x2
	global	??_strlen
??_strlen:	; 0 bytes @ 0x2
	global	MakeTxTemperature@x
MakeTxTemperature@x:	; 1 bytes @ 0x2
	global	OneWire_Reset@r
OneWire_Reset@r:	; 1 bytes @ 0x2
	global	OneWire_WriteByte@temp
OneWire_WriteByte@temp:	; 1 bytes @ 0x2
	global	OneWire_ReadByte@value
OneWire_ReadByte@value:	; 1 bytes @ 0x2
	global	SimI2C_SendByte@i
SimI2C_SendByte@i:	; 1 bytes @ 0x2
	global	eeprom_read@addr
eeprom_read@addr:	; 1 bytes @ 0x2
	global	___bmul@multiplier
___bmul@multiplier:	; 1 bytes @ 0x2
	global	___lbdiv@counter
___lbdiv@counter:	; 1 bytes @ 0x2
	global	___lbmod@dividend
___lbmod@dividend:	; 1 bytes @ 0x2
	global	___wmul@multiplicand
___wmul@multiplicand:	; 2 bytes @ 0x2
	global	strchr@chr
strchr@chr:	; 2 bytes @ 0x2
	ds	1
	global	??_TCN75_SetConfig
??_TCN75_SetConfig:	; 0 bytes @ 0x3
	global	??_TCN75_ReadReg
??_TCN75_ReadReg:	; 0 bytes @ 0x3
	global	??_Uart1_PutString
??_Uart1_PutString:	; 0 bytes @ 0x3
	global	OneWire_WriteByte@i
OneWire_WriteByte@i:	; 1 bytes @ 0x3
	global	OneWire_ReadByte@i
OneWire_ReadByte@i:	; 1 bytes @ 0x3
	global	TCN75_ReadReg@RegPoint
TCN75_ReadReg@RegPoint:	; 1 bytes @ 0x3
	global	TCN75_SetConfig@ErrTimes
TCN75_SetConfig@ErrTimes:	; 1 bytes @ 0x3
	global	Uart1_PutString@c
Uart1_PutString@c:	; 1 bytes @ 0x3
	global	GetVerify_CRC8@pBuff
GetVerify_CRC8@pBuff:	; 1 bytes @ 0x3
	global	___lbdiv@quotient
___lbdiv@quotient:	; 1 bytes @ 0x3
	global	___lbmod@counter
___lbmod@counter:	; 1 bytes @ 0x3
	ds	1
	global	??_PowerDown
??_PowerDown:	; 0 bytes @ 0x4
	global	??_OneWire_Command
??_OneWire_Command:	; 0 bytes @ 0x4
	global	??_strchr
??_strchr:	; 0 bytes @ 0x4
	global	??___wmul
??___wmul:	; 0 bytes @ 0x4
	global	PowerDown@i
PowerDown@i:	; 1 bytes @ 0x4
	global	OneWire_Command@command
OneWire_Command@command:	; 1 bytes @ 0x4
	global	TCN75_ReadReg@ErrTimes
TCN75_ReadReg@ErrTimes:	; 1 bytes @ 0x4
	global	TCN75_SetConfig@bRight
TCN75_SetConfig@bRight:	; 1 bytes @ 0x4
	global	GetVerify_Sum@pBuff
GetVerify_Sum@pBuff:	; 1 bytes @ 0x4
	global	GetVerify_CRC8@bit_counter
GetVerify_CRC8@bit_counter:	; 1 bytes @ 0x4
	global	strcpy@to
strcpy@to:	; 1 bytes @ 0x4
	global	___lbmod@rem
___lbmod@rem:	; 1 bytes @ 0x4
	global	___wmul@product
___wmul@product:	; 2 bytes @ 0x4
	global	strlen@cp
strlen@cp:	; 2 bytes @ 0x4
	ds	1
	global	??_DS18X20_StartMeas
??_DS18X20_StartMeas:	; 0 bytes @ 0x5
	global	??_LcdDisplay_CSQ
??_LcdDisplay_CSQ:	; 0 bytes @ 0x5
	global	??_LcdDisplay_CurTemp
??_LcdDisplay_CurTemp:	; 0 bytes @ 0x5
	global	??_LcdDisplay_Err
??_LcdDisplay_Err:	; 0 bytes @ 0x5
	global	LcdDisplay_CSQ@t1
LcdDisplay_CSQ@t1:	; 1 bytes @ 0x5
	global	TCN75_ReadReg@bRight
TCN75_ReadReg@bRight:	; 1 bytes @ 0x5
	global	GetVerify_Sum@sum
GetVerify_Sum@sum:	; 1 bytes @ 0x5
	global	GetVerify_CRC8@data
GetVerify_CRC8@data:	; 1 bytes @ 0x5
	global	strcpy@cp
strcpy@cp:	; 1 bytes @ 0x5
	ds	1
	global	??_ATCommand_Init
??_ATCommand_Init:	; 0 bytes @ 0x6
	global	?_atoi
?_atoi:	; 2 bytes @ 0x6
	global	?_strncmp
?_strncmp:	; 2 bytes @ 0x6
	global	LcdDisplay_CSQ@t2
LcdDisplay_CSQ@t2:	; 1 bytes @ 0x6
	global	GetVerify_Sum@i
GetVerify_Sum@i:	; 1 bytes @ 0x6
	global	GetVerify_CRC8@i
GetVerify_CRC8@i:	; 2 bytes @ 0x6
	global	atoi@s
atoi@s:	; 2 bytes @ 0x6
	global	strncmp@s1
strncmp@s1:	; 2 bytes @ 0x6
	ds	1
	global	??_GetRomData
??_GetRomData:	; 0 bytes @ 0x7
	global	??_SaveRomData
??_SaveRomData:	; 0 bytes @ 0x7
	global	LcdDisplay_CurTemp@t1
LcdDisplay_CurTemp@t1:	; 1 bytes @ 0x7
	global	GetRomData@i
GetRomData@i:	; 1 bytes @ 0x7
	global	SaveRomData@i
SaveRomData@i:	; 1 bytes @ 0x7
	ds	1
	global	??_atoi
??_atoi:	; 0 bytes @ 0x8
	global	??_InitVariable
??_InitVariable:	; 0 bytes @ 0x8
	global	LcdDisplay_CurTemp@t2
LcdDisplay_CurTemp@t2:	; 1 bytes @ 0x8
	global	GetVerify_CRC8@feedback_bit
GetVerify_CRC8@feedback_bit:	; 1 bytes @ 0x8
	global	strncmp@s2
strncmp@s2:	; 2 bytes @ 0x8
	ds	1
	global	GetVerify_CRC8@crc
GetVerify_CRC8@crc:	; 1 bytes @ 0x9
	ds	1
	global	??_DS18X20_ReadMeas
??_DS18X20_ReadMeas:	; 0 bytes @ 0xA
	global	DS18X20_ReadMeas@bVerify
DS18X20_ReadMeas@bVerify:	; 1 bytes @ 0xA
	global	strncmp@len
strncmp@len:	; 2 bytes @ 0xA
	ds	1
	global	DS18X20_ReadMeas@i
DS18X20_ReadMeas@i:	; 1 bytes @ 0xB
	ds	1
	global	??_ReadTData
??_ReadTData:	; 0 bytes @ 0xC
	global	??_strncmp
??_strncmp:	; 0 bytes @ 0xC
	global	ReadTData@retry
ReadTData@retry:	; 1 bytes @ 0xC
	global	atoi@sign
atoi@sign:	; 1 bytes @ 0xC
	ds	1
	global	??_InitSystem
??_InitSystem:	; 0 bytes @ 0xD
	global	?_strstr
?_strstr:	; 2 bytes @ 0xD
	global	InitSystem@x
InitSystem@x:	; 1 bytes @ 0xD
	global	atoi@a
atoi@a:	; 2 bytes @ 0xD
	global	strstr@s1
strstr@s1:	; 2 bytes @ 0xD
	ds	2
	global	strstr@s2
strstr@s2:	; 2 bytes @ 0xF
	ds	2
	global	??_strstr
??_strstr:	; 0 bytes @ 0x11
	global	??_ATCommand_WaitData
??_ATCommand_WaitData:	; 0 bytes @ 0x11
	global	?_ATCommand_SendCmd
?_ATCommand_SendCmd:	; 1 bytes @ 0x11
	global	ATCommand_SendCmd@cmd
ATCommand_SendCmd@cmd:	; 2 bytes @ 0x11
	ds	2
	global	??_ATCommand_SendCmd
??_ATCommand_SendCmd:	; 0 bytes @ 0x13
	global	ATCommand_WaitData@res
ATCommand_WaitData@res:	; 1 bytes @ 0x13
	ds	1
	global	ATCommand_WaitData@strx
ATCommand_WaitData@strx:	; 2 bytes @ 0x14
	ds	1
	global	ATCommand_SendCmd@retry
ATCommand_SendCmd@retry:	; 1 bytes @ 0x15
	ds	1
	global	ATCommand_SendCmd@strx
ATCommand_SendCmd@strx:	; 2 bytes @ 0x16
	ds	2
	global	ATCommand_SendCmd@res
ATCommand_SendCmd@res:	; 1 bytes @ 0x18
	ds	1
	global	??_PowerON
??_PowerON:	; 0 bytes @ 0x19
	global	??_InitGPRS
??_InitGPRS:	; 0 bytes @ 0x19
	global	??_InteractServer
??_InteractServer:	; 0 bytes @ 0x19
	global	InteractServer@retry
InteractServer@retry:	; 1 bytes @ 0x19
	global	PowerON@i
PowerON@i:	; 1 bytes @ 0x19
	ds	1
	global	InteractServer@i_10586
InteractServer@i_10586:	; 2 bytes @ 0x1A
	ds	1
	global	InitGPRS@i
InitGPRS@i:	; 1 bytes @ 0x1B
	ds	1
	global	InteractServer@i_10590
InteractServer@i_10590:	; 2 bytes @ 0x1C
	global	InitGPRS@strx
InitGPRS@strx:	; 2 bytes @ 0x1C
	ds	2
	global	InitGPRS@retry
InitGPRS@retry:	; 1 bytes @ 0x1E
	global	InteractServer@j_10594
InteractServer@j_10594:	; 2 bytes @ 0x1E
	ds	2
	global	InteractServer@res
InteractServer@res:	; 1 bytes @ 0x20
	ds	1
	global	InteractServer@t
InteractServer@t:	; 2 bytes @ 0x21
	ds	2
	global	InteractServer@addr
InteractServer@addr:	; 1 bytes @ 0x23
	ds	1
	global	InteractServer@j
InteractServer@j:	; 1 bytes @ 0x24
	ds	1
	global	InteractServer@k
InteractServer@k:	; 1 bytes @ 0x25
	ds	1
	global	InteractServer@i
InteractServer@i:	; 1 bytes @ 0x26
	ds	1
	global	??_CallSend
??_CallSend:	; 0 bytes @ 0x27
	global	??_CallTestSend
??_CallTestSend:	; 0 bytes @ 0x27
	global	CallSend@strx
CallSend@strx:	; 2 bytes @ 0x27
	global	CallTestSend@strx
CallTestSend@strx:	; 2 bytes @ 0x27
	ds	2
	global	CallSend@i
CallSend@i:	; 1 bytes @ 0x29
	global	CallTestSend@ret
CallTestSend@ret:	; 1 bytes @ 0x29
	ds	1
	global	??_CallTestProc
??_CallTestProc:	; 0 bytes @ 0x2A
	global	CallSend@ret
CallSend@ret:	; 1 bytes @ 0x2A
	global	CallTestProc@retry
CallTestProc@retry:	; 1 bytes @ 0x2A
	ds	1
	global	??_TestProc
??_TestProc:	; 0 bytes @ 0x2B
	global	??_CallProc
??_CallProc:	; 0 bytes @ 0x2B
	global	CallProc@retry
CallProc@retry:	; 1 bytes @ 0x2B
	ds	2
	global	??_main
??_main:	; 0 bytes @ 0x2D
	ds	2
	global	main@addr
main@addr:	; 1 bytes @ 0x2F
	ds	1
	global	main@i
main@i:	; 1 bytes @ 0x30
	ds	1
;;Data sizes: Strings 392, constant 33, data 6, bss 116, persistent 0 stack 0
;;Auto spaces:   Size  Autos    Used
;; COMMON          14      7      14
;; BANK0           79     49      78
;; BANK1           80      0      62
;; BANK2           80      0      24
;; BANK3           80      0       0
;; BANK4           76      0       0
;; BANK5            0      0       0
;; BANK6            0      0       0

;;
;; Pointer list with targets:

;; ?_strchr	PTR unsigned char  size(2) Largest target is 128
;;		 -> ATCommand_RxList(BIGRAM[100]), RAM(NULL[128]), 
;;
;; ?_strncmp	int  size(1) Largest target is 0
;;
;; ?_strlen	unsigned int  size(2) Largest target is 15
;;		 -> STR_44(CODE[5]), STR_33(CODE[12]), STR_32(CODE[12]), STR_30(CODE[7]), 
;;		 -> STR_26(CODE[9]), ATCommand_ErrString(BANK1[15]), STR_5(CODE[5]), ATCommand_OkString(BANK1[15]), 
;;
;; ?___wmul	unsigned int  size(1) Largest target is 0
;;
;; ?_atoi	int  size(1) Largest target is 0
;;
;; ?_strstr	PTR unsigned char  size(2) Largest target is 128
;;		 -> ATCommand_RxList(BIGRAM[100]), RAM(NULL[128]), 
;;
;; ?_strcpy	PTR unsigned char  size(1) Largest target is 15
;;		 -> ATCommand_ErrString(BANK1[15]), ATCommand_OkString(BANK1[15]), 
;;
;; strncmp@s2	PTR const unsigned char  size(2) Largest target is 15
;;		 -> STR_44(CODE[5]), STR_33(CODE[12]), STR_32(CODE[12]), STR_30(CODE[7]), 
;;		 -> STR_26(CODE[9]), ATCommand_ErrString(BANK1[15]), STR_5(CODE[5]), ATCommand_OkString(BANK1[15]), 
;;
;; strncmp@s1	PTR const unsigned char  size(2) Largest target is 128
;;		 -> ATCommand_RxList(BIGRAM[100]), RAM(NULL[128]), 
;;
;; strlen@s	PTR const unsigned char  size(2) Largest target is 15
;;		 -> STR_44(CODE[5]), STR_33(CODE[12]), STR_32(CODE[12]), STR_30(CODE[7]), 
;;		 -> STR_26(CODE[9]), ATCommand_ErrString(BANK1[15]), STR_5(CODE[5]), ATCommand_OkString(BANK1[15]), 
;;
;; strlen@cp	PTR const unsigned char  size(2) Largest target is 15
;;		 -> STR_44(CODE[5]), STR_33(CODE[12]), STR_32(CODE[12]), STR_30(CODE[7]), 
;;		 -> STR_26(CODE[9]), ATCommand_ErrString(BANK1[15]), STR_5(CODE[5]), ATCommand_OkString(BANK1[15]), 
;;
;; strchr@ptr	PTR const unsigned char  size(2) Largest target is 128
;;		 -> ATCommand_RxList(BIGRAM[100]), RAM(NULL[128]), 
;;
;; sp__strchr	PTR unsigned char  size(2) Largest target is 128
;;		 -> ATCommand_RxList(BIGRAM[100]), RAM(NULL[128]), 
;;
;; strstr@s2	PTR const unsigned char  size(2) Largest target is 15
;;		 -> STR_44(CODE[5]), STR_33(CODE[12]), STR_32(CODE[12]), STR_30(CODE[7]), 
;;		 -> STR_26(CODE[9]), ATCommand_ErrString(BANK1[15]), STR_5(CODE[5]), ATCommand_OkString(BANK1[15]), 
;;
;; strstr@s1	PTR const unsigned char  size(2) Largest target is 128
;;		 -> ATCommand_RxList(BIGRAM[100]), RAM(NULL[128]), 
;;
;; strcpy@from	PTR const unsigned char  size(2) Largest target is 11
;;		 -> STR_53(CODE[6]), STR_52(CODE[3]), STR_51(CODE[6]), STR_50(CODE[3]), 
;;		 -> STR_48(CODE[6]), STR_47(CODE[3]), STR_41(CODE[11]), STR_20(CODE[6]), 
;;		 -> STR_19(CODE[5]), STR_8(CODE[2]), STR_2(CODE[11]), 
;;
;; strcpy@to	PTR unsigned char  size(1) Largest target is 15
;;		 -> ATCommand_ErrString(BANK1[15]), ATCommand_OkString(BANK1[15]), 
;;
;; strcpy@cp	PTR unsigned char  size(1) Largest target is 15
;;		 -> ATCommand_ErrString(BANK1[15]), ATCommand_OkString(BANK1[15]), 
;;
;; atoi@s	PTR const unsigned char  size(2) Largest target is 128
;;		 -> ATCommand_RxList(BIGRAM[100]), RAM(NULL[128]), 
;;
;; GetVerify_CRC8@pBuff	PTR unsigned char  size(1) Largest target is 9
;;		 -> DS18X20_Scratchpad(BANK1[9]), 
;;
;; GetVerify_Sum@pBuff	PTR unsigned char  size(1) Largest target is 2
;;		 -> RomParams(BANK0[2]), 
;;
;; Uart1_PutString@pString	PTR const unsigned char  size(2) Largest target is 45
;;		 -> STR_49(CODE[3]), STR_46(CODE[12]), STR_45(CODE[15]), STR_43(CODE[15]), 
;;		 -> STR_42(CODE[45]), STR_40(CODE[14]), STR_39(CODE[4]), STR_38(CODE[10]), 
;;		 -> STR_37(CODE[10]), STR_36(CODE[23]), STR_35(CODE[33]), STR_34(CODE[11]), 
;;		 -> STR_31(CODE[11]), STR_29(CODE[8]), STR_28(CODE[11]), STR_27(CODE[13]), 
;;		 -> STR_25(CODE[10]), STR_24(CODE[9]), STR_23(CODE[6]), STR_22(CODE[5]), 
;;		 -> STR_21(CODE[4]), STR_18(CODE[5]), STR_17(CODE[5]), STR_16(CODE[9]), 
;;		 -> STR_15(CODE[5]), STR_14(CODE[5]), STR_13(CODE[9]), STR_12(CODE[5]), 
;;		 -> STR_11(CODE[5]), ICCID(BANK1[21]), STR_10(CODE[9]), STR_9(CODE[12]), 
;;		 -> STR_7(CODE[12]), STR_6(CODE[15]), STR_4(CODE[15]), STR_3(CODE[45]), 
;;		 -> STR_1(CODE[14]), 
;;
;; ATCommand_WaitData@strx	PTR unsigned char  size(2) Largest target is 128
;;		 -> ATCommand_RxList(BIGRAM[100]), RAM(NULL[128]), 
;;
;; ATCommand_SendCmd@cmd	PTR const unsigned char  size(2) Largest target is 45
;;		 -> STR_46(CODE[12]), STR_45(CODE[15]), STR_43(CODE[15]), STR_42(CODE[45]), 
;;		 -> STR_40(CODE[14]), STR_39(CODE[4]), STR_38(CODE[10]), STR_37(CODE[10]), 
;;		 -> STR_36(CODE[23]), STR_35(CODE[33]), STR_34(CODE[11]), STR_31(CODE[11]), 
;;		 -> STR_29(CODE[8]), STR_28(CODE[11]), STR_27(CODE[13]), STR_25(CODE[10]), 
;;		 -> STR_24(CODE[9]), STR_23(CODE[6]), STR_22(CODE[5]), STR_21(CODE[4]), 
;;		 -> STR_9(CODE[12]), STR_7(CODE[12]), STR_6(CODE[15]), STR_4(CODE[15]), 
;;		 -> STR_3(CODE[45]), STR_1(CODE[14]), 
;;
;; ATCommand_SendCmd@strx	PTR unsigned char  size(2) Largest target is 128
;;		 -> ATCommand_RxList(BIGRAM[100]), RAM(NULL[128]), 
;;
;; CallTestSend@strx	PTR unsigned char  size(2) Largest target is 128
;;		 -> ATCommand_RxList(BIGRAM[100]), RAM(NULL[128]), 
;;
;; InitGPRS@strx	PTR unsigned char  size(2) Largest target is 128
;;		 -> ATCommand_RxList(BIGRAM[100]), RAM(NULL[128]), 
;;
;; sp__strstr	PTR unsigned char  size(2) Largest target is 128
;;		 -> ATCommand_RxList(BIGRAM[100]), RAM(NULL[128]), 
;;
;; sp__strcpy	PTR unsigned char  size(1) Largest target is 15
;;		 -> ATCommand_ErrString(BANK1[15]), ATCommand_OkString(BANK1[15]), 
;;
;; CallSend@strx	PTR unsigned char  size(2) Largest target is 128
;;		 -> ATCommand_RxList(BIGRAM[100]), RAM(NULL[128]), 
;;


;;
;; Critical Paths under _main in COMMON
;;
;;   None.
;;
;; Critical Paths under _highISR in COMMON
;;
;;   _highISR->_ATCommand_ProcRx
;;   _ATCommand_ProcRx->_isgraph
;;
;; Critical Paths under _main in BANK0
;;
;;   _main->_TestProc
;;   _TestProc->_CallTestProc
;;   _CallTestProc->_CallTestSend
;;   _CallProc->_CallSend
;;   _InitSystem->_ReadTData
;;   _CallTestSend->_InteractServer
;;   _CallSend->_InteractServer
;;   _ReadTData->_DS18X20_ReadMeas
;;   _InteractServer->_ATCommand_SendCmd
;;   _InitGPRS->_ATCommand_SendCmd
;;   _PowerON->_ATCommand_SendCmd
;;   _DS18X20_ReadMeas->_GetVerify_CRC8
;;   _DS18X20_StartMeas->_OneWire_Command
;;   _OneWire_Command->_OneWire_WriteByte
;;   _ATCommand_WaitData->_strstr
;;   _ATCommand_SendCmd->_strstr
;;   _PowerDown->___delay_20ms
;;   _TCN75_ReadReg->_SimI2C_SendByte
;;   _TCN75_SetConfig->_SimI2C_SendByte
;;   _InitVariable->_GetRomData
;;   _InitVariable->_SaveRomData
;;   _atoi->___wmul
;;   _Uart1_PutString->_Uart1_PutChar
;;   _strstr->_strncmp
;;   _ATCommand_Init->_strcpy
;;   _SaveRomData->_GetVerify_Sum
;;   _GetRomData->_GetVerify_Sum
;;   _LcdDisplay_Err->___lbmod
;;   _LcdDisplay_CurTemp->___lbmod
;;   _LcdDisplay_CSQ->___lbmod
;;   _strncmp->_strlen
;;
;; Critical Paths under _highISR in BANK0
;;
;;   None.
;;
;; Critical Paths under _main in BANK1
;;
;;   None.
;;
;; Critical Paths under _highISR in BANK1
;;
;;   None.
;;
;; Critical Paths under _main in BANK2
;;
;;   None.
;;
;; Critical Paths under _highISR in BANK2
;;
;;   None.
;;
;; Critical Paths under _main in BANK3
;;
;;   None.
;;
;; Critical Paths under _highISR in BANK3
;;
;;   None.
;;
;; Critical Paths under _main in BANK4
;;
;;   None.
;;
;; Critical Paths under _highISR in BANK4
;;
;;   None.
;;
;; Critical Paths under _main in BANK5
;;
;;   None.
;;
;; Critical Paths under _highISR in BANK5
;;
;;   None.
;;
;; Critical Paths under _main in BANK6
;;
;;   None.
;;
;; Critical Paths under _highISR in BANK6
;;
;;   None.

;;
;;Main: autosize = 0, tempsize = 2, incstack = 0, save=0
;;

;;
;;Call Graph Tables:
;;
;; ---------------------------------------------------------------------------------
;; (Depth) Function   	        Calls       Base Space   Used Autos Params    Refs
;; ---------------------------------------------------------------------------------
;; (0) _main                                                 4     4      0   33029
;;                                             45 BANK0      4     4      0
;;                         _InitSystem
;;                       ___delay_20ms
;;                           _TestProc
;;                          _ReadTData
;;                           _CallProc
;;                             ___bmul
;;                       _eeprom_write
;; ---------------------------------------------------------------------------------
;; (1) _TestProc                                             2     2      0   14672
;;                                             43 BANK0      2     2      0
;;                      _LcdDisplayAll
;;                       ___delay_20ms
;;                          _ReadTData
;;                     _LcdDisplay_Err
;;                       _CallTestProc
;; ---------------------------------------------------------------------------------
;; (2) _CallTestProc                                         1     1      0   11853
;;                                             42 BANK0      1     1      0
;;                            _PowerON
;;                       _CallTestSend
;;                          _PowerDown
;;                 _LcdDisplay_CurTemp
;;                       ___delay_20ms
;;                     _LcdDisplay_Err
;; ---------------------------------------------------------------------------------
;; (1) _CallProc                                             1     1      0   12264
;;                                             43 BANK0      1     1      0
;;                            _PowerON
;;                           _CallSend
;;                          _PowerDown
;;                 _LcdDisplay_CurTemp
;;                       ___delay_20ms
;;                     _LcdDisplay_Err
;; ---------------------------------------------------------------------------------
;; (1) _InitSystem                                           1     1      0    3402
;;                                             13 BANK0      1     1      0
;;                            _InitMCU
;;                       _InitVariable
;;                        _DisplayInit
;;                     _ATCommand_Init
;;                      _OneWire_Reset
;;                         _TCN75_Init
;;                    _TCN75_SetConfig
;;                       ___delay_20ms
;;                          _ReadTData
;; ---------------------------------------------------------------------------------
;; (3) _CallTestSend                                         3     3      0    9619
;;                                             39 BANK0      3     3      0
;;                           _InitGPRS
;;                  _ATCommand_SendCmd
;;                             _strcpy
;;                       ___delay_20ms
;;                     _InteractServer
;;                             _strstr
;; ---------------------------------------------------------------------------------
;; (2) _CallSend                                             4     4      0   10030
;;                                             39 BANK0      4     4      0
;;                           _InitGPRS
;;                       ___delay_20ms
;;                  _ATCommand_SendCmd
;;                             _strcpy
;;                     _InteractServer
;;                             _strstr
;;                        _SaveRomData
;; ---------------------------------------------------------------------------------
;; (1) _ReadTData                                            1     1      0    2304
;;                                             12 BANK0      1     1      0
;;                  _DS18X20_StartMeas
;;                       ___delay_20ms
;;                   _DS18X20_ReadMeas
;;                    _TCN75_SetConfig
;;                      _TCN75_ReadReg
;;                 _LcdDisplay_CurTemp
;; ---------------------------------------------------------------------------------
;; (3) _InteractServer                                      14    14      0    4633
;;                                             25 BANK0     14    14      0
;;                             _strcpy
;;                  _ATCommand_SendCmd
;;                      _Uart1_PutChar
;;                    _Uart1_PutString
;;                  _MakeTxTemperature
;;                             ___bmul
;;                        _eeprom_read
;;                 _ATCommand_WaitData
;;                       ___delay_20ms
;; ---------------------------------------------------------------------------------
;; (3) _InitGPRS                                             6     6      0    3224
;;                                             25 BANK0      6     6      0
;;                       ___delay_20ms
;;                  _ATCommand_SendCmd
;;                      _Uart1_PutChar
;;                             _strstr
;;                               _atoi
;;                     _LcdDisplay_CSQ
;; ---------------------------------------------------------------------------------
;; (2) _PowerON                                              1     1      0    1149
;;                                             25 BANK0      1     1      0
;;                          _PowerDown
;;                       ___delay_20ms
;;                  _ATCommand_SendCmd
;; ---------------------------------------------------------------------------------
;; (2) _DS18X20_ReadMeas                                     2     2      0     763
;;                                             10 BANK0      2     2      0
;;                      _OneWire_Reset
;;                    _OneWire_Command
;;                   _OneWire_ReadByte
;;                     _GetVerify_CRC8
;; ---------------------------------------------------------------------------------
;; (2) _DS18X20_StartMeas                                    0     0      0     285
;;                      _OneWire_Reset
;;                    _OneWire_Command
;; ---------------------------------------------------------------------------------
;; (3) _OneWire_Command                                      1     1      0     215
;;                                              4 BANK0      1     1      0
;;                      _OneWire_Reset
;;                  _OneWire_WriteByte
;; ---------------------------------------------------------------------------------
;; (4) _ATCommand_WaitData                                   5     5      0     749
;;                                             17 BANK0      5     5      0
;;                             _strstr
;;                             _strcpy
;; ---------------------------------------------------------------------------------
;; (4) _ATCommand_SendCmd                                    8     6      2    1000
;;                                             17 BANK0      8     6      2
;;                    _Uart1_PutString
;;                             _strstr
;;                       ___delay_20ms
;;                             _strcpy
;; ---------------------------------------------------------------------------------
;; (2) _PowerDown                                            1     1      0      90
;;                                              4 BANK0      1     1      0
;;                       ___delay_20ms
;; ---------------------------------------------------------------------------------
;; (2) _TCN75_ReadReg                                        3     3      0     383
;;                                              3 BANK0      3     3      0
;;                       _SimI2C_Start
;;                    _SimI2C_SendByte
;;                      _SimI2C_RecAck
;;                    _SimI2C_ReadByte
;;                         _SimI2C_Ack
;;                       _SimI2C_NoAck
;;                        _SimI2C_Stop
;; ---------------------------------------------------------------------------------
;; (2) _TCN75_SetConfig                                      2     2      0     244
;;                                              3 BANK0      2     2      0
;;                       _SimI2C_Start
;;                    _SimI2C_SendByte
;;                      _SimI2C_RecAck
;;                        _SimI2C_Stop
;; ---------------------------------------------------------------------------------
;; (2) _InitVariable                                         0     0      0     621
;;                         _GetRomData
;;                        _SaveRomData
;; ---------------------------------------------------------------------------------
;; (3) _SimI2C_Stop                                          0     0      0       0
;; ---------------------------------------------------------------------------------
;; (3) _SimI2C_NoAck                                         0     0      0       0
;; ---------------------------------------------------------------------------------
;; (3) _SimI2C_Ack                                           0     0      0       0
;; ---------------------------------------------------------------------------------
;; (3) _SimI2C_ReadByte                                      2     2      0     108
;;                                              0 BANK0      2     2      0
;; ---------------------------------------------------------------------------------
;; (3) _SimI2C_RecAck                                        1     1      0      34
;;                                              0 BANK0      1     1      0
;; ---------------------------------------------------------------------------------
;; (3) _SimI2C_SendByte                                      3     3      0     139
;;                                              0 BANK0      3     3      0
;; ---------------------------------------------------------------------------------
;; (3) _SimI2C_Start                                         0     0      0       0
;; ---------------------------------------------------------------------------------
;; (4) _OneWire_WriteByte                                    4     4      0     114
;;                                              0 BANK0      4     4      0
;; ---------------------------------------------------------------------------------
;; (3) _OneWire_ReadByte                                     4     4      0     115
;;                                              0 BANK0      4     4      0
;; ---------------------------------------------------------------------------------
;; (4) _atoi                                                 9     7      2     569
;;                                              6 BANK0      9     7      2
;;                             ___wmul
;;                            _isdigit
;; ---------------------------------------------------------------------------------
;; (4) _Uart1_PutString                                      3     1      2     130
;;                                              1 BANK0      3     1      2
;;                      _Uart1_PutChar
;; ---------------------------------------------------------------------------------
;; (3) _strstr                                               4     0      4     562
;;                                             13 BANK0      4     0      4
;;                             _strlen
;;                            _strncmp
;;                             _strchr
;; ---------------------------------------------------------------------------------
;; (2) ___delay_20ms                                         4     2      2      22
;;                                              0 BANK0      4     2      2
;; ---------------------------------------------------------------------------------
;; (2) _TCN75_Init                                           0     0      0       0
;;                        _SimI2C_Init
;; ---------------------------------------------------------------------------------
;; (4) _OneWire_Reset                                        3     3      0      70
;;                                              0 BANK0      3     3      0
;; ---------------------------------------------------------------------------------
;; (2) _ATCommand_Init                                       0     0      0      73
;;                             _strcpy
;; ---------------------------------------------------------------------------------
;; (3) _SaveRomData                                          1     1      0     312
;;                                              7 BANK0      1     1      0
;;                      _GetVerify_Sum
;;                       _eeprom_write
;; ---------------------------------------------------------------------------------
;; (3) _GetRomData                                           1     1      0     309
;;                                              7 BANK0      1     1      0
;;                        _eeprom_read
;;                      _GetVerify_Sum
;; ---------------------------------------------------------------------------------
;; (2) _LcdDisplay_Err                                       0     0      0     400
;;                            ___lbdiv
;;                            ___lbmod
;;                      _LcdDisplayNum
;; ---------------------------------------------------------------------------------
;; (2) _LcdDisplay_CurTemp                                   4     4      0     536
;;                                              5 BANK0      4     4      0
;;                            ___lbdiv
;;                            ___lbmod
;;                      _LcdDisplayNum
;; ---------------------------------------------------------------------------------
;; (4) _LcdDisplay_CSQ                                       2     2      0     468
;;                                              5 BANK0      2     2      0
;;                            ___lbdiv
;;                            ___lbmod
;;                      _LcdDisplayNum
;; ---------------------------------------------------------------------------------
;; (2) _LcdDisplayAll                                        1     1      0      93
;;                                              0 BANK0      1     1      0
;;                      _LcdDisplayNum
;; ---------------------------------------------------------------------------------
;; (3) ___lbmod                                              5     4      1     159
;;                                              0 BANK0      5     4      1
;; ---------------------------------------------------------------------------------
;; (3) ___lbdiv                                              4     3      1     241
;;                                              0 BANK0      4     3      1
;; ---------------------------------------------------------------------------------
;; (5) ___wmul                                               6     2      4     136
;;                                              0 BANK0      6     2      4
;; ---------------------------------------------------------------------------------
;; (1) ___bmul                                               3     2      1     136
;;                                              0 BANK0      3     2      1
;; ---------------------------------------------------------------------------------
;; (4) _strchr                                               6     2      4      88
;;                                              0 BANK0      6     2      4
;; ---------------------------------------------------------------------------------
;; (4) _strncmp                                              7     1      6     134
;;                                              6 BANK0      7     1      6
;;                             _strlen (ARG)
;; ---------------------------------------------------------------------------------
;; (4) _strlen                                               6     4      2      89
;;                                              0 BANK0      6     4      2
;; ---------------------------------------------------------------------------------
;; (5) _isdigit                                              2     2      0      99
;;                                              0 BANK0      2     2      0
;; ---------------------------------------------------------------------------------
;; (3) _SimI2C_Init                                          0     0      0       0
;; ---------------------------------------------------------------------------------
;; (3) _GetVerify_CRC8                                      10     8      2     233
;;                                              0 BANK0     10     8      2
;; ---------------------------------------------------------------------------------
;; (4) _GetVerify_Sum                                        7     5      2     120
;;                                              0 BANK0      7     5      2
;; ---------------------------------------------------------------------------------
;; (4) _eeprom_read                                          3     3      0      22
;;                                              0 BANK0      3     3      0
;; ---------------------------------------------------------------------------------
;; (4) _MakeTxTemperature                                    3     1      2     556
;;                                              0 BANK0      3     1      2
;; ---------------------------------------------------------------------------------
;; (5) _Uart1_PutChar                                        1     1      0      31
;;                                              0 BANK0      1     1      0
;; ---------------------------------------------------------------------------------
;; (5) _strcpy                                               6     4      2      73
;;                                              0 BANK0      6     4      2
;; ---------------------------------------------------------------------------------
;; (1) _eeprom_write                                         2     1      1      62
;;                                              0 BANK0      2     1      1
;; ---------------------------------------------------------------------------------
;; (2) _InitMCU                                              0     0      0       0
;; ---------------------------------------------------------------------------------
;; (2) _DisplayInit                                          0     0      0       0
;; ---------------------------------------------------------------------------------
;; (3) _LcdDisplayNum                                        0     0      0       0
;; ---------------------------------------------------------------------------------
;; Estimated maximum stack depth 5
;; ---------------------------------------------------------------------------------
;; (Depth) Function   	        Calls       Base Space   Used Autos Params    Refs
;; ---------------------------------------------------------------------------------
;; (8) _highISR                                              1     1      0     179
;;                                              6 COMMON     1     1      0
;;                   _ATCommand_ProcRx
;; ---------------------------------------------------------------------------------
;; (9) _ATCommand_ProcRx                                     4     4      0     156
;;                                              2 COMMON     4     4      0
;;                            _isgraph
;; ---------------------------------------------------------------------------------
;; (10) _isgraph                                             2     2      0      68
;;                                              0 COMMON     2     2      0
;; ---------------------------------------------------------------------------------
;; Estimated maximum stack depth 10
;; ---------------------------------------------------------------------------------

;; Call Graph Graphs:

;; _main (ROOT)
;;   _InitSystem
;;     _InitMCU
;;     _InitVariable
;;       _GetRomData
;;         _eeprom_read
;;         _GetVerify_Sum
;;       _SaveRomData
;;         _GetVerify_Sum
;;         _eeprom_write
;;     _DisplayInit
;;     _ATCommand_Init
;;       _strcpy
;;     _OneWire_Reset
;;     _TCN75_Init
;;       _SimI2C_Init
;;     _TCN75_SetConfig
;;       _SimI2C_Start
;;       _SimI2C_SendByte
;;       _SimI2C_RecAck
;;       _SimI2C_Stop
;;     ___delay_20ms
;;     _ReadTData
;;       _DS18X20_StartMeas
;;         _OneWire_Reset
;;         _OneWire_Command
;;           _OneWire_Reset
;;           _OneWire_WriteByte
;;       ___delay_20ms
;;       _DS18X20_ReadMeas
;;         _OneWire_Reset
;;         _OneWire_Command
;;           _OneWire_Reset
;;           _OneWire_WriteByte
;;         _OneWire_ReadByte
;;         _GetVerify_CRC8
;;       _TCN75_SetConfig
;;         _SimI2C_Start
;;         _SimI2C_SendByte
;;         _SimI2C_RecAck
;;         _SimI2C_Stop
;;       _TCN75_ReadReg
;;         _SimI2C_Start
;;         _SimI2C_SendByte
;;         _SimI2C_RecAck
;;         _SimI2C_ReadByte
;;         _SimI2C_Ack
;;         _SimI2C_NoAck
;;         _SimI2C_Stop
;;       _LcdDisplay_CurTemp
;;         ___lbdiv
;;         ___lbmod
;;         _LcdDisplayNum
;;   ___delay_20ms
;;   _TestProc
;;     _LcdDisplayAll
;;       _LcdDisplayNum
;;     ___delay_20ms
;;     _ReadTData
;;       _DS18X20_StartMeas
;;         _OneWire_Reset
;;         _OneWire_Command
;;           _OneWire_Reset
;;           _OneWire_WriteByte
;;       ___delay_20ms
;;       _DS18X20_ReadMeas
;;         _OneWire_Reset
;;         _OneWire_Command
;;           _OneWire_Reset
;;           _OneWire_WriteByte
;;         _OneWire_ReadByte
;;         _GetVerify_CRC8
;;       _TCN75_SetConfig
;;         _SimI2C_Start
;;         _SimI2C_SendByte
;;         _SimI2C_RecAck
;;         _SimI2C_Stop
;;       _TCN75_ReadReg
;;         _SimI2C_Start
;;         _SimI2C_SendByte
;;         _SimI2C_RecAck
;;         _SimI2C_ReadByte
;;         _SimI2C_Ack
;;         _SimI2C_NoAck
;;         _SimI2C_Stop
;;       _LcdDisplay_CurTemp
;;         ___lbdiv
;;         ___lbmod
;;         _LcdDisplayNum
;;     _LcdDisplay_Err
;;       ___lbdiv
;;       ___lbmod
;;       _LcdDisplayNum
;;     _CallTestProc
;;       _PowerON
;;         _PowerDown
;;           ___delay_20ms
;;         ___delay_20ms
;;         _ATCommand_SendCmd
;;           _Uart1_PutString
;;             _Uart1_PutChar
;;           _strstr
;;             _strlen
;;             _strncmp
;;               _strlen (ARG)
;;             _strchr
;;           ___delay_20ms
;;           _strcpy
;;       _CallTestSend
;;         _InitGPRS
;;           ___delay_20ms
;;           _ATCommand_SendCmd
;;             _Uart1_PutString
;;               _Uart1_PutChar
;;             _strstr
;;               _strlen
;;               _strncmp
;;                 _strlen (ARG)
;;               _strchr
;;             ___delay_20ms
;;             _strcpy
;;           _Uart1_PutChar
;;           _strstr
;;             _strlen
;;             _strncmp
;;               _strlen (ARG)
;;             _strchr
;;           _atoi
;;             ___wmul
;;             _isdigit
;;           _LcdDisplay_CSQ
;;             ___lbdiv
;;             ___lbmod
;;             _LcdDisplayNum
;;         _ATCommand_SendCmd
;;           _Uart1_PutString
;;             _Uart1_PutChar
;;           _strstr
;;             _strlen
;;             _strncmp
;;               _strlen (ARG)
;;             _strchr
;;           ___delay_20ms
;;           _strcpy
;;         _strcpy
;;         ___delay_20ms
;;         _InteractServer
;;           _strcpy
;;           _ATCommand_SendCmd
;;             _Uart1_PutString
;;               _Uart1_PutChar
;;             _strstr
;;               _strlen
;;               _strncmp
;;                 _strlen (ARG)
;;               _strchr
;;             ___delay_20ms
;;             _strcpy
;;           _Uart1_PutChar
;;           _Uart1_PutString
;;             _Uart1_PutChar
;;           _MakeTxTemperature
;;           ___bmul
;;           _eeprom_read
;;           _ATCommand_WaitData
;;             _strstr
;;               _strlen
;;               _strncmp
;;                 _strlen (ARG)
;;               _strchr
;;             _strcpy
;;           ___delay_20ms
;;         _strstr
;;           _strlen
;;           _strncmp
;;             _strlen (ARG)
;;           _strchr
;;       _PowerDown
;;         ___delay_20ms
;;       _LcdDisplay_CurTemp
;;         ___lbdiv
;;         ___lbmod
;;         _LcdDisplayNum
;;       ___delay_20ms
;;       _LcdDisplay_Err
;;         ___lbdiv
;;         ___lbmod
;;         _LcdDisplayNum
;;   _ReadTData
;;     _DS18X20_StartMeas
;;       _OneWire_Reset
;;       _OneWire_Command
;;         _OneWire_Reset
;;         _OneWire_WriteByte
;;     ___delay_20ms
;;     _DS18X20_ReadMeas
;;       _OneWire_Reset
;;       _OneWire_Command
;;         _OneWire_Reset
;;         _OneWire_WriteByte
;;       _OneWire_ReadByte
;;       _GetVerify_CRC8
;;     _TCN75_SetConfig
;;       _SimI2C_Start
;;       _SimI2C_SendByte
;;       _SimI2C_RecAck
;;       _SimI2C_Stop
;;     _TCN75_ReadReg
;;       _SimI2C_Start
;;       _SimI2C_SendByte
;;       _SimI2C_RecAck
;;       _SimI2C_ReadByte
;;       _SimI2C_Ack
;;       _SimI2C_NoAck
;;       _SimI2C_Stop
;;     _LcdDisplay_CurTemp
;;       ___lbdiv
;;       ___lbmod
;;       _LcdDisplayNum
;;   _CallProc
;;     _PowerON
;;       _PowerDown
;;         ___delay_20ms
;;       ___delay_20ms
;;       _ATCommand_SendCmd
;;         _Uart1_PutString
;;           _Uart1_PutChar
;;         _strstr
;;           _strlen
;;           _strncmp
;;             _strlen (ARG)
;;           _strchr
;;         ___delay_20ms
;;         _strcpy
;;     _CallSend
;;       _InitGPRS
;;         ___delay_20ms
;;         _ATCommand_SendCmd
;;           _Uart1_PutString
;;             _Uart1_PutChar
;;           _strstr
;;             _strlen
;;             _strncmp
;;               _strlen (ARG)
;;             _strchr
;;           ___delay_20ms
;;           _strcpy
;;         _Uart1_PutChar
;;         _strstr
;;           _strlen
;;           _strncmp
;;             _strlen (ARG)
;;           _strchr
;;         _atoi
;;           ___wmul
;;           _isdigit
;;         _LcdDisplay_CSQ
;;           ___lbdiv
;;           ___lbmod
;;           _LcdDisplayNum
;;       ___delay_20ms
;;       _ATCommand_SendCmd
;;         _Uart1_PutString
;;           _Uart1_PutChar
;;         _strstr
;;           _strlen
;;           _strncmp
;;             _strlen (ARG)
;;           _strchr
;;         ___delay_20ms
;;         _strcpy
;;       _strcpy
;;       _InteractServer
;;         _strcpy
;;         _ATCommand_SendCmd
;;           _Uart1_PutString
;;             _Uart1_PutChar
;;           _strstr
;;             _strlen
;;             _strncmp
;;               _strlen (ARG)
;;             _strchr
;;           ___delay_20ms
;;           _strcpy
;;         _Uart1_PutChar
;;         _Uart1_PutString
;;           _Uart1_PutChar
;;         _MakeTxTemperature
;;         ___bmul
;;         _eeprom_read
;;         _ATCommand_WaitData
;;           _strstr
;;             _strlen
;;             _strncmp
;;               _strlen (ARG)
;;             _strchr
;;           _strcpy
;;         ___delay_20ms
;;       _strstr
;;         _strlen
;;         _strncmp
;;           _strlen (ARG)
;;         _strchr
;;       _SaveRomData
;;         _GetVerify_Sum
;;         _eeprom_write
;;     _PowerDown
;;       ___delay_20ms
;;     _LcdDisplay_CurTemp
;;       ___lbdiv
;;       ___lbmod
;;       _LcdDisplayNum
;;     ___delay_20ms
;;     _LcdDisplay_Err
;;       ___lbdiv
;;       ___lbmod
;;       _LcdDisplayNum
;;   ___bmul
;;   _eeprom_write
;;
;; _highISR (ROOT)
;;   _ATCommand_ProcRx
;;     _isgraph
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
;;COMMON               E      7       E       2      100.0%
;;BITSFR1              0      0       0       2        0.0%
;;SFR1                 0      0       0       2        0.0%
;;BITSFR2              0      0       0       3        0.0%
;;SFR2                 0      0       0       3        0.0%
;;STACK                0      0       D       3        0.0%
;;BITSFR3              0      0       0       4        0.0%
;;SFR3                 0      0       0       4        0.0%
;;ABS                  0      0      B2       4        0.0%
;;BITBANK0            4F      0       0       5        0.0%
;;BITSFR4              0      0       0       5        0.0%
;;SFR4                 0      0       0       5        0.0%
;;BANK0               4F     31      4E       6       98.7%
;;BITSFR5              0      0       0       6        0.0%
;;SFR5                 0      0       0       6        0.0%
;;BITBANK1            50      0       0       7        0.0%
;;BITSFR6              0      0       0       7        0.0%
;;SFR6                 0      0       0       7        0.0%
;;BANK1               50      0      3E       8       77.5%
;;BITSFR7              0      0       0       8        0.0%
;;SFR7                 0      0       0       8        0.0%
;;BITBANK2            50      0       0       9        0.0%
;;BITSFR8              0      0       0       9        0.0%
;;SFR8                 0      0       0       9        0.0%
;;BANK2               50      0      18      10       30.0%
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
;;BANK4               4C      0       0      14        0.0%
;;BITSFR13             0      0       0      14        0.0%
;;SFR13                0      0       0      14        0.0%
;;BITBANK5            50      0       0      15        0.0%
;;BITSFR14             0      0       0      15        0.0%
;;SFR14                0      0       0      15        0.0%
;;BITSFR15             0      0       0      16        0.0%
;;SFR15                0      0       0      16        0.0%
;;BANK5                0      0       0      16        0.0%
;;BITBANK6            10      0       0      17        0.0%
;;BITSFR16             0      0       0      17        0.0%
;;SFR16                0      0       0      17        0.0%
;;BITSFR17             0      0       0      18        0.0%
;;SFR17                0      0       0      18        0.0%
;;BANK6                0      0       0      18        0.0%
;;BITSFR18             0      0       0      19        0.0%
;;SFR18                0      0       0      19        0.0%
;;DATA                 0      0      BF      19        0.0%
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
;;		line 12 in file "F:\work\WYP\NBIoT\Main.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;  i               1   48[BANK0 ] unsigned char 
;;  addr            1   47[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, fsr0l, fsr0h, fsr1l, fsr1h, status,2, status,0, btemp+0, pclath, cstack
;; Tracked objects:
;;		On entry : 17F/0
;;		On exit  : 1F/F
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       0       0       0       0       0       0       0
;;      Locals:         0       2       0       0       0       0       0       0
;;      Temps:          0       2       0       0       0       0       0       0
;;      Totals:         0       4       0       0       0       0       0       0
;;Total ram usage:        4 bytes
;; Hardware stack levels required when called:   10
;; This function calls:
;;		_InitSystem
;;		___delay_20ms
;;		_TestProc
;;		_ReadTData
;;		_CallProc
;;		___bmul
;;		_eeprom_write
;; This function is called by:
;;		Startup code after reset
;; This function uses a non-reentrant model
;;
psect	maintext
	file	"F:\work\WYP\NBIoT\Main.c"
	line	12
	global	__size_of_main
	__size_of_main	equ	__end_of_main-_main
	
_main:	
	opt	stack 14
; Regs used in _main: [wreg-btemp+0+pclath+cstack]
	line	14
	
l34134:	
;Main.c: 13: unsigned char addr,i;
;Main.c: 14: InitSystem();
	fcall	_InitSystem
	line	15
	
l34136:	
;Main.c: 15: __delay_20ms(250);
	movlw	0FAh
	movwf	(?___delay_20ms)
	clrf	(?___delay_20ms+1)
	fcall	___delay_20ms
	line	16
	
l34138:	
;Main.c: 16: gFlags.bFirst=1;
	bsf	(_gFlags),2
	line	17
	
l34140:	
;Main.c: 17: TestProc();
	fcall	_TestProc
	line	18
	
l34142:	
;Main.c: 18: ReadTData();
	fcall	_ReadTData
	line	19
	
l34144:	
;Main.c: 19: CallProc();
	fcall	_CallProc
	line	20
	
l34146:	
;Main.c: 20: gFlags.bFirst=0;
	movlb 0	; select bank0
	bcf	(_gFlags),2
	line	21
	
l34148:	
;Main.c: 21: MeasurementTick=SystemTick;
	movf	(_SystemTick+1),w
	movwf	(_MeasurementTick+1)
	movf	(_SystemTick),w
	movwf	(_MeasurementTick)
	line	24
	
l34150:	
;Main.c: 23: {
;Main.c: 24: if(RB2==0)
	movlb 0	; select bank0
	btfsc	(106/8),(106)&7
	goto	u9991
	goto	u9990
u9991:
	goto	l34164
u9990:
	line	26
	
l34152:	
;Main.c: 25: {
;Main.c: 26: _delay((unsigned long)((20)*(4000000/4000.0)));
	opt asmopt_off
movlw	26
movwf	((??_main+0)+0+1),f
	movlw	248
movwf	((??_main+0)+0),f
u10107:
	decfsz	((??_main+0)+0),f
	goto	u10107
	decfsz	((??_main+0)+0+1),f
	goto	u10107
	clrwdt
opt asmopt_on

	line	27
	
l34154:	
;Main.c: 27: if(RB2==0)
	movlb 0	; select bank0
	btfsc	(106/8),(106)&7
	goto	u10001
	goto	u10000
u10001:
	goto	l34164
u10000:
	line	29
	
l34156:	
;Main.c: 28: {
;Main.c: 29: gFlags.bNotify=1;
	bsf	(_gFlags),0
	line	30
	
l34158:	
;Main.c: 30: ReadTData();
	fcall	_ReadTData
	line	31
	
l34160:	
;Main.c: 31: CallProc();
	fcall	_CallProc
	line	32
	
l34162:	
;Main.c: 32: gFlags.bNotify=0;
	movlb 0	; select bank0
	bcf	(_gFlags),0
	line	35
	
l34164:	
;Main.c: 33: }
;Main.c: 34: }
;Main.c: 35: if((SystemTick-RunTick)>20)
	movlb 1	; select bank1
	movf	(_RunTick)^080h,w
	movlb 0	; select bank0
	subwf	(_SystemTick),w
	movwf	(??_main+0)+0
	movlb 1	; select bank1
	movf	(_RunTick+1)^080h,w
	movlb 0	; select bank0
	subwfb	(_SystemTick+1),w
	movwf	1+(??_main+0)+0
	movlw	high(015h)
	subwf	1+(??_main+0)+0,w
	movlw	low(015h)
	skipnz
	subwf	0+(??_main+0)+0,w
	skipc
	goto	u10011
	goto	u10010
u10011:
	goto	l34170
u10010:
	line	37
	
l34166:	
;Main.c: 36: {
;Main.c: 37: RunTick=SystemTick;
	movf	(_SystemTick+1),w
	movlb 1	; select bank1
	movwf	(_RunTick+1)^080h
	movlb 0	; select bank0
	movf	(_SystemTick),w
	movlb 1	; select bank1
	movwf	(_RunTick)^080h
	line	39
;Main.c: 39: while(WA==0);
	
l6522:	
	movlb 15	; select bank15
	btfss	(15508/8)^0780h,(15508)&7
	goto	u10021
	goto	u10020
u10021:
	goto	l6522
u10020:
	line	40
	
l34168:	
;Main.c: 40: SEG21COM3=!SEG21COM3;
	movlw	1<<((15709)&7)
	xorwf	((15709)/8)^0780h,f
	line	43
	
l34170:	
;Main.c: 42: }
;Main.c: 43: if((SystemTick-MeasurementTick)>NeedMeasurementTick)
	movf	(_MeasurementTick),w
	movlb 0	; select bank0
	subwf	(_SystemTick),w
	movwf	(??_main+0)+0
	movf	(_MeasurementTick+1),w
	subwfb	(_SystemTick+1),w
	movwf	1+(??_main+0)+0
	movf	1+(??_main+0)+0,w
	subwf	(_NeedMeasurementTick+1),w
	skipz
	goto	u10035
	movf	0+(??_main+0)+0,w
	subwf	(_NeedMeasurementTick),w
u10035:
	skipnc
	goto	u10031
	goto	u10030
u10031:
	goto	l34220
u10030:
	line	45
	
l34172:	
;Main.c: 44: {
;Main.c: 45: MeasurementTick=SystemTick;
	movf	(_SystemTick+1),w
	movwf	(_MeasurementTick+1)
	movf	(_SystemTick),w
	movwf	(_MeasurementTick)
	line	46
	
l34174:	
;Main.c: 46: ReadTData();
	fcall	_ReadTData
	line	47
	
l34176:	
;Main.c: 47: TList.T[TListIndex++]=CurTemp;
	movlb 0	; select bank0
	lslf	(_TListIndex),w
	addlw	_TList&0ffh
	movwf	fsr1l
	movlw 1	; select bank2/3
	movwf fsr1h	
	
	movf	(_CurTemp),w
	movwi	[0]fsr1
	movf	(_CurTemp+1),w
	movwi	[1]fsr1
	
l34178:	
	incf	(_TListIndex),f
	line	48
	
l34180:	
;Main.c: 48: if(TListIndex>=12)
	movlw	(0Ch)
	subwf	(_TListIndex),w
	skipc
	goto	u10041
	goto	u10040
u10041:
	goto	l34220
u10040:
	line	50
	
l34182:	
;Main.c: 49: {
;Main.c: 50: CallProc();
	fcall	_CallProc
	line	51
	
l34184:	
;Main.c: 51: TListIndex=0;
	movlb 0	; select bank0
	clrf	(_TListIndex)
	line	52
	
l34186:	
;Main.c: 52: if(ErrState!=NoErr)
	movf	(_ErrState),w
	skipz
	goto	u10050
	goto	l34216
u10050:
	line	54
	
l34188:	
;Main.c: 53: {
;Main.c: 54: if(TxErrDataIndex==0xff)
	movf	(_TxErrDataIndex),w
	xorlw	0FFh&0ffh
	skipz
	goto	u10061
	goto	u10060
u10061:
	goto	l34192
u10060:
	line	55
	
l34190:	
;Main.c: 55: TxErrDataIndex=0;
	clrf	(_TxErrDataIndex)
	line	56
	
l34192:	
;Main.c: 56: addr=TxErrDataIndex*12;
	movlw	(0Ch)
	movwf	(?___bmul)
	movf	(_TxErrDataIndex),w
	fcall	___bmul
	movwf	(main@addr)
	line	57
	
l34194:	
;Main.c: 57: addr+=16;
	movlw	(010h)
	addwf	(main@addr),f
	line	58
	
l34196:	
;Main.c: 58: for(i=0;i<24;i++)
	clrf	(main@i)
	line	60
	
l34202:	
;Main.c: 59: {
;Main.c: 60: eeprom_write(addr+i,TList.All[i]);
	movf	(main@i),w
	addlw	_TList&0ffh
	movwf	fsr1l
	movlw 1	; select bank2/3
	movwf fsr1h	
	
	movf	indf1,w
	movwf	(?_eeprom_write)
	movf	(main@addr),w
	addwf	(main@i),w
	fcall	_eeprom_write
	line	58
	
l34204:	
	movlb 0	; select bank0
	incf	(main@i),f
	
l34206:	
	movlw	(018h)
	subwf	(main@i),w
	skipc
	goto	u10071
	goto	u10070
u10071:
	goto	l34202
u10070:
	line	62
	
l34208:	
;Main.c: 61: }
;Main.c: 62: TxErrDataIndex++;
	incf	(_TxErrDataIndex),f
	line	63
	
l34210:	
;Main.c: 63: if(TxErrDataIndex>=10)
	movlw	(0Ah)
	subwf	(_TxErrDataIndex),w
	skipc
	goto	u10081
	goto	u10080
u10081:
	goto	l6526
u10080:
	line	65
	
l34212:	
;Main.c: 64: {
;Main.c: 65: gFlags.bErrFull=1;
	bsf	(_gFlags),3
	line	66
	
l34214:	
;Main.c: 66: TxErrDataIndex=0;
	clrf	(_TxErrDataIndex)
	goto	l34220
	line	71
	
l34216:	
;Main.c: 69: else
;Main.c: 70: {
;Main.c: 71: TxErrDataIndex=0xff;
	movlw	(0FFh)
	movwf	(_TxErrDataIndex)
	line	72
	
l34218:	
;Main.c: 72: gFlags.bErrFull=0;
	bcf	(_gFlags),3
	goto	l34220
	line	74
	
l6526:	
	line	76
	
l34220:	
;Main.c: 73: }
;Main.c: 74: }
;Main.c: 75: }
;Main.c: 76: if(WERR==1)
	movlb 15	; select bank15
	btfss	(15501/8)^0780h,(15501)&7
	goto	u10091
	goto	u10090
u10091:
	goto	l34150
u10090:
	line	78
	
l34222:	
;Main.c: 77: {
;Main.c: 78: WERR=0;
	bcf	(15501/8)^0780h,(15501)&7
	goto	l34150
	global	start
	ljmp	start
	opt stack 0
GLOBAL	__end_of_main
	__end_of_main:
;; =============== function _main ends ============

psect	maintext
	line	81
	signat	_main,88
	global	_TestProc
psect	text2003,local,class=CODE,delta=2
global __ptext2003
__ptext2003:

;; *************** function _TestProc *****************
;; Defined at:
;;		line 9 in file "F:\work\WYP\NBIoT\TestProc.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, fsr0l, fsr0h, fsr1l, fsr1h, status,2, status,0, btemp+0, pclath, cstack
;; Tracked objects:
;;		On entry : 1F/0
;;		On exit  : 1F/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       0       0       0       0       0       0       0
;;      Locals:         0       0       0       0       0       0       0       0
;;      Temps:          0       2       0       0       0       0       0       0
;;      Totals:         0       2       0       0       0       0       0       0
;;Total ram usage:        2 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    9
;; This function calls:
;;		_LcdDisplayAll
;;		___delay_20ms
;;		_ReadTData
;;		_LcdDisplay_Err
;;		_CallTestProc
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text2003
	file	"F:\work\WYP\NBIoT\TestProc.c"
	line	9
	global	__size_of_TestProc
	__size_of_TestProc	equ	__end_of_TestProc-_TestProc
	
_TestProc:	
	opt	stack 13
; Regs used in _TestProc: [wreg-btemp+0+pclath+cstack]
	line	10
	
l34100:	
;TestProc.c: 10: if(RB7==0)
	btfsc	(111/8),(111)&7
	goto	u9941
	goto	u9940
u9941:
	goto	l10944
u9940:
	line	12
	
l34102:	
;TestProc.c: 11: {
;TestProc.c: 12: _delay((unsigned long)((20)*(4000000/4000.0)));
	opt asmopt_off
movlw	26
movwf	((??_TestProc+0)+0+1),f
	movlw	248
movwf	((??_TestProc+0)+0),f
u10117:
	decfsz	((??_TestProc+0)+0),f
	goto	u10117
	decfsz	((??_TestProc+0)+0+1),f
	goto	u10117
	clrwdt
opt asmopt_on

	line	13
	
l34104:	
;TestProc.c: 13: if(RB7==0)
	movlb 0	; select bank0
	btfsc	(111/8),(111)&7
	goto	u9951
	goto	u9950
u9951:
	goto	l10944
u9950:
	line	15
	
l34106:	
;TestProc.c: 14: {
;TestProc.c: 15: LcdDisplayAll(0);
	movlw	(0)
	fcall	_LcdDisplayAll
	line	16
;TestProc.c: 16: __delay_20ms(150);
	movlw	096h
	movlb 0	; select bank0
	movwf	(?___delay_20ms)
	clrf	(?___delay_20ms+1)
	fcall	___delay_20ms
	line	17
;TestProc.c: 17: LcdDisplayAll(1);
	movlw	(01h)
	fcall	_LcdDisplayAll
	line	18
	
l34108:	
;TestProc.c: 18: ReadTData();
	fcall	_ReadTData
	line	19
	
l34110:	
;TestProc.c: 19: if(CurTemp.u16==0xf000)
	movlb 0	; select bank0
		movf	(_CurTemp+1),w
	xorlw	240
	iorwf	(_CurTemp),w

	skipz
	goto	u9961
	goto	u9960
u9961:
	goto	l34116
u9960:
	line	21
	
l34112:	
;TestProc.c: 20: {
;TestProc.c: 21: LATA4=0;
	movlb 2	; select bank2
	bcf	(2148/8)^0100h,(2148)&7
	line	22
;TestProc.c: 22: LATA3=1;
	bsf	(2147/8)^0100h,(2147)&7
	line	23
;TestProc.c: 23: ErrState=MissT;
	movlb 0	; select bank0
	clrf	(_ErrState)
	incf	(_ErrState),f
	line	24
	
l34114:	
;TestProc.c: 24: LcdDisplay_Err();
	fcall	_LcdDisplay_Err
	line	25
;TestProc.c: 25: }
	goto	l34128
	line	28
	
l34116:	
;TestProc.c: 26: else
;TestProc.c: 27: {
;TestProc.c: 28: ErrState=NoErr;
	clrf	(_ErrState)
	line	29
	
l34118:	
;TestProc.c: 29: CallTestProc();
	fcall	_CallTestProc
	line	30
	
l34120:	
;TestProc.c: 30: if(ErrState!=NoErr)
	movlb 0	; select bank0
	movf	(_ErrState),w
	skipz
	goto	u9970
	goto	l10938
u9970:
	line	32
	
l34122:	
;TestProc.c: 31: {
;TestProc.c: 32: LATA4=0;
	movlb 2	; select bank2
	bcf	(2148/8)^0100h,(2148)&7
	line	33
;TestProc.c: 33: LATA3=1;
	bsf	(2147/8)^0100h,(2147)&7
	goto	l34114
	line	36
	
l10938:	
	line	38
;TestProc.c: 36: else
;TestProc.c: 37: {
;TestProc.c: 38: LATA4=1;
	movlb 2	; select bank2
	bsf	(2148/8)^0100h,(2148)&7
	line	39
;TestProc.c: 39: LATA3=0;
	bcf	(2147/8)^0100h,(2147)&7
	line	40
	
l34126:	
;TestProc.c: 40: LcdDisplayAll(2);
	movlw	(02h)
	fcall	_LcdDisplayAll
	line	45
	
l34128:	
;TestProc.c: 44: {
;TestProc.c: 45: if(ErrState!=NoErr)
	movlb 0	; select bank0
	movf	(_ErrState),w
	skipz
	goto	u9980
	goto	l34128
u9980:
	line	47
	
l34130:	
;TestProc.c: 46: {
;TestProc.c: 47: __delay_20ms(20);
	movlw	014h
	movwf	(?___delay_20ms)
	clrf	(?___delay_20ms+1)
	fcall	___delay_20ms
	line	48
	
l34132:	
;TestProc.c: 48: LATA3=!LATA3;
	movlw	1<<((2147)&7)
	movlb 2	; select bank2
	xorwf	((2147)/8)^0100h,f
	goto	l34128
	line	54
	
l10944:	
	return
	opt stack 0
GLOBAL	__end_of_TestProc
	__end_of_TestProc:
;; =============== function _TestProc ends ============

	signat	_TestProc,88
	global	_CallTestProc
psect	text2004,local,class=CODE,delta=2
global __ptext2004
__ptext2004:

;; *************** function _CallTestProc *****************
;; Defined at:
;;		line 56 in file "F:\work\WYP\NBIoT\TestProc.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;  retry           1   42[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, fsr0l, fsr0h, fsr1l, fsr1h, status,2, status,0, btemp+0, pclath, cstack
;; Tracked objects:
;;		On entry : 1F/0
;;		On exit  : 1F/F
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       0       0       0       0       0       0       0
;;      Locals:         0       1       0       0       0       0       0       0
;;      Temps:          0       0       0       0       0       0       0       0
;;      Totals:         0       1       0       0       0       0       0       0
;;Total ram usage:        1 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    8
;; This function calls:
;;		_PowerON
;;		_CallTestSend
;;		_PowerDown
;;		_LcdDisplay_CurTemp
;;		___delay_20ms
;;		_LcdDisplay_Err
;; This function is called by:
;;		_TestProc
;; This function uses a non-reentrant model
;;
psect	text2004
	file	"F:\work\WYP\NBIoT\TestProc.c"
	line	56
	global	__size_of_CallTestProc
	__size_of_CallTestProc	equ	__end_of_CallTestProc-_CallTestProc
	
_CallTestProc:	
	opt	stack 12
; Regs used in _CallTestProc: [wreg-btemp+0+pclath+cstack]
	line	58
	
l34062:	
;TestProc.c: 58: while(WA==0);
	
l10947:	
	movlb 15	; select bank15
	btfss	(15508/8)^0780h,(15508)&7
	goto	u9771
	goto	u9770
u9771:
	goto	l10947
u9770:
	
l10949:	
	line	59
;TestProc.c: 59: SEG5COM0=1;
	bsf	(15621/8)^0780h,(15621)&7
	line	60
;TestProc.c: 60: while(WA==0);
	
l10950:	
	btfss	(15508/8)^0780h,(15508)&7
	goto	u9781
	goto	u9780
u9781:
	goto	l10950
u9780:
	
l10952:	
	line	61
;TestProc.c: 61: SEG5COM2=1;
	bsf	(15669/8)^0780h,(15669)&7
	line	62
;TestProc.c: 62: while(WA==0);
	
l10953:	
	btfss	(15508/8)^0780h,(15508)&7
	goto	u9791
	goto	u9790
u9791:
	goto	l10953
u9790:
	
l10955:	
	line	63
;TestProc.c: 63: SEG21COM3=0;
	bcf	(15709/8)^0780h,(15709)&7
	line	64
;TestProc.c: 64: while(WA==0);
	
l10956:	
	btfss	(15508/8)^0780h,(15508)&7
	goto	u9801
	goto	u9800
u9801:
	goto	l10956
u9800:
	
l10958:	
	line	65
;TestProc.c: 65: SEG21COM2=0;
	bcf	(15685/8)^0780h,(15685)&7
	line	66
;TestProc.c: 66: if(gFlags.bNotify)
	movlb 0	; select bank0
	btfss	(_gFlags),0
	goto	u9811
	goto	u9810
u9811:
	goto	l34066
u9810:
	line	68
	
l10960:	
	movlb 15	; select bank15
	btfss	(15508/8)^0780h,(15508)&7
	goto	u9821
	goto	u9820
u9821:
	goto	l10960
u9820:
	
l10962:	
	line	69
;TestProc.c: 69: SEG22COM3=1;
	bsf	(15710/8)^0780h,(15710)&7
	line	70
;TestProc.c: 70: while(WA==0);
	
l10963:	
	btfss	(15508/8)^0780h,(15508)&7
	goto	u9831
	goto	u9830
u9831:
	goto	l10963
u9830:
	
l10965:	
	line	71
;TestProc.c: 71: SEG3COM3=1;
	bsf	(15691/8)^0780h,(15691)&7
	line	74
	
l34066:	
;TestProc.c: 72: }
;TestProc.c: 74: unsigned char retry=2;
	movlw	(02h)
	movlb 0	; select bank0
	movwf	(CallTestProc@retry)
	line	75
;TestProc.c: 75: while(retry!=0)
	goto	l34092
	line	77
	
l34068:	
;TestProc.c: 76: {
;TestProc.c: 77: ErrState=NoErr;
	clrf	(_ErrState)
	line	79
	
l34070:	
;TestProc.c: 79: if(PowerON()==0)
	fcall	_PowerON
	iorlw	0
	skipz
	goto	u9841
	goto	u9840
u9841:
	goto	l34074
u9840:
	line	81
	
l34072:	
;TestProc.c: 80: {
;TestProc.c: 81: ErrState=Miss900a;
	movlw	(02h)
	movlb 0	; select bank0
	movwf	(_ErrState)
	line	82
;TestProc.c: 82: }
	goto	l34084
	line	85
	
l34074:	
;TestProc.c: 83: else
;TestProc.c: 84: {
;TestProc.c: 85: CallTestSend();
	fcall	_CallTestSend
	line	86
	
l34076:	
;TestProc.c: 86: if(ErrState!=NoErr)
	movf	(_ErrState),w
	skipz
	goto	u9850
	goto	l34082
u9850:
	line	88
	
l34078:	
;TestProc.c: 87: {
;TestProc.c: 88: if(RD4==1)
	btfss	(124/8),(124)&7
	goto	u9861
	goto	u9860
u9861:
	goto	l34082
u9860:
	line	90
	
l34080:	
;TestProc.c: 89: {
;TestProc.c: 90: ErrState=MissPower;
	movlw	(013h)
	movwf	(_ErrState)
	line	93
	
l34082:	
;TestProc.c: 91: }
;TestProc.c: 92: }
;TestProc.c: 93: PowerDown();
	fcall	_PowerDown
	line	95
	
l34084:	
;TestProc.c: 94: }
;TestProc.c: 95: if(gFlags.bRetry)
	btfss	(_gFlags),4
	goto	u9871
	goto	u9870
u9871:
	goto	l10975
u9870:
	line	97
	
l34086:	
;TestProc.c: 96: {
;TestProc.c: 97: retry--;
	decf	(CallTestProc@retry),f
	line	98
	
l34088:	
;TestProc.c: 98: LcdDisplay_CurTemp();
	fcall	_LcdDisplay_CurTemp
	line	99
	
l34090:	
;TestProc.c: 99: __delay_20ms(3000);
	movlw	low(0BB8h)
	movlb 0	; select bank0
	movwf	(?___delay_20ms)
	movlw	high(0BB8h)
	movwf	((?___delay_20ms))+1
	fcall	___delay_20ms
	line	75
;TestProc.c: 100: }
	
l34092:	
	movf	(CallTestProc@retry),f
	skipz
	goto	u9881
	goto	u9880
u9881:
	goto	l34068
u9880:
	line	106
	
l10975:	
	movlb 15	; select bank15
	btfss	(15508/8)^0780h,(15508)&7
	goto	u9891
	goto	u9890
u9891:
	goto	l10975
u9890:
	
l10977:	
	line	107
;TestProc.c: 107: SEG5COM0=0;
	bcf	(15621/8)^0780h,(15621)&7
	line	108
;TestProc.c: 108: while(WA==0);
	
l10978:	
	btfss	(15508/8)^0780h,(15508)&7
	goto	u9901
	goto	u9900
u9901:
	goto	l10978
u9900:
	
l10980:	
	line	109
;TestProc.c: 109: SEG5COM2=0;
	bcf	(15669/8)^0780h,(15669)&7
	line	110
;TestProc.c: 110: while(WA==0);
	
l10981:	
	btfss	(15508/8)^0780h,(15508)&7
	goto	u9911
	goto	u9910
u9911:
	goto	l10981
u9910:
	
l10983:	
	line	111
;TestProc.c: 111: SEG22COM3=0;
	bcf	(15710/8)^0780h,(15710)&7
	line	112
;TestProc.c: 112: while(WA==0);
	
l10984:	
	btfss	(15508/8)^0780h,(15508)&7
	goto	u9921
	goto	u9920
u9921:
	goto	l10984
u9920:
	
l10986:	
	line	113
;TestProc.c: 113: SEG3COM3=0;
	bcf	(15691/8)^0780h,(15691)&7
	line	114
	
l34094:	
;TestProc.c: 114: if(ErrState!=NoErr)
	movlb 0	; select bank0
	movf	(_ErrState),w
	skipz
	goto	u9930
	goto	l34098
u9930:
	line	116
	
l34096:	
;TestProc.c: 115: {
;TestProc.c: 116: LcdDisplay_Err();
	fcall	_LcdDisplay_Err
	line	117
;TestProc.c: 117: }
	goto	l10989
	line	120
	
l34098:	
;TestProc.c: 118: else
;TestProc.c: 119: {
;TestProc.c: 120: LcdDisplay_CurTemp();
	fcall	_LcdDisplay_CurTemp
	line	123
	
l10989:	
	return
	opt stack 0
GLOBAL	__end_of_CallTestProc
	__end_of_CallTestProc:
;; =============== function _CallTestProc ends ============

	signat	_CallTestProc,88
	global	_CallProc
psect	text2005,local,class=CODE,delta=2
global __ptext2005
__ptext2005:

;; *************** function _CallProc *****************
;; Defined at:
;;		line 7 in file "F:\work\WYP\NBIoT\Function.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;  retry           1   43[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, fsr0l, fsr0h, fsr1l, fsr1h, status,2, status,0, btemp+0, pclath, cstack
;; Tracked objects:
;;		On entry : 10/F
;;		On exit  : 1F/F
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       0       0       0       0       0       0       0
;;      Locals:         0       1       0       0       0       0       0       0
;;      Temps:          0       0       0       0       0       0       0       0
;;      Totals:         0       1       0       0       0       0       0       0
;;Total ram usage:        1 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    8
;; This function calls:
;;		_PowerON
;;		_CallSend
;;		_PowerDown
;;		_LcdDisplay_CurTemp
;;		___delay_20ms
;;		_LcdDisplay_Err
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text2005
	file	"F:\work\WYP\NBIoT\Function.c"
	line	7
	global	__size_of_CallProc
	__size_of_CallProc	equ	__end_of_CallProc-_CallProc
	
_CallProc:	
	opt	stack 13
; Regs used in _CallProc: [wreg-btemp+0+pclath+cstack]
	line	9
	
l34022:	
;Function.c: 9: while(WA==0);
	
l8658:	
	movlb 15	; select bank15
	btfss	(15508/8)^0780h,(15508)&7
	goto	u9601
	goto	u9600
u9601:
	goto	l8658
u9600:
	
l8660:	
	line	10
;Function.c: 10: SEG5COM0=1;
	bsf	(15621/8)^0780h,(15621)&7
	line	11
;Function.c: 11: while(WA==0);
	
l8661:	
	btfss	(15508/8)^0780h,(15508)&7
	goto	u9611
	goto	u9610
u9611:
	goto	l8661
u9610:
	
l8663:	
	line	12
;Function.c: 12: SEG5COM2=1;
	bsf	(15669/8)^0780h,(15669)&7
	line	13
;Function.c: 13: while(WA==0);
	
l8664:	
	btfss	(15508/8)^0780h,(15508)&7
	goto	u9621
	goto	u9620
u9621:
	goto	l8664
u9620:
	
l8666:	
	line	14
;Function.c: 14: SEG21COM3=0;
	bcf	(15709/8)^0780h,(15709)&7
	line	15
;Function.c: 15: while(WA==0);
	
l8667:	
	btfss	(15508/8)^0780h,(15508)&7
	goto	u9631
	goto	u9630
u9631:
	goto	l8667
u9630:
	
l8669:	
	line	16
;Function.c: 16: SEG21COM2=0;
	bcf	(15685/8)^0780h,(15685)&7
	line	17
;Function.c: 17: if(gFlags.bNotify)
	movlb 0	; select bank0
	btfss	(_gFlags),0
	goto	u9641
	goto	u9640
u9641:
	goto	l34026
u9640:
	line	19
	
l8671:	
	movlb 15	; select bank15
	btfss	(15508/8)^0780h,(15508)&7
	goto	u9651
	goto	u9650
u9651:
	goto	l8671
u9650:
	
l8673:	
	line	20
;Function.c: 20: SEG22COM3=1;
	bsf	(15710/8)^0780h,(15710)&7
	line	21
;Function.c: 21: while(WA==0);
	
l8674:	
	btfss	(15508/8)^0780h,(15508)&7
	goto	u9661
	goto	u9660
u9661:
	goto	l8674
u9660:
	
l8676:	
	line	22
;Function.c: 22: SEG3COM3=1;
	bsf	(15691/8)^0780h,(15691)&7
	line	25
	
l34026:	
;Function.c: 23: }
;Function.c: 25: unsigned char retry=2;
	movlw	(02h)
	movlb 0	; select bank0
	movwf	(CallProc@retry)
	line	26
;Function.c: 26: while(retry!=0)
	goto	l34054
	line	28
	
l34028:	
;Function.c: 27: {
;Function.c: 28: ErrState=NoErr;
	clrf	(_ErrState)
	line	29
	
l34030:	
;Function.c: 29: gFlags.bRetry=0;
	bcf	(_gFlags),4
	line	31
	
l34032:	
;Function.c: 31: if(PowerON()==0)
	fcall	_PowerON
	iorlw	0
	skipz
	goto	u9671
	goto	u9670
u9671:
	goto	l34036
u9670:
	line	33
	
l34034:	
;Function.c: 32: {
;Function.c: 33: ErrState=Miss900a;
	movlw	(02h)
	movlb 0	; select bank0
	movwf	(_ErrState)
	line	34
;Function.c: 34: }
	goto	l34046
	line	37
	
l34036:	
;Function.c: 35: else
;Function.c: 36: {
;Function.c: 37: CallSend();
	fcall	_CallSend
	line	38
	
l34038:	
;Function.c: 38: if(ErrState!=NoErr)
	movf	(_ErrState),w
	skipz
	goto	u9680
	goto	l34044
u9680:
	line	40
	
l34040:	
;Function.c: 39: {
;Function.c: 40: if(RD4==1)
	btfss	(124/8),(124)&7
	goto	u9691
	goto	u9690
u9691:
	goto	l34044
u9690:
	line	42
	
l34042:	
;Function.c: 41: {
;Function.c: 42: ErrState=MissPower;
	movlw	(013h)
	movwf	(_ErrState)
	line	45
	
l34044:	
;Function.c: 43: }
;Function.c: 44: }
;Function.c: 45: PowerDown();
	fcall	_PowerDown
	line	47
	
l34046:	
;Function.c: 46: }
;Function.c: 47: if(gFlags.bRetry)
	btfss	(_gFlags),4
	goto	u9701
	goto	u9700
u9701:
	goto	l8686
u9700:
	line	49
	
l34048:	
;Function.c: 48: {
;Function.c: 49: retry--;
	decf	(CallProc@retry),f
	line	54
	
l34050:	
;Function.c: 54: LcdDisplay_CurTemp();
	fcall	_LcdDisplay_CurTemp
	line	55
	
l34052:	
;Function.c: 55: __delay_20ms(3000);
	movlw	low(0BB8h)
	movlb 0	; select bank0
	movwf	(?___delay_20ms)
	movlw	high(0BB8h)
	movwf	((?___delay_20ms))+1
	fcall	___delay_20ms
	line	26
;Function.c: 56: }
	
l34054:	
	movf	(CallProc@retry),f
	skipz
	goto	u9711
	goto	u9710
u9711:
	goto	l34028
u9710:
	line	62
	
l8686:	
	movlb 15	; select bank15
	btfss	(15508/8)^0780h,(15508)&7
	goto	u9721
	goto	u9720
u9721:
	goto	l8686
u9720:
	
l8688:	
	line	63
;Function.c: 63: SEG5COM0=0;
	bcf	(15621/8)^0780h,(15621)&7
	line	64
;Function.c: 64: while(WA==0);
	
l8689:	
	btfss	(15508/8)^0780h,(15508)&7
	goto	u9731
	goto	u9730
u9731:
	goto	l8689
u9730:
	
l8691:	
	line	65
;Function.c: 65: SEG5COM2=0;
	bcf	(15669/8)^0780h,(15669)&7
	line	66
;Function.c: 66: while(WA==0);
	
l8692:	
	btfss	(15508/8)^0780h,(15508)&7
	goto	u9741
	goto	u9740
u9741:
	goto	l8692
u9740:
	
l8694:	
	line	67
;Function.c: 67: SEG22COM3=0;
	bcf	(15710/8)^0780h,(15710)&7
	line	68
;Function.c: 68: while(WA==0);
	
l8695:	
	btfss	(15508/8)^0780h,(15508)&7
	goto	u9751
	goto	u9750
u9751:
	goto	l8695
u9750:
	
l8697:	
	line	69
;Function.c: 69: SEG3COM3=0;
	bcf	(15691/8)^0780h,(15691)&7
	line	70
	
l34056:	
;Function.c: 70: if(ErrState!=NoErr)
	movlb 0	; select bank0
	movf	(_ErrState),w
	skipz
	goto	u9760
	goto	l34060
u9760:
	line	72
	
l34058:	
;Function.c: 71: {
;Function.c: 72: LcdDisplay_Err();
	fcall	_LcdDisplay_Err
	line	73
;Function.c: 73: }
	goto	l8700
	line	76
	
l34060:	
;Function.c: 74: else
;Function.c: 75: {
;Function.c: 76: LcdDisplay_CurTemp();
	fcall	_LcdDisplay_CurTemp
	line	79
	
l8700:	
	return
	opt stack 0
GLOBAL	__end_of_CallProc
	__end_of_CallProc:
;; =============== function _CallProc ends ============

	signat	_CallProc,88
	global	_InitSystem
psect	text2006,local,class=CODE,delta=2
global __ptext2006
__ptext2006:

;; *************** function _InitSystem *****************
;; Defined at:
;;		line 88 in file "F:\work\WYP\NBIoT\Init.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;  x               1   13[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, fsr0l, fsr0h, fsr1l, fsr1h, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 17F/0
;;		On exit  : 1F/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       0       0       0       0       0       0       0
;;      Locals:         0       1       0       0       0       0       0       0
;;      Temps:          0       0       0       0       0       0       0       0
;;      Totals:         0       1       0       0       0       0       0       0
;;Total ram usage:        1 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    7
;; This function calls:
;;		_InitMCU
;;		_InitVariable
;;		_DisplayInit
;;		_ATCommand_Init
;;		_OneWire_Reset
;;		_TCN75_Init
;;		_TCN75_SetConfig
;;		___delay_20ms
;;		_ReadTData
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text2006
	file	"F:\work\WYP\NBIoT\Init.c"
	line	88
	global	__size_of_InitSystem
	__size_of_InitSystem	equ	__end_of_InitSystem-_InitSystem
	
_InitSystem:	
	opt	stack 13
; Regs used in _InitSystem: [wreg-status,0+pclath+cstack]
	line	90
	
l33976:	
;Init.c: 89: unsigned char x;
;Init.c: 90: InitMCU();
	fcall	_InitMCU
	line	91
	
l33978:	
;Init.c: 91: InitVariable();
	fcall	_InitVariable
	line	93
	
l33980:	
;Init.c: 93: DisplayInit();
	fcall	_DisplayInit
	line	94
	
l33982:	
;Init.c: 94: if(RomParams.bWinter==0)
	movlb 0	; select bank0
	movf	0+(_RomParams)+01h,f
	skipz
	goto	u9541
	goto	u9540
u9541:
	goto	l4435
u9540:
	line	96
	
l4431:	
	movlb 15	; select bank15
	btfss	(15508/8)^0780h,(15508)&7
	goto	u9551
	goto	u9550
u9551:
	goto	l4431
u9550:
	
l4433:	
	line	97
;Init.c: 97: SEG21COM0=1;
	bsf	(15637/8)^0780h,(15637)&7
	line	98
;Init.c: 98: }
	goto	l33986
	line	101
	
l4435:	
	movlb 15	; select bank15
	btfss	(15508/8)^0780h,(15508)&7
	goto	u9561
	goto	u9560
u9561:
	goto	l4435
u9560:
	
l4437:	
	line	102
;Init.c: 102: SEG21COM0=0;
	bcf	(15637/8)^0780h,(15637)&7
	line	105
	
l33986:	
;Init.c: 103: }
;Init.c: 105: ATCommand_Init();
	fcall	_ATCommand_Init
	line	107
	
l33988:	
;Init.c: 107: x=10;
	movlw	(0Ah)
	movwf	(InitSystem@x)
	line	108
;Init.c: 108: while(x!=0)
	goto	l4438
	line	110
	
l33990:	
;Init.c: 109: {
;Init.c: 110: if(OneWire_Reset()==0)
	fcall	_OneWire_Reset
	iorlw	0
	skipz
	goto	u9571
	goto	u9570
u9571:
	goto	l33994
u9570:
	line	112
	
l33992:	
;Init.c: 111: {
;Init.c: 112: gFlags.b18B20=1;
	bsf	(_gFlags),1
	line	113
;Init.c: 113: break;
	goto	l33996
	line	115
	
l33994:	
;Init.c: 114: }
;Init.c: 115: x--;
	decf	(InitSystem@x),f
	line	116
	
l4438:	
	line	108
	movf	(InitSystem@x),f
	skipz
	goto	u9581
	goto	u9580
u9581:
	goto	l33990
u9580:
	line	117
	
l33996:	
;Init.c: 116: }
;Init.c: 117: if(x==0)
	movf	(InitSystem@x),f
	skipz
	goto	u9591
	goto	u9590
u9591:
	goto	l34016
u9590:
	line	119
	
l33998:	
;Init.c: 118: {
;Init.c: 119: gFlags.b18B20=0;
	bcf	(_gFlags),1
	line	120
	
l34000:	
;Init.c: 120: TCN75_Init();
	fcall	_TCN75_Init
	line	121
	
l34002:	
;Init.c: 121: TCN75_Config.bShutdown=1;
	movlb 0	; select bank0
	bsf	(_TCN75_Config),0
	line	122
	
l34004:	
;Init.c: 122: TCN75_Config.COMP_INT=0;
	bcf	(_TCN75_Config),1
	line	123
	
l34006:	
;Init.c: 123: TCN75_Config.Polarity=0;
	bcf	(_TCN75_Config),2
	line	124
	
l34008:	
;Init.c: 124: TCN75_Config.FaultQueue=0b00;
	movlw	((0 & ((1<<2)-1))<<3)|not (((1<<2)-1)<<3)
	andwf	(_TCN75_Config),f
	line	125
	
l34010:	
;Init.c: 125: TCN75_Config.Resolution=0b11;
	movlw	(03h & ((1<<2)-1))<<5
	iorwf	(_TCN75_Config),f
	line	126
	
l34012:	
;Init.c: 126: TCN75_Config.OneShot=0;
	bcf	(_TCN75_Config),7
	line	127
	
l34014:	
;Init.c: 127: TCN75_SetConfig();
	fcall	_TCN75_SetConfig
	line	129
	
l34016:	
;Init.c: 128: }
;Init.c: 129: __delay_20ms(50);
	movlw	032h
	movwf	(?___delay_20ms)
	clrf	(?___delay_20ms+1)
	fcall	___delay_20ms
	line	130
	
l34018:	
;Init.c: 130: ReadTData();
	fcall	_ReadTData
	line	131
	
l34020:	
;Init.c: 131: __delay_20ms(250);
	movlw	0FAh
	movlb 0	; select bank0
	movwf	(?___delay_20ms)
	clrf	(?___delay_20ms+1)
	fcall	___delay_20ms
	line	132
	
l4443:	
	return
	opt stack 0
GLOBAL	__end_of_InitSystem
	__end_of_InitSystem:
;; =============== function _InitSystem ends ============

	signat	_InitSystem,88
	global	_CallTestSend
psect	text2007,local,class=CODE,delta=2
global __ptext2007
__ptext2007:

;; *************** function _CallTestSend *****************
;; Defined at:
;;		line 125 in file "F:\work\WYP\NBIoT\TestProc.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;  strx            2   39[BANK0 ] PTR unsigned char 
;;		 -> ATCommand_RxList(100), RAM(128), 
;;  ret             1   41[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, fsr0l, fsr0h, fsr1l, fsr1h, status,2, status,0, btemp+0, pclath, cstack
;; Tracked objects:
;;		On entry : 1D/0
;;		On exit  : 1F/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       0       0       0       0       0       0       0
;;      Locals:         0       3       0       0       0       0       0       0
;;      Temps:          0       0       0       0       0       0       0       0
;;      Totals:         0       3       0       0       0       0       0       0
;;Total ram usage:        3 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    7
;; This function calls:
;;		_InitGPRS
;;		_ATCommand_SendCmd
;;		_strcpy
;;		___delay_20ms
;;		_InteractServer
;;		_strstr
;; This function is called by:
;;		_CallTestProc
;; This function uses a non-reentrant model
;;
psect	text2007
	file	"F:\work\WYP\NBIoT\TestProc.c"
	line	125
	global	__size_of_CallTestSend
	__size_of_CallTestSend	equ	__end_of_CallTestSend-_CallTestSend
	
_CallTestSend:	
	opt	stack 11
; Regs used in _CallTestSend: [wreg-btemp+0+pclath+cstack]
	line	127
	
l33926:	
	line	128
	
l33928:	
;TestProc.c: 128: InitGPRS();
	fcall	_InitGPRS
	line	129
	
l33930:	
;TestProc.c: 129: if(ErrState!=NoErr)
	movf	(_ErrState),w
	skipz
	goto	u9480
	goto	l33934
u9480:
	goto	l10993
	line	131
	
l33934:	
;TestProc.c: 131: ATCommand_SendCmd("AT+CIPSTATUS\0");
	movlw	low(STR_40|8000h)
	movwf	(?_ATCommand_SendCmd)
	movlw	high(STR_40|8000h)
	movwf	((?_ATCommand_SendCmd))+1
	fcall	_ATCommand_SendCmd
	line	132
;TestProc.c: 132: strcpy(ATCommand_OkString,"CONNECT OK");
	movlw	low(STR_41|8000h)
	movwf	(?_strcpy)
	movlw	high(STR_41|8000h)
	movwf	((?_strcpy))+1
	movlw	(_ATCommand_OkString)&0ffh
	fcall	_strcpy
	line	133
	
l33936:	
;TestProc.c: 133: ATCommand_RetryTimes=1;
	clrf	(_ATCommand_RetryTimes)
	incf	(_ATCommand_RetryTimes),f
	line	134
	
l33938:	
;TestProc.c: 134: ATCommand_WaitACKTimes=600;
	movlw	low(0258h)
	movwf	(_ATCommand_WaitACKTimes)
	movlw	high(0258h)
	movwf	((_ATCommand_WaitACKTimes))+1
	line	138
	
l33940:	
;TestProc.c: 138: if(ATCommand_SendCmd("AT+CIPSTART=\"TCP\",\"www.wlwdjcy.com\",\"12128\"\0")!=ATACK_OK)
	movlw	low(STR_42|8000h)
	movwf	(?_ATCommand_SendCmd)
	movlw	high(STR_42|8000h)
	movwf	((?_ATCommand_SendCmd))+1
	fcall	_ATCommand_SendCmd
	xorlw	01h&0ffh
	skipnz
	goto	u9491
	goto	u9490
u9491:
	goto	l33948
u9490:
	line	142
	
l33942:	
;TestProc.c: 141: {
;TestProc.c: 142: ATCommand_SendCmd("AT+CIPSTART=?\0");
	movlw	low(STR_43|8000h)
	movwf	(?_ATCommand_SendCmd)
	movlw	high(STR_43|8000h)
	movwf	((?_ATCommand_SendCmd))+1
	fcall	_ATCommand_SendCmd
	line	143
	
l33944:	
;TestProc.c: 143: ErrState=MissAT_CIPSTART;
	movlw	(01Dh)
	movwf	(_ErrState)
	goto	l10993
	line	147
	
l33948:	
;TestProc.c: 145: }
;TestProc.c: 147: __delay_20ms(50);
	movlw	032h
	movwf	(?___delay_20ms)
	clrf	(?___delay_20ms+1)
	fcall	___delay_20ms
	line	149
	
l33950:	
;TestProc.c: 149: ret=InteractServer();
	fcall	_InteractServer
	movwf	(CallTestSend@ret)
	line	150
	
l33952:	
;TestProc.c: 150: if(ret!=ATACK_OK)
	decf	(CallTestSend@ret),w
	skipnz
	goto	u9501
	goto	u9500
u9501:
	goto	l33964
u9500:
	line	152
	
l33954:	
;TestProc.c: 151: {
;TestProc.c: 152: if(ErrState==MissAT_ServerClose)
	movf	(_ErrState),w
	xorlw	022h&0ffh
	skipz
	goto	u9511
	goto	u9510
u9511:
	goto	l33958
u9510:
	line	154
	
l33956:	
;TestProc.c: 153: {
;TestProc.c: 154: gFlags.bRetry=1;
	bsf	(_gFlags),4
	line	155
;TestProc.c: 155: return;
	goto	l10993
	line	157
	
l33958:	
;TestProc.c: 156: }
;TestProc.c: 157: ret=InteractServer();
	fcall	_InteractServer
	movwf	(CallTestSend@ret)
	line	158
	
l33960:	
;TestProc.c: 158: if(ret!=ATACK_OK)
	decf	(CallTestSend@ret),w
	skipnz
	goto	u9521
	goto	u9520
u9521:
	goto	l33964
u9520:
	goto	l33956
	line	165
	
l33964:	
;TestProc.c: 162: }
;TestProc.c: 163: }
;TestProc.c: 165: strx=strstr((const char*)ATCommand_RxList,"#KO$");
	movlw	low(8588)
	movwf	(?_strstr)
	movlw	high(8588)
	movwf	((?_strstr))+1
	movlw	low(STR_44|8000h)
	movwf	(0+?_strstr+02h)
	movlw	high(STR_44|8000h)
	movwf	((0+?_strstr+02h))+1
	fcall	_strstr
	movf	(1+(?_strstr)),w
	movwf	(CallTestSend@strx+1)
	movf	(0+(?_strstr)),w
	movwf	(CallTestSend@strx)
	line	166
	
l33966:	
;TestProc.c: 166: if(strx==0)
	movf	((CallTestSend@strx+1)),w
	iorwf	((CallTestSend@strx)),w
	skipz
	goto	u9531
	goto	u9530
u9531:
	goto	l33972
u9530:
	line	168
	
l33968:	
;TestProc.c: 167: {
;TestProc.c: 168: ErrState=MissAT_ErrServerData;
	movlw	(021h)
	movwf	(_ErrState)
	goto	l10993
	line	172
	
l33972:	
;TestProc.c: 170: }
;TestProc.c: 172: if(ATCommand_SendCmd("AT+CIPCLOSE=1\0")!=ATACK_OK)
	movlw	low(STR_45|8000h)
	movwf	(?_ATCommand_SendCmd)
	movlw	high(STR_45|8000h)
	movwf	((?_ATCommand_SendCmd))+1
	fcall	_ATCommand_SendCmd
	line	178
	
l33974:	
;TestProc.c: 176: }
;TestProc.c: 178: if(ATCommand_SendCmd("AT+CIPSHUT\0")!=ATACK_OK)
	movlw	low(STR_46|8000h)
	movwf	(?_ATCommand_SendCmd)
	movlw	high(STR_46|8000h)
	movwf	((?_ATCommand_SendCmd))+1
	fcall	_ATCommand_SendCmd
	line	183
	
l10993:	
	return
	opt stack 0
GLOBAL	__end_of_CallTestSend
	__end_of_CallTestSend:
;; =============== function _CallTestSend ends ============

	signat	_CallTestSend,88
	global	_CallSend
psect	text2008,local,class=CODE,delta=2
global __ptext2008
__ptext2008:

;; *************** function _CallSend *****************
;; Defined at:
;;		line 82 in file "F:\work\WYP\NBIoT\Function.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;  strx            2   39[BANK0 ] PTR unsigned char 
;;		 -> ATCommand_RxList(100), RAM(128), 
;;  ret             1   42[BANK0 ] unsigned char 
;;  i               1   41[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, fsr0l, fsr0h, fsr1l, fsr1h, status,2, status,0, btemp+0, pclath, cstack
;; Tracked objects:
;;		On entry : 1D/0
;;		On exit  : 1F/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       0       0       0       0       0       0       0
;;      Locals:         0       4       0       0       0       0       0       0
;;      Temps:          0       0       0       0       0       0       0       0
;;      Totals:         0       4       0       0       0       0       0       0
;;Total ram usage:        4 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    7
;; This function calls:
;;		_InitGPRS
;;		___delay_20ms
;;		_ATCommand_SendCmd
;;		_strcpy
;;		_InteractServer
;;		_strstr
;;		_SaveRomData
;; This function is called by:
;;		_CallProc
;; This function uses a non-reentrant model
;;
psect	text2008
	file	"F:\work\WYP\NBIoT\Function.c"
	line	82
	global	__size_of_CallSend
	__size_of_CallSend	equ	__end_of_CallSend-_CallSend
	
_CallSend:	
	opt	stack 12
; Regs used in _CallSend: [wreg-btemp+0+pclath+cstack]
	line	84
	
l33848:	
	line	85
;Function.c: 85: ErrState=NoErr;
	movlb 0	; select bank0
	clrf	(_ErrState)
	line	86
	
l33850:	
;Function.c: 86: InitGPRS();
	fcall	_InitGPRS
	line	87
	
l33852:	
;Function.c: 87: if(ErrState!=NoErr)
	movf	(_ErrState),w
	skipz
	goto	u9370
	goto	l33864
u9370:
	line	89
	
l33854:	
;Function.c: 88: {
;Function.c: 89: __delay_20ms(3000);
	movlw	low(0BB8h)
	movwf	(?___delay_20ms)
	movlw	high(0BB8h)
	movwf	((?___delay_20ms))+1
	fcall	___delay_20ms
	line	90
	
l33856:	
;Function.c: 90: ErrState=NoErr;
	clrf	(_ErrState)
	line	91
	
l33858:	
;Function.c: 91: InitGPRS();
	fcall	_InitGPRS
	line	92
	
l33860:	
;Function.c: 92: if(ErrState!=NoErr)
	movf	(_ErrState),w
	skipz
	goto	u9380
	goto	l33864
u9380:
	goto	l8705
	line	95
	
l33864:	
;Function.c: 94: }
;Function.c: 95: ATCommand_SendCmd("AT+CIPSTATUS\0");
	movlw	low(STR_1|8000h)
	movwf	(?_ATCommand_SendCmd)
	movlw	high(STR_1|8000h)
	movwf	((?_ATCommand_SendCmd))+1
	fcall	_ATCommand_SendCmd
	line	96
;Function.c: 96: strcpy(ATCommand_OkString,"CONNECT OK");
	movlw	low(STR_2|8000h)
	movwf	(?_strcpy)
	movlw	high(STR_2|8000h)
	movwf	((?_strcpy))+1
	movlw	(_ATCommand_OkString)&0ffh
	fcall	_strcpy
	line	97
	
l33866:	
;Function.c: 97: ATCommand_RetryTimes=1;
	clrf	(_ATCommand_RetryTimes)
	incf	(_ATCommand_RetryTimes),f
	line	98
	
l33868:	
;Function.c: 98: ATCommand_WaitACKTimes=600;
	movlw	low(0258h)
	movwf	(_ATCommand_WaitACKTimes)
	movlw	high(0258h)
	movwf	((_ATCommand_WaitACKTimes))+1
	line	103
	
l33870:	
;Function.c: 103: if(ATCommand_SendCmd("AT+CIPSTART=\"TCP\",\"www.wlwdjcy.com\",\"12128\"\0")!=ATACK_OK)
	movlw	low(STR_3|8000h)
	movwf	(?_ATCommand_SendCmd)
	movlw	high(STR_3|8000h)
	movwf	((?_ATCommand_SendCmd))+1
	fcall	_ATCommand_SendCmd
	xorlw	01h&0ffh
	skipnz
	goto	u9391
	goto	u9390
u9391:
	goto	l33880
u9390:
	line	106
	
l33872:	
;Function.c: 105: {
;Function.c: 106: ATCommand_SendCmd("AT+CIPSTART=?\0");
	movlw	low(STR_4|8000h)
	movwf	(?_ATCommand_SendCmd)
	movlw	high(STR_4|8000h)
	movwf	((?_ATCommand_SendCmd))+1
	fcall	_ATCommand_SendCmd
	line	107
	
l33874:	
;Function.c: 107: ErrState=MissAT_CIPSTART;
	movlw	(01Dh)
	movwf	(_ErrState)
	line	108
	
l33876:	
;Function.c: 108: gFlags.bRetry=1;
	bsf	(_gFlags),4
	goto	l8705
	line	112
	
l33880:	
;Function.c: 110: }
;Function.c: 112: __delay_20ms(50);
	movlw	032h
	movwf	(?___delay_20ms)
	clrf	(?___delay_20ms+1)
	fcall	___delay_20ms
	line	114
	
l33882:	
;Function.c: 114: ret=InteractServer();
	fcall	_InteractServer
	movwf	(CallSend@ret)
	line	115
	
l33884:	
;Function.c: 115: if(ret!=ATACK_OK)
	decf	(CallSend@ret),w
	skipnz
	goto	u9401
	goto	u9400
u9401:
	goto	l33898
u9400:
	line	117
	
l33886:	
;Function.c: 116: {
;Function.c: 117: if(ErrState==MissAT_ServerClose)
	movf	(_ErrState),w
	xorlw	022h&0ffh
	skipz
	goto	u9411
	goto	u9410
u9411:
	goto	l33890
u9410:
	goto	l33876
	line	122
	
l33890:	
;Function.c: 121: }
;Function.c: 122: ErrState=NoErr;
	clrf	(_ErrState)
	line	123
	
l33892:	
;Function.c: 123: ret=InteractServer();
	fcall	_InteractServer
	movwf	(CallSend@ret)
	line	124
	
l33894:	
;Function.c: 124: if(ret!=ATACK_OK)
	decf	(CallSend@ret),w
	skipnz
	goto	u9421
	goto	u9420
u9421:
	goto	l33898
u9420:
	goto	l33876
	line	131
	
l33898:	
;Function.c: 128: }
;Function.c: 129: }
;Function.c: 131: strx=strstr((const char*)ATCommand_RxList,"#KO$");
	movlw	low(8588)
	movwf	(?_strstr)
	movlw	high(8588)
	movwf	((?_strstr))+1
	movlw	low(STR_5|8000h)
	movwf	(0+?_strstr+02h)
	movlw	high(STR_5|8000h)
	movwf	((0+?_strstr+02h))+1
	fcall	_strstr
	movf	(1+(?_strstr)),w
	movwf	(CallSend@strx+1)
	movf	(0+(?_strstr)),w
	movwf	(CallSend@strx)
	line	132
	
l33900:	
;Function.c: 132: if(strx==0)
	movf	((CallSend@strx+1)),w
	iorwf	((CallSend@strx)),w
	skipz
	goto	u9431
	goto	u9430
u9431:
	goto	l33906
u9430:
	line	134
	
l33902:	
;Function.c: 133: {
;Function.c: 134: ErrState=MissAT_ErrServerData;
	movlw	(021h)
	movwf	(_ErrState)
	goto	l8705
	line	138
	
l33906:	
;Function.c: 136: }
;Function.c: 138: i=strx[4];
	movf	(CallSend@strx),w
	addlw	low(04h)
	movwf	fsr1l
	movlw	high(04h)
	addwfc	(CallSend@strx+1),w
	movwf	1+fsr1l
	movf	indf1,w
	movwf	(CallSend@i)
	line	139
	
l33908:	
;Function.c: 139: i=i-'0';
	movlw	(0D0h)
	addwf	(CallSend@i),f
	line	140
	
l33910:	
;Function.c: 140: if(i!=RomParams.bWinter)
	movf	0+(_RomParams)+01h,w
	xorwf	(CallSend@i),w
	skipnz
	goto	u9441
	goto	u9440
u9441:
	goto	l33922
u9440:
	line	142
	
l33912:	
;Function.c: 141: {
;Function.c: 142: RomParams.bWinter=i;
	movf	(CallSend@i),w
	movwf	0+(_RomParams)+01h
	line	143
	
l33914:	
;Function.c: 143: SaveRomData();
	fcall	_SaveRomData
	line	144
	
l33916:	
;Function.c: 144: if(RomParams.bWinter==0)
	movf	0+(_RomParams)+01h,f
	skipz
	goto	u9451
	goto	u9450
u9451:
	goto	l33920
u9450:
	line	146
	
l33918:	
;Function.c: 145: {
;Function.c: 146: NeedMeasurementTick=36000;
	movlw	low(08CA0h)
	movwf	(_NeedMeasurementTick)
	movlw	high(08CA0h)
	movwf	((_NeedMeasurementTick))+1
	line	148
;Function.c: 148: while(WA==0);
	
l8713:	
	movlb 15	; select bank15
	btfss	(15508/8)^0780h,(15508)&7
	goto	u9461
	goto	u9460
u9461:
	goto	l8713
u9460:
	
l8715:	
	line	149
;Function.c: 149: SEG21COM0=1;
	bsf	(15637/8)^0780h,(15637)&7
	line	151
;Function.c: 151: }
	goto	l33922
	line	154
	
l33920:	
;Function.c: 152: else
;Function.c: 153: {
;Function.c: 154: NeedMeasurementTick=6000;
	movlw	low(01770h)
	movwf	(_NeedMeasurementTick)
	movlw	high(01770h)
	movwf	((_NeedMeasurementTick))+1
	line	156
;Function.c: 156: while(WA==0);
	
l8717:	
	movlb 15	; select bank15
	btfss	(15508/8)^0780h,(15508)&7
	goto	u9471
	goto	u9470
u9471:
	goto	l8717
u9470:
	
l8719:	
	line	157
;Function.c: 157: SEG21COM0=0;
	bcf	(15637/8)^0780h,(15637)&7
	line	163
	
l33922:	
;Function.c: 159: }
;Function.c: 160: }
;Function.c: 163: if(ATCommand_SendCmd("AT+CIPCLOSE=1\0")!=ATACK_OK)
	movlw	low(STR_6|8000h)
	movlb 0	; select bank0
	movwf	(?_ATCommand_SendCmd)
	movlw	high(STR_6|8000h)
	movwf	((?_ATCommand_SendCmd))+1
	fcall	_ATCommand_SendCmd
	line	169
	
l33924:	
;Function.c: 167: }
;Function.c: 169: if(ATCommand_SendCmd("AT+CIPSHUT\0")!=ATACK_OK)
	movlw	low(STR_7|8000h)
	movwf	(?_ATCommand_SendCmd)
	movlw	high(STR_7|8000h)
	movwf	((?_ATCommand_SendCmd))+1
	fcall	_ATCommand_SendCmd
	line	174
	
l8705:	
	return
	opt stack 0
GLOBAL	__end_of_CallSend
	__end_of_CallSend:
;; =============== function _CallSend ends ============

	signat	_CallSend,88
	global	_ReadTData
psect	text2009,local,class=CODE,delta=2
global __ptext2009
__ptext2009:

;; *************** function _ReadTData *****************
;; Defined at:
;;		line 106 in file "F:\work\WYP\NBIoT\Main.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;  retry           1   12[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, fsr0l, fsr0h, fsr1l, fsr1h, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 10/0
;;		On exit  : 1F/F
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       0       0       0       0       0       0       0
;;      Locals:         0       1       0       0       0       0       0       0
;;      Temps:          0       0       0       0       0       0       0       0
;;      Totals:         0       1       0       0       0       0       0       0
;;Total ram usage:        1 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    6
;; This function calls:
;;		_DS18X20_StartMeas
;;		___delay_20ms
;;		_DS18X20_ReadMeas
;;		_TCN75_SetConfig
;;		_TCN75_ReadReg
;;		_LcdDisplay_CurTemp
;; This function is called by:
;;		_InitSystem
;;		_main
;;		_TestProc
;; This function uses a non-reentrant model
;;
psect	text2009
	file	"F:\work\WYP\NBIoT\Main.c"
	line	106
	global	__size_of_ReadTData
	__size_of_ReadTData	equ	__end_of_ReadTData-_ReadTData
	
_ReadTData:	
	opt	stack 13
; Regs used in _ReadTData: [wreg-status,0+pclath+cstack]
	line	108
	
l33814:	
;Main.c: 107: unsigned char retry;
;Main.c: 108: if(gFlags.b18B20)
	movlb 0	; select bank0
	btfss	(_gFlags),1
	goto	u9301
	goto	u9300
u9301:
	goto	l6545
u9300:
	line	110
	
l33816:	
;Main.c: 109: {
;Main.c: 110: retry=5;
	movlw	(05h)
	movwf	(ReadTData@retry)
	line	111
;Main.c: 111: while(retry!=0)
	goto	l6546
	line	113
	
l33818:	
;Main.c: 112: {
;Main.c: 113: if(DS18X20_StartMeas()!=0x00)
	fcall	_DS18X20_StartMeas
	xorlw	0&0ffh
	skipnz
	goto	u9311
	goto	u9310
u9311:
	goto	l33822
u9310:
	line	115
	
l33820:	
;Main.c: 114: {
;Main.c: 115: retry--;
	movlb 0	; select bank0
	decf	(ReadTData@retry),f
	line	116
;Main.c: 116: }
	goto	l6546
	line	119
	
l33822:	
;Main.c: 117: else
;Main.c: 118: {
;Main.c: 119: __delay_20ms(50);
	movlw	032h
	movwf	(?___delay_20ms)
	clrf	(?___delay_20ms+1)
	fcall	___delay_20ms
	line	120
	
l33824:	
;Main.c: 120: if(DS18X20_ReadMeas(1)==0x00)
	movlw	(01h)
	fcall	_DS18X20_ReadMeas
	iorlw	0
	skipz
	goto	u9321
	goto	u9320
u9321:
	goto	l33820
u9320:
	line	122
	
l33826:	
;Main.c: 121: {
;Main.c: 122: CurTemp.u8L=DS18X20_Scratchpad[0];
	movlb 1	; select bank1
	movf	(_DS18X20_Scratchpad)^080h,w
	movlb 0	; select bank0
	movwf	(_CurTemp)
	line	123
;Main.c: 123: CurTemp.u8H=DS18X20_Scratchpad[1];
	movlb 1	; select bank1
	movf	0+(_DS18X20_Scratchpad)^080h+01h,w
	movlb 0	; select bank0
	movwf	0+(_CurTemp)+01h
	line	124
;Main.c: 124: break;
	goto	l33832
	line	131
	
l6546:	
	line	111
	movf	(ReadTData@retry),f
	skipz
	goto	u9331
	goto	u9330
u9331:
	goto	l33818
u9330:
	line	132
	
l33832:	
;Main.c: 129: }
;Main.c: 130: }
;Main.c: 131: }
;Main.c: 132: if(retry==0)
	movf	(ReadTData@retry),f
	skipz
	goto	u9341
	goto	u9340
u9341:
	goto	l33846
u9340:
	line	133
	
l33834:	
;Main.c: 133: CurTemp.u16=0xf000;
	movlw	low(0F000h)
	movwf	(_CurTemp)
	movlw	high(0F000h)
	movwf	((_CurTemp))+1
	goto	l33846
	line	135
	
l6545:	
	line	137
;Main.c: 135: else
;Main.c: 136: {
;Main.c: 137: TCN75_Config.OneShot=1;
	bsf	(_TCN75_Config),7
	line	138
	
l33836:	
;Main.c: 138: if(TCN75_SetConfig()==1)
	fcall	_TCN75_SetConfig
	xorlw	01h&0ffh
	skipz
	goto	u9351
	goto	u9350
u9351:
	goto	l33834
u9350:
	line	140
	
l33838:	
;Main.c: 139: {
;Main.c: 140: __delay_20ms(25);
	movlw	019h
	movwf	(?___delay_20ms)
	clrf	(?___delay_20ms+1)
	fcall	___delay_20ms
	line	141
;Main.c: 141: if(TCN75_ReadReg(TCN75_TEMP)==1)
	movlw	(0)
	fcall	_TCN75_ReadReg
	xorlw	01h&0ffh
	skipz
	goto	u9361
	goto	u9360
u9361:
	goto	l33834
u9360:
	line	143
	
l33840:	
;Main.c: 142: {
;Main.c: 143: CurTemp.u16=TCN75_RegReadResualt.u16>>4;
	movf	(_TCN75_RegReadResualt+1),w
	movwf	(_CurTemp+1)
	movf	(_TCN75_RegReadResualt),w
	movwf	(_CurTemp)
	swapf	(_CurTemp),f
	swapf	(_CurTemp+1),f
	movlw	0fh
	andwf	(_CurTemp),f
	movf	(_CurTemp+1),w
	andlw	0f0h
	iorwf	(_CurTemp),f
	movlw	0fh
	andwf	(_CurTemp+1),f
	line	156
;Main.c: 144: }
	
l33846:	
;Main.c: 153: }
;Main.c: 154: }
;Main.c: 156: LcdDisplay_CurTemp();
	fcall	_LcdDisplay_CurTemp
	line	158
	
l6559:	
	return
	opt stack 0
GLOBAL	__end_of_ReadTData
	__end_of_ReadTData:
;; =============== function _ReadTData ends ============

	signat	_ReadTData,88
	global	_InteractServer
psect	text2010,local,class=CODE,delta=2
global __ptext2010
__ptext2010:

;; *************** function _InteractServer *****************
;; Defined at:
;;		line 176 in file "F:\work\WYP\NBIoT\Function.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;  j               2   30[BANK0 ] int 
;;  i               2   28[BANK0 ] int 
;;  i               2   26[BANK0 ] int 
;;  t               2   33[BANK0 ] struct .
;;  i               1   38[BANK0 ] unsigned char 
;;  k               1   37[BANK0 ] unsigned char 
;;  j               1   36[BANK0 ] unsigned char 
;;  addr            1   35[BANK0 ] unsigned char 
;;  res             1   32[BANK0 ] unsigned char 
;;  retry           1   25[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;                  1    wreg      unsigned char 
;; Registers used:
;;		wreg, fsr0l, fsr0h, fsr1l, fsr1h, status,2, status,0, btemp+0, pclath, cstack
;; Tracked objects:
;;		On entry : 1F/0
;;		On exit  : 1F/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       0       0       0       0       0       0       0
;;      Locals:         0      14       0       0       0       0       0       0
;;      Temps:          0       0       0       0       0       0       0       0
;;      Totals:         0      14       0       0       0       0       0       0
;;Total ram usage:       14 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    6
;; This function calls:
;;		_strcpy
;;		_ATCommand_SendCmd
;;		_Uart1_PutChar
;;		_Uart1_PutString
;;		_MakeTxTemperature
;;		___bmul
;;		_eeprom_read
;;		_ATCommand_WaitData
;;		___delay_20ms
;; This function is called by:
;;		_CallSend
;;		_CallTestSend
;; This function uses a non-reentrant model
;;
psect	text2010
	file	"F:\work\WYP\NBIoT\Function.c"
	line	176
	global	__size_of_InteractServer
	__size_of_InteractServer	equ	__end_of_InteractServer-_InteractServer
	
_InteractServer:	
	opt	stack 11
; Regs used in _InteractServer: [wreg-btemp+0+pclath+cstack]
	line	177
	
l33554:	
	line	180
	
l33556:	
;Function.c: 178: unsigned char retry,i,j,k,addr;
;Function.c: 179: uint t;
;Function.c: 180: retry=1;
	clrf	(InteractServer@retry)
	incf	(InteractServer@retry),f
	line	181
;Function.c: 181: res=ATACK_Null;
	clrf	(InteractServer@res)
	line	182
;Function.c: 182: while(retry!=0)
	goto	l33794
	line	184
	
l33558:	
;Function.c: 183: {
;Function.c: 184: strcpy(ATCommand_OkString,">");
	movlw	low(STR_8|8000h)
	movwf	(?_strcpy)
	movlw	high(STR_8|8000h)
	movwf	((?_strcpy))+1
	movlw	(_ATCommand_OkString)&0ffh
	fcall	_strcpy
	line	185
	
l33560:	
;Function.c: 185: ATCommand_WaitACKTimes=400;
	movlw	low(0190h)
	movwf	(_ATCommand_WaitACKTimes)
	movlw	high(0190h)
	movwf	((_ATCommand_WaitACKTimes))+1
	line	186
	
l33562:	
;Function.c: 186: if(ATCommand_SendCmd("AT+CIPSEND\0")!=ATACK_OK)
	movlw	low(STR_9|8000h)
	movwf	(?_ATCommand_SendCmd)
	movlw	high(STR_9|8000h)
	movwf	((?_ATCommand_SendCmd))+1
	fcall	_ATCommand_SendCmd
	xorlw	01h&0ffh
	skipnz
	goto	u9041
	goto	u9040
u9041:
	goto	l8726
u9040:
	line	188
	
l33564:	
;Function.c: 187: {
;Function.c: 188: ErrState=MissAT_CIPSEND;
	movlw	(01Eh)
	movwf	(_ErrState)
	line	189
	
l33566:	
;Function.c: 189: Uart1_PutChar(0x1b);
	movlw	(01Bh)
	fcall	_Uart1_PutChar
	line	190
	
l33568:	
;Function.c: 190: return res;
	movlb 0	; select bank0
	movf	(InteractServer@res),w
	goto	l8727
	line	191
	
l8726:	
	line	192
;Function.c: 191: }
;Function.c: 192: if(gFlags.bFirst)
	btfss	(_gFlags),2
	goto	u9051
	goto	u9050
u9051:
	goto	l8728
u9050:
	line	194
	
l33572:	
;Function.c: 193: {
;Function.c: 194: Uart1_PutString("@#pt#1#\0");
	movlw	low(STR_10|8000h)
	movwf	(?_Uart1_PutString)
	movlw	high(STR_10|8000h)
	movwf	((?_Uart1_PutString))+1
	fcall	_Uart1_PutString
	line	195
;Function.c: 195: Uart1_PutString(ICCID);
	movlw	(_ICCID&0ffh)
	movwf	(?_Uart1_PutString)
	movlw	0x1/2
	movwf	(?_Uart1_PutString+1)
	fcall	_Uart1_PutString
	line	196
	
l33574:	
;Function.c: 196: Uart1_PutChar('#');
	movlw	(023h)
	fcall	_Uart1_PutChar
	line	200
	
l33576:	
;Function.c: 200: if(RomParams.bWinter==0)
	movlb 0	; select bank0
	movf	0+(_RomParams)+01h,f
	skipz
	goto	u9061
	goto	u9060
u9061:
	goto	l33580
u9060:
	line	202
	
l33578:	
;Function.c: 201: {
;Function.c: 202: Uart1_PutString("60#\0");
	movlw	low(STR_11|8000h)
	movwf	(?_Uart1_PutString)
	movlw	high(STR_11|8000h)
	movwf	((?_Uart1_PutString))+1
	fcall	_Uart1_PutString
	line	203
;Function.c: 203: }
	goto	l33582
	line	206
	
l33580:	
;Function.c: 204: else
;Function.c: 205: {
;Function.c: 206: Uart1_PutString("10#\0");
	movlw	low(STR_12|8000h)
	movwf	(?_Uart1_PutString)
	movlw	high(STR_12|8000h)
	movwf	((?_Uart1_PutString))+1
	fcall	_Uart1_PutString
	line	209
	
l33582:	
;Function.c: 207: }
;Function.c: 209: MakeTxTemperature(CurTemp);
	movf	(_CurTemp+1),w
	movwf	(?_MakeTxTemperature+1)
	movf	(_CurTemp),w
	movwf	(?_MakeTxTemperature)
	fcall	_MakeTxTemperature
	line	210
	
l33584:	
;Function.c: 210: for(int i=0;i<4;i++)
	clrf	(InteractServer@i_10586)
	clrf	(InteractServer@i_10586+1)
	line	212
	
l33590:	
;Function.c: 211: {
;Function.c: 212: Uart1_PutChar(TxTemperature[i]);
	movlb 0	; select bank0
	movf	(InteractServer@i_10586),w
	addlw	_TxTemperature&0ffh
	movwf	fsr1l
	clrf fsr1h	
	
	movf	indf1,w
	fcall	_Uart1_PutChar
	line	210
	
l33592:	
	movlb 0	; select bank0
	incf	(InteractServer@i_10586),f
	skipnz
	incf	(InteractServer@i_10586+1),f
	
l33594:	
	movf	(InteractServer@i_10586+1),w
	xorlw	80h
	movwf	btemp+0
	movlw	(high(04h))^80h
	subwf	btemp+0,w
	skipz
	goto	u9075
	movlw	low(04h)
	subwf	(InteractServer@i_10586),w
u9075:

	skipc
	goto	u9071
	goto	u9070
u9071:
	goto	l33590
u9070:
	goto	l33774
	line	215
	
l8728:	
;Function.c: 215: else if(gFlags.bNotify)
	btfss	(_gFlags),0
	goto	u9081
	goto	u9080
u9081:
	goto	l33620
u9080:
	line	217
	
l33596:	
;Function.c: 216: {
;Function.c: 217: Uart1_PutString("@#pt#3#\0");
	movlw	low(STR_13|8000h)
	movwf	(?_Uart1_PutString)
	movlw	high(STR_13|8000h)
	movwf	((?_Uart1_PutString))+1
	fcall	_Uart1_PutString
	line	218
;Function.c: 218: Uart1_PutString(ICCID);
	movlw	(_ICCID&0ffh)
	movwf	(?_Uart1_PutString)
	movlw	0x1/2
	movwf	(?_Uart1_PutString+1)
	fcall	_Uart1_PutString
	line	219
	
l33598:	
;Function.c: 219: Uart1_PutChar('#');
	movlw	(023h)
	fcall	_Uart1_PutChar
	line	223
	
l33600:	
;Function.c: 223: if(RomParams.bWinter==0)
	movlb 0	; select bank0
	movf	0+(_RomParams)+01h,f
	skipz
	goto	u9091
	goto	u9090
u9091:
	goto	l33604
u9090:
	line	225
	
l33602:	
;Function.c: 224: {
;Function.c: 225: Uart1_PutString("60#\0");
	movlw	low(STR_14|8000h)
	movwf	(?_Uart1_PutString)
	movlw	high(STR_14|8000h)
	movwf	((?_Uart1_PutString))+1
	fcall	_Uart1_PutString
	line	226
;Function.c: 226: }
	goto	l33606
	line	229
	
l33604:	
;Function.c: 227: else
;Function.c: 228: {
;Function.c: 229: Uart1_PutString("10#\0");
	movlw	low(STR_15|8000h)
	movwf	(?_Uart1_PutString)
	movlw	high(STR_15|8000h)
	movwf	((?_Uart1_PutString))+1
	fcall	_Uart1_PutString
	line	232
	
l33606:	
;Function.c: 230: }
;Function.c: 232: MakeTxTemperature(CurTemp);
	movf	(_CurTemp+1),w
	movwf	(?_MakeTxTemperature+1)
	movf	(_CurTemp),w
	movwf	(?_MakeTxTemperature)
	fcall	_MakeTxTemperature
	line	233
	
l33608:	
;Function.c: 233: for(int i=0;i<4;i++)
	clrf	(InteractServer@i_10590)
	clrf	(InteractServer@i_10590+1)
	line	235
	
l33614:	
;Function.c: 234: {
;Function.c: 235: Uart1_PutChar(TxTemperature[i]);
	movlb 0	; select bank0
	movf	(InteractServer@i_10590),w
	addlw	_TxTemperature&0ffh
	movwf	fsr1l
	clrf fsr1h	
	
	movf	indf1,w
	fcall	_Uart1_PutChar
	line	233
	
l33616:	
	movlb 0	; select bank0
	incf	(InteractServer@i_10590),f
	skipnz
	incf	(InteractServer@i_10590+1),f
	
l33618:	
	movf	(InteractServer@i_10590+1),w
	xorlw	80h
	movwf	btemp+0
	movlw	(high(04h))^80h
	subwf	btemp+0,w
	skipz
	goto	u9105
	movlw	low(04h)
	subwf	(InteractServer@i_10590),w
u9105:

	skipc
	goto	u9101
	goto	u9100
u9101:
	goto	l33614
u9100:
	goto	l33774
	line	240
	
l33620:	
;Function.c: 238: else
;Function.c: 239: {
;Function.c: 240: Uart1_PutString("@#pt#2#\0");
	movlw	low(STR_16|8000h)
	movwf	(?_Uart1_PutString)
	movlw	high(STR_16|8000h)
	movwf	((?_Uart1_PutString))+1
	fcall	_Uart1_PutString
	line	241
;Function.c: 241: Uart1_PutString(ICCID);
	movlw	(_ICCID&0ffh)
	movwf	(?_Uart1_PutString)
	movlw	0x1/2
	movwf	(?_Uart1_PutString+1)
	fcall	_Uart1_PutString
	line	242
	
l33622:	
;Function.c: 242: Uart1_PutChar('#');
	movlw	(023h)
	fcall	_Uart1_PutChar
	line	246
	
l33624:	
;Function.c: 246: if(RomParams.bWinter==0)
	movlb 0	; select bank0
	movf	0+(_RomParams)+01h,f
	skipz
	goto	u9111
	goto	u9110
u9111:
	goto	l33628
u9110:
	line	248
	
l33626:	
;Function.c: 247: {
;Function.c: 248: Uart1_PutString("60#\0");
	movlw	low(STR_17|8000h)
	movwf	(?_Uart1_PutString)
	movlw	high(STR_17|8000h)
	movwf	((?_Uart1_PutString))+1
	fcall	_Uart1_PutString
	line	249
;Function.c: 249: }
	goto	l33630
	line	252
	
l33628:	
;Function.c: 250: else
;Function.c: 251: {
;Function.c: 252: Uart1_PutString("10#\0");
	movlw	low(STR_18|8000h)
	movwf	(?_Uart1_PutString)
	movlw	high(STR_18|8000h)
	movwf	((?_Uart1_PutString))+1
	fcall	_Uart1_PutString
	line	255
	
l33630:	
;Function.c: 253: }
;Function.c: 255: if(TxErrDataIndex!=0xff)
	movf	(_TxErrDataIndex),w
	xorlw	0FFh&0ffh
	skipnz
	goto	u9121
	goto	u9120
u9121:
	goto	l33746
u9120:
	line	257
	
l33632:	
;Function.c: 256: {
;Function.c: 257: if(gFlags.bErrFull)
	btfss	(_gFlags),3
	goto	u9131
	goto	u9130
u9131:
	goto	l33710
u9130:
	line	259
	
l33634:	
;Function.c: 258: {
;Function.c: 259: for(i=(TxErrDataIndex-1);i<10;i--)
	movf	(_TxErrDataIndex),w
	addlw	0FFh
	movwf	(InteractServer@i)
	
l33636:	
	movlw	(0Ah)
	subwf	(InteractServer@i),w
	skipc
	goto	u9141
	goto	u9140
u9141:
	goto	l33640
u9140:
	goto	l33674
	line	261
	
l33640:	
;Function.c: 260: {
;Function.c: 261: for(j=0;j<12;j++)
	clrf	(InteractServer@j)
	line	263
	
l33646:	
;Function.c: 262: {
;Function.c: 263: addr=(i)*12;
	movlw	(0Ch)
	movwf	(?___bmul)
	movf	(InteractServer@i),w
	fcall	___bmul
	movwf	(InteractServer@addr)
	line	264
	
l33648:	
;Function.c: 264: addr+=16;
	movlw	(010h)
	addwf	(InteractServer@addr),f
	line	265
	
l33650:	
;Function.c: 265: addr+=(j<<1);
	lslf	(InteractServer@j),w
	addwf	(InteractServer@addr),f
	line	266
;Function.c: 266: t.u8s[0]=eeprom_read(addr);
	movf	(InteractServer@addr),w
	fcall	_eeprom_read
	movlb 0	; select bank0
	movwf	(InteractServer@t)
	line	267
;Function.c: 267: t.u8s[1]=eeprom_read(addr+1);
	incf	(InteractServer@addr),w
	fcall	_eeprom_read
	movlb 0	; select bank0
	movwf	0+(InteractServer@t)+01h
	line	268
;Function.c: 268: MakeTxTemperature(t);
	movf	(InteractServer@t+1),w
	movwf	(?_MakeTxTemperature+1)
	movf	(InteractServer@t),w
	movwf	(?_MakeTxTemperature)
	fcall	_MakeTxTemperature
	line	269
	
l33652:	
;Function.c: 269: for(k=0;k<4;k++)
	clrf	(InteractServer@k)
	line	271
	
l33658:	
;Function.c: 270: {
;Function.c: 271: Uart1_PutChar(TxTemperature[k]);
	movf	(InteractServer@k),w
	addlw	_TxTemperature&0ffh
	movwf	fsr1l
	clrf fsr1h	
	
	movf	indf1,w
	fcall	_Uart1_PutChar
	line	269
	
l33660:	
	movlb 0	; select bank0
	incf	(InteractServer@k),f
	
l33662:	
	movlw	(04h)
	subwf	(InteractServer@k),w
	skipc
	goto	u9151
	goto	u9150
u9151:
	goto	l33658
u9150:
	line	273
	
l33664:	
;Function.c: 272: }
;Function.c: 273: Uart1_PutChar('|');
	movlw	(07Ch)
	fcall	_Uart1_PutChar
	line	261
	
l33666:	
	movlb 0	; select bank0
	incf	(InteractServer@j),f
	
l33668:	
	movlw	(0Ch)
	subwf	(InteractServer@j),w
	skipc
	goto	u9161
	goto	u9160
u9161:
	goto	l33646
u9160:
	line	259
	
l33670:	
	decf	(InteractServer@i),f
	goto	l33636
	line	276
	
l33674:	
;Function.c: 274: }
;Function.c: 275: }
;Function.c: 276: for(i=9;i>TxErrDataIndex;i--)
	movlw	(09h)
	movwf	(InteractServer@i)
	goto	l33708
	line	278
	
l33676:	
;Function.c: 277: {
;Function.c: 278: for(j=0;j<12;j++)
	clrf	(InteractServer@j)
	line	280
	
l33682:	
;Function.c: 279: {
;Function.c: 280: addr=(i)*12;
	movlw	(0Ch)
	movwf	(?___bmul)
	movf	(InteractServer@i),w
	fcall	___bmul
	movwf	(InteractServer@addr)
	line	281
	
l33684:	
;Function.c: 281: addr+=16;
	movlw	(010h)
	addwf	(InteractServer@addr),f
	line	282
	
l33686:	
;Function.c: 282: addr+=(j<<1);
	lslf	(InteractServer@j),w
	addwf	(InteractServer@addr),f
	line	283
;Function.c: 283: t.u8s[0]=eeprom_read(addr);
	movf	(InteractServer@addr),w
	fcall	_eeprom_read
	movlb 0	; select bank0
	movwf	(InteractServer@t)
	line	284
;Function.c: 284: t.u8s[1]=eeprom_read(addr+1);
	incf	(InteractServer@addr),w
	fcall	_eeprom_read
	movlb 0	; select bank0
	movwf	0+(InteractServer@t)+01h
	line	285
;Function.c: 285: MakeTxTemperature(t);
	movf	(InteractServer@t+1),w
	movwf	(?_MakeTxTemperature+1)
	movf	(InteractServer@t),w
	movwf	(?_MakeTxTemperature)
	fcall	_MakeTxTemperature
	line	286
	
l33688:	
;Function.c: 286: for(k=0;k<4;k++)
	clrf	(InteractServer@k)
	line	288
	
l33694:	
;Function.c: 287: {
;Function.c: 288: Uart1_PutChar(TxTemperature[k]);
	movf	(InteractServer@k),w
	addlw	_TxTemperature&0ffh
	movwf	fsr1l
	clrf fsr1h	
	
	movf	indf1,w
	fcall	_Uart1_PutChar
	line	286
	
l33696:	
	movlb 0	; select bank0
	incf	(InteractServer@k),f
	
l33698:	
	movlw	(04h)
	subwf	(InteractServer@k),w
	skipc
	goto	u9171
	goto	u9170
u9171:
	goto	l33694
u9170:
	line	290
	
l33700:	
;Function.c: 289: }
;Function.c: 290: Uart1_PutChar('|');
	movlw	(07Ch)
	fcall	_Uart1_PutChar
	line	278
	
l33702:	
	movlb 0	; select bank0
	incf	(InteractServer@j),f
	
l33704:	
	movlw	(0Ch)
	subwf	(InteractServer@j),w
	skipc
	goto	u9181
	goto	u9180
u9181:
	goto	l33682
u9180:
	line	276
	
l33706:	
	decf	(InteractServer@i),f
	
l33708:	
	movf	(InteractServer@i),w
	subwf	(_TxErrDataIndex),w
	skipc
	goto	u9191
	goto	u9190
u9191:
	goto	l33676
u9190:
	goto	l33746
	line	296
	
l33710:	
;Function.c: 294: else
;Function.c: 295: {
;Function.c: 296: for(i=0;i<TxErrDataIndex;i++)
	clrf	(InteractServer@i)
	goto	l33744
	line	299
	
l33712:	
;Function.c: 297: {
;Function.c: 299: for(j=0;j<12;j++)
	clrf	(InteractServer@j)
	line	301
	
l33718:	
;Function.c: 300: {
;Function.c: 301: addr=i*12;
	movlw	(0Ch)
	movwf	(?___bmul)
	movf	(InteractServer@i),w
	fcall	___bmul
	movwf	(InteractServer@addr)
	line	302
	
l33720:	
;Function.c: 302: addr+=16;
	movlw	(010h)
	addwf	(InteractServer@addr),f
	line	303
	
l33722:	
;Function.c: 303: addr+=(j<<1);
	lslf	(InteractServer@j),w
	addwf	(InteractServer@addr),f
	line	304
;Function.c: 304: t.u8s[0]=eeprom_read(addr);
	movf	(InteractServer@addr),w
	fcall	_eeprom_read
	movlb 0	; select bank0
	movwf	(InteractServer@t)
	line	305
;Function.c: 305: t.u8s[1]=eeprom_read(addr+1);
	incf	(InteractServer@addr),w
	fcall	_eeprom_read
	movlb 0	; select bank0
	movwf	0+(InteractServer@t)+01h
	line	306
;Function.c: 306: MakeTxTemperature(t);
	movf	(InteractServer@t+1),w
	movwf	(?_MakeTxTemperature+1)
	movf	(InteractServer@t),w
	movwf	(?_MakeTxTemperature)
	fcall	_MakeTxTemperature
	line	307
	
l33724:	
;Function.c: 307: for(k=0;k<4;k++)
	clrf	(InteractServer@k)
	line	309
	
l33730:	
;Function.c: 308: {
;Function.c: 309: Uart1_PutChar(TxTemperature[k]);
	movf	(InteractServer@k),w
	addlw	_TxTemperature&0ffh
	movwf	fsr1l
	clrf fsr1h	
	
	movf	indf1,w
	fcall	_Uart1_PutChar
	line	307
	
l33732:	
	movlb 0	; select bank0
	incf	(InteractServer@k),f
	
l33734:	
	movlw	(04h)
	subwf	(InteractServer@k),w
	skipc
	goto	u9201
	goto	u9200
u9201:
	goto	l33730
u9200:
	line	311
	
l33736:	
;Function.c: 310: }
;Function.c: 311: Uart1_PutChar('|');
	movlw	(07Ch)
	fcall	_Uart1_PutChar
	line	299
	
l33738:	
	movlb 0	; select bank0
	incf	(InteractServer@j),f
	
l33740:	
	movlw	(0Ch)
	subwf	(InteractServer@j),w
	skipc
	goto	u9211
	goto	u9210
u9211:
	goto	l33718
u9210:
	line	296
	
l33742:	
	incf	(InteractServer@i),f
	
l33744:	
	movf	(_TxErrDataIndex),w
	subwf	(InteractServer@i),w
	skipc
	goto	u9221
	goto	u9220
u9221:
	goto	l33712
u9220:
	line	316
	
l33746:	
;Function.c: 312: }
;Function.c: 313: }
;Function.c: 314: }
;Function.c: 315: }
;Function.c: 316: for(i=0;i<12;i++)
	clrf	(InteractServer@i)
	
l33748:	
	movlw	(0Ch)
	subwf	(InteractServer@i),w
	skipc
	goto	u9231
	goto	u9230
u9231:
	goto	l33752
u9230:
	goto	l33774
	line	318
	
l33752:	
;Function.c: 317: {
;Function.c: 318: MakeTxTemperature(TList.T[i]);
	lslf	(InteractServer@i),w
	addlw	_TList&0ffh
	movwf	fsr1l
	movlw 1	; select bank2/3
	movwf fsr1h	
	
	moviw	[0]fsr1
	movwf	(?_MakeTxTemperature)
	moviw	[1]fsr1
	movwf	(?_MakeTxTemperature+1)
	fcall	_MakeTxTemperature
	line	319
	
l33754:	
;Function.c: 319: for(int j=0;j<4;j++)
	clrf	(InteractServer@j_10594)
	clrf	(InteractServer@j_10594+1)
	line	321
	
l33760:	
;Function.c: 320: {
;Function.c: 321: Uart1_PutChar(TxTemperature[j]);
	movlb 0	; select bank0
	movf	(InteractServer@j_10594),w
	addlw	_TxTemperature&0ffh
	movwf	fsr1l
	clrf fsr1h	
	
	movf	indf1,w
	fcall	_Uart1_PutChar
	line	319
	
l33762:	
	movlb 0	; select bank0
	incf	(InteractServer@j_10594),f
	skipnz
	incf	(InteractServer@j_10594+1),f
	
l33764:	
	movf	(InteractServer@j_10594+1),w
	xorlw	80h
	movwf	btemp+0
	movlw	(high(04h))^80h
	subwf	btemp+0,w
	skipz
	goto	u9245
	movlw	low(04h)
	subwf	(InteractServer@j_10594),w
u9245:

	skipc
	goto	u9241
	goto	u9240
u9241:
	goto	l33760
u9240:
	line	323
	
l33766:	
;Function.c: 322: }
;Function.c: 323: if(i!=(12-1))
	movlb 0	; select bank0
	movf	(InteractServer@i),w
	xorlw	0Bh&0ffh
	skipnz
	goto	u9251
	goto	u9250
u9251:
	goto	l33770
u9250:
	line	325
	
l33768:	
;Function.c: 324: {
;Function.c: 325: Uart1_PutChar('|');
	movlw	(07Ch)
	fcall	_Uart1_PutChar
	line	316
	
l33770:	
	movlb 0	; select bank0
	incf	(InteractServer@i),f
	goto	l33748
	line	329
	
l33774:	
;Function.c: 326: }
;Function.c: 327: }
;Function.c: 328: }
;Function.c: 329: Uart1_PutChar('#');
	movlw	(023h)
	fcall	_Uart1_PutChar
	line	330
;Function.c: 330: Uart1_PutChar('@');
	movlw	(040h)
	fcall	_Uart1_PutChar
	line	331
;Function.c: 331: Uart1_PutChar(0x1a);
	movlw	(01Ah)
	fcall	_Uart1_PutChar
	line	332
	
l33776:	
;Function.c: 332: ATCommand_WaitACKTimes=400;
	movlw	low(0190h)
	movlb 0	; select bank0
	movwf	(_ATCommand_WaitACKTimes)
	movlw	high(0190h)
	movwf	((_ATCommand_WaitACKTimes))+1
	line	333
	
l33778:	
;Function.c: 333: ATCommand_Clear=0x1a;
	movlw	(01Ah)
	movwf	(_ATCommand_Clear)
	line	334
	
l33780:	
;Function.c: 334: strcpy(ATCommand_OkString,"$OK#");
	movlw	low(STR_19|8000h)
	movwf	(?_strcpy)
	movlw	high(STR_19|8000h)
	movwf	((?_strcpy))+1
	movlw	(_ATCommand_OkString)&0ffh
	fcall	_strcpy
	line	335
	
l33782:	
;Function.c: 335: strcpy(ATCommand_ErrString,"CLOSE");
	movlw	low(STR_20|8000h)
	movwf	(?_strcpy)
	movlw	high(STR_20|8000h)
	movwf	((?_strcpy))+1
	movlw	(_ATCommand_ErrString)&0ffh
	fcall	_strcpy
	line	336
	
l33784:	
;Function.c: 336: res=ATCommand_WaitData();
	fcall	_ATCommand_WaitData
	movwf	(InteractServer@res)
	line	337
	
l33786:	
;Function.c: 337: if(res!=ATACK_Null)
	movf	(InteractServer@res),w
	skipz
	goto	u9260
	goto	l33790
u9260:
	goto	l33796
	line	339
	
l33790:	
;Function.c: 339: __delay_20ms(100);;
	movlw	064h
	movwf	(?___delay_20ms)
	clrf	(?___delay_20ms+1)
	fcall	___delay_20ms
	line	340
	
l33792:	
;Function.c: 340: retry--;
	decf	(InteractServer@retry),f
	line	182
	
l33794:	
	movf	(InteractServer@retry),f
	skipz
	goto	u9271
	goto	u9270
u9271:
	goto	l33558
u9270:
	line	342
	
l33796:	
;Function.c: 341: }
;Function.c: 342: if(res!=ATACK_OK)
	decf	(InteractServer@res),w
	skipnz
	goto	u9281
	goto	u9280
u9281:
	goto	l33568
u9280:
	line	344
	
l33798:	
;Function.c: 343: {
;Function.c: 344: if(res==ATACK_Err)
	movf	(InteractServer@res),w
	xorlw	02h&0ffh
	skipz
	goto	u9291
	goto	u9290
u9291:
	goto	l33802
u9290:
	line	345
	
l33800:	
;Function.c: 345: ErrState=MissAT_ServerClose;
	movlw	(022h)
	movwf	(_ErrState)
	goto	l33804
	line	347
	
l33802:	
;Function.c: 346: else
;Function.c: 347: ErrState=MissAT_NoServerData;
	movlw	(020h)
	movwf	(_ErrState)
	line	348
	
l33804:	
;Function.c: 348: Uart1_PutChar(0x1b);
	movlw	(01Bh)
	fcall	_Uart1_PutChar
	goto	l33568
	line	358
	
l8727:	
	return
	opt stack 0
GLOBAL	__end_of_InteractServer
	__end_of_InteractServer:
;; =============== function _InteractServer ends ============

	signat	_InteractServer,89
	global	_InitGPRS
psect	text2011,local,class=CODE,delta=2
global __ptext2011
__ptext2011:

;; *************** function _InitGPRS *****************
;; Defined at:
;;		line 412 in file "F:\work\WYP\NBIoT\Function.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;  strx            2   28[BANK0 ] PTR unsigned char 
;;		 -> ATCommand_RxList(100), RAM(128), 
;;  retry           1   30[BANK0 ] unsigned char 
;;  i               1   27[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, fsr0l, fsr0h, fsr1l, fsr1h, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 1D/0
;;		On exit  : 1F/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       0       0       0       0       0       0       0
;;      Locals:         0       4       0       0       0       0       0       0
;;      Temps:          0       2       0       0       0       0       0       0
;;      Totals:         0       6       0       0       0       0       0       0
;;Total ram usage:        6 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    6
;; This function calls:
;;		___delay_20ms
;;		_ATCommand_SendCmd
;;		_Uart1_PutChar
;;		_strstr
;;		_atoi
;;		_LcdDisplay_CSQ
;; This function is called by:
;;		_CallSend
;;		_CallTestSend
;; This function uses a non-reentrant model
;;
psect	text2011
	file	"F:\work\WYP\NBIoT\Function.c"
	line	412
	global	__size_of_InitGPRS
	__size_of_InitGPRS	equ	__end_of_InitGPRS-_InitGPRS
	
_InitGPRS:	
	opt	stack 11
; Regs used in _InitGPRS: [wreg-status,0+pclath+cstack]
	line	414
	
l33370:	
	line	415
	
l33372:	
;Function.c: 415: __delay_20ms(150);
	movlw	096h
	movlb 0	; select bank0
	movwf	(?___delay_20ms)
	clrf	(?___delay_20ms+1)
	fcall	___delay_20ms
	line	417
	
l33374:	
;Function.c: 417: if(ATCommand_SendCmd("AT\0")!=ATACK_OK)
	movlw	low(STR_21|8000h)
	movwf	(?_ATCommand_SendCmd)
	movlw	high(STR_21|8000h)
	movwf	((?_ATCommand_SendCmd))+1
	fcall	_ATCommand_SendCmd
	xorlw	01h&0ffh
	skipnz
	goto	u8751
	goto	u8750
u8751:
	goto	l33380
u8750:
	line	419
	
l33376:	
;Function.c: 418: {
;Function.c: 419: ErrState=MissAT;
	movlw	(03h)
	movwf	(_ErrState)
	goto	l8789
	line	422
	
l33380:	
;Function.c: 421: }
;Function.c: 422: __delay_20ms(1000);
	movlw	low(03E8h)
	movwf	(?___delay_20ms)
	movlw	high(03E8h)
	movwf	((?___delay_20ms))+1
	fcall	___delay_20ms
	line	423
;Function.c: 423: Uart1_PutChar(0x1b);
	movlw	(01Bh)
	fcall	_Uart1_PutChar
	line	424
	
l33382:	
;Function.c: 424: if(ATCommand_SendCmd("ATH\0")!=ATACK_OK)
	movlw	low(STR_22|8000h)
	movlb 0	; select bank0
	movwf	(?_ATCommand_SendCmd)
	movlw	high(STR_22|8000h)
	movwf	((?_ATCommand_SendCmd))+1
	fcall	_ATCommand_SendCmd
	xorlw	01h&0ffh
	skipnz
	goto	u8761
	goto	u8760
u8761:
	goto	l33388
u8760:
	line	426
	
l33384:	
;Function.c: 425: {
;Function.c: 426: ErrState=MissAT_ATH;
	movlw	(0Bh)
	movwf	(_ErrState)
	goto	l8789
	line	439
	
l33388:	
;Function.c: 428: }
;Function.c: 439: if(ATCommand_SendCmd("ATE1\0")!=ATACK_OK)
	movlw	low(STR_23|8000h)
	movwf	(?_ATCommand_SendCmd)
	movlw	high(STR_23|8000h)
	movwf	((?_ATCommand_SendCmd))+1
	fcall	_ATCommand_SendCmd
	xorlw	01h&0ffh
	skipnz
	goto	u8771
	goto	u8770
u8771:
	goto	l33394
u8770:
	line	441
	
l33390:	
;Function.c: 440: {
;Function.c: 441: ErrState=MissAT_ATE1;
	movlw	(0Ch)
	movwf	(_ErrState)
	goto	l8789
	line	444
	
l33394:	
;Function.c: 443: }
;Function.c: 444: retry=10;
	movlw	(0Ah)
	movwf	(InitGPRS@retry)
	line	445
;Function.c: 445: while(retry!=0)
	goto	l33404
	line	447
	
l33396:	
;Function.c: 446: {
;Function.c: 447: if(ATCommand_SendCmd("AT+CIMI\0")==ATACK_OK)
	movlw	low(STR_24|8000h)
	movwf	(?_ATCommand_SendCmd)
	movlw	high(STR_24|8000h)
	movwf	((?_ATCommand_SendCmd))+1
	fcall	_ATCommand_SendCmd
	xorlw	01h&0ffh
	skipz
	goto	u8781
	goto	u8780
u8781:
	goto	l33400
u8780:
	goto	l33406
	line	451
	
l33400:	
;Function.c: 450: }
;Function.c: 451: __delay_20ms(150);
	movlw	096h
	movwf	(?___delay_20ms)
	clrf	(?___delay_20ms+1)
	fcall	___delay_20ms
	line	452
	
l33402:	
;Function.c: 452: retry--;
	decf	(InitGPRS@retry),f
	line	445
	
l33404:	
	movf	(InitGPRS@retry),f
	skipz
	goto	u8791
	goto	u8790
u8791:
	goto	l33396
u8790:
	line	454
	
l33406:	
;Function.c: 453: }
;Function.c: 454: if(retry==0)
	movf	(InitGPRS@retry),f
	skipz
	goto	u8801
	goto	u8800
u8801:
	goto	l33412
u8800:
	line	456
	
l33408:	
;Function.c: 455: {
;Function.c: 456: ErrState=MissSimCard;
	movlw	(04h)
	movwf	(_ErrState)
	goto	l8789
	line	459
	
l33412:	
;Function.c: 458: }
;Function.c: 459: retry=10;
	movlw	(0Ah)
	movwf	(InitGPRS@retry)
	line	460
;Function.c: 460: while(retry!=0)
	goto	l33440
	line	463
	
l33414:	
;Function.c: 461: {
;Function.c: 463: if(ATCommand_SendCmd("AT+ICCID\0")==ATACK_OK)
	movlw	low(STR_25|8000h)
	movwf	(?_ATCommand_SendCmd)
	movlw	high(STR_25|8000h)
	movwf	((?_ATCommand_SendCmd))+1
	fcall	_ATCommand_SendCmd
	xorlw	01h&0ffh
	skipz
	goto	u8811
	goto	u8810
u8811:
	goto	l33440
u8810:
	line	465
	
l33416:	
;Function.c: 464: {
;Function.c: 465: strx=strstr((const char*)ATCommand_RxList,"+ICCID: ");
	movlw	low(8588)
	movwf	(?_strstr)
	movlw	high(8588)
	movwf	((?_strstr))+1
	movlw	low(STR_26|8000h)
	movwf	(0+?_strstr+02h)
	movlw	high(STR_26|8000h)
	movwf	((0+?_strstr+02h))+1
	fcall	_strstr
	movf	(1+(?_strstr)),w
	movwf	(InitGPRS@strx+1)
	movf	(0+(?_strstr)),w
	movwf	(InitGPRS@strx)
	line	466
	
l33418:	
;Function.c: 466: if(strx!=0)
	movf	(InitGPRS@strx+1),w
	iorwf	(InitGPRS@strx),w
	skipnz
	goto	u8821
	goto	u8820
u8821:
	goto	l33436
u8820:
	line	468
	
l33420:	
;Function.c: 467: {
;Function.c: 468: for(i=0;i<15;i++)
	clrf	(InitGPRS@i)
	line	470
	
l33426:	
;Function.c: 469: {
;Function.c: 470: ICCID[i]=strx[13+i];
	movf	(InitGPRS@i),w
	addlw	_ICCID&0ffh
	movwf	fsr1l
	clrf fsr1h	
	
	movf	(InitGPRS@i),w
	addwf	(InitGPRS@strx),w
	movwf	(??_InitGPRS+0)+0
	movf	(InitGPRS@strx+1),w
	skipnc
	incf	wreg,f
	btfsc	(InitGPRS@i),7
	decf	wreg,f
	movwf	((??_InitGPRS+0)+0)+1
	movf	0+(??_InitGPRS+0)+0,w
	addlw	low(0Dh)
	movwf	fsr0l
	movlw	high(0Dh)
	addwfc	1+(??_InitGPRS+0)+0,w
	movwf	1+fsr0l
	movf	indf0,w
	movwf	indf1
	line	468
	
l33428:	
	incf	(InitGPRS@i),f
	
l33430:	
	movlw	(0Fh)
	subwf	(InitGPRS@i),w
	skipc
	goto	u8831
	goto	u8830
u8831:
	goto	l33426
u8830:
	line	472
	
l33432:	
;Function.c: 471: }
;Function.c: 472: ICCID[15]='\0';
	movlb 1	; select bank1
	clrf	0+(_ICCID)^080h+0Fh
	line	473
;Function.c: 473: break;
	goto	l33442
	line	477
	
l33436:	
;Function.c: 475: else
;Function.c: 476: {
;Function.c: 477: retry--;
	decf	(InitGPRS@retry),f
	line	478
	
l33438:	
;Function.c: 478: __delay_20ms(150);
	movlw	096h
	movwf	(?___delay_20ms)
	clrf	(?___delay_20ms+1)
	fcall	___delay_20ms
	line	460
	
l33440:	
	movf	(InitGPRS@retry),f
	skipz
	goto	u8841
	goto	u8840
u8841:
	goto	l33414
u8840:
	line	505
	
l33442:	
;Function.c: 479: }
;Function.c: 480: }
;Function.c: 502: }
;Function.c: 505: if(ATCommand_SendCmd("AT+CNMI=0,0\0")!=ATACK_OK)
	movlw	low(STR_27|8000h)
	movlb 0	; select bank0
	movwf	(?_ATCommand_SendCmd)
	movlw	high(STR_27|8000h)
	movwf	((?_ATCommand_SendCmd))+1
	fcall	_ATCommand_SendCmd
	xorlw	01h&0ffh
	skipnz
	goto	u8851
	goto	u8850
u8851:
	goto	l33448
u8850:
	line	507
	
l33444:	
;Function.c: 506: {
;Function.c: 507: ErrState=MissAT_CNMI;
	movlw	(0Dh)
	movwf	(_ErrState)
	goto	l8789
	line	511
	
l33448:	
;Function.c: 509: }
;Function.c: 511: if(ATCommand_SendCmd("AT+CMGF=1\0")!=ATACK_OK)
	movlw	low(STR_28|8000h)
	movwf	(?_ATCommand_SendCmd)
	movlw	high(STR_28|8000h)
	movwf	((?_ATCommand_SendCmd))+1
	fcall	_ATCommand_SendCmd
	xorlw	01h&0ffh
	skipnz
	goto	u8861
	goto	u8860
u8861:
	goto	l33454
u8860:
	line	513
	
l33450:	
;Function.c: 512: {
;Function.c: 513: ErrState=MissAT_CMGF;
	movlw	(0Eh)
	movwf	(_ErrState)
	goto	l8789
	line	520
	
l33454:	
;Function.c: 515: }
;Function.c: 520: retry=10;
	movlw	(0Ah)
	movwf	(InitGPRS@retry)
	line	521
;Function.c: 521: CSQ=0xff;
	movlw	(0FFh)
	movwf	(_CSQ)
	line	522
;Function.c: 522: while(retry!=0)
	goto	l33474
	line	524
	
l33456:	
;Function.c: 523: {
;Function.c: 524: if(ATCommand_SendCmd("AT+CSQ\0")==ATACK_OK)
	movlw	low(STR_29|8000h)
	movwf	(?_ATCommand_SendCmd)
	movlw	high(STR_29|8000h)
	movwf	((?_ATCommand_SendCmd))+1
	fcall	_ATCommand_SendCmd
	xorlw	01h&0ffh
	skipz
	goto	u8871
	goto	u8870
u8871:
	goto	l33474
u8870:
	line	526
	
l33458:	
;Function.c: 525: {
;Function.c: 526: strx=strstr((const char*)ATCommand_RxList,"+CSQ: ");
	movlw	low(8588)
	movwf	(?_strstr)
	movlw	high(8588)
	movwf	((?_strstr))+1
	movlw	low(STR_30|8000h)
	movwf	(0+?_strstr+02h)
	movlw	high(STR_30|8000h)
	movwf	((0+?_strstr+02h))+1
	fcall	_strstr
	movf	(1+(?_strstr)),w
	movwf	(InitGPRS@strx+1)
	movf	(0+(?_strstr)),w
	movwf	(InitGPRS@strx)
	line	527
	
l33460:	
;Function.c: 527: if(strx!=0)
	movf	(InitGPRS@strx+1),w
	iorwf	(InitGPRS@strx),w
	skipnz
	goto	u8881
	goto	u8880
u8881:
	goto	l33470
u8880:
	line	529
	
l33462:	
;Function.c: 528: {
;Function.c: 529: CSQ=atoi(strx+6);
	movf	(InitGPRS@strx),w
	addlw	low(06h)
	movwf	(??_InitGPRS+0)+0
	movlw	high(06h)
	addwfc	(InitGPRS@strx+1),w
	movwf	1+(??_InitGPRS+0)+0
	movf	0+(??_InitGPRS+0)+0,w
	movwf	(?_atoi)
	movf	1+(??_InitGPRS+0)+0,w
	movwf	(?_atoi+1)
	fcall	_atoi
	movf	(0+(?_atoi)),w
	movwf	(_CSQ)
	line	531
	
l33464:	
;Function.c: 531: LcdDisplay_CSQ();
	fcall	_LcdDisplay_CSQ
	line	533
	
l33466:	
;Function.c: 533: if(CSQ!=0)
	movlb 0	; select bank0
	movf	(_CSQ),w
	skipz
	goto	u8890
	goto	l8809
u8890:
	goto	l33476
	line	538
	
l33470:	
;Function.c: 536: else
;Function.c: 537: {
;Function.c: 538: retry--;
	decf	(InitGPRS@retry),f
	line	539
	
l33472:	
;Function.c: 539: __delay_20ms(150);
	movlw	096h
	movwf	(?___delay_20ms)
	clrf	(?___delay_20ms+1)
	fcall	___delay_20ms
	goto	l33474
	line	541
	
l8809:	
	line	522
	
l33474:	
	movf	(InitGPRS@retry),f
	skipz
	goto	u8901
	goto	u8900
u8901:
	goto	l33456
u8900:
	line	543
	
l33476:	
;Function.c: 540: }
;Function.c: 541: }
;Function.c: 542: }
;Function.c: 543: if(retry==0 && CSQ!=0xff)
	movf	(InitGPRS@retry),f
	skipz
	goto	u8911
	goto	u8910
u8911:
	goto	l33484
u8910:
	
l33478:	
	movf	(_CSQ),w
	xorlw	0FFh&0ffh
	skipnz
	goto	u8921
	goto	u8920
u8921:
	goto	l33484
u8920:
	line	545
	
l33480:	
;Function.c: 544: {
;Function.c: 545: ErrState=MissAT_CSQ;
	movlw	(0Fh)
	movwf	(_ErrState)
	goto	l8789
	line	570
	
l33484:	
;Function.c: 547: }
;Function.c: 570: retry=20;
	movlw	(014h)
	movwf	(InitGPRS@retry)
	line	571
;Function.c: 571: while(retry!=0)
	goto	l33508
	line	573
	
l33486:	
;Function.c: 572: {
;Function.c: 573: if(ATCommand_SendCmd("AT+CGREG?\0")!=ATACK_OK)
	movlw	low(STR_31|8000h)
	movwf	(?_ATCommand_SendCmd)
	movlw	high(STR_31|8000h)
	movwf	((?_ATCommand_SendCmd))+1
	fcall	_ATCommand_SendCmd
	xorlw	01h&0ffh
	skipnz
	goto	u8931
	goto	u8930
u8931:
	goto	l33492
u8930:
	line	575
	
l33488:	
;Function.c: 574: {
;Function.c: 575: ErrState=MissAT_COPS;
	movlw	(010h)
	movwf	(_ErrState)
	goto	l8789
	line	578
	
l33492:	
;Function.c: 577: }
;Function.c: 578: strx=strstr((const char*)ATCommand_RxList,"+CGREG: 0,1");
	movlw	low(8588)
	movwf	(?_strstr)
	movlw	high(8588)
	movwf	((?_strstr))+1
	movlw	low(STR_32|8000h)
	movwf	(0+?_strstr+02h)
	movlw	high(STR_32|8000h)
	movwf	((0+?_strstr+02h))+1
	fcall	_strstr
	movf	(1+(?_strstr)),w
	movwf	(InitGPRS@strx+1)
	movf	(0+(?_strstr)),w
	movwf	(InitGPRS@strx)
	line	579
	
l33494:	
;Function.c: 579: if(strx!=0)
	movf	(InitGPRS@strx+1),w
	iorwf	(InitGPRS@strx),w
	skipnz
	goto	u8941
	goto	u8940
u8941:
	goto	l33498
u8940:
	goto	l33510
	line	583
	
l33498:	
;Function.c: 582: }
;Function.c: 583: strx=strstr((const char*)ATCommand_RxList,"+CGREG: 0,5");
	movlw	low(8588)
	movwf	(?_strstr)
	movlw	high(8588)
	movwf	((?_strstr))+1
	movlw	low(STR_33|8000h)
	movwf	(0+?_strstr+02h)
	movlw	high(STR_33|8000h)
	movwf	((0+?_strstr+02h))+1
	fcall	_strstr
	movf	(1+(?_strstr)),w
	movwf	(InitGPRS@strx+1)
	movf	(0+(?_strstr)),w
	movwf	(InitGPRS@strx)
	line	584
	
l33500:	
;Function.c: 584: if(strx!=0)
	movf	(InitGPRS@strx+1),w
	iorwf	(InitGPRS@strx),w
	skipnz
	goto	u8951
	goto	u8950
u8951:
	goto	l33504
u8950:
	goto	l33510
	line	588
	
l33504:	
;Function.c: 587: }
;Function.c: 588: __delay_20ms(150);
	movlw	096h
	movwf	(?___delay_20ms)
	clrf	(?___delay_20ms+1)
	fcall	___delay_20ms
	line	589
	
l33506:	
;Function.c: 589: retry--;
	decf	(InitGPRS@retry),f
	line	571
	
l33508:	
	movf	(InitGPRS@retry),f
	skipz
	goto	u8961
	goto	u8960
u8961:
	goto	l33486
u8960:
	line	591
	
l33510:	
;Function.c: 590: }
;Function.c: 591: if(retry==0)
	movf	(InitGPRS@retry),f
	skipz
	goto	u8971
	goto	u8970
u8971:
	goto	l33516
u8970:
	line	593
	
l33512:	
;Function.c: 592: {
;Function.c: 593: ErrState=MissNet;
	movlw	(05h)
	movwf	(_ErrState)
	goto	l8789
	line	596
	
l33516:	
;Function.c: 595: }
;Function.c: 596: if(ATCommand_SendCmd("AT+COLP=1\0")!=ATACK_OK)
	movlw	low(STR_34|8000h)
	movwf	(?_ATCommand_SendCmd)
	movlw	high(STR_34|8000h)
	movwf	((?_ATCommand_SendCmd))+1
	fcall	_ATCommand_SendCmd
	xorlw	01h&0ffh
	skipnz
	goto	u8981
	goto	u8980
u8981:
	goto	l33522
u8980:
	line	598
	
l33518:	
;Function.c: 597: {
;Function.c: 598: ErrState=MissAT_COLP;
	movlw	(011h)
	movwf	(_ErrState)
	goto	l8789
	line	644
	
l33522:	
;Function.c: 600: }
;Function.c: 644: if(ICCID[0]=='6'|| ICCID[0]=='1')
	movlb 1	; select bank1
	movf	(_ICCID)^080h,w
	xorlw	036h&0ffh
	skipnz
	goto	u8991
	goto	u8990
u8991:
	goto	l33526
u8990:
	
l33524:	
	movf	(_ICCID)^080h,w
	xorlw	031h&0ffh
	skipz
	goto	u9001
	goto	u9000
u9001:
	goto	l33534
u9000:
	line	646
	
l33526:	
;Function.c: 645: {
;Function.c: 646: if(ATCommand_SendCmd("AT+CSTT=\"UNIM2M.NJM2MAPN\",\"\",\"\"\0")!=ATACK_OK)
	movlw	low(STR_35|8000h)
	movlb 0	; select bank0
	movwf	(?_ATCommand_SendCmd)
	movlw	high(STR_35|8000h)
	movwf	((?_ATCommand_SendCmd))+1
	fcall	_ATCommand_SendCmd
	xorlw	01h&0ffh
	skipnz
	goto	u9011
	goto	u9010
u9011:
	goto	l33542
u9010:
	line	648
	
l33528:	
;Function.c: 647: {
;Function.c: 648: ErrState=MissAT_CSTT;
	movlw	(01Ah)
	movwf	(_ErrState)
	line	649
	
l33530:	
;Function.c: 649: gFlags.bRetry=1;
	bsf	(_gFlags),4
	goto	l8789
	line	655
	
l33534:	
;Function.c: 653: else
;Function.c: 654: {
;Function.c: 655: if(ATCommand_SendCmd("AT+CSTT=\"CMMTM\",\"\",\"\"\0")!=ATACK_OK)
	movlw	low(STR_36|8000h)
	movlb 0	; select bank0
	movwf	(?_ATCommand_SendCmd)
	movlw	high(STR_36|8000h)
	movwf	((?_ATCommand_SendCmd))+1
	fcall	_ATCommand_SendCmd
	xorlw	01h&0ffh
	skipnz
	goto	u9021
	goto	u9020
u9021:
	goto	l33542
u9020:
	goto	l33528
	line	662
	
l33542:	
;Function.c: 660: }
;Function.c: 661: }
;Function.c: 662: ATCommand_WaitACKTimes=400;
	movlw	low(0190h)
	movwf	(_ATCommand_WaitACKTimes)
	movlw	high(0190h)
	movwf	((_ATCommand_WaitACKTimes))+1
	line	663
	
l33544:	
;Function.c: 663: if(ATCommand_SendCmd("AT+CIICR\0")!=ATACK_OK)
	movlw	low(STR_37|8000h)
	movwf	(?_ATCommand_SendCmd)
	movlw	high(STR_37|8000h)
	movwf	((?_ATCommand_SendCmd))+1
	fcall	_ATCommand_SendCmd
	xorlw	01h&0ffh
	skipnz
	goto	u9031
	goto	u9030
u9031:
	goto	l33552
u9030:
	line	665
	
l33546:	
;Function.c: 664: {
;Function.c: 665: ErrState=MissAT_CIICR;
	movlw	(01Bh)
	movwf	(_ErrState)
	goto	l33530
	line	670
	
l33552:	
;Function.c: 668: }
;Function.c: 670: ATCommand_SendCmd("AT+CIFSR\0");
	movlw	low(STR_38|8000h)
	movwf	(?_ATCommand_SendCmd)
	movlw	high(STR_38|8000h)
	movwf	((?_ATCommand_SendCmd))+1
	fcall	_ATCommand_SendCmd
	line	671
	
l8789:	
	return
	opt stack 0
GLOBAL	__end_of_InitGPRS
	__end_of_InitGPRS:
;; =============== function _InitGPRS ends ============

	signat	_InitGPRS,88
	global	_PowerON
psect	text2012,local,class=CODE,delta=2
global __ptext2012
__ptext2012:

;; *************** function _PowerON *****************
;; Defined at:
;;		line 694 in file "F:\work\WYP\NBIoT\Function.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;  i               1   25[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;                  1    wreg      unsigned char 
;; Registers used:
;;		wreg, fsr0l, fsr0h, fsr1l, fsr1h, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 1F/0
;;		On exit  : 1D/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       0       0       0       0       0       0       0
;;      Locals:         0       1       0       0       0       0       0       0
;;      Temps:          0       0       0       0       0       0       0       0
;;      Totals:         0       1       0       0       0       0       0       0
;;Total ram usage:        1 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    6
;; This function calls:
;;		_PowerDown
;;		___delay_20ms
;;		_ATCommand_SendCmd
;; This function is called by:
;;		_CallProc
;;		_CallTestProc
;; This function uses a non-reentrant model
;;
psect	text2012
	file	"F:\work\WYP\NBIoT\Function.c"
	line	694
	global	__size_of_PowerON
	__size_of_PowerON	equ	__end_of_PowerON-_PowerON
	
_PowerON:	
	opt	stack 12
; Regs used in _PowerON: [wreg-status,0+pclath+cstack]
	line	696
	
l33342:	
;Function.c: 695: unsigned char i;
;Function.c: 696: if(RD4==0)
	btfsc	(124/8),(124)&7
	goto	u8711
	goto	u8710
u8711:
	goto	l33352
u8710:
	line	698
	
l33344:	
;Function.c: 697: {
;Function.c: 698: if(PowerDown()==0)
	fcall	_PowerDown
	iorlw	0
	skipz
	goto	u8721
	goto	u8720
u8721:
	goto	l33350
u8720:
	line	700
	
l33346:	
;Function.c: 699: {
;Function.c: 700: ErrState=Miss900a;
	movlw	(02h)
	movwf	(_ErrState)
	line	701
;Function.c: 701: return 0;
	movlw	(0)
	goto	l8843
	line	703
	
l33350:	
;Function.c: 702: }
;Function.c: 703: __delay_20ms(150);
	movlw	096h
	movwf	(?___delay_20ms)
	clrf	(?___delay_20ms+1)
	fcall	___delay_20ms
	line	705
	
l33352:	
;Function.c: 704: }
;Function.c: 705: LATD5=1;
	movlb 2	; select bank2
	bsf	(2173/8)^0100h,(2173)&7
	line	706
	
l33354:	
;Function.c: 706: i=15;
	movlw	(0Fh)
	movlb 0	; select bank0
	movwf	(PowerON@i)
	line	707
;Function.c: 707: while(i!=0)
	goto	l8844
	
l8845:	
	line	709
;Function.c: 708: {
;Function.c: 709: ATCommand_RetryTimes=1;
	clrf	(_ATCommand_RetryTimes)
	incf	(_ATCommand_RetryTimes),f
	line	710
	
l33356:	
;Function.c: 710: if(ATCommand_SendCmd("AT\0")==ATACK_OK)
	movlw	low(STR_39|8000h)
	movwf	(?_ATCommand_SendCmd)
	movlw	high(STR_39|8000h)
	movwf	((?_ATCommand_SendCmd))+1
	fcall	_ATCommand_SendCmd
	xorlw	01h&0ffh
	skipz
	goto	u8731
	goto	u8730
u8731:
	goto	l33364
u8730:
	line	712
	
l33358:	
;Function.c: 711: {
;Function.c: 712: ErrState=MissAT;
	movlw	(03h)
	movwf	(_ErrState)
	line	713
	
l33360:	
;Function.c: 713: LATD5=0;
	movlb 2	; select bank2
	bcf	(2173/8)^0100h,(2173)&7
	line	714
;Function.c: 714: return 1;
	movlw	(01h)
	goto	l8843
	line	716
	
l33364:	
;Function.c: 715: }
;Function.c: 716: i--;
	decf	(PowerON@i),f
	line	717
	
l8844:	
	line	707
	movf	(PowerON@i),f
	skipz
	goto	u8741
	goto	u8740
u8741:
	goto	l8845
u8740:
	
l8847:	
	line	718
;Function.c: 717: }
;Function.c: 718: LATD5=0;
	movlb 2	; select bank2
	bcf	(2173/8)^0100h,(2173)&7
	line	719
	
l33366:	
;Function.c: 719: return 0;
	movlw	(0)
	line	735
	
l8843:	
	return
	opt stack 0
GLOBAL	__end_of_PowerON
	__end_of_PowerON:
;; =============== function _PowerON ends ============

	signat	_PowerON,89
	global	_DS18X20_ReadMeas
psect	text2013,local,class=CODE,delta=2
global __ptext2013
__ptext2013:

;; *************** function _DS18X20_ReadMeas *****************
;; Defined at:
;;		line 144 in file "F:\work\WYP\NBIoT\DS18x20.c"
;; Parameters:    Size  Location     Type
;;  bVerify         1    wreg     unsigned char 
;; Auto vars:     Size  Location     Type
;;  bVerify         1   10[BANK0 ] unsigned char 
;;  i               1   11[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;                  1    wreg      unsigned char 
;; Registers used:
;;		wreg, fsr1l, fsr1h, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 1F/0
;;		On exit  : 1E/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       0       0       0       0       0       0       0
;;      Locals:         0       2       0       0       0       0       0       0
;;      Temps:          0       0       0       0       0       0       0       0
;;      Totals:         0       2       0       0       0       0       0       0
;;Total ram usage:        2 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    5
;; This function calls:
;;		_OneWire_Reset
;;		_OneWire_Command
;;		_OneWire_ReadByte
;;		_GetVerify_CRC8
;; This function is called by:
;;		_ReadTData
;; This function uses a non-reentrant model
;;
psect	text2013
	file	"F:\work\WYP\NBIoT\DS18x20.c"
	line	144
	global	__size_of_DS18X20_ReadMeas
	__size_of_DS18X20_ReadMeas	equ	__end_of_DS18X20_ReadMeas-_DS18X20_ReadMeas
	
_DS18X20_ReadMeas:	
	opt	stack 12
; Regs used in _DS18X20_ReadMeas: [wreg+fsr1l-status,0+pclath+cstack]
;DS18X20_ReadMeas@bVerify stored from wreg
	line	146
	movwf	(DS18X20_ReadMeas@bVerify)
	
l33298:	
;DS18x20.c: 145: unsigned char i;
;DS18x20.c: 146: if(OneWire_Reset())
	fcall	_OneWire_Reset
	xorlw	0&0ffh
	skipnz
	goto	u8661
	goto	u8660
u8661:
	goto	l33304
u8660:
	line	147
	
l33300:	
;DS18x20.c: 147: return 0x01;
	movlw	(01h)
	goto	l17289
	line	148
	
l33304:	
;DS18x20.c: 148: if(OneWire_Command(0xBE))
	movlw	(0BEh)
	fcall	_OneWire_Command
	xorlw	0&0ffh
	skipnz
	goto	u8671
	goto	u8670
u8671:
	goto	l33310
u8670:
	goto	l33300
	line	150
	
l33310:	
;DS18x20.c: 150: if(bVerify)
	movf	(DS18X20_ReadMeas@bVerify),w
	skipz
	goto	u8680
	goto	l33336
u8680:
	line	152
	
l33312:	
;DS18x20.c: 151: {
;DS18x20.c: 152: for ( i=0 ; i< 9; i++ )
	clrf	(DS18X20_ReadMeas@i)
	line	153
	
l33318:	
;DS18x20.c: 153: DS18X20_Scratchpad[i]=OneWire_ReadByte();
	movf	(DS18X20_ReadMeas@i),w
	addlw	_DS18X20_Scratchpad&0ffh
	movwf	fsr1l
	clrf fsr1h	
	
	fcall	_OneWire_ReadByte
	movwf	indf1
	line	152
	
l33320:	
	incf	(DS18X20_ReadMeas@i),f
	
l33322:	
	movlw	(09h)
	subwf	(DS18X20_ReadMeas@i),w
	skipc
	goto	u8691
	goto	u8690
u8691:
	goto	l33318
u8690:
	line	154
	
l33324:	
;DS18x20.c: 154: if ( GetVerify_CRC8( DS18X20_Scratchpad, 9-1 )!=DS18X20_Scratchpad[9-1] )
	movlw	08h
	movwf	(?_GetVerify_CRC8)
	clrf	(?_GetVerify_CRC8+1)
	movlw	(_DS18X20_Scratchpad)&0ffh
	fcall	_GetVerify_CRC8
	movlb 1	; select bank1
	xorwf	0+(_DS18X20_Scratchpad)^080h+08h,w
	skipnz
	goto	u8701
	goto	u8700
u8701:
	goto	l33330
u8700:
	line	155
	
l33326:	
;DS18x20.c: 155: return 0x03;
	movlw	(03h)
	goto	l17289
	line	156
	
l33330:	
;DS18x20.c: 156: return 0x00;
	movlw	(0)
	goto	l17289
	line	160
	
l33336:	
;DS18x20.c: 158: else
;DS18x20.c: 159: {
;DS18x20.c: 160: DS18X20_Scratchpad[0]=OneWire_ReadByte();
	fcall	_OneWire_ReadByte
	movlb 1	; select bank1
	movwf	(_DS18X20_Scratchpad)^080h
	line	161
;DS18x20.c: 161: DS18X20_Scratchpad[1]=OneWire_ReadByte();
	fcall	_OneWire_ReadByte
	movlb 1	; select bank1
	movwf	0+(_DS18X20_Scratchpad)^080h+01h
	goto	l33330
	line	165
	
l17289:	
	return
	opt stack 0
GLOBAL	__end_of_DS18X20_ReadMeas
	__end_of_DS18X20_ReadMeas:
;; =============== function _DS18X20_ReadMeas ends ============

	signat	_DS18X20_ReadMeas,4217
	global	_DS18X20_StartMeas
psect	text2014,local,class=CODE,delta=2
global __ptext2014
__ptext2014:

;; *************** function _DS18X20_StartMeas *****************
;; Defined at:
;;		line 133 in file "F:\work\WYP\NBIoT\DS18x20.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  1    wreg      unsigned char 
;; Registers used:
;;		wreg, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 10/0
;;		On exit  : 1F/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       0       0       0       0       0       0       0
;;      Locals:         0       0       0       0       0       0       0       0
;;      Temps:          0       0       0       0       0       0       0       0
;;      Totals:         0       0       0       0       0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    5
;; This function calls:
;;		_OneWire_Reset
;;		_OneWire_Command
;; This function is called by:
;;		_ReadTData
;; This function uses a non-reentrant model
;;
psect	text2014
	file	"F:\work\WYP\NBIoT\DS18x20.c"
	line	133
	global	__size_of_DS18X20_StartMeas
	__size_of_DS18X20_StartMeas	equ	__end_of_DS18X20_StartMeas-_DS18X20_StartMeas
	
_DS18X20_StartMeas:	
	opt	stack 12
; Regs used in _DS18X20_StartMeas: [wreg+status,2+status,0+pclath+cstack]
	line	134
	
l33288:	
;DS18x20.c: 134: if(OneWire_Reset())
	fcall	_OneWire_Reset
	xorlw	0&0ffh
	skipnz
	goto	u8651
	goto	u8650
u8651:
	goto	l33294
u8650:
	line	135
	
l33290:	
;DS18x20.c: 135: return 0x01;
	movlw	(01h)
	goto	l17285
	line	136
	
l33294:	
;DS18x20.c: 136: return OneWire_Command( 0x44);
	movlw	(044h)
	fcall	_OneWire_Command
	line	137
	
l17285:	
	return
	opt stack 0
GLOBAL	__end_of_DS18X20_StartMeas
	__end_of_DS18X20_StartMeas:
;; =============== function _DS18X20_StartMeas ends ============

	signat	_DS18X20_StartMeas,89
	global	_OneWire_Command
psect	text2015,local,class=CODE,delta=2
global __ptext2015
__ptext2015:

;; *************** function _OneWire_Command *****************
;; Defined at:
;;		line 126 in file "F:\work\WYP\NBIoT\OneWire.c"
;; Parameters:    Size  Location     Type
;;  command         1    wreg     unsigned char 
;; Auto vars:     Size  Location     Type
;;  command         1    4[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;                  1    wreg      unsigned char 
;; Registers used:
;;		wreg, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 1F/0
;;		On exit  : 1F/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       0       0       0       0       0       0       0
;;      Locals:         0       1       0       0       0       0       0       0
;;      Temps:          0       0       0       0       0       0       0       0
;;      Totals:         0       1       0       0       0       0       0       0
;;Total ram usage:        1 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    4
;; This function calls:
;;		_OneWire_Reset
;;		_OneWire_WriteByte
;; This function is called by:
;;		_DS18X20_StartMeas
;;		_DS18X20_ReadMeas
;; This function uses a non-reentrant model
;;
psect	text2015
	file	"F:\work\WYP\NBIoT\OneWire.c"
	line	126
	global	__size_of_OneWire_Command
	__size_of_OneWire_Command	equ	__end_of_OneWire_Command-_OneWire_Command
	
_OneWire_Command:	
	opt	stack 11
; Regs used in _OneWire_Command: [wreg+status,2+status,0+pclath+cstack]
;OneWire_Command@command stored from wreg
	movwf	(OneWire_Command@command)
	line	127
	
l33276:	
;OneWire.c: 127: if(OneWire_Reset())
	fcall	_OneWire_Reset
	xorlw	0&0ffh
	skipnz
	goto	u8641
	goto	u8640
u8641:
	goto	l33282
u8640:
	line	128
	
l33278:	
;OneWire.c: 128: return 0x01;
	movlw	(01h)
	goto	l19357
	line	129
	
l33282:	
;OneWire.c: 129: OneWire_WriteByte( 0xCC );
	movlw	(0CCh)
	fcall	_OneWire_WriteByte
	line	130
;OneWire.c: 130: OneWire_WriteByte( command );
	movf	(OneWire_Command@command),w
	fcall	_OneWire_WriteByte
	line	131
	
l33284:	
;OneWire.c: 131: return 0x00;
	movlw	(0)
	line	132
	
l19357:	
	return
	opt stack 0
GLOBAL	__end_of_OneWire_Command
	__end_of_OneWire_Command:
;; =============== function _OneWire_Command ends ============

	signat	_OneWire_Command,4217
	global	_ATCommand_WaitData
psect	text2016,local,class=CODE,delta=2
global __ptext2016
__ptext2016:

;; *************** function _ATCommand_WaitData *****************
;; Defined at:
;;		line 125 in file "F:\work\WYP\NBIoT\ATCommand.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;  strx            2   20[BANK0 ] PTR unsigned char 
;;		 -> ATCommand_RxList(100), RAM(128), 
;;  res             1   19[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;                  1    wreg      unsigned char 
;; Registers used:
;;		wreg, fsr0l, fsr0h, fsr1l, fsr1h, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 1F/0
;;		On exit  : 1F/0
;;		Unchanged: FFFE0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       0       0       0       0       0       0       0
;;      Locals:         0       3       0       0       0       0       0       0
;;      Temps:          0       2       0       0       0       0       0       0
;;      Totals:         0       5       0       0       0       0       0       0
;;Total ram usage:        5 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    5
;; This function calls:
;;		_strstr
;;		_strcpy
;; This function is called by:
;;		_InteractServer
;; This function uses a non-reentrant model
;;
psect	text2016
	file	"F:\work\WYP\NBIoT\ATCommand.c"
	line	125
	global	__size_of_ATCommand_WaitData
	__size_of_ATCommand_WaitData	equ	__end_of_ATCommand_WaitData-_ATCommand_WaitData
	
_ATCommand_WaitData:	
	opt	stack 10
; Regs used in _ATCommand_WaitData: [wreg-status,0+pclath+cstack]
	line	126
	
l33232:	
;ATCommand.c: 126: unsigned char res=0;
	clrf	(ATCommand_WaitData@res)
	line	128
;ATCommand.c: 128: res=ATACK_Null;
	clrf	(ATCommand_WaitData@res)
	line	129
	
l33234:	
;ATCommand.c: 129: ATCommand_Flags.bRx=0;
	bcf	(_ATCommand_Flags),1
	line	130
	
l33236:	
;ATCommand.c: 130: ATCommand_Flags.bChar=0;
	bcf	(_ATCommand_Flags),0
	line	131
	
l33238:	
;ATCommand.c: 131: ATCommand_WaitACKTick=SystemTick;
	movf	(_SystemTick+1),w
	movwf	(_ATCommand_WaitACKTick+1)
	movf	(_SystemTick),w
	movwf	(_ATCommand_WaitACKTick)
	line	132
	
l33240:	
;ATCommand.c: 132: ATCommand_RxCount=0;
	clrf	(_ATCommand_RxCount)
	line	133
	
l33242:	
;ATCommand.c: 133: ATCommand_Flags.bWaitData=1;
	bsf	(_ATCommand_Flags),2
	line	134
	
l33244:	
;ATCommand.c: 134: ATCommand_RxList[ATCommand_RxCount]='\0';
	movf	(_ATCommand_RxCount),w
	addlw	low 8588
	movwf	fsr1l
	movlw	high 8588
	skipnc
	movlw	high (8588)+1
	movwf	(fsr1l)+1
	clrf	indf1
	line	137
	
l33246:	
;ATCommand.c: 136: {
;ATCommand.c: 137: strx=strstr((const char*)ATCommand_RxList,ATCommand_OkString);
	movlw	low(8588)
	movwf	(?_strstr)
	movlw	high(8588)
	movwf	((?_strstr))+1
	movlw	(_ATCommand_OkString&0ffh)
	movwf	(0+?_strstr+02h)
	movlw	0x1/2
	movwf	(1+?_strstr+02h)
	fcall	_strstr
	movf	(1+(?_strstr)),w
	movwf	(ATCommand_WaitData@strx+1)
	movf	(0+(?_strstr)),w
	movwf	(ATCommand_WaitData@strx)
	line	138
	
l33248:	
;ATCommand.c: 138: if(strx!=0)
	movf	(ATCommand_WaitData@strx+1),w
	iorwf	(ATCommand_WaitData@strx),w
	skipnz
	goto	u8611
	goto	u8610
u8611:
	goto	l33254
u8610:
	line	140
	
l33250:	
;ATCommand.c: 139: {
;ATCommand.c: 140: res=ATACK_OK;
	clrf	(ATCommand_WaitData@res)
	incf	(ATCommand_WaitData@res),f
	line	141
;ATCommand.c: 141: ATCommand_Flags.bRx=1;
	bsf	(_ATCommand_Flags),1
	line	142
;ATCommand.c: 142: break;
	goto	l15219
	line	146
	
l33254:	
;ATCommand.c: 144: else
;ATCommand.c: 145: {
;ATCommand.c: 146: strx=strstr((const char*)ATCommand_RxList,ATCommand_ErrString);
	movlw	low(8588)
	movwf	(?_strstr)
	movlw	high(8588)
	movwf	((?_strstr))+1
	movlw	(_ATCommand_ErrString&0ffh)
	movwf	(0+?_strstr+02h)
	movlw	0x1/2
	movwf	(1+?_strstr+02h)
	fcall	_strstr
	movf	(1+(?_strstr)),w
	movwf	(ATCommand_WaitData@strx+1)
	movf	(0+(?_strstr)),w
	movwf	(ATCommand_WaitData@strx)
	line	147
	
l33256:	
;ATCommand.c: 147: if(strx!=0)
	movf	(ATCommand_WaitData@strx+1),w
	iorwf	(ATCommand_WaitData@strx),w
	skipnz
	goto	u8621
	goto	u8620
u8621:
	goto	l33262
u8620:
	line	149
	
l33258:	
;ATCommand.c: 148: {
;ATCommand.c: 149: res=ATACK_Err;
	movlw	(02h)
	movwf	(ATCommand_WaitData@res)
	line	150
	
l33260:	
;ATCommand.c: 150: ATCommand_Flags.bRx=1;
	bsf	(_ATCommand_Flags),1
	line	151
;ATCommand.c: 151: break;
	goto	l15219
	line	154
	
l33262:	
;ATCommand.c: 152: }
;ATCommand.c: 153: }
;ATCommand.c: 154: if((SystemTick-ATCommand_WaitACKTick)>ATCommand_WaitACKTimes)
	movf	(_ATCommand_WaitACKTick),w
	subwf	(_SystemTick),w
	movwf	(??_ATCommand_WaitData+0)+0
	movf	(_ATCommand_WaitACKTick+1),w
	subwfb	(_SystemTick+1),w
	movwf	1+(??_ATCommand_WaitData+0)+0
	movf	1+(??_ATCommand_WaitData+0)+0,w
	subwf	(_ATCommand_WaitACKTimes+1),w
	skipz
	goto	u8635
	movf	0+(??_ATCommand_WaitData+0)+0,w
	subwf	(_ATCommand_WaitACKTimes),w
u8635:
	skipnc
	goto	u8631
	goto	u8630
u8631:
	goto	l33246
u8630:
	line	135
	
l15219:	
	line	157
;ATCommand.c: 156: }
;ATCommand.c: 157: ATCommand_Flags.bWaitData=0;
	bcf	(_ATCommand_Flags),2
	line	158
	
l33266:	
;ATCommand.c: 158: strcpy(ATCommand_OkString,"OK");
	movlw	low(STR_52|8000h)
	movwf	(?_strcpy)
	movlw	high(STR_52|8000h)
	movwf	((?_strcpy))+1
	movlw	(_ATCommand_OkString)&0ffh
	fcall	_strcpy
	line	159
;ATCommand.c: 159: strcpy(ATCommand_ErrString,"ERROR");
	movlw	low(STR_53|8000h)
	movwf	(?_strcpy)
	movlw	high(STR_53|8000h)
	movwf	((?_strcpy))+1
	movlw	(_ATCommand_ErrString)&0ffh
	fcall	_strcpy
	line	160
	
l33268:	
;ATCommand.c: 160: ATCommand_Clear='\0';
	clrf	(_ATCommand_Clear)
	line	162
	
l33270:	
;ATCommand.c: 162: ATCommand_WaitACKTimes=50;
	movlw	032h
	movwf	(_ATCommand_WaitACKTimes)
	clrf	(_ATCommand_WaitACKTimes+1)
	line	163
	
l33272:	
;ATCommand.c: 163: return res;
	movf	(ATCommand_WaitData@res),w
	line	164
	
l15224:	
	return
	opt stack 0
GLOBAL	__end_of_ATCommand_WaitData
	__end_of_ATCommand_WaitData:
;; =============== function _ATCommand_WaitData ends ============

	signat	_ATCommand_WaitData,89
	global	_ATCommand_SendCmd
psect	text2017,local,class=CODE,delta=2
global __ptext2017
__ptext2017:

;; *************** function _ATCommand_SendCmd *****************
;; Defined at:
;;		line 71 in file "F:\work\WYP\NBIoT\ATCommand.c"
;; Parameters:    Size  Location     Type
;;  cmd             2   17[BANK0 ] PTR const unsigned char 
;;		 -> STR_46(12), STR_45(15), STR_43(15), STR_42(45), 
;;		 -> STR_40(14), STR_39(4), STR_38(10), STR_37(10), 
;;		 -> STR_36(23), STR_35(33), STR_34(11), STR_31(11), 
;;		 -> STR_29(8), STR_28(11), STR_27(13), STR_25(10), 
;;		 -> STR_24(9), STR_23(6), STR_22(5), STR_21(4), 
;;		 -> STR_9(12), STR_7(12), STR_6(15), STR_4(15), 
;;		 -> STR_3(45), STR_1(14), 
;; Auto vars:     Size  Location     Type
;;  strx            2   22[BANK0 ] PTR unsigned char 
;;		 -> ATCommand_RxList(100), RAM(128), 
;;  res             1   24[BANK0 ] unsigned char 
;;  retry           1   21[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;                  1    wreg      unsigned char 
;; Registers used:
;;		wreg, fsr0l, fsr0h, fsr1l, fsr1h, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 1F/0
;;		On exit  : 1F/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       2       0       0       0       0       0       0
;;      Locals:         0       4       0       0       0       0       0       0
;;      Temps:          0       2       0       0       0       0       0       0
;;      Totals:         0       8       0       0       0       0       0       0
;;Total ram usage:        8 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    5
;; This function calls:
;;		_Uart1_PutString
;;		_strstr
;;		___delay_20ms
;;		_strcpy
;; This function is called by:
;;		_CallSend
;;		_InteractServer
;;		_InitGPRS
;;		_PowerON
;;		_CallTestSend
;; This function uses a non-reentrant model
;;
psect	text2017
	file	"F:\work\WYP\NBIoT\ATCommand.c"
	line	71
	global	__size_of_ATCommand_SendCmd
	__size_of_ATCommand_SendCmd	equ	__end_of_ATCommand_SendCmd-_ATCommand_SendCmd
	
_ATCommand_SendCmd:	
	opt	stack 10
; Regs used in _ATCommand_SendCmd: [wreg-status,0+pclath+cstack]
	line	72
	
l33172:	
	line	74
;ATCommand.c: 73: unsigned char retry;
;ATCommand.c: 74: char *strx=0;
	clrf	(ATCommand_SendCmd@strx)
	clrf	(ATCommand_SendCmd@strx+1)
	line	76
	
l33174:	
;ATCommand.c: 76: retry=ATCommand_RetryTimes;
	movf	(_ATCommand_RetryTimes),w
	movwf	(ATCommand_SendCmd@retry)
	line	77
	
l33176:	
;ATCommand.c: 77: res=ATACK_Null;
	clrf	(ATCommand_SendCmd@res)
	line	78
;ATCommand.c: 78: while(retry!=0)
	goto	l33218
	line	80
	
l33178:	
;ATCommand.c: 79: {
;ATCommand.c: 80: Uart1_PutString(cmd);
	movf	(ATCommand_SendCmd@cmd+1),w
	movwf	(?_Uart1_PutString+1)
	movf	(ATCommand_SendCmd@cmd),w
	movwf	(?_Uart1_PutString)
	fcall	_Uart1_PutString
	line	81
;ATCommand.c: 81: Uart1_PutString("\r\0");
	movlw	low(STR_49|8000h)
	movwf	(?_Uart1_PutString)
	movlw	high(STR_49|8000h)
	movwf	((?_Uart1_PutString))+1
	fcall	_Uart1_PutString
	line	82
	
l33180:	
;ATCommand.c: 82: ATCommand_Flags.bRx=0;
	bcf	(_ATCommand_Flags),1
	line	83
	
l33182:	
;ATCommand.c: 83: ATCommand_Flags.bChar=0;
	bcf	(_ATCommand_Flags),0
	line	84
	
l33184:	
;ATCommand.c: 84: ATCommand_WaitACKTick=SystemTick;
	movf	(_SystemTick+1),w
	movwf	(_ATCommand_WaitACKTick+1)
	movf	(_SystemTick),w
	movwf	(_ATCommand_WaitACKTick)
	line	85
	
l33186:	
;ATCommand.c: 85: ATCommand_RxCount=0;
	clrf	(_ATCommand_RxCount)
	line	86
	
l33188:	
;ATCommand.c: 86: ATCommand_Flags.bWaitData=1;
	bsf	(_ATCommand_Flags),2
	line	87
	
l33190:	
;ATCommand.c: 87: ATCommand_RxList[ATCommand_RxCount]='\0';
	movf	(_ATCommand_RxCount),w
	addlw	low 8588
	movwf	fsr1l
	movlw	high 8588
	skipnc
	movlw	high (8588)+1
	movwf	(fsr1l)+1
	clrf	indf1
	line	88
;ATCommand.c: 88: while(1)
	
l15205:	
	line	90
;ATCommand.c: 89: {
;ATCommand.c: 90: strx=strstr((const char*)ATCommand_RxList,ATCommand_OkString);
	movlw	low(8588)
	movwf	(?_strstr)
	movlw	high(8588)
	movwf	((?_strstr))+1
	movlw	(_ATCommand_OkString&0ffh)
	movwf	(0+?_strstr+02h)
	movlw	0x1/2
	movwf	(1+?_strstr+02h)
	fcall	_strstr
	movf	(1+(?_strstr)),w
	movwf	(ATCommand_SendCmd@strx+1)
	movf	(0+(?_strstr)),w
	movwf	(ATCommand_SendCmd@strx)
	line	91
	
l33192:	
;ATCommand.c: 91: if(strx!=0)
	movf	(ATCommand_SendCmd@strx+1),w
	iorwf	(ATCommand_SendCmd@strx),w
	skipnz
	goto	u8561
	goto	u8560
u8561:
	goto	l33198
u8560:
	line	93
	
l33194:	
;ATCommand.c: 92: {
;ATCommand.c: 93: res=ATACK_OK;
	clrf	(ATCommand_SendCmd@res)
	incf	(ATCommand_SendCmd@res),f
	line	94
;ATCommand.c: 94: ATCommand_Flags.bRx=1;
	bsf	(_ATCommand_Flags),1
	line	95
;ATCommand.c: 95: break;
	goto	l15207
	line	99
	
l33198:	
;ATCommand.c: 97: else
;ATCommand.c: 98: {
;ATCommand.c: 99: strx=strstr((const char*)ATCommand_RxList,ATCommand_ErrString);
	movlw	low(8588)
	movwf	(?_strstr)
	movlw	high(8588)
	movwf	((?_strstr))+1
	movlw	(_ATCommand_ErrString&0ffh)
	movwf	(0+?_strstr+02h)
	movlw	0x1/2
	movwf	(1+?_strstr+02h)
	fcall	_strstr
	movf	(1+(?_strstr)),w
	movwf	(ATCommand_SendCmd@strx+1)
	movf	(0+(?_strstr)),w
	movwf	(ATCommand_SendCmd@strx)
	line	100
	
l33200:	
;ATCommand.c: 100: if(strx!=0)
	movf	(ATCommand_SendCmd@strx+1),w
	iorwf	(ATCommand_SendCmd@strx),w
	skipnz
	goto	u8571
	goto	u8570
u8571:
	goto	l33206
u8570:
	line	102
	
l33202:	
;ATCommand.c: 101: {
;ATCommand.c: 102: res=ATACK_Err;
	movlw	(02h)
	movwf	(ATCommand_SendCmd@res)
	line	103
	
l33204:	
;ATCommand.c: 103: ATCommand_Flags.bRx=1;
	bsf	(_ATCommand_Flags),1
	line	104
;ATCommand.c: 104: break;
	goto	l15207
	line	107
	
l33206:	
;ATCommand.c: 105: }
;ATCommand.c: 106: }
;ATCommand.c: 107: if((SystemTick-ATCommand_WaitACKTick)>ATCommand_WaitACKTimes)
	movf	(_ATCommand_WaitACKTick),w
	subwf	(_SystemTick),w
	movwf	(??_ATCommand_SendCmd+0)+0
	movf	(_ATCommand_WaitACKTick+1),w
	subwfb	(_SystemTick+1),w
	movwf	1+(??_ATCommand_SendCmd+0)+0
	movf	1+(??_ATCommand_SendCmd+0)+0,w
	subwf	(_ATCommand_WaitACKTimes+1),w
	skipz
	goto	u8585
	movf	0+(??_ATCommand_SendCmd+0)+0,w
	subwf	(_ATCommand_WaitACKTimes),w
u8585:
	skipnc
	goto	u8581
	goto	u8580
u8581:
	goto	l15205
u8580:
	line	88
	
l15207:	
	line	110
;ATCommand.c: 109: }
;ATCommand.c: 110: ATCommand_Flags.bWaitData=0;
	bcf	(_ATCommand_Flags),2
	line	111
	
l33210:	
;ATCommand.c: 111: if(res==ATACK_OK)
	decf	(ATCommand_SendCmd@res),w
	skipz
	goto	u8591
	goto	u8590
u8591:
	goto	l33214
u8590:
	goto	l33220
	line	113
	
l33214:	
;ATCommand.c: 113: __delay_20ms(100);;
	movlw	064h
	movwf	(?___delay_20ms)
	clrf	(?___delay_20ms+1)
	fcall	___delay_20ms
	line	114
	
l33216:	
;ATCommand.c: 114: retry--;
	decf	(ATCommand_SendCmd@retry),f
	line	78
	
l33218:	
	movf	(ATCommand_SendCmd@retry),f
	skipz
	goto	u8601
	goto	u8600
u8601:
	goto	l33178
u8600:
	line	116
	
l33220:	
;ATCommand.c: 115: }
;ATCommand.c: 116: strcpy(ATCommand_OkString,"OK");
	movlw	low(STR_50|8000h)
	movwf	(?_strcpy)
	movlw	high(STR_50|8000h)
	movwf	((?_strcpy))+1
	movlw	(_ATCommand_OkString)&0ffh
	fcall	_strcpy
	line	117
;ATCommand.c: 117: strcpy(ATCommand_ErrString,"ERROR");
	movlw	low(STR_51|8000h)
	movwf	(?_strcpy)
	movlw	high(STR_51|8000h)
	movwf	((?_strcpy))+1
	movlw	(_ATCommand_ErrString)&0ffh
	fcall	_strcpy
	line	118
	
l33222:	
;ATCommand.c: 118: ATCommand_Clear='\0';
	clrf	(_ATCommand_Clear)
	line	120
	
l33224:	
;ATCommand.c: 120: ATCommand_RetryTimes=3;
	movlw	(03h)
	movwf	(_ATCommand_RetryTimes)
	line	121
	
l33226:	
;ATCommand.c: 121: ATCommand_WaitACKTimes=50;
	movlw	032h
	movwf	(_ATCommand_WaitACKTimes)
	clrf	(_ATCommand_WaitACKTimes+1)
	line	122
	
l33228:	
;ATCommand.c: 122: return res;
	movf	(ATCommand_SendCmd@res),w
	line	123
	
l15214:	
	return
	opt stack 0
GLOBAL	__end_of_ATCommand_SendCmd
	__end_of_ATCommand_SendCmd:
;; =============== function _ATCommand_SendCmd ends ============

	signat	_ATCommand_SendCmd,4217
	global	_PowerDown
psect	text2018,local,class=CODE,delta=2
global __ptext2018
__ptext2018:

;; *************** function _PowerDown *****************
;; Defined at:
;;		line 673 in file "F:\work\WYP\NBIoT\Function.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;  i               1    4[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;                  1    wreg      unsigned char 
;; Registers used:
;;		wreg, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 1F/0
;;		On exit  : 1F/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       0       0       0       0       0       0       0
;;      Locals:         0       1       0       0       0       0       0       0
;;      Temps:          0       0       0       0       0       0       0       0
;;      Totals:         0       1       0       0       0       0       0       0
;;Total ram usage:        1 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    4
;; This function calls:
;;		___delay_20ms
;; This function is called by:
;;		_CallProc
;;		_PowerON
;;		_CallTestProc
;; This function uses a non-reentrant model
;;
psect	text2018
	file	"F:\work\WYP\NBIoT\Function.c"
	line	673
	global	__size_of_PowerDown
	__size_of_PowerDown	equ	__end_of_PowerDown-_PowerDown
	
_PowerDown:	
	opt	stack 12
; Regs used in _PowerDown: [wreg+status,2+status,0+pclath+cstack]
	line	675
	
l33144:	
;Function.c: 674: unsigned char i;
;Function.c: 675: if(RD4==0)
	btfsc	(124/8),(124)&7
	goto	u8521
	goto	u8520
u8521:
	goto	l33162
u8520:
	line	677
	
l33146:	
;Function.c: 676: {
;Function.c: 677: LATD5=1;
	movlb 2	; select bank2
	bsf	(2173/8)^0100h,(2173)&7
	line	678
	
l33148:	
;Function.c: 678: __delay_20ms(70);
	movlw	046h
	movlb 0	; select bank0
	movwf	(?___delay_20ms)
	clrf	(?___delay_20ms+1)
	fcall	___delay_20ms
	line	679
	
l33150:	
;Function.c: 679: LATD5=0;
	movlb 2	; select bank2
	bcf	(2173/8)^0100h,(2173)&7
	line	680
	
l33152:	
;Function.c: 680: i=15;
	movlw	(0Fh)
	movlb 0	; select bank0
	movwf	(PowerDown@i)
	line	681
;Function.c: 681: while(i!=0)
	goto	l8833
	line	683
	
l33154:	
;Function.c: 682: {
;Function.c: 683: __delay_20ms(50);
	movlw	032h
	movwf	(?___delay_20ms)
	clrf	(?___delay_20ms+1)
	fcall	___delay_20ms
	line	684
	
l33156:	
;Function.c: 684: if(RD4==1)
	btfss	(124/8),(124)&7
	goto	u8531
	goto	u8530
u8531:
	goto	l33160
u8530:
	goto	l33162
	line	686
	
l33160:	
;Function.c: 686: i--;
	decf	(PowerDown@i),f
	line	687
	
l8833:	
	line	681
	movf	(PowerDown@i),f
	skipz
	goto	u8541
	goto	u8540
u8541:
	goto	l33154
u8540:
	line	689
	
l33162:	
;Function.c: 687: }
;Function.c: 688: }
;Function.c: 689: if(i==0)
	movf	(PowerDown@i),f
	skipz
	goto	u8551
	goto	u8550
u8551:
	goto	l33168
u8550:
	line	690
	
l33164:	
;Function.c: 690: return 0;
	movlw	(0)
	goto	l8838
	line	691
	
l33168:	
;Function.c: 691: return 1;
	movlw	(01h)
	line	692
	
l8838:	
	return
	opt stack 0
GLOBAL	__end_of_PowerDown
	__end_of_PowerDown:
;; =============== function _PowerDown ends ============

	signat	_PowerDown,89
	global	_TCN75_ReadReg
psect	text2019,local,class=CODE,delta=2
global __ptext2019
__ptext2019:

;; *************** function _TCN75_ReadReg *****************
;; Defined at:
;;		line 20 in file "F:\work\WYP\NBIoT\TCN75.c"
;; Parameters:    Size  Location     Type
;;  RegPoint        1    wreg     unsigned char 
;; Auto vars:     Size  Location     Type
;;  RegPoint        1    3[BANK0 ] unsigned char 
;;  bRight          1    5[BANK0 ] unsigned char 
;;  ErrTimes        1    4[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;                  1    wreg      unsigned char 
;; Registers used:
;;		wreg, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 1F/0
;;		On exit  : 1F/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       0       0       0       0       0       0       0
;;      Locals:         0       3       0       0       0       0       0       0
;;      Temps:          0       0       0       0       0       0       0       0
;;      Totals:         0       3       0       0       0       0       0       0
;;Total ram usage:        3 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    4
;; This function calls:
;;		_SimI2C_Start
;;		_SimI2C_SendByte
;;		_SimI2C_RecAck
;;		_SimI2C_ReadByte
;;		_SimI2C_Ack
;;		_SimI2C_NoAck
;;		_SimI2C_Stop
;; This function is called by:
;;		_ReadTData
;; This function uses a non-reentrant model
;;
psect	text2019
	file	"F:\work\WYP\NBIoT\TCN75.c"
	line	20
	global	__size_of_TCN75_ReadReg
	__size_of_TCN75_ReadReg	equ	__end_of_TCN75_ReadReg-_TCN75_ReadReg
	
_TCN75_ReadReg:	
	opt	stack 12
; Regs used in _TCN75_ReadReg: [wreg+status,2+status,0+pclath+cstack]
;TCN75_ReadReg@RegPoint stored from wreg
	movwf	(TCN75_ReadReg@RegPoint)
	line	21
	
l33102:	
;TCN75.c: 21: unsigned char ErrTimes=2;
	movlw	(02h)
	movwf	(TCN75_ReadReg@ErrTimes)
	line	22
	
l33104:	
;TCN75.c: 22: unsigned char bRight=0;
	clrf	(TCN75_ReadReg@bRight)
	line	23
;TCN75.c: 23: while(ErrTimes--)
	goto	l33136
	line	25
	
l33106:	
;TCN75.c: 24: {
;TCN75.c: 25: SimI2C_Start();
	fcall	_SimI2C_Start
	line	26
	
l33108:	
;TCN75.c: 26: SimI2C_SendByte(0b10010000&0xfe);
	movlw	(090h)
	fcall	_SimI2C_SendByte
	line	27
	
l33110:	
;TCN75.c: 27: if(SimI2C_RecAck())
	fcall	_SimI2C_RecAck
	xorlw	0&0ffh
	skipnz
	goto	u8481
	goto	u8480
u8481:
	goto	l33114
u8480:
	goto	l33136
	line	29
	
l33114:	
;TCN75.c: 29: SimI2C_SendByte(RegPoint);
	movf	(TCN75_ReadReg@RegPoint),w
	fcall	_SimI2C_SendByte
	line	30
	
l33116:	
;TCN75.c: 30: if(SimI2C_RecAck())
	fcall	_SimI2C_RecAck
	xorlw	0&0ffh
	skipnz
	goto	u8491
	goto	u8490
u8491:
	goto	l33120
u8490:
	goto	l33136
	line	32
	
l33120:	
;TCN75.c: 32: SimI2C_Start();
	fcall	_SimI2C_Start
	line	33
	
l33122:	
;TCN75.c: 33: SimI2C_SendByte(0b10010000|0x01);
	movlw	(091h)
	fcall	_SimI2C_SendByte
	line	34
	
l33124:	
;TCN75.c: 34: if(SimI2C_RecAck())
	fcall	_SimI2C_RecAck
	xorlw	0&0ffh
	skipnz
	goto	u8501
	goto	u8500
u8501:
	goto	l33128
u8500:
	goto	l33136
	line	36
	
l33128:	
;TCN75.c: 36: TCN75_RegReadResualt.u8H=SimI2C_ReadByte();
	fcall	_SimI2C_ReadByte
	movwf	0+(_TCN75_RegReadResualt)+01h
	line	37
	
l33130:	
;TCN75.c: 37: SimI2C_Ack();
	fcall	_SimI2C_Ack
	line	38
	
l33132:	
;TCN75.c: 38: TCN75_RegReadResualt.u8L=SimI2C_ReadByte();
	fcall	_SimI2C_ReadByte
	movwf	(_TCN75_RegReadResualt)
	line	39
;TCN75.c: 39: SimI2C_NoAck();
	fcall	_SimI2C_NoAck
	line	40
	
l33134:	
;TCN75.c: 40: bRight=1;
	movlb 0	; select bank0
	clrf	(TCN75_ReadReg@bRight)
	incf	(TCN75_ReadReg@bRight),f
	line	41
;TCN75.c: 41: break;
	goto	l33138
	line	23
	
l33136:	
	decf	(TCN75_ReadReg@ErrTimes),f
	movf	((TCN75_ReadReg@ErrTimes)),w
	xorlw	0FFh&0ffh
	skipz
	goto	u8511
	goto	u8510
u8511:
	goto	l33106
u8510:
	line	43
	
l33138:	
;TCN75.c: 42: }
;TCN75.c: 43: SimI2C_Stop();
	fcall	_SimI2C_Stop
	line	44
	
l33140:	
;TCN75.c: 44: return bRight;
	movlb 0	; select bank0
	movf	(TCN75_ReadReg@bRight),w
	line	45
	
l21448:	
	return
	opt stack 0
GLOBAL	__end_of_TCN75_ReadReg
	__end_of_TCN75_ReadReg:
;; =============== function _TCN75_ReadReg ends ============

	signat	_TCN75_ReadReg,4217
	global	_TCN75_SetConfig
psect	text2020,local,class=CODE,delta=2
global __ptext2020
__ptext2020:

;; *************** function _TCN75_SetConfig *****************
;; Defined at:
;;		line 47 in file "F:\work\WYP\NBIoT\TCN75.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;  bRight          1    4[BANK0 ] unsigned char 
;;  ErrTimes        1    3[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;                  1    wreg      unsigned char 
;; Registers used:
;;		wreg, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 1F/0
;;		On exit  : 1F/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       0       0       0       0       0       0       0
;;      Locals:         0       2       0       0       0       0       0       0
;;      Temps:          0       0       0       0       0       0       0       0
;;      Totals:         0       2       0       0       0       0       0       0
;;Total ram usage:        2 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    4
;; This function calls:
;;		_SimI2C_Start
;;		_SimI2C_SendByte
;;		_SimI2C_RecAck
;;		_SimI2C_Stop
;; This function is called by:
;;		_InitSystem
;;		_ReadTData
;; This function uses a non-reentrant model
;;
psect	text2020
	file	"F:\work\WYP\NBIoT\TCN75.c"
	line	47
	global	__size_of_TCN75_SetConfig
	__size_of_TCN75_SetConfig	equ	__end_of_TCN75_SetConfig-_TCN75_SetConfig
	
_TCN75_SetConfig:	
	opt	stack 12
; Regs used in _TCN75_SetConfig: [wreg+status,2+status,0+pclath+cstack]
	line	48
	
l33070:	
;TCN75.c: 48: unsigned char ErrTimes=2;
	movlw	(02h)
	movwf	(TCN75_SetConfig@ErrTimes)
	line	49
	
l33072:	
;TCN75.c: 49: unsigned char bRight=0;
	clrf	(TCN75_SetConfig@bRight)
	line	50
;TCN75.c: 50: while(ErrTimes--)
	goto	l33094
	line	52
	
l33074:	
;TCN75.c: 51: {
;TCN75.c: 52: SimI2C_Start();
	fcall	_SimI2C_Start
	line	53
	
l33076:	
;TCN75.c: 53: SimI2C_SendByte(0b10010000&0xfe);
	movlw	(090h)
	fcall	_SimI2C_SendByte
	line	54
	
l33078:	
;TCN75.c: 54: if(SimI2C_RecAck())
	fcall	_SimI2C_RecAck
	xorlw	0&0ffh
	skipnz
	goto	u8441
	goto	u8440
u8441:
	goto	l33082
u8440:
	goto	l33094
	line	56
	
l33082:	
;TCN75.c: 56: SimI2C_SendByte(0x01);
	movlw	(01h)
	fcall	_SimI2C_SendByte
	line	57
	
l33084:	
;TCN75.c: 57: if(SimI2C_RecAck())
	fcall	_SimI2C_RecAck
	xorlw	0&0ffh
	skipnz
	goto	u8451
	goto	u8450
u8451:
	goto	l33088
u8450:
	goto	l33094
	line	59
	
l33088:	
;TCN75.c: 59: SimI2C_SendByte(TCN75_Config.AllFlag);
	movf	(_TCN75_Config),w
	fcall	_SimI2C_SendByte
	line	60
	
l33090:	
;TCN75.c: 60: if(SimI2C_RecAck())
	fcall	_SimI2C_RecAck
	xorlw	0&0ffh
	skipnz
	goto	u8461
	goto	u8460
u8461:
	goto	l21455
u8460:
	goto	l33094
	line	61
	
l21455:	
	line	62
;TCN75.c: 62: bRight=1;
	clrf	(TCN75_SetConfig@bRight)
	incf	(TCN75_SetConfig@bRight),f
	line	63
;TCN75.c: 63: break;
	goto	l33096
	line	50
	
l33094:	
	decf	(TCN75_SetConfig@ErrTimes),f
	movf	((TCN75_SetConfig@ErrTimes)),w
	xorlw	0FFh&0ffh
	skipz
	goto	u8471
	goto	u8470
u8471:
	goto	l33074
u8470:
	line	65
	
l33096:	
;TCN75.c: 64: }
;TCN75.c: 65: SimI2C_Stop();
	fcall	_SimI2C_Stop
	line	66
	
l33098:	
;TCN75.c: 66: return bRight;
	movlb 0	; select bank0
	movf	(TCN75_SetConfig@bRight),w
	line	67
	
l21457:	
	return
	opt stack 0
GLOBAL	__end_of_TCN75_SetConfig
	__end_of_TCN75_SetConfig:
;; =============== function _TCN75_SetConfig ends ============

	signat	_TCN75_SetConfig,89
	global	_InitVariable
psect	text2021,local,class=CODE,delta=2
global __ptext2021
__ptext2021:

;; *************** function _InitVariable *****************
;; Defined at:
;;		line 60 in file "F:\work\WYP\NBIoT\Init.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, fsr1l, fsr1h, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 17F/0
;;		On exit  : 17F/0
;;		Unchanged: FFE80/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       0       0       0       0       0       0       0
;;      Locals:         0       0       0       0       0       0       0       0
;;      Temps:          0       0       0       0       0       0       0       0
;;      Totals:         0       0       0       0       0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    5
;; This function calls:
;;		_GetRomData
;;		_SaveRomData
;; This function is called by:
;;		_InitSystem
;; This function uses a non-reentrant model
;;
psect	text2021
	file	"F:\work\WYP\NBIoT\Init.c"
	line	60
	global	__size_of_InitVariable
	__size_of_InitVariable	equ	__end_of_InitVariable-_InitVariable
	
_InitVariable:	
	opt	stack 12
; Regs used in _InitVariable: [wreg+fsr1l-status,0+pclath+cstack]
	line	61
	
l33052:	
;Init.c: 61: if(GetRomData()==0)
	fcall	_GetRomData
	iorlw	0
	skipz
	goto	u8421
	goto	u8420
u8421:
	goto	l33058
u8420:
	line	63
	
l33054:	
;Init.c: 62: {
;Init.c: 63: RomParams.bWinter=1;
	clrf	0+(_RomParams)+01h
	incf	0+(_RomParams)+01h,f
	line	64
	
l33056:	
;Init.c: 64: SaveRomData();
	fcall	_SaveRomData
	line	66
	
l33058:	
;Init.c: 65: }
;Init.c: 66: gFlags.AllFlag=0;
	clrf	(_gFlags)
	line	67
	
l33060:	
;Init.c: 67: SystemTick=0;
	clrf	(_SystemTick)
	clrf	(_SystemTick+1)
	line	75
	
l33062:	
;Init.c: 75: if(RomParams.bWinter==0)
	movf	0+(_RomParams)+01h,f
	skipz
	goto	u8431
	goto	u8430
u8431:
	goto	l33066
u8430:
	line	77
	
l33064:	
;Init.c: 76: {
;Init.c: 77: NeedMeasurementTick=36000;
	movlw	low(08CA0h)
	movwf	(_NeedMeasurementTick)
	movlw	high(08CA0h)
	movwf	((_NeedMeasurementTick))+1
	line	78
;Init.c: 78: }
	goto	l33068
	line	81
	
l33066:	
;Init.c: 79: else
;Init.c: 80: {
;Init.c: 81: NeedMeasurementTick=6000;
	movlw	low(01770h)
	movwf	(_NeedMeasurementTick)
	movlw	high(01770h)
	movwf	((_NeedMeasurementTick))+1
	line	84
	
l33068:	
;Init.c: 82: }
;Init.c: 84: TxErrDataIndex=0;
	clrf	(_TxErrDataIndex)
	line	85
	
l4427:	
	return
	opt stack 0
GLOBAL	__end_of_InitVariable
	__end_of_InitVariable:
;; =============== function _InitVariable ends ============

	signat	_InitVariable,88
	global	_SimI2C_Stop
psect	text2022,local,class=CODE,delta=2
global __ptext2022
__ptext2022:

;; *************** function _SimI2C_Stop *****************
;; Defined at:
;;		line 29 in file "F:\work\WYP\NBIoT\SimI2C.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		None
;; Tracked objects:
;;		On entry : 1F/0
;;		On exit  : 1F/2
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       0       0       0       0       0       0       0
;;      Locals:         0       0       0       0       0       0       0       0
;;      Temps:          0       0       0       0       0       0       0       0
;;      Totals:         0       0       0       0       0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    3
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_TCN75_ReadReg
;;		_TCN75_SetConfig
;; This function uses a non-reentrant model
;;
psect	text2022
	file	"F:\work\WYP\NBIoT\SimI2C.c"
	line	29
	global	__size_of_SimI2C_Stop
	__size_of_SimI2C_Stop	equ	__end_of_SimI2C_Stop-_SimI2C_Stop
	
_SimI2C_Stop:	
	opt	stack 11
; Regs used in _SimI2C_Stop: []
	line	30
	
l33050:	
;SimI2C.c: 30: LATD7=0;
	movlb 2	; select bank2
	bcf	(2175/8)^0100h,(2175)&7
	line	31
;SimI2C.c: 31: LATD6=0;
	bcf	(2174/8)^0100h,(2174)&7
	line	32
;SimI2C.c: 32: _delay((unsigned long)((1)*(4000000/4000000.0)));;
		opt asmopt_off
	clrwdt
	opt asmopt_on

	line	33
;SimI2C.c: 33: LATD7=1;
	movlb 2	; select bank2
	bsf	(2175/8)^0100h,(2175)&7
	line	34
;SimI2C.c: 34: _delay((unsigned long)((1)*(4000000/4000000.0)));;
		opt asmopt_off
	clrwdt
	opt asmopt_on

	line	35
;SimI2C.c: 35: LATD6=1;
	movlb 2	; select bank2
	bsf	(2174/8)^0100h,(2174)&7
	line	36
	
l27669:	
	return
	opt stack 0
GLOBAL	__end_of_SimI2C_Stop
	__end_of_SimI2C_Stop:
;; =============== function _SimI2C_Stop ends ============

	signat	_SimI2C_Stop,88
	global	_SimI2C_NoAck
psect	text2023,local,class=CODE,delta=2
global __ptext2023
__ptext2023:

;; *************** function _SimI2C_NoAck *****************
;; Defined at:
;;		line 64 in file "F:\work\WYP\NBIoT\SimI2C.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		None
;; Tracked objects:
;;		On entry : 1F/0
;;		On exit  : 1F/2
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       0       0       0       0       0       0       0
;;      Locals:         0       0       0       0       0       0       0       0
;;      Temps:          0       0       0       0       0       0       0       0
;;      Totals:         0       0       0       0       0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    3
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_TCN75_ReadReg
;; This function uses a non-reentrant model
;;
psect	text2023
	file	"F:\work\WYP\NBIoT\SimI2C.c"
	line	64
	global	__size_of_SimI2C_NoAck
	__size_of_SimI2C_NoAck	equ	__end_of_SimI2C_NoAck-_SimI2C_NoAck
	
_SimI2C_NoAck:	
	opt	stack 11
; Regs used in _SimI2C_NoAck: []
	line	65
	
l33048:	
;SimI2C.c: 65: LATD7=1;
	movlb 2	; select bank2
	bsf	(2175/8)^0100h,(2175)&7
	line	66
;SimI2C.c: 66: LATD6=1;
	bsf	(2174/8)^0100h,(2174)&7
	line	67
;SimI2C.c: 67: _delay((unsigned long)((1)*(4000000/4000000.0)));;
		opt asmopt_off
	clrwdt
	opt asmopt_on

	line	68
;SimI2C.c: 68: LATD7=0;
	movlb 2	; select bank2
	bcf	(2175/8)^0100h,(2175)&7
	line	69
	
l27678:	
	return
	opt stack 0
GLOBAL	__end_of_SimI2C_NoAck
	__end_of_SimI2C_NoAck:
;; =============== function _SimI2C_NoAck ends ============

	signat	_SimI2C_NoAck,88
	global	_SimI2C_Ack
psect	text2024,local,class=CODE,delta=2
global __ptext2024
__ptext2024:

;; *************** function _SimI2C_Ack *****************
;; Defined at:
;;		line 53 in file "F:\work\WYP\NBIoT\SimI2C.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		None
;; Tracked objects:
;;		On entry : 1F/0
;;		On exit  : 1F/2
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       0       0       0       0       0       0       0
;;      Locals:         0       0       0       0       0       0       0       0
;;      Temps:          0       0       0       0       0       0       0       0
;;      Totals:         0       0       0       0       0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    3
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_TCN75_ReadReg
;; This function uses a non-reentrant model
;;
psect	text2024
	file	"F:\work\WYP\NBIoT\SimI2C.c"
	line	53
	global	__size_of_SimI2C_Ack
	__size_of_SimI2C_Ack	equ	__end_of_SimI2C_Ack-_SimI2C_Ack
	
_SimI2C_Ack:	
	opt	stack 11
; Regs used in _SimI2C_Ack: []
	line	54
	
l33046:	
;SimI2C.c: 54: LATD6=0;
	movlb 2	; select bank2
	bcf	(2174/8)^0100h,(2174)&7
	line	55
;SimI2C.c: 55: _delay((unsigned long)((1)*(4000000/4000000.0)));;
		opt asmopt_off
	clrwdt
	opt asmopt_on

	line	56
;SimI2C.c: 56: LATD7=1;
	movlb 2	; select bank2
	bsf	(2175/8)^0100h,(2175)&7
	line	57
;SimI2C.c: 57: _delay((unsigned long)((1)*(4000000/4000000.0)));;
		opt asmopt_off
	clrwdt
	opt asmopt_on

	line	58
;SimI2C.c: 58: LATD7=0;
	movlb 2	; select bank2
	bcf	(2175/8)^0100h,(2175)&7
	line	59
;SimI2C.c: 59: _delay((unsigned long)((1)*(4000000/4000000.0)));;
		opt asmopt_off
	clrwdt
	opt asmopt_on

	line	60
;SimI2C.c: 60: LATD6=1;
	movlb 2	; select bank2
	bsf	(2174/8)^0100h,(2174)&7
	line	61
	
l27675:	
	return
	opt stack 0
GLOBAL	__end_of_SimI2C_Ack
	__end_of_SimI2C_Ack:
;; =============== function _SimI2C_Ack ends ============

	signat	_SimI2C_Ack,88
	global	_SimI2C_ReadByte
psect	text2025,local,class=CODE,delta=2
global __ptext2025
__ptext2025:

;; *************** function _SimI2C_ReadByte *****************
;; Defined at:
;;		line 90 in file "F:\work\WYP\NBIoT\SimI2C.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;  i               1    1[BANK0 ] unsigned char 
;;  data            1    0[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;                  1    wreg      unsigned char 
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 1D/0
;;		On exit  : 1F/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       0       0       0       0       0       0       0
;;      Locals:         0       2       0       0       0       0       0       0
;;      Temps:          0       0       0       0       0       0       0       0
;;      Totals:         0       2       0       0       0       0       0       0
;;Total ram usage:        2 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    3
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_TCN75_ReadReg
;; This function uses a non-reentrant model
;;
psect	text2025
	file	"F:\work\WYP\NBIoT\SimI2C.c"
	line	90
	global	__size_of_SimI2C_ReadByte
	__size_of_SimI2C_ReadByte	equ	__end_of_SimI2C_ReadByte-_SimI2C_ReadByte
	
_SimI2C_ReadByte:	
	opt	stack 11
; Regs used in _SimI2C_ReadByte: [wreg+status,2+status,0]
	line	92
	
l33028:	
;SimI2C.c: 91: unsigned char data,i;
;SimI2C.c: 92: TRISD6=1;
	movlb 1	; select bank1
	bsf	(1150/8)^080h,(1150)&7
	line	93
;SimI2C.c: 93: _delay((unsigned long)((1)*(4000000/4000000.0)));;
		opt asmopt_off
	clrwdt
	opt asmopt_on

	line	94
;SimI2C.c: 94: LATD7=0;
	movlb 2	; select bank2
	bcf	(2175/8)^0100h,(2175)&7
	line	95
	
l33030:	
;SimI2C.c: 95: data=0;
	movlb 0	; select bank0
	clrf	(SimI2C_ReadByte@data)
	line	96
;SimI2C.c: 96: for(i=0;i<8;i++)
	clrf	(SimI2C_ReadByte@i)
	line	97
	
l27688:	
	line	98
;SimI2C.c: 97: {
;SimI2C.c: 98: _delay((unsigned long)((1)*(4000000/4000000.0)));;
		opt asmopt_off
	clrwdt
	opt asmopt_on

	line	99
;SimI2C.c: 99: LATD7=1;
	movlb 2	; select bank2
	bsf	(2175/8)^0100h,(2175)&7
	line	100
;SimI2C.c: 100: _delay((unsigned long)((1)*(4000000/4000000.0)));;
		opt asmopt_off
	clrwdt
	opt asmopt_on

	line	101
;SimI2C.c: 101: data=data<<1;
	movlb 0	; select bank0
	lslf	(SimI2C_ReadByte@data),f
	line	102
;SimI2C.c: 102: if(RD6)
	btfss	(126/8),(126)&7
	goto	u8401
	goto	u8400
u8401:
	goto	l27690
u8400:
	line	103
	
l33036:	
;SimI2C.c: 103: data=data|0x01;
	bsf	(SimI2C_ReadByte@data)+(0/8),(0)&7
	
l27690:	
	line	104
;SimI2C.c: 104: _delay((unsigned long)((1)*(4000000/4000000.0)));;
		opt asmopt_off
	clrwdt
	opt asmopt_on

	line	105
;SimI2C.c: 105: LATD7=0;
	movlb 2	; select bank2
	bcf	(2175/8)^0100h,(2175)&7
	line	106
;SimI2C.c: 106: _delay((unsigned long)((1)*(4000000/4000000.0)));;
		opt asmopt_off
	clrwdt
	opt asmopt_on

	line	96
	
l33038:	
	movlb 0	; select bank0
	incf	(SimI2C_ReadByte@i),f
	
l33040:	
	movlw	(08h)
	subwf	(SimI2C_ReadByte@i),w
	skipc
	goto	u8411
	goto	u8410
u8411:
	goto	l27688
u8410:
	
l27689:	
	line	108
;SimI2C.c: 107: }
;SimI2C.c: 108: TRISD6=0;
	movlb 1	; select bank1
	bcf	(1150/8)^080h,(1150)&7
	line	109
;SimI2C.c: 109: _delay((unsigned long)((1)*(4000000/4000000.0)));;
		opt asmopt_off
	clrwdt
	opt asmopt_on

	line	110
	
l33042:	
;SimI2C.c: 110: return data;
	movlb 0	; select bank0
	movf	(SimI2C_ReadByte@data),w
	line	111
	
l27691:	
	return
	opt stack 0
GLOBAL	__end_of_SimI2C_ReadByte
	__end_of_SimI2C_ReadByte:
;; =============== function _SimI2C_ReadByte ends ============

	signat	_SimI2C_ReadByte,89
	global	_SimI2C_RecAck
psect	text2026,local,class=CODE,delta=2
global __ptext2026
__ptext2026:

;; *************** function _SimI2C_RecAck *****************
;; Defined at:
;;		line 39 in file "F:\work\WYP\NBIoT\SimI2C.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;  t               1    0[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;                  1    wreg      unsigned char 
;; Registers used:
;;		wreg
;; Tracked objects:
;;		On entry : 1F/2
;;		On exit  : 1F/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       0       0       0       0       0       0       0
;;      Locals:         0       1       0       0       0       0       0       0
;;      Temps:          0       0       0       0       0       0       0       0
;;      Totals:         0       1       0       0       0       0       0       0
;;Total ram usage:        1 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    3
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_TCN75_ReadReg
;;		_TCN75_SetConfig
;; This function uses a non-reentrant model
;;
psect	text2026
	file	"F:\work\WYP\NBIoT\SimI2C.c"
	line	39
	global	__size_of_SimI2C_RecAck
	__size_of_SimI2C_RecAck	equ	__end_of_SimI2C_RecAck-_SimI2C_RecAck
	
_SimI2C_RecAck:	
	opt	stack 11
; Regs used in _SimI2C_RecAck: [wreg]
	line	41
	
l33018:	
;SimI2C.c: 40: unsigned char t;
;SimI2C.c: 41: TRISD6=1;
	movlb 1	; select bank1
	bsf	(1150/8)^080h,(1150)&7
	line	42
;SimI2C.c: 42: LATD7=0;
	movlb 2	; select bank2
	bcf	(2175/8)^0100h,(2175)&7
	line	43
;SimI2C.c: 43: _delay((unsigned long)((1)*(4000000/4000000.0)));;
		opt asmopt_off
	clrwdt
	opt asmopt_on

	line	44
;SimI2C.c: 44: LATD7=1;
	movlb 2	; select bank2
	bsf	(2175/8)^0100h,(2175)&7
	line	45
;SimI2C.c: 45: _delay((unsigned long)((1)*(4000000/4000000.0)));;
		opt asmopt_off
	clrwdt
	opt asmopt_on

	line	46
	
l33020:	
;SimI2C.c: 46: t=RD6;
	movlw	0
	movlb 0	; select bank0
	btfsc	(126/8),(126)&7
	movlw	1
	movwf	(SimI2C_RecAck@t)
	line	47
	
l33022:	
;SimI2C.c: 47: LATD7=0;
	movlb 2	; select bank2
	bcf	(2175/8)^0100h,(2175)&7
	line	48
	
l33024:	
;SimI2C.c: 48: TRISD6=0;
	movlb 1	; select bank1
	bcf	(1150/8)^080h,(1150)&7
	line	49
;SimI2C.c: 49: return t;
	movlb 0	; select bank0
	movf	(SimI2C_RecAck@t),w
	line	50
	
l27672:	
	return
	opt stack 0
GLOBAL	__end_of_SimI2C_RecAck
	__end_of_SimI2C_RecAck:
;; =============== function _SimI2C_RecAck ends ============

	signat	_SimI2C_RecAck,89
	global	_SimI2C_SendByte
psect	text2027,local,class=CODE,delta=2
global __ptext2027
__ptext2027:

;; *************** function _SimI2C_SendByte *****************
;; Defined at:
;;		line 71 in file "F:\work\WYP\NBIoT\SimI2C.c"
;; Parameters:    Size  Location     Type
;;  data            1    wreg     unsigned char 
;; Auto vars:     Size  Location     Type
;;  data            1    0[BANK0 ] unsigned char 
;;  i               1    2[BANK0 ] unsigned char 
;;  t               1    1[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 1D/2
;;		On exit  : 1F/2
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       0       0       0       0       0       0       0
;;      Locals:         0       3       0       0       0       0       0       0
;;      Temps:          0       0       0       0       0       0       0       0
;;      Totals:         0       3       0       0       0       0       0       0
;;Total ram usage:        3 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    3
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_TCN75_ReadReg
;;		_TCN75_SetConfig
;; This function uses a non-reentrant model
;;
psect	text2027
	file	"F:\work\WYP\NBIoT\SimI2C.c"
	line	71
	global	__size_of_SimI2C_SendByte
	__size_of_SimI2C_SendByte	equ	__end_of_SimI2C_SendByte-_SimI2C_SendByte
	
_SimI2C_SendByte:	
	opt	stack 11
; Regs used in _SimI2C_SendByte: [wreg+status,2+status,0]
;SimI2C_SendByte@data stored from wreg
	line	74
	movlb 0	; select bank0
	movwf	(SimI2C_SendByte@data)
	
l33002:	
;SimI2C.c: 72: unsigned char i;
;SimI2C.c: 73: unsigned char t;
;SimI2C.c: 74: for(i=0;i<8;i++)
	clrf	(SimI2C_SendByte@i)
	line	75
	
l27681:	
	line	76
;SimI2C.c: 75: {
;SimI2C.c: 76: LATD7=0;
	movlb 2	; select bank2
	bcf	(2175/8)^0100h,(2175)&7
	line	77
	
l33008:	
;SimI2C.c: 77: t=data&0x80;
	movlb 0	; select bank0
	movf	(SimI2C_SendByte@data),w
	movwf	(SimI2C_SendByte@t)
	
l33010:	
	movlw	(080h)
	andwf	(SimI2C_SendByte@t),f
	line	78
;SimI2C.c: 78: if(t==0x00)
	movf	(SimI2C_SendByte@t),f
	skipz
	goto	u8381
	goto	u8380
u8381:
	goto	l27683
u8380:
	line	79
	
l33012:	
;SimI2C.c: 79: LATD6=0;
	movlb 2	; select bank2
	bcf	(2174/8)^0100h,(2174)&7
	goto	l27684
	line	80
	
l27683:	
	line	81
;SimI2C.c: 80: else
;SimI2C.c: 81: LATD6=1;
	movlb 2	; select bank2
	bsf	(2174/8)^0100h,(2174)&7
	
l27684:	
	line	82
;SimI2C.c: 82: data<<=1;
	movlb 0	; select bank0
	lslf	(SimI2C_SendByte@data),f
	line	83
;SimI2C.c: 83: _delay((unsigned long)((1)*(4000000/4000000.0)));;
		opt asmopt_off
	clrwdt
	opt asmopt_on

	line	84
;SimI2C.c: 84: LATD7=1;
	movlb 2	; select bank2
	bsf	(2175/8)^0100h,(2175)&7
	line	85
;SimI2C.c: 85: _delay((unsigned long)((1)*(4000000/4000000.0)));;
		opt asmopt_off
	clrwdt
	opt asmopt_on

	line	74
	
l33014:	
	movlb 0	; select bank0
	incf	(SimI2C_SendByte@i),f
	
l33016:	
	movlw	(08h)
	subwf	(SimI2C_SendByte@i),w
	skipc
	goto	u8391
	goto	u8390
u8391:
	goto	l27681
u8390:
	
l27682:	
	line	87
;SimI2C.c: 86: }
;SimI2C.c: 87: LATD7=0;
	movlb 2	; select bank2
	bcf	(2175/8)^0100h,(2175)&7
	line	88
	
l27685:	
	return
	opt stack 0
GLOBAL	__end_of_SimI2C_SendByte
	__end_of_SimI2C_SendByte:
;; =============== function _SimI2C_SendByte ends ============

	signat	_SimI2C_SendByte,4216
	global	_SimI2C_Start
psect	text2028,local,class=CODE,delta=2
global __ptext2028
__ptext2028:

;; *************** function _SimI2C_Start *****************
;; Defined at:
;;		line 19 in file "F:\work\WYP\NBIoT\SimI2C.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		None
;; Tracked objects:
;;		On entry : 1F/0
;;		On exit  : 1F/2
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       0       0       0       0       0       0       0
;;      Locals:         0       0       0       0       0       0       0       0
;;      Temps:          0       0       0       0       0       0       0       0
;;      Totals:         0       0       0       0       0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    3
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_TCN75_ReadReg
;;		_TCN75_SetConfig
;; This function uses a non-reentrant model
;;
psect	text2028
	file	"F:\work\WYP\NBIoT\SimI2C.c"
	line	19
	global	__size_of_SimI2C_Start
	__size_of_SimI2C_Start	equ	__end_of_SimI2C_Start-_SimI2C_Start
	
_SimI2C_Start:	
	opt	stack 11
; Regs used in _SimI2C_Start: []
	line	20
	
l33000:	
;SimI2C.c: 20: LATD6=1;
	movlb 2	; select bank2
	bsf	(2174/8)^0100h,(2174)&7
	line	21
;SimI2C.c: 21: LATD7=1;
	bsf	(2175/8)^0100h,(2175)&7
	line	22
;SimI2C.c: 22: _delay((unsigned long)((1)*(4000000/4000000.0)));;
		opt asmopt_off
	clrwdt
	opt asmopt_on

	line	23
;SimI2C.c: 23: LATD6=0;
	movlb 2	; select bank2
	bcf	(2174/8)^0100h,(2174)&7
	line	24
;SimI2C.c: 24: _delay((unsigned long)((1)*(4000000/4000000.0)));;
		opt asmopt_off
	clrwdt
	opt asmopt_on

	line	25
;SimI2C.c: 25: LATD7=0;
	movlb 2	; select bank2
	bcf	(2175/8)^0100h,(2175)&7
	line	26
	
l27666:	
	return
	opt stack 0
GLOBAL	__end_of_SimI2C_Start
	__end_of_SimI2C_Start:
;; =============== function _SimI2C_Start ends ============

	signat	_SimI2C_Start,88
	global	_OneWire_WriteByte
psect	text2029,local,class=CODE,delta=2
global __ptext2029
__ptext2029:

;; *************** function _OneWire_WriteByte *****************
;; Defined at:
;;		line 167 in file "F:\work\WYP\NBIoT\OneWire.c"
;; Parameters:    Size  Location     Type
;;  val             1    wreg     unsigned char 
;; Auto vars:     Size  Location     Type
;;  val             1    1[BANK0 ] unsigned char 
;;  i               1    3[BANK0 ] unsigned char 
;;  temp            1    2[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 1F/0
;;		On exit  : 1F/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       0       0       0       0       0       0       0
;;      Locals:         0       3       0       0       0       0       0       0
;;      Temps:          0       1       0       0       0       0       0       0
;;      Totals:         0       4       0       0       0       0       0       0
;;Total ram usage:        4 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    3
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_OneWire_Command
;; This function uses a non-reentrant model
;;
psect	text2029
	file	"F:\work\WYP\NBIoT\OneWire.c"
	line	167
	global	__size_of_OneWire_WriteByte
	__size_of_OneWire_WriteByte	equ	__end_of_OneWire_WriteByte-_OneWire_WriteByte
	
_OneWire_WriteByte:	
	opt	stack 10
; Regs used in _OneWire_WriteByte: [wreg+status,2+status,0]
;OneWire_WriteByte@val stored from wreg
	line	170
	movwf	(OneWire_WriteByte@val)
	
l31258:	
;OneWire.c: 168: unsigned char i;
;OneWire.c: 169: unsigned char temp;
;OneWire.c: 170: for (i=0;i<8;i++)
	clrf	(OneWire_WriteByte@i)
	line	172
	
l31264:	
;OneWire.c: 171: {
;OneWire.c: 172: temp=val>>i;
	movf	(OneWire_WriteByte@val),w
	movwf	(??_OneWire_WriteByte+0)+0
	incf	(OneWire_WriteByte@i),w
	goto	u5264
u5265:
	lsrf	(??_OneWire_WriteByte+0)+0,f
u5264:
	decfsz	wreg,f
	goto	u5265
	movf	0+(??_OneWire_WriteByte+0)+0,w
	movwf	(OneWire_WriteByte@temp)
	line	173
;OneWire.c: 173: temp&=0x01;
	movlw	(01h)
	andwf	(OneWire_WriteByte@temp),f
	line	174
	
l31266:	
;OneWire.c: 174: (GIE = 0);
	bcf	(95/8),(95)&7
	line	175
	
l31268:	
;OneWire.c: 175: TRISB1 = 0;LATB1=0;
	movlb 1	; select bank1
	bcf	(1129/8)^080h,(1129)&7
	
l31270:	
	movlb 2	; select bank2
	bcf	(2153/8)^0100h,(2153)&7
	line	176
	
l31272:	
;OneWire.c: 176: _delay((unsigned long)((2)*(4000000/4000000.0)));
		opt asmopt_off
	nop2	;2 cycle nop
	opt asmopt_on

	line	177
	
l31274:	
;OneWire.c: 177: if (temp==1)
	movlb 0	; select bank0
	decf	(OneWire_WriteByte@temp),w
	skipz
	goto	u5271
	goto	u5270
u5271:
	goto	l31278
u5270:
	line	179
	
l31276:	
;OneWire.c: 178: {
;OneWire.c: 179: TRISB1=1;
	movlb 1	; select bank1
	bsf	(1129/8)^080h,(1129)&7
	line	181
	
l31278:	
;OneWire.c: 180: }
;OneWire.c: 181: _delay((unsigned long)((75)*(4000000/4000000.0)));
	opt asmopt_off
movlw	24
	movlb 0	; select bank0
movwf	(??_OneWire_WriteByte+0)+0,f
u10127:
decfsz	(??_OneWire_WriteByte+0)+0,f
	goto	u10127
	nop2	;nop
opt asmopt_on

	line	182
	
l31280:	
;OneWire.c: 182: TRISB1=1;
	movlb 1	; select bank1
	bsf	(1129/8)^080h,(1129)&7
	line	183
	
l31282:	
;OneWire.c: 183: (GIE = 1);
	bsf	(95/8),(95)&7
	line	170
	
l31284:	
	movlb 0	; select bank0
	incf	(OneWire_WriteByte@i),f
	
l31286:	
	movlw	(08h)
	subwf	(OneWire_WriteByte@i),w
	skipc
	goto	u5281
	goto	u5280
u5281:
	goto	l31264
u5280:
	line	187
	
l19368:	
	return
	opt stack 0
GLOBAL	__end_of_OneWire_WriteByte
	__end_of_OneWire_WriteByte:
;; =============== function _OneWire_WriteByte ends ============

	signat	_OneWire_WriteByte,4216
	global	_OneWire_ReadByte
psect	text2030,local,class=CODE,delta=2
global __ptext2030
__ptext2030:

;; *************** function _OneWire_ReadByte *****************
;; Defined at:
;;		line 190 in file "F:\work\WYP\NBIoT\OneWire.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;  i               1    3[BANK0 ] unsigned char 
;;  value           1    2[BANK0 ] unsigned char 
;;  b               1    1[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;                  1    wreg      unsigned char 
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 1E/0
;;		On exit  : 1F/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       0       0       0       0       0       0       0
;;      Locals:         0       3       0       0       0       0       0       0
;;      Temps:          0       1       0       0       0       0       0       0
;;      Totals:         0       4       0       0       0       0       0       0
;;Total ram usage:        4 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    3
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_DS18X20_ReadMeas
;; This function uses a non-reentrant model
;;
psect	text2030
	file	"F:\work\WYP\NBIoT\OneWire.c"
	line	190
	global	__size_of_OneWire_ReadByte
	__size_of_OneWire_ReadByte	equ	__end_of_OneWire_ReadByte-_OneWire_ReadByte
	
_OneWire_ReadByte:	
	opt	stack 11
; Regs used in _OneWire_ReadByte: [wreg+status,2+status,0]
	line	193
	
l31240:	
;OneWire.c: 191: unsigned char i;
;OneWire.c: 192: unsigned char b;
;OneWire.c: 193: unsigned char value=0;
	movlb 0	; select bank0
	clrf	(OneWire_ReadByte@value)
	line	194
;OneWire.c: 194: for(i=0;i<8;i++)
	clrf	(OneWire_ReadByte@i)
	line	195
	
l19371:	
	line	196
;OneWire.c: 195: {
;OneWire.c: 196: (GIE = 0);
	bcf	(95/8),(95)&7
	line	197
;OneWire.c: 197: TRISB1 = 0;LATB1=0;
	movlb 1	; select bank1
	bcf	(1129/8)^080h,(1129)&7
	movlb 2	; select bank2
	bcf	(2153/8)^0100h,(2153)&7
	line	198
;OneWire.c: 198: _delay((unsigned long)((2)*(4000000/4000000.0)));
		opt asmopt_off
	nop2	;2 cycle nop
	opt asmopt_on

	line	200
;OneWire.c: 200: TRISB1=1;
	movlb 1	; select bank1
	bsf	(1129/8)^080h,(1129)&7
	line	201
;OneWire.c: 201: _delay((unsigned long)((15-3-9)*(4000000/4000000.0)));
		opt asmopt_off
	nop2	;2 cycle nop
	opt asmopt_on
	opt asmopt_off
	clrwdt
	opt asmopt_on

	line	202
	
l31246:	
;OneWire.c: 202: b=RB1;
	movlw	0
	movlb 0	; select bank0
	btfsc	(105/8),(105)&7
	movlw	1
	movwf	(OneWire_ReadByte@b)
	line	203
	
l31248:	
;OneWire.c: 203: (GIE = 1);
	bsf	(95/8),(95)&7
	line	204
;OneWire.c: 204: _delay((unsigned long)((60)*(4000000/4000000.0)));
	opt asmopt_off
movlw	19
movwf	(??_OneWire_ReadByte+0)+0,f
u10137:
decfsz	(??_OneWire_ReadByte+0)+0,f
	goto	u10137
	nop2	;nop
opt asmopt_on

	line	206
;OneWire.c: 206: if(b)
	movlb 0	; select bank0
	movf	(OneWire_ReadByte@b),w
	skipz
	goto	u5230
	goto	l31252
u5230:
	line	208
	
l31250:	
;OneWire.c: 207: {
;OneWire.c: 208: value|=(0x01<<i);
	movlw	(01h)
	movwf	(??_OneWire_ReadByte+0)+0
	incf	(OneWire_ReadByte@i),w
	goto	u5244
u5245:
	lslf	(??_OneWire_ReadByte+0)+0,f
u5244:
	decfsz	wreg,f
	goto	u5245
	movf	0+(??_OneWire_ReadByte+0)+0,w
	iorwf	(OneWire_ReadByte@value),f
	line	194
	
l31252:	
	incf	(OneWire_ReadByte@i),f
	movlw	(08h)
	subwf	(OneWire_ReadByte@i),w
	skipc
	goto	u5251
	goto	u5250
u5251:
	goto	l19371
u5250:
	line	212
	
l31254:	
;OneWire.c: 210: }
;OneWire.c: 211: }
;OneWire.c: 212: return(value);
	movf	(OneWire_ReadByte@value),w
	line	213
	
l19374:	
	return
	opt stack 0
GLOBAL	__end_of_OneWire_ReadByte
	__end_of_OneWire_ReadByte:
;; =============== function _OneWire_ReadByte ends ============

	signat	_OneWire_ReadByte,89
	global	_atoi
psect	text2031,local,class=CODE,delta=2
global __ptext2031
__ptext2031:

;; *************** function _atoi *****************
;; Defined at:
;;		line 6 in file "C:\Program Files (x86)\HI-TECH Software\PICC\9.71a\sources\atoi.c"
;; Parameters:    Size  Location     Type
;;  s               2    6[BANK0 ] PTR const unsigned char 
;;		 -> ATCommand_RxList(100), RAM(128), 
;; Auto vars:     Size  Location     Type
;;  a               2   13[BANK0 ] int 
;;  sign            1   12[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;                  2    6[BANK0 ] int 
;; Registers used:
;;		wreg, fsr1l, fsr1h, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 1F/0
;;		On exit  : 1F/0
;;		Unchanged: FFFE0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       2       0       0       0       0       0       0
;;      Locals:         0       3       0       0       0       0       0       0
;;      Temps:          0       4       0       0       0       0       0       0
;;      Totals:         0       9       0       0       0       0       0       0
;;Total ram usage:        9 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    4
;; This function calls:
;;		___wmul
;;		_isdigit
;; This function is called by:
;;		_InitGPRS
;; This function uses a non-reentrant model
;;
psect	text2031
	file	"C:\Program Files (x86)\HI-TECH Software\PICC\9.71a\sources\atoi.c"
	line	6
	global	__size_of_atoi
	__size_of_atoi	equ	__end_of_atoi-_atoi
	
_atoi:	
	opt	stack 10
; Regs used in _atoi: [wreg+fsr1l-status,0+pclath+cstack]
	line	10
	
l32966:	
	goto	l32970
	line	11
	
l32968:	
	incf	(atoi@s),f
	skipnz
	incf	(atoi@s+1),f
	line	10
	
l32970:	
	movf	(atoi@s),w
	movwf	fsr1l
	movf	(atoi@s+1),w
	movwf	fsr1h

	movf	indf1,w
	xorlw	020h&0ffh
	skipnz
	goto	u8321
	goto	u8320
u8321:
	goto	l32968
u8320:
	
l32972:	
	movf	(atoi@s),w
	movwf	fsr1l
	movf	(atoi@s+1),w
	movwf	fsr1h

	movf	indf1,w
	xorlw	09h&0ffh
	skipnz
	goto	u8331
	goto	u8330
u8331:
	goto	l32968
u8330:
	line	12
	
l32974:	
	clrf	(atoi@a)
	clrf	(atoi@a+1)
	line	13
	clrf	(atoi@sign)
	line	14
	
l32976:	
	movf	(atoi@s),w
	movwf	fsr1l
	movf	(atoi@s+1),w
	movwf	fsr1h

	movf	indf1,w
	xorlw	02Dh&0ffh
	skipz
	goto	u8341
	goto	u8340
u8341:
	goto	l32980
u8340:
	line	15
	
l32978:	
	incf	(atoi@sign),f
	line	16
	incf	(atoi@s),f
	skipnz
	incf	(atoi@s+1),f
	line	17
	goto	l32988
	
l32980:	
	movf	(atoi@s),w
	movwf	fsr1l
	movf	(atoi@s+1),w
	movwf	fsr1h

	movf	indf1,w
	xorlw	02Bh&0ffh
	skipz
	goto	u8351
	goto	u8350
u8351:
	goto	l32988
u8350:
	line	18
	
l32982:	
	incf	(atoi@s),f
	skipnz
	incf	(atoi@s+1),f
	goto	l32988
	line	20
	
l32984:	
	movf	(atoi@s),w
	movwf	fsr1l
	movf	(atoi@s+1),w
	movwf	fsr1h

	movf	indf1,w
	movwf	(??_atoi+0)+0
	clrf	(??_atoi+0)+0+1
	movf	(atoi@a+1),w
	movwf	(?___wmul+1)
	movf	(atoi@a),w
	movwf	(?___wmul)
	movlw	0Ah
	movwf	0+(?___wmul)+02h
	clrf	1+(?___wmul)+02h
	fcall	___wmul
	movf	0+(??_atoi+0)+0,w
	addwf	(0+(?___wmul)),w
	movwf	(??_atoi+2)+0
	movf	1+(??_atoi+0)+0,w
	addwfc	(1+(?___wmul)),w
	movwf	1+(??_atoi+2)+0
	movf	0+(??_atoi+2)+0,w
	addlw	low(0FFD0h)
	movwf	(atoi@a)
	movlw	high(0FFD0h)
	addwfc	1+(??_atoi+2)+0,w
	movwf	1+(atoi@a)
	goto	l32982
	line	19
	
l32988:	
	movf	(atoi@s),w
	movwf	fsr1l
	movf	(atoi@s+1),w
	movwf	fsr1h

	movf	indf1,w
	fcall	_isdigit
	btfsc	status,0
	goto	u8361
	goto	u8360
u8361:
	goto	l32984
u8360:
	line	21
	
l32990:	
	movf	(atoi@sign),w
	skipz
	goto	u8370
	goto	l32996
u8370:
	line	22
	
l32992:	
	comf	(atoi@a),w
	movwf	(??_atoi+0)+0
	comf	(atoi@a+1),w
	movwf	((??_atoi+0)+0+1)
	incf	(??_atoi+0)+0,f
	skipnz
	incf	((??_atoi+0)+0+1),f
	movf	0+(??_atoi+0)+0,w
	movwf	(?_atoi)
	movf	1+(??_atoi+0)+0,w
	movwf	(?_atoi+1)
	goto	l27747
	line	23
	
l32996:	
	movf	(atoi@a+1),w
	movwf	(?_atoi+1)
	movf	(atoi@a),w
	movwf	(?_atoi)
	line	24
	
l27747:	
	return
	opt stack 0
GLOBAL	__end_of_atoi
	__end_of_atoi:
;; =============== function _atoi ends ============

	signat	_atoi,4218
	global	_Uart1_PutString
psect	text2032,local,class=CODE,delta=2
global __ptext2032
__ptext2032:

;; *************** function _Uart1_PutString *****************
;; Defined at:
;;		line 63 in file "F:\work\WYP\NBIoT\Uart.c"
;; Parameters:    Size  Location     Type
;;  pString         2    1[BANK0 ] PTR const unsigned char 
;;		 -> STR_49(3), STR_46(12), STR_45(15), STR_43(15), 
;;		 -> STR_42(45), STR_40(14), STR_39(4), STR_38(10), 
;;		 -> STR_37(10), STR_36(23), STR_35(33), STR_34(11), 
;;		 -> STR_31(11), STR_29(8), STR_28(11), STR_27(13), 
;;		 -> STR_25(10), STR_24(9), STR_23(6), STR_22(5), 
;;		 -> STR_21(4), STR_18(5), STR_17(5), STR_16(9), 
;;		 -> STR_15(5), STR_14(5), STR_13(9), STR_12(5), 
;;		 -> STR_11(5), ICCID(21), STR_10(9), STR_9(12), 
;;		 -> STR_7(12), STR_6(15), STR_4(15), STR_3(45), 
;;		 -> STR_1(14), 
;; Auto vars:     Size  Location     Type
;;  c               1    3[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, fsr0l, fsr0h, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 1F/0
;;		On exit  : 1F/0
;;		Unchanged: FFFE0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       2       0       0       0       0       0       0
;;      Locals:         0       1       0       0       0       0       0       0
;;      Temps:          0       0       0       0       0       0       0       0
;;      Totals:         0       3       0       0       0       0       0       0
;;Total ram usage:        3 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    4
;; This function calls:
;;		_Uart1_PutChar
;; This function is called by:
;;		_InteractServer
;;		_ATCommand_SendCmd
;; This function uses a non-reentrant model
;;
psect	text2032
	file	"F:\work\WYP\NBIoT\Uart.c"
	line	63
	global	__size_of_Uart1_PutString
	__size_of_Uart1_PutString	equ	__end_of_Uart1_PutString-_Uart1_PutString
	
_Uart1_PutString:	
	opt	stack 10
; Regs used in _Uart1_PutString: [wreg-fsr0h+status,2+status,0+pclath+cstack]
	line	65
;Uart.c: 64: char c;
;Uart.c: 65: while(1)
	
l23527:	
	line	67
	
l32956:	
;Uart.c: 66: {
;Uart.c: 67: c=*pString;
	movf	(Uart1_PutString@pString),w
	movwf	fsr0l
	movf	((Uart1_PutString@pString+1)),w
	movwf	fsr0h
	movf	indf0,w ;code access
	movwf	(Uart1_PutString@c)
	line	68
	
l32958:	
;Uart.c: 68: if(c=='\0')
	movf	(Uart1_PutString@c),f
	skipz
	goto	u8311
	goto	u8310
u8311:
	goto	l32962
u8310:
	goto	l23531
	line	70
	
l32962:	
;Uart.c: 70: Uart1_PutChar(c);
	movf	(Uart1_PutString@c),w
	fcall	_Uart1_PutChar
	line	71
	
l32964:	
;Uart.c: 71: pString++;
	movlb 0	; select bank0
	incf	(Uart1_PutString@pString),f
	skipnz
	incf	(Uart1_PutString@pString+1),f
	goto	l23527
	line	73
	
l23531:	
	return
	opt stack 0
GLOBAL	__end_of_Uart1_PutString
	__end_of_Uart1_PutString:
;; =============== function _Uart1_PutString ends ============

	signat	_Uart1_PutString,4216
	global	_strstr
psect	text2033,local,class=CODE,delta=2
global __ptext2033
__ptext2033:

;; *************** function _strstr *****************
;; Defined at:
;;		line 5 in file "C:\Program Files (x86)\HI-TECH Software\PICC\9.71a\sources\strstr.c"
;; Parameters:    Size  Location     Type
;;  s1              2   13[BANK0 ] PTR const unsigned char 
;;		 -> ATCommand_RxList(100), RAM(128), 
;;  s2              2   15[BANK0 ] PTR const unsigned char 
;;		 -> STR_44(5), STR_33(12), STR_32(12), STR_30(7), 
;;		 -> STR_26(9), ATCommand_ErrString(15), STR_5(5), ATCommand_OkString(15), 
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  2    wreg      PTR unsigned char 
;; Registers used:
;;		wreg, fsr0l, fsr0h, fsr1l, fsr1h, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 1F/0
;;		On exit  : 1F/0
;;		Unchanged: FFFE0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       4       0       0       0       0       0       0
;;      Locals:         0       0       0       0       0       0       0       0
;;      Temps:          0       0       0       0       0       0       0       0
;;      Totals:         0       4       0       0       0       0       0       0
;;Total ram usage:        4 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    4
;; This function calls:
;;		_strlen
;;		_strncmp
;;		_strchr
;; This function is called by:
;;		_CallSend
;;		_InitGPRS
;;		_CallTestSend
;;		_ATCommand_SendCmd
;;		_ATCommand_WaitData
;; This function uses a non-reentrant model
;;
psect	text2033
	file	"C:\Program Files (x86)\HI-TECH Software\PICC\9.71a\sources\strstr.c"
	line	5
	global	__size_of_strstr
	__size_of_strstr	equ	__end_of_strstr-_strstr
	
_strstr:	
	opt	stack 11
; Regs used in _strstr: [wreg-status,0+pclath+cstack]
	line	6
	
l32940:	
	goto	l32948
	line	7
	
l32942:	
	movf	(strstr@s1+1),w
	movwf	(?_strncmp+1)
	movf	(strstr@s1),w
	movwf	(?_strncmp)
	movf	(strstr@s2+1),w
	movwf	(1+?_strncmp+02h)
	movf	(strstr@s2),w
	movwf	(0+?_strncmp+02h)
	movf	(strstr@s2+1),w
	movwf	(?_strlen+1)
	movf	(strstr@s2),w
	movwf	(?_strlen)
	fcall	_strlen
	movf	(1+(?_strlen)),w
	movwf	1+(?_strncmp)+04h
	movf	(0+(?_strlen)),w
	movwf	0+(?_strncmp)+04h
	fcall	_strncmp
	movf	((1+(?_strncmp))),w
	iorwf	((0+(?_strncmp))),w
	skipz
	goto	u8281
	goto	u8280
u8281:
	goto	l32946
u8280:
	line	8
	
l32944:	
	goto	l27775
	line	9
	
l32946:	
	movf	(strstr@s1+1),w
	movwf	(?_strchr+1)
	movf	(strstr@s1),w
	movwf	(?_strchr)
	incf	(?_strchr),f
	skipnz
	incf	(?_strchr+1),f
	movf	(strstr@s2),w
	movwf	fsr0l
	movf	((strstr@s2+1)),w
	movwf	fsr0h
	movf	indf0,w ;code access
	movwf	0+(?_strchr)+02h
	clrf	1+(?_strchr)+02h
	fcall	_strchr
	movf	(1+(?_strchr)),w
	movwf	(strstr@s1+1)
	movf	(0+(?_strchr)),w
	movwf	(strstr@s1)
	line	6
	
l32948:	
	movf	(strstr@s1+1),w
	iorwf	(strstr@s1),w
	skipnz
	goto	u8291
	goto	u8290
u8291:
	goto	l32952
u8290:
	
l32950:	
	movf	(strstr@s1),w
	movwf	fsr1l
	movf	(strstr@s1+1),w
	movwf	fsr1h

	movf	indf1,f
	skipz
	goto	u8301
	goto	u8300
u8301:
	goto	l32942
u8300:
	line	11
	
l32952:	
	clrf	(?_strstr)
	clrf	(?_strstr+1)
	line	12
	
l27775:	
	return
	opt stack 0
GLOBAL	__end_of_strstr
	__end_of_strstr:
;; =============== function _strstr ends ============

	signat	_strstr,8313
	global	___delay_20ms
psect	text2034,local,class=CODE,delta=2
global __ptext2034
__ptext2034:

;; *************** function ___delay_20ms *****************
;; Defined at:
;;		line 8 in file "F:\work\WYP\NBIoT\afx.c"
;; Parameters:    Size  Location     Type
;;  x               2    0[BANK0 ] unsigned int 
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg
;; Tracked objects:
;;		On entry : 1F/0
;;		On exit  : 1F/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       2       0       0       0       0       0       0
;;      Locals:         0       0       0       0       0       0       0       0
;;      Temps:          0       2       0       0       0       0       0       0
;;      Totals:         0       4       0       0       0       0       0       0
;;Total ram usage:        4 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    3
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_InitSystem
;;		_main
;;		_ReadTData
;;		_CallProc
;;		_CallSend
;;		_InteractServer
;;		_InitGPRS
;;		_PowerDown
;;		_PowerON
;;		_TestProc
;;		_CallTestProc
;;		_CallTestSend
;;		_ATCommand_SendCmd
;; This function uses a non-reentrant model
;;
psect	text2034
	file	"F:\work\WYP\NBIoT\afx.c"
	line	8
	global	__size_of___delay_20ms
	__size_of___delay_20ms	equ	__end_of___delay_20ms-___delay_20ms
	
___delay_20ms:	
	opt	stack 12
; Regs used in ___delay_20ms: [wreg]
	line	9
	
l31176:	
;afx.c: 9: while(x--)
	goto	l13057
	line	11
	
l31178:	
;afx.c: 10: {
;afx.c: 11: _delay((unsigned long)((20)*(4000000/4000.0)));
	opt asmopt_off
movlw	26
movwf	((??___delay_20ms+0)+0+1),f
	movlw	248
movwf	((??___delay_20ms+0)+0),f
u10147:
	decfsz	((??___delay_20ms+0)+0),f
	goto	u10147
	decfsz	((??___delay_20ms+0)+0+1),f
	goto	u10147
	clrwdt
opt asmopt_on

	line	12
	
l13057:	
	line	9
	movlw	low(01h)
	movlb 0	; select bank0
	subwf	(___delay_20ms@x),f
	movlw	high(01h)
	subwfb	(___delay_20ms@x+1),f
	incf	((___delay_20ms@x)),w
	skipnz
	incf	((___delay_20ms@x+1)),w

	skipz
	goto	u5121
	goto	u5120
u5121:
	goto	l31178
u5120:
	line	13
	
l13060:	
	return
	opt stack 0
GLOBAL	__end_of___delay_20ms
	__end_of___delay_20ms:
;; =============== function ___delay_20ms ends ============

	signat	___delay_20ms,4216
	global	_TCN75_Init
psect	text2035,local,class=CODE,delta=2
global __ptext2035
__ptext2035:

;; *************** function _TCN75_Init *****************
;; Defined at:
;;		line 16 in file "F:\work\WYP\NBIoT\TCN75.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 1F/0
;;		On exit  : 1F/2
;;		Unchanged: FFFE0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       0       0       0       0       0       0       0
;;      Locals:         0       0       0       0       0       0       0       0
;;      Temps:          0       0       0       0       0       0       0       0
;;      Totals:         0       0       0       0       0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    4
;; This function calls:
;;		_SimI2C_Init
;; This function is called by:
;;		_InitSystem
;; This function uses a non-reentrant model
;;
psect	text2035
	file	"F:\work\WYP\NBIoT\TCN75.c"
	line	16
	global	__size_of_TCN75_Init
	__size_of_TCN75_Init	equ	__end_of_TCN75_Init-_TCN75_Init
	
_TCN75_Init:	
	opt	stack 12
; Regs used in _TCN75_Init: [status,2+status,0+pclath+cstack]
	line	17
	
l32938:	
;TCN75.c: 17: SimI2C_Init();
	fcall	_SimI2C_Init
	line	18
	
l21439:	
	return
	opt stack 0
GLOBAL	__end_of_TCN75_Init
	__end_of_TCN75_Init:
;; =============== function _TCN75_Init ends ============

	signat	_TCN75_Init,88
	global	_OneWire_Reset
psect	text2036,local,class=CODE,delta=2
global __ptext2036
__ptext2036:

;; *************** function _OneWire_Reset *****************
;; Defined at:
;;		line 6 in file "F:\work\WYP\NBIoT\OneWire.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;  r               1    2[BANK0 ] unsigned char 
;;  Retry           1    1[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;                  1    wreg      unsigned char 
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 1F/0
;;		On exit  : 1F/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       0       0       0       0       0       0       0
;;      Locals:         0       2       0       0       0       0       0       0
;;      Temps:          0       1       0       0       0       0       0       0
;;      Totals:         0       3       0       0       0       0       0       0
;;Total ram usage:        3 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    3
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_InitSystem
;;		_DS18X20_StartMeas
;;		_DS18X20_ReadMeas
;;		_OneWire_Command
;; This function uses a non-reentrant model
;;
psect	text2036
	file	"F:\work\WYP\NBIoT\OneWire.c"
	line	6
	global	__size_of_OneWire_Reset
	__size_of_OneWire_Reset	equ	__end_of_OneWire_Reset-_OneWire_Reset
	
_OneWire_Reset:	
	opt	stack 10
; Regs used in _OneWire_Reset: [wreg+status,2+status,0]
	line	8
	
l31148:	
;OneWire.c: 7: unsigned char r,Retry;
;OneWire.c: 8: r=1;
	clrf	(OneWire_Reset@r)
	incf	(OneWire_Reset@r),f
	line	9
	
l31150:	
;OneWire.c: 9: Retry=5;
	movlw	(05h)
	movwf	(OneWire_Reset@Retry)
	line	10
;OneWire.c: 10: while(Retry--)
	goto	l31168
	
l19349:	
	line	12
;OneWire.c: 11: {
;OneWire.c: 12: TRISB1 = 0;LATB1=0;
	movlb 1	; select bank1
	bcf	(1129/8)^080h,(1129)&7
	movlb 2	; select bank2
	bcf	(2153/8)^0100h,(2153)&7
	line	13
	
l31152:	
;OneWire.c: 13: _delay((unsigned long)((480)*(4000000/4000000.0)));
	opt asmopt_off
movlw	159
	movlb 0	; select bank0
movwf	(??_OneWire_Reset+0)+0,f
u10157:
decfsz	(??_OneWire_Reset+0)+0,f
	goto	u10157
	nop2	;nop
opt asmopt_on

	line	14
	
l31154:	
;OneWire.c: 14: TRISB1=1;
	movlb 1	; select bank1
	bsf	(1129/8)^080h,(1129)&7
	line	15
	
l31156:	
;OneWire.c: 15: (GIE = 0);
	bcf	(95/8),(95)&7
	line	16
;OneWire.c: 16: _delay((unsigned long)((75)*(4000000/4000000.0)));
	opt asmopt_off
movlw	24
	movlb 0	; select bank0
movwf	(??_OneWire_Reset+0)+0,f
u10167:
decfsz	(??_OneWire_Reset+0)+0,f
	goto	u10167
	nop2	;nop
opt asmopt_on

	line	17
;OneWire.c: 17: r=RB1;
	movlw	0
	movlb 0	; select bank0
	btfsc	(105/8),(105)&7
	movlw	1
	movwf	(OneWire_Reset@r)
	line	18
	
l31158:	
;OneWire.c: 18: (GIE = 1);
	bsf	(95/8),(95)&7
	line	19
;OneWire.c: 19: _delay((unsigned long)((480)*(4000000/4000000.0)));
	opt asmopt_off
movlw	159
movwf	(??_OneWire_Reset+0)+0,f
u10177:
decfsz	(??_OneWire_Reset+0)+0,f
	goto	u10177
	nop2	;nop
opt asmopt_on

	line	20
	
l31160:	
;OneWire.c: 20: if(RB1==0)
	movlb 0	; select bank0
	btfsc	(105/8),(105)&7
	goto	u5091
	goto	u5090
u5091:
	goto	l31164
u5090:
	line	21
	
l31162:	
;OneWire.c: 21: r=1;
	clrf	(OneWire_Reset@r)
	incf	(OneWire_Reset@r),f
	line	22
	
l31164:	
;OneWire.c: 22: if(r==0)
	movf	(OneWire_Reset@r),f
	skipz
	goto	u5101
	goto	u5100
u5101:
	goto	l31168
u5100:
	goto	l31170
	line	10
	
l31168:	
	decf	(OneWire_Reset@Retry),f
	movf	((OneWire_Reset@Retry)),w
	xorlw	0FFh&0ffh
	skipz
	goto	u5111
	goto	u5110
u5111:
	goto	l19349
u5110:
	line	25
	
l31170:	
;OneWire.c: 24: }
;OneWire.c: 25: return r;
	movf	(OneWire_Reset@r),w
	line	26
	
l19353:	
	return
	opt stack 0
GLOBAL	__end_of_OneWire_Reset
	__end_of_OneWire_Reset:
;; =============== function _OneWire_Reset ends ============

	signat	_OneWire_Reset,89
	global	_ATCommand_Init
psect	text2037,local,class=CODE,delta=2
global __ptext2037
__ptext2037:

;; *************** function _ATCommand_Init *****************
;; Defined at:
;;		line 17 in file "F:\work\WYP\NBIoT\ATCommand.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, fsr0l, fsr0h, fsr1l, fsr1h, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 17F/F
;;		On exit  : 17F/0
;;		Unchanged: FFE80/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       0       0       0       0       0       0       0
;;      Locals:         0       0       0       0       0       0       0       0
;;      Temps:          0       0       0       0       0       0       0       0
;;      Totals:         0       0       0       0       0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    4
;; This function calls:
;;		_strcpy
;; This function is called by:
;;		_InitSystem
;; This function uses a non-reentrant model
;;
psect	text2037
	file	"F:\work\WYP\NBIoT\ATCommand.c"
	line	17
	global	__size_of_ATCommand_Init
	__size_of_ATCommand_Init	equ	__end_of_ATCommand_Init-_ATCommand_Init
	
_ATCommand_Init:	
	opt	stack 12
; Regs used in _ATCommand_Init: [wreg-status,0+pclath+cstack]
	line	18
	
l32930:	
;ATCommand.c: 18: ATCommand_WaitACKTimes=50;
	movlw	032h
	movlb 0	; select bank0
	movwf	(_ATCommand_WaitACKTimes)
	clrf	(_ATCommand_WaitACKTimes+1)
	line	19
;ATCommand.c: 19: ATCommand_RetryTimes=3;
	movlw	(03h)
	movwf	(_ATCommand_RetryTimes)
	line	20
	
l32932:	
;ATCommand.c: 20: strcpy(ATCommand_OkString,"OK");
	movlw	low(STR_47|8000h)
	movwf	(?_strcpy)
	movlw	high(STR_47|8000h)
	movwf	((?_strcpy))+1
	movlw	(_ATCommand_OkString)&0ffh
	fcall	_strcpy
	line	21
	
l32934:	
;ATCommand.c: 21: strcpy(ATCommand_ErrString,"ERROR");
	movlw	low(STR_48|8000h)
	movwf	(?_strcpy)
	movlw	high(STR_48|8000h)
	movwf	((?_strcpy))+1
	movlw	(_ATCommand_ErrString)&0ffh
	fcall	_strcpy
	line	22
	
l32936:	
;ATCommand.c: 22: ATCommand_Clear='\0';
	clrf	(_ATCommand_Clear)
	line	24
	
l15187:	
	return
	opt stack 0
GLOBAL	__end_of_ATCommand_Init
	__end_of_ATCommand_Init:
;; =============== function _ATCommand_Init ends ============

	signat	_ATCommand_Init,88
	global	_SaveRomData
psect	text2038,local,class=CODE,delta=2
global __ptext2038
__ptext2038:

;; *************** function _SaveRomData *****************
;; Defined at:
;;		line 139 in file "F:\work\WYP\NBIoT\afx.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;  i               1    7[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, fsr1l, fsr1h, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 1F/0
;;		On exit  : 1F/0
;;		Unchanged: FFFE0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       0       0       0       0       0       0       0
;;      Locals:         0       1       0       0       0       0       0       0
;;      Temps:          0       0       0       0       0       0       0       0
;;      Totals:         0       1       0       0       0       0       0       0
;;Total ram usage:        1 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    4
;; This function calls:
;;		_GetVerify_Sum
;;		_eeprom_write
;; This function is called by:
;;		_InitVariable
;;		_CallSend
;; This function uses a non-reentrant model
;;
psect	text2038
	file	"F:\work\WYP\NBIoT\afx.c"
	line	139
	global	__size_of_SaveRomData
	__size_of_SaveRomData	equ	__end_of_SaveRomData-_SaveRomData
	
_SaveRomData:	
	opt	stack 11
; Regs used in _SaveRomData: [wreg+fsr1l-status,0+pclath+cstack]
	line	141
	
l32914:	
;afx.c: 140: unsigned char i;
;afx.c: 141: RomParams.sum=GetVerify_Sum(&RomParams.All[1],2-1);
	clrf	(?_GetVerify_Sum)
	incf	(?_GetVerify_Sum),f
	clrf	(?_GetVerify_Sum+1)
	movlw	(_RomParams+01h)&0ffh
	fcall	_GetVerify_Sum
	movwf	(_RomParams)
	line	142
	
l32916:	
;afx.c: 142: RomParams.sum+=1;
	incf	(_RomParams),f
	line	143
	
l32918:	
;afx.c: 143: for(i=0;i<2;i++)
	clrf	(SaveRomData@i)
	line	144
	
l32924:	
;afx.c: 144: eeprom_write(i,RomParams.All[i]);
	movf	(SaveRomData@i),w
	addlw	_RomParams&0ffh
	movwf	fsr1l
	clrf fsr1h	
	
	movf	indf1,w
	movwf	(?_eeprom_write)
	movf	(SaveRomData@i),w
	fcall	_eeprom_write
	line	143
	
l32926:	
	movlb 0	; select bank0
	incf	(SaveRomData@i),f
	
l32928:	
	movlw	(02h)
	subwf	(SaveRomData@i),w
	skipc
	goto	u8271
	goto	u8270
u8271:
	goto	l32924
u8270:
	line	145
	
l13110:	
	return
	opt stack 0
GLOBAL	__end_of_SaveRomData
	__end_of_SaveRomData:
;; =============== function _SaveRomData ends ============

	signat	_SaveRomData,88
	global	_GetRomData
psect	text2039,local,class=CODE,delta=2
global __ptext2039
__ptext2039:

;; *************** function _GetRomData *****************
;; Defined at:
;;		line 125 in file "F:\work\WYP\NBIoT\afx.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;  i               1    7[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;                  1    wreg      unsigned char 
;; Registers used:
;;		wreg, fsr1l, fsr1h, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 17F/0
;;		On exit  : 17F/0
;;		Unchanged: FFE80/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       0       0       0       0       0       0       0
;;      Locals:         0       1       0       0       0       0       0       0
;;      Temps:          0       0       0       0       0       0       0       0
;;      Totals:         0       1       0       0       0       0       0       0
;;Total ram usage:        1 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    4
;; This function calls:
;;		_eeprom_read
;;		_GetVerify_Sum
;; This function is called by:
;;		_InitVariable
;; This function uses a non-reentrant model
;;
psect	text2039
	file	"F:\work\WYP\NBIoT\afx.c"
	line	125
	global	__size_of_GetRomData
	__size_of_GetRomData	equ	__end_of_GetRomData-_GetRomData
	
_GetRomData:	
	opt	stack 11
; Regs used in _GetRomData: [wreg+fsr1l-status,0+pclath+cstack]
	line	127
	
l32886:	
;afx.c: 126: unsigned char i;
;afx.c: 127: for(i=0;i<2;i++)
	clrf	(GetRomData@i)
	line	128
	
l32892:	
;afx.c: 128: RomParams.All[i]=eeprom_read(i);
	movf	(GetRomData@i),w
	addlw	_RomParams&0ffh
	movwf	fsr1l
	clrf fsr1h	
	
	movf	(GetRomData@i),w
	fcall	_eeprom_read
	movwf	indf1
	line	127
	
l32894:	
	movlb 0	; select bank0
	incf	(GetRomData@i),f
	
l32896:	
	movlw	(02h)
	subwf	(GetRomData@i),w
	skipc
	goto	u8251
	goto	u8250
u8251:
	goto	l32892
u8250:
	line	129
	
l32898:	
;afx.c: 129: i=GetVerify_Sum(&RomParams.All[1],2-1);
	clrf	(?_GetVerify_Sum)
	incf	(?_GetVerify_Sum),f
	clrf	(?_GetVerify_Sum+1)
	movlw	(_RomParams+01h)&0ffh
	fcall	_GetVerify_Sum
	movwf	(GetRomData@i)
	line	130
	
l32900:	
;afx.c: 130: i+=1;
	incf	(GetRomData@i),f
	line	131
	
l32902:	
;afx.c: 131: if(i==RomParams.sum)
	movf	(_RomParams),w
	xorwf	(GetRomData@i),w
	skipz
	goto	u8261
	goto	u8260
u8261:
	goto	l32910
u8260:
	line	133
	
l32904:	
;afx.c: 132: {
;afx.c: 133: return 1;
	movlw	(01h)
	goto	l13104
	line	136
	
l32910:	
;afx.c: 135: else
;afx.c: 136: return 0;
	movlw	(0)
	line	137
	
l13104:	
	return
	opt stack 0
GLOBAL	__end_of_GetRomData
	__end_of_GetRomData:
;; =============== function _GetRomData ends ============

	signat	_GetRomData,89
	global	_LcdDisplay_Err
psect	text2040,local,class=CODE,delta=2
global __ptext2040
__ptext2040:

;; *************** function _LcdDisplay_Err *****************
;; Defined at:
;;		line 370 in file "F:\work\WYP\NBIoT\Display.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, fsr0l, fsr0h, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 1D/0
;;		On exit  : 1F/F
;;		Unchanged: FFFE0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       0       0       0       0       0       0       0
;;      Locals:         0       0       0       0       0       0       0       0
;;      Temps:          0       0       0       0       0       0       0       0
;;      Totals:         0       0       0       0       0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    4
;; This function calls:
;;		___lbdiv
;;		___lbmod
;;		_LcdDisplayNum
;; This function is called by:
;;		_CallProc
;;		_TestProc
;;		_CallTestProc
;; This function uses a non-reentrant model
;;
psect	text2040
	file	"F:\work\WYP\NBIoT\Display.c"
	line	370
	global	__size_of_LcdDisplay_Err
	__size_of_LcdDisplay_Err	equ	__end_of_LcdDisplay_Err-_LcdDisplay_Err
	
_LcdDisplay_Err:	
	opt	stack 12
; Regs used in _LcdDisplay_Err: [wreg-fsr0h+status,2+status,0+pclath+cstack]
	line	374
	
l32876:	
;Display.c: 374: while(WA==0);
	
l2345:	
	movlb 15	; select bank15
	btfss	(15508/8)^0780h,(15508)&7
	goto	u8231
	goto	u8230
u8231:
	goto	l2345
u8230:
	
l2347:	
	line	375
;Display.c: 375: SEG5COM3=0;
	bcf	(15693/8)^0780h,(15693)&7
	line	376
;Display.c: 376: while(WA==0);
	
l2348:	
	btfss	(15508/8)^0780h,(15508)&7
	goto	u8241
	goto	u8240
u8241:
	goto	l2348
u8240:
	
l2350:	
	line	377
;Display.c: 377: SEG21COM2=1;
	bsf	(15685/8)^0780h,(15685)&7
	line	378
	
l32878:	
;Display.c: 378: DpyNum[0]=0x01 | 0x08 | 0x10 | 0x20 | 0x40;
	movlw	(079h)
	movlb 0	; select bank0
	movwf	(_DpyNum)
	line	379
	
l32880:	
;Display.c: 379: DpyNum[1]=SegCode[ErrState/10];
	movlw	(0Ah)
	movwf	(?___lbdiv)
	movf	(_ErrState),w
	fcall	___lbdiv
	addlw	low(_SegCode|8000h)
	movwf	fsr0l
	movlw	high(_SegCode|8000h)
	skipnc
	addlw	1
	movwf	fsr0h
	movf	indf0,w ;code access
	movwf	0+(_DpyNum)+01h
	line	380
	
l32882:	
;Display.c: 380: DpyNum[2]=SegCode[ErrState%10];
	movlw	(0Ah)
	movwf	(?___lbmod)
	movf	(_ErrState),w
	fcall	___lbmod
	addlw	low(_SegCode|8000h)
	movwf	fsr0l
	movlw	high(_SegCode|8000h)
	skipnc
	addlw	1
	movwf	fsr0h
	movf	indf0,w ;code access
	movwf	0+(_DpyNum)+02h
	line	381
	
l32884:	
;Display.c: 381: LcdDisplayNum();
	fcall	_LcdDisplayNum
	line	382
	
l2351:	
	return
	opt stack 0
GLOBAL	__end_of_LcdDisplay_Err
	__end_of_LcdDisplay_Err:
;; =============== function _LcdDisplay_Err ends ============

	signat	_LcdDisplay_Err,88
	global	_LcdDisplay_CurTemp
psect	text2041,local,class=CODE,delta=2
global __ptext2041
__ptext2041:

;; *************** function _LcdDisplay_CurTemp *****************
;; Defined at:
;;		line 340 in file "F:\work\WYP\NBIoT\Display.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;  t2              1    8[BANK0 ] unsigned char 
;;  t1              1    7[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, fsr0l, fsr0h, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 1F/0
;;		On exit  : 1F/F
;;		Unchanged: FFFE0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       0       0       0       0       0       0       0
;;      Locals:         0       2       0       0       0       0       0       0
;;      Temps:          0       2       0       0       0       0       0       0
;;      Totals:         0       4       0       0       0       0       0       0
;;Total ram usage:        4 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    4
;; This function calls:
;;		___lbdiv
;;		___lbmod
;;		_LcdDisplayNum
;; This function is called by:
;;		_ReadTData
;;		_CallProc
;;		_CallTestProc
;; This function uses a non-reentrant model
;;
psect	text2041
	file	"F:\work\WYP\NBIoT\Display.c"
	line	340
	global	__size_of_LcdDisplay_CurTemp
	__size_of_LcdDisplay_CurTemp	equ	__end_of_LcdDisplay_CurTemp-_LcdDisplay_CurTemp
	
_LcdDisplay_CurTemp:	
	opt	stack 12
; Regs used in _LcdDisplay_CurTemp: [wreg-fsr0h+status,2+status,0+pclath+cstack]
	line	345
	
l32854:	
;Display.c: 341: unsigned char t1,t2;
;Display.c: 345: if(CurTemp.u16==0xf000)
		movf	(_CurTemp+1),w
	xorlw	240
	iorwf	(_CurTemp),w

	skipz
	goto	u8181
	goto	u8180
u8181:
	goto	l2339
u8180:
	line	347
	
l32856:	
;Display.c: 346: {
;Display.c: 347: DpyNum[0]=0x01 | 0x08 | 0x10 | 0x20 | 0x40;
	movlw	(079h)
	movwf	(_DpyNum)
	line	348
;Display.c: 348: DpyNum[1]=0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20;
	movlw	(03Fh)
	movwf	0+(_DpyNum)+01h
	line	349
;Display.c: 349: DpyNum[2]=0x02 | 0x04;
	movlw	(06h)
	movwf	0+(_DpyNum)+02h
	line	350
;Display.c: 350: while(WA==0);
	
l2332:	
	movlb 15	; select bank15
	btfss	(15508/8)^0780h,(15508)&7
	goto	u8191
	goto	u8190
u8191:
	goto	l2332
u8190:
	
l2334:	
	line	351
;Display.c: 351: SEG21COM2=1;
	bsf	(15685/8)^0780h,(15685)&7
	line	352
;Display.c: 352: while(WA==0);
	
l2335:	
	btfss	(15508/8)^0780h,(15508)&7
	goto	u8201
	goto	u8200
u8201:
	goto	l2335
u8200:
	
l2337:	
	line	353
;Display.c: 353: SEG5COM3=0;
	bcf	(15693/8)^0780h,(15693)&7
	line	354
;Display.c: 354: }
	goto	l32874
	line	357
	
l2339:	
	movlb 15	; select bank15
	btfss	(15508/8)^0780h,(15508)&7
	goto	u8211
	goto	u8210
u8211:
	goto	l2339
u8210:
	
l2341:	
	line	358
;Display.c: 358: SEG5COM3=1;
	bsf	(15693/8)^0780h,(15693)&7
	line	359
	
l32858:	
;Display.c: 359: t1=CurTemp.u16>>4;
	movlb 0	; select bank0
	movf	(_CurTemp+1),w
	movwf	(??_LcdDisplay_CurTemp+0)+0+1
	movf	(_CurTemp),w
	movwf	(??_LcdDisplay_CurTemp+0)+0
	movlw	04h
u8225:
	lsrf	(??_LcdDisplay_CurTemp+0)+1,f
	rrf	(??_LcdDisplay_CurTemp+0)+0,f
	decfsz	wreg,f
	goto	u8225
	movf	0+(??_LcdDisplay_CurTemp+0)+0,w
	movwf	(LcdDisplay_CurTemp@t1)
	line	360
	
l32860:	
;Display.c: 360: t2=CurTemp.u16&0x0f;
	movf	(_CurTemp),w
	movwf	(LcdDisplay_CurTemp@t2)
	
l32862:	
	movlw	(0Fh)
	andwf	(LcdDisplay_CurTemp@t2),f
	line	361
	
l32864:	
;Display.c: 361: t2=DS18X20_ToDecicel[t2];
	movf	(LcdDisplay_CurTemp@t2),w
	addlw	low(_DS18X20_ToDecicel|8000h)
	movwf	fsr0l
	movlw	high(_DS18X20_ToDecicel|8000h)
	skipnc
	addlw	1
	movwf	fsr0h
	movf	indf0,w ;code access
	movwf	(LcdDisplay_CurTemp@t2)
	line	362
	
l32866:	
;Display.c: 362: DpyNum[0]=SegCode[t1/10];
	movlw	(0Ah)
	movwf	(?___lbdiv)
	movf	(LcdDisplay_CurTemp@t1),w
	fcall	___lbdiv
	addlw	low(_SegCode|8000h)
	movwf	fsr0l
	movlw	high(_SegCode|8000h)
	skipnc
	addlw	1
	movwf	fsr0h
	movf	indf0,w ;code access
	movwf	(_DpyNum)
	line	363
	
l32868:	
;Display.c: 363: DpyNum[1]=SegCode[t1%10];
	movlw	(0Ah)
	movwf	(?___lbmod)
	movf	(LcdDisplay_CurTemp@t1),w
	fcall	___lbmod
	addlw	low(_SegCode|8000h)
	movwf	fsr0l
	movlw	high(_SegCode|8000h)
	skipnc
	addlw	1
	movwf	fsr0h
	movf	indf0,w ;code access
	movwf	0+(_DpyNum)+01h
	line	364
	
l32870:	
;Display.c: 364: DpyNum[1] |= 0x80;
	bsf	0+(_DpyNum)+01h+(7/8),(7)&7
	line	365
	
l32872:	
;Display.c: 365: DpyNum[2]=SegCode[t2];
	movf	(LcdDisplay_CurTemp@t2),w
	addlw	low(_SegCode|8000h)
	movwf	fsr0l
	movlw	high(_SegCode|8000h)
	skipnc
	addlw	1
	movwf	fsr0h
	movf	indf0,w ;code access
	movwf	0+(_DpyNum)+02h
	line	367
	
l32874:	
;Display.c: 366: }
;Display.c: 367: LcdDisplayNum();
	fcall	_LcdDisplayNum
	line	368
	
l2342:	
	return
	opt stack 0
GLOBAL	__end_of_LcdDisplay_CurTemp
	__end_of_LcdDisplay_CurTemp:
;; =============== function _LcdDisplay_CurTemp ends ============

	signat	_LcdDisplay_CurTemp,88
	global	_LcdDisplay_CSQ
psect	text2042,local,class=CODE,delta=2
global __ptext2042
__ptext2042:

;; *************** function _LcdDisplay_CSQ *****************
;; Defined at:
;;		line 327 in file "F:\work\WYP\NBIoT\Display.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;  t2              1    6[BANK0 ] unsigned char 
;;  t1              1    5[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, fsr0l, fsr0h, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 1F/0
;;		On exit  : 1F/F
;;		Unchanged: FFFE0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       0       0       0       0       0       0       0
;;      Locals:         0       2       0       0       0       0       0       0
;;      Temps:          0       0       0       0       0       0       0       0
;;      Totals:         0       2       0       0       0       0       0       0
;;Total ram usage:        2 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    4
;; This function calls:
;;		___lbdiv
;;		___lbmod
;;		_LcdDisplayNum
;; This function is called by:
;;		_InitGPRS
;; This function uses a non-reentrant model
;;
psect	text2042
	file	"F:\work\WYP\NBIoT\Display.c"
	line	327
	global	__size_of_LcdDisplay_CSQ
	__size_of_LcdDisplay_CSQ	equ	__end_of_LcdDisplay_CSQ-_LcdDisplay_CSQ
	
_LcdDisplay_CSQ:	
	opt	stack 10
; Regs used in _LcdDisplay_CSQ: [wreg-fsr0h+status,2+status,0+pclath+cstack]
	line	332
	
l32846:	
;Display.c: 328: unsigned char t1,t2;
;Display.c: 332: t1=CSQ/10;
	movlw	(0Ah)
	movwf	(?___lbdiv)
	movf	(_CSQ),w
	fcall	___lbdiv
	movwf	(LcdDisplay_CSQ@t1)
	line	333
;Display.c: 333: t2=CSQ%10;
	movlw	(0Ah)
	movwf	(?___lbmod)
	movf	(_CSQ),w
	fcall	___lbmod
	movwf	(LcdDisplay_CSQ@t2)
	line	334
	
l32848:	
;Display.c: 334: DpyNum[0]=0x01 | 0x02 | 0x10 | 0x20 | 0x40;
	movlw	(073h)
	movwf	(_DpyNum)
	line	335
	
l32850:	
;Display.c: 335: DpyNum[1]=SegCode[t1];
	movf	(LcdDisplay_CSQ@t1),w
	addlw	low(_SegCode|8000h)
	movwf	fsr0l
	movlw	high(_SegCode|8000h)
	skipnc
	addlw	1
	movwf	fsr0h
	movf	indf0,w ;code access
	movwf	0+(_DpyNum)+01h
	line	336
	
l32852:	
;Display.c: 336: DpyNum[2]=SegCode[t2];
	movf	(LcdDisplay_CSQ@t2),w
	addlw	low(_SegCode|8000h)
	movwf	fsr0l
	movlw	high(_SegCode|8000h)
	skipnc
	addlw	1
	movwf	fsr0h
	movf	indf0,w ;code access
	movwf	0+(_DpyNum)+02h
	line	337
;Display.c: 337: LcdDisplayNum();
	fcall	_LcdDisplayNum
	line	338
	
l2328:	
	return
	opt stack 0
GLOBAL	__end_of_LcdDisplay_CSQ
	__end_of_LcdDisplay_CSQ:
;; =============== function _LcdDisplay_CSQ ends ============

	signat	_LcdDisplay_CSQ,88
	global	_LcdDisplayAll
psect	text2043,local,class=CODE,delta=2
global __ptext2043
__ptext2043:

;; *************** function _LcdDisplayAll *****************
;; Defined at:
;;		line 240 in file "F:\work\WYP\NBIoT\Display.c"
;; Parameters:    Size  Location     Type
;;  x               1    wreg     unsigned char 
;; Auto vars:     Size  Location     Type
;;  x               1    0[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 1D/0
;;		On exit  : 10/0
;;		Unchanged: FFFE0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       0       0       0       0       0       0       0
;;      Locals:         0       1       0       0       0       0       0       0
;;      Temps:          0       0       0       0       0       0       0       0
;;      Totals:         0       1       0       0       0       0       0       0
;;Total ram usage:        1 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    4
;; This function calls:
;;		_LcdDisplayNum
;; This function is called by:
;;		_TestProc
;; This function uses a non-reentrant model
;;
psect	text2043
	file	"F:\work\WYP\NBIoT\Display.c"
	line	240
	global	__size_of_LcdDisplayAll
	__size_of_LcdDisplayAll	equ	__end_of_LcdDisplayAll-_LcdDisplayAll
	
_LcdDisplayAll:	
	opt	stack 12
; Regs used in _LcdDisplayAll: [wreg+status,2+status,0+pclath+cstack]
;LcdDisplayAll@x stored from wreg
	line	244
	movlb 0	; select bank0
	movwf	(LcdDisplayAll@x)
	
l32828:	
;Display.c: 244: if(x==0)
	movf	(LcdDisplayAll@x),f
	skipz
	goto	u7851
	goto	u7850
u7851:
	goto	l32834
u7850:
	line	246
	
l32830:	
;Display.c: 245: {
;Display.c: 246: DpyNum[0]=0xff;
	movlw	(0FFh)
	movwf	(_DpyNum)
	line	247
;Display.c: 247: DpyNum[1]=0xff;
	movlw	(0FFh)
	movwf	0+(_DpyNum)+01h
	line	248
;Display.c: 248: DpyNum[2]=0xff;
	movlw	(0FFh)
	movwf	0+(_DpyNum)+02h
	line	249
	
l32832:	
;Display.c: 249: LcdDisplayNum();
	fcall	_LcdDisplayNum
	line	250
;Display.c: 250: while(WA==0);
	
l2231:	
	btfss	(15508/8)^0780h,(15508)&7
	goto	u7861
	goto	u7860
u7861:
	goto	l2231
u7860:
	
l2233:	
	line	251
;Display.c: 251: SEG5COM0=1;
	bsf	(15621/8)^0780h,(15621)&7
	line	252
;Display.c: 252: while(WA==0);
	
l2234:	
	btfss	(15508/8)^0780h,(15508)&7
	goto	u7871
	goto	u7870
u7871:
	goto	l2234
u7870:
	
l2236:	
	line	253
;Display.c: 253: SEG5COM1=1;
	bsf	(15645/8)^0780h,(15645)&7
	line	254
;Display.c: 254: while(WA==0);
	
l2237:	
	btfss	(15508/8)^0780h,(15508)&7
	goto	u7881
	goto	u7880
u7881:
	goto	l2237
u7880:
	
l2239:	
	line	255
;Display.c: 255: SEG5COM2=1;
	bsf	(15669/8)^0780h,(15669)&7
	line	256
;Display.c: 256: while(WA==0);
	
l2240:	
	btfss	(15508/8)^0780h,(15508)&7
	goto	u7891
	goto	u7890
u7891:
	goto	l2240
u7890:
	
l2242:	
	line	257
;Display.c: 257: SEG5COM3=1;
	bsf	(15693/8)^0780h,(15693)&7
	line	258
;Display.c: 258: while(WA==0);
	
l2243:	
	btfss	(15508/8)^0780h,(15508)&7
	goto	u7901
	goto	u7900
u7901:
	goto	l2243
u7900:
	
l2245:	
	line	259
;Display.c: 259: SEG22COM3=1;
	bsf	(15710/8)^0780h,(15710)&7
	line	260
;Display.c: 260: while(WA==0);
	
l2246:	
	btfss	(15508/8)^0780h,(15508)&7
	goto	u7911
	goto	u7910
u7911:
	goto	l2246
u7910:
	
l2248:	
	line	261
;Display.c: 261: SEG3COM3=1;
	bsf	(15691/8)^0780h,(15691)&7
	line	262
;Display.c: 262: while(WA==0);
	
l2249:	
	btfss	(15508/8)^0780h,(15508)&7
	goto	u7921
	goto	u7920
u7921:
	goto	l2249
u7920:
	
l2251:	
	line	263
;Display.c: 263: SEG21COM3=1;
	bsf	(15709/8)^0780h,(15709)&7
	line	264
;Display.c: 264: while(WA==0);
	
l2252:	
	btfss	(15508/8)^0780h,(15508)&7
	goto	u7931
	goto	u7930
u7931:
	goto	l2252
u7930:
	
l2254:	
	line	265
;Display.c: 265: SEG21COM2=1;
	bsf	(15685/8)^0780h,(15685)&7
	line	266
;Display.c: 266: while(WA==0);
	
l2255:	
	btfss	(15508/8)^0780h,(15508)&7
	goto	u7941
	goto	u7940
u7941:
	goto	l2255
u7940:
	
l2257:	
	line	267
;Display.c: 267: SEG21COM1=1;
	bsf	(15661/8)^0780h,(15661)&7
	line	268
;Display.c: 268: while(WA==0);
	
l2258:	
	btfss	(15508/8)^0780h,(15508)&7
	goto	u7951
	goto	u7950
u7951:
	goto	l2258
u7950:
	
l2260:	
	line	269
;Display.c: 269: SEG21COM0=1;
	bsf	(15637/8)^0780h,(15637)&7
	line	270
;Display.c: 270: }
	goto	l2325
	line	271
	
l32834:	
;Display.c: 271: else if(x==1)
	decf	(LcdDisplayAll@x),w
	skipz
	goto	u7961
	goto	u7960
u7961:
	goto	l32840
u7960:
	line	273
	
l32836:	
;Display.c: 272: {
;Display.c: 273: DpyNum[0]=0;
	clrf	(_DpyNum)
	line	274
;Display.c: 274: DpyNum[1]=0;
	clrf	0+(_DpyNum)+01h
	line	275
;Display.c: 275: DpyNum[2]=0;
	clrf	0+(_DpyNum)+02h
	line	276
	
l32838:	
;Display.c: 276: LcdDisplayNum();
	fcall	_LcdDisplayNum
	line	277
;Display.c: 277: while(WA==0);
	
l2263:	
	btfss	(15508/8)^0780h,(15508)&7
	goto	u7971
	goto	u7970
u7971:
	goto	l2263
u7970:
	
l2265:	
	line	278
;Display.c: 278: SEG5COM0=0;
	bcf	(15621/8)^0780h,(15621)&7
	line	279
;Display.c: 279: while(WA==0);
	
l2266:	
	btfss	(15508/8)^0780h,(15508)&7
	goto	u7981
	goto	u7980
u7981:
	goto	l2266
u7980:
	
l2268:	
	line	280
;Display.c: 280: SEG5COM1=0;
	bcf	(15645/8)^0780h,(15645)&7
	line	281
;Display.c: 281: while(WA==0);
	
l2269:	
	btfss	(15508/8)^0780h,(15508)&7
	goto	u7991
	goto	u7990
u7991:
	goto	l2269
u7990:
	
l2271:	
	line	282
;Display.c: 282: SEG5COM2=0;
	bcf	(15669/8)^0780h,(15669)&7
	line	283
;Display.c: 283: while(WA==0);
	
l2272:	
	btfss	(15508/8)^0780h,(15508)&7
	goto	u8001
	goto	u8000
u8001:
	goto	l2272
u8000:
	
l2274:	
	line	284
;Display.c: 284: SEG5COM3=0;
	bcf	(15693/8)^0780h,(15693)&7
	line	285
;Display.c: 285: while(WA==0);
	
l2275:	
	btfss	(15508/8)^0780h,(15508)&7
	goto	u8011
	goto	u8010
u8011:
	goto	l2275
u8010:
	
l2277:	
	line	286
;Display.c: 286: SEG22COM3=0;
	bcf	(15710/8)^0780h,(15710)&7
	line	287
;Display.c: 287: while(WA==0);
	
l2278:	
	btfss	(15508/8)^0780h,(15508)&7
	goto	u8021
	goto	u8020
u8021:
	goto	l2278
u8020:
	
l2280:	
	line	288
;Display.c: 288: SEG3COM3=0;
	bcf	(15691/8)^0780h,(15691)&7
	line	289
;Display.c: 289: while(WA==0);
	
l2281:	
	btfss	(15508/8)^0780h,(15508)&7
	goto	u8031
	goto	u8030
u8031:
	goto	l2281
u8030:
	
l2283:	
	line	290
;Display.c: 290: SEG21COM3=0;
	bcf	(15709/8)^0780h,(15709)&7
	line	291
;Display.c: 291: while(WA==0);
	
l2284:	
	btfss	(15508/8)^0780h,(15508)&7
	goto	u8041
	goto	u8040
u8041:
	goto	l2284
u8040:
	
l2286:	
	line	292
;Display.c: 292: SEG21COM2=0;
	bcf	(15685/8)^0780h,(15685)&7
	line	293
;Display.c: 293: while(WA==0);
	
l2287:	
	btfss	(15508/8)^0780h,(15508)&7
	goto	u8051
	goto	u8050
u8051:
	goto	l2287
u8050:
	
l2289:	
	line	294
;Display.c: 294: SEG21COM1=0;
	bcf	(15661/8)^0780h,(15661)&7
	line	295
;Display.c: 295: while(WA==0);
	
l2290:	
	btfss	(15508/8)^0780h,(15508)&7
	goto	u8061
	goto	u8060
u8061:
	goto	l2290
u8060:
	
l2292:	
	line	296
;Display.c: 296: SEG21COM0=0;
	bcf	(15637/8)^0780h,(15637)&7
	line	297
;Display.c: 297: }
	goto	l2325
	line	298
	
l32840:	
;Display.c: 298: else if(x==2)
	movf	(LcdDisplayAll@x),w
	xorlw	02h&0ffh
	skipz
	goto	u8071
	goto	u8070
u8071:
	goto	l2325
u8070:
	line	300
	
l32842:	
;Display.c: 299: {
;Display.c: 300: DpyNum[0]=0x01 | 0x02 | 0x04 | 0x10 | 0x20 | 0x40;
	movlw	(077h)
	movwf	(_DpyNum)
	line	301
;Display.c: 301: DpyNum[1]=0x01 | 0x02 | 0x04 | 0x10 | 0x20 | 0x40;
	movlw	(077h)
	movwf	0+(_DpyNum)+01h
	line	302
;Display.c: 302: DpyNum[2]=0x01 | 0x02 | 0x04 | 0x10 | 0x20 | 0x40;
	movlw	(077h)
	movwf	0+(_DpyNum)+02h
	line	303
	
l32844:	
;Display.c: 303: LcdDisplayNum();
	fcall	_LcdDisplayNum
	line	304
;Display.c: 304: while(WA==0);
	
l2295:	
	btfss	(15508/8)^0780h,(15508)&7
	goto	u8081
	goto	u8080
u8081:
	goto	l2295
u8080:
	
l2297:	
	line	305
;Display.c: 305: SEG5COM0=0;
	bcf	(15621/8)^0780h,(15621)&7
	line	306
;Display.c: 306: while(WA==0);
	
l2298:	
	btfss	(15508/8)^0780h,(15508)&7
	goto	u8091
	goto	u8090
u8091:
	goto	l2298
u8090:
	
l2300:	
	line	307
;Display.c: 307: SEG5COM1=0;
	bcf	(15645/8)^0780h,(15645)&7
	line	308
;Display.c: 308: while(WA==0);
	
l2301:	
	btfss	(15508/8)^0780h,(15508)&7
	goto	u8101
	goto	u8100
u8101:
	goto	l2301
u8100:
	
l2303:	
	line	309
;Display.c: 309: SEG5COM2=0;
	bcf	(15669/8)^0780h,(15669)&7
	line	310
;Display.c: 310: while(WA==0);
	
l2304:	
	btfss	(15508/8)^0780h,(15508)&7
	goto	u8111
	goto	u8110
u8111:
	goto	l2304
u8110:
	
l2306:	
	line	311
;Display.c: 311: SEG5COM3=0;
	bcf	(15693/8)^0780h,(15693)&7
	line	312
;Display.c: 312: while(WA==0);
	
l2307:	
	btfss	(15508/8)^0780h,(15508)&7
	goto	u8121
	goto	u8120
u8121:
	goto	l2307
u8120:
	
l2309:	
	line	313
;Display.c: 313: SEG22COM3=0;
	bcf	(15710/8)^0780h,(15710)&7
	line	314
;Display.c: 314: while(WA==0);
	
l2310:	
	btfss	(15508/8)^0780h,(15508)&7
	goto	u8131
	goto	u8130
u8131:
	goto	l2310
u8130:
	
l2312:	
	line	315
;Display.c: 315: SEG3COM3=0;
	bcf	(15691/8)^0780h,(15691)&7
	line	316
;Display.c: 316: while(WA==0);
	
l2313:	
	btfss	(15508/8)^0780h,(15508)&7
	goto	u8141
	goto	u8140
u8141:
	goto	l2313
u8140:
	
l2315:	
	line	317
;Display.c: 317: SEG21COM3=0;
	bcf	(15709/8)^0780h,(15709)&7
	line	318
;Display.c: 318: while(WA==0);
	
l2316:	
	btfss	(15508/8)^0780h,(15508)&7
	goto	u8151
	goto	u8150
u8151:
	goto	l2316
u8150:
	
l2318:	
	line	319
;Display.c: 319: SEG21COM2=0;
	bcf	(15685/8)^0780h,(15685)&7
	line	320
;Display.c: 320: while(WA==0);
	
l2319:	
	btfss	(15508/8)^0780h,(15508)&7
	goto	u8161
	goto	u8160
u8161:
	goto	l2319
u8160:
	
l2321:	
	line	321
;Display.c: 321: SEG21COM1=0;
	bcf	(15661/8)^0780h,(15661)&7
	line	322
;Display.c: 322: while(WA==0);
	
l2322:	
	btfss	(15508/8)^0780h,(15508)&7
	goto	u8171
	goto	u8170
u8171:
	goto	l2322
u8170:
	goto	l2292
	line	325
	
l2325:	
	return
	opt stack 0
GLOBAL	__end_of_LcdDisplayAll
	__end_of_LcdDisplayAll:
;; =============== function _LcdDisplayAll ends ============

	signat	_LcdDisplayAll,4216
	global	___lbmod
psect	text2044,local,class=CODE,delta=2
global __ptext2044
__ptext2044:

;; *************** function ___lbmod *****************
;; Defined at:
;;		line 5 in file "C:\Program Files (x86)\HI-TECH Software\PICC\9.71a\sources\lbmod.c"
;; Parameters:    Size  Location     Type
;;  dividend        1    wreg     unsigned char 
;;  divisor         1    0[BANK0 ] unsigned char 
;; Auto vars:     Size  Location     Type
;;  dividend        1    2[BANK0 ] unsigned char 
;;  rem             1    4[BANK0 ] unsigned char 
;;  counter         1    3[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;                  1    wreg      unsigned char 
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 1F/0
;;		On exit  : 1F/0
;;		Unchanged: FFFE0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       1       0       0       0       0       0       0
;;      Locals:         0       3       0       0       0       0       0       0
;;      Temps:          0       1       0       0       0       0       0       0
;;      Totals:         0       5       0       0       0       0       0       0
;;Total ram usage:        5 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    3
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_LcdDisplay_CSQ
;;		_LcdDisplay_CurTemp
;;		_LcdDisplay_Err
;; This function uses a non-reentrant model
;;
psect	text2044
	file	"C:\Program Files (x86)\HI-TECH Software\PICC\9.71a\sources\lbmod.c"
	line	5
	global	__size_of___lbmod
	__size_of___lbmod	equ	__end_of___lbmod-___lbmod
	
___lbmod:	
	opt	stack 11
; Regs used in ___lbmod: [wreg+status,2+status,0]
;___lbmod@dividend stored from wreg
	line	9
	movwf	(___lbmod@dividend)
	
l31020:	
	movlw	(08h)
	movwf	(___lbmod@counter)
	line	10
	
l31022:	
	clrf	(___lbmod@rem)
	line	12
	
l31024:	
	movf	(___lbmod@dividend),w
	movwf	(??___lbmod+0)+0
	movlw	07h
u4635:
	lsrf	(??___lbmod+0)+0,f
	decfsz	wreg,f
	goto	u4635
	lslf	(___lbmod@rem),w
	iorwf	0+(??___lbmod+0)+0,w
	movwf	(___lbmod@rem)
	line	13
	
l31026:	
	lslf	(___lbmod@dividend),f
	line	14
	
l31028:	
	movf	(___lbmod@divisor),w
	subwf	(___lbmod@rem),w
	skipc
	goto	u4641
	goto	u4640
u4641:
	goto	l31032
u4640:
	line	15
	
l31030:	
	movf	(___lbmod@divisor),w
	subwf	(___lbmod@rem),f
	line	16
	
l31032:	
	decfsz	(___lbmod@counter),f
	goto	u4651
	goto	u4650
u4651:
	goto	l31024
u4650:
	line	17
	
l31034:	
	movf	(___lbmod@rem),w
	line	18
	
l27826:	
	return
	opt stack 0
GLOBAL	__end_of___lbmod
	__end_of___lbmod:
;; =============== function ___lbmod ends ============

	signat	___lbmod,8313
	global	___lbdiv
psect	text2045,local,class=CODE,delta=2
global __ptext2045
__ptext2045:

;; *************** function ___lbdiv *****************
;; Defined at:
;;		line 5 in file "C:\Program Files (x86)\HI-TECH Software\PICC\9.71a\sources\lbdiv.c"
;; Parameters:    Size  Location     Type
;;  dividend        1    wreg     unsigned char 
;;  divisor         1    0[BANK0 ] unsigned char 
;; Auto vars:     Size  Location     Type
;;  dividend        1    1[BANK0 ] unsigned char 
;;  quotient        1    3[BANK0 ] unsigned char 
;;  counter         1    2[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;                  1    wreg      unsigned char 
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 1F/0
;;		On exit  : 1F/0
;;		Unchanged: FFFE0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       1       0       0       0       0       0       0
;;      Locals:         0       3       0       0       0       0       0       0
;;      Temps:          0       0       0       0       0       0       0       0
;;      Totals:         0       4       0       0       0       0       0       0
;;Total ram usage:        4 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    3
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_LcdDisplay_CSQ
;;		_LcdDisplay_CurTemp
;;		_LcdDisplay_Err
;; This function uses a non-reentrant model
;;
psect	text2045
	file	"C:\Program Files (x86)\HI-TECH Software\PICC\9.71a\sources\lbdiv.c"
	line	5
	global	__size_of___lbdiv
	__size_of___lbdiv	equ	__end_of___lbdiv-___lbdiv
	
___lbdiv:	
	opt	stack 11
; Regs used in ___lbdiv: [wreg+status,2+status,0]
;___lbdiv@dividend stored from wreg
	line	9
	movwf	(___lbdiv@dividend)
	
l32804:	
	clrf	(___lbdiv@quotient)
	line	10
	
l32806:	
	movf	(___lbdiv@divisor),w
	skipz
	goto	u7810
	goto	l32824
u7810:
	line	11
	
l32808:	
	clrf	(___lbdiv@counter)
	incf	(___lbdiv@counter),f
	line	12
	goto	l32812
	
l27815:	
	line	13
	lslf	(___lbdiv@divisor),f
	line	14
	
l32810:	
	incf	(___lbdiv@counter),f
	line	12
	
l32812:	
	btfss	(___lbdiv@divisor),(7)&7
	goto	u7821
	goto	u7820
u7821:
	goto	l27815
u7820:
	line	16
	
l27817:	
	line	17
	lslf	(___lbdiv@quotient),f
	line	18
	
l32814:	
	movf	(___lbdiv@divisor),w
	subwf	(___lbdiv@dividend),w
	skipc
	goto	u7831
	goto	u7830
u7831:
	goto	l32820
u7830:
	line	19
	
l32816:	
	movf	(___lbdiv@divisor),w
	subwf	(___lbdiv@dividend),f
	line	20
	
l32818:	
	bsf	(___lbdiv@quotient)+(0/8),(0)&7
	line	22
	
l32820:	
	lsrf	(___lbdiv@divisor),f
	line	23
	
l32822:	
	decfsz	(___lbdiv@counter),f
	goto	u7841
	goto	u7840
u7841:
	goto	l27817
u7840:
	line	25
	
l32824:	
	movf	(___lbdiv@quotient),w
	line	26
	
l27820:	
	return
	opt stack 0
GLOBAL	__end_of___lbdiv
	__end_of___lbdiv:
;; =============== function ___lbdiv ends ============

	signat	___lbdiv,8313
	global	___wmul
psect	text2046,local,class=CODE,delta=2
global __ptext2046
__ptext2046:

;; *************** function ___wmul *****************
;; Defined at:
;;		line 3 in file "C:\Program Files (x86)\HI-TECH Software\PICC\9.71a\sources\wmul.c"
;; Parameters:    Size  Location     Type
;;  multiplier      2    0[BANK0 ] unsigned int 
;;  multiplicand    2    2[BANK0 ] unsigned int 
;; Auto vars:     Size  Location     Type
;;  product         2    4[BANK0 ] unsigned int 
;; Return value:  Size  Location     Type
;;                  2    0[BANK0 ] unsigned int 
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 1F/0
;;		On exit  : 1F/0
;;		Unchanged: FFFE0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       4       0       0       0       0       0       0
;;      Locals:         0       2       0       0       0       0       0       0
;;      Temps:          0       0       0       0       0       0       0       0
;;      Totals:         0       6       0       0       0       0       0       0
;;Total ram usage:        6 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    3
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_atoi
;; This function uses a non-reentrant model
;;
psect	text2046
	file	"C:\Program Files (x86)\HI-TECH Software\PICC\9.71a\sources\wmul.c"
	line	3
	global	__size_of___wmul
	__size_of___wmul	equ	__end_of___wmul-___wmul
	
___wmul:	
	opt	stack 9
; Regs used in ___wmul: [wreg+status,2+status,0]
	line	4
	
l32788:	
	clrf	(___wmul@product)
	clrf	(___wmul@product+1)
	line	7
	
l32790:	
	btfss	(___wmul@multiplier),(0)&7
	goto	u7791
	goto	u7790
u7791:
	goto	l32794
u7790:
	line	8
	
l32792:	
	movf	(___wmul@multiplicand),w
	addwf	(___wmul@product),f
	movf	(___wmul@multiplicand+1),w
	addwfc	(___wmul@product+1),f
	line	9
	
l32794:	
	lslf	(___wmul@multiplicand),f
	rlf	(___wmul@multiplicand+1),f
	line	10
	
l32796:	
	lsrf	(___wmul@multiplier+1),f
	rrf	(___wmul@multiplier),f
	line	11
	
l32798:	
	movf	((___wmul@multiplier+1)),w
	iorwf	((___wmul@multiplier)),w
	skipz
	goto	u7801
	goto	u7800
u7801:
	goto	l32790
u7800:
	line	12
	
l32800:	
	movf	(___wmul@product+1),w
	movwf	(?___wmul+1)
	movf	(___wmul@product),w
	movwf	(?___wmul)
	line	13
	
l27790:	
	return
	opt stack 0
GLOBAL	__end_of___wmul
	__end_of___wmul:
;; =============== function ___wmul ends ============

	signat	___wmul,8314
	global	___bmul
psect	text2047,local,class=CODE,delta=2
global __ptext2047
__ptext2047:

;; *************** function ___bmul *****************
;; Defined at:
;;		line 3 in file "C:\Program Files (x86)\HI-TECH Software\PICC\9.71a\sources\bmul.c"
;; Parameters:    Size  Location     Type
;;  multiplier      1    wreg     unsigned char 
;;  multiplicand    1    0[BANK0 ] unsigned char 
;; Auto vars:     Size  Location     Type
;;  multiplier      1    2[BANK0 ] unsigned char 
;;  product         1    1[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;                  1    wreg      unsigned char 
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 1F/0
;;		On exit  : 1F/0
;;		Unchanged: FFFE0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       1       0       0       0       0       0       0
;;      Locals:         0       2       0       0       0       0       0       0
;;      Temps:          0       0       0       0       0       0       0       0
;;      Totals:         0       3       0       0       0       0       0       0
;;Total ram usage:        3 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    3
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_main
;;		_InteractServer
;; This function uses a non-reentrant model
;;
psect	text2047
	file	"C:\Program Files (x86)\HI-TECH Software\PICC\9.71a\sources\bmul.c"
	line	3
	global	__size_of___bmul
	__size_of___bmul	equ	__end_of___bmul-___bmul
	
___bmul:	
	opt	stack 13
; Regs used in ___bmul: [wreg+status,2+status,0]
;___bmul@multiplier stored from wreg
	movwf	(___bmul@multiplier)
	line	4
	
l32772:	
	clrf	(___bmul@product)
	line	7
	
l32774:	
	btfss	(___bmul@multiplier),(0)&7
	goto	u7771
	goto	u7770
u7771:
	goto	l32778
u7770:
	line	8
	
l32776:	
	movf	(___bmul@multiplicand),w
	addwf	(___bmul@product),f
	line	9
	
l32778:	
	lslf	(___bmul@multiplicand),f
	line	10
	
l32780:	
	lsrf	(___bmul@multiplier),f
	line	11
	
l32782:	
	movf	(___bmul@multiplier),f
	skipz
	goto	u7781
	goto	u7780
u7781:
	goto	l32774
u7780:
	line	12
	
l32784:	
	movf	(___bmul@product),w
	line	13
	
l27784:	
	return
	opt stack 0
GLOBAL	__end_of___bmul
	__end_of___bmul:
;; =============== function ___bmul ends ============

	signat	___bmul,8313
	global	_strchr
psect	text2048,local,class=CODE,delta=2
global __ptext2048
__ptext2048:

;; *************** function _strchr *****************
;; Defined at:
;;		line 5 in file "C:\Program Files (x86)\HI-TECH Software\PICC\9.71a\sources\strchr.c"
;; Parameters:    Size  Location     Type
;;  ptr             2    0[BANK0 ] PTR const unsigned char 
;;		 -> ATCommand_RxList(100), RAM(128), 
;;  chr             2    2[BANK0 ] int 
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  2    wreg      PTR unsigned char 
;; Registers used:
;;		wreg, fsr1l, fsr1h, status,2, status,0
;; Tracked objects:
;;		On entry : 1F/0
;;		On exit  : 1F/0
;;		Unchanged: FFFE0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       4       0       0       0       0       0       0
;;      Locals:         0       0       0       0       0       0       0       0
;;      Temps:          0       2       0       0       0       0       0       0
;;      Totals:         0       6       0       0       0       0       0       0
;;Total ram usage:        6 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    3
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_strstr
;; This function uses a non-reentrant model
;;
psect	text2048
	file	"C:\Program Files (x86)\HI-TECH Software\PICC\9.71a\sources\strchr.c"
	line	5
	global	__size_of_strchr
	__size_of_strchr	equ	__end_of_strchr-_strchr
	
_strchr:	
	opt	stack 10
; Regs used in _strchr: [wreg+fsr1l-status,0]
	line	6
	
l28119:	
	line	7
	
l30954:	
	movf	(strchr@ptr),w
	movwf	fsr1l
	movf	(strchr@ptr+1),w
	movwf	fsr1h

	movf	indf1,w
	xorwf	(strchr@chr),w
	skipz
	goto	u4531
	goto	u4530
u4531:
	goto	l30958
u4530:
	line	8
	
l30956:	
	goto	l28121
	line	9
	
l30958:	
	movf	(strchr@ptr+1),w
	movwf	(??_strchr+0)+0+1
	movf	(strchr@ptr),w
	movwf	(??_strchr+0)+0
	incf	(strchr@ptr),f
	skipnz
	incf	(strchr@ptr+1),f
	movf	0+(??_strchr+0)+0,w
	movwf	fsr1l
	movf	1+(??_strchr+0)+0,w
	movwf	fsr1h

	movf	indf1,f
	skipz
	goto	u4541
	goto	u4540
u4541:
	goto	l28119
u4540:
	line	10
	
l30960:	
	clrf	(?_strchr)
	clrf	(?_strchr+1)
	line	11
	
l28121:	
	return
	opt stack 0
GLOBAL	__end_of_strchr
	__end_of_strchr:
;; =============== function _strchr ends ============

	signat	_strchr,8313
	global	_strncmp
psect	text2049,local,class=CODE,delta=2
global __ptext2049
__ptext2049:

;; *************** function _strncmp *****************
;; Defined at:
;;		line 5 in file "C:\Program Files (x86)\HI-TECH Software\PICC\9.71a\sources\strncmp.c"
;; Parameters:    Size  Location     Type
;;  s1              2    6[BANK0 ] PTR const unsigned char 
;;		 -> ATCommand_RxList(100), RAM(128), 
;;  s2              2    8[BANK0 ] PTR const unsigned char 
;;		 -> STR_44(5), STR_33(12), STR_32(12), STR_30(7), 
;;		 -> STR_26(9), ATCommand_ErrString(15), STR_5(5), ATCommand_OkString(15), 
;;  len             2   10[BANK0 ] unsigned int 
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  2    6[BANK0 ] int 
;; Registers used:
;;		wreg, fsr0l, fsr0h, fsr1l, fsr1h, status,2, status,0, pclath
;; Tracked objects:
;;		On entry : 1F/0
;;		On exit  : 1F/0
;;		Unchanged: FFFE0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       6       0       0       0       0       0       0
;;      Locals:         0       0       0       0       0       0       0       0
;;      Temps:          0       1       0       0       0       0       0       0
;;      Totals:         0       7       0       0       0       0       0       0
;;Total ram usage:        7 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    3
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_strstr
;; This function uses a non-reentrant model
;;
psect	text2049
	file	"C:\Program Files (x86)\HI-TECH Software\PICC\9.71a\sources\strncmp.c"
	line	5
	global	__size_of_strncmp
	__size_of_strncmp	equ	__end_of_strncmp-_strncmp
	
_strncmp:	
	opt	stack 10
; Regs used in _strncmp: [wreg-status,0+pclath]
	line	6
	
l30936:	
	goto	l30948
	line	7
	
l30938:	
	movf	(strncmp@s1),w
	movwf	fsr1l
	movf	(strncmp@s1+1),w
	movwf	fsr1h

	movf	indf1,w
	xorlw	0&0ffh
	skipnz
	goto	u4501
	goto	u4500
u4501:
	goto	l30942
u4500:
	
l30940:	
	movf	(strncmp@s2),w
	movwf	fsr0l
	movf	((strncmp@s2+1)),w
	movwf	fsr0h
	movf	indf0,w ;code access
	movwf	(??_strncmp+0)+0
	movf	(strncmp@s1),w
	movwf	fsr1l
	movf	(strncmp@s1+1),w
	movwf	fsr1h

	movf	indf1,w
	xorwf	(??_strncmp+0)+0,w
	skipnz
	goto	u4511
	goto	u4510
u4511:
	goto	l30946
u4510:
	line	8
	
l30942:	
	movf	(strncmp@s1),w
	movwf	fsr1l
	movf	(strncmp@s1+1),w
	movwf	fsr1h

	movf	(strncmp@s2),w
	movwf	fsr0l
	movf	((strncmp@s2+1)),w
	movwf	fsr0h
	movf	indf0,w ;code access
	subwf	indf1,w
	movwf	(?_strncmp)
	clrf	(?_strncmp)+1
	skipc
	decf	1+(?_strncmp),f
	
	goto	l28136
	line	10
	
l30946:	
	incf	(strncmp@s1),f
	skipnz
	incf	(strncmp@s1+1),f
	line	11
	incf	(strncmp@s2),f
	skipnz
	incf	(strncmp@s2+1),f
	line	6
	
l30948:	
	movlw	low(01h)
	subwf	(strncmp@len),f
	movlw	high(01h)
	subwfb	(strncmp@len+1),f
	incf	((strncmp@len)),w
	skipnz
	incf	((strncmp@len+1)),w

	skipz
	goto	u4521
	goto	u4520
u4521:
	goto	l30938
u4520:
	line	13
	
l30950:	
	clrf	(?_strncmp)
	clrf	(?_strncmp+1)
	line	14
	
l28136:	
	return
	opt stack 0
GLOBAL	__end_of_strncmp
	__end_of_strncmp:
;; =============== function _strncmp ends ============

	signat	_strncmp,12410
	global	_strlen
psect	text2050,local,class=CODE,delta=2
global __ptext2050
__ptext2050:

;; *************** function _strlen *****************
;; Defined at:
;;		line 5 in file "C:\Program Files (x86)\HI-TECH Software\PICC\9.71a\sources\strlen.c"
;; Parameters:    Size  Location     Type
;;  s               2    0[BANK0 ] PTR const unsigned char 
;;		 -> STR_44(5), STR_33(12), STR_32(12), STR_30(7), 
;;		 -> STR_26(9), ATCommand_ErrString(15), STR_5(5), ATCommand_OkString(15), 
;; Auto vars:     Size  Location     Type
;;  cp              2    4[BANK0 ] PTR const unsigned char 
;;		 -> STR_44(5), STR_33(12), STR_32(12), STR_30(7), 
;;		 -> STR_26(9), ATCommand_ErrString(15), STR_5(5), ATCommand_OkString(15), 
;; Return value:  Size  Location     Type
;;                  2    0[BANK0 ] unsigned int 
;; Registers used:
;;		wreg, fsr0l, fsr0h, status,2, status,0, pclath
;; Tracked objects:
;;		On entry : 1F/0
;;		On exit  : 1F/0
;;		Unchanged: FFFE0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       2       0       0       0       0       0       0
;;      Locals:         0       2       0       0       0       0       0       0
;;      Temps:          0       2       0       0       0       0       0       0
;;      Totals:         0       6       0       0       0       0       0       0
;;Total ram usage:        6 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    3
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_strstr
;; This function uses a non-reentrant model
;;
psect	text2050
	file	"C:\Program Files (x86)\HI-TECH Software\PICC\9.71a\sources\strlen.c"
	line	5
	global	__size_of_strlen
	__size_of_strlen	equ	__end_of_strlen-_strlen
	
_strlen:	
	opt	stack 10
; Regs used in _strlen: [wreg-fsr0h+status,2+status,0+pclath]
	line	8
	
l30928:	
	movf	(strlen@s+1),w
	movwf	(strlen@cp+1)
	movf	(strlen@s),w
	movwf	(strlen@cp)
	line	9
	
l30930:	
	movf	(strlen@cp+1),w
	movwf	(??_strlen+0)+0+1
	movf	(strlen@cp),w
	movwf	(??_strlen+0)+0
	incf	(strlen@cp),f
	skipnz
	incf	(strlen@cp+1),f
	movf	0+(??_strlen+0)+0,w
	movwf	fsr0l
	movf	(1+(??_strlen+0)+0),w
	movwf	fsr0h
	movf	indf0,w ;code access
	iorlw	0
	skipz
	goto	u4491
	goto	u4490
u4491:
	goto	l30930
u4490:
	line	11
	
l30932:	
	movf	(strlen@s),w
	subwf	(strlen@cp),w
	movwf	(??_strlen+0)+0
	movf	(strlen@s+1),w
	subwfb	(strlen@cp+1),w
	movwf	1+(??_strlen+0)+0
	movf	0+(??_strlen+0)+0,w
	addlw	low(-1)
	movwf	(?_strlen)
	movlw	high(-1)
	addwfc	1+(??_strlen+0)+0,w
	movwf	1+(?_strlen)
	line	12
	
l28128:	
	return
	opt stack 0
GLOBAL	__end_of_strlen
	__end_of_strlen:
;; =============== function _strlen ends ============

	signat	_strlen,4218
	global	_isdigit
psect	text2051,local,class=CODE,delta=2
global __ptext2051
__ptext2051:

;; *************** function _isdigit *****************
;; Defined at:
;;		line 13 in file "C:\Program Files (x86)\HI-TECH Software\PICC\9.71a\sources\isdigit.c"
;; Parameters:    Size  Location     Type
;;  c               1    wreg     unsigned char 
;; Auto vars:     Size  Location     Type
;;  c               1    1[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 1F/0
;;		On exit  : 1F/0
;;		Unchanged: FFFE0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       0       0       0       0       0       0       0
;;      Locals:         0       2       0       0       0       0       0       0
;;      Temps:          0       0       0       0       0       0       0       0
;;      Totals:         0       2       0       0       0       0       0       0
;;Total ram usage:        2 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    3
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_atoi
;; This function uses a non-reentrant model
;;
psect	text2051
	file	"C:\Program Files (x86)\HI-TECH Software\PICC\9.71a\sources\isdigit.c"
	line	13
	global	__size_of_isdigit
	__size_of_isdigit	equ	__end_of_isdigit-_isdigit
	
_isdigit:	
	opt	stack 9
; Regs used in _isdigit: [wreg+status,2+status,0]
;isdigit@c stored from wreg
	movwf	(isdigit@c)
	line	14
	
l32760:	
	clrf	(_isdigit$31842)
	
l32762:	
	movlw	(03Ah)
	subwf	(isdigit@c),w
	skipnc
	goto	u7751
	goto	u7750
u7751:
	goto	l32768
u7750:
	
l32764:	
	movlw	(030h)
	subwf	(isdigit@c),w
	skipc
	goto	u7761
	goto	u7760
u7761:
	goto	l32768
u7760:
	
l32766:	
	clrf	(_isdigit$31842)
	incf	(_isdigit$31842),f
	
l32768:	
	rrf	(_isdigit$31842),w
	
	line	15
	
l27752:	
	return
	opt stack 0
GLOBAL	__end_of_isdigit
	__end_of_isdigit:
;; =============== function _isdigit ends ============

	signat	_isdigit,4216
	global	_SimI2C_Init
psect	text2052,local,class=CODE,delta=2
global __ptext2052
__ptext2052:

;; *************** function _SimI2C_Init *****************
;; Defined at:
;;		line 3 in file "F:\work\WYP\NBIoT\SimI2C.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		None
;; Tracked objects:
;;		On entry : 1F/0
;;		On exit  : 1F/2
;;		Unchanged: FFFE0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       0       0       0       0       0       0       0
;;      Locals:         0       0       0       0       0       0       0       0
;;      Temps:          0       0       0       0       0       0       0       0
;;      Totals:         0       0       0       0       0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    3
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_TCN75_Init
;; This function uses a non-reentrant model
;;
psect	text2052
	file	"F:\work\WYP\NBIoT\SimI2C.c"
	line	3
	global	__size_of_SimI2C_Init
	__size_of_SimI2C_Init	equ	__end_of_SimI2C_Init-_SimI2C_Init
	
_SimI2C_Init:	
	opt	stack 11
; Regs used in _SimI2C_Init: []
	line	4
	
l32758:	
;SimI2C.c: 4: TRISD7=0;
	movlb 1	; select bank1
	bcf	(1151/8)^080h,(1151)&7
	line	5
;SimI2C.c: 5: TRISD6=0;
	bcf	(1150/8)^080h,(1150)&7
	line	13
;SimI2C.c: 13: LATD7=1;
	movlb 2	; select bank2
	bsf	(2175/8)^0100h,(2175)&7
	line	14
;SimI2C.c: 14: LATD6=1;
	bsf	(2174/8)^0100h,(2174)&7
	line	15
	
l27663:	
	return
	opt stack 0
GLOBAL	__end_of_SimI2C_Init
	__end_of_SimI2C_Init:
;; =============== function _SimI2C_Init ends ============

	signat	_SimI2C_Init,88
	global	_GetVerify_CRC8
psect	text2053,local,class=CODE,delta=2
global __ptext2053
__ptext2053:

;; *************** function _GetVerify_CRC8 *****************
;; Defined at:
;;		line 90 in file "F:\work\WYP\NBIoT\Verify.c"
;; Parameters:    Size  Location     Type
;;  pBuff           1    wreg     PTR unsigned char 
;;		 -> DS18X20_Scratchpad(9), 
;;  Count           2    0[BANK0 ] unsigned int 
;; Auto vars:     Size  Location     Type
;;  pBuff           1    3[BANK0 ] PTR unsigned char 
;;		 -> DS18X20_Scratchpad(9), 
;;  i               2    6[BANK0 ] unsigned int 
;;  crc             1    9[BANK0 ] unsigned char 
;;  feedback_bit    1    8[BANK0 ] unsigned char 
;;  data            1    5[BANK0 ] unsigned char 
;;  bit_counter     1    4[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;                  1    wreg      unsigned char 
;; Registers used:
;;		wreg, fsr1l, fsr1h, status,2, status,0
;; Tracked objects:
;;		On entry : 1F/0
;;		On exit  : 1F/0
;;		Unchanged: FFFE0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       2       0       0       0       0       0       0
;;      Locals:         0       7       0       0       0       0       0       0
;;      Temps:          0       1       0       0       0       0       0       0
;;      Totals:         0      10       0       0       0       0       0       0
;;Total ram usage:       10 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    3
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_DS18X20_ReadMeas
;; This function uses a non-reentrant model
;;
psect	text2053
	file	"F:\work\WYP\NBIoT\Verify.c"
	line	90
	global	__size_of_GetVerify_CRC8
	__size_of_GetVerify_CRC8	equ	__end_of_GetVerify_CRC8-_GetVerify_CRC8
	
_GetVerify_CRC8:	
	opt	stack 11
; Regs used in _GetVerify_CRC8: [wreg+fsr1l-status,0]
;GetVerify_CRC8@pBuff stored from wreg
	line	97
	movwf	(GetVerify_CRC8@pBuff)
	
l30882:	
;Verify.c: 91: unsigned char crc;
;Verify.c: 92: unsigned int i;
;Verify.c: 93: unsigned char bit_counter;
;Verify.c: 94: unsigned char data;
;Verify.c: 95: unsigned char feedback_bit;
;Verify.c: 97: crc = 0x00;
	clrf	(GetVerify_CRC8@crc)
	line	99
;Verify.c: 99: for(i = 0; i != Count; i++)
	clrf	(GetVerify_CRC8@i)
	clrf	(GetVerify_CRC8@i+1)
	goto	l30908
	line	101
	
l30884:	
;Verify.c: 100: {
;Verify.c: 101: data = pBuff[i];
	movf	(GetVerify_CRC8@i),w
	addwf	(GetVerify_CRC8@pBuff),w
	movwf	(??_GetVerify_CRC8+0)+0
	movf	0+(??_GetVerify_CRC8+0)+0,w
	movwf	fsr1l
	clrf fsr1h	
	
	movf	indf1,w
	movwf	(GetVerify_CRC8@data)
	line	102
	
l30886:	
;Verify.c: 102: bit_counter = 8;
	movlw	(08h)
	movwf	(GetVerify_CRC8@bit_counter)
	line	105
	
l30888:	
;Verify.c: 104: {
;Verify.c: 105: feedback_bit = (crc ^ data) & 0x01;
	movf	(GetVerify_CRC8@crc),w
	xorwf	(GetVerify_CRC8@data),w
	movwf	(GetVerify_CRC8@feedback_bit)
	
l30890:	
	movlw	(01h)
	andwf	(GetVerify_CRC8@feedback_bit),f
	line	106
	
l30892:	
;Verify.c: 106: if ( feedback_bit == 0x01 )
	decf	(GetVerify_CRC8@feedback_bit),w
	skipz
	goto	u4431
	goto	u4430
u4431:
	goto	l30896
u4430:
	line	107
	
l30894:	
;Verify.c: 107: crc = crc ^ 0x18;
	movlw	(018h)
	xorwf	(GetVerify_CRC8@crc),f
	line	108
	
l30896:	
;Verify.c: 108: crc = (crc >> 1) & 0x7F;
	lsrf	(GetVerify_CRC8@crc),f
	
l30898:	
	bcf	(GetVerify_CRC8@crc)+(7/8),(7)&7
	line	109
	
l30900:	
;Verify.c: 109: if ( feedback_bit == 0x01 )
	decf	(GetVerify_CRC8@feedback_bit),w
	skipz
	goto	u4441
	goto	u4440
u4441:
	goto	l25597
u4440:
	line	110
	
l30902:	
;Verify.c: 110: crc = crc | 0x80;
	bsf	(GetVerify_CRC8@crc)+(7/8),(7)&7
	
l25597:	
	line	111
;Verify.c: 111: data = data >> 1;
	lsrf	(GetVerify_CRC8@data),f
	line	112
	
l30904:	
;Verify.c: 112: bit_counter--;
	decf	(GetVerify_CRC8@bit_counter),f
	line	113
;Verify.c: 113: }while (bit_counter > 0);
	movf	(GetVerify_CRC8@bit_counter),f
	skipz
	goto	u4451
	goto	u4450
u4451:
	goto	l30888
u4450:
	line	99
	
l30906:	
	incf	(GetVerify_CRC8@i),f
	skipnz
	incf	(GetVerify_CRC8@i+1),f
	
l30908:	
	movf	(GetVerify_CRC8@Count+1),w
	xorwf	(GetVerify_CRC8@i+1),w
	skipz
	goto	u4465
	movf	(GetVerify_CRC8@Count),w
	xorwf	(GetVerify_CRC8@i),w
u4465:

	skipz
	goto	u4461
	goto	u4460
u4461:
	goto	l30884
u4460:
	line	115
	
l30910:	
;Verify.c: 114: }
;Verify.c: 115: return crc;
	movf	(GetVerify_CRC8@crc),w
	line	116
	
l25600:	
	return
	opt stack 0
GLOBAL	__end_of_GetVerify_CRC8
	__end_of_GetVerify_CRC8:
;; =============== function _GetVerify_CRC8 ends ============

	signat	_GetVerify_CRC8,8313
	global	_GetVerify_Sum
psect	text2054,local,class=CODE,delta=2
global __ptext2054
__ptext2054:

;; *************** function _GetVerify_Sum *****************
;; Defined at:
;;		line 79 in file "F:\work\WYP\NBIoT\Verify.c"
;; Parameters:    Size  Location     Type
;;  pBuff           1    wreg     PTR unsigned char 
;;		 -> RomParams(2), 
;;  Count           2    0[BANK0 ] unsigned int 
;; Auto vars:     Size  Location     Type
;;  pBuff           1    4[BANK0 ] PTR unsigned char 
;;		 -> RomParams(2), 
;;  i               1    6[BANK0 ] unsigned char 
;;  sum             1    5[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;                  1    wreg      unsigned char 
;; Registers used:
;;		wreg, fsr1l, fsr1h, status,2, status,0
;; Tracked objects:
;;		On entry : 1F/0
;;		On exit  : 1F/0
;;		Unchanged: FFFE0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       2       0       0       0       0       0       0
;;      Locals:         0       3       0       0       0       0       0       0
;;      Temps:          0       2       0       0       0       0       0       0
;;      Totals:         0       7       0       0       0       0       0       0
;;Total ram usage:        7 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    3
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_GetRomData
;;		_SaveRomData
;; This function uses a non-reentrant model
;;
psect	text2054
	file	"F:\work\WYP\NBIoT\Verify.c"
	line	79
	global	__size_of_GetVerify_Sum
	__size_of_GetVerify_Sum	equ	__end_of_GetVerify_Sum-_GetVerify_Sum
	
_GetVerify_Sum:	
	opt	stack 10
; Regs used in _GetVerify_Sum: [wreg+fsr1l-status,0]
;GetVerify_Sum@pBuff stored from wreg
	line	81
	movwf	(GetVerify_Sum@pBuff)
	
l30858:	
;Verify.c: 80: unsigned char sum,i;
;Verify.c: 81: sum=0;
	clrf	(GetVerify_Sum@sum)
	line	82
;Verify.c: 82: for(i=0;i<Count;i++)
	clrf	(GetVerify_Sum@i)
	goto	l30864
	line	84
	
l30860:	
;Verify.c: 83: {
;Verify.c: 84: sum=(unsigned char)(sum+pBuff[i]);
	movf	(GetVerify_Sum@i),w
	addwf	(GetVerify_Sum@pBuff),w
	movwf	(??_GetVerify_Sum+0)+0
	movf	0+(??_GetVerify_Sum+0)+0,w
	movwf	fsr1l
	clrf fsr1h	
	
	movf	indf1,w
	addwf	(GetVerify_Sum@sum),f
	line	82
	
l30862:	
	incf	(GetVerify_Sum@i),f
	
l30864:	
	movf	(GetVerify_Sum@i),w
	movwf	(??_GetVerify_Sum+0)+0
	clrf	(??_GetVerify_Sum+0)+0+1
	movf	(GetVerify_Sum@Count+1),w
	subwf	1+(??_GetVerify_Sum+0)+0,w
	skipz
	goto	u4405
	movf	(GetVerify_Sum@Count),w
	subwf	0+(??_GetVerify_Sum+0)+0,w
u4405:
	skipc
	goto	u4401
	goto	u4400
u4401:
	goto	l30860
u4400:
	line	86
	
l30866:	
;Verify.c: 85: }
;Verify.c: 86: return sum;
	movf	(GetVerify_Sum@sum),w
	line	87
	
l25590:	
	return
	opt stack 0
GLOBAL	__end_of_GetVerify_Sum
	__end_of_GetVerify_Sum:
;; =============== function _GetVerify_Sum ends ============

	signat	_GetVerify_Sum,8313
	global	_eeprom_read
psect	text2055,local,class=CODE,delta=2
global __ptext2055
__ptext2055:

;; *************** function _eeprom_read *****************
;; Defined at:
;;		line 8 in file "eeread.c"
;; Parameters:    Size  Location     Type
;;  addr            1    wreg     unsigned char 
;; Auto vars:     Size  Location     Type
;;  addr            1    2[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;                  1    wreg      unsigned char 
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 1F/0
;;		On exit  : 1F/3
;;		Unchanged: FFFE0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       0       0       0       0       0       0       0
;;      Locals:         0       1       0       0       0       0       0       0
;;      Temps:          0       2       0       0       0       0       0       0
;;      Totals:         0       3       0       0       0       0       0       0
;;Total ram usage:        3 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    3
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_InteractServer
;;		_GetRomData
;; This function uses a non-reentrant model
;;
psect	text2055
	file	"C:\Program Files (x86)\HI-TECH Software\PICC\9.71a\sources\eeread.c"
	line	8
	global	__size_of_eeprom_read
	__size_of_eeprom_read	equ	__end_of_eeprom_read-_eeprom_read
	
_eeprom_read:	
	opt	stack 10
; Regs used in _eeprom_read: [wreg+status,2+status,0]
;eeprom_read@addr stored from wreg
	line	10
	movwf	(eeprom_read@addr)
	line	9
	
l27704:	
	line	10
# 10 "C:\Program Files (x86)\HI-TECH Software\PICC\9.71a\sources\eeread.c"
clrwdt ;#
psect	text2055
	line	11
	movlb 3	; select bank3
	btfsc	(3241/8)^0180h,(3241)&7
	goto	u4391
	goto	u4390
u4391:
	goto	l27704
u4390:
	line	12
	
l30854:	
	movlb 0	; select bank0
	movf	(eeprom_read@addr),w
	movlb 3	; select bank3
	movwf	(401)^0180h	;volatile
	movlw	(03Fh)
	andwf	(405)^0180h,f	;volatile
	bsf	(3240/8)^0180h,(3240)&7
	clrc
	btfsc	(3240/8)^0180h,(3240)&7
	setc
	movlw	0
	addwfc	wreg,w
	movlb 0	; select bank0
	movwf	(??_eeprom_read+0)+0
	clrf	(??_eeprom_read+0)+0+1
	movlb 3	; select bank3
	movf	(403)^0180h,w	;volatile
	line	13
	
l27706:	
	return
	opt stack 0
GLOBAL	__end_of_eeprom_read
	__end_of_eeprom_read:
;; =============== function _eeprom_read ends ============

	signat	_eeprom_read,4217
	global	_MakeTxTemperature
psect	text2056,local,class=CODE,delta=2
global __ptext2056
__ptext2056:

;; *************** function _MakeTxTemperature *****************
;; Defined at:
;;		line 360 in file "F:\work\WYP\NBIoT\Function.c"
;; Parameters:    Size  Location     Type
;;  T               2    0[BANK0 ] struct .
;; Auto vars:     Size  Location     Type
;;  x               1    2[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 1F/0
;;		On exit  : 1F/0
;;		Unchanged: FFFE0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       2       0       0       0       0       0       0
;;      Locals:         0       1       0       0       0       0       0       0
;;      Temps:          0       0       0       0       0       0       0       0
;;      Totals:         0       3       0       0       0       0       0       0
;;Total ram usage:        3 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    3
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_InteractServer
;; This function uses a non-reentrant model
;;
psect	text2056
	file	"F:\work\WYP\NBIoT\Function.c"
	line	360
	global	__size_of_MakeTxTemperature
	__size_of_MakeTxTemperature	equ	__end_of_MakeTxTemperature-_MakeTxTemperature
	
_MakeTxTemperature:	
	opt	stack 10
; Regs used in _MakeTxTemperature: [wreg+status,2+status,0]
	line	362
	
l32712:	
;Function.c: 361: unsigned char x;
;Function.c: 362: x=(T.u8H>>4);
	swapf	0+(MakeTxTemperature@T)+01h,w
	andlw	(0ffh shr 4) & 0ffh
	movwf	(MakeTxTemperature@x)
	line	363
	
l32714:	
;Function.c: 363: if(x>9)
	movlw	(0Ah)
	subwf	(MakeTxTemperature@x),w
	skipc
	goto	u7711
	goto	u7710
u7711:
	goto	l32720
u7710:
	line	365
	
l32716:	
;Function.c: 364: {
;Function.c: 365: x=x-10;
	movlw	(0F6h)
	addwf	(MakeTxTemperature@x),f
	line	366
;Function.c: 366: x=x+0x41;
	movlw	(041h)
	addwf	(MakeTxTemperature@x),f
	line	367
	
l32718:	
;Function.c: 367: TxTemperature[0]=x;
	movf	(MakeTxTemperature@x),w
	movwf	(_TxTemperature)
	line	368
;Function.c: 368: }
	goto	l32724
	line	371
	
l32720:	
;Function.c: 369: else
;Function.c: 370: {
;Function.c: 371: x=x+'0';
	movlw	(030h)
	addwf	(MakeTxTemperature@x),f
	goto	l32718
	line	374
	
l32724:	
;Function.c: 373: }
;Function.c: 374: x=(T.u8H&0x0F);
	movf	0+(MakeTxTemperature@T)+01h,w
	movwf	(MakeTxTemperature@x)
	movlw	(0Fh)
	andwf	(MakeTxTemperature@x),f
	line	375
	
l32726:	
;Function.c: 375: if(x>9)
	movlw	(0Ah)
	subwf	(MakeTxTemperature@x),w
	skipc
	goto	u7721
	goto	u7720
u7721:
	goto	l32732
u7720:
	line	377
	
l32728:	
;Function.c: 376: {
;Function.c: 377: x=x-10;
	movlw	(0F6h)
	addwf	(MakeTxTemperature@x),f
	line	378
;Function.c: 378: x=x+0x41;
	movlw	(041h)
	addwf	(MakeTxTemperature@x),f
	line	379
	
l32730:	
;Function.c: 379: TxTemperature[1]=x;
	movf	(MakeTxTemperature@x),w
	movwf	0+(_TxTemperature)+01h
	line	380
;Function.c: 380: }
	goto	l32736
	line	383
	
l32732:	
;Function.c: 381: else
;Function.c: 382: {
;Function.c: 383: x=x+'0';
	movlw	(030h)
	addwf	(MakeTxTemperature@x),f
	goto	l32730
	line	386
	
l32736:	
;Function.c: 385: }
;Function.c: 386: x=(T.u8L>>4);
	swapf	(MakeTxTemperature@T),w
	andlw	(0ffh shr 4) & 0ffh
	movwf	(MakeTxTemperature@x)
	line	387
;Function.c: 387: if(x>9)
	movlw	(0Ah)
	subwf	(MakeTxTemperature@x),w
	skipc
	goto	u7731
	goto	u7730
u7731:
	goto	l32742
u7730:
	line	389
	
l32738:	
;Function.c: 388: {
;Function.c: 389: x=x-10;
	movlw	(0F6h)
	addwf	(MakeTxTemperature@x),f
	line	390
;Function.c: 390: x=x+0x41;
	movlw	(041h)
	addwf	(MakeTxTemperature@x),f
	line	391
	
l32740:	
;Function.c: 391: TxTemperature[2]=x;
	movf	(MakeTxTemperature@x),w
	movwf	0+(_TxTemperature)+02h
	line	392
;Function.c: 392: }
	goto	l32746
	line	395
	
l32742:	
;Function.c: 393: else
;Function.c: 394: {
;Function.c: 395: x=x+'0';
	movlw	(030h)
	addwf	(MakeTxTemperature@x),f
	goto	l32740
	line	398
	
l32746:	
;Function.c: 397: }
;Function.c: 398: x=(T.u8L&0x0F);
	movf	(MakeTxTemperature@T),w
	movwf	(MakeTxTemperature@x)
	movlw	(0Fh)
	andwf	(MakeTxTemperature@x),f
	line	399
	
l32748:	
;Function.c: 399: if(x>9)
	movlw	(0Ah)
	subwf	(MakeTxTemperature@x),w
	skipc
	goto	u7741
	goto	u7740
u7741:
	goto	l32754
u7740:
	line	401
	
l32750:	
;Function.c: 400: {
;Function.c: 401: x=x-10;
	movlw	(0F6h)
	addwf	(MakeTxTemperature@x),f
	line	402
;Function.c: 402: x=x+0x41;
	movlw	(041h)
	addwf	(MakeTxTemperature@x),f
	line	403
	
l32752:	
;Function.c: 403: TxTemperature[3]=x;
	movf	(MakeTxTemperature@x),w
	movwf	0+(_TxTemperature)+03h
	line	404
;Function.c: 404: }
	goto	l8785
	line	407
	
l32754:	
;Function.c: 405: else
;Function.c: 406: {
;Function.c: 407: x=x+'0';
	movlw	(030h)
	addwf	(MakeTxTemperature@x),f
	goto	l32752
	line	410
	
l8785:	
	return
	opt stack 0
GLOBAL	__end_of_MakeTxTemperature
	__end_of_MakeTxTemperature:
;; =============== function _MakeTxTemperature ends ============

	signat	_MakeTxTemperature,4216
	global	_Uart1_PutChar
psect	text2057,local,class=CODE,delta=2
global __ptext2057
__ptext2057:

;; *************** function _Uart1_PutChar *****************
;; Defined at:
;;		line 47 in file "F:\work\WYP\NBIoT\Uart.c"
;; Parameters:    Size  Location     Type
;;  c               1    wreg     unsigned char 
;; Auto vars:     Size  Location     Type
;;  c               1    0[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 1F/3
;;		Unchanged: FFFE0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       0       0       0       0       0       0       0
;;      Locals:         0       1       0       0       0       0       0       0
;;      Temps:          0       0       0       0       0       0       0       0
;;      Totals:         0       1       0       0       0       0       0       0
;;Total ram usage:        1 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    3
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_InteractServer
;;		_InitGPRS
;;		_Uart1_PutString
;; This function uses a non-reentrant model
;;
psect	text2057
	file	"F:\work\WYP\NBIoT\Uart.c"
	line	47
	global	__size_of_Uart1_PutChar
	__size_of_Uart1_PutChar	equ	__end_of_Uart1_PutChar-_Uart1_PutChar
	
_Uart1_PutChar:	
	opt	stack 9
; Regs used in _Uart1_PutChar: [wreg]
;Uart1_PutChar@c stored from wreg
	movlb 0	; select bank0
	movwf	(Uart1_PutChar@c)
	line	48
	
l32708:	
;Uart.c: 48: while(TRMT==0);
	
l23515:	
	movlb 3	; select bank3
	btfss	(3313/8)^0180h,(3313)&7
	goto	u7701
	goto	u7700
u7701:
	goto	l23515
u7700:
	line	52
	
l32710:	
;Uart.c: 52: TXREG=c;
	movlb 0	; select bank0
	movf	(Uart1_PutChar@c),w
	movlb 3	; select bank3
	movwf	(410)^0180h	;volatile
	line	53
	
l23518:	
	return
	opt stack 0
GLOBAL	__end_of_Uart1_PutChar
	__end_of_Uart1_PutChar:
;; =============== function _Uart1_PutChar ends ============

	signat	_Uart1_PutChar,4216
	global	_strcpy
psect	text2058,local,class=CODE,delta=2
global __ptext2058
__ptext2058:

;; *************** function _strcpy *****************
;; Defined at:
;;		line 10 in file "C:\Program Files (x86)\HI-TECH Software\PICC\9.71a\sources\strcpy.c"
;; Parameters:    Size  Location     Type
;;  to              1    wreg     PTR unsigned char 
;;		 -> ATCommand_ErrString(15), ATCommand_OkString(15), 
;;  from            2    0[BANK0 ] PTR const unsigned char 
;;		 -> STR_53(6), STR_52(3), STR_51(6), STR_50(3), 
;;		 -> STR_48(6), STR_47(3), STR_41(11), STR_20(6), 
;;		 -> STR_19(5), STR_8(2), STR_2(11), 
;; Auto vars:     Size  Location     Type
;;  to              1    4[BANK0 ] PTR unsigned char 
;;		 -> ATCommand_ErrString(15), ATCommand_OkString(15), 
;;  cp              1    5[BANK0 ] PTR unsigned char 
;;		 -> ATCommand_ErrString(15), ATCommand_OkString(15), 
;; Return value:  Size  Location     Type
;;                  1    wreg      PTR unsigned char 
;; Registers used:
;;		wreg, fsr0l, fsr0h, fsr1l, fsr1h, status,2, status,0, pclath
;; Tracked objects:
;;		On entry : 1F/0
;;		On exit  : 1F/0
;;		Unchanged: FFFE0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       2       0       0       0       0       0       0
;;      Locals:         0       2       0       0       0       0       0       0
;;      Temps:          0       2       0       0       0       0       0       0
;;      Totals:         0       6       0       0       0       0       0       0
;;Total ram usage:        6 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    3
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_CallSend
;;		_InteractServer
;;		_CallTestSend
;;		_ATCommand_Init
;;		_ATCommand_SendCmd
;;		_ATCommand_WaitData
;; This function uses a non-reentrant model
;;
psect	text2058
	file	"C:\Program Files (x86)\HI-TECH Software\PICC\9.71a\sources\strcpy.c"
	line	10
	global	__size_of_strcpy
	__size_of_strcpy	equ	__end_of_strcpy-_strcpy
	
_strcpy:	
	opt	stack 9
; Regs used in _strcpy: [wreg-status,0+pclath]
;strcpy@to stored from wreg
	line	18
	movwf	(strcpy@to)
	
l30800:	
	movf	(strcpy@to),w
	movwf	(strcpy@cp)
	line	19
	
l30802:	
	movf	(strcpy@cp),w
	movwf	fsr1l
	clrf fsr1h	
	
	incf	(strcpy@cp),f
	movf	(strcpy@from+1),w
	movwf	(??_strcpy+0)+0+1
	movf	(strcpy@from),w
	movwf	(??_strcpy+0)+0
	incf	(strcpy@from),f
	skipnz
	incf	(strcpy@from+1),f
	movf	0+(??_strcpy+0)+0,w
	movwf	fsr0l
	movf	(1+(??_strcpy+0)+0),w
	movwf	fsr0h
	movf	indf0,w ;code access
	movwi	[0]fsr1
	movf	wreg
	btfss	status,2
	goto	u4331
	goto	u4330
u4331:
	goto	l30802
u4330:
	line	22
	
l27763:	
	return
	opt stack 0
GLOBAL	__end_of_strcpy
	__end_of_strcpy:
;; =============== function _strcpy ends ============

	signat	_strcpy,8313
	global	_eeprom_write
psect	text2059,local,class=CODE,delta=2
global __ptext2059
__ptext2059:

;; *************** function _eeprom_write *****************
;; Defined at:
;;		line 8 in file "C:\Program Files (x86)\HI-TECH Software\PICC\9.71a\sources\eewrite.c"
;; Parameters:    Size  Location     Type
;;  addr            1    wreg     unsigned char 
;;  value           1    0[BANK0 ] unsigned char 
;; Auto vars:     Size  Location     Type
;;  addr            1    1[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 1F/0
;;		On exit  : 1F/3
;;		Unchanged: FFFE0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       1       0       0       0       0       0       0
;;      Locals:         0       1       0       0       0       0       0       0
;;      Temps:          0       0       0       0       0       0       0       0
;;      Totals:         0       2       0       0       0       0       0       0
;;Total ram usage:        2 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    3
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_main
;;		_SaveRomData
;; This function uses a non-reentrant model
;;
psect	text2059
	file	"C:\Program Files (x86)\HI-TECH Software\PICC\9.71a\sources\eewrite.c"
	line	8
	global	__size_of_eeprom_write
	__size_of_eeprom_write	equ	__end_of_eeprom_write-_eeprom_write
	
_eeprom_write:	
	opt	stack 13
; Regs used in _eeprom_write: [wreg+status,2+status,0]
;eeprom_write@addr stored from wreg
	movwf	(eeprom_write@addr)
	line	9
	
l27725:	
	
l27726:	
	movlb 3	; select bank3
	btfsc	(3241/8)^0180h,(3241)&7
	goto	u7671
	goto	u7670
u7671:
	goto	l27726
u7670:
	
l32688:	
	movlb 0	; select bank0
	movf	(eeprom_write@addr),w
	movlb 3	; select bank3
	movwf	(401)^0180h	;volatile
	movlb 0	; select bank0
	movf	(eeprom_write@value),w
	movlb 3	; select bank3
	movwf	(403)^0180h	;volatile
	
l32690:	
	movlw	(03Fh)
	andwf	(405)^0180h,f	;volatile
	
l32692:	
	bcf	(24/8),(24)&7
	
l32694:	
	btfss	(95/8),(95)&7
	goto	u7681
	goto	u7680
u7681:
	goto	l27729
u7680:
	
l32696:	
	bsf	(24/8),(24)&7
	
l27729:	
	bcf	(95/8),(95)&7
	bsf	(3242/8)^0180h,(3242)&7
	
l32698:	
	movlw	(055h)
	movwf	(406)^0180h	;volatile
	movlw	(0AAh)
	movwf	(406)^0180h	;volatile
	
l32700:	
	bsf	(3241/8)^0180h,(3241)&7
	
l32702:	
	bcf	(3242/8)^0180h,(3242)&7
	
l32704:	
	btfss	(24/8),(24)&7
	goto	u7691
	goto	u7690
u7691:
	goto	l27732
u7690:
	
l32706:	
	bsf	(95/8),(95)&7
	line	10
	
l27732:	
	return
	opt stack 0
GLOBAL	__end_of_eeprom_write
	__end_of_eeprom_write:
;; =============== function _eeprom_write ends ============

	signat	_eeprom_write,8312
	global	_InitMCU
psect	text2060,local,class=CODE,delta=2
global __ptext2060
__ptext2060:

;; *************** function _InitMCU *****************
;; Defined at:
;;		line 3 in file "F:\work\WYP\NBIoT\Init.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, status,2
;; Tracked objects:
;;		On entry : 17F/0
;;		On exit  : 17F/0
;;		Unchanged: FFE80/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       0       0       0       0       0       0       0
;;      Locals:         0       0       0       0       0       0       0       0
;;      Temps:          0       0       0       0       0       0       0       0
;;      Totals:         0       0       0       0       0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    3
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_InitSystem
;; This function uses a non-reentrant model
;;
psect	text2060
	file	"F:\work\WYP\NBIoT\Init.c"
	line	3
	global	__size_of_InitMCU
	__size_of_InitMCU	equ	__end_of_InitMCU-_InitMCU
	
_InitMCU:	
	opt	stack 12
; Regs used in _InitMCU: [wreg+status,2]
	line	5
	
l32632:	
;Init.c: 5: ADCON1=0b00111111;
	movlw	(03Fh)
	movlb 1	; select bank1
	movwf	(158)^080h	;volatile
	line	7
	
l32634:	
;Init.c: 7: ANSELA=0;
	movlb 3	; select bank3
	clrf	(396)^0180h	;volatile
	line	8
	
l32636:	
;Init.c: 8: ANSELB=0;
	clrf	(397)^0180h	;volatile
	line	9
	
l32638:	
;Init.c: 9: ANSELD=0;
	clrf	(399)^0180h	;volatile
	line	10
	
l32640:	
;Init.c: 10: ANSELE=0;
	clrf	(400)^0180h	;volatile
	line	12
	
l32642:	
;Init.c: 12: LATD5=0;
	movlb 2	; select bank2
	bcf	(2173/8)^0100h,(2173)&7
	line	13
	
l32644:	
;Init.c: 13: TRISD5=0;
	movlb 1	; select bank1
	bcf	(1149/8)^080h,(1149)&7
	line	14
	
l32646:	
;Init.c: 14: TRISD4=1;
	bsf	(1148/8)^080h,(1148)&7
	line	16
	
l32648:	
;Init.c: 16: nWPUEN=0;
	bcf	(1199/8)^080h,(1199)&7
	line	17
	
l32650:	
;Init.c: 17: TRISB7=1;
	bsf	(1135/8)^080h,(1135)&7
	line	18
	
l32652:	
;Init.c: 18: WPUB7=1;
	movlb 4	; select bank4
	bsf	(4207/8)^0200h,(4207)&7
	line	20
	
l32654:	
;Init.c: 20: LATA4=0;
	movlb 2	; select bank2
	bcf	(2148/8)^0100h,(2148)&7
	line	21
	
l32656:	
;Init.c: 21: LATA3=0;
	bcf	(2147/8)^0100h,(2147)&7
	line	23
	
l32658:	
;Init.c: 23: TRISA4=0;
	movlb 1	; select bank1
	bcf	(1124/8)^080h,(1124)&7
	line	24
	
l32660:	
;Init.c: 24: TRISA3=0;
	bcf	(1123/8)^080h,(1123)&7
	line	26
	
l32662:	
;Init.c: 26: TRISB2=1;
	bsf	(1130/8)^080h,(1130)&7
	line	30
;Init.c: 30: T2CON=0b00111011;
	movlw	(03Bh)
	movlb 0	; select bank0
	movwf	(28)	;volatile
	line	31
;Init.c: 31: PR2=227;
	movlw	(0E3h)
	movwf	(27)	;volatile
	line	32
	
l32664:	
;Init.c: 32: TMR2ON=0;
	bcf	(226/8),(226)&7
	line	33
	
l32666:	
;Init.c: 33: TMR2IE=0;
	movlb 1	; select bank1
	bcf	(1161/8)^080h,(1161)&7
	line	34
	
l32668:	
;Init.c: 34: TMR2IF=0;
	movlb 0	; select bank0
	bcf	(137/8),(137)&7
	line	38
;Init.c: 38: T1CON=0b01110000;
	movlw	(070h)
	movwf	(24)	;volatile
	line	39
;Init.c: 39: ((void)(TMR1H=((15536)>>8),TMR1L=((15536)&0xFF)));
	movlw	(03Ch)
	movwf	(23)	;volatile
	movlw	(0B0h)
	movwf	(22)	;volatile
	line	40
	
l32670:	
;Init.c: 40: TMR1ON=1;
	bsf	(192/8),(192)&7
	line	41
	
l32672:	
;Init.c: 41: TMR1IE=1;
	movlb 1	; select bank1
	bsf	(1160/8)^080h,(1160)&7
	line	42
	
l32674:	
;Init.c: 42: TMR1IF=0;
	movlb 0	; select bank0
	bcf	(136/8),(136)&7
	line	48
	
l32676:	
;Init.c: 48: TRISC7=1;
	movlb 1	; select bank1
	bsf	(1143/8)^080h,(1143)&7
	line	49
	
l32678:	
;Init.c: 49: TRISC6=1;
	bsf	(1142/8)^080h,(1142)&7
	line	50
;Init.c: 50: TXSTA=0b00100110;
	movlw	(026h)
	movlb 3	; select bank3
	movwf	(414)^0180h	;volatile
	line	51
;Init.c: 51: RCSTA=0b10010000;
	movlw	(090h)
	movwf	(413)^0180h	;volatile
	line	52
;Init.c: 52: SPBRG=25;
	movlw	(019h)
	movwf	(411)^0180h	;volatile
	line	53
	
l32680:	
;Init.c: 53: RCIE=1;
	movlb 1	; select bank1
	bsf	(1165/8)^080h,(1165)&7
	line	54
	
l32682:	
;Init.c: 54: RCIF=0;
	movlb 0	; select bank0
	bcf	(141/8),(141)&7
	line	56
	
l32684:	
;Init.c: 56: PEIE=1;
	bsf	(94/8),(94)&7
	line	57
	
l32686:	
;Init.c: 57: GIE=1;
	bsf	(95/8),(95)&7
	line	58
	
l4421:	
	return
	opt stack 0
GLOBAL	__end_of_InitMCU
	__end_of_InitMCU:
;; =============== function _InitMCU ends ============

	signat	_InitMCU,88
	global	_DisplayInit
psect	text2061,local,class=CODE,delta=2
global __ptext2061
__ptext2061:

;; *************** function _DisplayInit *****************
;; Defined at:
;;		line 385 in file "F:\work\WYP\NBIoT\Display.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, status,2
;; Tracked objects:
;;		On entry : 17F/0
;;		On exit  : 17F/F
;;		Unchanged: FFE80/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       0       0       0       0       0       0       0
;;      Locals:         0       0       0       0       0       0       0       0
;;      Temps:          0       0       0       0       0       0       0       0
;;      Totals:         0       0       0       0       0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    3
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_InitSystem
;; This function uses a non-reentrant model
;;
psect	text2061
	file	"F:\work\WYP\NBIoT\Display.c"
	line	385
	global	__size_of_DisplayInit
	__size_of_DisplayInit	equ	__end_of_DisplayInit-_DisplayInit
	
_DisplayInit:	
	opt	stack 12
; Regs used in _DisplayInit: [wreg+status,2]
	line	389
	
l32580:	
;Display.c: 389: LCDPS = 0b00000011;
	movlw	(03h)
	movlb 15	; select bank15
	movwf	(1938)^0780h	;volatile
	line	390
	
l32582:	
;Display.c: 390: LCDSE0 = 0;
	clrf	(1944)^0780h	;volatile
	line	391
	
l32584:	
;Display.c: 391: LCDSE1 = 0;
	clrf	(1945)^0780h	;volatile
	line	392
	
l32586:	
;Display.c: 392: LCDSE2 = 0;
	clrf	(1946)^0780h	;volatile
	line	393
	
l32588:	
;Display.c: 393: SEG21=1;
	bsf	(15573/8)^0780h,(15573)&7
	line	394
	
l32590:	
;Display.c: 394: SEG5=1;
	bsf	(15557/8)^0780h,(15557)&7
	line	395
	
l32592:	
;Display.c: 395: SEG11=1;
	bsf	(15563/8)^0780h,(15563)&7
	line	396
	
l32594:	
;Display.c: 396: SEG16=1;
	bsf	(15568/8)^0780h,(15568)&7
	line	397
	
l32596:	
;Display.c: 397: SEG6=1;
	bsf	(15558/8)^0780h,(15558)&7
	line	398
	
l32598:	
;Display.c: 398: SEG3=1;
	bsf	(15555/8)^0780h,(15555)&7
	line	399
	
l32600:	
;Display.c: 399: SEG23=1;
	bsf	(15575/8)^0780h,(15575)&7
	line	400
	
l32602:	
;Display.c: 400: SEG22=1;
	bsf	(15574/8)^0780h,(15574)&7
	line	402
	
l32604:	
;Display.c: 402: LCDCON = 0b00001111;
	movlw	(0Fh)
	movwf	(1937)^0780h	;volatile
	line	403
;Display.c: 403: LCDDATA0=0;
	clrf	(1952)^0780h	;volatile
	line	404
;Display.c: 404: LCDDATA1=0;
	clrf	(1953)^0780h	;volatile
	line	405
;Display.c: 405: LCDDATA2=0;
	clrf	(1954)^0780h	;volatile
	line	406
;Display.c: 406: LCDDATA3=0;
	clrf	(1955)^0780h	;volatile
	line	407
;Display.c: 407: LCDDATA4=0;
	clrf	(1956)^0780h	;volatile
	line	408
;Display.c: 408: LCDDATA5=0;
	clrf	(1957)^0780h	;volatile
	line	409
;Display.c: 409: LCDDATA6=0;
	clrf	(1958)^0780h	;volatile
	line	410
;Display.c: 410: LCDDATA7=0;
	clrf	(1959)^0780h	;volatile
	line	411
;Display.c: 411: LCDDATA8=0;
	clrf	(1960)^0780h	;volatile
	line	412
;Display.c: 412: LCDDATA9=0;
	clrf	(1961)^0780h	;volatile
	line	413
;Display.c: 413: LCDDATA10=0;
	clrf	(1962)^0780h	;volatile
	line	414
;Display.c: 414: LCDDATA11=0;
	clrf	(1963)^0780h	;volatile
	line	416
	
l32606:	
;Display.c: 416: LCDREF = 0b10100000;
	movlw	(0A0h)
	movwf	(1939)^0780h	;volatile
	line	417
	
l32608:	
;Display.c: 417: LCDRL = 0b00110000;
	movlw	(030h)
	movwf	(1941)^0780h	;volatile
	line	418
;Display.c: 418: LCDCST = 0b00000000;
	clrf	(1940)^0780h	;volatile
	line	420
	
l32610:	
;Display.c: 420: LCDEN=1;
	bsf	(15503/8)^0780h,(15503)&7
	line	440
	
l32612:	
;Display.c: 440: SEG5COM0=0;
	bcf	(15621/8)^0780h,(15621)&7
	line	441
	
l32614:	
;Display.c: 441: SEG5COM1=0;
	bcf	(15645/8)^0780h,(15645)&7
	line	442
	
l32616:	
;Display.c: 442: SEG5COM2=0;
	bcf	(15669/8)^0780h,(15669)&7
	line	443
	
l32618:	
;Display.c: 443: SEG5COM3=1;
	bsf	(15693/8)^0780h,(15693)&7
	line	444
	
l32620:	
;Display.c: 444: SEG22COM3=0;
	bcf	(15710/8)^0780h,(15710)&7
	line	445
	
l32622:	
;Display.c: 445: SEG3COM3=0;
	bcf	(15691/8)^0780h,(15691)&7
	line	446
	
l32624:	
;Display.c: 446: SEG21COM3=0;
	bcf	(15709/8)^0780h,(15709)&7
	line	447
	
l32626:	
;Display.c: 447: SEG21COM2=0;
	bcf	(15685/8)^0780h,(15685)&7
	line	448
	
l32628:	
;Display.c: 448: SEG21COM1=0;
	bcf	(15661/8)^0780h,(15661)&7
	line	449
	
l32630:	
;Display.c: 449: SEG21COM0=0;
	bcf	(15637/8)^0780h,(15637)&7
	line	453
	
l2354:	
	return
	opt stack 0
GLOBAL	__end_of_DisplayInit
	__end_of_DisplayInit:
;; =============== function _DisplayInit ends ============

	signat	_DisplayInit,88
	global	_LcdDisplayNum
psect	text2062,local,class=CODE,delta=2
global __ptext2062
__ptext2062:

;; *************** function _LcdDisplayNum *****************
;; Defined at:
;;		line 12 in file "F:\work\WYP\NBIoT\Display.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		None
;; Tracked objects:
;;		On entry : 10/0
;;		On exit  : 1F/F
;;		Unchanged: FFFE0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       0       0       0       0       0       0       0
;;      Locals:         0       0       0       0       0       0       0       0
;;      Temps:          0       0       0       0       0       0       0       0
;;      Totals:         0       0       0       0       0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    3
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_LcdDisplayAll
;;		_LcdDisplay_CSQ
;;		_LcdDisplay_CurTemp
;;		_LcdDisplay_Err
;; This function uses a non-reentrant model
;;
psect	text2062
	file	"F:\work\WYP\NBIoT\Display.c"
	line	12
	global	__size_of_LcdDisplayNum
	__size_of_LcdDisplayNum	equ	__end_of_LcdDisplayNum-_LcdDisplayNum
	
_LcdDisplayNum:	
	opt	stack 11
; Regs used in _LcdDisplayNum: []
	line	16
	
l32534:	
;Display.c: 16: if(DpyNum[0]&0x01)
	movlb 0	; select bank0
	btfss	(_DpyNum),(0)&7
	goto	u7011
	goto	u7010
u7011:
	goto	l2056
u7010:
	line	18
	
l2052:	
	movlb 15	; select bank15
	btfss	(15508/8)^0780h,(15508)&7
	goto	u7021
	goto	u7020
u7021:
	goto	l2052
u7020:
	
l2054:	
	line	19
;Display.c: 19: SEG23COM0 = 1;
	bsf	(15639/8)^0780h,(15639)&7
	line	20
;Display.c: 20: }
	goto	l2055
	line	23
	
l2056:	
	movlb 15	; select bank15
	btfss	(15508/8)^0780h,(15508)&7
	goto	u7031
	goto	u7030
u7031:
	goto	l2056
u7030:
	
l2058:	
	line	24
;Display.c: 24: SEG23COM0 = 0;
	bcf	(15639/8)^0780h,(15639)&7
	line	25
	
l2055:	
	line	26
;Display.c: 25: }
;Display.c: 26: if(DpyNum[0]&0x02)
	movlb 0	; select bank0
	btfss	(_DpyNum),(1)&7
	goto	u7041
	goto	u7040
u7041:
	goto	l2064
u7040:
	line	28
	
l2060:	
	movlb 15	; select bank15
	btfss	(15508/8)^0780h,(15508)&7
	goto	u7051
	goto	u7050
u7051:
	goto	l2060
u7050:
	
l2062:	
	line	29
;Display.c: 29: SEG23COM1 = 1;
	bsf	(15663/8)^0780h,(15663)&7
	line	30
;Display.c: 30: }
	goto	l2063
	line	33
	
l2064:	
	movlb 15	; select bank15
	btfss	(15508/8)^0780h,(15508)&7
	goto	u7061
	goto	u7060
u7061:
	goto	l2064
u7060:
	
l2066:	
	line	34
;Display.c: 34: SEG23COM1 = 0;
	bcf	(15663/8)^0780h,(15663)&7
	line	35
	
l2063:	
	line	36
;Display.c: 35: }
;Display.c: 36: if(DpyNum[0]&0x04)
	movlb 0	; select bank0
	btfss	(_DpyNum),(2)&7
	goto	u7071
	goto	u7070
u7071:
	goto	l2072
u7070:
	line	38
	
l2068:	
	movlb 15	; select bank15
	btfss	(15508/8)^0780h,(15508)&7
	goto	u7081
	goto	u7080
u7081:
	goto	l2068
u7080:
	
l2070:	
	line	39
;Display.c: 39: SEG23COM2 = 1;
	bsf	(15687/8)^0780h,(15687)&7
	line	40
;Display.c: 40: }
	goto	l2071
	line	43
	
l2072:	
	movlb 15	; select bank15
	btfss	(15508/8)^0780h,(15508)&7
	goto	u7091
	goto	u7090
u7091:
	goto	l2072
u7090:
	
l2074:	
	line	44
;Display.c: 44: SEG23COM2 = 0;
	bcf	(15687/8)^0780h,(15687)&7
	line	45
	
l2071:	
	line	46
;Display.c: 45: }
;Display.c: 46: if(DpyNum[0]&0x08)
	movlb 0	; select bank0
	btfss	(_DpyNum),(3)&7
	goto	u7101
	goto	u7100
u7101:
	goto	l2080
u7100:
	line	48
	
l2076:	
	movlb 15	; select bank15
	btfss	(15508/8)^0780h,(15508)&7
	goto	u7111
	goto	u7110
u7111:
	goto	l2076
u7110:
	
l2078:	
	line	49
;Display.c: 49: SEG23COM3 = 1;
	bsf	(15711/8)^0780h,(15711)&7
	line	50
;Display.c: 50: }
	goto	l2079
	line	53
	
l2080:	
	movlb 15	; select bank15
	btfss	(15508/8)^0780h,(15508)&7
	goto	u7121
	goto	u7120
u7121:
	goto	l2080
u7120:
	
l2082:	
	line	54
;Display.c: 54: SEG23COM3 = 0;
	bcf	(15711/8)^0780h,(15711)&7
	line	55
	
l2079:	
	line	56
;Display.c: 55: }
;Display.c: 56: if(DpyNum[0]&0x10)
	movlb 0	; select bank0
	btfss	(_DpyNum),(4)&7
	goto	u7131
	goto	u7130
u7131:
	goto	l2088
u7130:
	line	58
	
l2084:	
	movlb 15	; select bank15
	btfss	(15508/8)^0780h,(15508)&7
	goto	u7141
	goto	u7140
u7141:
	goto	l2084
u7140:
	
l2086:	
	line	59
;Display.c: 59: SEG22COM2 = 1;
	bsf	(15686/8)^0780h,(15686)&7
	line	60
;Display.c: 60: }
	goto	l2087
	line	63
	
l2088:	
	movlb 15	; select bank15
	btfss	(15508/8)^0780h,(15508)&7
	goto	u7151
	goto	u7150
u7151:
	goto	l2088
u7150:
	
l2090:	
	line	64
;Display.c: 64: SEG22COM2 = 0;
	bcf	(15686/8)^0780h,(15686)&7
	line	65
	
l2087:	
	line	66
;Display.c: 65: }
;Display.c: 66: if(DpyNum[0]&0x20)
	movlb 0	; select bank0
	btfss	(_DpyNum),(5)&7
	goto	u7161
	goto	u7160
u7161:
	goto	l2096
u7160:
	line	68
	
l2092:	
	movlb 15	; select bank15
	btfss	(15508/8)^0780h,(15508)&7
	goto	u7171
	goto	u7170
u7171:
	goto	l2092
u7170:
	
l2094:	
	line	69
;Display.c: 69: SEG22COM0 = 1;
	bsf	(15638/8)^0780h,(15638)&7
	line	70
;Display.c: 70: }
	goto	l2095
	line	73
	
l2096:	
	movlb 15	; select bank15
	btfss	(15508/8)^0780h,(15508)&7
	goto	u7181
	goto	u7180
u7181:
	goto	l2096
u7180:
	
l2098:	
	line	74
;Display.c: 74: SEG22COM0 = 0;
	bcf	(15638/8)^0780h,(15638)&7
	line	75
	
l2095:	
	line	76
;Display.c: 75: }
;Display.c: 76: if(DpyNum[0]&0x40)
	movlb 0	; select bank0
	btfss	(_DpyNum),(6)&7
	goto	u7191
	goto	u7190
u7191:
	goto	l2104
u7190:
	line	78
	
l2100:	
	movlb 15	; select bank15
	btfss	(15508/8)^0780h,(15508)&7
	goto	u7201
	goto	u7200
u7201:
	goto	l2100
u7200:
	
l2102:	
	line	79
;Display.c: 79: SEG22COM1 = 1;
	bsf	(15662/8)^0780h,(15662)&7
	line	80
;Display.c: 80: }
	goto	l2103
	line	83
	
l2104:	
	movlb 15	; select bank15
	btfss	(15508/8)^0780h,(15508)&7
	goto	u7211
	goto	u7210
u7211:
	goto	l2104
u7210:
	
l2106:	
	line	84
;Display.c: 84: SEG22COM1 = 0;
	bcf	(15662/8)^0780h,(15662)&7
	line	85
	
l2103:	
	line	87
;Display.c: 85: }
;Display.c: 87: if(DpyNum[1]&0x01)
	movlb 0	; select bank0
	btfss	0+(_DpyNum)+01h,(0)&7
	goto	u7221
	goto	u7220
u7221:
	goto	l2112
u7220:
	line	89
	
l2108:	
	movlb 15	; select bank15
	btfss	(15508/8)^0780h,(15508)&7
	goto	u7231
	goto	u7230
u7231:
	goto	l2108
u7230:
	
l2110:	
	line	90
;Display.c: 90: SEG6COM0 = 1;
	bsf	(15622/8)^0780h,(15622)&7
	line	91
;Display.c: 91: }
	goto	l2111
	line	94
	
l2112:	
	movlb 15	; select bank15
	btfss	(15508/8)^0780h,(15508)&7
	goto	u7241
	goto	u7240
u7241:
	goto	l2112
u7240:
	
l2114:	
	line	95
;Display.c: 95: SEG6COM0 = 0;
	bcf	(15622/8)^0780h,(15622)&7
	line	96
	
l2111:	
	line	97
;Display.c: 96: }
;Display.c: 97: if(DpyNum[1]&0x02)
	movlb 0	; select bank0
	btfss	0+(_DpyNum)+01h,(1)&7
	goto	u7251
	goto	u7250
u7251:
	goto	l2120
u7250:
	line	99
	
l2116:	
	movlb 15	; select bank15
	btfss	(15508/8)^0780h,(15508)&7
	goto	u7261
	goto	u7260
u7261:
	goto	l2116
u7260:
	
l2118:	
	line	100
;Display.c: 100: SEG6COM1 = 1;
	bsf	(15646/8)^0780h,(15646)&7
	line	101
;Display.c: 101: }
	goto	l2119
	line	104
	
l2120:	
	movlb 15	; select bank15
	btfss	(15508/8)^0780h,(15508)&7
	goto	u7271
	goto	u7270
u7271:
	goto	l2120
u7270:
	
l2122:	
	line	105
;Display.c: 105: SEG6COM1 = 0;
	bcf	(15646/8)^0780h,(15646)&7
	line	106
	
l2119:	
	line	107
;Display.c: 106: }
;Display.c: 107: if(DpyNum[1]&0x04)
	movlb 0	; select bank0
	btfss	0+(_DpyNum)+01h,(2)&7
	goto	u7281
	goto	u7280
u7281:
	goto	l2128
u7280:
	line	109
	
l2124:	
	movlb 15	; select bank15
	btfss	(15508/8)^0780h,(15508)&7
	goto	u7291
	goto	u7290
u7291:
	goto	l2124
u7290:
	
l2126:	
	line	110
;Display.c: 110: SEG6COM2 = 1;
	bsf	(15670/8)^0780h,(15670)&7
	line	111
;Display.c: 111: }
	goto	l2127
	line	114
	
l2128:	
	movlb 15	; select bank15
	btfss	(15508/8)^0780h,(15508)&7
	goto	u7301
	goto	u7300
u7301:
	goto	l2128
u7300:
	
l2130:	
	line	115
;Display.c: 115: SEG6COM2 = 0;
	bcf	(15670/8)^0780h,(15670)&7
	line	116
	
l2127:	
	line	117
;Display.c: 116: }
;Display.c: 117: if(DpyNum[1]&0x08)
	movlb 0	; select bank0
	btfss	0+(_DpyNum)+01h,(3)&7
	goto	u7311
	goto	u7310
u7311:
	goto	l2136
u7310:
	line	119
	
l2132:	
	movlb 15	; select bank15
	btfss	(15508/8)^0780h,(15508)&7
	goto	u7321
	goto	u7320
u7321:
	goto	l2132
u7320:
	
l2134:	
	line	120
;Display.c: 120: SEG6COM3 = 1;
	bsf	(15694/8)^0780h,(15694)&7
	line	121
;Display.c: 121: }
	goto	l2135
	line	124
	
l2136:	
	movlb 15	; select bank15
	btfss	(15508/8)^0780h,(15508)&7
	goto	u7331
	goto	u7330
u7331:
	goto	l2136
u7330:
	
l2138:	
	line	125
;Display.c: 125: SEG6COM3 = 0;
	bcf	(15694/8)^0780h,(15694)&7
	line	126
	
l2135:	
	line	127
;Display.c: 126: }
;Display.c: 127: if(DpyNum[1]&0x10)
	movlb 0	; select bank0
	btfss	0+(_DpyNum)+01h,(4)&7
	goto	u7341
	goto	u7340
u7341:
	goto	l2144
u7340:
	line	129
	
l2140:	
	movlb 15	; select bank15
	btfss	(15508/8)^0780h,(15508)&7
	goto	u7351
	goto	u7350
u7351:
	goto	l2140
u7350:
	
l2142:	
	line	130
;Display.c: 130: SEG3COM2 = 1;
	bsf	(15667/8)^0780h,(15667)&7
	line	131
;Display.c: 131: }
	goto	l2143
	line	134
	
l2144:	
	movlb 15	; select bank15
	btfss	(15508/8)^0780h,(15508)&7
	goto	u7361
	goto	u7360
u7361:
	goto	l2144
u7360:
	
l2146:	
	line	135
;Display.c: 135: SEG3COM2 = 0;
	bcf	(15667/8)^0780h,(15667)&7
	line	136
	
l2143:	
	line	137
;Display.c: 136: }
;Display.c: 137: if(DpyNum[1]&0x20)
	movlb 0	; select bank0
	btfss	0+(_DpyNum)+01h,(5)&7
	goto	u7371
	goto	u7370
u7371:
	goto	l2152
u7370:
	line	139
	
l2148:	
	movlb 15	; select bank15
	btfss	(15508/8)^0780h,(15508)&7
	goto	u7381
	goto	u7380
u7381:
	goto	l2148
u7380:
	
l2150:	
	line	140
;Display.c: 140: SEG3COM0 = 1;
	bsf	(15619/8)^0780h,(15619)&7
	line	141
;Display.c: 141: }
	goto	l2151
	line	144
	
l2152:	
	movlb 15	; select bank15
	btfss	(15508/8)^0780h,(15508)&7
	goto	u7391
	goto	u7390
u7391:
	goto	l2152
u7390:
	
l2154:	
	line	145
;Display.c: 145: SEG3COM0 = 0;
	bcf	(15619/8)^0780h,(15619)&7
	line	146
	
l2151:	
	line	147
;Display.c: 146: }
;Display.c: 147: if(DpyNum[1]&0x40)
	movlb 0	; select bank0
	btfss	0+(_DpyNum)+01h,(6)&7
	goto	u7401
	goto	u7400
u7401:
	goto	l2160
u7400:
	line	149
	
l2156:	
	movlb 15	; select bank15
	btfss	(15508/8)^0780h,(15508)&7
	goto	u7411
	goto	u7410
u7411:
	goto	l2156
u7410:
	
l2158:	
	line	150
;Display.c: 150: SEG3COM1 = 1;
	bsf	(15643/8)^0780h,(15643)&7
	line	151
;Display.c: 151: }
	goto	l2159
	line	154
	
l2160:	
	movlb 15	; select bank15
	btfss	(15508/8)^0780h,(15508)&7
	goto	u7421
	goto	u7420
u7421:
	goto	l2160
u7420:
	
l2162:	
	line	155
;Display.c: 155: SEG3COM1 = 0;
	bcf	(15643/8)^0780h,(15643)&7
	line	156
	
l2159:	
	line	157
;Display.c: 156: }
;Display.c: 157: if(DpyNum[1]&0x80)
	movlb 0	; select bank0
	btfss	0+(_DpyNum)+01h,(7)&7
	goto	u7431
	goto	u7430
u7431:
	goto	l2168
u7430:
	line	159
	
l2164:	
	movlb 15	; select bank15
	btfss	(15508/8)^0780h,(15508)&7
	goto	u7441
	goto	u7440
u7441:
	goto	l2164
u7440:
	
l2166:	
	line	160
;Display.c: 160: SEG16COM3 = 1;
	bsf	(15704/8)^0780h,(15704)&7
	line	161
;Display.c: 161: }
	goto	l2167
	line	164
	
l2168:	
	movlb 15	; select bank15
	btfss	(15508/8)^0780h,(15508)&7
	goto	u7451
	goto	u7450
u7451:
	goto	l2168
u7450:
	
l2170:	
	line	165
;Display.c: 165: SEG16COM3 = 0;
	bcf	(15704/8)^0780h,(15704)&7
	line	166
	
l2167:	
	line	168
;Display.c: 166: }
;Display.c: 168: if(DpyNum[2]&0x01)
	movlb 0	; select bank0
	btfss	0+(_DpyNum)+02h,(0)&7
	goto	u7461
	goto	u7460
u7461:
	goto	l2176
u7460:
	line	170
	
l2172:	
	movlb 15	; select bank15
	btfss	(15508/8)^0780h,(15508)&7
	goto	u7471
	goto	u7470
u7471:
	goto	l2172
u7470:
	
l2174:	
	line	171
;Display.c: 171: SEG11COM0 = 1;
	bsf	(15627/8)^0780h,(15627)&7
	line	172
;Display.c: 172: }
	goto	l2175
	line	175
	
l2176:	
	movlb 15	; select bank15
	btfss	(15508/8)^0780h,(15508)&7
	goto	u7481
	goto	u7480
u7481:
	goto	l2176
u7480:
	
l2178:	
	line	176
;Display.c: 176: SEG11COM0 = 0;
	bcf	(15627/8)^0780h,(15627)&7
	line	177
	
l2175:	
	line	178
;Display.c: 177: }
;Display.c: 178: if(DpyNum[2]&0x02)
	movlb 0	; select bank0
	btfss	0+(_DpyNum)+02h,(1)&7
	goto	u7491
	goto	u7490
u7491:
	goto	l2184
u7490:
	line	180
	
l2180:	
	movlb 15	; select bank15
	btfss	(15508/8)^0780h,(15508)&7
	goto	u7501
	goto	u7500
u7501:
	goto	l2180
u7500:
	
l2182:	
	line	181
;Display.c: 181: SEG11COM1 = 1;
	bsf	(15651/8)^0780h,(15651)&7
	line	182
;Display.c: 182: }
	goto	l2183
	line	185
	
l2184:	
	movlb 15	; select bank15
	btfss	(15508/8)^0780h,(15508)&7
	goto	u7511
	goto	u7510
u7511:
	goto	l2184
u7510:
	
l2186:	
	line	186
;Display.c: 186: SEG11COM1 = 0;
	bcf	(15651/8)^0780h,(15651)&7
	line	187
	
l2183:	
	line	188
;Display.c: 187: }
;Display.c: 188: if(DpyNum[2]&0x04)
	movlb 0	; select bank0
	btfss	0+(_DpyNum)+02h,(2)&7
	goto	u7521
	goto	u7520
u7521:
	goto	l2192
u7520:
	line	190
	
l2188:	
	movlb 15	; select bank15
	btfss	(15508/8)^0780h,(15508)&7
	goto	u7531
	goto	u7530
u7531:
	goto	l2188
u7530:
	
l2190:	
	line	191
;Display.c: 191: SEG11COM2 = 1;
	bsf	(15675/8)^0780h,(15675)&7
	line	192
;Display.c: 192: }
	goto	l2191
	line	195
	
l2192:	
	movlb 15	; select bank15
	btfss	(15508/8)^0780h,(15508)&7
	goto	u7541
	goto	u7540
u7541:
	goto	l2192
u7540:
	
l2194:	
	line	196
;Display.c: 196: SEG11COM2 = 0;
	bcf	(15675/8)^0780h,(15675)&7
	line	197
	
l2191:	
	line	198
;Display.c: 197: }
;Display.c: 198: if(DpyNum[2]&0x08)
	movlb 0	; select bank0
	btfss	0+(_DpyNum)+02h,(3)&7
	goto	u7551
	goto	u7550
u7551:
	goto	l2200
u7550:
	line	200
	
l2196:	
	movlb 15	; select bank15
	btfss	(15508/8)^0780h,(15508)&7
	goto	u7561
	goto	u7560
u7561:
	goto	l2196
u7560:
	
l2198:	
	line	201
;Display.c: 201: SEG11COM3 = 1;
	bsf	(15699/8)^0780h,(15699)&7
	line	202
;Display.c: 202: }
	goto	l2199
	line	205
	
l2200:	
	movlb 15	; select bank15
	btfss	(15508/8)^0780h,(15508)&7
	goto	u7571
	goto	u7570
u7571:
	goto	l2200
u7570:
	
l2202:	
	line	206
;Display.c: 206: SEG11COM3 = 0;
	bcf	(15699/8)^0780h,(15699)&7
	line	207
	
l2199:	
	line	208
;Display.c: 207: }
;Display.c: 208: if(DpyNum[2]&0x10)
	movlb 0	; select bank0
	btfss	0+(_DpyNum)+02h,(4)&7
	goto	u7581
	goto	u7580
u7581:
	goto	l2208
u7580:
	line	210
	
l2204:	
	movlb 15	; select bank15
	btfss	(15508/8)^0780h,(15508)&7
	goto	u7591
	goto	u7590
u7591:
	goto	l2204
u7590:
	
l2206:	
	line	211
;Display.c: 211: SEG16COM2 = 1;
	bsf	(15680/8)^0780h,(15680)&7
	line	212
;Display.c: 212: }
	goto	l2207
	line	215
	
l2208:	
	movlb 15	; select bank15
	btfss	(15508/8)^0780h,(15508)&7
	goto	u7601
	goto	u7600
u7601:
	goto	l2208
u7600:
	
l2210:	
	line	216
;Display.c: 216: SEG16COM2 = 0;
	bcf	(15680/8)^0780h,(15680)&7
	line	217
	
l2207:	
	line	218
;Display.c: 217: }
;Display.c: 218: if(DpyNum[2]&0x20)
	movlb 0	; select bank0
	btfss	0+(_DpyNum)+02h,(5)&7
	goto	u7611
	goto	u7610
u7611:
	goto	l2216
u7610:
	line	220
	
l2212:	
	movlb 15	; select bank15
	btfss	(15508/8)^0780h,(15508)&7
	goto	u7621
	goto	u7620
u7621:
	goto	l2212
u7620:
	
l2214:	
	line	221
;Display.c: 221: SEG16COM0 = 1;
	bsf	(15632/8)^0780h,(15632)&7
	line	222
;Display.c: 222: }
	goto	l2215
	line	225
	
l2216:	
	movlb 15	; select bank15
	btfss	(15508/8)^0780h,(15508)&7
	goto	u7631
	goto	u7630
u7631:
	goto	l2216
u7630:
	
l2218:	
	line	226
;Display.c: 226: SEG16COM0 = 0;
	bcf	(15632/8)^0780h,(15632)&7
	line	227
	
l2215:	
	line	228
;Display.c: 227: }
;Display.c: 228: if(DpyNum[2]&0x40)
	movlb 0	; select bank0
	btfss	0+(_DpyNum)+02h,(6)&7
	goto	u7641
	goto	u7640
u7641:
	goto	l2224
u7640:
	line	230
	
l2220:	
	movlb 15	; select bank15
	btfss	(15508/8)^0780h,(15508)&7
	goto	u7651
	goto	u7650
u7651:
	goto	l2220
u7650:
	
l2222:	
	line	231
;Display.c: 231: SEG16COM1 = 1;
	bsf	(15656/8)^0780h,(15656)&7
	line	232
;Display.c: 232: }
	goto	l2227
	line	235
	
l2224:	
	movlb 15	; select bank15
	btfss	(15508/8)^0780h,(15508)&7
	goto	u7661
	goto	u7660
u7661:
	goto	l2224
u7660:
	
l2226:	
	line	236
;Display.c: 236: SEG16COM1 = 0;
	bcf	(15656/8)^0780h,(15656)&7
	line	238
	
l2227:	
	return
	opt stack 0
GLOBAL	__end_of_LcdDisplayNum
	__end_of_LcdDisplayNum:
;; =============== function _LcdDisplayNum ends ============

	signat	_LcdDisplayNum,88
	global	_highISR
psect	intentry,class=CODE,delta=2
global __pintentry
__pintentry:

;; *************** function _highISR *****************
;; Defined at:
;;		line 83 in file "F:\work\WYP\NBIoT\Main.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;  rx              1    6[COMMON] unsigned char 
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, fsr0l, fsr0h, fsr1l, fsr1h, status,2, status,0, btemp+0, btemp+1, pclath, cstack
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 1E/0
;;		Unchanged: FFFE0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       0       0       0       0       0       0       0
;;      Locals:         1       0       0       0       0       0       0       0
;;      Temps:          0       0       0       0       0       0       0       0
;;      Totals:         1       0       0       0       0       0       0       0
;;Total ram usage:        1 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    2
;; This function calls:
;;		_ATCommand_ProcRx
;; This function is called by:
;;		Interrupt level 1
;; This function uses a non-reentrant model
;;
psect	intentry
	file	"F:\work\WYP\NBIoT\Main.c"
	line	83
	global	__size_of_highISR
	__size_of_highISR	equ	__end_of_highISR-_highISR
	
_highISR:	
	opt	stack 6
; Regs used in _highISR: [allreg]
psect	intentry
	pagesel	$
	line	85
	
i1l30738:	
;Main.c: 84: unsigned char rx;
;Main.c: 85: if(RCIE&&RCIF)
	movlb 1	; select bank1
	btfss	(1165/8)^080h,(1165)&7
	goto	u420_21
	goto	u420_20
u420_21:
	goto	i1l30750
u420_20:
	
i1l30740:	
	movlb 0	; select bank0
	btfss	(141/8),(141)&7
	goto	u421_21
	goto	u421_20
u421_21:
	goto	i1l30750
u421_20:
	line	87
	
i1l30742:	
;Main.c: 86: {
;Main.c: 87: RCIF=0;
	bcf	(141/8),(141)&7
	line	88
;Main.c: 88: if(OERR==1)
	movlb 3	; select bank3
	btfss	(3305/8)^0180h,(3305)&7
	goto	u422_21
	goto	u422_20
u422_21:
	goto	i1l30746
u422_20:
	line	90
	
i1l30744:	
;Main.c: 89: {
;Main.c: 90: CREN=0;
	bcf	(3308/8)^0180h,(3308)&7
	line	91
;Main.c: 91: OERR=0;
	bcf	(3305/8)^0180h,(3305)&7
	line	92
;Main.c: 92: CREN=1;
	bsf	(3308/8)^0180h,(3308)&7
	line	94
	
i1l30746:	
;Main.c: 93: }
;Main.c: 94: rx=RCREG;
	movf	(409)^0180h,w	;volatile
	movwf	(highISR@rx)
	line	95
	
i1l30748:	
;Main.c: 95: ATCommand_ProcRx(rx);
	movf	(highISR@rx),w
	fcall	_ATCommand_ProcRx
	line	97
	
i1l30750:	
;Main.c: 96: }
;Main.c: 97: if(TMR1IF&& TMR1IE)
	movlb 0	; select bank0
	btfss	(136/8),(136)&7
	goto	u423_21
	goto	u423_20
u423_21:
	goto	i1l6542
u423_20:
	
i1l30752:	
	movlb 1	; select bank1
	btfss	(1160/8)^080h,(1160)&7
	goto	u424_21
	goto	u424_20
u424_21:
	goto	i1l6542
u424_20:
	line	99
	
i1l30754:	
# 99 "F:\work\WYP\NBIoT\Main.c"
clrwdt ;#
psect	intentry
	line	100
;Main.c: 100: TMR1IF=0;
	movlb 0	; select bank0
	bcf	(136/8),(136)&7
	line	101
	
i1l30756:	
;Main.c: 101: ((void)(TMR1H=((15536)>>8),TMR1L=((15536)&0xFF)));
	movlw	(03Ch)
	movwf	(23)	;volatile
	movlw	(0B0h)
	movwf	(22)	;volatile
	line	102
	
i1l30758:	
;Main.c: 102: SystemTick++;
	incf	(_SystemTick),f
	skipnz
	incf	(_SystemTick+1),f
	line	104
	
i1l6542:	
	retfie
	opt stack 0
GLOBAL	__end_of_highISR
	__end_of_highISR:
;; =============== function _highISR ends ============

	signat	_highISR,88
	global	_ATCommand_ProcRx
psect	text2064,local,class=CODE,delta=2
global __ptext2064
__ptext2064:

;; *************** function _ATCommand_ProcRx *****************
;; Defined at:
;;		line 27 in file "F:\work\WYP\NBIoT\ATCommand.c"
;; Parameters:    Size  Location     Type
;;  rx              1    wreg     unsigned char 
;; Auto vars:     Size  Location     Type
;;  rx              1    5[COMMON] unsigned char 
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, fsr1l, fsr1h, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 1F/3
;;		On exit  : 1F/3
;;		Unchanged: FFFE0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       0       0       0       0       0       0       0
;;      Locals:         1       0       0       0       0       0       0       0
;;      Temps:          3       0       0       0       0       0       0       0
;;      Totals:         4       0       0       0       0       0       0       0
;;Total ram usage:        4 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    1
;; This function calls:
;;		_isgraph
;; This function is called by:
;;		_highISR
;; This function uses a non-reentrant model
;;
psect	text2064
	file	"F:\work\WYP\NBIoT\ATCommand.c"
	line	27
	global	__size_of_ATCommand_ProcRx
	__size_of_ATCommand_ProcRx	equ	__end_of_ATCommand_ProcRx-_ATCommand_ProcRx
	
_ATCommand_ProcRx:	
	opt	stack 5
; Regs used in _ATCommand_ProcRx: [wreg+fsr1l-status,0+pclath+cstack]
;ATCommand_ProcRx@rx stored from wreg
	movwf	(ATCommand_ProcRx@rx)
	line	28
	
i1l30760:	
;ATCommand.c: 28: if(ATCommand_Flags.bRx)
	btfss	(_ATCommand_Flags),1
	goto	u425_21
	goto	u425_20
u425_21:
	goto	i1l15190
u425_20:
	goto	i1l15191
	line	29
	
i1l15190:	
	line	30
;ATCommand.c: 30: if(ATCommand_Clear!='\0')
	movf	(_ATCommand_Clear),w
	skipz
	goto	u426_20
	goto	i1l15192
u426_20:
	line	32
	
i1l30764:	
;ATCommand.c: 31: {
;ATCommand.c: 32: if(rx==ATCommand_Clear)
	movf	(ATCommand_ProcRx@rx),w
	xorwf	(_ATCommand_Clear),w
	skipz
	goto	u427_21
	goto	u427_20
u427_21:
	goto	i1l15192
u427_20:
	line	34
	
i1l30766:	
;ATCommand.c: 33: {
;ATCommand.c: 34: ATCommand_RxCount=0;
	clrf	(_ATCommand_RxCount)
	line	35
	
i1l30768:	
;ATCommand.c: 35: ATCommand_RxList[ATCommand_RxCount]='\0';
	movf	(_ATCommand_RxCount),w
	addlw	low 8588
	movwf	fsr1l
	movlw	high 8588
	skipnc
	movlw	high (8588)+1
	movwf	(fsr1l)+1
	clrf	indf1
	goto	i1l15191
	line	38
	
i1l15192:	
	line	39
;ATCommand.c: 37: }
;ATCommand.c: 38: }
;ATCommand.c: 39: if(ATCommand_Flags.bChar)
	btfss	(_ATCommand_Flags),0
	goto	u428_21
	goto	u428_20
u428_21:
	goto	i1l30786
u428_20:
	line	41
	
i1l30772:	
;ATCommand.c: 40: {
;ATCommand.c: 41: ATCommand_RxList[ATCommand_RxCount++]=rx;
	movf	(ATCommand_ProcRx@rx),w
	movwf	(??_ATCommand_ProcRx+0)+0
	movf	(_ATCommand_RxCount),w
	addlw	low 8588
	movwf	(??_ATCommand_ProcRx+1)+0
	movlw	high 8588
	skipnc
	movlw	high (8588)+1
	movwf	((??_ATCommand_ProcRx+1)+0)+1
	movf	0+(??_ATCommand_ProcRx+1)+0,w
	movwf	fsr1l
	movf	1+(??_ATCommand_ProcRx+1)+0,w
	movwf	fsr1h
	movf	(??_ATCommand_ProcRx+0)+0,w
	movwf	indf1
	
i1l30774:	
	incf	(_ATCommand_RxCount),f
	line	42
	
i1l30776:	
;ATCommand.c: 42: if(ATCommand_RxCount>=100)
	movlw	(064h)
	subwf	(_ATCommand_RxCount),w
	skipc
	goto	u429_21
	goto	u429_20
u429_21:
	goto	i1l30780
u429_20:
	line	44
	
i1l30778:	
;ATCommand.c: 43: {
;ATCommand.c: 44: ATCommand_RxCount=0;
	clrf	(_ATCommand_RxCount)
	line	45
;ATCommand.c: 45: }
	goto	i1l30782
	line	48
	
i1l30780:	
;ATCommand.c: 46: else
;ATCommand.c: 47: {
;ATCommand.c: 48: ATCommand_RxList[ATCommand_RxCount]='\0';
	movf	(_ATCommand_RxCount),w
	addlw	low 8588
	movwf	fsr1l
	movlw	high 8588
	skipnc
	movlw	high (8588)+1
	movwf	(fsr1l)+1
	clrf	indf1
	line	50
	
i1l30782:	
;ATCommand.c: 49: }
;ATCommand.c: 50: if(!ATCommand_Flags.bWaitData)
	btfsc	(_ATCommand_Flags),2
	goto	u430_21
	goto	u430_20
u430_21:
	goto	i1l15191
u430_20:
	line	53
	
i1l30784:	
;ATCommand.c: 51: {
;ATCommand.c: 52: ;;
;ATCommand.c: 53: ATCommand_RxCount=0;
	clrf	(_ATCommand_RxCount)
	goto	i1l15191
	line	58
	
i1l30786:	
;ATCommand.c: 56: else
;ATCommand.c: 57: {
;ATCommand.c: 58: if(isgraph(rx)==1)
	movf	(ATCommand_ProcRx@rx),w
	fcall	_isgraph
	btfss	status,0
	goto	u431_21
	goto	u431_20
u431_21:
	goto	i1l15191
u431_20:
	line	60
	
i1l30788:	
;ATCommand.c: 59: {
;ATCommand.c: 60: ATCommand_Flags.bChar=1;
	bsf	(_ATCommand_Flags),0
	line	61
	
i1l30790:	
;ATCommand.c: 61: ATCommand_RxList[ATCommand_RxCount++]=rx;
	movf	(ATCommand_ProcRx@rx),w
	movwf	(??_ATCommand_ProcRx+0)+0
	movf	(_ATCommand_RxCount),w
	addlw	low 8588
	movwf	(??_ATCommand_ProcRx+1)+0
	movlw	high 8588
	skipnc
	movlw	high (8588)+1
	movwf	((??_ATCommand_ProcRx+1)+0)+1
	movf	0+(??_ATCommand_ProcRx+1)+0,w
	movwf	fsr1l
	movf	1+(??_ATCommand_ProcRx+1)+0,w
	movwf	fsr1h
	movf	(??_ATCommand_ProcRx+0)+0,w
	movwf	indf1
	
i1l30792:	
	incf	(_ATCommand_RxCount),f
	line	62
	
i1l30794:	
;ATCommand.c: 62: if(ATCommand_RxCount>=100)
	movlw	(064h)
	subwf	(_ATCommand_RxCount),w
	skipc
	goto	u432_21
	goto	u432_20
u432_21:
	goto	i1l30768
u432_20:
	goto	i1l30766
	line	69
	
i1l15191:	
	return
	opt stack 0
GLOBAL	__end_of_ATCommand_ProcRx
	__end_of_ATCommand_ProcRx:
;; =============== function _ATCommand_ProcRx ends ============

	signat	_ATCommand_ProcRx,4216
	global	_isgraph
psect	text2065,local,class=CODE,delta=2
global __ptext2065
__ptext2065:

;; *************** function _isgraph *****************
;; Defined at:
;;		line 13 in file "C:\Program Files (x86)\HI-TECH Software\PICC\9.71a\sources\isgraph.c"
;; Parameters:    Size  Location     Type
;;  c               1    wreg     unsigned char 
;; Auto vars:     Size  Location     Type
;;  c               1    1[COMMON] unsigned char 
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 1F/3
;;		On exit  : 1F/3
;;		Unchanged: FFFE0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6
;;      Params:         0       0       0       0       0       0       0       0
;;      Locals:         2       0       0       0       0       0       0       0
;;      Temps:          0       0       0       0       0       0       0       0
;;      Totals:         2       0       0       0       0       0       0       0
;;Total ram usage:        2 bytes
;; Hardware stack levels used:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_ATCommand_ProcRx
;; This function uses a non-reentrant model
;;
psect	text2065
	file	"C:\Program Files (x86)\HI-TECH Software\PICC\9.71a\sources\isgraph.c"
	line	13
	global	__size_of_isgraph
	__size_of_isgraph	equ	__end_of_isgraph-_isgraph
	
_isgraph:	
	opt	stack 4
; Regs used in _isgraph: [wreg+status,2+status,0]
;isgraph@c stored from wreg
	movwf	(isgraph@c)
	line	14
	
i1l30870:	
	clrf	(_isgraph$31845)
	
i1l30872:	
	movlw	(07Fh)
	subwf	(isgraph@c),w
	skipnc
	goto	u441_21
	goto	u441_20
u441_21:
	goto	i1l30878
u441_20:
	
i1l30874:	
	movlw	(021h)
	subwf	(isgraph@c),w
	skipc
	goto	u442_21
	goto	u442_20
u442_21:
	goto	i1l30878
u442_20:
	
i1l30876:	
	clrf	(_isgraph$31845)
	incf	(_isgraph$31845),f
	
i1l30878:	
	rrf	(_isgraph$31845),w
	
	line	15
	
i1l27757:	
	return
	opt stack 0
GLOBAL	__end_of_isgraph
	__end_of_isgraph:
;; =============== function _isgraph ends ============

	signat	_isgraph,4216
psect	text2066,local,class=CODE,delta=2
global __ptext2066
__ptext2066:
	global	btemp
	btemp set 07Eh

	DABS	1,126,2	;btemp
	global	wtemp0
	wtemp0 set btemp
global __pbssBIGRAM
__pbssBIGRAM	equ	8588
	end
