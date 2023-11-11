#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<stdio_ext.h>
#include<fcntl.h>
#include<dirent.h>
struct time
{
	unsigned int day;
	unsigned int mon;
	unsigned int year;
	unsigned int hour;
	unsigned int min;
	unsigned int sec;
};
struct dob
{
	unsigned int date;
	unsigned int month;
	unsigned int year;
};
struct nominee
{
	char nom_name[50];
	unsigned long int mob_no;
	unsigned long int aadhar_no;
};
struct address
{
	char house_no[10];
	char area[20];
	char location[20];
	char district[20];
	char state[20];
	unsigned int pin_code;
};
struct register_data
{
	char name[200];
	char user_id[100];
	unsigned long int mob_no;
	unsigned long int aadhar_no;
	unsigned long int passwd;
	int balance;
	char gen[10];
	unsigned long int acc_no;
	struct dob d_o_b;
	struct nominee info;
	struct time dt;
	struct address details;
};
struct communicate
{
	int option;
	int balan;
	int status;
};
struct transaction
{
	int ind;
	char status[20];
	unsigned rem_balance;
};
int register_acc();
int directory_check(char *str);
int digit_count(unsigned long int mob,int fix);
void login_credition();
