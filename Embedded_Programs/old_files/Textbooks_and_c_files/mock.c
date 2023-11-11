#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<stdio_ext.h>
#include<fcntl.h>
#include<dirent.h>
#include<time.h>
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
	time_t t=time(NULL);
	struct tm var=*localtime(&t);
	struct register_data reg;
	int fd=open("417",O_RDWR);
	read(fd,&reg,sizeof(reg));


	printf("The name:%s\n",reg.name);
	printf("The user id:%s\n",reg.user_id);
	printf("The out:%ld\n",reg.mob_no);
	printf("The aadhar:%ld\n",reg.aadhar_no);
	printf("The day:%d--The mon:%d--The year%d---The hour:%d--The min:%d---The sec:%d\n",reg.dt.day,reg.dt.mon,reg.dt.year,reg.dt.hour,reg.dt.min,reg.dt.sec);

}
