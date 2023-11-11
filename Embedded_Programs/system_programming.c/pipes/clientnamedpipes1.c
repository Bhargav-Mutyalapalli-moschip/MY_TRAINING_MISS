#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
int main()
{
	int fd,ret;
	char buf[1024];
	while(1)
	{
		if((fd=open("serverfifo",O_WRONLY))<0)
		{
			printf("failed to open file\n");
			exit(1);
		}
		printf("client:");
		scanf("%[^\n]",buf);
		__fpurge(stdin);
		if((ret=write(fd,buf,strlen(buf)))<0)
		{
			printf("failed to write\n");
			exit(1);
		}

		if((fd=open("clientfifo",O_RDONLY))<0)
		{
			if((ret=mkfifo("clientfifo",0777))<0)
			{
				printf("failed to create clientobject\n");
				exit(1);
			}
			if((fd=open("clientfifo",O_RDONLY))<0)
			{
				printf("failed to open file\n");
				exit(1);
			}
		}
		if((ret=read(fd,buf,sizeof(buf)))<0)
		{
			printf("failed to read\n");
			exit(1);
		}

		printf("server:%s\n",buf);
	}

}





