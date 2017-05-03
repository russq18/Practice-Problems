#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>


int main(void){

	pid_t pid;

	printf("spawning..\n");

	if((pid = fork()) < 0) {
		printf("fork error\n");
		return;
	} else if(pid == 0){
		printf("sucess\n");
		if(execl("./repeater", "repeater", "child", NULL) == -1) {
			strerror(errno);
			printf("error execl\n");
		}
	}
	else  
	{    
    		int ret_status;    
    		waitpid(pid , &ret_status, 0);  

    		if(ret_status == 0){
       			printf("The child process terminated normally.\n");
			printf("parent\n");    
    		}

    		if(ret_status == 1)      
    		{
       		printf("The child process terminated with an error!.\n");
		printf("parent\n");    
    		}
		exit(0);
	}
}	


