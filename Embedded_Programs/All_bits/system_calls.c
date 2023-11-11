#include<stdio.h>
#include<unistd.h>
#include<signal.h>
int main()
{
	int i=0;
	while(1)
	{
		printf("pranav%d\n",++i);
		alarm(2);
	}
}

