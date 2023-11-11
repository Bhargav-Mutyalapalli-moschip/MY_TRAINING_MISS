#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
int glob = 0,loop=100,j=10,i=0;
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cnd = PTHREAD_COND_INITIALIZER;
void * mythread_fun1(void *);
void * mythread_fun2(void *);
int main()
{
        pthread_t ti1,ti2;
        int i,ret,ret1;
        void *res;
        ret=pthread_create(&ti1,0,mythread_fun1,&loop);
        ret1=pthread_create(&ti2,0,mythread_fun2,&loop);
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
        int local;
//      loop = *(int *)ptr;
        while(i<=loop)
        {
			pthread_mutex_lock(&mtx);
                if(i==j)
                {
        //              printf("th1 entry\n");
			j=j+10;
			printf("The j:value:%d\n",j);
			printf("The i:value:%d\n",i);
		pthread_cond_signal(&cnd);
                        pthread_cond_wait(&cnd,&mtx);
        //              printf("th1 left\n");
                }
                else
		{
                        printf("th1 : %d  : %ld \n",i++,pthread_self());
                //      printf("th1 : %d \n",i++);
			
		}
			pthread_mutex_unlock(&mtx);
        }
}
void* mythread_fun2(void *ptr)
{
        int local;
//      loop = *(int *)ptr;
        while(i<=loop)
        {
			pthread_mutex_lock(&mtx);
                if((i==j))
                {
                //      printf("th2 entry\n");
			j=j+10;
			printf("The j:value:%d\n",j);
			printf("The i:value:%d\n",i);
			//if()
		pthread_cond_signal(&cnd);
                        pthread_cond_wait(&cnd,&mtx);
                //      printf("th2 entry\n");
                }
                else
		{
			printf("\t\t\t\tth2 : %d  : %ld \n",i++,pthread_self());
			//printf("\tth2 : %d \n",i++);
			
		}
			pthread_mutex_unlock(&mtx);
        }
}


/*
syntax : timedwait : int pthread_cond_timedwait(pthread_cond_t *restrict cond,pthread_mutex_t *restrict mutex,const struct timespec *restrict abstime);
syntax : int pthread_cond_wait(pthread_cond_t *restrict cond,
pthread_mutex_t *restrict mutex);

*/
