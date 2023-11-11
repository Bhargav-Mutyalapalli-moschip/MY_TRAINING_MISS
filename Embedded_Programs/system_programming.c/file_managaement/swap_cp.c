#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdio_ext.h>
#include<fcntl.h>
#include<unistd.h>
int i=0;
int main(int argc,char *argv[])
{
	int i=0;
	char buff1[100],buff2[100];
	int fd1,fd2,ret1,ret2,size1,size2;
	fd1=open(argv[1],O_RDWR);
	if(fd1 < 0)
	{
		printf("First file is not exist\n");
		exit(1);
	}
	fd2=open(argv[2],O_RDWR);
	if(fd2 < 0)
	{
		printf("Second file is not exist\n");
		exit(1);
	}
	size1=lseek(fd1,0,SEEK_END);
	size2=lseek(fd2,0,SEEK_END);
	lseek(fd1,0,SEEK_SET);
	lseek(fd2,0,SEEK_SET);
	while((ret1=read(fd1,buff1,99))&&(ret2=read(fd2,buff2,99)))
	{
		if(ret1 < 0 || ret2 < 0)
		{
			printf("The read failed to perform\n");
			exit(1);
		}
		buff1[ret1]='\0';
		buff2[ret2]='\0';
		lseek(fd1,99*i,SEEK_SET);
		lseek(fd2,99*i,SEEK_SET);
		i++;
		ret1=write(fd1,buff2,strlen(buff2));
		if(ret1 < 0)
		{
			printf("Write failed\n");
		}
		ret2=write(fd2,buff1,strlen(buff1));
		if(ret1 < 0)
		{
			printf("Write failed\n");
		}
	}
	if(ret1==0)
	{
		while(ret2=read(fd2,buff2,99))
		{

			if(ret2 < 0)
			{
				printf("Failed to read\n");
				exit(1);
			}
			buff2[ret2]='\0';
			lseek(fd2,99*i,SEEK_SET);
			i++;
			ret2=write(fd1,buff2,strlen(buff2));
			if(ret1 < 0)
			{
				printf("Write failed\n");
			}

		}
		ftruncate(fd2,size1);


	}
	else
	{
		while(ret1=read(fd1,buff1,99))
		{
			if(ret1 < 0)
			{
				printf("Failed to read\n");
				exit(1);
			}
			buff1[ret1]='\0';
			lseek(fd1,99*i,SEEK_SET);
			i++;
			ret1=write(fd2,buff1,strlen(buff1));
			if(ret1 < 0)
			{
				printf("Write failed\n");
			}
		}
	//	ftruncate(fd1,size2);
	}



}







