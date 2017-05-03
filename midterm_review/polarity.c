#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void * thread_1(void *arg);
void * thread_2(void *arg);
int r;

int main(int argc, char argv[]){
	int err;
	pthread_t tid;
	int i;


	err = pthread_create(&tid, NULL,thread_1,&i);
	err = pthread_create(&tid,NULL, thread_2,&i);

	if(err != 0)
		perror("Error creating Threads");
	
	while(1){
	r = rand();
		sleep(1);
	}
}
void* thread_1(void *arg){
	int i = *(int *) arg;
	printf("thread 1 %d\n", i);
	fflush(NULL);
	
	char str[16];
	sprintf(str, "new thread: %d", i);

	while(1){
		if(r % 2 == 0){
			printf("EVEN\n");
			fflush(NULL);
			r++;
			sleep(2);
		}		
	}
	return((void*)0);
}


void* thread_2(void *arg){
	int i = *(int *) arg;
	printf("thread2 %d\n", i);
	fflush(NULL);
	
	char str[16];
	sprintf(str, "new thread: %d", i);

	while(1){
		if(r % 2 != 0){
			printf("ODD\n");
			fflush(NULL);
			r++;
			sleep(2);
		}		
	}
	return((void*)0);
}
