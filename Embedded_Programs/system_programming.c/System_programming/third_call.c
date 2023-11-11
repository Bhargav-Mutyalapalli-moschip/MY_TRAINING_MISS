#include<stdio.h>
#include<unistd.h>
int main()
{
	int a=10,b=25,c=0;
	c=a+b;
	printf("The exec family:%d\n",c);
	char *const argv[]={"ps","ps","-ef",NULL};
	execvp(argv[0], &argv[1]);
	
}

