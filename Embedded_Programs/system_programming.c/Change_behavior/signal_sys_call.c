#include<stdio.h>
#include<signal.h>
#include<unistd.h>
void newsignal();
int main()
{
	int i=0;
	signal(SIGINT,SIG_DFL);
	while(i<=100000)
	{
		sleep(1);
		printf("%d\n",i);
		printf("Pid:%d\n",getpid());
		printf("Running---------Continuing\n");
		i++;
	}
}
void newsignal()
{
	printf("Updated ------------signal\n");
	printf("The old signal name is:SIGINT\n");
}

