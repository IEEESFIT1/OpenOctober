//Java program for FTPLogin
import java.io.BufferedReader;
import java.io.PrintWriter;
import java.io.InputStreamReader;
import java.net.Socket;
public class FTPLogin
{
    public static void main (String args[])
    {
        Socket socket = null;
        BufferedReader in = null;
        PrintWriter out = null;
        String line = null;
        if (args.length != 3)
        {
            System.out.println ("USAGE: IP USER PASS");
        }
        else
        {
            try
            {
                socket = new Socket (args[0], 21);
                in = new BufferedReader (new InputStreamReader(socket.getInputStream()));
                out = new PrintWriter (socket.getOutputStream());
                out.print("user "+ args[1] + "");
                out.print("pass "+ args[2] + "");
                out.print ("pwd");
                out.print ("quit");
                out.flush();
                while ( (line = in.readLine()) != null)
                {
                    System.out.println(line);
                }
            }
            catch (Exception e)
            {
                System.out.println(e.getMessage());
            }
            finally
            {
                try
                {
                    out.close();
                    in.close();
                    socket.close();
                }
                catch (Exception fe)
                {
                    System.out.println ("RESOURCE CLOSE EXCEPTION " +fe.getMessage());
                }
            }
        } 
    } 
} 
