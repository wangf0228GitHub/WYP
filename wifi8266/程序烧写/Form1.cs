using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO.Ports;
using WFNetLib;
using System.Threading;
using System.Diagnostics;
using System.Runtime.InteropServices;
using System.Media;

namespace 程序烧写
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        public const int MB_ICONEXCLAMATION = 48;
        [DllImport("user32.dll")]
        public static extern bool MessageBeep(uint uType);


        [DllImport("kernel32.dll", EntryPoint = "Beep")]
        // 第一个参数是指频率的高低，越大越高，第二个参数是指响的时间多长  
        public static extern int Beep(
        int dwFreq,
        int dwDuration
        );  

        private void Form1_Load(object sender, EventArgs e)
        {            
            string[] ports = SerialPort.GetPortNames();
            Array.Sort(ports);
            cbCom.Items.Clear();
            cbCom.Items.AddRange(ports);
            cbCom.SelectedIndex = 0;
            InitTxData();
            
        }
        bool bComRead = false;
        bool bComReadExit = true;
        string oldID;
        private void button1_Click(object sender, EventArgs e)
        {
            if (textBox1.Text.Length != 15)
            {
                MessageBox.Show("设备ID长度需要为15位");
                return;
            }
            if (oldID == textBox1.Text)
            {
                MessageBox.Show("不能两次连续下载相同ID");
                return;
            }
            if (button1.Text == "烧写")
            {
                progressBar1.Value = progressBar1.Minimum;
                serialPort1.Close();
                serialPort1.PortName = cbCom.Text;
                if (!WFGlobal.OpenSerialPort(ref serialPort1, "所选"))
                {
                    return;
                }
                textBox1.Enabled = false;
                button1.Text = "停止";                
                bComRead = true;
                Thread t = new Thread(ComProc_Read);
                t.Start();
            }
            else
            {
                bComRead = false;
                while (!bComReadExit) ;
                button1.Text = "烧写";
                serialPort1.Close();
                textBox1.Enabled = true;
            }            
        }
        void ComProc_Read()
        {
            bComReadExit = false;
            int start = Environment.TickCount - 100000;
            bool bNext=false;
            while (true)
            {
                serialPort1.ReadTimeout = 100;
                while (bComRead)
                {
                    serialPort1.Write(txFrame1, 0, txFrame1.Length);
                    Debug.WriteLine(WFNetLib.StringFunc.StringsFunction.byteToHexStr(txFrame1, " "));
                    bNext = false;
                    InitRxFrame();
                    while (bComRead)
                    {
                        try
                        {                            
                            if (DataPacketed((byte)serialPort1.ReadByte()))
                            {
                                if (CheckPocket(0x08))
                                {
                                    bNext = true;
                                    break;
                                }
                            }
                        }
                        catch// (System.Exception ex)
                        {
                            break;
                        }
                    }
                    if (bNext)
                        break;
                }
                if (!bComRead)
                    break;
                if(!bNext)
                    break;
                this.Invoke((EventHandler)(delegate
                {
                    button1.Enabled = false;
                }));
                serialPort1.ReadTimeout = 5000;
                Thread.Sleep(500);
                serialPort1.DiscardInBuffer();
                bNext = true;
                for (int i = 2; i < 22; i++)
                {
                    if (TxFrameProc(i) == false)
                    {
                        bNext = false;
                        break;
                    }
                    if (!bComRead)
                        break;
                }
                if (!bNext)
                {
                    MessageBox.Show("烧写发生错误!");
                    break;
                }
                if (!WaitPocket())
                {
                    MessageBox.Show("烧写发生错误!");
                    break;
                }
                byte[] blank = Properties.Resources.blank;
                byte[] eagle_flash = Properties.Resources.eagle_flash;
                byte[] eagle_irom0text = Properties.Resources.eagle_irom0text;
                byte[] ID = new byte[4096];
                byte[] esp_init_data_default = Properties.Resources.esp_init_data_default;
                int[] len = new int[5];                
                len[0] = eagle_flash.Length / 4096;
                if (eagle_flash.Length % 4096 != 0)
                {
                    len[0]++;
                    eagle_flash = new byte[len[0] * 4096];
                    for(int i=0;i<Properties.Resources.eagle_flash.Length;i++)
                    {
                        eagle_flash[i] = Properties.Resources.eagle_flash[i];
                    }
                    for (int i = Properties.Resources.eagle_flash.Length; i < (len[0] * 4096); i++)
                    {
                        eagle_flash[i] = 0xff;
                    }
                }
                len[1] =1;
                for (int i = 0; i < 4096; i++)
                {
                    ID[i] = 0x00;
                }
                byte[] bid = Encoding.ASCII.GetBytes(textBox1.Text);
                for (int i = 0; i < bid.Length;i++ )
                {
                    ID[i] = bid[i];
                } 
                len[2] = eagle_irom0text.Length / 4096;
                if (eagle_irom0text.Length % 4096 != 0)
                {
                    len[2]++;
                    eagle_irom0text = new byte[len[2] * 4096];
                    Array.Copy(Properties.Resources.eagle_irom0text, 0, eagle_irom0text,0,Properties.Resources.eagle_irom0text.Length);
                    for (int i = Properties.Resources.eagle_irom0text.Length; i < (len[2] * 4096); i++)
                    {
                        eagle_irom0text[i] = 0xff;
                    }
                }
                len[3] = esp_init_data_default.Length / 4096;
                if (esp_init_data_default.Length % 4096 != 0)
                {
                    len[3]++;
                    esp_init_data_default = new byte[len[3] * 4096];
                    for (int i = 0; i < Properties.Resources.esp_init_data_default.Length; i++)
                    {
                        esp_init_data_default[i] = Properties.Resources.esp_init_data_default[i];
                    }
                    for (int i = Properties.Resources.esp_init_data_default.Length; i < (len[3] * 4096); i++)
                    {
                        esp_init_data_default[i] = 0xff;
                    }
                }
                len[4] = blank.Length / 4096;
                if (blank.Length % 4096 != 0)
                {
                    len[4]++;
                    blank = new byte[len[4] * 4096];
                    for (int i = 0; i < Properties.Resources.blank.Length; i++)
                    {
                        blank[i] = Properties.Resources.blank[i];
                    }
                    for (int i = Properties.Resources.blank.Length; i < (len[4] * 4096); i++)
                    {
                        blank[i] = 0xff;
                    }
                }
                int count = 0;
                for (int i = 0; i < 5; i++)
                {                    
                    len[i] = len[i] * 4;
                    count += len[i];
                }
                count += 4;
                this.Invoke((EventHandler)(delegate
                {
                    progressBar1.Maximum = count;
                }));
                /************************************************************************/
                /*  eagle_flash                                                         */
                /************************************************************************/
                serialPort1.Write(txFrame_Start, 0, 3);
                Debug.WriteLine(WFNetLib.StringFunc.StringsFunction.byteToHexStr(txFrame_Start, " "));
                Thread.Sleep(100);
                serialPort1.Write(txFrame_File1, 0, txFrame_File1.Length);
                Debug.WriteLine(WFNetLib.StringFunc.StringsFunction.byteToHexStr(txFrame_File1, " "));
                if (!WaitPocket())
                {
                    MessageBox.Show("烧写发生错误!");
                    break;
                }
                bNext = true;
                for (int i = 0; i < len[0]; i++)
                {
                    this.Invoke((EventHandler)(delegate
                    {
                        progressBar1.PerformStep();
                    }));
                    serialPort1.Write(eagle_flash, i*1024, 1024);
                    Debug.WriteLine(WFNetLib.StringFunc.StringsFunction.byteToHexStr(eagle_flash, i*1024,1024," "));
                    if (!WaitPocket())
                    {
                        bNext = false;
                        break;
                    }
                }
                if (!bNext)
                {
                    MessageBox.Show("烧写发生错误!");
                    break;
                }
                if (!WaitPocket())
                {
                    MessageBox.Show("烧写发生错误!");
                    break;
                }
                if (!WaitPocket())
                {
                    MessageBox.Show("烧写发生错误!");
                    break;
                }
                /************************************************************************/
                /*  ID                                                         */
                /************************************************************************/
                serialPort1.Write(txFrame_Start, 0, 3);
                Debug.WriteLine(WFNetLib.StringFunc.StringsFunction.byteToHexStr(txFrame_Start, " "));
                Thread.Sleep(100);
                serialPort1.Write(txFrame_File2, 0, txFrame_File2.Length);
                Debug.WriteLine(WFNetLib.StringFunc.StringsFunction.byteToHexStr(txFrame_File2, " "));
                if (!WaitPocket())
                {
                    MessageBox.Show("烧写发生错误!");
                    break;
                }
                bNext = true;
                for (int i = 0; i < len[1]; i++)
                {
                    this.Invoke((EventHandler)(delegate
                    {
                        progressBar1.PerformStep();
                    }));
                    serialPort1.Write(ID, i * 1024, 1024);
                    Debug.WriteLine(WFNetLib.StringFunc.StringsFunction.byteToHexStr(ID, i * 1024, 1024, " "));
                    if (!WaitPocket())
                    {
                        bNext = false;
                        break;
                    }
                }
                if (!bNext)
                {
                    MessageBox.Show("烧写发生错误!");
                    break;
                }
                if (!WaitPocket())
                {
                    MessageBox.Show("烧写发生错误!");
                    break;
                }
                if (!WaitPocket())
                {
                    MessageBox.Show("烧写发生错误!");
                    break;
                }
                /************************************************************************/
                /*  Param                                                               */
                /************************************************************************/
                serialPort1.Write(txFrame_Start, 0, 3);
                Debug.WriteLine(WFNetLib.StringFunc.StringsFunction.byteToHexStr(txFrame_Start, " "));
                Thread.Sleep(100);
                serialPort1.Write(txFrame_FileParam, 0, txFrame_FileParam.Length);
                Debug.WriteLine(WFNetLib.StringFunc.StringsFunction.byteToHexStr(txFrame_FileParam, " "));
                if (!WaitPocket())
                {
                    MessageBox.Show("烧写发生错误!");
                    break;
                }
                bNext = true;
                byte[] Param = new byte[4096];
                for (int i = 0; i < 4096; i++)
                {
                    Param[i] = 0xff;
                }
                for (int i = 0; i < len[1]; i++)
                {
                    this.Invoke((EventHandler)(delegate
                    {
                        progressBar1.PerformStep();
                    }));
                    serialPort1.Write(Param, i * 1024, 1024);
                    Debug.WriteLine(WFNetLib.StringFunc.StringsFunction.byteToHexStr(Param, i * 1024, 1024, " "));
                    if (!WaitPocket())
                    {
                        bNext = false;
                        break;
                    }
                }
                if (!bNext)
                {
                    MessageBox.Show("烧写发生错误!");
                    break;
                }
                if (!WaitPocket())
                {
                    MessageBox.Show("烧写发生错误!");
                    break;
                }
                if (!WaitPocket())
                {
                    MessageBox.Show("烧写发生错误!");
                    break;
                }
                /************************************************************************/
                /* eagle_irom0text                                                      */
                /************************************************************************/
                serialPort1.Write(txFrame_Start, 0, 3);
                Debug.WriteLine(WFNetLib.StringFunc.StringsFunction.byteToHexStr(txFrame_Start, " "));
                Thread.Sleep(100);
                serialPort1.Write(txFrame_File3, 0, txFrame_File3.Length);
                Debug.WriteLine(WFNetLib.StringFunc.StringsFunction.byteToHexStr(txFrame_File3, " "));
                if (!WaitPocket())
                {
                    MessageBox.Show("烧写发生错误!");
                    break;
                }
                bNext = true;
                for (int i = 0; i < len[2]; i++)
                {
                    this.Invoke((EventHandler)(delegate
                    {
                        progressBar1.PerformStep();
                    }));
                    serialPort1.Write(eagle_irom0text, i * 1024, 1024);
                    Debug.WriteLine(WFNetLib.StringFunc.StringsFunction.byteToHexStr(eagle_irom0text, i * 1024, 1024, " "));
                    if (!WaitPocket())
                    {
                        bNext = false;
                        break;
                    }
                }
                if (!bNext)
                {
                    MessageBox.Show("烧写发生错误!");
                    break;
                }
                if (!WaitPocket())
                {
                    MessageBox.Show("烧写发生错误!");
                    break;
                }
                if (!WaitPocket())
                {
                    MessageBox.Show("烧写发生错误!");
                    break;
                }
                /************************************************************************/
                /* esp_init_data_default                                                */
                /************************************************************************/
                serialPort1.Write(txFrame_Start, 0, 3);
                Debug.WriteLine(WFNetLib.StringFunc.StringsFunction.byteToHexStr(txFrame_Start, " "));
                Thread.Sleep(100);
                serialPort1.Write(txFrame_File4, 0, txFrame_File4.Length);
                Debug.WriteLine(WFNetLib.StringFunc.StringsFunction.byteToHexStr(txFrame_File4, " "));
                if (!WaitPocket())
                {
                    MessageBox.Show("烧写发生错误!");
                    break;
                }
                bNext = true;
                for (int i = 0; i < len[3]; i++)
                {
                    this.Invoke((EventHandler)(delegate
                    {
                        progressBar1.PerformStep();
                    }));
                    serialPort1.Write(esp_init_data_default, i * 1024, 1024);
                    Debug.WriteLine(WFNetLib.StringFunc.StringsFunction.byteToHexStr(esp_init_data_default, i * 1024, 1024, " "));
                    if (!WaitPocket())
                    {
                        bNext = false;
                        break;
                    }
                }
                if (!bNext)
                {
                    MessageBox.Show("烧写发生错误!");
                    break;
                }
                if (!WaitPocket())
                {
                    MessageBox.Show("烧写发生错误!");
                    break;
                }
                if (!WaitPocket())
                {
                    MessageBox.Show("烧写发生错误!");
                    break;
                }
                /************************************************************************/
                /* blank                                                                */
                /************************************************************************/
                serialPort1.Write(txFrame_Start, 0, 3);
                Debug.WriteLine(WFNetLib.StringFunc.StringsFunction.byteToHexStr(txFrame_Start, " "));
                Thread.Sleep(100);
                serialPort1.Write(txFrame_File5, 0, txFrame_File5.Length);
                Debug.WriteLine(WFNetLib.StringFunc.StringsFunction.byteToHexStr(txFrame_File5, " "));
                if (!WaitPocket())
                {
                    MessageBox.Show("烧写发生错误!");
                    break;
                }
                bNext = true;
                for (int i = 0; i < len[4]; i++)
                {
                    this.Invoke((EventHandler)(delegate
                    {
                        progressBar1.PerformStep();
                    }));
                    serialPort1.Write(blank, i * 1024, 1024);
                    Debug.WriteLine(WFNetLib.StringFunc.StringsFunction.byteToHexStr(blank, i * 1024, 1024, " "));
                    if (!WaitPocket())
                    {
                        bNext = false;
                        break;
                    }
                }
                if (!bNext)
                {
                    MessageBox.Show("烧写发生错误!");
                    break;
                }
                if (!WaitPocket())
                {
                    MessageBox.Show("烧写发生错误!");
                    break;
                }
                if (!WaitPocket())
                {
                    MessageBox.Show("烧写发生错误!");
                    break;
                }
                /************************************************************************/
                /* 完成                                                                 */
                /************************************************************************/
                this.Invoke((EventHandler)(delegate
                {
                    textBox1.Text="";
                }));
                oldID = textBox1.Text;
                SoundPlayer sp;
                sp = new SoundPlayer(Properties.Resources.下载完成);
                sp.Play();
                MessageBox.Show("烧写成功!");
                break;
            }
            serialPort1.Close();
            this.Invoke((EventHandler)(delegate
            {
                button1.Text = "烧写";
                textBox1.Enabled = true;
                button1.Enabled = true;
            }));
            bComReadExit = true;
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (button1.Text != "烧写")
            {
                bComRead = false;
                while (!bComReadExit) ;
                serialPort1.Close();
            }
        }
    }
}
