#include <stdio.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>

//properly release all resources when process recieves sigint
int semid;
void sig_handler(int signo){
	if(signo == SIGINT)
		printf("\nrecieved SIGINT\n");
	if(semctl(semid,IPC_RMID,0) == -1)
		printf("\nerror erasing memory: %s\n", strerror(errno));
		
	exit(0);
}

void main(){
	key_t key;
	//set signal to sigint
	if(signal(SIGINT, sig_handler) == SIG_ERR)
		printf("Can't catch SIGINT\n");

	//generate key
	if((key = ftok("/tmp", 0)) == -1){
		printf("Error generating key\n");
	}

	if((semid = semget(IPC_PRIVATE, 1, 0666| IPC_CREAT)) < 0){
		printf("Semget error\n");
		exit(1);
	}

	
	printf("semid is: %d\n",semid);

	while(1){
		int semVal;
		if((semVal=semctl(semid,0,GETVAL))== -1){
			printf("Error getting sem value\n");
		}
		else
			printf("Value of Semphore: %d\n", semVal);

		struct sembuf op[1];

		op[0].sem_num = 0;
		op[0].sem_op = 1;
		op[0].sem_flg = 0;
		
		if(semop(semid,op,1)== -1)
			printf("Error incrementing\n");

		sleep(1);
	}
		
}
