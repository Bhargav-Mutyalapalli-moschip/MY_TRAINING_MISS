#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int fd[2],pid,ret,var,i,fd1[2],var1,stat;
	var=pipe(fd);
	var1=pipe(fd1);
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
		ret=write(fd[1],"my name is pranav",strlen("my name is pranav"));
		if(ret < 0)
		{
			printf("Failed to write\n");
			exit(1);
		}
		printf("Sleep is started in parent\n");
		//sleep(5);
		//wait(&stat);
		printf("Sleep is ennded in parent\n");
		close(fd[1]);
		close(fd1[1]);
		ret=read(fd1[0],buffer,99);
		if(ret < 0)
		{
			printf("Failed to read\n");
			exit(0);
		}
		buffer[ret]='\0';
		printf("The parent string:%s\n",buffer);
		close(fd1[0]);
		printf("Parent terminated\n");
	}
	else
	{
		printf("Child is invoked\n");
		close(fd[1]);
		ret=read(fd[0],buffer,99);
		if(ret < 0)
		{
			printf("Failed to read\n");
			exit(0);
		}
		buffer[ret]='\0';
		for(i=0;buffer[i]!='\0';i++)
		{
			if(buffer[i] == ' ')
				continue;
			if(buffer[i] >='a' && buffer[i] <= 'z')
				buffer[i]=buffer[i]-32;
			else
				buffer[i]=buffer[i]+32;
		}
		close(fd[0]);
		close(fd1[0]);
		ret=write(fd1[1],buffer,strlen(buffer));
		if(ret < 0)
		{
			printf("Failed to write\n");
			exit(1);
		}
		close(fd1[1]);
		printf("Child terminated\n");
	}
}

