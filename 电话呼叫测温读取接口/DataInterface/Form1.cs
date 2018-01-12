using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using WFNetLib;
using System.Net;
using System.IO;
using System.Runtime.Serialization.Json;
using System.Runtime.Serialization;
using WFNetLib.Log;
using TempDataInterfaceDLL;

namespace DataInterface
{    
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            
            //DataTable dt = 温度数据DataDBOption.DataTableSelect_GetLastDataTime();
            DateTime time;
            time = DateTime.Now;//最开始使用新程序的时间
            tempDataInterface = new TempDataInterface(time.AddMinutes(-20));
            for (int i = 0; i < 10;i++ )
            {
                tempDataInterface.ShowText[i] = new TempDataInterface.ShowTextCallbackDelegate(ShowText);
                tempDataInterface.NewTempData[i] = new TempDataInterface.NewTempDataCallbackDelegate(NewTempData);
                tempDataInterface.NewCallData[i] = new TempDataInterface.NewCallDataCallbackDelegate(NewCallData);
            }
            count = 0;
        }
        void NewTempData(TempData td)
        {
            ShowText(td._Caller + ":" + td._Temperature.ToString() + ":" + td._CallInTime.ToString()+"\r\n\r\n\r\n");
            
        }
        void NewCallData(TempData td)
        {
            //存储数据
//             温度数据Data tData = new 温度数据Data();
//             tData.Caller = td._Caller;
//             tData.CallInTime = td._CallInTime;//整数
//             tData.Temperature = td._Temperature;
//             tData.ErrFlag = td._ErrFlag;
//             温度数据DataDBOption.InsertCall(tData);
        }
        bool bExitThread;
        int count;
        TempDataInterface tempDataInterface;
        private delegate void ShowTextLog(string str);
        private void ShowTextLogProc(string str)
        {
            if (textBox1.Text.Length > 20000)
                textBox1.Clear();
            textBox1.AppendText(str);
        }
        public void ShowText(string str)
        {
            try
            {
                this.Invoke(new ShowTextLog(ShowTextLogProc), str + "\r\n");
            }
            catch
            {
            	
            }
            
        }

        private void toolStripButton2_Click(object sender, EventArgs e)
        {
            if (toolStripButton2.Text == "定时扫描")
            {
                tempDataInterface.StartPeriodGetDataProc();
                toolStripButton2.Text = "停止扫描";
            }
            else
            {
                tempDataInterface.StopPeriodGetDataProc();
                toolStripButton2.Text = "定时扫描";
                textBox1.AppendText("进程已停止\r\n");
            }
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            tempDataInterface.StopPeriodGetDataProc();
        }

        private void toolStripButton1_Click(object sender, EventArgs e)
        {
            tempDataInterface = new TempDataInterface(new DateTime(2015,12,03,15,24,00));
            for (int i = 0; i < 10; i++)
            {
                tempDataInterface.ShowText[i] = new TempDataInterface.ShowTextCallbackDelegate(ShowText);
                tempDataInterface.NewTempData[i] = new TempDataInterface.NewTempDataCallbackDelegate(NewTempData);
                tempDataInterface.NewCallData[i] = new TempDataInterface.NewCallDataCallbackDelegate(NewCallData);
            }
            tempDataInterface.FirstIntCheckTime = new DateTime(2015, 12, 03, 15, 27, 00);
            tempDataInterface.GetData(28, 1);
        }
    }
    
}
