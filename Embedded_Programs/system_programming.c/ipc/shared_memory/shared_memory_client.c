#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/shm.h>
#include<unistd.h>
#define KEY 0x11223344
int main()
{
	int shmid,ret;
	char *ptr;
	shmid=shmget(KEY,512,0);
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
	strcpy(ptr,"Hello");
	ptr=ptr+256;
	ptr[0]='\0';
        while(ptr[0]=='\0');
	write(1,ptr,strlen(ptr));
	shmdt(ptr);
}
	
	

