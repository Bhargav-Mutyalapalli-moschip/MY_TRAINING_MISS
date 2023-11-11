#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include<pthread.h>
void *myown_thread1(void *ptr);
void *myown_thread2(void *ptr);
pthread_mutex_t mut=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond1=PTHREAD_COND_INITIALIZER;
pthread_cond_t cond2=PTHREAD_COND_INITIALIZER;
int glob=0,i;
int main()
{
	pthread_t t1,t2;
	int loop=100,ret;
	char buf[100];
	printf("enter the string:");
	scanf("%[^\n]",buf);
	__fpurge(stdin);
	ret=pthread_create(&t1,0,myown_thread1,buf);
	if(ret < 0)
	{
		printf("Failed to create\n");
		exit(1);
	}
	ret=pthread_create(&t1,0,myown_thread2,buf);
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
	int local;
	pthread_mutex_lock(&mut);
	for(i;((char *)ptr)[i]!='\0';)
	{
		printf("Thread1 executing%d\n",i);
		if((((char *)ptr)[i] >= 'a') && (((char *)ptr)[i] <= 'z'))
		{
			printf("%c\n",((char *)ptr)[i]);
			i++;
		}
		else
			pthread_cond_wait(&cond1,&mut);
		pthread_cond_signal(&cond2);


	}
	pthread_mutex_unlock(&mut);
}
void *myown_thread2(void *ptr)
{
	int local;
	pthread_mutex_lock(&mut);
	for(i;((char *)ptr)[i]!='\0';)
	{
		printf("Thread2 executing%d\n",i);
		if((((char *)ptr)[i] >= 'A') && (((char *)ptr)[i] <= 'Z'))
		{
			printf("%c\n",((char *)ptr)[i]);
			i++;
		}
		else
			pthread_cond_wait(&cond2,&mut);
		pthread_cond_signal(&cond1);
	}
	pthread_mutex_unlock(&mut);
}




