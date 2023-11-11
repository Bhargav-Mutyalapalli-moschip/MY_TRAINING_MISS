#include<stdio.h>
#include<signal.h>
#include<unistd.h>
void newsignal(int signo);
int main()
{
	int i=0;
	pid_t pid;
	struct sigaction var;
	var.sa_handler=newsignal;
	var.sa_flags=0;
	sigemptyset(&var.sa_mask);
	sigaddset(&var.sa_mask,2);
	sigaddset(&var.sa_mask,64);
	sigprocmask(SIG_BLOCK,&var.sa_mask,0);
	sigaction(2,&var,NULL);
	while(i<=50)
	{
		printf("The pid is:%d\n",getpid());
		sleep(1);
		printf("Here first while afer blocking\n");
		printf("%d\n",i);
		i++;
	}
	sigdelset(&var.sa_mask,64);
	sigprocmask(SIG_UNBLOCK,&var.sa_mask,0);
	i=0;
	while(i<=100)
	{
		printf("The pid is:%d\n",getpid());
		sleep(1);
		printf("Here first while before blocking\n");
		printf("%d\n",i);
		i++;
	}






}
void newsignal(int signo)
{
	printf("signo no is:%d is recieved\n",signo);
	printf("Replaced signal is continuing\n");
}
	
