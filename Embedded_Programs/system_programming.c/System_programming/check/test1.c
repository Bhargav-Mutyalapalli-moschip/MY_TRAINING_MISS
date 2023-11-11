#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
struct details
{
	int a;
	char c;
	float d;
};
int main()
{

	int fd;
	struct details var;
	fd=open("normal.txt",O_RDONLY);
	read(fd,&var,sizeof(var));
	printf("The out:%d\n",var.a);
	printf("The out:%c\n",var.c);
	printf("The out:%f\n",var.d);
}
	
