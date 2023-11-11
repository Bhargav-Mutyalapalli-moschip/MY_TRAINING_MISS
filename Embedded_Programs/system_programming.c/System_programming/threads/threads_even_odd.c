#include<stdio.h>
#include<pthread.h>
#include<signal.h>
void *my_new_signal1(void *ptr);
void *my_new_signal2(void *ptr);
int main()
{
	pthread_t ti1,ti2;
	int ret1,var=10000,ret2;
	ret1=pthread_create(&ti1,0,my_new_signal1,&var);
	ret2=pthread_create(&ti2,0,my_new_signal2,&var);
	pthread_exit(NULL);
}
void *my_new_signal1(void *ptr)
{
	int i;
	printf(">>>>new signa --1 is invoked\n");
	for(i=0;i<=*(int *)ptr;i++)
	{
		if(i%2==0)
		{
			printf("The even:%d\n",i);
		}
	}
}
void *my_new_signal2(void *ptr)
{
	int i;
	printf(">>>>new signa --2 is invoked\n");
	for(i=0;i<=*(int *)ptr;i++)
	{
		if(i%2!=0)
		{
			printf("\t-----------------The odd:%d\n",i);
		}
	}
}





