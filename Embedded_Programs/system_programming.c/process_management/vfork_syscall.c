#include<stdio.h>
#include<unistd.h>
int main()
{
	pid_t pid;
	pid=vfork();
	if(pid < 0)
	{
		printf("Failed to create the child\n");
		exit(1);
	}
	else if(pid > 0)
	{
		printf("In parent\n");
		sleep(10);
		printf("After child in parent\n");
	}
	else
	{
		printf("In child\n");
		sleep(2);
	}
}


