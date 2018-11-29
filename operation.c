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

char** initialize(char** comrade,int * i,char * oper){
	int j = 0;
	char ** comrade_clone;
	comrade_clone = malloc(256);
	while(strcmp(comrade[*i],oper)){
			comrade_clone[j] = comrade[*i];
			(*i)++;
			j++;
		}
	(*i)++;
	comrade_clone[j] = NULL;
	return comrade_clone;
}

char** initialize2(char** comrade,int * i){
	int j = 0;
	char ** comrade_clone;
	comrade_clone = malloc(256);
	while(comrade[*i]){
			comrade_clone[j] = comrade[*i];
			(*i)++;
			j++;
		}
	(*i)++;
	comrade_clone[j] = NULL;
	return comrade_clone;
}
/*
void if_redir(char ** comrade,char** ){
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
}
*/
int operation(char ** comrade, int position){
	char ** comrade_clone1;
	char ** comrade_clone2;
	
	comrade_clone1 = malloc(256*sizeof(char));
	comrade_clone2 = malloc(256*sizeof(char));
	
	int * i;
	i = malloc(4);
	int ok = 0;
	i = &ok;
	
	if(!comrade[position]){}else
	if(!strcmp(comrade[position],";")){
		comrade_clone1 = initialize(comrade,i,";");
		comrade_clone2 = initialize2(comrade,i);
		exeorder(comrade_clone1);
		exeorder(comrade_clone2);
	}else if(!strcmp(comrade[position],">")){
		//printf(strcmp
		comrade_clone1 = initialize(comrade,i,">");
		char * filename;
		filename = malloc(256*sizeof(char));
		filename = comrade[*i];
		(*i)++;
		comrade_clone2 = initialize2(comrade,i);
		int woo = open(filename,O_CREAT | O_WRONLY,0644);
		int stdout_clone = dup(STDOUT_FILENO);
		dup2(woo,STDOUT_FILENO);
		//int o = 0;
		/*while(comrade_clone1[o]){
			printf("%s\n",comrade_clone1[o]);
			o++;
		
		}printf("%s\n",comrade_clone1[o]);*/
		exeorder(comrade_clone1);
		dup2(stdout_clone,STDOUT_FILENO);
		close(woo);
		
	}else if(!strcmp(comrade[position],"<")){
		comrade_clone1 = initialize(comrade,i,"<");
		char * filename;
		filename = malloc(256*sizeof(char));
		filename = comrade[*i];
		(*i)++;
		comrade_clone2 = initialize2(comrade,i);
		
		int woo = open(filename, O_RDONLY);
		int stdin_clone = dup(STDIN_FILENO);
		dup2(woo,STDIN_FILENO);
		exeorder(comrade_clone1);
		dup2(stdin_clone,STDIN_FILENO);
		
		close(woo);
		/*int i = 0;
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
			printf("R U CRAZZZZYYYY?\n");
			/*while(comrade_clone1[j]){
				comrade_clone2[j] = comrade_clone1[j];
				j++;
			}
			while(comrade[i]){
				comrade_clone2[j] = comrade[i];
				i++;
				j++;
			}
			comrade_clone2[j]=NULL;
			exeorder(comrade_clone2);*\/
		}else{
			printf("info: items after %s are ignored\n",filename);
		}
		//printf("I don't know how to do this\n"); 
		*/
	}
	else if(!strcmp(comrade[position],"|")){
		
		int o = 0;
		comrade_clone1 = initialize(comrade,i,"|");
		comrade_clone2 = initialize2(comrade,i);
		//o++;
		//(*i)++;

		int fd[2];
		//pipe_array[0] = STDIN_FILENO;
		//pipe_array[1] = STDOUT_FILENO;
		//printf("problem pipe\n");
		pipe(fd);
		
		int f = fork();
		if(!f)
        {
				close(fd[0]);
                /* Child process closes up input side of pipe */
				int stdout_clone = dup(STDOUT_FILENO);
				dup2(fd[1],STDOUT_FILENO);
                //close(fd[0]);
			
			
			exeorder(comrade_clone1);
			//execlp(comrade_clone1[0],"asdfs",NULL);	
			
			dup2(stdout_clone,fd[1]);
				exit(0);
                /* Send "string" through the output side of pipe */
                //write(fd[1], , (strlen(string)+1));
                //exit(0);
        }
        else
        {
				//nt stdin_clone = dup(STDIN_FILENO);
				//dup2(fd[1],STDIN_FILENO);
				close(fd[1]);
			int stdin_clone = dup(STDIN_FILENO);
			dup2(fd[0],STDIN_FILENO);
			
			exeorder(comrade_clone2);
			//execlp(comrade_clone2[0],"agsd",NULL);
			
			
			//sleep(10);
			close(fd[0]);
			dup2(stdin_clone,STDIN_FILENO);
			
			//exit(0);
				//char currentline[100];
				//comrade_clone2[o] = "<";
				//o++;
				   
			//assert(fd[0] != NULL);
				//FILE * g = fd[0];
				//
			//				int doo = open(fd[0],O_RDONLY,0644);
			//FILE *fptr = fdopen( fd[0], "rb" );
			//	comrade_clone2[o] = fp;
		    	//exeorder(comrade_clone2); 
        	//	while (fgets(currentline, sizeof(currentline), fptr)) {
            		//fprintf(stderr, "got line: %s\n", currentline);
            		/* Do something with `currentline` */
				//	printf("ls: %s\n",currentline);
					//comrade_clone2[o] = currentline;
					//(*i)++;
					//o++;
        	//	}//printf("woo\n");
				///comrade_clone2[o] = NULL;
				//exeorder(comrade_clone2);
                /* Parent process closes up output side of pipe */
               // close(fd[0]);
				
                /* Read in a string from the pipe */
                //nbytes = read(fd[0], readbuffer, sizeof(readbuffer));
                //printf("Received string: %s", readbuffer);
        }
		
		
	}
		//free(comrade_clone1);
		//free(comrade_clone2);
		//free(filename);	
}
