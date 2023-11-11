#include<stdio.h>
#include<signal.h>
int main()
{
	int i=0;
	unsigned long int signalset;
        printf("Size of:%ld\n",sizeof(signalset));
	printf("The present pid:%d\n",getpid());
	sigemptyset(&signalset);
	printf("After empty:%llx\n",signalset);
	sigaddset(&signalset,2);
	sigaddset(&signalset,64);
	printf("The signalset:%lx\n",signalset);
	sigprocmask(SIG_BLOCK,&signalset,NULL);
	while(i<10)
	{
		sleep(2);
		printf("Print");
		printf("Looper\n");
		i++;
	}
	i=0;
	sigdelset(&signalset,64);
	sigprocmask(SIG_UNBLOCK,&signalset,NULL);
	while(i<10)
	{
		sleep(2);
		printf("Print");
		printf("Looper\n");
		i++;
	}

}









