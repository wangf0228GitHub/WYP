using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using WFNetLib.PacketProc;
using System.IO.Ports;
using WFNetLib;
using System.Threading;

namespace 手持设备上位机
{
    public partial class Form4 : Form
    {
        public Form4(System.IO.Ports.SerialPort x)
        {
            InitializeComponent();
            COMPort1 = x;
        }
        System.IO.Ports.SerialPort COMPort1;
        private void button1_Click(object sender, EventArgs e)
        {
            CP1616Packet Rx1616 = new CP1616Packet(100, 1);            
            bool bOK = false;
            for (int i = 0; i < 3; i++)
            {
                try
                {
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
                                return;
                            }
                        }
                        catch
                        { break; }
                    }
                    if (bOK)
                        break;
                    Thread.Sleep(100);
                }
                catch
                {
                    break;
                }
            }
            MessageBox.Show("设定失败");
        }
    }
}
