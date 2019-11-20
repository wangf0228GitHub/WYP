using System;
using System.Collections.Generic;

using System.Text;

namespace WFNetLib
{
    public class Verify
    {
#region 和校验

        static public byte GetVerify_byteSum(byte[] pBuff)
        {
            return GetVerify_byteSum(pBuff, 0, pBuff.Length);
        }
        static public byte GetVerify_byteSum(byte[] pBuff, int count)
        {
            return GetVerify_byteSum(pBuff, 0, count);
        }
        static public byte GetVerify_byteSum(byte[] pBuff, int start, int count)
        {
            byte sum = 0;
            for (int i = 0; i < count; i++)
                sum = (byte)(sum + pBuff[i + start]);
            return sum;
        }
        static public byte GetVerify_byteSum(List<byte> pBuff)
        {
            return GetVerify_byteSum(pBuff, 0, pBuff.Count);
        }
        static public byte GetVerify_byteSum(List<byte> pBuff, int count)
        {
            return GetVerify_byteSum(pBuff, 0, count);
        }
        static public byte GetVerify_byteSum(List<byte> pBuff, int start, int count)
        {
            return GetVerify_byteSum(pBuff.ToArray(),start,count);
        }
#endregion
        
#region 字节异或校验

        static public byte GetVerify_byteXOR(byte[] pBuff, int count)
        {
            return GetVerify_byteXOR(pBuff, 0, count);
        }
        static public byte GetVerify_byteXOR(byte[] pBuff, int start, int count)
        {
            byte ret=pBuff[start];
            for (int i = 1; i < count; i++)
            {
                ret = (byte)(ret ^ pBuff[start + i]);
            }
            return ret;
        }

#endregion



#region IP/ICMP/IGMP/TCP/UDP等协议的校验
        static public ushort GetVerify_IP(byte[] pBuff)
        {
            return GetVerify_IP(pBuff, 0, pBuff.Length);
        }
        static public ushort GetVerify_IP(byte[] pBuff, int count)
        {
            return GetVerify_IP(pBuff, 0, count);
        }
        static public ushort GetVerify_IP(byte[] pBuff, int start, int count)
        {
            uint cksum=0;
            if (count % 2 != 0)
            {
                cksum += BytesOP.MakeShort(pBuff[count - 1],0);
            }
            for (int i = 0; i < count-1; i = i + 2)
            {
                ushort x = BytesOP.MakeShort(pBuff[i],pBuff[i+1]);
                cksum += x;
            }
            cksum = (cksum >> 16) + (cksum & 0xffff);
            return (ushort)(~cksum);
        }
#endregion
    }
}
