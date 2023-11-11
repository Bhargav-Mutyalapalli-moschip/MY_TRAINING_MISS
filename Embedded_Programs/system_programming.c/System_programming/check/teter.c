#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<stdio_ext.h>
#include<fcntl.h>
#include<dirent.h>
#include<time.h>
#include <sys/ipc.h>
struct time
{
        unsigned int day;
        unsigned int mon;
        unsigned int year;
        unsigned int hour;
        unsigned int min;
        unsigned int sec;
};
struct register_data
{
	char name[200];
	char user_id[100];
	long int mob_no;
	long int aadhar_no;
	unsigned long int passwd;
	struct time dt;
};
int main()
{
	key_t num;
	struct register_data reg;
	printf("Enter keyword\n");
	scanf("%[^\n]",reg.user_id);
	__fpurge(stdin);
	num=ftok(reg.user_id,256);
	printf("The generated key:%ld\n",num);
}



