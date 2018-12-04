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

static void siginthandler(int signo){
	if(SIGINT == signo){
		char cwd[256];
		char hostname[256];
		gethostname(hostname,256);
		printf("\n%s@%s:%s $ ",getenv("USER"),hostname,getcwd(cwd, sizeof(cwd)));
		fflush(stdout);
	}
}

static void siginthandler2(int signo){
	if(SIGINT == signo){
		printf("\n");
		//char cwd[256];
		//printf("\n%s@%s:%s $ ",getenv("USER"),getenv("HOSTNAME"),getcwd(cwd, sizeof(cwd)));
		//fflush(stdout);
	}
}

/*
int getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}

char * initializer(){
	char * title;
	char * file = getenv("USER");
	strcat(file,".sl");
	
	if(access(file,F_OK) != -1 ) {
		int fuser = open(getenv("USER"),O_RDONLY);
		read(fuser,title,10);
		close(fuser);
	} else {
    	int fuser = open(file,O_CREAT | O_WRONLY, 0644);
		srand(time(NULL));
		int num = rand();
		printf("Hello %s, please pick a role:\na - an Archeologist\nb - a Barbarian\nc - a Caveman\nh - a Healer\nk - a Knight\nm - a Monk\np - a Priest/Pristess\nr - a Rogue\nR - a Ranger\ns - a Samurai\nt - a Tourist\nv - a Valkyrie\nw - a Wizard\n",getenv("USER"));
	
			char input = getch();
			printf("%d\n",input=='a');
		
		while(input != 'a'){
			input = getch();
		}
		
		switch(input){
			case 'a': title = "Digger";
			case 'b': title = "Plunderer";
			case 'c': title = "Troglodyte";
			case 'h': title = "Rhizotomist";
			case 'k': title = "Gallant";
			case 'm': title = "Candidate";
			case 'p': title = "Aspirant";
			case 'r': title = "Tenderfoot";
			case 'R': title = "Footpad";
			case 's': title = "Hatamoto";
			case 't': title = "Rambler";
			case 'v': title = "Stripling";
			case 'w': title = "Evoker";
		}
		
		int a = write(fuser,title,10);
		printf("%d\n",a);
		close(fuser);
	}	
	return title;
}
*/


int main(){
	signal(SIGINT,siginthandler);
	char * input;
	char ** comrade;
	char hostname[256];
	gethostname(hostname,256);
	//int i = 0;
	while( 2){
		//close(STDIN_FILENO);
		signal(SIGINT,siginthandler);
		input = malloc(256);	
		comrade = malloc(256);

		char cwd[256];
		printf("%s@%s:%s $ ",getenv("USER"),hostname,getcwd(cwd, sizeof(cwd)));
		
		scanf(" %[^\n]s",input);
		//if(sizeof(*input)<256){
			printf("input size: %d\n",sizeof(input));
			printf("input: %s\n",input);
			comrade = parse_args(input);
			signal(SIGINT,siginthandler2);
		//if(i ==1){sleep(100);}
			exeorder(comrade);//}
		//else{printf("Command too long\n");}
		//wait(NULL);
		free(input);
		free(comrade);
		//i ++;
		//sleep(100);
	}
	return 0;
}

