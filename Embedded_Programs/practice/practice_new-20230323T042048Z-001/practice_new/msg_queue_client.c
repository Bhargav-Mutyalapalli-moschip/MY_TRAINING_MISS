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
	message.msg_type=MSG_TYPE;
	msgqid=msgget(KEY,0);
	strcpy(message.str,"BYE BYE TATA TATA");
        msgsnd(msgqid,&message,sizeof(message),0);


}

	


