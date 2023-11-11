#include<stdio.h>
#include<pthread.h>
void *my_new_thread1(void *ptr);
void *my_new_thread2(void *ptr);
int global=0;
pthread_mutex_t mute=PTHREAD_MUTEX_INITIALIZER;
int main()
{
	pthread_t t1,t2;
	int var=10000;
	pthread_create(&t1,0,my_new_thread1,&var);
	pthread_create(&t2,0,my_new_thread2,&var);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	printf("The global:%d\n",global);
}
void *my_new_thread1(void *ptr)
{
	int i,local,loop;
	loop=*(int *)ptr;
	for(i=0;i<loop;i++)
	{
		pthread_mutex_lock(&mute);
		local=global;
		local++;
		global=local;
		pthread_mutex_unlock(&mute);
	}
}
void *my_new_thread2(void *ptr)
{
	int i,local,loop;
	loop=*(int *)ptr;
	for(i=0;i<loop;i++)
	{
		pthread_mutex_lock(&mute);
		local=global;
		local++;
		global=local;
		pthread_mutex_unlock(&mute);
	}
}








