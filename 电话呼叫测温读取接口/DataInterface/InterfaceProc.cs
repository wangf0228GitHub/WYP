// using System;
// using System.Collections.Generic;
// using System.Linq;
// using System.Text;
// using WFNetLib;
// using System.Net;
// using System.Runtime.Serialization.Json;
// using System.IO;
// using System.Windows.Forms;
// using System.Collections;
// using WFNetLib.Log;
// using System.Data;
// using System.Diagnostics;
// using System.Threading;
// 
// namespace DataInterface
// {
//     public class InterfaceProc
//     {
//         public string[] UserName;
//         public string[] Password;
//         WFHttpWebResponse[] WebResponse;
//         DateTime[] oldDateTime;
//         DateTime[] LastDateTime;
//         public delegate void ShowTextCallbackDelegate(string str);
//         public ShowTextCallbackDelegate ShowText = null;
//         Hashtable IntCalls;
//         string ErrLogFile;
//         void ErrLog(string err)
//         {
//             DateTime dt = DateTime.Now;
//             TextLog.AddTextLog(err, System.Windows.Forms.Application.StartupPath + "\\ErrLog\\" + String.Format("{0:D4}", dt.Year) + "-" + String.Format("{0:D2}", dt.Month) + "-" + String.Format("{0:D2}", dt.Day) + "运行信息.txt",true);
//         }
//         bool Login(int index)
//         {
//             try
//             {
//                 HttpWebResponse hr = WebResponse[index].CreateGetHttpResponse("http://www.c4006.com/user/servlet/verify.tslogin");
// //                 if(ShowText!=null)
// //                     ShowText(UserName[index] + WebResponse[index].Content);
//                 // {\"message\":\"8415\",\"data\":{},\"success\":true}
//                 DataContractJsonSerializer s = new DataContractJsonSerializer(typeof(verify));
//                 MemoryStream stream = new MemoryStream(System.Text.Encoding.UTF8.GetBytes(WebResponse[index].Content));
//                 verify v = (verify)s.ReadObject(stream);
//                 string url = "http://www.c4006.com/user/servlet/login.tslogin?userName=admin@";
//                 url += UserName[index];
//                 url += "&passWord=";
//                 url += Password[index];
//                 url += "&verifyCode=";
//                 url += v.message;
//                 url += "&verifyHidden=";
//                 url += v.message;
//                 url += "";
//                 hr = WebResponse[index].CreateGetHttpResponse(url);
// //                 if (ShowText != null)
// //                     ShowText(UserName[index] + WebResponse[index].Content);
//                 //{\"message\":\"index\",\"data\":{},\"success\":true} 
//                 stream = new MemoryStream(System.Text.Encoding.UTF8.GetBytes(WebResponse[index].Content));
//                 s = new DataContractJsonSerializer(typeof(login));
//                 login l = (login)s.ReadObject(stream);
//                 url = "http://www.c4006.com/" + l.message;
//                 hr = WebResponse[index].CreateGetHttpResponse(url);
//                 //ShowText(UserName[index] + WebResponse[index].Content);
//                 if (ShowText != null)
//                     ShowText(UserName[index] + "成功登陆!");
//             }
//             catch (System.Exception ex)
//             {
//                 ErrLog(ex.Message);
//                 ShowText(ex.Message+"....");
//                 return false;
//             }
//             return true;
//         }
//         public List<CallData> GetData(int index)
//         {
//             List<CallData> ret = null;
//             int page = 1;
//             int retry = 5;
//             string url;
//             try
//             {
//                 while (retry != 0)
//                 {                    
//                     retry--;
//                     url = "http://www.c4006.com/customer/servlet/GetExtensionCallerByID.ts?beginTime=";
//                     url += oldDateTime[index].ToString("yyyy-MM-dd HH:mm:ss");
//                     url += "&endTime=";
//                     url += DateTime.Now.ToString("yyyy-MM-dd HH:mm:ss");
//                     url += "&page=" + page.ToString();
//                     url += "&limit=100";
//                     LastDateTime[index] = DateTime.Now;
//                     HttpWebResponse hr = WebResponse[index].CreateGetHttpResponse(url);
//                     DataContractJsonSerializer s = new DataContractJsonSerializer(typeof(myData));
//                     MemoryStream stream = new MemoryStream(System.Text.Encoding.UTF8.GetBytes(WebResponse[index].Content));
//                     myData calldata = (myData)s.ReadObject(stream);
// 
//                     if (ShowText != null)
//                     {
//                         if (calldata.count != 0)
//                         {
//                             ShowText(oldDateTime[index].ToString("yyyy-MM-dd HH:mm:ss") + "~" + DateTime.Now.ToString("yyyy-MM-dd HH:mm:ss") + ":" + UserName[index] + WebResponse[index].Content);
//                         }
//                     }
//                     if (!calldata.success)
//                     {
//                         if (ShowText != null)
//                             ShowText(UserName[index] + "重新登陆!");
//                         Login(index);
//                         continue;
//                     }
//                     else
//                     {
//                         if (calldata.data.Length != 0)                            
//                         {
//                             if(ret==null)
//                                 ret = new List<CallData>();
//                             for (int j = 0; j < calldata.data.Length; j++)
//                             {
//                                 CallData d = new CallData();
//                                 d.UserIndex = index;
//                                 d.caller = calldata.data[j].caller;
//                                 try
//                                 {
//                                     d.callin_time = DateTime.Parse(calldata.data[j].callin_time);
//                                 }
//                                 catch
//                                 {
//                                     if (ShowText != null)
//                                         ShowText(UserName[index] + "的数据中存在无效字符串：" + calldata.data[j].callin_time);
//                                     ErrLog(UserName[index] + "的数据中存在无效字符串：" + calldata.data[j].callin_time);
//                                     continue;
//                                 }
//                                 ret.Add(d);
//                             }
//                             if (calldata.count > (calldata.data.Length + (page - 1) * 100))
//                             {
//                                 page++;
//                                 retry++;
//                                 if (ShowText != null)
//                                     ShowText(UserName[index] + "延时等待!");
//                                 Thread.Sleep(10000);
//                             }
//                             else
//                                 break;
//                         }
//                         else
//                             break;
//                     }
//                 }
//                 if (retry == 0)//失败
//                 {
//                     ret = null;
//                     if (ShowText != null)
//                         ShowText(UserName[index] + "失败，无法登陆!");
//                     ErrLog(UserName[index] + "失败，无法登陆!");
//                 }
//             }
//             catch (System.Exception ex)
//             {
//                 ErrLog(UserName[index] + ":"+ex.Message);
//                 if (ShowText != null)
//                     ShowText(UserName[index] + ":"+ex.Message);
//             }
//             if (ret != null)
//             {
//                 DateTime dt = ret[0].callin_time;
//                 for (int i = 0; i < ret.Count; i++)
//                 {
//                     if (dt < ret[i].callin_time)
//                     {
//                         dt = ret[i].callin_time;
//                     }
//                 }
//                 oldDateTime[index] = dt.AddSeconds(1);    
//             }
//             if (ShowText != null)
//                 ShowText(UserName[index] + "数据获得完毕，等待处理!");
//             return ret;
//         }
//         public Thread PeriodGetDataThreadIns = null;
//         int count;
//         public void PeriodGetDataThreadStart()
//         {
//             bPeriodGetDataThreadStop = false;
//             bPeriodGetDataThreadIsStop = false;
//             count = 0;
//             PeriodGetDataThreadIns = new Thread(new ThreadStart(PeriodGetDataProc));
//             PeriodGetDataThreadIns.Name = "周期访问端口";
//             ShowText("周期访问端口开始");
//             PeriodGetDataThreadIns.Start(); 
//         }
//         public bool bPeriodGetDataThreadStop;
//         public bool bPeriodGetDataThreadIsStop;
//         private void PeriodGetDataProc()
//         {
//             while (!bPeriodGetDataThreadStop)
//             {
//                 count++;
//                 if ((count % 500) == 0)
//                 {
//                     for (int i = 0; i < 30; i++)
//                     {
//                         WebResponse[i] = new WFHttpWebResponse();
//                     } 
//                 }
//                 ShowText("-----------------------------第" + count.ToString() + "次访问--------------------------");
//                 CheckData();
//                 Thread.Sleep(10000);
//             }
//             bPeriodGetDataThreadIsStop = true;
//         }
//         public void CheckData()
//         {
// //             GetData(20);
// //             return;
//             //获得整数温度
//             for (int i = 0; i < 19; i++)
//             {
//                 List<CallData> calls = GetData(i);
//                 if (calls != null)
//                 {
//                     //for (int j = (calls.Count-1); j >=0; j--)
//                     for (int j = 0; j < calls.Count; j++)
//                     {
//                         List<CallData> intCalls = (List<CallData>)IntCalls[calls[j].caller];
//                         if (intCalls != null)
//                         {
//                             intCalls.Add(calls[j]);
//                         }
//                         else
//                         {
//                             intCalls = new List<CallData>();
//                             intCalls.Add(calls[j]);
//                         }
//                         IntCalls[calls[j].caller] = intCalls;
//                         if (ShowText != null)
//                         {
//                             ShowText("---------------获得整数-------------------");
//                             ShowText(calls[j].caller);
//                             ShowText((calls[j].UserIndex + 11).ToString());
//                             ShowText(calls[j].callin_time.ToString());
//                             ShowText("----------------------------------------------");
//                         }
//                     }
//                 }
//             }
//             //获得小数温度
//             for (int i = 19; i < 29; i++)
//             {
// //                 if(i==20)
// //                     continue;
//                 List<CallData> calls = GetData(i);
//                 if (calls != null)
//                 {
//                     //for (int j = (calls.Count-1); j >=0; j--)
//                     for (int j = 0; j < calls.Count; j++)
//                     {
//                         if (ShowText != null)
//                         {
//                             ShowText("---------------获得小数-------------------");
//                             ShowText(calls[j].caller);
//                             ShowText((calls[j].UserIndex-19).ToString());
//                             ShowText(calls[j].callin_time.ToString());
//                             ShowText("----------------------------------------------");
//                         }
//                         List<CallData> intCalls = (List<CallData>)IntCalls[calls[j].caller];
//                         if (intCalls != null)//已经有了整数温度
//                         {
//                             bool bSave = false;
//                             //组合温度
//                             for (int k = 0; k < intCalls.Count; k++)
//                             {
//                                 CallData intCall = intCalls[k];
//                                 //小数温度点的时间应位于整数温度点的时间之后的60s内
//                                 if (intCall.callin_time < calls[j].callin_time)
//                                 {
//                                     if (intCall.callin_time.AddSeconds(60) > calls[j].callin_time)
//                                     {
//                                         float t = intCall.UserIndex + 11;
//                                         t = t + (calls[j].UserIndex - 19) / 10.0f;
//                                         //存储数据
//                                         温度数据Data tData = new 温度数据Data();
//                                         tData.Caller = intCall.caller;
//                                         tData.CallInTime = intCall.callin_time;//整数的时间
//                                         tData.Temperature = t;
//                                         tData.ErrFlag = 0;
//                                         温度数据DataDBOption.Insert(tData);
//                                         bSave = true;
//                                         intCalls.RemoveAt(k);
//                                         IntCalls[calls[j].caller] = intCalls;
//                                         if (ShowText != null)
//                                         {
//                                             ShowText("---------------组合温度，无纠错-------------------");
//                                             ShowText(calls[j].caller);
//                                             ShowText(t.ToString());
//                                             ShowText(calls[j].callin_time.ToString());
//                                             ShowText("----------------------------------------------");
//                                         }
//                                         break;
//                                     }
//                                 }
//                             }
//                             if (!bSave)//只有小数的容错
//                             {
//                                 DataTable dt = 温度数据DataDBOption.DataTableSelect_GetLastData(calls[j].caller);
//                                 if (dt.Rows.Count != 0)
//                                 {
//                                     float t = float.Parse(dt.Rows[0][0].ToString());
//                                     DateTime date = DateTime.Parse(dt.Rows[0][1].ToString());
//                                     if(date.AddHours(4)>calls[j].callin_time)
//                                     {
//                                         int oldInt = (int)t;
//                                         t = oldInt + (calls[j].UserIndex - 19) / 10.0f;
//                                         //存储数据
//                                         温度数据Data tData = new 温度数据Data();
//                                         tData.Caller = calls[j].caller;
//                                         tData.CallInTime = calls[j].callin_time;//小数的时间
//                                         tData.Temperature = t;
//                                         tData.ErrFlag = 2;
//                                         温度数据DataDBOption.Insert(tData);
//                                         if (ShowText != null)
//                                         {
//                                             ShowText("---------------组合温度，只有小数的容错，整数超过60s-------------------");
//                                             ShowText(calls[j].caller);
//                                             ShowText(t.ToString());
//                                             ShowText(calls[j].callin_time.ToString());
//                                             ShowText("----------------------------------------------");
//                                         }
//                                     }
//                                     else
//                                     {
//                                         if (ShowText != null)
//                                         {
//                                             ShowText("---------------放弃小数，历史温度间隔超过4小时--------");
//                                             ShowText(calls[j].caller);
//                                             ShowText((calls[j].UserIndex + 11).ToString());
//                                             ShowText(calls[j].callin_time.ToString());
//                                             ShowText("----------------------------------------------");
//                                         }
//                                     }
//                                 }
//                             }
//                         }
//                         else//只有小数的容错
//                         {
//                             DataTable dt = 温度数据DataDBOption.DataTableSelect_GetLastData(calls[j].caller);
//                             if (dt.Rows.Count != 0)
//                             {
//                                 float t = float.Parse(dt.Rows[0][0].ToString());
//                                 DateTime date = DateTime.Parse(dt.Rows[0][1].ToString());
//                                 if(date.AddHours(4)>calls[j].callin_time)
//                                 {
//                                     int oldInt = (int)t;
//                                     t = oldInt + (calls[j].UserIndex - 19) / 10.0f;
//                                     //存储数据
//                                     温度数据Data tData = new 温度数据Data();
//                                     tData.Caller = calls[j].caller;
//                                     tData.CallInTime = calls[j].callin_time;//小数的时间
//                                     tData.Temperature = t;
//                                     tData.ErrFlag = 2;
//                                     温度数据DataDBOption.Insert(tData);
//                                     ShowText("---------------组合温度，只有小数的容错，但没有整数-------------------");
//                                     ShowText(calls[j].caller);
//                                     ShowText(t.ToString());
//                                     ShowText(calls[j].callin_time.ToString());
//                                     ShowText("----------------------------------------------");
//                                 }
//                             }
//                         }
//                     }
//                 }                
//             }
//             //遍历整数温度表
//             Hashtable tempIntCalls = new Hashtable();
//             foreach (DictionaryEntry de in IntCalls)
//             {
//                 List<CallData> intCalls = (List<CallData>)de.Value;
//                 bool bOK = false;
//                 while(!bOK)
//                 {
//                     bOK = true;
//                     for (int i = 0; i <intCalls.Count; i++)
//                     {
//                         CallData intCall = intCalls[i];
//                         //当前数据已经距离最后获得时间大于30s，对数据进行纠错
//                         intCall.Delay++;
//                         if(intCall.Delay>3)
//                         //if (intCall.callin_time.AddSeconds(30) < LastDateTime[intCall.UserIndex])
//                         {                            
//                             DataTable dt = 温度数据DataDBOption.DataTableSelect_GetLastData(intCall.caller);
//                             if (dt.Rows.Count != 0)
//                             {
//                                 DateTime date = DateTime.Parse(dt.Rows[0][1].ToString());
//                                 //if (date.AddHours(4) < intCall.callin_time)
//                                 {
//                                     float t = float.Parse(dt.Rows[0][0].ToString());
//                                     int newInt = intCall.UserIndex + 11;
//                                     int oldInt = (int)t;
//                                     int delta = newInt - oldInt;
//                                     if (delta > 1)
//                                     {
//                                         t = newInt + 0.0f;
//                                     }
//                                     else if (delta > 0)
//                                     {
//                                         t = newInt + 0.2f;
//                                     }
//                                     else if (delta < -1)
//                                     {
//                                         t = newInt + 0.9f;
//                                     }
//                                     else if (delta < 0)
//                                     {
//                                         t = newInt + 0.8f;
//                                     }
//                                     else//整数部分相等
//                                     {
//                                         int h1 = date.Hour;
//                                         int h2 = intCall.callin_time.Hour;
//                                         DateTime dd = date;
//                                         t = t - oldInt;
//                                         while (true)
//                                         {
//                                             dd=dd.AddHours(1);
//                                             if (dd >= intCall.callin_time)
//                                             {
//                                                 break;
//                                             }
//                                             else
//                                             {
//                                                 if (dd.Hour < 3 || dd.Hour>15)
//                                                     t=t-0.1f;
//                                                 else
//                                                     t=t+0.1f;
//                                             }
//                                         }
//                                         float t1 = newInt + t;
//                                         h1 = (int)t1;
//                                         if (h1 != newInt)
//                                         {
//                                             t = newInt + 0.0f;
//                                         }
//                                         else
//                                         {
//                                             t = t1;
//                                         }
//                                     }
//                                     //存储数据
//                                     温度数据Data tData = new 温度数据Data();
//                                     tData.Caller = intCall.caller;
//                                     tData.CallInTime = intCall.callin_time;//整数
//                                     tData.Temperature = t;
//                                     tData.ErrFlag = 1;
//                                     温度数据DataDBOption.Insert(tData);
//                                     if (ShowText != null)
//                                     {
//                                         ShowText("---------------组合温度，只有整数容错-------------------");
//                                         ShowText(intCall.caller);
//                                         ShowText(t.ToString());
//                                         ShowText("开始时间" + intCall.callin_time.ToString());
//                                         ShowText("容错时间:" + LastDateTime[intCall.UserIndex].ToString());
//                                         ShowText("----------------------------------------------");
//                                     }
//                                 }
//                             }
//                             intCalls.RemoveAt(i);
//                             bOK = false;
//                             break;
//                         }                     
//                     }
//                 }
//                 tempIntCalls[de.Key]=intCalls;               
//             }
//             IntCalls = new Hashtable();
//             foreach (DictionaryEntry de in tempIntCalls)
//             {
//                 List<CallData> intCalls = (List<CallData>)de.Value;
//                 if (intCalls.Count != 0)
//                     IntCalls[de.Key] = de.Value;
//             }
//             if (ShowText != null)
//             {
//                 ShowText("---------------完成一次扫描--------");
//             }
//         }
//         public InterfaceProc()
//         {
//             bPeriodGetDataThreadIsStop = true;
//             UserName = new string[30];
//             Password = new string[30];
// 
// 
//             //11度到19度温度点
//             UserName[0] = "4000011254";//11
//             Password[0] = "2Wv4Bf";
//             UserName[1] = "4000011274";//12
//             Password[1] = "AT2DQi";
//             UserName[2] = "4000011324";//13
//             Password[2] = "DB4PPG";
//             UserName[3] = "4000011364";//14
//             Password[3] = "kqQW7f";
//             UserName[4] = "4000011374";//15
//             Password[4] = "FdcdQ4";
//             UserName[5] = "4000011424";//16
//             Password[5] = "ATLHGh";
//             UserName[6] = "4000011434";//17
//             Password[6] = "IkLNUQ";
//             UserName[7] = "4000011474";//18
//             Password[7] = "fsCEVg";
//             UserName[8] = "4000011524";//19
//             Password[8] = "DfnYUT";
// 
//             //20度到29度温度点
//             UserName[9] = "4000011534";//20
//             Password[9] = "4RFDZK";
//             UserName[10] = "4000011564";//21
//             Password[10] = "TDlwFh";
//             UserName[11] = "4000011574";//22
//             Password[11] = "CaEpnX";
//             UserName[12] = "4000011594";//23
//             Password[12] = "9moYWy";
//             UserName[13] = "4000011614";//24
//             Password[13] = "j2qGb6";
//             UserName[14] = "4000011624";//25
//             Password[14] = "imyXPX";
//             UserName[15] = "4000011634";//26
//             Password[15] = "ZzeJDu";
//             UserName[16] = "4000011704";//27
//             Password[16] = "IRJlvR";
//             UserName[17] = "4000011714";//28
//             Password[17] = "9mP8b5";
//             UserName[18] = "4000011724";//29
//             Password[18] = "InvpDT"; 
// 
//             //小数温度点
//             UserName[19] = "4000413804";//0
//             Password[19] = "4QjGjY";
//             UserName[20] = "4000413814";//1
//             Password[20] = "gcxtjc";
//             UserName[21] = "4000413824";//2
//             Password[21] = "FH48O3";
//             UserName[22] = "4000413834";//3
//             Password[22] = "cfp3pw";
//             UserName[23] = "4000414154";//4
//             Password[23] = "ZRwJdE";
//             UserName[24] = "4000413854";//5
//             Password[24] = "grN9bu";
//             UserName[25] = "4000413864";//6
//             Password[25] = "GvXOlH";
//             UserName[26] = "4000413874";//7
//             Password[26] = "YCoweF";
//             UserName[27] = "4000414124";//8
//             Password[27] = "HBdDuS";
//             UserName[28] = "4000414134";//9
//             Password[28] = "oZEQbT";
//             //申告号码
//             UserName[29] = "4000011074";//
//             Password[29] = "VTNZR4";
// 
//             WebResponse = new WFHttpWebResponse[30];
//             IntCalls = new Hashtable();
//             oldDateTime = new DateTime[30];
//             LastDateTime = new DateTime[30];
//             DataTable dt=温度数据DataDBOption.DataTableSelect_GetLastDataTime();
//             if (dt.Rows.Count == 0)
//             {
//                 for (int i = 0; i < 30; i++)
//                 {
//                     oldDateTime[i] = DateTime.Now.AddDays(-100);
//                 }
//             }
//             else
//             {
//                 for (int i = 0; i < 30; i++)
//                 {
//                     oldDateTime[i] = DateTime.Parse(dt.Rows[0][0].ToString()).AddSeconds(1);
//                 }
//             }
//             for (int i = 0; i < 30; i++)
//             {
//                 WebResponse[i] = new WFHttpWebResponse();             
//             }            
//         }
//     }
//     public class CallData
//     {
//         public int UserIndex;
//         public string caller;
//         public DateTime callin_time;
//         public int Delay;
//         public CallData()
//         {
//             caller = "";
//             Delay = 0;
//         }
//     }
//     [System.Runtime.Serialization.DataContract]
//     public class verify
//     {
//         [System.Runtime.Serialization.DataMember]
//         public string message;
//         [System.Runtime.Serialization.DataMember]
//         public string data;
//         [System.Runtime.Serialization.DataMember]
//         public bool success;
//     }
//     [System.Runtime.Serialization.DataContract]
//     public class login
//     {
//         [System.Runtime.Serialization.DataMember]
//         public string message;
//         [System.Runtime.Serialization.DataMember]
//         public string data;
//         [System.Runtime.Serialization.DataMember]
//         public bool success;
//     }
//     [System.Runtime.Serialization.DataContract]
//     public class myData
//     {
//         [System.Runtime.Serialization.DataMember]
//         public string message;
//         [System.Runtime.Serialization.DataMember]
//         public bool success;
//         [System.Runtime.Serialization.DataMember]
//         public int count;
//         [System.Runtime.Serialization.DataMember]
//         public JsonCallData[] data;
//     }
//     [System.Runtime.Serialization.DataContract]
//     public class JsonCallData
//     {
//         [System.Runtime.Serialization.DataMember]
//         public string caller;
//         [System.Runtime.Serialization.DataMember]
//         public string called;
//         [System.Runtime.Serialization.DataMember]
//         public string callin_time;
//     }
// }
