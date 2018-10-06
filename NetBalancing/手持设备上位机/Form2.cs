using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using WFNetLib.PacketProc;
using WFNetLib;
using Microsoft.Office.Interop.Excel;
//using System.Diagnostics;
using System.Threading;
using System.Net;
using WFOffice2007;

namespace 手持设备上位机
{
    public partial class Form2 : Form
    {
        public Form2(System.IO.Ports.SerialPort x)
        {
            InitializeComponent();
            COMPort1 = x;
        }
        System.IO.Ports.SerialPort COMPort1;
        private void numericUpDown2_ValueChanged(object sender, EventArgs e)
        {
            
        }
        CP1616Packet Rx1616;
        ExcelExport ee;
        List<byte[]> hl;
        List<byte> se;
        List<byte> er;
        private void button1_Click(object sender, EventArgs e)
        {
            if (radioButton1.Checked)
            {
                Rx1616 = new CP1616Packet(4, 1);
                byte[] tx = CP1616Packet.MakeCP1616Packet(4, 1, 1);
                COMPort1.Write(tx, 0, tx.Length);
                while (true)
                {
                    try
                    {
                        if (Rx1616.DataPacketed((byte)COMPort1.ReadByte()))
                        {
                            ee = new ExcelExport(100);
                            ee.ExcelWorkbookCallbackProc = new ExcelExport.ExcelWorkbookCallback(ExcelWorkbookCallbackProc);
                            ee.ExcelExportProc();
                            break;
                        }
                    }
                    catch
                    {
                        MessageBox.Show("读取数据失败");
                        break; 
                    }
                }
            }
            else if (radioButton2.Checked)
            {                
                hl = new List<byte[]>();
                se=new List<byte>();
                er=new List<byte>();
                progressBar1.Value = 0;
                int retry;
                bool bOK;
                for(int i=0;i<100;i++)
                {
                    retry = 20;
                    bOK = false;
                    while(retry!=0)
                    {
                        Rx1616 = new CP1616Packet(5, 1);
                        byte[] tx = CP1616Packet.MakeCP1616Packet(5, 1, (byte)i);
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
                                    //                                 byte[] temp = new byte[Rx1616.Data.Length - 2];
                                    //                                 for (int j = 0; j < Rx1616.Data.Length - 2; j++)
                                    //                                 {
                                    //                                     temp[j]
                                    //                                 }
                                    hl.Add(Rx1616.Data);
                                    se.Add((byte)(i + 1));
                                    progressBar1.Value++;
                                    Thread.Sleep(100);
                                    bOK = true;
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
                        Thread.Sleep(1000);
                    }
                    if (retry == 0)
                    {
                        er.Add((byte)(i + 1));
                    } 
                }
                if (se.Count != 0)
                {
                    if (er.Count != 0)
                    {
                        string str = "如下传感器数据读取失败:\r\n";
                        for (int i = 0; i < er.Count; i++)
                        {
                            str += "第" + er[i].ToString() + "号传感器" + "\r\n";
                        }
                        str += "是否继续保存";
                        if (MessageBox.Show(str, "读取错误", MessageBoxButtons.YesNo) == DialogResult.No)
                            return;
                    }
                    ee = new ExcelExport();
                    ee.SheetCount = se.Count;
                    //ee.ExcelWorkbookCallbackProc = new ExcelExport.ExcelWorkbookCallback(ExcelWorkbookCallbackProc1);
                    //ee.ExcelExportProc1();
                }
                else
                {
                    MessageBox.Show("读取历史数据失败");
                }
            }
            else if (radioButton3.Checked)
            {
                if (numericUpDown2.Value < numericUpDown1.Value)
                {
                    MessageBox.Show("范围有误");
                    return;
                }
                hl = new List<byte[]>();
                se = new List<byte>();
                er = new List<byte>();
                progressBar1.Value = 0;
                int per = (int)(numericUpDown2.Value - numericUpDown1.Value + 1);
                per = 100 / per;
                int retry;
                bool bOK;
                for (int i = (int)(numericUpDown1.Value - 1); i < (int)numericUpDown2.Value; i++)
                {
                    retry = 20;
                    bOK = false;
                    while (retry != 0)
                    {
                        Rx1616 = new CP1616Packet(5, 1);
                        byte[] tx = CP1616Packet.MakeCP1616Packet(5, 1, (byte)i);
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
                                    //                                 byte[] temp = new byte[Rx1616.Data.Length - 2];
                                    //                                 for (int j = 0; j < Rx1616.Data.Length - 2; j++)
                                    //                                 {
                                    //                                     temp[j]
                                    //                                 }
                                    hl.Add(Rx1616.Data);
                                    se.Add((byte)(i + 1));
                                    progressBar1.Value+=per;
                                    Thread.Sleep(100);
                                    bOK = true;
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
                        Thread.Sleep(1000);
                    }
                    if (retry == 0)
                    {
                        er.Add((byte)(i + 1));
                    }
                }
                progressBar1.Value = 100;
                if (se.Count != 0)
                {
                    if (er.Count != 0)
                    {
                        string str = "如下传感器数据读取失败:\r\n";
                        for (int i = 0; i < er.Count; i++)
                        {
                            str += "第" + er[i].ToString() + "号传感器" + "\r\n";
                        }
                        str += "是否继续保存";
                        if (MessageBox.Show(str, "读取错误", MessageBoxButtons.YesNo) == DialogResult.No)
                            return;
                    }
                    ee = new ExcelExport();
                    ee.SheetCount = se.Count;
                    //ee.ExcelWorkbookCallbackProc = new ExcelExport.ExcelWorkbookCallback(ExcelWorkbookCallbackProc1);
                    //ee.ExcelExportProc1();
                }
                else
                {
                    MessageBox.Show("读取历史数据失败");
                }
            }
        }
        private bool ExcelWorkbookCallbackProc(Workbook wBook, int index)
        {
            Worksheet wSheet;
            string str;
            wSheet = (Worksheet)wBook.Worksheets[1];
            Range dr;
            if (index == -1)
            {
                for (int i = 0; i < wBook.Worksheets.Count - 1; i++)
                {
                    wSheet = (Worksheet)wBook.Worksheets[i + 1];
                    wSheet.Delete();
                }
                wSheet = (Worksheet)wBook.Worksheets[1];
                wSheet.Name = "手抄器当前温度数据";
                wSheet.Cells[1, 1] = "设备编号";
                wSheet.Cells[1, 2] = "安装地址";
                wSheet.Cells[1, 3] = "最后一组数据获得时间";
                wSheet.Cells[1, 4] = "温度数据（℃）";
                dr = wSheet.get_Range("A1", "D1");
                dr.Interior.Color = System.Drawing.ColorTranslator.ToOle(System.Drawing.Color.DarkOrange);
                dr.Interior.Pattern = XlPattern.xlPatternSolid;
                dr = wSheet.get_Range("A1", "D101");
                dr.NumberFormat = "@";
            }
            else if (index == int.MaxValue)
            {
                dr = wSheet.get_Range("A1", "D101");
                dr.Columns.AutoFit();
                dr.HorizontalAlignment = XlHAlign.xlHAlignCenter;
                dr.Borders.LineStyle = XlLineStyle.xlContinuous;
            }
            else
            {               
                wSheet.Cells[2 + index, 1] = index+1;
                int n=21;
                for (int i = 0; i < 21; i++)
                {
                    if (Rx1616.Data[index * 27+i]==0)
                    {
                        n = i;
                        break;
                    }
                }
                wSheet.Cells[2 + index, 2] = Encoding.Default.GetString(Rx1616.Data, index * 27,n);
                if (Rx1616.Data[index * 27 + 21] == 0xff)
                {
                    wSheet.Cells[2 + index, 3] = "无";
                    wSheet.Cells[2 + index, 4] = "无";
                }
                else
                {
                    str = Rx1616.Data[index * 27 + 21].ToString("D02") + "-" + Rx1616.Data[index * 27 + 22].ToString("D02") + " " + Rx1616.Data[index * 27 + 23].ToString("D02") + ":" + Rx1616.Data[index * 27 + 24].ToString("D02");
                    wSheet.Cells[2 + index, 3] = str;
//                     Debug.WriteLine(str);
//                     Debug.WriteLine(Rx1616.Data[index * 27 + 26].ToString("X2"));
//                     Debug.WriteLine(Rx1616.Data[index * 27 + 25].ToString("X2"));
                    wSheet.Cells[2 + index, 4] = ((BytesOP.MakeShort(Rx1616.Data[index * 27 + 26], Rx1616.Data[index * 27 + 25])) * 0.0625+0.5).ToString("f1");
                }                
                if (index % 2 == 1)
                {
                    dr = wSheet.get_Range("A" + (2 + index).ToString(), "D" + (2 + index).ToString());
                    dr.Interior.Color = System.Drawing.ColorTranslator.ToOle(System.Drawing.Color.LightGray);
                    dr.Interior.Pattern = XlPattern.xlPatternSolid;
                }
            }
            return true;
        }
        string strAddr;
        /*
        private bool ExcelWorkbookCallbackProc1(Workbook wBook, int index)
        {
            Worksheet wSheet;
            wSheet = (Worksheet)wBook.Worksheets[ee.SheetIndex];
            string str;
            Range dr;
            if (index == -1)
            {
                wSheet.Name = se[ee.SheetIndex-1].ToString("D03");
                wSheet.Cells[1, 1] = "设备编号";
                wSheet.Cells[1, 2] = "安装地址";
                wSheet.Cells[1, 3] = "读取时间";
                wSheet.Cells[1, 4] = "温度数据（℃）";
                dr = wSheet.get_Range("A1", "D1");
                dr.Interior.Color = System.Drawing.ColorTranslator.ToOle(System.Drawing.Color.DarkOrange);
                dr.Interior.Pattern = XlPattern.xlPatternSolid;
                dr = wSheet.get_Range("A1", "D211");
                dr.NumberFormat = "@";
                strAddr = null;
            }
            else if (index == int.MaxValue)
            {
                dr = wSheet.get_Range("A1", "D211");
                dr.Columns.AutoFit();
                dr.HorizontalAlignment = XlHAlign.xlHAlignCenter;
                dr.Borders.LineStyle = XlLineStyle.xlContinuous;
            }
            else
            {
                int ix = hl[ee.SheetIndex - 1].Length - 21 - 2;
                int ix1 = index * 6 + 21;
                if (((index+1) * 6) <= ix)
                {
                    wSheet.Cells[2 + index, 1] = se[ee.SheetIndex - 1];
                    if (strAddr == null)
                    {
                        int n = 21;
                        for (int i = 0; i < 21; i++)
                        {
                            if (hl[ee.SheetIndex - 1][i] == 0)
                            {
                                n = i;
                                break;
                            }
                        }
                        strAddr = Encoding.Default.GetString(hl[ee.SheetIndex - 1], 0, n);
                    }
                    wSheet.Cells[2 + index, 2] = strAddr;
                    str = hl[ee.SheetIndex - 1][ix1].ToString("D02") + "-" + hl[ee.SheetIndex - 1][ix1 + 1].ToString("D02") + " " + hl[ee.SheetIndex - 1][ix1 + 2].ToString("D02") + ":" + hl[ee.SheetIndex - 1][ix1 + 3].ToString("D02");
                    wSheet.Cells[2 + index, 3] = str;
//                     Debug.WriteLine(str);
//                     Debug.WriteLine(hl[ee.SheetIndex - 1][ix1 + 4].ToString("X2"));
//                     Debug.WriteLine(hl[ee.SheetIndex - 1][ix1 + 5].ToString("X2"));
                    ushort t=BytesOP.MakeShort(hl[ee.SheetIndex - 1][ix1 + 5], hl[ee.SheetIndex - 1][ix1 + 4]);
                    if(t==0xffff)
                    {
                        wSheet.Cells[2 + index, 4] = "传感器异常";
                    }
                    else
                    {
                        wSheet.Cells[2 + index, 4] = ((t) * 0.0625 + 0.5).ToString("f1");
                    }

                    if (index % 2 == 1)
                    {
                        dr = wSheet.get_Range("A" + (2 + index).ToString(), "D" + (2 + index).ToString());
                        dr.Interior.Color = System.Drawing.ColorTranslator.ToOle(System.Drawing.Color.LightGray);
                        dr.Interior.Pattern = XlPattern.xlPatternSolid;
                    }
                }
                else
                    return false;                
            }
            return true;
        }
         * */
        private void Form2_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            if (radioButton1.Checked)//当前数据
            {
                Rx1616 = new CP1616Packet(4, 1);
                byte[] tx = CP1616Packet.MakeCP1616Packet(4, 1, 1);
                COMPort1.Write(tx, 0, tx.Length);
                while (true)
                {
                    try
                    {
                        if (Rx1616.DataPacketed((byte)COMPort1.ReadByte()))
                        {
                            string session = JsonWork.login();
                            if (session == "")
                                return;
                            JsonTempDataList jsonTempDataList = new JsonTempDataList();
                            jsonTempDataList.list = new List<JsonTempData>();
                            for (int i = 0; i < 100; i++)
                            {
                                JsonTempData jtd = new JsonTempData();
                                jtd.cid = i.ToString();
                                if (Rx1616.Data[i * 27 + 21] == 0xff)
                                {
                                    continue;
                                }
                                else
                                {
                                    jtd.date=Rx1616.Data[i * 27 + 21].ToString("D02") + "-" + Rx1616.Data[i * 27 + 22].ToString("D02") + " " + Rx1616.Data[i * 27 + 23].ToString("D02") + ":" + Rx1616.Data[i * 27 + 24].ToString("D02");
                                    jtd.temperature=((BytesOP.MakeShort(Rx1616.Data[i * 27 + 26], Rx1616.Data[i * 27 + 25])) * 0.0625+0.5).ToString("f1");
                                }
                                jsonTempDataList.list.Add(jtd);
                            }
                            WFHttpWebResponse web = new WFHttpWebResponse();
                            IDictionary<string, string> p = new Dictionary<string, string>();
                            p.Add("temperature_list", JsonWork.GetJsonString<JsonTempDataList>(jsonTempDataList));
                            p.Add("session", session);
                            p.Add("device_id", Form1.DeviceID.ToString());
                            
                            HttpWebResponse hr = web.CreatePostHttpResponse(JsonWork.strUrl + "post_temperature_list", p);
                            JsonAddrListReturn AddrList = JsonWork.GetJsonObject<JsonAddrListReturn>(web.Content);
                            if (AddrList.code != "200")
                            {
                                MessageBox.Show("数据导出失败:" + AddrList.message);
                                return;
                            }
                            else
                            {
                                MessageBox.Show("数据导出成功");
                                return;
                            }
                            break;
                        }
                    }
                    catch
                    {
                        MessageBox.Show("数据导出失败");
                        break;
                    }
                }
            }
            else if (radioButton2.Checked)
            {
                hl = new List<byte[]>();
                se = new List<byte>();
                er = new List<byte>();
                progressBar1.Value = 0;
                int retry;
                bool bOK;
                for (int i = 0; i < 100; i++)
                {
                    retry = 20;
                    bOK = false;
                    while (retry != 0)
                    {
                        Rx1616 = new CP1616Packet(5, 1);
                        byte[] tx = CP1616Packet.MakeCP1616Packet(5, 1, (byte)i);
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
                                    //                                 byte[] temp = new byte[Rx1616.Data.Length - 2];
                                    //                                 for (int j = 0; j < Rx1616.Data.Length - 2; j++)
                                    //                                 {
                                    //                                     temp[j]
                                    //                                 }
                                    hl.Add(Rx1616.Data);
                                    se.Add((byte)(i + 1));
                                    progressBar1.Value++;
                                    Thread.Sleep(100);
                                    bOK = true;
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
                        Thread.Sleep(1000);
                    }
                    if (retry == 0)
                    {
                        er.Add((byte)(i + 1));
                    }
                }
                if (se.Count != 0)
                {
                    if (er.Count != 0)
                    {
                        string str = "如下传感器数据读取失败:\r\n";
                        for (int i = 0; i < er.Count; i++)
                        {
                            str += "第" + er[i].ToString() + "号传感器" + "\r\n";
                        }
                        str += "是否继续导出";
                        if (MessageBox.Show(str, "读取错误", MessageBoxButtons.YesNo) == DialogResult.No)
                            return;
                    }
                    string session = JsonWork.login();
                    if (session == "")
                        return;
                    JsonTempDataList jsonTempDataList = new JsonTempDataList();
                    jsonTempDataList.list = new List<JsonTempData>();
                    for (int i = 0; i < se.Count; i++)
                    {                        
                        int ix1 = 21;
                        while((ix1+6)<hl[i].Length)
                        {
                            JsonTempData jtd = new JsonTempData();
                            jtd.cid = se[i].ToString();
                            jtd.date = hl[i][ix1].ToString("D02") + "-" + hl[i][ix1 + 1].ToString("D02") + " " + hl[i][ix1 + 2].ToString("D02") + ":" + hl[i][ix1 + 3].ToString("D02");
                            
                            ushort t = BytesOP.MakeShort(hl[i][ix1 + 5], hl[i][ix1 + 4]);
                            if (t == 0xffff)
                            {
                                jtd.temperature = "-100";
                            }
                            else
                            {
                                jtd.temperature = ((t) * 0.0625 + 0.5).ToString("f1");
                            }
                            jsonTempDataList.list.Add(jtd);
                            ix1 += 6;
                        } 
                    }
                    WFHttpWebResponse web = new WFHttpWebResponse();
                    IDictionary<string, string> p = new Dictionary<string, string>();
                    p.Add("temperature_list", JsonWork.GetJsonString<JsonTempDataList>(jsonTempDataList));
                    p.Add("session", session);
                    p.Add("device_id", Form1.DeviceID.ToString());

                    HttpWebResponse hr = web.CreatePostHttpResponse(JsonWork.strUrl + "post_temperature_list", p);
                    JsonAddrListReturn AddrList = JsonWork.GetJsonObject<JsonAddrListReturn>(web.Content);
                    if (AddrList.code != "200")
                    {
                        MessageBox.Show("数据导出失败:" + AddrList.message);
                        return;
                    }
                    else
                    {
                        MessageBox.Show("数据导出成功");
                        return;
                    }
//                     ee = new ExcelExport();
//                     ee.SheetCount = se.Count;
//                     ee.ExcelWorkbookCallbackProc = new ExcelExport.ExcelWorkbookCallback(ExcelWorkbookCallbackProc1);
//                     ee.ExcelExportProc1();
                }
                else
                {
                    MessageBox.Show("读取历史数据失败");
                }
            }
            else if (radioButton3.Checked)
            {
                if (numericUpDown2.Value < numericUpDown1.Value)
                {
                    MessageBox.Show("范围有误");
                    return;
                }
                hl = new List<byte[]>();
                se = new List<byte>();
                er = new List<byte>();
                progressBar1.Value = 0;
                int per = (int)(numericUpDown2.Value - numericUpDown1.Value + 1);
                per = 100 / per;
                int retry;
                bool bOK;
                for (int i = (int)(numericUpDown1.Value - 1); i < (int)numericUpDown2.Value; i++)
                {
                    retry = 20;
                    bOK = false;
                    while (retry != 0)
                    {
                        Rx1616 = new CP1616Packet(5, 1);
                        byte[] tx = CP1616Packet.MakeCP1616Packet(5, 1, (byte)i);
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
                                    //                                 byte[] temp = new byte[Rx1616.Data.Length - 2];
                                    //                                 for (int j = 0; j < Rx1616.Data.Length - 2; j++)
                                    //                                 {
                                    //                                     temp[j]
                                    //                                 }
                                    hl.Add(Rx1616.Data);
                                    se.Add((byte)(i + 1));
                                    progressBar1.Value += per;
                                    Thread.Sleep(100);
                                    bOK = true;
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
                        Thread.Sleep(1000);
                    }
                    if (retry == 0)
                    {
                        er.Add((byte)(i + 1));
                    }
                }
                progressBar1.Value = 100;
                if (se.Count != 0)
                {
                    if (er.Count != 0)
                    {
                        string str = "如下传感器数据读取失败:\r\n";
                        for (int i = 0; i < er.Count; i++)
                        {
                            str += "第" + er[i].ToString() + "号传感器" + "\r\n";
                        }
                        str += "是否继续导出";
                        if (MessageBox.Show(str, "读取错误", MessageBoxButtons.YesNo) == DialogResult.No)
                            return;
                    }
                    string session = JsonWork.login();
                    if (session == "")
                        return;
                    JsonTempDataList jsonTempDataList = new JsonTempDataList();
                    jsonTempDataList.list = new List<JsonTempData>();
                    for (int i = 0; i < se.Count; i++)
                    {                        
                        int ix1 = 21;
                        while ((ix1 + 6) < hl[i].Length)
                        {
                            JsonTempData jtd = new JsonTempData();
                            jtd.cid = se[i].ToString();
                            jtd.date = hl[i][ix1].ToString("D02") + "-" + hl[i][ix1 + 1].ToString("D02") + " " + hl[i][ix1 + 2].ToString("D02") + ":" + hl[i][ix1 + 3].ToString("D02");

                            ushort t = BytesOP.MakeShort(hl[i][ix1 + 5], hl[i][ix1 + 4]);
                            if (t == 0xffff)
                            {
                                jtd.temperature = "-100";
                            }
                            else
                            {
                                jtd.temperature = ((t) * 0.0625 + 0.5).ToString("f1");
                            }
                            jsonTempDataList.list.Add(jtd);
                            ix1 += 6;
                        }
                    }
                    WFHttpWebResponse web = new WFHttpWebResponse();
                    IDictionary<string, string> p = new Dictionary<string, string>();
                    p.Add("temperature_list", JsonWork.GetJsonString<JsonTempDataList>(jsonTempDataList));
                    p.Add("session", session);
                    p.Add("device_id", Form1.DeviceID.ToString());

                    HttpWebResponse hr = web.CreatePostHttpResponse(JsonWork.strUrl + "post_temperature_list", p);
                    JsonAddrListReturn AddrList = JsonWork.GetJsonObject<JsonAddrListReturn>(web.Content);
                    if (AddrList.code != "200")
                    {
                        MessageBox.Show("数据导出失败:" + AddrList.message);
                        return;
                    }
                    else
                    {
                        MessageBox.Show("数据导出成功");
                        return;
                    }
//                     ee = new ExcelExport();
//                     ee.SheetCount = se.Count;
//                     ee.ExcelWorkbookCallbackProc = new ExcelExport.ExcelWorkbookCallback(ExcelWorkbookCallbackProc1);
//                     ee.ExcelExportProc1();
                }
                else
                {
                    MessageBox.Show("读取历史数据失败");
                }
            }
        }
    }
}
