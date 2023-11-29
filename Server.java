import java.net.*;
import java.io.*;

class Server
{
    public static void main(String arg[])throws Exception
    {
        System.out.println("Server Application is running...");
        ServerSocket ssobj = new ServerSocket(2100);            //2100 is a port number
        System.out.println("Server is running at port no :2100");

        Socket s = ssobj.accept();
        System.out.println("Server and client connection is succesfull");

        PrintStream ps = new PrintStream(s.getOutputStream());

        BufferedReader br1 = new BufferedReader(new InputStreamReader(s.getInputStream()));
        BufferedReader br2 = new BufferedReader(new InputStreamReader(System.in));
                System.out.println("Chat Messenger Stated...");
        String str1,str2;
        while((str1 = br1.readLine())!= null)
        {
            System.out.println("Client says: "+str1);
            System.out.println("Enter message for client : ");
            
            str2 = br2.readLine();
            ps.println(str2);
        }
        System.out.println("Thank you for using Chat messenger...");

    }
}