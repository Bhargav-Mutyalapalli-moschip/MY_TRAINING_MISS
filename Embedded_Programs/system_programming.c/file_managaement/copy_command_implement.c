#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main(int argc,char *argv[])
{
	char str[100];
	int i,l=0,fd1,ret1,ret2,fd2,var;
	for(i=0;argv[l][i]!='\0';i++)
	{
		if(argv[l][i]==' ')
		{
			argv[l][i]='\0';
			l++;
		}
	}
	for(i=1;i<argc;i++)
	printf("%s\n",argv[i]);
	fd1=open(argv[1],O_RDONLY);
	if(fd1 < 0)
	{
		printf("cp: cannot stat '%s': No such file or directory\n",argv[1]);
		exit(-1);
	}
	fd2=open(argv[2],O_RDWR);
	if(fd2 < 0)
	{
		var=creat(argv[2],0664);
	}
	while(ret1=read(fd1,str,99))
	{
		if(ret1 < 0)
		{
			printf("The read operation is not formed\n");
			exit(-1);
		}
		str[ret1]='\0';
		ret2=write(fd2,str,strlen(str));
		if(ret2 < 0)
		{
			printf("The write is not performed\n");
			exit(-1);
		}
	}


	
		




}


