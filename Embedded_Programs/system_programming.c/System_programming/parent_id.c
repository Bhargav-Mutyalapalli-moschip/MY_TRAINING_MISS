#include<stdio.h>
#include<unistd.h>
int main()
{
	pid_t pid;
	pid=fork();
	if(pid < 0)
	{
		printf("Failed to create child using fork\n");
		exit(-1);
	}
	els

