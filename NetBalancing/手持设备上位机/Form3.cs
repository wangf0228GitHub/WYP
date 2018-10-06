using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using WFNetLib.PacketProc;

namespace 手持设备上位机
{
    public partial class Form3 : Form
    {
        public Form3(System.IO.Ports.SerialPort x)
        {
            InitializeComponent();
            COMPort1 = x;
        }
        System.IO.Ports.SerialPort COMPort1;

        private void Form3_Load(object sender, EventArgs e)
        {

        }
        CP1616Packet Rx1616;
        private void button1_Click(object sender, EventArgs e)
        {
            
            if (radioButton1.Checked)
            {                
                int retry;
                bool bOK;
                retry = 20;
                bOK = false;
                while (retry != 0)
                {
                    Rx1616 = new CP1616Packet(6, 1);
                    byte[] tx = CP1616Packet.MakeCP1616Packet(6, 1, new byte[2] { 0, 100 });
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
                                MessageBox.Show("清空数据成功");
                                break;
                            }
                        }
                        catch
                        {
                            break;
                        }
                    }
                    if (bOK)
                        break;
                    retry--;
                }
                if (retry == 0)
                {
                    MessageBox.Show("清空数据失败");
                }                
            }
            else if (radioButton2.Checked)
            {
                int retry;
                bool bOK;
                retry = 20;
                bOK = false;
                while (retry != 0)
                {
                    Rx1616 = new CP1616Packet(6, 1);
                    byte[] tx = CP1616Packet.MakeCP1616Packet(6, 1, new byte[2] { (byte)(numericUpDown1.Value-1),(byte)(numericUpDown2.Value) });
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
                                MessageBox.Show("清空数据成功");
                                break;
                            }
                        }
                        catch
                        {
                            break;
                        }
                    }
                    if (bOK)
                        break;
                    retry--;
                }
                if (retry == 0)
                {
                    MessageBox.Show("清空数据失败");
                }
            }
        }
    }
}
