#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	int fd1,fd2,ret;
	char buf[10];
	fd1=open("sample.txt",O_RDWR);
	if(fd1 < 0)
	{
		printf("1.Failed to open\n");
		exit(1);
	}
	fd2=open("sample.txt",O_RDWR);
	if(fd2 < 0)
	{
		printf("1.Failed to open\n");
		exit(1);
	}
	close(fd1);
	//close(fd2);
	ret=read(fd2,buf,9);
	if(ret < 0)
	{
		printf("failed to read\n");
		exit(1);
	}
	buf[ret]='\0';
	printf("The out:%s\n",buf);

}


