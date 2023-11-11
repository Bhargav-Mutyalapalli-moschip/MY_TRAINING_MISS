#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
	int fd,fd1;
	fd=open("sample.txt",O_RDWR);
	if(fd < 0)
	{
		printf("Failed to open the file and its creation\n");
		exit(1);
	}
	fd1=dup2(fd,1);
	printf("The modified fd:%d\n",fd);
	if(fd < 0)
	{
		printf("Failed to duplicate\n");
		exit(1);
	}
	printf("My name is ram i am from ap\n");
}


