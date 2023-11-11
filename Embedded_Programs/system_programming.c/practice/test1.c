#include<stdio.h>
#include<stdio_ext.h>
#include<string.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	char buff[100];
	int ret,fd;
	/*ret=mknod("fifo",0640,S_IFIFO);
	if(ret < 0)
	{
		printf("Failed to create the named pipe\n");
		exit(1);
	}*/
	char *fifo="/home/pranavix/Documents/pranav_documents/mywork/system_programming.c/practice/fifo";
	ret=mkfifo("fifo",0666);
	printf("The ret:%d\n",ret);
	if(ret < 0)
	{
		printf("Failed to create fifo\n");
		exit(1);
	}
	printf("The fifo return value:%d\n",ret);
	while(1)
	{
		printf("Enter the message\n");
		scanf("%s",buff);
		printf("Enter the message after\n");
		__fpurge(stdin);
		fd=open(fifo,O_WRONLY);
		if(fd < 0)
		{
			printf("failed to read\n");
			exit(1);
		}
		ret=write(fd,buff,strlen(buff));
		if(ret < 0)
		{
			printf("failed to write\n");
			exit(1);
		}
		close(fd);
		printf("mode on\n");
		fd=open(fifo,O_RDONLY);
		if(fd < 0)
		{
			printf("failed to open\n");
			exit(1);
		}
		ret=read(fd,buff,99);
		if(ret < 0)
		{
			printf("Failed to read\n");
			exit(1);
		}
		//buff[ret]='\0';
		printf("The message from 2nd person is:%s\n",buff);
		close(fd);
	}


}



