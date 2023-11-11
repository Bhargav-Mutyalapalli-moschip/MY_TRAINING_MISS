#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/shm.h>
#include<unistd.h>
#define KEY 0x11223344
int main()
{
	int shmid;
	char *ptr;
	shmid=shmget(KEY,512,IPC_CREAT | 0660);
	if(shmid < 0)
	{
		printf("Failed to create shared memory\n");
		exit(1);
	}
	ptr=shmat(shmid,NULL,0);
	if(ptr==NULL)
	{
		printf("Failed the attach the shared memory\n");
		exit(1);
	}
	ptr[0]='\0';
	while(ptr[0]=='\0');
	sleep(1);
	write(1,ptr,strlen(ptr));
	ptr=ptr+256;
	strcpy(ptr,"Hii client");
	sleep(1);
	shmdt(ptr);
}
	
	

