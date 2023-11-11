#include<stdio.h>
#include<unistd.h>
#include<sys/msg.h>
#include<sys/shm.h>
#include<string.h>
#define KEY 0x1998860
int main()
{
	int shmid,ret;
	char *ptr;
	shmid=shmget(KEY,512,0);
	ptr=shmat(shmid,NULL,0);
	while(1)
	{
		printf("client:-->\n");
		scanf("%[^\n]s",ptr);
		//strcpy(ptr,"hii");
		//shmdt(ptr);
		//ptr=shmat(shmid,NULL,0);
		sleep(3);
		ptr[0]='\0';
		while(ptr[0]=='\0');
		sleep(1);
		printf("%s\n",ptr);
		//t=shmdt(ptr);
	}
}

