#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
char str[100];
int length,i;
int glob = 0,loop=100,i=0;
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cnd = PTHREAD_COND_INITIALIZER;
void * mythread_fun1(void *);
void * mythread_fun2(void *);
int main()
{
	pthread_t ti1,ti2;
	int i,ret,ret1;
	void *res;
	printf("enter the string : ");
	scanf("%s",str);
	length=strlen(str);
	ret=pthread_create(&ti1,0,mythread_fun1,NULL);
	ret1=pthread_create(&ti2,0,mythread_fun2,NULL);
	if(ret<0||ret1<0)
	{
		printf("failed to create the new thread \n ");
		exit(1);
	}
	pthread_join(ti1,NULL);
	printf("\n\nthread1 completd ");
	pthread_join(ti2,NULL);
	printf("glob : %d \n", glob);
}
void* mythread_fun1(void *ptr)
{
	while(i<length)
	{
		pthread_mutex_lock(&mtx);
		if(str[i]>='A'&&str[i]<='Z')
		{
			pthread_cond_wait(&cnd,&mtx);
		}
		else
		{
			printf("th1 : %c \n ",str[i]);
			i++;
		}
		pthread_mutex_unlock(&mtx);
	        pthread_cond_signal(&cnd);
	}
}
void* mythread_fun2(void *ptr)
{
	int local;
	while(i<length)
	{
		pthread_mutex_lock(&mtx);
		if(str[i]>='a'&&str[i]<='z')
		{
			pthread_cond_wait(&cnd,&mtx);
		}
		else
		{
			printf("\t\t\t\tth2 : %c\n",str[i]);
			i++;
		}
		pthread_mutex_unlock(&mtx);
		pthread_cond_signal(&cnd);
	}
}


/*
syntax : timedwait : int pthread_cond_timedwait(pthread_cond_t *restrict cond,pthread_mutex_t *restrict mutex,const struct timespec *restrict abstime);
syntax : int pthread_cond_wait(pthread_cond_t *restrict cond,
pthread_mutex_t *restrict mutex);

*/
