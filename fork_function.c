#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main(){
  int id = fork();
  if (id>0){
    wait(NULL);
  }else if(id == 0){
    printf("Parent Process ID : %d\n", getppid());
    printf("Child Process ID: %d\n", getpid());
  }else{
    printf("No Process");
  }
  return 0;
}
