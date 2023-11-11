#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int i=1;
	while(i)
	{
		printf("%d\n",i);
		printf("getpid:%d\n",getpid());
		sleep(1);
		i++;
	}
}


