#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	char rbuf[100];
	int ret,fd;
	fd=open("serverfifo",O_RDONLY);
	if(fd < 0)
	{
		ret=mkfifo("serverfifo",0667);
		if(ret < 0)
		{
			printf("Failed to create the special file\n");
			exit(1);
		}
		fd=open("serverfifo",O_RDONLY);
		if(fd < 0)
		{
			printf("Failed to open\n");
			exit(1);
		}
	}
	read(fd,rbuf,sizeof(rbuf));
	write(1,rbuf,strlen(rbuf));
	close(fd);
}




