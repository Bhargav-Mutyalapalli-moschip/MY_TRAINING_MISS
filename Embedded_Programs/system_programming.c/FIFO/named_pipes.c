#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
//int mknod(const char *pathname,mode_t mode,dev_t dev);
int main()
{
	int ret,var;
	ret=mknod("myfifo_named_pipe",0640,S_IFIFO);
	if(ret < 0)
	{
		printf("Failed to create named pipe\n");
		exit(1);
	}
	printf("The ret vale:%d\n",ret);
}




