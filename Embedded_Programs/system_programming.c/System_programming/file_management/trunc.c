#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	int fd,ret;
	char buf[30];
	fd=open("sample.c",O_TRUNC|O_WRONLY);
	if(fd < 0)
	{
		printf("Failed to open the file\n");
		exit(-1);
	}
	ret=read(fd,buf,29);
	printf("The ret value for read:%d\n",ret);
	if(ret < 0)
	{
		printf("Failed to read\n");
		exit(-1);
	}
	buf[ret]='\0';
	printf("%s",buf);
}

