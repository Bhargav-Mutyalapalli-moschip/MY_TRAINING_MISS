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
	char *buf1,*buf2;
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
	printf("The size:%d\n",size1);
	printf("The size:%d\n",size2);
	buf1=(char *)malloc(size1*sizeof(char));
	buf2=(char *)malloc(size2*sizeof(char));
	ret1=read(fd1,buf1,size1);
	if(ret1 < 0)
	{
		printf("Failed to read\n");
		exit(1);
	}
	ret2=read(fd2,buf2,size2);
	if(ret2 < 0)
	{
		printf("Failed to read\n");
		exit(1);
	}
	buf1[ret1]='\0';
	buf2[ret2]='\0';
	close(fd1);
	close(fd2);
	fd1=open(argv[1],O_RDWR|O_TRUNC);
	fd2=open(argv[2],O_RDWR|O_TRUNC);
	ret2=write(fd1,buf2,strlen(buf2));
	if(ret1 < 0)
	{
		printf("The write is failed\n");
		exit(1);
	}
	ret2=write(fd2,buf1,strlen(buf1));
	if(ret2 < 0)
	{
		printf("The write is failed\n");
		exit(1);
	}

}
