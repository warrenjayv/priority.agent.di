using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

using pri.net.report;

namespace pri {
  namespace net {
     namespace station {
        public class server {
            
           static _NET_PARAM _NP   = new _NET_PARAM( 8042, 23, 24 ); 
           static IPHostEntry host = Dns.GetHostEntry(Dns.GetHostName( )); 

           public static void service ( ) {
              (bool status, int index) stat = select_ip_addrs ( host ); 
              if(! stat.status ) 
              {
                printer.write("ERROR: no error network devices found!", color.red); 
              }
              
              IPAddress  _ipaddr = host.AddressList[stat.index];
              IPEndPoint _iep    = new IPEndPoint(_ipaddr, _NP.SERVER_PORT); 
              Socket     _rs     = new Socket
                                   (
                                         _ipaddr.AddressFamily,
                                         SocketType.Stream,
                                         ProtocolType.Tcp
                                   ); 
              try 
              {
                _rs.Bind(_iep); 
                _rs.Listen(_NP.MAX_CONN); 
        
              }
              catch ( Exception e )
              {
                 printer.write(e.ToString( ), color.red);   
              }

           }

           internal static (bool, int) select_ip_addrs (IPHostEntry ihe) {
      
              printer.write("ip list: ", color.mag); 
              for (int i = 0; i < ihe.AddressList.Length; i++) 
              {
                 printer.write(" ["+i+"] "+ihe.AddressList[i], color.mag); 
              }

           }

           internal static void select_ip ( ) 
           {
              while(true) 
              {
                try {
                   printer.write("please select an ip <index>", color.mag); 
                   
                }
                catch (InvalidSelectionException e) 
                {

                }
                catch (Exception e) 
                {


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

           public _NET_PARAM(int _BUFFER_LEN, int _SERVER_PORT, int _MAX_CONN ) 
           {
              BUFFER_LEN  = _BUFFER_LEN;
              SERVER_PORT = _SERVER_PORT;
              MAX_CONN    = _MAX_CONN;
              SEL         = 0;
              IS_IP_SET   = false;
              IS_PORT_SET = false; 
           }
        }

        public class InvalidSelectionException : Exception 
        {
          public InvalidSelectionException( ) { printer.write("selection out of range. try again.", color.red ); }
        }
     }
  }
}
