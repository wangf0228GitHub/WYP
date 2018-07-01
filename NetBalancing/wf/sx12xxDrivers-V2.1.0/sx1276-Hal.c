#include "main.h"
#include "platform.h"
#include ".\sx12xxDrivers-V2.1.0\src\radio\sx1276-Hal.h"




void SX1276InitIo( void )
{
    
}

void SX1276SetReset( uint8_t state )
{ 
     if( state == RADIO_RESET_ON )
     {
         // Set RESET pin to 0
		 HAL_GPIO_WritePin(RF_CSN_GPIO_Port,RF_CSN_Pin,GPIO_PIN_RESET); 
     }
     else
     {
		 HAL_GPIO_WritePin(RF_CSN_GPIO_Port,RF_CSN_Pin,GPIO_PIN_SET);
     }
}

void SX1276Write( uint8_t addr, uint8_t data )
{
    SX1276WriteBuffer( addr, &data, 1 );
}

void SX1276Read( uint8_t addr, uint8_t *data )
{
    SX1276ReadBuffer( addr, data, 1 );
}

void SX1276WriteBuffer( uint8_t addr, uint8_t *buffer, uint8_t size )
{
//     uint8_t i;
// 
//     //NSS = 0;
//     GPIO_WriteBit( NSS_IOPORT, NSS_PIN, Bit_RESET );
// 
//     SpiInOut( addr | 0x80 );
//     for( i = 0; i < size; i++ )
//     {
//         SpiInOut( buffer[i] );
//     }
// 
//     //NSS = 1;
//     GPIO_WriteBit( NSS_IOPORT, NSS_PIN, Bit_SET );
}

void SX1276ReadBuffer( uint8_t addr, uint8_t *buffer, uint8_t size )
{
    uint8_t i;

//     //NSS = 0;
//     GPIO_WriteBit( NSS_IOPORT, NSS_PIN, Bit_RESET );
// 
//     SpiInOut( addr & 0x7F );
// 
//     for( i = 0; i < size; i++ )
//     {
//         buffer[i] = SpiInOut( 0 );
//     }
// 
//     //NSS = 1;
//     GPIO_WriteBit( NSS_IOPORT, NSS_PIN, Bit_SET );
}

void SX1276WriteFifo( uint8_t *buffer, uint8_t size )
{
    SX1276WriteBuffer( 0, buffer, size );
}

void SX1276ReadFifo( uint8_t *buffer, uint8_t size )
{
    SX1276ReadBuffer( 0, buffer, size );
}

inline uint8_t SX1276ReadDio0( void )
{
	return HAL_GPIO_ReadPin(RF_SDN_GPIO_Port,RF_SDN_Pin);
   //return 0;//GPIO_ReadInputDataBit( DIO0_IOPORT, DIO0_PIN );
}

inline uint8_t SX1276ReadDio1( void )
{
   return 0;// return GPIO_ReadInputDataBit( DIO1_IOPORT, DIO1_PIN );
}

inline uint8_t SX1276ReadDio2( void )
{
    return 0;//return GPIO_ReadInputDataBit( DIO2_IOPORT, DIO2_PIN );
}

inline uint8_t SX1276ReadDio3( void )
{
    return 0;//return IoePinGet( RF_DIO3_PIN );
}

inline uint8_t SX1276ReadDio4( void )
{
    return 0;//return IoePinGet( RF_DIO4_PIN );
}

inline uint8_t SX1276ReadDio5( void )
{
    return 0;//return IoePinGet( RF_DIO5_PIN );
}

inline void SX1276WriteRxTx( uint8_t txEnable )
{
//     if( txEnable != 0 )
//     {
//         IoePinOn( FEM_CTX_PIN );
//         IoePinOff( FEM_CPS_PIN );
//     }
//     else
//     {
//         IoePinOff( FEM_CTX_PIN );
//         IoePinOn( FEM_CPS_PIN );
//     }
}

