#include<stdio.h>
int main()
{
	int n=0,ret;
	while(n<=100000000)
	{
		ret=alarm(5);
		printf("The rturn value from alarm:%d\n",ret);
		sleep(4);
		n++;
	}
}


