#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>
#include<wait.h>
int main()
{
	int i=0,var=0;
	pid_t pid,cpid=25;
	pid=fork();
	if(pid < 0)
	{
		printf("Faile to create the child process\n");
		exit(-1);
	}
	else if(pid > 0)
	{
		printf("Child process:%d\n",pid);
		sleep(5);
		printf("Child process:%d\n",pid);
		cpid=waitpid(pid,&var,WNOHANG);
		printf("Child terminated id:%d\n",cpid);
	//	if(WIFCONTINUED(var))
	//

	/*	if(WIFEXITED(var))
		printf("normal termiation id:%d\n",WEXITSTATUS(var));*/
	/*	if(WIFSIGNALED(var))
		printf("ABnormal termination :%d\n",WCOREDUMP(var));*/
	/*	if(WIFSTOPPED(var))
		printf("STOPPED :%d\n",WSTOPSIG(var));*/
		


	}
	else
	{
		/*while(i<55)
		{
			i++;
			//if(i==5)
			//raise(19);
			printf("Child process:%d\n",getpid());
		}*/
		printf("parent process:%d\n",getppid());
		raise(2);
		printf("Child process:%d\n",pid);
		//exit(30);
		//raise(19);
	}
}


	



