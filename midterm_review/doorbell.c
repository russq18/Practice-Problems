#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

static void ding(int signo){
	printf("DING\n");
}

int main( int argc, char* argv []){
	struct sigaction act, oact;
	
	act.sa_handler = ding;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	if(sigaction(SIGUSR1, &act, &oact) < 0)
		return 0;

	while(1){
		pause();
	}
}
