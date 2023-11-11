#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	pid_t pid;
	pid=fork();
	if(pid < 0)
	{
		printf("Failed to create the child process\n");
		exit(-1);
	}
	else if(pid > 0)
	{
		printf("Child process id:%d\n",pid);
		printf("parent process id:%d\n",getpid());
	}
	else
	{
		printf("Child process id:%d\n",pid);
		printf("parent process id:%d\n",getpid());
	}




}

	
