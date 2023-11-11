#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	char dev[100];
	int fd,ret;
	fd=open("/dev/pranav",O_RDWR);
	printf("Open fd:%d\n",fd);
	if(fd < 0)
	{
		printf("Failed to open\n");
		exit(1);
	}
	printf("Open is success\n");
	/*ret=write(fd,"The way he deserved things",strlen("The way he deserved things"));
	if(ret < 0)
	{
		printf("Failed to write\n");
		exit(1);
	}*/
	ret=read(fd,dev,sizeof(dev));
	if(ret < 0)
	{
		printf("Failed to read\n");
		exit(1);
	}
	write(1,dev,strlen(dev));
	close(fd);

}


