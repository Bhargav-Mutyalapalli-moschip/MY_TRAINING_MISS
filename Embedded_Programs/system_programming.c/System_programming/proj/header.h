#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<stdio_ext.h>
#include<fcntl.h>
#include<dirent.h>
    // Structure for time
struct time
{
	unsigned int day;
	unsigned int mon;
	unsigned int year;
	unsigned int hour;
	unsigned int min;
	unsigned int sec;
};
    // Structure for register the data
struct register_data
{
	char name[200];
	char user_id[100];
	long int mob_no;
	long int aadhar_no;
	unsigned long int passwd;

	struct time dt;
};
