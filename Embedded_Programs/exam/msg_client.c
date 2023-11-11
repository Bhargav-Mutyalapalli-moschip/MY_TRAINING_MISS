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
	char str[100];
	long int msg_type=MSG_TYPE;
	int msgqid;
	msgqid=msgget(KEY,0);
	((long int *)str)[0]=1;
	strcpy(str+(sizeof(long int)),"Man with golden heart");
        msgsnd(msgqid,str,(strlen(str)+sizeof(msg_type)+1),0);


}

	


