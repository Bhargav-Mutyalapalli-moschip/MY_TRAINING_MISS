#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	char str[10];
	int fd,fd1,fd2,ret,ret1,ret2;
	fd=open("sample.txt",O_RDONLY);
	if(fd < 0)
	{
		printf("failed to open\n");
		exit(1);
	}
	fd2=open("cat_command.c",O_RDONLY);
	if(fd < 0)
	{
		printf("failed to open\n");
		exit(1);
	}	
	fd1=dup2(fd,fd2);
	if(fd1 < 0)
	{
		printf("The failed\n");
		exit(1);
	}
	printf("FD:%d------FD1:%d------FD2:%d\n",fd,fd1,fd2);
	ret=read(fd2,str,9);
	str[ret]='\0';
	printf("%s",str);
	printf("FD:%d------FD1:%d------FD2:%d\n",fd,fd1,fd2);
}

