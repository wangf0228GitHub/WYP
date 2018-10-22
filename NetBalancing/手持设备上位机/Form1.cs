using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.IO.Ports;
using WFNetLib.PacketProc;
using WFNetLib;
using System.Threading;
using System.Diagnostics;
using System.Net;
using WFOffice2007;

namespace 手持设备上位机
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        public void WaitMS(int ms)
        {
            while (ms != 0)
            {
                Application.DoEvents();
                Thread.Sleep(1);
                ms--;
            }
        }
        string PortName;
        public static ushort DeviceID;
        CP1616Packet Rx1616;
        //连接设备
        private void button1_Click(object sender, EventArgs e)
        {
            //bool bOK = false;
            if (button1.Text == "连接设备")//启动串口扫描，连接设备
            {
                Rx1616 = new CP1616Packet(1, 1);
                string[] ports = SerialPort.GetPortNames();
                PortName = "";
                progressBar1.Value = 0;
                int perCount, per;
                perCount = ports.Length * 3;
                per = 100 / perCount;
                foreach (string com in ports)
                {
                    COMPort1.PortName = com;
                    for (int i = 0; i < 3; i++)
                    {
                        progressBar1.Value += per;
                        try
                        {
                            COMPort1.Open();
                            byte[] tx = CP1616Packet.MakeCP1616Packet(1, 1, 1);
                            try
                            {
                                COMPort1.Write(tx, 0, tx.Length);
                            }
                            catch { continue; }
                            while (true)
                            {
                                try
                                {
                                    if (Rx1616.DataPacketed((byte)COMPort1.ReadByte()))
                                    {
                                        DeviceID=BytesOP.MakeShort(Rx1616.Data[0], Rx1616.Data[1]);
                                        label3.Text = "设备ID:" + DeviceID.ToString();
                                        label2.Text=com;//.Show(com);
                                        PortName = com;
                                        progressBar1.Value = 100;
                                        button1.Text = "断开连接";
                                        enBT(true);
                                        //bOK = true;
                                        break;
                                    }
                                }
                                catch
                                { break; }
                            }
                            if (PortName != "")
                                break;
                            COMPort1.Close();
                            Thread.Sleep(100);
                        }
                        catch
                        {
                            break;
                        }
                    }
                    if (PortName != "")
                    {
                        break;
                    }
                }
                if (PortName == "")
                {
                    progressBar1.Value = 100;
                    MessageBox.Show("未找到设备");
                }
            }
            else//已经连接，则断开
            {
                Rx1616 = new CP1616Packet(2, 1);
                byte[] tx = CP1616Packet.MakeCP1616Packet(2, 1, 1);
                try
                {
                    COMPort1.Write(tx, 0, tx.Length);
                }
                catch 
                {
                    PortName = "";
                    progressBar1.Value = 100;
                    button1.Text = "连接设备";
                    label3.Text = "";
                    enBT(false);
                    button1.Enabled = true;
                    COMPort1.Close();
                }
                while (true)
                {
                    try
                    {
                        if (Rx1616.DataPacketed((byte)COMPort1.ReadByte()))
                        {
                            PortName = "";
                            progressBar1.Value = 100;
                            button1.Text = "连接设备";
                            enBT(false);
                            button1.Enabled = true;
                            label3.Text = "";
                            break;
                        }
                    }
                    catch
                    { break; }
                }
                COMPort1.Close();
            }
        }
        //同步地址信息
        private void ImportAddrInfo_Click(object sender, EventArgs e)
        {
            ExcelImport el = new ExcelImport(true, "安装位置");
            DataTable dt = el.ExcelImportProc_OleDB();
            if (dt == null || dt.Rows.Count != 104)
            {
                MessageBox.Show("地址数据文件格式有问题，请检查!");
                return;
            }
            enBT(false);
            
            int areaLen = 64;
            int addrInfoLen = areaLen + 100 * 2;
            byte[] addrInfo = new byte[addrInfoLen];
            for (int i = 0; i < addrInfoLen; i++)
            {
                addrInfo[i] = 0;
            }
            //设备安装小区
            string strInstallArea = dt.Rows[2][1].ToString();
            Debug.WriteLine("设备安装小区：" + strInstallArea);
            byte[] byteInstallArea = Encoding.Default.GetBytes(strInstallArea);
            if (byteInstallArea.Length >= areaLen)
            {
                for (int i = 0; i < areaLen; i++)
                {
                    addrInfo[i] = byteInstallArea[i];
                }
            }
            else
            {
                for (int i = 0; i < byteInstallArea.Length; i++)
                {
                    addrInfo[i] = byteInstallArea[i];
                }
            }
            //栋单元信息处理
            byte dong, danyuan;
            for (int i = 0; i < 100; i++)
            {
                Debug.WriteLine("传感器" + (i + 1).ToString() + "：" + dt.Rows[4 + i][1].ToString() + "-" + dt.Rows[4 + i][2].ToString());
                if (!byte.TryParse(dt.Rows[4 + i][1].ToString(), out dong))
                {
                    MessageBox.Show("单元格B"+(i+5).ToString()+"内容输入有问题，只能输入0-200的数字");
                    return;
                }
                if (!byte.TryParse(dt.Rows[4 + i][2].ToString(), out danyuan))
                {
                    MessageBox.Show("单元格C" + (i + 5).ToString() + "内容输入有问题，只能输入0-200的数字");
                    return;
                }
                addrInfo[areaLen + i * 2] = dong;
                addrInfo[areaLen + i * 2 + 1] = danyuan;                
            }
            byte[] tx=CP1616Packet.MakeCP1616Packet(3, 1, addrInfo);
            int retry = 20;
            Rx1616 = new CP1616Packet(3, 1);
            bool bOK = false;
            while (retry != 0)
            {
                WaitMS(100);
                try
                {
                    COMPort1.Write(tx, 0, tx.Length);
                }
                catch { retry--; continue; }
                while (true)
                {
                    try
                    {
                        if (Rx1616.DataPacketed((byte)COMPort1.ReadByte()))
                        {
                            bOK = true;
                            break;
                        }
                    }
                    catch
                    { break; }
                }
                if (bOK)
                {
                    break;
                }
                retry--;
            }
            if (retry == 0)
            {
                MessageBox.Show("地址数据导入失败，请重试!");
                enBT(true);
            }
            else
            {
                MessageBox.Show("地址数据导入完成!");
                enBT(true);
            }
        }
        void enBT(bool ben)
        {
            button1.Enabled = ben;
            button2.Enabled = ben;
            button3.Enabled = ben;
            button4.Enabled = ben;
            button5.Enabled = ben;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Form2 f = new Form2(COMPort1);
            f.ShowDialog();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            Form3 f = new Form3(COMPort1);
            f.ShowDialog();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            Form4 f = new Form4(COMPort1);
            f.ShowDialog();
        }
    }   
}
