#include <stdio.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>

int shmid;
char* shmpointer;

//properly release all resources when process recieves sigint
void sig_handler(int signo){
	if(signo == SIGINT){
		printf("recieved SIGINT\n");
		if(shmdt(shmpointer) == -1)
			printf("error detaching\n");
		if(shmctl(shmid,IPC_RMID,0) == -1)
			printf("error erasing memory\n");
		exit(0);
	}
}

void main(){
	key_t key;
	
	//set signal to sigint
	if(signal(SIGINT, sig_handler) == SIG_ERR)
		printf("Can't catch SIGINT\n");

	//generate key
	if((key = ftok("/tmp", 0)) == -1){
		printf("Error generating key\n");
		exit(1);
	}

	//obtain the key for the 10-byte segment
	if((shmid = shmget(IPC_PRIVATE,10,IPC_CREAT | 0600)) < 0){
		printf("Error getting ID\n");
		exit(2);
	}
	else 
		printf("Shared Memory id:  [%d]\n", shmid);
	//in an infinite loop
	while(1){
		//reads the value stored in the shm segment
		if((shmpointer = shmat(shmid, 0, 0)) == (void*) -1){
			printf("Error with shmat\n");
			exit(1);
		}
		else{
			printf("Shared Memory Pointer: %s\n", shmpointer);
		}

		int shmlength = strlen(shmpointer);
		char* cbuf;
		int cbuflen;
		//if the value in shm is "Hi"
		if(strcmp(shmpointer, "Hi") == 0){
			cbuf = "Bye";
			cbuflen = strlen(cbuf);
			//write to string "Bye"
			sprintf(shmpointer, "Bye");
			printf("Before write (%lu): %s\n", strlen(shmpointer),shmpointer);
		}
		else{
			cbuf = "Hi";
			cbuflen = strlen(cbuf);
			//writes "hi" in the shm segment
			sprintf(shmpointer, "Hi");
			printf("After write (%lu): %s\n", strlen(shmpointer), shmpointer);
		}
		sleep(2);
	}
}
