using System;
using System.Collections.Generic;
using System.Text;
using WFNetLib.PacketProc;
using WFNetLib;

namespace WFNetLib.PacketProc
{
    /// <summary>
    /// 包头
    /// </summary>
    public class CP1616PacketHead
    {
        /// <summary>
        /// 包头大小
        /// </summary>        
        public static Int32 Addr_SIZE = 2;
        public static Int32 DataLen_SIZE = 2;
        public static Int32 CommandLen_SIZE = 1;
        public static Int32 HEAD_SIZE = 7;
        public UInt16 RxAddr;
        public byte Command;
        public UInt16 Len = 0;
        public byte[] Data;
        public CP1616PacketHead()
        {
            Data=new byte[HEAD_SIZE];
        }
    }
    public class CP1616Packet
    {
        public CP1616PacketHead Header;
        public byte[] Data;
        public int RxCount;
        public byte[] RxList;
        public byte NeedCommand;
        public UInt16 NeedAddr;
        public static Int32 BUFFER_SIZE = 1024;
        public CP1616Packet(byte com,UInt16 addr)
        {
            NeedCommand=com;
            NeedAddr=addr;
            Header=new CP1616PacketHead();
            RxCount = 0;
        }
        public CP1616Packet()
        {
            NeedCommand=0xff;
            NeedAddr=0xffff;
            Header=new CP1616PacketHead();
            RxCount = 0;
        }
        public static byte[] MakeCP1616Packet(byte com, UInt16 addr, byte b)
        {
            return MakeCP1616Packet(com, addr, new byte[] { b });
        }
        public static byte[] MakeCP1616Packet(byte com, UInt16 addr, byte[] data)
        {
            byte[] txbuffer = new byte[CP1616PacketHead.HEAD_SIZE + data.Length + 2];
            txbuffer[0] = 0x16;
            txbuffer[1] = 0x16;
            txbuffer[2] = BytesOP.GetHighByte(addr);
            txbuffer[3] = BytesOP.GetLowByte(addr);
            txbuffer[4] = com;
            txbuffer[5] = BytesOP.GetHighByte((UInt16)data.Length);
            txbuffer[6] = BytesOP.GetLowByte((UInt16)data.Length);
            for (int i = 0; i < data.Length; i++)
            {
                txbuffer[i + CP1616PacketHead.HEAD_SIZE] = data[i];
            }
            txbuffer[CP1616PacketHead.HEAD_SIZE + data.Length] = Verify.GetVerify_byteSum(txbuffer, CP1616PacketHead.HEAD_SIZE + data.Length);
            txbuffer[CP1616PacketHead.HEAD_SIZE + data.Length + 1] = 0x0d;
            return txbuffer;
        }
        public bool DataPacketed(byte rx)
        {
            //判断读取的字节数+缓冲区已有字节数是否超过缓冲区总大小
            if(RxCount<CP1616PacketHead.HEAD_SIZE)
            {
                Header.Data[RxCount++]=rx;
                if(RxCount==1)
                {
                    if(Header.Data[0]!=0x16)
                    {
                        RxCount=0;
                    }
                }
                else if(RxCount==2)
                {
                    if(Header.Data[1]!=0x16)
                    {
                        RxCount=0;
                    }
                }
                else if(RxCount==4)
                {
                    Header.RxAddr=BytesOP.MakeShort(Header.Data[2],Header.Data[3]);
                    if(NeedAddr!=0xffff)
                    {
                        if((Header.RxAddr!=0xffff)&&(Header.RxAddr!=NeedAddr))
                        {
                            RxCount=0;
                        }
                    }
                }
                else if(RxCount==5)
                {
                    Header.Command=Header.Data[4];
                    if(NeedCommand!=0xff)
                    {
                        if(Header.Command!=NeedCommand)
                        {
                            RxCount=0;
                        }
                    }
                }
                else if(RxCount==7)
                {
                    Header.Len=BytesOP.MakeShort(Header.Data[5],Header.Data[6]);
                    Data=new byte[Header.Len+2];
                }
            }
            else
            {
                Data[RxCount-CP1616PacketHead.HEAD_SIZE]=rx;
                RxCount++;
                if(RxCount==(CP1616PacketHead.HEAD_SIZE+Header.Len+2))
                {
                    if (Data[Data.Length - 1] == 0x0d)
                    {
                        byte s1 = Verify.GetVerify_byteSum(Header.Data);
                        byte s2 = Verify.GetVerify_byteSum(Data, Data.Length - 2);
                        s1 = (byte)(s1 + s2);
                        if (s1 == Data[Data.Length - 2])
                            return true;
                    }
                    else
                    {
                        RxCount = 0;
                        return false;
                    }
                }
            }
            return false;
        }        
    }
}
