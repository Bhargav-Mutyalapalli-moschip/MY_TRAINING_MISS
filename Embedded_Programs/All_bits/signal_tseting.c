#include<stdio.h>
#include<signal.h>
#include<string.h>
void my_handler(int sig_no);
int main()
{
	int ret,i=0;
	signal(2,my_handler);
	while(i<=100)
	{
		printf("\tPID:%d\n",getpid());
		sleep(1);
		i++;
	}
}
void my_handler(int sig_no)
{
	printf("The signal number :%d\n",sig_no);
	printf("My handler function is invoked\n");
}

