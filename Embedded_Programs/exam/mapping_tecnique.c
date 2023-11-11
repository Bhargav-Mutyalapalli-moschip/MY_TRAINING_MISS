#include<sys/mman.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
int main()
{
	struct stat buf;
	char *ptr;
	int fd;
	fd=open("sample.txt",O_RDWR);
	if(fd < 0)
	{
		printf("Failed to open\n");
		exit(1);
	}
	fstat(fd,&buf);
	ptr=mmap(NULL,buf.st_size,PROT_READ | PROT_WRITE,MAP_SHARED|MAP_PRIVATE,fd,0);
	write(1,ptr,buf.st_size);
	munmap(ptr,buf.st_size);
}



