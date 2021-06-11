import java.net.InetAddress;
import java.util.Scanner;
class FindIp{
	public static void main(String[] args){
		String domainName;
		if(args.length == 1){
			domainName = args[0];
		}else{
			Scanner domainInput = new Scanner(System.in);
			System.out.print("Enter Domain Name :");
			domainName = domainInput.nextLine();
		}
		try{
			InetAddress domainObject = InetAddress.getByName(domainName);
			String host_ip = domainObject.getHostAddress();
			System.out.println("IP Address is " + host_ip);

		}catch(Exception e){
			System.out.println(e);
		}
	}
}
