//Java program for Creating a Non-Blocking Socket
public class test
    {
     public static void main(String args[])
         {
             try {
             SocketChannel sChannel = createSocketChannel("www.xxx", 8080);
                 while (!sChannel.finishConnect()) {
                 System.out.println("wonderful!! Connection Established!");
             }
         }
             catch (IOException e) {
		System.out.println("Warning: Some exception has occured!");
         }
     }
     public static SocketChannel createSocketChannel(String hostName, int port) throws IOException
         {
         SocketChannel sChannel = SocketChannel.open();
         sChannel.configureBlocking(false);
         sChannel.connect(new InetSocketAddress(hostName, port));
         return sChannel;
     }
}
