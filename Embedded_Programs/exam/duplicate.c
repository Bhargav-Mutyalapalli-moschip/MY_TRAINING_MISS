#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	int fd,fd1;
	fd=open("sample.txt",O_RDWR);
	fd1=dup(1);
	close(1);
	write(fd1,"Hello how are you",strlen("Hello how are you"));
}
	

