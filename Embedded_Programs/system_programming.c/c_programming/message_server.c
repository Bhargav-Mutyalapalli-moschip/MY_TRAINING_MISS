#include<stdio.h>
#include<string.h>
#include<mqueue.h>
int main()
{
	struct mq_attr var;
	int ret;
	ret=mq_open("server",O_CREAT | O_RDWR,0660,&var);
	printf("The ret:%d\n",ret);
	mq_send(


	
}

