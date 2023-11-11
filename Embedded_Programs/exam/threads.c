#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
void *myown_thread1(void *ptr);
void *myown_thread2(void *ptr);
pthread_mutex_t mut=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond=PTHREAD_COND_INITIALIZER;
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
	ret=pthread_create(&t1,0,myown_thread2,&loop);
	if(ret < 0)
	{
		printf("Failed to create\n");
		exit(1);
	}
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	printf("Main gets terminated\n");
		printf("executing%d\n",glob);

}
void *myown_thread1(void *ptr)
{
	int i,local;
	for(i=0;i<=*((int *)ptr);i++)
	{
		printf("Thread1 executing\n");
		pthread_mutex_lock(&mut);
		local=glob;
		local++;
		glob=local;
		pthread_mutex_unlock(&mut);


	}
}
void *myown_thread2(void *ptr)
{
	int i,local;
	for(i=0;i<=*((int *)ptr);i++)
	{
		printf("Thread2 executing\n");
		pthread_mutex_lock(&mut);
		local=glob;
		local++;
		glob=local;
		pthread_mutex_unlock(&mut);
	}
}




