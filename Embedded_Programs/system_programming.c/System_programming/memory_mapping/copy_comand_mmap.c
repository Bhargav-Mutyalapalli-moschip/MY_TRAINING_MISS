#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/mman.h>
int main()
{
	struct stat var;
	char *ptr,*str;
	int fd,fd1,ret;
	fd=open("test.txt",O_RDONLY);
	if(fd < 0)
	{
		printf("Failed to read\n");
		exit(1);
	}
	fstat(fd,&var);
	ptr=mmap(NULL,var.st_size,PROT_READ, MAP_SHARED,fd,0);
	if(ptr==NULL)
	{
		printf("Failed to map\n");
		exit(1);
	}
	fd1=open("core1.txt",O_WRONLY | O_CREAT,0664);
	if(fd1 < 0)
	{
		printf("Failed to open file 2\n");
		exit(1);
	}
	ret=ftruncate(fd1,var.st_size);
	if(ret < 0)
	{
		printf("Failed to truncate\n");
		exit(1);
	}
	str=mmap(NULL,var.st_size,PROT_READ | PROT_WRITE, MAP_SHARED,fd1,0);
	str=memcpy(str,ptr,var.st_size);
	
}



