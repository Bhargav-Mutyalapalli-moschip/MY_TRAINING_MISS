#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int fd[2],pid,ret,var,i;
	var=pipe(fd);
	char buffer[100];
	if(var!=0)
	{
		printf("Failed to create pipe\n");
		exit(1);
        }
	pid=fork();
	if(pid < 0)
	{
		printf("Failed to create the child\n");
		exit(1);
	}
	else if(pid > 0)
	{
		printf("Parent invoked\n");
		close(fd[0]);
		ret=write(fd[1],"My name is Pranav",strlen("My name is Pranav"));
		if(ret < 0)
		{
			printf("Failed to write\n");
			exit(1);
		}
		close(fd[1]);
		printf("Parent terminated\n");
	}
	else
	{
		printf("Child is invoked\n");
		close(fd[1]);
	//	ret=read(fd[0],buffer,99);
		if(ret < 0)
		{
			printf("Failed to read\n");
			exit(0);
		}
	//	buffer[ret]='\0';
		for(i=0;buffer[i]!='\0';i++)
		{
			if(buffer[i] == ' ')
			continue;
			if(buffer[i] >='a' && buffer[i] <= 'z')
			buffer[i]=buffer[i]-32;
			else
			buffer[i]=buffer[i]+32;
		}

		printf("The output string is :%s\n",buffer);
		close(fd[0]);
		printf("Child terminated\n");
	}



}
