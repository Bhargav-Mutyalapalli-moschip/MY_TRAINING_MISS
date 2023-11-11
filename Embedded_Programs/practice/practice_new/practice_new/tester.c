#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
	int fd,fd1;
	fd=open("sample.txt",O_RDWR);
	close(1);
	dup(fd);
	printf("hello all how are you guys\n");

}
