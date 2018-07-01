#include "rf.h"

uint8_t mode;
uint8_t Freq_Sel;
uint8_t Power_Sel;
uint8_t Lora_Rate_Sel;
uint8_t BandWide_Sel;
uint8_t Fsk_Rate_Sel;

uint32_t sx1276_7_8_Tick;

uint8_t gb_SF;
uint8_t  gb_BW;
//uint8_t  CR;	      //LR_RegModemConfig1 
  
#define sx1276_7_8_CRC   0x01  //CRC Enable

#define datlen 11

uint8_t gtmp;
/**********************************************************
**Parameter table define
**********************************************************/

//============================
/**********************************************************
**Parameter table define
**********************************************************/
const uint8_t sx1276_7_8FreqTbl[1][3] = 
{ 
  {0x6C, 0x80, 0x00}, //434MHz
};

const uint8_t sx1276_7_8PowerTbl[4] =
{ 
  0xFF,                   //20dbm  
  0xFC,                   //17dbm
  0xF9,                   //14dbm
  0xF6,                   //11dbm 
};

const uint8_t sx1276_7_8SpreadFactorTbl[7] =
{
  6,7,8,9,10,11,12
};

const uint8_t sx1276_7_8LoRaBwTbl[10] =
{
//7.8KHz,10.4KHz,15.6KHz,20.8KHz,31.2KHz,41.7KHz,62.5KHz,125KHz,250KHz,500KHz
  0,1,2,3,4,5,6,7,8,9
};

const uint8_t sx1276_7_8Data[] = {"HR_WT Lora sx1276_7_8"};


///////////////////////////////////////////////// Test mode //////////////////////////////////////////////////
const uint8_t TxTestFiFoData[57] = {
						0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
						0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
						0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
						0xff, 0xff, 
						0xff, 0xff, 0xff, 0xff, 
						0xff, 
						0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
						0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
						0xff, 0xff, 
						0xff, 0xff, 0xff, 0xff, 0xff
                        };

uint8_t RxData[64];

/**********************************************************
**Name:     SPIRead
**Function: SPI Read CMD
**Input:    adr -> address for read
**Output:   None
**********************************************************/
uint8_t sx1276_7_8_SPIRead(uint8_t addr)
{
  uint8_t tmp; 
  //NSS = 0;
  SX1276_CSN_Low();

  SX1276_SPIProc( addr & 0x7F );
  tmp=SX1276_SPIProc( 0 )
  SX1276_CSN_High();
  return(tmp);
}
/**********************************************************
**Name:     SPIWrite
**Function: SPI Write CMD
**Input:    WrPara -> address & data
**Output:   None
**********************************************************/
void sx1276_7_8_SPIWrite(uint8_t addr, uint8_t data)                
{
	//NSS = 0;
	SX1276_CSN_Low();
	SX1276_SPIProc( addr | 0x80 );
	SX1276_SPIProc( data );
	//NSS = 1;
	SX1276_CSN_High();
}

/**********************************************************
**Name:     SPIBurstRead
**Function: SPI burst read mode
**Input:    adr-----address for read
**          ptr-----data buffer point for read
**          length--how many bytes for read
**Output:   None
**********************************************************/
void sx1276_7_8_SPIBurstRead(uint8_t addr, uint8_t *buffer, uint8_t length)
{
	uint8_t i;
	//NSS = 0;
	SX1276_CSN_Low();

	SX1276_SPIProc( addr & 0x7F );

	for( i = 0; i < length; i++ )
	{
		buffer[i] = SX1276_SPIProc( 0 );
	}
	SX1276_CSN_High();
}
/**********************************************************
**Name:     SPIBurstWrite
**Function: SPI burst write mode
**Input:    adr-----address for write
**          ptr-----data buffer point for write
**          length--how many bytes for write
**Output:   none
**********************************************************/
void sx1276_7_8_SPIBurstWrite(uint8_t addr, uint8_t *buffer, uint8_t length)
{
	uint8_t i;
	//NSS = 0;
	SX1276_CSN_Low();
	SX1276_SPIProc( addr | 0x80 );
	for( i = 0; i < length; i++ )
	{
		SX1276_SPIProc( buffer[i] );
	}
	//NSS = 1;
	SX1276_CSN_High();
}

/**********************************************************
**Name:     sx1276_7_8_Standby
**Function: Entry standby mode
**Input:    None
**Output:   None
**********************************************************/
void sx1276_7_8_Standby(void)
{
  sx1276_7_8_SPIWrite(LR_RegOpMode,0x09);                              		//Standby//Low Frequency Mode
	//SPIWrite(LR_RegOpMode,0x01);                              	 //Standby//High Frequency Mode
}
/**********************************************************
**Name:     sx1276_7_8_Sleep
**Function: Entry sleep mode
**Input:    None
**Output:   None
**********************************************************/
void sx1276_7_8_Sleep(void)
{
  sx1276_7_8_SPIWrite(LR_RegOpMode,0x08);                              		//Sleep//Low Frequency Mode
	//SPIWrite(LR_RegOpMode,0x00);                            		 //Sleep//High Frequency Mode
}

/*********************************************************/
//LoRa mode
/*********************************************************/
/**********************************************************
**Name:     sx1276_7_8_EntryLoRa
**Function: Set RFM69 entry LoRa(LongRange) mode
**Input:    None
**Output:   None
**********************************************************/
void sx1276_7_8_EntryLoRa(void)
{
  sx1276_7_8_SPIWrite(LR_RegOpMode,0x88);//Low Frequency Mode
	//SPIWrite(LR_RegOpMode,0x80);//High Frequency Mode
}

/**********************************************************
**Name:     sx1276_7_8_LoRaClearIrq
**Function: Clear all irq
**Input:    None
**Output:   None
**********************************************************/
void sx1276_7_8_LoRaClearIrq(void)
{
  sx1276_7_8_SPIWrite(LR_RegIrqFlags,0xFF);
}

/**********************************************************
**Name:     sx1276_7_8_Config
**Function: sx1276_7_8 base config
**Input:    mode
**Output:   None
**********************************************************/
void sx1276_7_8_Config(uint8_t mode)
{
  uint8_t i; 
    
  sx1276_7_8_Sleep();                                      //Change modem mode Must in Sleep mode 
  for(i=250;i!=0;i--)                                      //Delay
    ;
	wfDelay_ms(15);

  if(mode == 0x01)//lora mode
  {
    sx1276_7_8_EntryLoRa();  
    //SPIWrite(0x5904);   //?? Change digital regulator form 1.6V to 1.47V: see errata note
    
		sx1276_7_8_SPIBurstWrite(LR_RegFrMsb,(uint8_t *)sx1276_7_8FreqTbl[Freq_Sel],3);  //setting frequency parameter

    //setting base parameter 
    sx1276_7_8_SPIWrite(LR_RegPaConfig,sx1276_7_8PowerTbl[Power_Sel]);             //Setting output power parameter  
    
    sx1276_7_8_SPIWrite(LR_RegOcp,0x0B);                              //RegOcp,Close Ocp
    sx1276_7_8_SPIWrite(LR_RegLna,0x23);                              //RegLNA,High & LNA Enable
    
    if(sx1276_7_8SpreadFactorTbl[Lora_Rate_Sel]==6)           //SFactor=6
    {
      uint8_t tmp;
      sx1276_7_8_SPIWrite(LR_RegModemConfig1,((sx1276_7_8LoRaBwTbl[BandWide_Sel]<<4)+(sx1276_7_8_CR<<1)+0x01));//Implicit Enable CRC Enable(0x02) & Error Coding rate 4/5(0x01), 4/6(0x02), 4/7(0x03), 4/8(0x04)
      sx1276_7_8_SPIWrite(LR_RegModemConfig2,((sx1276_7_8SpreadFactorTbl[Lora_Rate_Sel]<<4)+(sx1276_7_8_CRC<<2)+0x03));
      
      tmp = sx1276_7_8_SPIRead(0x31);
      tmp &= 0xF8;
      tmp |= 0x05;
      sx1276_7_8_SPIWrite(0x31,tmp);
      sx1276_7_8_SPIWrite(0x37,0x0C);
    } 
    else
    {
      sx1276_7_8_SPIWrite(LR_RegModemConfig1,((sx1276_7_8LoRaBwTbl[BandWide_Sel]<<4)+(sx1276_7_8_CR<<1)+0x00));//Explicit Enable CRC Enable(0x02) & Error Coding rate 4/5(0x01), 4/6(0x02), 4/7(0x03), 4/8(0x04)
      sx1276_7_8_SPIWrite(LR_RegModemConfig2,((sx1276_7_8SpreadFactorTbl[Lora_Rate_Sel]<<4)+(sx1276_7_8_CRC<<2)+0x03));  //SFactor &  LNA gain set by the internal AGC loop 
    }
    sx1276_7_8_SPIWrite(LR_RegSymbTimeoutLsb,0xFF);                   //RegSymbTimeoutLsb Timeout = 0x3FF(Max) 
    
    sx1276_7_8_SPIWrite(LR_RegPreambleMsb,0x00);                       //RegPreambleMsb 
    sx1276_7_8_SPIWrite(LR_RegPreambleLsb,12);                      //RegPreambleLsb 8+4=12byte Preamble
    
    sx1276_7_8_SPIWrite(REG_LR_DIOMAPPING2,0x01);                     //RegDioMapping2 DIO5=00, DIO4=01
  
  }
  else
  {
		sx1276_7_8_Sleep();                                      //Change modem mode Must in Sleep mode 
		sx1276_7_8_SPIBurstWrite(LR_RegFrMsb,(uint8_t *)sx1276_7_8FreqTbl[Freq_Sel],3);  //setting frequency parameter
		
    sx1276_7_8_SPIWrite(LR_RegPaConfig,sx1276_7_8PowerTbl[Power_Sel]);             //Setting output power parameter
    
    sx1276_7_8_SPIWrite(RegFdevMsb,0x02);
		sx1276_7_8_SPIWrite(RegFdevMsb,0x3d);//Fdev 35k
		
		sx1276_7_8_SPIWrite(RegOcp,0x0b);//Close Ocp
		sx1276_7_8_SPIWrite(RegLna,0x23);//High & LNA Enable
		
		sx1276_7_8_SPIWrite(RegRxBw,0x12);//83KHz
		
		sx1276_7_8_SPIWrite(RegPreambleDetect,0xa0);//Enable 2Byte 
		sx1276_7_8_SPIWrite(RegPreambleMsb,0x00);
		sx1276_7_8_SPIWrite(RegPreambleLsb,0x06);//6Byte Preamble
		
		sx1276_7_8_SPIWrite(RegSyncConfig,0x92);//Sync 2+1=3bytes
		sx1276_7_8_SPIWrite(RegSyncValue1,0xaa);
		sx1276_7_8_SPIWrite(RegSyncValue2,0x2d);
		sx1276_7_8_SPIWrite(RegSyncValue3,0xd4);//SyncWord = aa2dd4
		
		sx1276_7_8_SPIWrite(RegPacketConfig1,0x00);//Disable CRC,NRZ
		sx1276_7_8_SPIWrite(RegPacketConfig2,0x40);//Packet Mode
		
		sx1276_7_8_SPIWrite(RegPayloadLength,0x15);//21bytes Fixed
		sx1276_7_8_SPIWrite(RegFifoThresh,0x95);//FiFoThresh   21bytes 
  }
  sx1276_7_8_Standby();                                         //Entry standby mode
}



/**********************************************************
**Name:     sx1276_7_8_LoRaEntryRx
**Function: Entry Rx mode
**Input:    None
**Output:   None
**********************************************************/
uint8_t sx1276_7_8_LoRaEntryRx(void)
{
  uint8_t addr; 
        
  sx1276_7_8_Config(1);                                         //setting base parameter
  
  sx1276_7_8_SPIWrite(REG_LR_PADAC,0x84);                              //Normal and Rx
  sx1276_7_8_SPIWrite(LR_RegHopPeriod,0xFF);                          //RegHopPeriod NO FHSS
  sx1276_7_8_SPIWrite(REG_LR_DIOMAPPING1,0x01);                       //DIO0=00, DIO1=00, DIO2=00, DIO3=01
      
  sx1276_7_8_SPIWrite(LR_RegIrqFlagsMask,0x3F);                       //Open RxDone interrupt & Timeout
  sx1276_7_8_LoRaClearIrq();   
  
  sx1276_7_8_SPIWrite(LR_RegPayloadLength,21);                       //RegPayloadLength  21byte(this register must difine when the data long of one byte in SF is 6)
    
  addr = sx1276_7_8_SPIRead(LR_RegFifoRxBaseAddr);           				//Read RxBaseAddr
  sx1276_7_8_SPIWrite(LR_RegFifoAddrPtr,addr);                        //RxBaseAddr -> FiFoAddrPtr  
  sx1276_7_8_SPIWrite(LR_RegOpMode,0x8d);                        		//Continuous Rx Mode//Low Frequency Mode
	//SPIWrite(LR_RegOpMode,0x05);                        		//Continuous Rx Mode//High Frequency Mode
	sx1276_7_8_Tick=HAL_GetTick();
	//delayms(15);
	while(1)
	{
		if((sx1276_7_8_SPIRead(LR_RegModemStat)&0x04)==0x04)   //Rx-on going RegModemStat
			break;
		if(GetDeltaTick(sx1276_7_8_Tick)>300)	
			return 0;                                              //over time for error
	}
}

/**********************************************************
**Name:     sx1276_7_8_LoRaReadRSSI
**Function: Read the RSSI value
**Input:    none
**Output:   temp, RSSI value
**********************************************************/
uint8_t sx1276_7_8_LoRaReadRSSI(void)
{
  uint16_t temp=10;
  temp=sx1276_7_8_SPIRead(LR_RegRssiValue);                  //Read RegRssiValue,Rssi value
  temp=temp+127-137;                                       //127:Max RSSI, 137:RSSI offset
  return (uint8_t)temp;
}

/**********************************************************
**Name:     sx1276_7_8_LoRaRxPacket
**Function: Receive data in LoRa mode
**Input:    None
**Output:   1- Success
            0- Fail
**********************************************************/
uint8_t sx1276_7_8_LoRaRxPacket(void)
{
  uint8_t i; 
  uint8_t addr;
  uint8_t packet_size;
 
  if(bRFIRQ())
  {
    for(i=0;i<32;i++) 
      RxData[i] = 0x00;
    
    addr = sx1276_7_8_SPIRead(LR_RegFifoRxCurrentaddr);      //last packet addr
    sx1276_7_8_SPIWrite(LR_RegFifoAddrPtr,addr);                      //RxBaseAddr -> FiFoAddrPtr    
    if(sx1276_7_8SpreadFactorTbl[Lora_Rate_Sel]==6)           //When SpreadFactor is six,will used Implicit Header mode(Excluding internal packet length)
      packet_size=21;
    else
      packet_size = sx1276_7_8_SPIRead(LR_RegRxNbBytes);     //Number for received bytes    
    sx1276_7_8_SPIBurstRead(0x00, RxData, packet_size);
    
    sx1276_7_8_LoRaClearIrq();
		if(RxData[3]==0x03)
		return(1);
		else
    return(0);
/*		
    for(i=0;i<17;i++)
    {
      if(RxData[i]!=sx1276_7_8Data[i])
			
        break;  
    }    
    if(i>=13)                                              //Rx success
      return(1);
    else
      return(0);
*/		
		
  }
  else
    return(0);
}
/**********************************************************
**Name:     sx1276_7_8_LoRaEntryTx
**Function: Entry Tx mode
**Input:    None
**Output:   None
**********************************************************/
uint8_t sx1276_7_8_LoRaEntryTx(void)
{
  uint8_t addr,temp;
    
  sx1276_7_8_Config(1);                                         //setting base parameter
    
  sx1276_7_8_SPIWrite(REG_LR_PADAC,0x87);                                   //Tx for 20dBm
  sx1276_7_8_SPIWrite(LR_RegHopPeriod,0x00);                               //RegHopPeriod NO FHSS
  sx1276_7_8_SPIWrite(REG_LR_DIOMAPPING1,0x41);                       //DIO0=01, DIO1=00, DIO2=00, DIO3=01
  
  sx1276_7_8_LoRaClearIrq();
  sx1276_7_8_SPIWrite(LR_RegIrqFlagsMask,0xF7);                       //Open TxDone interrupt
  sx1276_7_8_SPIWrite(LR_RegPayloadLength,21);                       //RegPayloadLength  21byte
  
  addr = sx1276_7_8_SPIRead(LR_RegFifoTxBaseAddr);           //RegFiFoTxBaseAddr
  sx1276_7_8_SPIWrite(LR_RegFifoAddrPtr,addr);                        //RegFifoAddrPtr

  sx1276_7_8_Tick=HAL_GetTick();
  //delayms(15);
  while(1)
  {
	  temp=sx1276_7_8_SPIRead(LR_RegPayloadLength);
	  if(temp==21)
	  {
		  break; 
	  }
	  if(GetDeltaTick(sx1276_7_8_Tick)>300)	
		  return 0;                                              //over time for error
  }
}
/**********************************************************
**Name:     sx1276_7_8_LoRaTxPacket
**Function: Send data in LoRa mode
**Input:    None
**Output:   1- Send over
**********************************************************/
uint8_t sx1276_7_8_LoRaTxPacket(void)
{ 
	uint8_t i;
  uint8_t TxFlag=0;
  uint8_t addr;
	
  for(i=0;i<32;i++) 
      RxData[i] = i;
	//BurstWrite(0x00, (uint8_t *)sx1276_7_8Data, 21);
	sx1276_7_8_SPIBurstWrite(0x00, RxData, 21);
	sx1276_7_8_SPIWrite(LR_RegOpMode,0x8b);                    //Tx Mode           
	while(1)
	{
		if(bRFIRQ())                      //Packet send over
		{      
			sx1276_7_8_SPIRead(LR_RegIrqFlags);
			sx1276_7_8_LoRaClearIrq();                                //Clear irq
				
			sx1276_7_8_Standby();                                     //Entry Standby mode      
			
			break;
		}
	} 
}

/**********************************************************
**Name:     sx1276_7_8_ReadRSSI
**Function: Read the RSSI value
**Input:    none
**Output:   temp, RSSI value
**********************************************************/
uint8_t sx1276_7_8_ReadRSSI(void)
{
  uint8_t temp=0xff;
	
  temp=sx1276_7_8_SPIRead(0x11);
  temp>>=1;
  temp=127-temp;                                           //127:Max RSSI
  return temp;
}


void sx1276_7_8_TestConfig(void)
{
  uint8_t i;
  
  for(i=200;i!=0;i--)                                      //Delay
    ; 
  for(i=200;i!=0;i--)                                      //Delay
    ;  
	wfDelay_ms(15);  
  sx1276_7_8_Sleep();                                           //Change modem mode Must in Sleep mode 
	sx1276_7_8_Sleep();                                           //Change modem mode Must in Sleep mode 
	wfDelay_ms(20);

  sx1276_7_8_SPIBurstWrite(LR_RegFrMsb,(uint8_t *)sx1276_7_8FreqTbl[Freq_Sel],3);  //setting frequency parameter
	
	sx1276_7_8_SPIWrite(LR_RegPaConfig,sx1276_7_8PowerTbl[Power_Sel]);             //Setting output power parameter
	
	sx1276_7_8_SPIWrite(RegFdevMsb,0x02);
	sx1276_7_8_SPIWrite(RegFdevMsb,0x3d);//Fdev 35k
		
	sx1276_7_8_SPIWrite(RegOcp,0x0b);//Close Ocp
	//SPIWrite(RegLna,0x23);//High & LNA Enable
	sx1276_7_8_SPIWrite(RegLna,0x20);//High & LNA disable
	
	sx1276_7_8_SPIWrite(RegRxBw,0x12);//83KHz
	
	sx1276_7_8_SPIWrite(RegPreambleDetect,0xa0);//Enable 2Byte
	//SPIWrite(RegPreambleDetect,0x20);//disable
	
	sx1276_7_8_SPIWrite(RegPreambleMsb,0x00);
	sx1276_7_8_SPIWrite(RegPreambleLsb,0x00);//0Byte Preamble
	
	sx1276_7_8_SPIWrite(RegPacketConfig1,0x00);//fix packet Disable CRC,NRZ
	//SPIWrite(RegPacketConfig2,0x40);//Packet Mode
	
  sx1276_7_8_Standby();  
}





