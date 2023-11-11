#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/msg.h>
#define MSG_TYPE 1
#define KEY 0x11223344
int main()
{
	int msgqid;
	char str[100];
	msgqid=msgget(KEY,IPC_CREAT|0777);
	msgrcv(msgqid,str,sizeof(str),1,0);
	printf("The msg type:%ld\n",((long int *)str)[0]);
	printf("The msg type:%s\n",str+(sizeof(long int)));


}




