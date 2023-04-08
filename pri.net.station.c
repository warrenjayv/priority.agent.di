using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

namespace pri {
  namespace net {
     namespace station {
        public class server {
           IPHostEntry host = Dns.GetHostEntry(Dns.GetHostName( )); 

           internal static (bool, int) select_ip_addrs (  ) {
              IPHostEntry ihe = Dns.GetHostEntry(Dns.GetHostName()); 
      
              write("ip list: ", color.mag); 
              for (int i = 0; i < ihe.AddressList.Length; i++) 
              {
                 write(" ["+i+"] "+ihe.AddressList[i], color.ag); 
              }
           }

           internal static void select_ip ( ) 
           {
              while(true) 
              {
                
              }
           }
    
           internal static void write(string msg, ConsoleColor c) 
           {
              color.set(c); 
              Console.WriteLine(msg);
              color.set(color.white);
           }
        } 

        public static class color {
           public static ConsoleColor red     = ConsoleColor.Red;
           public static ConsoleColor blue    = ConsoleColor.Blue;
           public static ConsoleColor yellow  = ConsoleColor.Yellow;
           public static ConsoleColor white   = ConsoleColor.White;
           public static ConsoleColor green   = ConsoleColor.Green;
           public static ConsoleColor mag     = ConsoleColor.Magenta;
           public static ConsoleColor cyan    = ConsoleColor.Cyan;
           public static ConsoleColor gray    = ConsoleColor.Gray;
           public static ConsoleColor darkmag = ConsoleColor.DarkMagenta;

           public static void set( ConsoleColor c ) {
              Console.ForegroundColor = c;
           }
          
           public static void reset( ) {
              Console.ForegroundColor = white; 
           }
        }

        public struct _NET_PARAM { 
           public int  BUFFER_LEN;
           public int  SERVER_PORT;
           public int  MAX_CONN;
           public int  SEL;
           public bool IS_IP_SET; 
           public bool IS_PORT_SET; 

           public _NET_PARAM( ) 
           {
              BUFFER_LEN  = 8042;
              SERVER_PORT = 23;
              MAX_CONN    = 24;
              SEL         = 0;
              IS_IP_SET   = false;
              IS_PORT_SET = false; 
           }
        }
     }
  }
}
