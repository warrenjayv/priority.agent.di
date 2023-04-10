
using pri.net.station;

namespace pri 
{
  namespace net 
  {
    namespace report 
    {
      public static class printer {
         public static void write(string msg, ConsoleColor c) 
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
     }
   }
 }
