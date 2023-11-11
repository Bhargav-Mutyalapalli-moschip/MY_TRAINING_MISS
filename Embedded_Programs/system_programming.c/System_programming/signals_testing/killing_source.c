#include<stdio.h>
#include<unistd.h>
#include<signal.h>
int main()
{
	int ret;
	pid_t pid;
	scanf("%d",&pid);
	ret=kill(pid,2);
	if(ret==0)
	printf("Kill is worked effectively\n");
	else
		printf("failed to perform the kill opertion\n");
}

