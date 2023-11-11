#include<stdio.h>
#include<stdio_ext.h>
#include<signal.h>
#include<unistd.h>
int main()
{
	pid_t  pid;
	int i=0,ret=0;
	printf("Pid:%d\n",getpid());
	ret=pause();
	printf("The returned value:%d\n",ret);
	while(i<=100)
	{
		printf("The output:%d\n",i);
	}
}






