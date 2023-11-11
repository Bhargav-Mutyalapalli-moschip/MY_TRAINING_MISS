#include<stdio.h>
#include<dirent.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	DIR *d;
	struct dirent *dir;
	d=opendir(".");
	while((dir=readdir(d))!=NULL)
	{
		printf("%s\n",dir->d_name);
	}
}

