using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Net;
using System.Net.Security;
using System.IO;
using System.Security.Cryptography.X509Certificates;

namespace WFNetLib
{
    public class WFHttpWebResponse
    {
         public static readonly string DefaultUserAgent = "Mozilla/4.0 (compatible; MSIE 8.0; Windows NT 6.1; Trident/4.0; SLCC2; .NET CLR 2.0.50727; .NET CLR 3.5.30729; .NET CLR 3.0.30729; Media Center PC 6.0; .NET4.0C; .NET4.0E; doyo 2.0.3)";

         public CookieCollection Cookies;
         public IDictionary<string, string> HeaderParameters;
         public string Content;
         public WFHttpWebResponse()
         {
             Cookies = new CookieCollection();
             HeaderParameters = new Dictionary<string, string>();
         }
         /// <summary>  
         ///  创建GET方式的HTTP请求  
         /// </summary>  
         ///  <param name="url">请求的URL</param>  
         ///  <param name="timeout">请求的超时时间</param>  
         ///  <param name="userAgent">请求的客户端浏览器信息，可以为空</param>  
         ///  <param name="cookies">随同HTTP请求发送的Cookie信息，如果不需要身份验证可以为空</param>  
         ///  <returns></returns>  
         public HttpWebResponse CreateGetHttpResponse(string url)
         {
            return CreateGetHttpResponse(url, null, null, null);
         }
         public HttpWebResponse CreateGetHttpResponse(string url, CookieCollection cookies)
         {
             return CreateGetHttpResponse(url, null, null,cookies);
         }         
         public HttpWebResponse CreateGetHttpResponse(string url, IDictionary<string, string> newHeaders, int? timeout, CookieCollection newCookies)  
         {  
             if (string.IsNullOrEmpty(url))  
             {  
                 throw new ArgumentNullException("url");  
             }
             HttpWebRequest request = WebRequest.Create(url) as HttpWebRequest;  
             request.Method = "GET";  
             request.UserAgent = DefaultUserAgent;               
             if (timeout.HasValue)  
             {  
                 request.Timeout = timeout.Value;  
             }
             if (HeaderParameters.Count != 0)
             {
                 foreach (string key in HeaderParameters.Keys)
                 {
                     request.Headers[key] = HeaderParameters[key];
                 }
             }
             if (!(newHeaders == null || newHeaders.Count == 0))
             {
                 foreach (string key in newHeaders.Keys)
                 {
                     request.Headers[key] = newHeaders[key];
                     HeaderParameters[key] = newHeaders[key];
                 }
             }
             request.CookieContainer = new CookieContainer(); 
             if (Cookies != null && Cookies.Count != 0)
             {
                 foreach (Cookie c in Cookies)
                 {
                     request.CookieContainer.Add(c);
                 }
             }
             if (newCookies != null && newCookies.Count != 0)  
             {
                 foreach (Cookie c in newCookies)
                 {
                     request.CookieContainer.Add(c);
                     Cookies.Add(c);
                 }
                 //request.CookieContainer.Add(cookies);  
             }  

             HttpWebResponse Response =request.GetResponse() as HttpWebResponse;
             if (Response.Cookies.Count != 0)
             {
                 foreach (Cookie c in Response.Cookies)
                 {
                     Cookies.Add(c);
                 }
             }

             if (Response.Headers["ContentEncoding"] != null)
             {
                 Stream receiveStream = Response.GetResponseStream();
                 StreamReader sr = new StreamReader(receiveStream, Encoding.GetEncoding(Response.Headers["ContentEncoding"].ToString()));
                 Content=sr.ReadToEnd();
             }
             else
             {
                 try
                 {
                     Stream receiveStream = Response.GetResponseStream();
                     StreamReader sr = new StreamReader(receiveStream);
                     Content = sr.ReadToEnd();
                 }
                 catch
                 {
                 	
                 }
             }
             return Response;
         }  

         /// <summary>  
         /// 创建POST方式的HTTP请求  
         /// </summary>  
         /// <param name="url">请求的URL</param>  
         /// <param name="parameters">随同请求POST的参数名称及参数值字典</param>  
         /// <param name="timeout">请求的超时时间</param>  
         /// <param name="userAgent">请求的客户端浏览器信息，可以为空</param>  
         /// <param name="requestEncoding">发送HTTP请求时所用的编码</param>  
         /// <param name="cookies">随同HTTP请求发送的Cookie信息，如果不需要身份验证可以为空</param>  
         /// <returns></returns>  
         public HttpWebResponse CreatePostHttpResponse(string url, string post)
         {
             IDictionary<string, string> p = new Dictionary<string, string>();
             p.Add("", post);
             return CreatePostHttpResponse(url, p, null, null, null, null);
         } 
         public HttpWebResponse CreatePostHttpResponse(string url, IDictionary<string, string> parameters)
         {
             return CreatePostHttpResponse(url, parameters, null, null, null, null);
         }
         public HttpWebResponse CreatePostHttpResponse(string url, IDictionary<string,string> parameters,Encoding requestEncoding,IDictionary<string, string> newHeaders, int? timeout, CookieCollection newCookies)  
         {  
             if (string.IsNullOrEmpty(url))  
             {  
                 throw new ArgumentNullException("url");  
             }               
             HttpWebRequest request=null;             
             if (requestEncoding == null)
             {
                 requestEncoding = Encoding.UTF8;
                 //throw new ArgumentNullException("requestEncoding");
             }  
             //如果是发送HTTPS请求  
             if(url.StartsWith("https",StringComparison.OrdinalIgnoreCase))  
             {  
                 ServicePointManager.ServerCertificateValidationCallback = new RemoteCertificateValidationCallback(CheckValidationResult);  
                 request = WebRequest.Create(url) as HttpWebRequest;  
                 request.ProtocolVersion=HttpVersion.Version10;  
             }  
             else 
             {  
                 request = WebRequest.Create(url) as HttpWebRequest;  
             }
             request.KeepAlive = false;
             request.Method = "POST";  
             request.ContentType = "application/x-www-form-urlencoded";
             request.UserAgent = DefaultUserAgent;
             if (!(HeaderParameters == null || HeaderParameters.Count == 0))
             {
                 foreach (string key in HeaderParameters.Keys)
                 {
                     request.Headers[key] = HeaderParameters[key];
                 }
             }
             if (!(newHeaders == null || newHeaders.Count == 0))
             {
                 foreach (string key in newHeaders.Keys)
                 {
                     request.Headers[key] = newHeaders[key];
                     HeaderParameters[key] = newHeaders[key];
                 }
             }
             if (timeout.HasValue)  
             {  
                 request.Timeout = timeout.Value;  
             }
             request.CookieContainer = new CookieContainer(); 
             if (Cookies != null && Cookies.Count != 0)
             {
                 foreach (Cookie c in Cookies)
                 {
                     request.CookieContainer.Add(c);
                 }
             }
             if (newCookies != null && newCookies.Count != 0)
             {
                 foreach (Cookie c in newCookies)
                 {
                     request.CookieContainer.Add(c);
                     Cookies.Add(c);
                 }
                 //request.CookieContainer.Add(cookies);  
             }  
             //如果需要POST数据  
             if(!(parameters==null||parameters.Count==0))  
             {  
                 StringBuilder buffer = new StringBuilder();  
                 int i = 0;
                 foreach (string key in parameters.Keys)
                 {
                     if (key == "")
                     {
                         if (i > 0)
                         {
                             buffer.AppendFormat("&{0}", parameters[key]);
                         }
                         else
                         {
                             buffer.AppendFormat("{0}", parameters[key]);
                         }
                     }
                     else
                     {
                         if (i > 0)
                         {
                             buffer.AppendFormat("&{0}={1}", key, parameters[key]);
                         }
                         else
                         {
                             buffer.AppendFormat("{0}={1}", key, parameters[key]);
                         }
                     }
                     i++;
                 }
                 byte[] data = requestEncoding.GetBytes(buffer.ToString());  
                 using (Stream stream = request.GetRequestStream())  
                 {  
                     stream.Write(data, 0, data.Length);  
                 }  
             }
             request.KeepAlive = false;
             //ServicePointManager.SecurityProtocol = SecurityProtocolType.Ssl3;// (SecurityProtocolType)3072;
             ServicePointManager.SecurityProtocol = SecurityProtocolType.Tls | SecurityProtocolType.Ssl3;
             HttpWebResponse Response= request.GetResponse() as HttpWebResponse;
             if (Response.Cookies.Count != 0)
             {
                 foreach (Cookie c in Response.Cookies)
                 {
                     Cookies.Add(c);
                 }
             }

             if (Response.Headers["ContentEncoding"] != null)
             {
                 Stream receiveStream = Response.GetResponseStream();
                 StreamReader sr = new StreamReader(receiveStream, Encoding.GetEncoding(Response.Headers["ContentEncoding"].ToString()));
                 Content = sr.ReadToEnd();
             }
             else
             {
                 try
                 {
                     Stream receiveStream = Response.GetResponseStream();
                     StreamReader sr = new StreamReader(receiveStream);
                     Content = sr.ReadToEnd();
                 }
                 catch
                 {

                 }
             }
             return Response;
         }  
         private static bool CheckValidationResult(object sender, X509Certificate certificate, X509Chain chain, SslPolicyErrors errors)  
         {  
             return true; //总是接受  
         }

         public static string PostInput(Stream InputStream)
         {
             return PostInput(InputStream, Encoding.UTF8);
         }
         public static string PostInput(Stream InputStream, Encoding encoding)
         {
             try
             {
                 System.IO.Stream s = InputStream;
                 int count = 0;
                 byte[] buffer = new byte[1024];
                 StringBuilder builder = new StringBuilder();
                 while ((count = s.Read(buffer, 0, 1024)) > 0)
                 {
                     builder.Append(encoding.GetString(buffer, 0, count));
                 }
                 s.Flush();
                 s.Close();
                 s.Dispose();
                 return builder.ToString();
             }
             catch (Exception ex)
             { throw ex; }
         }
    }

}
