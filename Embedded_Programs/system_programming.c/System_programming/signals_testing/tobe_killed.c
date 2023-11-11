#include<stdio.h>
#include<unistd.h>
int main()
{
	int i;
	while(i<200)
	{
		printf("%d\n",getpid());
		printf("%d\n",i);
		if(i==199)
			kill(getpid(),19);
		i++;
	}
	printf("Out\n");
	if(i==199)
	raise(18);
}
