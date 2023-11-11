#include<stdio.h>
struct time
{
	unsigned int day;
	unsigned int mon;
	unsigned int year;
	unsigned int hour;
	unsigned int min;
	unsigned int sec;
};
struct nominee
{
	char nom_name[100];
	unsigned long int nom_mob_no;
	unsigned long int nom_aadhar_no;
};
struct dob
{
	unsigned int day;
	unsigned int mon;
	unsigned int year;
};
struct address
{
	char hous_no[10];
	char area[20];
	char location[20];
	unsigned int pin;
	char district[20];
	char state[20];
};
struct register_data
{
	char username[100];
	char userid[20];
	char gen[10];
	unsigned long int passwd;
	unsigned long int mob_no;
	unsigned long int aadhar_no;
	int balance;
	unsigned long int acc_no;
	struct nominee info;
	struct dob date;
	struct time dt;
	struct address details;
};
struct communicate
{
	int opt;
	int stat;
};
struct transaction
{
	int index;
	char amount_stat[20];
	int rem_balance;
	struct time mod_time;
};
