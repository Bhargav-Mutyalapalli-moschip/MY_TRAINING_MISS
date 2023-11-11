#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/shm.h>
#include<sys/sem.h>
#include<unistd.h>
#define KEY 0x11223344
int main()
{
	struct sembuf var;
	int shmid,ret,semid;
	char *ptr;
	shmid=shmget(KEY,512,0);
	if(shmid < 0)
	{
		printf("Failed to create shared memory\n");
		exit(1);
	}
	semid=semget(KEY,2,0);
        if(semid < 0)
        {
                printf("Failed to create semaphore\n");
                exit(1);
        }
	ptr=shmat(shmid,NULL,0);
	if(ptr==NULL)
	{
		printf("Failed the attach the shared memory\n");
		exit(1);
	}
	strcpy(ptr,"Hello");
	var.sem_num=0; //counter number
        var.sem_op=+1; //because is sem_op has negative value then semop acts as blocking call
        var.sem_flg=0;
	ret=semop(semid,&var,1); //acts as blocking call
        if(ret < 0)
        {
                printf("failed to work semop function\n");
                exit(1);
        }
	var.sem_num=1; //counter number
        var.sem_op=-1; //because is sem_op has negative value then semop acts as blocking call
        var.sem_flg=0;
	ret=semop(semid,&var,1); //acts as blocking call
        if(ret < 0)
        {
                printf("failed to work semop function\n");
                exit(1);
        }
	printf("From server:%s\n",ptr+256);
	shmdt(ptr);
}
	
	

