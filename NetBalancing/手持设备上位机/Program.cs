using System;
using System.Collections.Generic;
using System.Windows.Forms;
using WFNetLib.PacketProc;

namespace 手持设备上位机
{
    static class Program
    {
        /// <summary>
        /// 应用程序的主入口点。
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            CP1616PacketHead.Addr_SIZE = 0;
            CP1616PacketHead.CalcHeaderLen();
            Application.Run(new Form1());
        }
    }
}
