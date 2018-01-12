using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.Serialization.Json;
using System.IO;
using WFNetLib;
using System.Net;
using System.Windows.Forms;

namespace 手持设备上位机
{
    public class JsonWork
    {
        public static string strUrl = "http://www.iottw.cn:61233/api/handset/";
        public static string login()
        {
            WFHttpWebResponse web = new WFHttpWebResponse();
            IDictionary<string, string> p = new Dictionary<string, string>();
            p.Add("name", "HandsetMeter");
            p.Add("password", "cewen///abc");
            HttpWebResponse hr = web.CreatePostHttpResponse(strUrl + "login", p);
            JsonLoginReturn ret = JsonWork.GetJsonObject<JsonLoginReturn>(web.Content);
            if (ret.code == "200")
                return ret.session;
            else
                MessageBox.Show("登陆失败:" + ret.message);
            return "";
        }
        public static T GetJsonObject<T>(string value)
        {
            DataContractJsonSerializer s = new DataContractJsonSerializer(typeof(T));
            MemoryStream stream = new MemoryStream(System.Text.Encoding.UTF8.GetBytes(value));
            T data = (T)s.ReadObject(stream);
            return data;
        }
        public static string GetJsonString<T>(T value)
        {
            System.Runtime.Serialization.Json.DataContractJsonSerializer json = new System.Runtime.Serialization.Json.DataContractJsonSerializer(typeof(T));
            MemoryStream stream = new MemoryStream();
            json.WriteObject(stream, value);
            string str = System.Text.Encoding.UTF8.GetString(stream.ToArray());
            return str;
        }
    }
    [System.Runtime.Serialization.DataContract]
    public class JsonTempData
    {
        [System.Runtime.Serialization.DataMember]
        public string cid { get; set; }
        [System.Runtime.Serialization.DataMember]
        public string date { get; set; }
        [System.Runtime.Serialization.DataMember]
        public string temperature { get; set; }
    }
    [System.Runtime.Serialization.DataContract]
    public class JsonTempDataList
    {
        [System.Runtime.Serialization.DataMember]
        public List<JsonTempData> list { get; set; }
    }


    [System.Runtime.Serialization.DataContract]
    public class JsonDataReturn
    {
        [System.Runtime.Serialization.DataMember]
        public string code;
        [System.Runtime.Serialization.DataMember]
        public string message;
    }

    [System.Runtime.Serialization.DataContract]
    public class JsonAddrListReturn
    {
        [System.Runtime.Serialization.DataMember]
        public string code;
        [System.Runtime.Serialization.DataMember]
        public string message;
        [System.Runtime.Serialization.DataMember]
        public Obj obj;
    }
    [System.Runtime.Serialization.DataContract]
    public class Obj
    {
        [System.Runtime.Serialization.DataMember]
        public List<JsonAddr> list { get; set; }
    }
    [System.Runtime.Serialization.DataContract]
    public class JsonAddr
    {
        [System.Runtime.Serialization.DataMember]
        public string id;
        [System.Runtime.Serialization.DataMember]
        public string name;
    }
    [System.Runtime.Serialization.DataContract]
    public class JsonLoginReturn
    {
        [System.Runtime.Serialization.DataMember]
        public string code;
        [System.Runtime.Serialization.DataMember]
        public string message;
        [System.Runtime.Serialization.DataMember]
        public string session;
    }
}
