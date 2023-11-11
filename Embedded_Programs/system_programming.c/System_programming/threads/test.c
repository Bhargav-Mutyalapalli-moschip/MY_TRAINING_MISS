#include<stdio.h>
#include<pthread.h>
int main()
{
	int a=gettid();
	int b=getpid();
	printf("The :%d------%d\n",a,b);
}
