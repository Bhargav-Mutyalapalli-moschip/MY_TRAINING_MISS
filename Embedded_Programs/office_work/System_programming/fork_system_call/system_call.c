#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
main()
{
	
	pid_t pid,parentid;
	pid=fork();
	if(pid > 0)
	{
		printf("parent:%d\n",getpid());
		printf("Parent : child process id:%d\n",pid);
		while(1)
		{
			printf("pare");
		printf("8888888888");
		sleep(1);
		}
	}
	/*else
	{
		printf("child:%d\n",getpid());
		printf("Child : parent process id:%d\n",getppid());
		printf("Child process id:%d\n",pid);
		while(1)
		{
			printf("chlde");
		printf("99999");
			sleep(10);
		}
	}*/


}
