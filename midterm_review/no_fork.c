#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>
#include <errno.h>

int main(void){

	pid_t pid;
	struct rlimit proc_limit;

	proc_limit.rlim_cur = 0;
	proc_limit.rlim_max = 1024;

	if(setrlimit(RLIMIT_NPROC, &proc_limit) == -1)
		strerror(errno);

	getrlimit(RLIMIT_NPROC, &proc_limit);
	printf("number of child processes allowed: %d\n", proc_limit.rlim_cur);
	printf("creating child process...\n");
	
	if((pid = fork()) == -1){
		printf("sucess child not created!!\n");
		return;
	}else {
		printf("fail, child created!!\n");
	}

}
