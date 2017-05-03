#include <sys/shm.h>
#include <sys/ipc.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SHM_SIZE 4

int main(int argc, char* argv[]){
	key_t key;
    	int shmid;
    	char *shmpointer;
	char* value;
	
	if (argc != 2) {
        	printf("invalid input\n");
        	exit(1);
	}

	printf("%s\n", argv[1]);
	value = argv[1];
	printf("value: %s\n", value);
		
	if((key = ftok("drop.c", 'R')) == -1){
		printf("ftok\n");
		exit(1);
	}


	printf("key: %d\n", key);

	if((shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0600)) < 0) {
        	perror("shmget");
        	exit(1);
    	}else{	
		printf("shmid: %d\n",shmid);
	}

	if((shmpointer = shmat(shmid,0,0)) == (void*) -1){
		printf("shmat error");
		exit(1);
	}else{
		printf("Attached to %d\n", shmid);
	}
	/*
	if (shmpointer == NULL) {
		printf("null pointer\n");
	}
	*/


	int shmLength = strlen(shmpointer);
	char *cbuf = value;
	int cbuflen = strlen(cbuf);

	if (shmLength+cbuflen+1 < SHM_SIZE) {
		printf("Before write (%lu): %s\n", strlen(shmpointer), shmpointer);

		memcpy(shmpointer+shmLength, cbuf,  cbuflen+1);

		printf("After write (%lu): %s\n", strlen(shmpointer), shmpointer);
	} else
		printf("Buffer full\n");
	/*
	while(1){
		printf("loop");
		if (value == *shmpointer)
			break;
		pause();	
	}
	*/

	if(shmdt(shmpointer) < 0){
        	perror("shmdt");
        	exit(1);
    	}
	if (shmctl(shmid, IPC_RMID, 0)  == -1)
		printf("Can not validate shared memory");

	printf("detached from %d\n", shmid);
    	return 0;
	
}
