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
using System.Reflection;

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
        List<byte[]> historyDataList;
        List<byte> rxSensorIndexList;
        List<byte> errorSensorIndexList;
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
                            ee.ExcelWorkbookCallbackProc = new ExcelExport.ExcelWorkbookCallback(curdataExcelWorkbookCallbackProc);
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
            else if (radioButton2.Checked)//全部导出
            {                
                historyDataList = new List<byte[]>();
                rxSensorIndexList=new List<byte>();
                errorSensorIndexList=new List<byte>();
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
                                    historyDataList.Add(Rx1616.Data);
                                    rxSensorIndexList.Add((byte)(i + 1));
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
                        errorSensorIndexList.Add((byte)(i + 1));
                    } 
                }
                if (rxSensorIndexList.Count != 0)
                {
                    if (errorSensorIndexList.Count != 0)
                    {
                        string str = "如下传感器数据读取失败:\r\n";
                        for (int i = 0; i < errorSensorIndexList.Count; i++)
                        {
                            str += "第" + errorSensorIndexList[i].ToString() + "号传感器" + "\r\n";
                        }
                        str += "是否继续保存";
                        if (MessageBox.Show(str, "读取错误", MessageBoxButtons.YesNo) == DialogResult.No)
                            return;
                    }
                    ee = new ExcelExport(-1,rxSensorIndexList.Count);
                    ee.ExcelWorkbookCallbackProc = new ExcelExport.ExcelWorkbookCallback(historydataExcelWorkbookCallbackProc);
                    ee.ExcelExportProc();
                }
                else
                {
                    MessageBox.Show("读取历史数据失败");
                }
            }
            else if (radioButton3.Checked)//部分导出
            {
                if (numericUpDown2.Value < numericUpDown1.Value)
                {
                    MessageBox.Show("范围有误");
                    return;
                }
                historyDataList = new List<byte[]>();
                rxSensorIndexList = new List<byte>();
                errorSensorIndexList = new List<byte>();
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
                                    historyDataList.Add(Rx1616.Data);
                                    rxSensorIndexList.Add((byte)(i + 1));
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
                        errorSensorIndexList.Add((byte)(i + 1));
                    }
                }
                progressBar1.Value = 100;
                if (rxSensorIndexList.Count != 0)
                {
                    if (errorSensorIndexList.Count != 0)
                    {
                        string str = "如下传感器数据读取失败:\r\n";
                        for (int i = 0; i < errorSensorIndexList.Count; i++)
                        {
                            str += "第" + errorSensorIndexList[i].ToString() + "号传感器" + "\r\n";
                        }
                        str += "是否继续保存";
                        if (MessageBox.Show(str, "读取错误", MessageBoxButtons.YesNo) == DialogResult.No)
                            return;
                    }
                    ee = new ExcelExport(-1,rxSensorIndexList.Count);
                    ee.SheetCount = rxSensorIndexList.Count;
                    ee.ExcelWorkbookCallbackProc = new ExcelExport.ExcelWorkbookCallback(historydataExcelWorkbookCallbackProc);
                    ee.ExcelExportProc();
                }
                else
                {
                    MessageBox.Show("读取历史数据失败");
                }
            }
        }
        private bool curdataExcelWorkbookCallbackProc(Workbook wBook, int sheetIndex, int itemIndex)
        {
            Worksheet wSheet;
            wSheet = (Worksheet)wBook.Worksheets[ee.SheetIndex];
            string str;
            Range dr;
            if (itemIndex == -1)
            {
                wSheet = (Worksheet)wBook.Worksheets[1];
                wSheet.Name = "手抄器当前温度数据";
                wSheet.Cells[1, 1] = "设备安装小区";
                wSheet.Cells[1, 2] = Encoding.Default.GetString(Rx1616.Data, 0, 64);
                wSheet.Cells[2, 1] = "设备编号";
                wSheet.Cells[2, 2] = "安装地址";
                wSheet.Cells[2, 3] = "最后一组数据获得时间";
                wSheet.Cells[2, 4] = "温度数据（℃）";
                dr = wSheet.get_Range("A1", "A1");
                dr.Interior.Color = System.Drawing.ColorTranslator.ToOle(System.Drawing.Color.DarkOrange);
                dr = wSheet.get_Range("B1", "H1");//获取需要合并的单元格的范围
                dr.Application.DisplayAlerts = false;
                dr.Merge(Missing.Value);
                dr.Application.DisplayAlerts = true;
                dr = wSheet.get_Range("A2", "D2");
                dr.Interior.Color = System.Drawing.ColorTranslator.ToOle(System.Drawing.Color.DarkOrange);
                dr.Interior.Pattern = XlPattern.xlPatternSolid;
                dr = wSheet.get_Range("A1", "D102");
                dr.NumberFormat = "@";
            }
            else if (itemIndex == int.MaxValue)
            {
                dr = wSheet.get_Range("A1", "D102");
                dr.Columns.AutoFit();
                dr.HorizontalAlignment = XlHAlign.xlHAlignCenter;
                dr.Borders.LineStyle = XlLineStyle.xlContinuous;              
                
            }
            else
            {               
                wSheet.Cells[3 + itemIndex, 1] = itemIndex+1;
                wSheet.Cells[3 + itemIndex, 2] = Rx1616.Data[64 + itemIndex * 8 + 0].ToString() + "-" + Rx1616.Data[64 + itemIndex * 8 + 1].ToString();
                if (Rx1616.Data[64 + itemIndex * 8 + 2] == 0xff)
                {
                    wSheet.Cells[3 + itemIndex, 3] = "无";
                    wSheet.Cells[3 + itemIndex, 4] = "无";
                }
                else
                {
                    str = Rx1616.Data[64 + itemIndex * 8 + 2].ToString("D02") + "-" + Rx1616.Data[64 + itemIndex * 8 + 3].ToString("D02") + " " + Rx1616.Data[64 + itemIndex * 8 + 4].ToString("D02") + ":" + Rx1616.Data[64 + itemIndex * 8 + 5].ToString("D02");
                    wSheet.Cells[3 + itemIndex, 3] = str;
                    wSheet.Cells[3 + itemIndex, 4] = ((BytesOP.MakeShort(Rx1616.Data[64 + itemIndex * 8 + 6], Rx1616.Data[64 + itemIndex * 8 + 7])) * 0.0625 + 0.05).ToString("f1");
                }                
                if (itemIndex % 2 == 1)
                {
                    dr = wSheet.get_Range("A" + (3 + itemIndex).ToString(), "D" + (3 + itemIndex).ToString());
                    dr.Interior.Color = System.Drawing.ColorTranslator.ToOle(System.Drawing.Color.LightGray);
                    dr.Interior.Pattern = XlPattern.xlPatternSolid;
                }
                if (itemIndex == 99)
                    return false;
            }
            return true;
        }
        private bool historydataExcelWorkbookCallbackProc(Workbook wBook, int sheetIndex, int itemIndex)
        {
            Worksheet wSheet;
            wSheet = (Worksheet)wBook.Worksheets[ee.SheetIndex];
            string str;
            Range dr;
            if (itemIndex == -1)
            {
                wSheet.Name = rxSensorIndexList[ee.SheetIndex-1].ToString("D03");
                wSheet.Cells[1, 1] = "设备编号";
                wSheet.Cells[1, 2] = rxSensorIndexList[ee.SheetIndex - 1].ToString();
                wSheet.Cells[2, 1] = "安装地址";
                wSheet.Cells[2, 2] = Encoding.Default.GetString(historyDataList[ee.SheetIndex - 1], 0, 64) + ":" + historyDataList[ee.SheetIndex - 1][64].ToString() + "-" + historyDataList[ee.SheetIndex - 1][65].ToString();
                dr = wSheet.get_Range("A1", "A2");
                dr.Interior.Color = System.Drawing.ColorTranslator.ToOle(System.Drawing.Color.DarkOrange);
                dr.Interior.Pattern = XlPattern.xlPatternSolid;

                dr = wSheet.get_Range("B2", "H2");//获取需要合并的单元格的范围
                dr.Application.DisplayAlerts = false;
                dr.Merge(Missing.Value);
                dr.Application.DisplayAlerts = true;

                wSheet.Cells[3, 1] = "读取时间";
                wSheet.Cells[3, 2] = "温度数据（℃）";
                dr = wSheet.get_Range("A3", "B3");
                dr.Interior.Color = System.Drawing.ColorTranslator.ToOle(System.Drawing.Color.DarkOrange);
                dr.Interior.Pattern = XlPattern.xlPatternSolid;
                dr = wSheet.get_Range("A1", "B103");
                dr.NumberFormat = "@";
            }
            else if (itemIndex == int.MaxValue)
            {
                dr = wSheet.get_Range("A1", "B103");
                dr.Columns.AutoFit();
                dr.HorizontalAlignment = XlHAlign.xlHAlignCenter;
                dr.Borders.LineStyle = XlLineStyle.xlContinuous;
            }
            else
            {
                int bIndex = 64 + 2 + itemIndex * 6;
                if (bIndex >= (historyDataList[ee.SheetIndex - 1].Length-2))
                    return false;
                str = historyDataList[ee.SheetIndex - 1][bIndex].ToString("D02") + "-" + historyDataList[ee.SheetIndex - 1][bIndex + 1].ToString("D02") + " " + historyDataList[ee.SheetIndex - 1][bIndex + 2].ToString("D02") + ":" + historyDataList[ee.SheetIndex - 1][bIndex + 3].ToString("D02");
                wSheet.Cells[4 + itemIndex, 1] = str;
                //                     Debug.WriteLine(str);
                //                     Debug.WriteLine(hl[ee.SheetIndex - 1][ix1 + 4].ToString("X2"));
                //                     Debug.WriteLine(hl[ee.SheetIndex - 1][ix1 + 5].ToString("X2"));
                ushort t = BytesOP.MakeShort(historyDataList[ee.SheetIndex - 1][bIndex + 5], historyDataList[ee.SheetIndex - 1][bIndex + 4]);
                if (t == 0xffff)
                {
                    wSheet.Cells[4 + itemIndex, 2] = "传感器异常";
                }
                else
                {
                    wSheet.Cells[4 + itemIndex, 2] = ((t) * 0.0625 + 0.05).ToString("f1");
                }

                if (itemIndex % 2 == 1)
                {
                    dr = wSheet.get_Range("A" + (4 + itemIndex).ToString(), "B" + (4 + itemIndex).ToString());
                    dr.Interior.Color = System.Drawing.ColorTranslator.ToOle(System.Drawing.Color.LightGray);
                    dr.Interior.Pattern = XlPattern.xlPatternSolid;
                }
            }
            return true;
        }
        private void Form2_Load(object sender, EventArgs e)
        {

        }
    }
}
