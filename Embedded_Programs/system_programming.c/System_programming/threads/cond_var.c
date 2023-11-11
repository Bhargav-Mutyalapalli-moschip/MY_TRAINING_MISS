#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
void *mythread1(void *ptr);
void *mythread2(void *ptr);
int var=0;
pthread_mutex_t count_mutex  = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  condition_var  = PTHREAD_COND_INITIALIZER;
int main()
{
	pthread_t thread1,thread2;
	int ret,loop=100;
	ret=pthread_create(&thread1,0,mythread1,&loop);
	ret=pthread_create(&thread2,0,mythread2,&loop);
	
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
}
void *mythread1(void *ptr)
{
	int i=0,num;
	num=*(int *)ptr;
	pthread_mutex_lock(&count_mutex);
	//pthread_cond_wait(&condition_var,&count_mutex);
	while(i<=num)
	{
		printf("The thread 1 is exec:%d\n",i);
		printf("The thread 1 is exec var:%d\n",var);
		i++;
		var++;
	}
	pthread_mutex_unlock(&count_mutex);
}
void *mythread2(void *ptr)
{
	int i=0,num;
	num=*(int *)ptr;
	pthread_mutex_lock(&count_mutex);
	//pthread_cond_signal(&condition_var);
	while(i<=num)
	{
		printf("The thread 2 is exec:%d\n",i);
		printf("The thread 2 is exec var:%d\n",var);
		i++;
		var++;
	}
	pthread_mutex_unlock(&count_mutex);
}



	

