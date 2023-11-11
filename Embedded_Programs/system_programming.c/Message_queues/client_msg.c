#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/msg.h>
#define MSG_TYPE 1
#define KEY 0x11223344
struct msg
{
	long int msg_type;
	char str[100];
}message;
int main()
{
	int msgqid;
	msgqid=msgget(KEY,IPC_CREAT|0777);
	msgrcv(msgqid,&message,sizeof(message),1,0);
	printf("The msg type:%ld\n",message.msg_type);
	printf("The msg type:%s\n",message.str);


}




