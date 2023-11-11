#include<stdio.h>
//#include<pthread.h>
#include<signal.h>
#include<unistd.h>
void *mythread(void *ptr);
int main()
{
	pthread_t ti;
	int var=20000,ret;
	ret=pthread_create(&ti,0,mythread,&var);
	//pthread_exit(&ret);
sleep(5);
	printf("Main gets terminated\n");
	exit(0);


}
void *mythread(void *ptr)
{
	printf("My thread is invoked\n");
	int i;
	for(i=0;i<=*(int *)ptr;i++)
	{
		sleep(5);
		printf("The out:%d\n",i);
	}
	printf("New thread completed execution\n");
	//exit(0);

}

