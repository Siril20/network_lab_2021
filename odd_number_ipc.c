#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
int receive_msg(int fd[]){
	close(fd[1]);
	char y[30];
	int x;
	read(fd[0],y,sizeof(y));
	close(fd[0]);
	sscanf(y,"%d",&x);
	return x;
}
void send_msg(int fd[]){
	close(fd[0]);
	char y[30];
	printf("Enter the Number:");
	fgets(y,sizeof(y),stdin);
	//scanf("%d",y);
	write(fd[1],y,sizeof(y));
	close(fd[1]);
}
int main(){
	int fd[2];
	int n;
	if(pipe(fd) == -1){	//pipe return -1 on failure
		printf("Pipe Creation Failed Successfully");
		return 1;
	}
	pid_t id = fork();
	if(id < 0){
		printf("Fork Creation Failed Successfully");
		return 1;
	}else if(id == 0){	//child process
		n = receive_msg(fd);
		for(int i=0;i<=n;i++){
			if(i%2!=0)
				printf("%d \t",i);
		}
		printf("\n");
	}else{	//parent process
		send_msg(fd);
	}
	return 0;
}
