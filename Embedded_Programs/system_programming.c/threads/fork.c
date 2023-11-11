#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	close(0);
	int pid,k;
	pid=vfork();
	if(pid > 0)
	{
		printf("The//\n");
		exit(0);
	//	wait(&k);
	}
	else
	{
		int a;
		scanf("%d",&a);
		printf("The out:%d\n",a);
	
	}
}

