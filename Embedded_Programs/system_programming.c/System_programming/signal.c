#include<stdio.h>
#include<signal.h>
#include<unistd.h>
void ownfun();
int main()
{
	int i=0;
	signal(2,ownfun);
	printf("The pid:%d\n",getpid());
	while(i<1000)
	{
		sleep(1);
		printf("The outt:%d\n",i);
		printf("The o:%d\n",i);
		i++;
	}

	
}
void ownfun()
{
	printf("REplaced siganl\n");
	printf("-----The replaced signal is own function----\n");
}
