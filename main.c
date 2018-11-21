#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

static void sighandler(int signo){
	if(SIGINT == signo){
		printf("\n");
	}
}

static void sighandler2(int signo){
	if(SIGINT == signo){
		printf("hello!\n");		
		exit(0);
	}
}

int main(){
	signal(SIGINT,sighandler);
	
	char * env = getenv("PATH");
	char * input;
	input = malloc(256);

	while(1){
		printf("user: $ ");
		scanf("%s",input);
		
		char command[256]; 
		strcat(command,input);
		
		int f = fork();
		if(!f){
			signal(SIGINT,sighandler);
			char env_copy[256];
			strcpy(env_copy,env);
			int i = 0;
			printf("%s\n",env_copy);
			char *command;
			printf("%s\n",command);
			while(i < 4){
				command = strsep(&env_copy,":");
				strcat(command,"/");
				strcat(command,input);
				printf("%s\n",command);
				execlp(command,"",NULL);
				command = strtok(NULL, ":");
				i++;
			}		
		}
		wait(NULL);

		

		free(input);
		input = malloc(256);
	}
	return 0;
}
