#ifndef   __FlagDefine_h__
#define   __FlagDefine_h__
/************************************************************************/
/* 第一个为最低位                                                       */
/************************************************************************/
typedef union   
{
	struct
	{
		unsigned bNotify:1;
		unsigned b18B20:1;
		unsigned bFirst:1;
		unsigned bErrFull:1;
		unsigned bRetry:1;
	};
	unsigned char AllFlag;
} _GFlags;        // general flags

#define RomCount 2
typedef union   
{
	struct
	{
 		unsigned char sum;//校验和
//  		union   
//  		{
//  			struct
//  			{
//  				unsigned bCall:1;//是否呼叫
// 				unsigned bWinter:1;
//  			};
//  			unsigned char AllFlag;
//  		} SystemState; 		
 		unsigned char bWinter;//是否为冬天
// 		unsigned char ConnectRetry;//连接重试次数
// 		unsigned char MeasurementCycle;//测量间隔
	};
	unsigned char All[RomCount];
} _RomParams;        // general flags
 
#define MaxTList 12
typedef union   
{
	uint T[MaxTList];
	unsigned char All[MaxTList*2];
} _TList;        // general flags
//_ROMParams ROMParams;
#endif
