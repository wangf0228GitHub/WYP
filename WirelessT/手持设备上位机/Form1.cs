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
        private void button1_Click(object sender, EventArgs e)
        {
            bool bOK = false;
            if (button1.Text == "连接设备")
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
                                        button2.Enabled = true;
                                        button3.Enabled = true;
                                        button4.Enabled = true;
                                        bOK = true;
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
            else
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
                    button2.Enabled = false;
                    button3.Enabled = false;
                    button4.Enabled = false;
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
                            button2.Enabled = false;
                            button3.Enabled = false;
                            button4.Enabled = false;
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
        
        private void button2_Click(object sender, EventArgs e)
        {
            string session = JsonWork.login();
            if (session == "")
                return;
            WFHttpWebResponse web = new WFHttpWebResponse();
            IDictionary<string, string> p = new Dictionary<string, string>();
            p.Add("session",session);
            p.Add("device_id", DeviceID.ToString());
            HttpWebResponse hr = web.CreatePostHttpResponse(JsonWork.strUrl + "get_device_list", p);
            JsonAddrListReturn AddrList = JsonWork.GetJsonObject<JsonAddrListReturn>(web.Content);
            if (AddrList.code != "200")
            {
                MessageBox.Show("获取数据失败:" + AddrList.message);
                return;
            }
            enBT(false);
//             ExcelImport el = new ExcelImport(true, "安装位置");
//             DataTable dt = el.ExcelImportProc_OleDB();
//             if (dt == null || dt.Rows.Count < 100 || dt.Columns.Count < 2)
//             {
//                 MessageBox.Show("地址数据文件格式有问题，请检查!");
//                 return;
//             }
            
            byte[] tx;
            byte[] temp;
            byte[] temp1;
            progressBar1.Maximum = AddrList.obj.list.Count;
            progressBar1.Value = 0;
            byte id;
            for (int i = 0; i<AddrList.obj.list.Count; i++)
            {
                Debug.WriteLine(AddrList.obj.list[i].id + "," + AddrList.obj.list[i].name);
                temp = Encoding.Default.GetBytes(AddrList.obj.list[i].name);
                if(!byte.TryParse(AddrList.obj.list[i].id, out id))
                    continue;
                if (id==0)
                {
                    continue;
                }
                id--;
                if (temp.Length > 20)
                {
                    temp1 = new byte[23];                    
                    temp1[0] =id;
                    temp1[1] = 21;
                    temp1[22] = 0;
                    for (int j = 0; j < 20; j++)
                        temp1[j + 2] = temp[j];
                    tx = CP1616Packet.MakeCP1616Packet(3, 1, temp1);
                }
                else
                {
                    temp1 = new byte[3 + temp.Length];
                    temp1[0] = id;
                    temp1[1] = (byte)(temp.Length + 1);
                    temp1[2 + temp.Length] = 0;
                    for (int j = 0; j < temp.Length; j++)
                        temp1[j + 2] = temp[j];
                    tx = CP1616Packet.MakeCP1616Packet(3, 1, temp1);
                }
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
                        progressBar1.Value++;
                        break;
                    }
                    retry--;
                }
                if (retry == 0)
                {
                    MessageBox.Show("第" + (i + 1).ToString() + "个传感器地址设置出错!");
                    break;
                }
            }
            MessageBox.Show("地址数据导入完成!");
            enBT(true);
        }
        void enBT(bool ben)
        {
            button1.Enabled = ben;
            button2.Enabled = ben;
            button3.Enabled = ben;
            button4.Enabled = ben;
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
    }   
}
