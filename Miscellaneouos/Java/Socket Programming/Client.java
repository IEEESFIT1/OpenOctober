import java.net.*;//net package for sockets
import java.io.*;//io package for taking inputs and sending outputs
class Client { //Class declaration(should be the name of the program as well)
  public static void main(String[] args)throws IOException { //declaring main method

    Socket s = new Socket("localhost", 3333); //creating socket object which stores 127.0.0.1 and port no
    DataInputStream din = new DataInputStream(s.getInputStream()); //creating InputStream to fetch the data
    DataOutputStream dout = new DataOutputStream(s.getOutputStream()); //creating output stream to send the data
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); //for providing input
    String s1 = "", s2 = ""; //s1 for sending and s2 for receiving
    while (!s1.equals("stop")) { //terminates communication after encountering 'stop'
      s1 = br.readLine();
      dout.writeUTF(s1);//sending data from s2 to the outputstream
      dout.flush();
      s2 = din.readUTF(); //receiving data from s2 to through the input stream
      System.out.println("From Server: " + s2); //print message from the server
    }

    dout.close();//close output stream
    s.close();//close the socket }
  }
