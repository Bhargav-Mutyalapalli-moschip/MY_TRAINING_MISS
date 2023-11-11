#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	char str[100];
	int fd,ret;
	fd=open("test.txt",O_RDWR);
	if(fd < 0)
	{
		printf("Failed to open the file\n");
		exit(-1);
	}
	printf("The file descripter table index is:%d\n",fd);
	scanf("%[^\n]",str);
	//sleep(20);
	ret=write(fd,str,strlen(str));
	if(ret < 0)
	{
		printf("Failed to perform the write operation\n");
		exit(-1);
	}
	while(ret=read(fd,str,4))
	{
		if(ret < 0)
		{

			printf("Failed to perform read operation\n");
			exit(-1);
		}
		str[ret]='\0';
		printf("%s",str);
	}
	printf("The return value:%d\n",ret);




}

