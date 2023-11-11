//----------------------------project work------//
//-------Name :M.B.R.Pranav
//-------ID:  MISSES0423
//---------------------------------------
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdio_ext.h>
#include<signal.h>
#include<string.h>
#include<time.h>
#include<dirent.h>
#include<sys/stat.h>
#include "header.h"     //it is stored in our user header file--//
#define PORT 9821
   //-------------------fUNCTION dECLARATIONS---------//
void digit_count(unsigned long int num,int fix);
void directory_check(char *str);
void folder_creation();
struct register_data reg,swap_var;
struct communicate status;
struct transaction trans;
int proffd,transfd;
int main()
{
	time_t t=time(NULL);
	struct tm tym=*localtime(&t);   // for time
	char str[100];
	char buff[100];
	int ret,client_size;
	struct sockaddr_in server,client;
	mkdir("/home/pranavix/Desktop/Bankdatabase",0777);
	int sockfd,newsockfd;
	sockfd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if(sockfd < 0)
	{
		printf("Failed to create and open the file\n");
		exit(1);
	}
	memset(&server,0,sizeof(server));
	server.sin_family=AF_INET;
	server.sin_port=htons(PORT);
	server.sin_addr.s_addr=INADDR_ANY;
	ret=bind(sockfd,(struct sockaddr *)&server,sizeof(server));
	if(ret < 0)
	{
		printf("Failed to bind\n");
		exit(1);
	}
	printf("\t\t-----Server is UP---------\n");
	ret=listen(sockfd,5);
	if(ret < 0)
	{
		printf("Failed o listen\n");
		exit(1);
	}
        client_size=sizeof(client);
	newsockfd=accept(sockfd,(struct sockaddr *)&client,&client_size);
	if(newsockfd < 0)
	{
		printf("Failed to accept\n");
		exit(1);
	}
	printf("Client is connected\n");
	while(1)
	{
		ret=recv(newsockfd,&status,sizeof(status),0);
		if(ret < 0)
		{
			printf("Failed to receive\n");
			exit(1);
		}
		ret=recv(newsockfd,&reg,sizeof(reg),0);
		if(ret < 0)
		{
			printf("Failed to receive\n");
			exit(1);
		}
		if(status.stat == 1)
		{
			directory_check(reg.userid);
		}
		if(status.stat == 2)
		{
			digit_count(reg.passwd,8);
		}
		if(status.stat == 3)
		{
			digit_count(reg.mob_no,10);
		}
		if(status.stat == 4)
		{
			digit_count(reg.aadhar_no,12);
		}
		if(status.stat == 5)
		{
			digit_count(reg.info.nom_mob_no,10);
		}
		if(status.stat == 6)
		{
			digit_count(reg.info.nom_aadhar_no,12);
		}
		if(status.stat == 7)
		{
			folder_creation();
		}
		if(status.stat == 8)
		{
			directory_check(reg.userid);
		}
		if(status.stat == 9)
		{
			chdir("/home/pranavix/Desktop/Bankdatabase");
			chdir(reg.userid);
			proffd=open("profile.txt",O_RDONLY);
			read(proffd,&swap_var,sizeof(swap_var));
			if(reg.passwd == swap_var.passwd)
			status.opt=11;
			else
			status.opt=12;
			close(proffd);

		}
		if(status.stat == 10)
		{
			chdir("/home/pranavix/Desktop/Bankdatabase");
			chdir(reg.userid);
			proffd=open("profile.txt",O_RDWR);
			transfd=open("transact.txt",O_RDWR);
			read(proffd,&swap_var,sizeof(swap_var));
			printf("The old balance:%d\n",swap_var.balance);
			swap_var.balance=swap_var.balance+reg.balance;
			printf("The new balance:%d\n",swap_var.balance);
			strcpy(trans.amount_stat,"CREDITED");
			trans.index=trans.index+1;
			trans.rem_balance=swap_var.balance;
			trans.mod_time.day=tym.tm_mday;
			trans.mod_time.mon=tym.tm_mon+1;
			trans.mod_time.year=tym.tm_year+1900;
			trans.mod_time.hour=tym.tm_hour;
			trans.mod_time.min=tym.tm_min;
			trans.mod_time.sec=tym.tm_sec;
                        lseek(transfd,0,SEEK_END);
                        write(transfd,&trans,sizeof(trans));
			lseek(proffd,0,SEEK_SET);
			write(proffd,&swap_var,sizeof(swap_var));
			close(proffd);
			close(transfd);
			status.opt=13;
		}
		if(status.stat == 11)
		{
			chdir("/home/pranavix/Desktop/Bankdatabase");
			chdir(reg.userid);
			proffd=open("profile.txt",O_RDWR);
			transfd=open("transact.txt",O_RDWR);
			read(proffd,&swap_var,sizeof(swap_var));
			if(reg.balance > swap_var.balance)
			{
				status.opt=14;
				
			}
			else
			{
				printf("The old balance:%d\n",swap_var.balance);
				swap_var.balance=swap_var.balance-reg.balance;
				printf("The new balance:%d\n",swap_var.balance);
				strcpy(trans.amount_stat,"DEBITED");
				trans.index=trans.index+1;
				trans.rem_balance=swap_var.balance;
				trans.mod_time.day=tym.tm_mday;
				trans.mod_time.mon=tym.tm_mon+1;
				trans.mod_time.year=tym.tm_year+1900;
				trans.mod_time.hour=tym.tm_hour;
				trans.mod_time.min=tym.tm_min;
				trans.mod_time.sec=tym.tm_sec;
				lseek(transfd,0,SEEK_END);
				write(transfd,&trans,sizeof(trans));
				lseek(proffd,0,SEEK_SET);
				write(proffd,&swap_var,sizeof(swap_var));
				close(proffd);
				close(transfd);
				status.opt=15;
			}
		}
		if(status.stat == 12)
		{
			chdir("/home/pranavix/Desktop/Bankdatabase");
			chdir(reg.userid);
			proffd=open("profile.txt",O_RDWR);
			read(proffd,&swap_var,sizeof(swap_var));
			status.stat=swap_var.balance;
			lseek(proffd,0,SEEK_SET);
			write(proffd,&swap_var,sizeof(swap_var));
			close(proffd);
			status.opt=16;
		}
		if(status.stat == 13)
		{
			chdir("/home/pranavix/Desktop/Bankdatabase");
			chdir(reg.userid);
			proffd=open("profile.txt",O_RDONLY);
			read(proffd,&swap_var,sizeof(swap_var));
			close(proffd);
			status.opt=17;
		}
		if(status.stat == 14)
		{
			chdir("/home/pranavix/Desktop/Bankdatabase");
			chdir(reg.userid);
			transfd=open("transact.txt",O_RDWR);
			//read(transfd,&trans,sizeof(trans));
			while(ret=read(transfd,&trans,sizeof(trans)))
			{
				ret=send(newsockfd,&trans,sizeof(trans),0);
				if(ret < 0)
				{
					printf("Failed to receive\n");
					exit(1);
				}

			}
			if(ret == 0)
			{
				trans.index=20;
				ret=send(newsockfd,&trans,sizeof(trans),0);
			}
			printf("The index:%d\n",trans.index);
			printf("The amount status:%s\n",trans.amount_stat);
			printf("The remaining balance:%d\n",trans.rem_balance);
			close(transfd);
			status.opt =17;

		}
		if(status.stat != 14)
		{
			ret=send(newsockfd,&status,sizeof(status),0);
			if(ret < 0)
			{
				printf("Failed to receive\n");
				exit(1);
			}
		}
		if(status.stat == 13)
		{
			ret=send(newsockfd,&swap_var,sizeof(swap_var),0);
			if(ret < 0)
			{
				printf("Failed to receive\n");
				exit(1);
			}
		}




	}

}
//-------------------Directoy checking------
void directory_check(char *str)
{
	DIR *d;
	struct dirent *dir;
	d=opendir("/home/pranavix/Desktop/Bankdatabase");
	if(d)
	{
		while((dir=readdir(d))!=NULL)
		{
			if((strcmp(str,dir->d_name)==0))
			{
				printf("Found\n");
				status.opt=1;
				break;
			}
			else
			{
				printf("Not found\n");
				status.opt=2;
			}
		}
		closedir(d);
	}
}
//------------------------Digit count-------------
void digit_count(unsigned long int num,int fix)
{
	unsigned long int temp=num;
	int rem=0;
	while(temp!=0)
	{
		rem++;
		temp=temp/10;
	}
	if(fix == 8)
	{
		if(rem >= fix)
			status.opt=5;
		else
			status.opt=6;
	}
	else if(rem > fix || rem < fix)
		status.opt=3;
	else if(rem == fix)
		status.opt=4;
}
//-------------------Folder creation-----------//
void folder_creation()
{
	chdir("/home/pranavix/Desktop/Bankdatabase");
	mkdir(reg.userid,0777);
	chdir(reg.userid);
	proffd=open("profile.txt",O_CREAT | O_RDWR,0664);
	if(proffd < 0)
	{
		printf("Failed to open and create\n");
		exit(1);
	}
	write(proffd,&reg,sizeof(reg));
	transfd=open("transact.txt",O_CREAT | O_RDWR,0664);
	if(transfd < 0)
	{
		printf("Failed to open and create\n");
		exit(1);
	}
	status.opt=10;
}







