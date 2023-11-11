#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	char buf1[100];
	char buf2[100];
	int fd1,fd2,ret1,ret2;
	fd1=open("sample.txt",O_RDWR);
	if(fd1 < 0)
	{
		printf("cp: cannot stat '%s': No such file or directory\n","sample.txt");
		exit(1);
	}
	fd2=open("sample1.txt",O_RDWR|O_CREAT,0777);
	if(fd2 < 0)
	{
		printf("Failed to open 2\n");
		exit(-1);
	}
	while((ret1=read(fd1,buf1,99))||(ret2=read(fd2,buf2,99)))
	{
		if((ret1 < 0)&&(ret2 < 0))
		{
			printf("Failed to read\n");
			exit(1);
		}
		buf1[ret1]='\0';
		buf2[ret2]='\0';
		ret2=write(fd2,buf2,strlen(buf2));
		if(ret1 < 0)
		{
			printf("Failed to write\n");
			exit(1);
		}
		ret2=write(fd1,buf1,strlen(buf1));
		if(ret2 < 0)
		{
			printf("Failed to write\n");
			exit(1);
		}
	}
}

		
		









