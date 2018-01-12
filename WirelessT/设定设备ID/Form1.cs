using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using WFNetLib.PacketProc;
using WFNetLib;
using System.IO.Ports;
using System.Threading;

namespace 设定设备ID
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        string PortName;
        CP1616Packet Rx1616;
        private void button1_Click(object sender, EventArgs e)
        {
            Rx1616 = new CP1616Packet(100, 1);
            string[] ports = SerialPort.GetPortNames();
            PortName = "";
            progressBar1.Value = 0;
            int perCount, per;
            perCount = ports.Length * 3;
            per = 100 / perCount;
            bool bOK = false;
            foreach (string com in ports)
            {
                COMPort1.PortName = com;
                for (int i = 0; i < 3; i++)
                {
                    progressBar1.Value += per;
                    try
                    {
                        COMPort1.Open();
                        byte[] deviceID = new byte[2];
                        deviceID[0] = BytesOP.GetHighByte((ushort)numericUpDown1.Value);
                        deviceID[1] = BytesOP.GetLowByte((ushort)numericUpDown1.Value);
                        byte[] tx = CP1616Packet.MakeCP1616Packet(100, 1, deviceID);
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
                                    MessageBox.Show("设定成功");
                                    bOK = true;
                                    break;
                                }
                            }
                            catch
                            { break; }
                        }
                        if (bOK)
                            break;
                        COMPort1.Close();
                        Thread.Sleep(100);
                    }
                    catch
                    {
                        break;
                    }
                }
                if (bOK)
                {
                    break;
                }
            }
            if (!bOK)
            {
                progressBar1.Value = 100;
                MessageBox.Show("未找到设备");
            }
            COMPort1.Close();
        }
    }
}
