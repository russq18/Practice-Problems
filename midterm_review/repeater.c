#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){
	printf("test\n");

	if (argc < 2){
		printf("error invalid parameters\n");
		return;
	}
	else
		printf("aok\n");

	while(1){
		printf("%s\n", argv[1]);
		sleep(1);
	}
}
