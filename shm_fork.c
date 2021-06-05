#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<sys/wait.h>
#include<unistd.h>

#define SHSIZE 10

int main(){
	int shmid;
	key_t key;
	char *shm;
	char *s;
	key = 8080;
	int fork_id = fork();
	if(fork_id<0){
		printf("Fork Error");
		return 1;
	}
	if(fork_id==0){		//Child Process
		shmid = shmget(key, SHSIZE, 0666);

		if(shmid < 0){
			printf("Failed Accessing Shared Memory Space id...");
			return 1;
		}
		shm = shmat(shmid, NULL, 0);

		if(shm == (char *)-1){
			printf("Failed Attaching to Shared Memory Space");
			return 1;
		}

		printf("Printing Msg from shared Memory...\n");

		for(s=shm; *s!=0;s++)
			printf("%c",*s);

		printf("\n");

		*shm = '*';

		return 0;
	}
	else{			//Parent Process
		shmid = shmget(key, SHSIZE, IPC_CREAT | 0666);

		if(shmid < 0  ){
			printf("Failed Creating Shared Memory Space...");
			return 1;
		}

		shm = shmat(shmid, NULL, 0);

		if(shm == (char *)-1){
			printf("Failed Attaching to Shared Memory Space...");
			return 1;
		}

		printf("Copying Msg to Shared Memory...\n");

		strcpy(shm,"Hello World");

		s=shm;
		s+=11;
		*s = 0;

		while(*shm != '*')
			sleep(1);

		return 0;
	}
}
