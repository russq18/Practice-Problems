#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>


int main(void){

	pid_t pid;

	printf("loading..\n");

	 if((pid=fork()) == 0){
		if(execl("./sailing", "sailing", "Bitch", NULL) == -1) {
			printf("error execl %s\n",strerror(errno));
			exit(1);
		}

	}
		sleep(10);
		kill(pid, SIGUSR1);

    		if(waitpid(pid ,NULL, 0)== -1){
			printf("error waiting on child: %s\n", strerror(errno));
			exit(1);
		}  
	}
	
	

