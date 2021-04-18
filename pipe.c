#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main(){
  int fd[2];
  if(pipe(fd) == -1){
    //pipe return -1 on failure
    printf("Pipe Creation Failed Successfully");
    return 1;
  }
  pid_t id = fork();
  if(id < 0){
    printf("Fork Creation Failed Successfully");
    return 1;
  }else if(id == 0){
    close(fd[1]);
    char y[30];
    read(fd[0],y,sizeof(y));
    close(fd[0]);
    printf("\nMessage recived from parent process:\n%s\n",y);
  }else{
    close(fd[0]);
    char s[30];
    printf("\nEnter the Message:");
    fgets(s, sizeof(s), stdin);
    write(fd[1],s,sizeof(s));
    close(fd[1]);
  }
  return 0;
}
