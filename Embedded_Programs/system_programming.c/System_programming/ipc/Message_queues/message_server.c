#include<stdio.h>
#include<stdlib.h>
#include<sys/msg.h>
#include<string.h>
#include<unistd.h>
#define KEY 0x11223344
int main()
{
	struct msqid_ds task;
	char array[100];
	int ret,var;
	ret=msgget(KEY,IPC_CREAT|0640);
	if(ret < 0)
	{
		printf("Failed to create the message queue\n");
		exit(1);
	}
	msgctl(ret,IPC_STAT,&task);
	printf("The Current number of bytes:%lu\n",task.msg_cbytes);
	printf("The number of messages in queue:%lu\n",task.msg_qnum);
	printf("The reuse junk:%lu\n",task.msg_qbytes);
	var = msgrcv(ret,array,100,1,0);
	if(var < 0)
	{
		printf("Failed to receive the message fromn the client\n");
	}
	printf("The msgtype is:%ld\n",((long int*)array)[0]);
	printf("The pid is:%ld\n",(((long int*)array)[1]));
	printf("The message:%s\n",(array+(2*sizeof(long int))));

	

}


	

