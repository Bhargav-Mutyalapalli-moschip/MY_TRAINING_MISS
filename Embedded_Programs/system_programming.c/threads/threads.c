#include<stdio.h>
#include<stdio_ext.h>
#include<pthread.h>
pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
void *thread1(void *ptr1);
void *thread2(void *ptr1);
int glob;
int main()
{
	pthread_t t1,t2;
	char str[100];
	scanf("%[^\n]",str);
	__fpurge(stdin);
	pthread_create(&t1,NULL,thread1,str);
	pthread_create(&t2,NULL,thread2,str);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_cond_broadcast(&cond1);
	printf("Completed\n");
}
void *thread1(void *ptr1)
{
	char *ptr=ptr1;
	int i=0;
	pthread_mutex_lock(&lock);
	for(i=0;ptr[i]!='\0';i++)
	{
		if(ptr[i] == ' ')
			continue;
		if(ptr[i] >= 'a' && ptr[i] <= 'z')
		{
			printf("The small:%c\n",ptr[i]);
			pthread_cond_signal(&cond1);
		}
		else
		{
			printf("Thread 1 blocks\n");
			printf("The thread1:%c\n",ptr[i]);
			pthread_mutex_unlock(&lock);
			pthread_cond_signal(&cond1);
			pthread_cond_wait(&cond1,&lock);
			printf("Thread1 unblocks\n");
		}
	}
}
void *thread2(void *ptr1)
{
	char *ptr=ptr1;
	int i=0;
	pthread_mutex_lock(&lock);
	for(i=0;ptr[i]!='\0';i++)
	{
		if(ptr[i] == ' ')
			continue;
		if(ptr[i] >= 'A' && ptr[i] <= 'Z')
		{
			printf("The Large:%c\n",ptr[i]);
			pthread_cond_signal(&cond1);
		}
		else
		{
			printf("Thread 2 blocks\n");
			printf("The thread2:%c\n",ptr[i]);
			pthread_mutex_unlock(&lock);
			pthread_cond_signal(&cond1);
			pthread_cond_wait(&cond1,&lock);
			printf("Thread2 unblocks\n");
		}
	}
}
