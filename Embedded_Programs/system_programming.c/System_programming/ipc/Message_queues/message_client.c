#include<stdio.h>
#include<stdlib.h>
#include<sys/msg.h>
#include<string.h>
#include<unistd.h>
#define KEY 0x11223344
int main()
{
	char array[100];
	int ret,var;
	ret=msgget(KEY,0);
	if(ret < 0)
	{
		printf("Failed to create the message queue\n");
		exit(1);
	}
	((long int*)array)[0]=1;
	((long int*)array)[1]=getpid();
	scanf("%[^\n]",array+(2*sizeof(long int)));
	printf("The msgtype is:%ld\n",((long int *)array)[0]);
	printf("The pid is:%ld\n",((long int*)array)[1]);
	printf("The message:%s\n",(array+(2*sizeof(long int))));
	var = msgsnd(ret,array,((2*sizeof(long int))+strlen(array)+1),0);
	if(var < 0)
	{
		printf("Failed to send the message fromn the client\n");
	}

}


	

