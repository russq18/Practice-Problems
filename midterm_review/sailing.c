#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

static void sail(int signo){
	if(signo == SIGUSR1){
		printf("rides over\n");
		exit(0);
	}
}

int main(int argc, char * argv []){

	if(argc != 2){
		printf("command line error\n");
		exit(0);
	}

	char* string = argv[1];

	struct sigaction act, oact;
	act.sa_handler = sail;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;

	if(sigaction(SIGUSR1, &act, &oact) < 0)
		return 0;

	while(1){
		printf("%s Im sailing! Im sailing!!\n",string);
		sleep(1);
	}
}
