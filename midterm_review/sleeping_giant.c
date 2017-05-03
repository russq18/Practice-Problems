#include <sys/sem.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h>
#include <pthread.h>
#include <errno.h>
#include <stdlib.h>


void* up_giant(void*arg);
void* down_giant(void*arg);



int main(void){

	char *filepath = "/tmp";
	int tokid = 0;
	key_t key;
	pthread_t tid;
	int semid;
	int thread;

	union semun {
		int val;
		struct semid_ds* buf;
		ushort* array;
	} arg;


	if ((key = ftok(filepath, tokid)) == -1)
		perror("Can not create token");

	if ((semid = semget(key, 1, 0666 | IPC_CREAT)) == -1)
		perror("Can not create semaphore");

	arg.val = 0;

	if ((semctl(semid,0, SETVAL, arg)) == -1)
		perror("Error setting semaphore to 0");

	thread = pthread_create(&tid, NULL, up_giant,&semid);
	thread = pthread_create(&tid, NULL, down_giant,&semid);

	if(thread != 0)
		perror("error creating threads");

	sleep(10);
	exit(0);
}

void * up_giant(void * arg){
	printf("up_giant\n");
	int semid = *(int*) arg;

	while(1){
		int semVal;
		if((semVal = semctl(semid,0,GETVAL))==-1)
			printf("error getting semaphore\n");

		struct sembuf op[1];
		op[0].sem_num = 0;
		op[0].sem_op = 1;
		op[0].sem_flg = 0;

		if (semop(semid, op, 1) == -1)
			printf("Error incrementing semaphore");

		printf("Semaphore value: %d\n", semVal);
		sleep(1);
	}
	
}

void * down_giant(void * arg){
	printf("down_giant\n");
	int semid = *(int*) arg;
	while(1){
		int semVal;
		struct sembuf op[1];

		op[0].sem_num = 0;
		op[0].sem_op = -1;
		op[0].sem_flg = 0;

		if((semVal= semctl(semid,0, GETVAL))== -1)
			printf("error getting semaphore\n");
	
		if(semVal > 0){
			if (semop(semid, op, 1) == -1)
				printf("Error decrementing semaphore");
			
			printf("Semaphore value: %d\n", semVal);
			sleep(1);
		}
	}
	
}
