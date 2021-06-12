import java.net.*;
import java.io.*;
import java.util.*;
class ClientB{
	public static void main(String args[]){
		Scanner scan_obj = new Scanner(System.in);
		String hostName = "localhost";
		int portNumber = 8000;
		PrintWriter out;
		BufferedReader in;
		String msg;
		try{
			Socket client_socket = new Socket(hostName,portNumber);
			out = new PrintWriter(client_socket.getOutputStream(),true);
			in = new BufferedReader(new InputStreamReader(client_socket.getInputStream()));
			System.out.println(in.readLine());
			while((msg = scan_obj.nextLine()).equals("quit")!=true){
				out.println(msg);
			}
			out.println(msg);
			System.out.println("Exiting..");
		}catch(Exception e){
			System.out.println(e);
		}
	}
}
