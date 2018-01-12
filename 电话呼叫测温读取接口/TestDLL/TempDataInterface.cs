using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Collections;
using System.Threading;
using System.Net;
using System.IO;

namespace TempDataInterfaceDLL
{
    public class TempDataInterface
    {
        public delegate void ShowTextCallbackDelegate(string str);
        public ShowTextCallbackDelegate ShowText = null;


        public delegate void NewTempDataCallbackDelegate(TempData td);
        public NewTempDataCallbackDelegate NewTempData = null;

        public delegate void NewCallDataCallbackDelegate(TempData td);
        public NewCallDataCallbackDelegate NewCallData = null;



        public Thread PeriodGetDataThreadIns = null;

        public void StartPeriodGetDataProc()
        {            
            PeriodGetDataThreadIns = new Thread(new ThreadStart(PeriodGetDataProc));
            PeriodGetDataThreadIns.Name = "周期访问端口";
            PeriodGetDataThreadIns.Start();
        }
        public void StopPeriodGetDataProc()
        {
            PeriodGetDataThreadIns.Abort();
            //while (!bPeriodGetDataThreadIsStop) ;
        }
        private void PeriodGetDataProc()
        {
            try
            {
                while(true)
                {
                    CheckData();
                    Thread.Sleep(1000);
                }
            }
            catch {}
        }
        string[] calls;
        public void CheckData()
        {
            TempData td = new TempData();
            Random r = new Random();
            td._Caller = calls[r.Next(0,30)];
            td._CallInTime = DateTime.Now;//整数的时间            
            td._Temperature = r.Next(11,29)+((float)r.Next(0,10))/10;
            td._ErrFlag = (byte)r.Next(0, 2);
            if (NewTempData != null)
            {
                NewTempData(td);
            }
            td._Temperature = r.Next(11, 29) + ((float)r.Next(0, 10)) / 10;
            if (NewCallData != null)
            {
                NewCallData(td);
            }
        }
        
        public TempDataInterface(DateTime LastDateTime)
        {
            calls = new string[30];
            calls[0]="045187722301";
            calls[1]="045187722302";
            calls[2]="045187722303";
            calls[3]="045187722304";
            calls[4]="045187722305";
            calls[5]="045187722306";
            calls[6]="045187722307";
            calls[7]="045187722308";
            calls[8]="045187722309";
            calls[9]="045187722310";
            calls[10]="045187722311";
            calls[11]="045187722312";
            calls[12]="045187722313";
            calls[13]="045187722314";
            calls[14]="045187722315";
            calls[15]="045187722316";
            calls[16]="045187722317";
            calls[17]="045187722318";
            calls[18]="045187722319";
            calls[19]="045187722320";
            calls[20]="045187722321";
            calls[21]="045187722322";
            calls[22]="045187722323";
            calls[23]="045187722324";
            calls[24]="045187722325";
            calls[25]="045187722326";
            calls[26]="045187722327";
            calls[27]="045187722328";
            calls[28]="045187722329";
            calls[29]="045187722330";
        }
    }
}
