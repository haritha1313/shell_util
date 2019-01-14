#include<stdio.h>
#include<unistd.h>
int main()
{
	pid_t pid;
	pid = fork();
	if(pid == -1)
	{
		printf("Error making Process!\n");
		return(-1);
	}
	if(!pid) // if child process is running
	{
		printf("Parent\n");
		sleep(1);
	}
	else
	{
		printf("Child with PID : %d\n",pid);
		sleep(1);
		return(0);
	}
}
