#include<sys/mman.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
int main()
{
	struct stat buf,buf2;
	char *ptr,*ptr2;
	int fd1,fd2;
	fd1=open("source.txt",O_RDWR);
	if(fd1 < 0)
	{
		printf("Failed to open\n");
		exit(1);
	}
	fstat(fd1,&buf);
	ptr=mmap(NULL,buf.st_size,PROT_READ | PROT_WRITE,MAP_SHARED|MAP_PRIVATE,fd1,0);
	fd2=open("dest.txt",O_RDWR|O_CREAT|O_TRUNC,0667);
	if(fd2 < 0)
	{
		printf("Failed to open\n");
		exit(1);
	}
	printf("came\n");
	fstat(fd2,&buf2);
	ptr2=mmap(NULL,buf2.st_size,PROT_READ | PROT_WRITE,MAP_SHARED|MAP_PRIVATE,fd2,0);
	printf("came\n");
	//memcpy(ptr2,ptr,buf.st_size);
	munmap(ptr,buf.st_size);
	munmap(ptr2,buf2.st_size);
}



