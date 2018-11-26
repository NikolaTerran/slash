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

char ** parse_args(char * line){
	char  **a;
	a = malloc(10*256*sizeof(char));	
	int i = 0;
	while(line){
		a[i] = strsep(&line," ");
		i++;
	}
	a[i] = NULL;
	return a;
}