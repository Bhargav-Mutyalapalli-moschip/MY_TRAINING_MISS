#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
struct node
{
	char name[200];
	char user_id[100];
	long int mob_no;
	long int aadhar_no;
};
int main()
{
	char ptr[100];
	int fd;
	struct node link;
	fd=open("258",O_RDWR);
	read(fd,&link,sizeof(link));
	printf("The name:%s\n",link.name);
	printf("The user id:%s\n",link.user_id);
	printf("The out:%ld\n",link.mob_no);
	printf("The aadhar:%ld\n",link.aadhar_no);
	sleep(100);
	/*printf("The name:%s\n",((char *)ptr)[0]);
	printf("The user name:%s\n",((char *)ptr)[1]);
	printf("The out:%ld\n",((long int *)ptr)[2]);
	printf("The aadhar:%ld\n",((long int *)ptr)[3]);*/
}

