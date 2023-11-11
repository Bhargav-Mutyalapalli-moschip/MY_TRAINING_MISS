#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
int main()
{
	int fd;
	close(1);
	printf("The way\n");
	printf("you triggered\n");
	fd=open("surya.txt",O_RDWR);
	if(fd< 0)
	{
		printf("Failed to open\n");
		exit(1);
	}
	printf("Hello\n");
	printf("World thinking\n");
}



