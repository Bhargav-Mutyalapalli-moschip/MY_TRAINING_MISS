#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int fd,ret;
	char buf[100];
	fd=open("/dev/pranav",O_RDWR);
	if(fd < 0)
	{
		printf("Fail\n");
		exit(1);
	}
	printf("Successfully communicated\n");
	ret=read(fd,buf,sizeof(buf));
	if(ret < 0)
	{
		printf("Failed to perform read operation\n");
		exit(1);
	}
	buf[ret]='\0';
        printf("The string:%s\n",buf);
	close(fd);



}
