#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	char str[100];
	int fd,ret,fd1,ret1;
	fd=open("sample.txt",O_RDWR);
	if(fd < 0)
	{
		printf("Failed to open the file\n");
		exit(-1);
	}
	printf("The file descripter table index is:%d\n",fd);
	scanf("%[^\n]",str);
	ret=write(fd,str,strlen(str));
	printf("Another open\n");
	fd1=open("sample.txt",O_RDWR);
	if(fd1 < 0)
	{
		printf("Failed to open the file\n");
		exit(-1);
	}
	printf("The file descripter table index is:%d\n",fd1);
	__fpurge(stdin);
	scanf("%[^\n]",str);
	ret=write(fd1,str,strlen(str));




}

