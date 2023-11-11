#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/shm.h>
#define KEY 0x11223344
int main()
{
	int ret,shmid;
	char *ptr;
	shmid=shmget(KEY,512,IPC_CREAT|0660);
	ptr=shmat(shmid,NULL,0);
	sleep(10);
	printf("%s\n",ptr);
	shmdt(ptr);
}



