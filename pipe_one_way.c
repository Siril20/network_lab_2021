#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
void receive_msg(int fd[]){
	close(fd[1]);
	char y[30];
	read(fd[0],y,sizeof(y));
	close(fd[0]);
	printf("Process ID : %d\n", getpid());
	printf("Message Received: %s",y);
}
void send_msg(int fd[]){
	close(fd[0]);
	char y[30];
	printf("Process ID: %d\n", getpid());
	printf("Enter the Message:");
	fgets(y,sizeof(y),stdin);
	write(fd[1],y,sizeof(y));
	close(fd[1]);
}
int main(){
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
		receive_msg(fd);
	}else{	//parent process
		send_msg(fd);
	}
	return 0;
}
