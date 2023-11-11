#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	char str[100],ptr[100];
	int fd1,ret1,fd2,ret2;
	fd1=open("test.txt",O_RDWR);
	if(fd1 < 0)
	{
		printf("Failed to open the file\n");
		exit(-1);
	}
	printf("The file descripter table index is:%d\n",fd1);
	scanf("%[^\n]",str);
	__fpurge(stdin);
	scanf("%[^\n]",ptr);
	//sleep(20);
	ret1=write(fd1,str,strlen(str));
	fd2=open("test.txt",O_RDWR);
	if(fd2 < 0)
	{
		printf("Failed to open the file\n");
		exit(-1);
	}
	ret2=write(fd2,ptr,strlen(ptr));
	if(ret2 < 0)
	{
		printf("Failed to perform the write operation\n");
		exit(-1);
	}
	printf("The fd 1: value is:old:%d\n",fd1);
	close(fd1);
	fd1=0;
	fd1=open("test.txt",O_RDWR);
	if(fd1 < 0)
	{
		printf("Failed to open the file\n");
		exit(-1);
	}
	printf("The fd 1: value is:new:%d\n",fd1);






}

