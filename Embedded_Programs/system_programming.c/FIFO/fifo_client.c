#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	char str[100];
	int fd;
	fd=open("myfifo_named_pipe",O_WRONLY);
	if(fd < 0)
	{
		printf("Failed to open\n");
		exit(1);
	}
	printf("Enter the string\n");
	scanf("%s",str);
}


