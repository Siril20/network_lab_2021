#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
int main(){
	int fd[2];
	if(pipe(fd)==-1){
		printf("Error");
	}
	int pid = fork();
	if(pid == -1){
		printf("Fork Creation Failed Successfully");
	}
	if(pid ==0){	//Child Process
		close(fd[1]);
		int arr[10];
		int n;
		read(fd[0],&n,sizeof(int));
		read(fd[0],arr,sizeof(int) *n);
		for(int i=0;i<n;i++){
			printf("%d \t",arr[i]);
		}
		printf("\n");
		close(fd[0]);

	}else{	//Parent Process
		close(fd[0]);
		int arr[10];
		int n,i,k=0;
		printf("Enter a number");
		scanf("%d",&n);
		for(i=0;i<=n;i++){
			if(i%2==1){
				arr[k]=i;
				k++;
			}
		}
		write(fd[1],&k,sizeof(int));
		write(fd[1], arr, sizeof(int) * n);
		close(fd[1]);
	}
	return 0;
}
