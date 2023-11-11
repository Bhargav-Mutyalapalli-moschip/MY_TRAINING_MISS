#include<stdio.h>
#include<unistd.h>
int main()
{
	int a=10,b=20;
	a=a+b;
	printf("THe out:%d\n",a);
	char *argv[]={"ps","ps","-ef",NULL};
	execvp(argv[0],&argv[1]);
}

