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


int detect_operators(char ** comrade, int i){
	while(comrade[i]){
		if(!strcmp(comrade[i],";")){
			return i;
		}else if(!strcmp(comrade[i],"|")){
			return i;
		}else if(!strcmp(comrade[i],"<")){
			return i;
		}else if(!strcmp(comrade[i],">")){
			return i;
		}
		i++;
	}
	return 0;
}
