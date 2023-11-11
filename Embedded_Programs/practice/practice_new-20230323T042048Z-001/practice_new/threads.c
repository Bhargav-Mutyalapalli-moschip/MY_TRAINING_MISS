#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
void *myown_thread(void *ptr);
int main()
{
	pthread_t t1,t2;
	int loop=100,ret;
	ret=pthread_create(&t1,0,myown_thread,&loop);
	if(ret < 0)
	{
		printf("Failed to create\n");
		exit(1);
	}
	printf("Main gets terminated\n");
	//pthread_exit(&ret);
	t2=pthread_self();
	printf("The thread id:%ld\n",t2);
	pthread_join(t1,NULL);

}
void *myown_thread(void *ptr)
{
	int i;
	for(i=0;i<=*((int *)ptr);i++)
	{
		printf("Thread executing\n");
		printf("Thread executing%d\n",i);
	}
}



