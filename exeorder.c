#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <time.h>
#include <fcntl.h>
#include <termios.h>
#include "slash.h"


//static void siginthandler2(int signo){
//	if(SIGINT == signo){
//		printf("\n");
//		exit(0);
//		exeorder();
//	}
//}

int exeorder(){
	
		char * input;
		input = malloc(256);
		char ** comrade;
		comrade = malloc(256);

		char cwd[256];
		printf("%s@%s:%s $ ",getenv("USER"),getenv("HOSTNAME"),getcwd(cwd, sizeof(cwd)));
		
		scanf(" %[^\n]s",input);
		printf("input: %s\n",input);
		comrade = parse_args(input);
	
		if(!strcmp(comrade[0],"exit")){
			exit(0);
		}
		
		if(!strcmp(comrade[0],"cd")){
			if(comrade[2]){
				printf("cd: too many arguments\n");
			}else{
				int i = chdir(comrade[1]);
				if(i < 0){
					printf("Unable to move to \"%s\"\n",comrade[1]);
				}
			}
		}else if(detect_operators(comrade)){
			int i = detect_operators(comrade);
			operation(comrade,i);
			
		}else{
		
			int f = fork();
			if(!f){
				//signal(SIGINT,siginthandler2);
				execvp(comrade[0],comrade);
				printf("%s\n",strerror(errno));
			}
			wait(NULL);
		}
		
		free(input);
		free(comrade);
		input = malloc(256);
		comrade = malloc(256);
		return 0;
}

