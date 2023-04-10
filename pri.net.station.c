using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

using pri.net.station;

namespace pri {
  namespace net {
     namespace station {
        public class server {
            
           _NET_PARAM _NP   = new _NET_PARAM( ); 
           IPHostEntry host = Dns.GetHostEntry(Dns.GetHostName( )); 

           public static void service ( ) {
              (bool status, int index) stat = select_ip_addrs ( host ); 
              if(! stat.status ) 
              {
                printer.write("ERROR: no error network devices found!", color.red); 
              }
              
              IPAddress  _ipaddr = host.addressList[stat.index];
              IPEndPoint _iep    = new IPEndPoint(_ipaddr, _NP.SERVER_PORT); 
              Socket     _rs     = new socket
                                   (
                                         ipaddr.AddressFamily,
                                         SocketType.Stream,
                                         ProtocolType.Tcp
                                   ); 
              try {
                _rs.Bind(iep); 
                _rs.Listen(_NP.MAX_CONN); 
        
              }

           }

           internal static (bool, int) select_ip_addrs (IPHostEntry ihe) {
      
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
                try {
                   write("please select an ip <index>", color.mag); 
                   
                }
              }
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
