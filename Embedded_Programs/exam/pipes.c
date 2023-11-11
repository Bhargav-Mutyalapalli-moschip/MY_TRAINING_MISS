#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
int main()
{
	//it is works only works for related processes
	int fd[2],ret;
	pid_t pid;
	char buff[100];
	ret=pipe(fd);
	printf("The %d\n",fd[0]);
	printf("The %d\n",fd[1]);
	pid=fork();
	if(pid < 0)
	{
		printf("Failed to create the child process\n");
		exit(1);
	}
	else if(pid > 0)
	{
		printf("In parent\n");
		close(fd[0]);
		write(fd[1],"hello all how are you",strlen("hello all how are you"));
		close(fd[1]);
	}
	else
	{
		printf("In child\n");
		close(fd[1]);
		read(fd[0],buff,sizeof(buff));
		write(1,buff,strlen(buff));
		close(fd[1]);
	}
}
