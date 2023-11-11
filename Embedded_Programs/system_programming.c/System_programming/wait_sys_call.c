#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>
#include<wait.h>
int main()
{
	pid_t pid,cpid;
	int var=0,i=0;
	pid=fork();
	if(pid < 0)
	{
		printf("Failed to create the child process\n");
		exit(-1);
	}
	else if(pid > 0)
	{
		printf("Parent process is running\n");
	//	sleep(5);
		cpid=wait(&var);
		if(WIFSIGNALED(var))
		{
			printf("var : 0x%x\n",var);

			printf("The normal termination:%x\n",WTERMSIG(var));
			printf("terminated child id:%d\n",cpid);
		}
	}
	else
	{
	//	sleep(5);
		//raise(2);
		printf("Child process id:%d\n",getpid());
		printf("Parent process id:%d\n",getppid());
		//exit(20);
		abort();

	}
}



