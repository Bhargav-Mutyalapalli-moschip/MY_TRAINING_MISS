#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/shm.h>
#define KEY 0x1998860
int main()
{
	char *ptr;
	int shmid,ret;
	shmid=shmget(KEY,512,IPC_CREAT|0660);
	ptr=shmat(shmid,NULL,0);
	while(1)
	{
		ptr[0]='\0';
		while(ptr[0]=='\0');
		sleep(1);
		printf("%s\n",ptr);
		//	ret=shmdt(ptr);
		//ptr=shmat(shmid,NULL,0);
		sleep(3);
		scanf("%[^\n]s",ptr);
		//strcpy(ptr,"hello");
		sleep(20);
		//shmdt(ptr);
	}
}
