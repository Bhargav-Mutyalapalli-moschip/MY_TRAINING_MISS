#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	int fd,ret;
	char str[100];
	fd=open("sample.txt",O_RDWR | O_APPEND);
	if(fd <  0)
	{
		printf("Failed to open\n");
		exit(1);
	}
	printf("enter the info to write in the file\n");
	scanf("%[^\n]",str);
	ret=write(fd,str,strlen(str));
	if(ret < 0)
	{
		printf("Failed to write\n");
		exit(1);
	}
	lseek(fd,0,SEEK_SET);
	while(ret=read(fd,str,99))
	{
		str[ret]='\0';
		printf("%s",str);
	}
}


