#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sched.h>
#define _GNU_SOURCE
int main()
{
	pid_t pid;
	pid=clone();
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
void child_func(void *ptr)
{
	char *arg=(char *)


