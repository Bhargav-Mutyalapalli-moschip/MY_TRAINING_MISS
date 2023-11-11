#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int x=10;
int main()
{
	pid_t pid,i=0;
	pid=vfork();
	if(pid < 0)
	{
		printf("Failed to create the child process\n");
		exit(-1);
	}
	else if(pid > 0)
	{
		printf("%p------%d\n",&x,x);
	//	exit(0);
	}
	else
	{
		while(i<10)
		{
			printf("Surya");
			i++;
		}
		x=45;
		printf("%p------%d\n",&x,x);
		//exit(0);
	}
}


