import java.net.*;
import java.io.*;
import java.util.*;
class ServerB{
	public static void main(String args[]){
		Scanner scan_obj = new Scanner(System.in);
		ServerSocket serverSocket;
		Socket clientSocket;
		PrintWriter out;
		BufferedReader in;
		String client;
		try{
			serverSocket = new ServerSocket();
			serverSocket.bind(new InetSocketAddress(8000));
			while(true){
				System.out.println("Waiting for Clients...");
				clientSocket = serverSocket.accept();
				System.out.println("Client Connected");
				out = new PrintWriter(clientSocket.getOutputStream(),true);
				in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
				out.println("Server Connected, enter quit  to disconnect");
				while((client=in.readLine()).equals("quit")!=true){
					System.out.println("Client : " + client);
				}
				System.out.println("Closing Client");
				clientSocket.close();
			}
		}catch(Exception e){
			System.out.print(e);
		}
	}
}
