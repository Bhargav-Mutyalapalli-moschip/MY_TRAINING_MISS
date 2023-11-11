#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
void *myown_thread1(void *ptr);
void *myown_thread2(void *ptr);
int glob=0;
int main()
{
	pthread_t t1,t2;
	int loop=100,ret;
	ret=pthread_create(&t1,0,myown_thread1,&loop);
	if(ret < 0)
	{
		printf("Failed to create\n");
		exit(1);
	}
	ret=pthread_create(&t2,0,myown_thread2,&loop);
	if(ret < 0)
	{
		printf("Failed to create\n");
		exit(1);
	}
	pthread_join(t1,NULL);
	pthread_join(t1,NULL);
	printf("Two threads is terminated\n");
	printf("Two threads is terminated:%d\n",glob);

}
void *myown_thread1(void *ptr)
{
	int i,local;
	for(i=0;i<=*((int *)ptr);i++)
	{
		local=glob;
		local++;
		glob=local;

		printf("Thread executing\n");
	}
}
void *myown_thread2(void *ptr)
{
	int i,local;
	for(i=0;i<=*((int *)ptr);i++)
	{
		local=glob;
		local++;
		glob=local;
		printf("Thread executing\n");
	}
}



