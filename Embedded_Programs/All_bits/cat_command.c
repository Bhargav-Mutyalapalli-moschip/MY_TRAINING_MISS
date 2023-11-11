#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc,char *argv[])
{
	printf("The in:%s\n",argv[0]);
	if((strcmp(argv[0],"./cat")==0))
	{
		int fd,ret;
		char str[100];
		fd=open(argv[1],O_RDWR);
		if(fd <  0)
		{
			printf("Failed to open\n");
			exit(1);
		}
		while(ret=read(fd,str,99))
		{
			str[ret]='\0';
			printf("%s",str);
		}
	}
	else
	printf("No such file in directory\n");

}

