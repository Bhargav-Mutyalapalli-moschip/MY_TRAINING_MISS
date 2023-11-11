#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/shm.h>
#include<sys/sem.h>
#include<unistd.h>
#define KEY 0x11223344
int main()
{
	int shmid,semid,ret;
	struct sembuf var; 
	char *ptr;
	shmid=shmget(KEY,512,IPC_CREAT | 0660);
	if(shmid < 0)
	{
		printf("Failed to create shared memory\n");
		exit(1);
	}
	semid=semget(KEY,2,IPC_CREAT | 0640);
	if(semid < 0)
	{
		printf("Failed to create semaphore\n");
		exit(1);
	}
	ret=semctl(semid,0,SETVAL,0);
	if(ret < 0)
	{
		printf("Failed to update in counter 0\n");
		exit(1);
	}

	ret=semctl(semid,1,SETVAL,0);
	if(ret < 0)
	{
		printf("Failed to update in counter 1\n");
		exit(1);
	}
	printf("the out:%d\n",ret);
	var.sem_num=0; //counter number
	var.sem_op=-1; //because is sem_op has negative value then semop acts as blocking call
	var.sem_flg=0;
	ret=semop(semid,&var,1); //acts as blocking call
	if(ret < 0)
	{
		printf("failed to work semop function\n");
		exit(1);
	}
	ptr=shmat(shmid,NULL,0);
	if(ptr==NULL)
	{
		printf("Failed the attach the shared memory\n");
		exit(1);
	}
	write(1,ptr,strlen(ptr));
	ptr=ptr+256;
	strcpy(ptr,"Hii client");
	var.sem_num=1; //counter number
	var.sem_op=+1; //because is sem_op has negative value then semop acts as blocking call
	var.sem_flg=0;
	ret=semop(semid,&var,1); //acts as blocking call
        if(ret < 0)
        {
                printf("failed to work semop function\n");
                exit(1);
        }
	
	shmdt(ptr);
}
	
	

