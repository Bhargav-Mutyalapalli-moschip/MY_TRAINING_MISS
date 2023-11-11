#include<time.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<arpa/inet.h>
#include<dirent.h>
#include<sys/types.h>
struct dob
{
	int dat;
	int mnth;
	int year;
};
struct nomne
{
	char nom_name[256];
	unsigned long int mbl_nmb;
	unsigned long int nom_adhar;
};
struct addr
{
	char h_no[12];
	char area[20];
	char locn[30];
	char dsrt[30];
	char state[30];
};
struct profile
{
	char usr_name[100];
	char usr_id[9];
	char pass[16];
	char gen;
	unsigned long int bal;
	char adar_nmbr[13];
	char mob_nmbr[11];
	char acc_nmbr[16];
	struct dob db;
	struct tm *tim;
	struct nomne det;
	struct addr dt;
};
struct status
{
	int stat;
	int cas;
};
struct login
{
	char usr_id[9];
	char pass[16];
};



