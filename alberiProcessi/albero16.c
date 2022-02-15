#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>


int glob=0;
int pid=0;
int main(){
       signal(SIGCHLD,SIG_IGN);
       int stato;
	fork();
	glob--;
	if (fork()){
		pid = fork();
		glob--;
		pid = 0;
	}
	if (pid){
		glob--;
	}
	else{
		fork();
		glob--;
	}
	printf("Sono il processo %d, figlio di %d. GLOB = %d\n",getpid(),getppid(),glob);
wait(&stato);
exit(0);
}
