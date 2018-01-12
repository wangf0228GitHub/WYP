using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace TempDataInterfaceDLL
{
    public class TempData
    {
        public String _Caller;//呼入电话号
        public DateTime _CallInTime;//呼入时间
        public Single _Temperature;//温度
        public Byte _ErrFlag;//错误标志
    }

    public class CallData
    {
        public int UserIndex;
        public string caller;
        public DateTime callin_time;
        public int Delay;
        public CallData()
        {
            caller = "";
            Delay = 0;
        }
    }
    
}
