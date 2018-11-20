#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

static void sighandler(int signo){
	if(SIGINT == signo){
		printf("hello!\n");		
		exit(0);
	}
}


int main(){
	signal(SIGINT,sighandler);

	char * input;
	input = malloc(256);

	while(1){
		printf("user: $ ");
		scanf("%s",input);
		
		char command[256]; 
		strcpy(command, "/bin/");
		strcat(command,input);
		
		int f = fork();
		if(!f){
			execlp(command,"-a",NULL);
		}
		wait(NULL);

		

		free(input);
		input = malloc(256);
	}
	return 0;
}
