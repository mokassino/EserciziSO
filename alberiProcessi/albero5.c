#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>


int glob = 4;
int pid = 0;

int main ()
{        signal(SIGCHLD,SIG_IGN);
        int stato;
	int i;
         printf(" radice %d\n", getpid());
	for (i = 1; i < 4; i ++)
	{
		if (pid == 0)
		{
			pid = fork();  
        

		}

		if (pid != 0)

		{
			glob = glob * 2;

		}

		glob = glob - 1;
	}
wait(&stato);
printf ("processo = %d, padre = %d, glob = %d i = %d\n", getpid(),getppid(), glob, i);
exit(0);
}
