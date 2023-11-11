#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<stdio_ext.h>

int main()
{
	char wstr[30];
	char rstr[30];
	int ret,fd,ret1;
	while(1)
	{
		fd=open("server_fifo",O_WRONLY);
		if(fd < 0)
		{
			printf("Failed to open\n");
			exit(1);
		}
		printf("Enter the message to ask the server\n");
		scanf("%[^\n]",wstr);
		__fpurge(stdin);
		if(strcmp("end",wstr)==0)
		break;
		ret1=write(fd,wstr,strlen(wstr));
		if(ret1 < 0)
		{
			printf("Failed to perform write operation\n");
			exit(2);
		}
		fd=open("client_fifo",O_RDONLY);
		if(fd < 0)
		{
			ret=mkfifo("client_fifo",0660);
			if(ret < 0)
			{
				printf("Failed to create the fifo file\n");
				exit(1);
			}
			printf("In client\n");
			fd=open("client_fifo",O_RDONLY);
			if(fd < 0)
			{
				printf("Failed to open the special file(fifo)\n");
				exit(1);
			}

		}
		printf("Server message\n");
		ret=read(fd,rstr,29);
		if(ret < 0)
		{
			printf("failed to perform the read operation\n");
			exit(1);
		}
		ret1=write(1,rstr,ret);
		printf("\n");
		if(ret1 < 0)
		{
			printf("Failed to perform write operation\n");
			exit(1);
		}
		close(fd);
	}






}

