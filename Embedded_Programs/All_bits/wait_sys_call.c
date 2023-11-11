#include<stdio.h>
#include <sys/wait.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
int main()
{
	pid_t pid,cpid;
	int status;
	pid=fork();
	if(pid < 0)
	{
		printf("Failed to create child\n");
		exit(1);
	}
	else if(pid > 0)
	{
		printf("parent is entered\n");
		printf("The parent process id:%d\n",getpid());
		printf("The child process id in parent:%d\n",pid);
		cpid=wait(&status);
		if(WIFEXITED(status))
		printf("The normal termination:%d\n",WEXITSTATUS(status));
		if(WIFSIGNALED(status))
		printf("The abnormal termination:%d\n",WTERMSIG(status));
		if(WIFSIGNALED(status))
		printf("The abnormal termination:%d\n",WCOREDUMP(status));
		printf("The terminated child pid in parent:%d\n",cpid);
	}
	else
	{
		printf("child entered\n");
		printf("The child process id:%d\n",getpid());
		printf("The returned child:%d\n",pid);
		sleep(5);
		printf("child terminated\n");
		raise(6);
	}
}



