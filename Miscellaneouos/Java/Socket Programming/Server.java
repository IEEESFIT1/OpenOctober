import java.net.*;//net package for sockets
import java.io.*;//io package for taking inputs and sending outputs
class Server { //Class declaration(should be the name of the program as well)
  public static void main(String[] args)throws IOException { //declaring main method

    ServerSocket ss = new ServerSocket(3333); //create server socket
    Socket s = ss.accept(); //create socket for accepting client information
    DataInputStream din = new DataInputStream(s.getInputStream()); //creating InputStream to fetch the data
    DataOutputStream dout = new DataOutputStream(s.getOutputStream()); //creating output stream to send the data
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); //for providing input

    String s1 = "", s2 = ""; //s1 for sending and s2 for receiving
    while (!s1.equals("stop")) { //terminates communication after encountering 'stop'
      s1 = din.readUTF(); //receiving data from s2 to through the input stream
      System.out.println("From Client: " + s1);
      s2 = s1;
      dout.writeUTF(s2);//sending data from s2 to the outputstream
      dout.flush();//clear buffers
    }
    din.close();//close inputstream
    s.close();//close socket
    ss.close();//close server socket }
  }
