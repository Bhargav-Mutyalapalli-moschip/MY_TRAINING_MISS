#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	char wbuf[100];
	int ret,fd;
	fd=open("serverfifo",O_WRONLY);
	write(fd,"Hello world",strlen("Hello world"));
	close(fd);
}




