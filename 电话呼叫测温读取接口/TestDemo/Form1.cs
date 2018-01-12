using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Net;
using System.IO;
using System.Runtime.Serialization;
using TempDataInterfaceDLL;


namespace TestDemo
{    
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();                  
            tempDataInterface = new TempDataInterface(DateTime.Now);//实际应用时，应该使用数据库中最后一条呼叫数据的时间
            tempDataInterface.NewTempData = new TempDataInterface.NewTempDataCallbackDelegate(NewTempData);
            tempDataInterface.NewCallData = new TempDataInterface.NewCallDataCallbackDelegate(NewCallData);
        }
        void NewTempData(TempData td)
        {
            ShowText("温度数据");
            ShowText("电话号:"+td._Caller);
            ShowText("温度:"+td._Temperature.ToString());
            ShowText("时间:"+td._CallInTime.ToString());
            ShowText("状态标值:"+td._ErrFlag.ToString());
            ShowText("--------------------------------------------------------");
        }
        void NewCallData(TempData td)
        {
            ShowText("呼叫数据");
            ShowText("电话号:" + td._Caller);
            ShowText("温度:" + td._Temperature.ToString());
            ShowText("时间:" + td._CallInTime.ToString());
            ShowText("状态标值:" + td._ErrFlag.ToString());
            ShowText("--------------------------------------------------------");
        }
        
        TempDataInterface tempDataInterface;
        private delegate void ShowTextLog(string str);
        private void ShowTextLogProc(string str)
        {
            str += "\r\n";
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
    }
    
}
