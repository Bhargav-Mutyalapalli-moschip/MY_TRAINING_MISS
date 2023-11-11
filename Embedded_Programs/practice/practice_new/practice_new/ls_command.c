#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
int main()
{
	DIR *d;
	struct dirent *dir;
	d=opendir(".");
	while((dir=readdir(d))!=NULL)
	printf("%s\n",dir->d_name);
}

