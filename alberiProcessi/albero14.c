#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

int glob=5;
int pid = 0;
int main(){
       signal(SIGCHLD,SIG_IGN);
       int stato;
	fork();
	glob--;
	if (!fork()){
		glob--;
	}
	if (pid==0){
		pid=fork();
		glob--;
	}

	printf("Sono %d figlio di %d.\n Glob: %d\n\n",getpid(),getppid(),glob);
wait(&stato);
exit(0);
}
