#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main(){
  pid_t id;
  id = fork();
  if(id<0){
    printf("Fork Process Creation Failed Successfully");
    return 1;
  }
  else if(id==0){
    printf("Process: %d Running\n",getpid());
    sleep(10);
    printf("Process: %d Ends\n",getpid());
    return 0;
  }
  else{
    printf("Process: %d Running\n",getpid());
    sleep(30);
    printf("Process: %d Ends\n",getpid());
    return 0;
  }
}
