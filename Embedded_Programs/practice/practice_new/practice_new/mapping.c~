#include<stdio.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	int fd1,fd2;
	char *ptr1,*ptr2;
	int ret;
	struct stat var;
	fd1=open("sample.txt",O_RDONLY);
	if(fd1 < 0)
	{
		printf("Failed to open1\n");
		exit(1);
	}
	ret=fstat(fd1,&var);
	if(ret < 0)
	{
		printf("Failed to know the statics\n");
		exit(1);
	}
	ptr1=mmap(NULL,var.st_size,PROT_READ,MAP_PRIVATE,fd1,0);
	if(ptr1 == NULL)
	{
		printf("FAiled to map\n");
		exit(1);
	}
	fd2=open("dest.txt",O_RDWR|O_CREAT,0777);
	if(fd2 < 0)
	{
		printf("Failed to open2\n");
		exit(1);
	}
	ret=ftruncate(fd2,var.st_size);
	if(ret < 0)
	{
		printf("Failed to ftruncate\n");
		exit(1);
	}
	ptr2=mmap(NULL,var.st_size,PROT_WRITE|PROT_READ,MAP_SHARED,fd2,0);
	if(ptr2 == NULL)
	{
		printf("FAiled to map\n");
		exit(1);
	}
	memcpy(ptr2,ptr1,var.st_size);	
	close(fd1);
	close(fd2);
	munmap(ptr1,var.st_size);
	munmap(ptr2,var.st_size);
}

