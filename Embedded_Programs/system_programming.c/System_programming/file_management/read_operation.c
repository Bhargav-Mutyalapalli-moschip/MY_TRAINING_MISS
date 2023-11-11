#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
int main()
{
	char rbuf[20];
	char buff[100];
	int fd,ret;
	fd=open("check.txt",O_RDWR);
	if(fd < 0)
	{
		printf("Failed to open the file\n");
		exit(-1);
	}
	ret=read(fd,buff,99);
	if(ret < 0)
	{
		printf("Failed to perform the read operation\n");
		exit(-1);
	}
        scanf("%[^\n]",rbuf);
	ret=write(fd,rbuf,strlen(rbuf));
	sleep(20);
	if(ret < 0)
	{
		printf("Failed to write\n");
		exit(-1);
	}
	ret=read(fd,buff,99);
	if(ret < 0)
	{
		printf("Failed to perform the read operation\n");
		exit(-1);
	}
	printf("The out:%s\n",buff);

}

