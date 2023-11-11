#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
struct node
{
	char name[20];
};
int main()
{
	struct node link;
	int fd;
	strcpy(link.name,"123");
	fd=open(link.name,O_CREAT | O_TRUNC|O_RDWR,0664);
	write(fd,"hello",strlen("hello"));
}


