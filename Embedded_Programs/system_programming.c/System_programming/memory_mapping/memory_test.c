#include<stdio.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/mman.h>
int main()
{
	struct stat var;
	char *ptr;
	int fd;
	fd=open("test.txt",O_RDWR);
	if(fd < 0)
	{
		printf("Failed to read\n");
		exit(1);
	}
	fstat(fd,&var);
	ptr=mmap(NULL,var.st_size,PROT_READ | PROT_WRITE,MAP_SHARED,fd,0);
	if(ptr==NULL)
	{
		printf("Failed to map\n");
		exit(1);
	}
	write(1,ptr,var.st_size);
}



