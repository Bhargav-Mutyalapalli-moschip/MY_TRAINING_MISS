#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include<sys/msg.h>
#include<string.h>
#include<unistd.h>
#define KEY 0x11223344
int main()
{
	struct msqid_ds var1;
	var1.msg_qbytes=10000;
	char array[1000];
	int ret,var;
	while(1)
	{
		ret=msgget(KEY,IPC_CREAT|0640);
		if(ret < 0)
		{
			printf("Failed to create the message queue\n");
			exit(1);
		}
		msgctl(ret,IPC_SET,&var1);
		var = msgrcv(ret,&array,1000,1,0);
		if(var < 0)
		{
			printf("Failed to receive the message fromn the client\n");
		}
		printf("The msgtype is:%ld\n",((long int*)array)[0]);
		printf("The pid is:%ld\n",(((long int*)array)[1]));
		printf("The message:%s\n",(array+(2*sizeof(long int))));
		ret=msgget(KEY,0);
		if(ret < 0)
		{
			printf("Failed to create the message queue\n");
			exit(1);
		}
		((long int*)array)[0]=1;
		((long int*)array)[1]=getpid();
		printf("Client---->:");
		scanf("%[^\n]",array+(2*sizeof(long int)));
		__fpurge(stdin);
		printf("The msgtype is:%ld\n",((long int *)array)[0]);
		printf("The pid is:%ld\n",((long int*)array)[1]);
		printf("The message:%s\n",(array+(2*sizeof(long int))));
		var = msgsnd(ret,&array,((2*sizeof(long int))+strlen(array)+1),0);
		if(var < 0)
		{
			printf("Failed to send the message fromn the client\n");
		}
	}


}




