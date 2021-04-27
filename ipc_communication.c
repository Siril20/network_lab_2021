#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
void receive_msg(int fd[]){
	close(fd[1]);
	char y[30];
	read(fd[0],y,sizeof(y));
	close(fd[0]);
	printf("%s",y);
}
void send_msg(int fd[]){
	close(fd[0]);
	char y[30];
	printf("Enter the Message:");
	fgets(y,sizeof(y),stdin);
	write(fd[1],y,sizeof(y));
	close(fd[1]);
}
int main(){
	int n=4;
	while(n>3 || n<1){
		printf("1.Parent to Child\n2.Child to Parent\n3.Exit\n");
		printf("Enter direction:");
		scanf("%d",&n);
		if(n==3){
			printf("Exiting\n");
			return 0;
		}
		getchar();
	}
	int fd[2];
	if(pipe(fd) == -1){	//pipe return -1 on failure
		printf("Pipe Creation Failed Successfully");
		return 1;
	}
	pid_t id = fork();
	if(id < 0){
		printf("Fork Creation Failed Successfully");
		return 1;
	}else if(id == 0){	//child process
		if(n==1){
			receive_msg(fd);
		}
		else{
			send_msg(fd);
		}
	}else{	//parent process
		if(n==1){
			send_msg(fd);
		}
		else{
			receive_msg(fd);
		}
	}
	return 0;
}
