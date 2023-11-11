#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdio_ext.h>
#include<stdlib.h>
void newsignal();
int main()
{
	signal(14,newsignal);
	//pause();
	printf("Process terminated\n");
	while(1);
}
void newsignal()
{
	printf("The new signal is executing\n");
	printf("SIGALRM-----------IS REPLACED----------PRINTEING THE REPLACED FUNCTION TASK\n");
	raise(19);
}
