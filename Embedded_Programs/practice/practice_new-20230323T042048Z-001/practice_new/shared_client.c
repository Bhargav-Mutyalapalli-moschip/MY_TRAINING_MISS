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
	shmid=shmget(KEY,512,0);
	ptr=shmat(shmid,NULL,0);
	strcpy(ptr,"hello hii ela unnav");
	shmdt(ptr);
}



