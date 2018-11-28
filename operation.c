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
	char ** comrade_clone1;
	char ** comrade_clone2;
	char * filename;
	comrade_clone1 = malloc(256*sizeof(char));
	comrade_clone2 = malloc(256*sizeof(char));
	filename = malloc(256*sizeof(char));
	if(!comrade[position]){}else
	if(!strcmp(comrade[position],";")){
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
		exeorder(comrade_clone1);
		int o = 0;
		exeorder(comrade_clone2);
		

	}else if(!strcmp(comrade[position],">")){
		int i = 0;
		int j = 0;
		//FILE* woo = dup(STDOUT_FILENO);
		while(strcmp(comrade[i],">")){
			comrade_clone1[i] = comrade[i];
			i++;
		}
		comrade_clone1[i] = NULL;
		i++;
		filename = comrade[i];
		i++;
		
		int woo = open(filename,O_CREAT | O_WRONLY,0644);
		int stdout_clone = dup(STDOUT_FILENO);
		dup2(woo,STDOUT_FILENO);
		exeorder(comrade_clone1);
		dup2(stdout_clone,STDOUT_FILENO);
		
		close(woo);
		
		//printf("comradi: %s\n",comrade[i]);
		if(!comrade[i]){}else
		if(!strcmp(comrade[i],";")){
			i++;
			while(comrade[i]){
				comrade_clone2[j] = comrade[i];
				//printf("this is in hwile: cc2: %s\n",comrade_clone2[j]);
				i++;
				j++;
			}
			comrade_clone2[j] = NULL;
			exeorder(comrade_clone2);
		}else if(!strcmp(comrade[i],">")){
			while(comrade_clone1[j]){
				comrade_clone2[j] = comrade_clone1[j];
				j++;
			}
			while(comrade[i]){
				comrade_clone2[j] = comrade[i];
				i++;
				j++;
			}
			comrade_clone2[j]=NULL;
			exeorder(comrade_clone2);
		}else{
			printf("info: items after %s are ignored\n",filename);
		}
	
		//free(comrade_clone1);
		//free(comrade_clone2);
		//exeorder(comrade_clone2);
	}else if(!strcmp(comrade[position],"<")){
		int i = 0;
		int j = 0;
		//FILE* woo = dup(STDOUT_FILENO);
		while(strcmp(comrade[i],"<")){
			comrade_clone1[i] = comrade[i];
			i++;
		}
		comrade_clone1[i] = NULL;
		i++;
		filename = comrade[i];
		i++;
		
		int woo = open(filename,O_CREAT | O_RDONLY,0644);
		int stdin_clone = dup(STDIN_FILENO);
		dup2(woo,STDIN_FILENO);
		exeorder(comrade_clone1);
		dup2(stdin_clone,STDIN_FILENO);
		
		close(woo);
		
		//printf("comradi: %s\n",comrade[i]);
		if(!comrade[i]){}else
		if(!strcmp(comrade[i],";")){
			i++;
			while(comrade[i]){
				comrade_clone2[j] = comrade[i];
				//printf("this is in hwile: cc2: %s\n",comrade_clone2[j]);
				i++;
				j++;
			}
			comrade_clone2[j] = NULL;
			exeorder(comrade_clone2);
		}else if(!strcmp(comrade[i],">")){
			while(comrade_clone1[j]){
				comrade_clone2[j] = comrade_clone1[j];
				j++;
			}
			while(comrade[i]){
				comrade_clone2[j] = comrade[i];
				i++;
				j++;
			}
			comrade_clone2[j]=NULL;
			exeorder(comrade_clone2);
		}else{
			printf("info: items after %s are ignored\n",filename);
		}
		
		
		//printf("I don't know how to do this\n");
	}
	else if(!strcmp(comrade[position],"|")){
		printf("I don't know how to do this\n");
	}
		//free(comrade_clone1);
		//free(comrade_clone2);
		//free(filename);	
}
