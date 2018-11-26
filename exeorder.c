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

int exeorder(char ** comrade){
	

		

	
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
		

		return 0;
}

