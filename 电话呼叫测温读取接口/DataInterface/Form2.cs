using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Collections;

namespace DataInterface
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
//             dataProc = new InterfaceProc();
//             dataProc.ShowText = new DataInterface.InterfaceProc.ShowTextCallbackDelegate(ShowText);
        }
//        InterfaceProc dataProc;
        private void button1_Click(object sender, EventArgs e)
        {

//             Hashtable Call1, Call2;
//             Call1 = new Hashtable();
//             Call2 = new Hashtable();
            
            
//            dataProc.CheckData();
//             
//             List<CallData>[] datas=dataProc.GetData(dateTimePicker1.Value, dateTimePicker2.Value);
//             listView1.Items.Clear();
//             int index=0;
//             for (int i = 0; i < 30; i++)
//             {
//                 if (datas[i] == null)
//                     continue;
//                 if (datas[i].Count == 0)
//                     continue;
//                 for (int j = (datas[i].Count-1); j >0; j--)
//                 {
//                     if (Call1.ContainsKey(datas[i][j].caller))
//                     {                        
//                         CallData call= (CallData)Call1[datas[i][j].caller];
//                         Call1.Remove(datas[i][j].caller);
//                         if (call.callin_time.AddSeconds(30) < datas[i][j].callin_time)//超过30秒了，则放弃
//                         {                            
//                             Call1.Add(datas[i][j].caller, datas[i][j]);
//                             ShowText("放弃呼叫数据:" + call.caller + ";" + dataProc.UserName[call.UserIndex] + ";" + call.callin_time.ToString("yyyy-MM-dd HH:mm:ss"));
//                         }
//                         else
//                         {
//                             //组出温度
//                             index++;
//                             ListViewItem lt = listView1.Items.Add(index.ToString());
//                             lt.SubItems.Add(datas[i][j].caller);
//                             lt.SubItems.Add("组出温度");
//                             lt.SubItems.Add(call.callin_time.ToString("HH:mm:ss"));
//                             lt.SubItems.Add(dataProc.UserName[call.UserIndex]);
//                             lt.SubItems.Add(datas[i][j].callin_time.ToString("HH:mm:ss"));
//                             lt.SubItems.Add(dataProc.UserName[datas[i][j].UserIndex]);
//                         }
//                     }
//                     else
//                     {
//                         Call1.Add(datas[i][j].caller, datas[i][j]);
//                     }
//                 }
// 
//             }
        }

        private delegate void ShowTextLog(string str);
        private void ShowTextLogProc(string str)
        {
            str = DateTime.Now.ToString("hh:mm:ss:ffff") + ":  " + str;
            textBox1.AppendText(str);
        }
        public void ShowText(string str)
        {
            this.Invoke(new ShowTextLog(ShowTextLogProc), str + "\r\n");
        }
    }
}
