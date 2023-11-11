#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	int fd,ret;
	char buff[30];
	fd=open("test.c",O_WRONLY);
	if(fd < 0)
	{
		printf("Failed to open\n");
		exit(0);
	}
	ret=read(fd,buff,23);
	printf("%d\n",ret);
}


