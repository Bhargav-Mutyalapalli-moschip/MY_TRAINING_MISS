#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/mman.h>
int main()
{
	char *ptr;
#ifdef USE_MAP_ANON
	ptr=mmap(NULL,sizeof(int),PROT_READ | PROT_WRITE ,MAP_SHARED | MAP_ANONYMOUS,-1,0);

#else
	int fd =open("/dev/zero",O_RDWR);
	ptr=mmap(NULL,sizeof(int),PROT_READ | PROT_WRITE ,MAP_SHARED ,fd,0);
	close(fd);
	int pid=fork();
	if(pid > 0)
	{
		sleep(2);
		printf("The parent process:%c\n",*ptr);
		exit(1);
	}
	else
	{
		*ptr='p';
		printf("The child process:%c\n",*ptr);
		exit(1);
	}
#endif
}




