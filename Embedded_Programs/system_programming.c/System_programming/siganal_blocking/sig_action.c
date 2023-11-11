#include<stdio.h>
#include<signal.h>
#include<unistd.h>
void mynewsignal(int signo);
int main()
{
	struct sigaction var;
	int i=0;
	sigset_t signalset;
	var.sa_handler=mynewsignal;
	var.sa_flags=0;
	sigemptyset(&var.sa_mask);
	sigaddset(&var.sa_mask,2);
	sigaddset(&var.sa_mask,64);
	sigprocmask(SIG_BLOCK,&var.sa_mask,NULL);
	sigaction(2,&var,NULL);
	while(i<=50)
	{
		sleep(1);
		printf("PId:%d\n",getpid());
		printf("The i:%d\n",i);
		i++;
	}
	sigdelset(&var.sa_mask,64);
	sigprocmask(SIG_UNBLOCK,&var,NULL);
	i=0;
	while(i<=50)
	{
		sleep(1);
		printf("PId:%d\n",getpid());
		printf("The i:%d\n",i);
		printf("Last\n");
		i++;
	}
}
void mynewsignal(int signo)
{
	printf("Signal  %d is recieved\n",signo);
	printf("\n\n\n\n\n\n\n\n\n\n\n");
	printf("Executing\n");
}





