#include<stdio.h>
#include<unistd.h>
int main(int argc,char *argv[])
{
	printf("Started\n");
	execvp(argv[1],&argv[1]);
}
