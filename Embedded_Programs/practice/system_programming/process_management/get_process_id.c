#include<stdio.h>
#include<unistd.h>    //The pid related info header
int main()
{
	pid_t pid,ppid;
/*-----------the current process id----*/
	pid=getpid();
	printf("The process id:%d\n",pid);
/*-----------the current process parent  id----*/
	ppid=getppid();
	printf("The parent process id:%d\n",ppid);
}


