#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
	printf("First argument should be cat\n");
	int fd;
	char *ptr;
	struct stat buf;
	fd=open(argv[1],O_RDWR);
	if(fd < 0)
	{
		printf("failed to open\n");
		exit(1);
	}
	fstat(fd,&buf);
	ptr=mmap(NULL,buf.st_size,PROT_READ | PROT_WRITE,MAP_SHARED,fd,0);
	write(1,ptr,buf.st_size);
	munmap(ptr,buf.st_size);
}

