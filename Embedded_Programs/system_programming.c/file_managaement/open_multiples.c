#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	int fd1,fd2,ret1,ret2;
	fd1=open("sample.txt",O_RDWR);
	if(fd1 < 0)
	{
		printf("Failed to read 1\n");
		exit(1);
	}
	printf("First fd1:%d\n",fd1);
	close(fd1);
	fd2=open("sample.txt",O_RDWR);
	if(fd2 < 0)
	{
		printf("Failed to read 2\n");
		exit(1);
	}
	printf("Second fd2:%d\n",fd2);
	ret2=open("sample.txt",O_RDWR);
	if(fd2 < 0)
	{
		printf("Failed to read 2\n");
		exit(1);
	}
	printf("third fd3:%d\n",ret2);
}



