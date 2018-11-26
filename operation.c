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


int operation(char ** comrade, int position){
	if(!strcmp(comrade[position],";")){
		char ** comrade_clone1;
		char ** comrade_clone2;
		comrade_clone1 = malloc(256*sizeof(char));
		comrade_clone2 = malloc(256*sizeof(char));
		int i = 0;
		int j = 0;
		while(strcmp(comrade[i],";")){
			comrade_clone1[i] = comrade[i];
			i++;
		}
		comrade_clone1[i] = NULL;
		i++;
		while(comrade[i]){
			comrade_clone2[j] = comrade[i];
			i++;
			j++;
		}
		int f = fork();
		if(!f){
			execvp(comrade_clone1[0],comrade_clone1);
		}
		wait(NULL);
		int o = 0;
		exeorder(comrade_clone2);
		wait(NULL);
	}else if(!strcmp(comrade[position],">")){
		wut = dup(STDOUT_FILENO);
		dup2(3, STDOUT_FILENO);
		printf("hola");
		dup2(backup_stdout, STDOUT_FILENO);		
	/*char ** comrade_clone1;
		char ** comrade_clone2;
		comrade_clone1 = malloc(10*256*sizeof(char));
		comrade_clone2 = malloc(10*256*sizeof(char));
		int i = 0;
		int j = 0;
		while(strcmp(comrade[i],">")){
			comrade_clone1[i] = comrade[i];
			i++;
		}
		comrade_clone1[i] = NULL;
		i++;
		while(comrade[i]){
			comrade_clone2[j] = comrade[i];
			i++;
			j++;
		}
		//int f = fork();
		//if(!f){
		//	execvp(comrade_clone1[0],comrade_clone1);
		//}
		//wait(NULL);
		FILE *fp;
 		char line[130];			
  		fp = popen("ls -l", "r");
		int file = open(comrade_clone2, O_CREAT | O_APPEND, 0644);
		while(fgets(line, sizeof(line), fp)){
			printf("1\n");
			printf("%s", line);
			write(file,line,sizeof(line));
		}
	    pclose(fp);
		close(file); */
		printf("I don't know how to do this\n");
	}else if(!strcmp(comrade[position],"<")){
		printf("I don't know how to do this\n");
	}
	else if(!strcmp(comrade[position],"|")){
		printf("I don't know how to do this\n");
	}
	
}

