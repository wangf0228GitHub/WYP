using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;

namespace DataInterface
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
            //WFNetLib.ADO.SQLServerOP.ConnectionString="Data Source=(local)\\SQL2008;Initial Catalog=电话测温平台;Integrated Security=True";
            Application.Run(new Form1());
        }
    }
}
