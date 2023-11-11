#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<arpa/inet.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include "header.h"
#define PORTER 9989
int count=0;
char *ptr;
struct communicate stater;
int main()
{
	time_t t=time(NULL);
	struct tm mod_time=*localtime(&t);
	int fd,fd1,profilefd,transfd,wret;
	struct transaction trans;
	struct register_data server_data,check;
	struct sockaddr_in server,client;
	int socketfd,newsocketfd,ret,bret,client_size,opt=1;
	char buf[100];
	socketfd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if(socketfd < 0)
	{
		printf("Failed to create and open the socket\n");
		exit(1);
	}
	mkdir("/home/pranavix/Desktop/Bankdatabase",0700);
	memset(&server,0,sizeof(server));
	server.sin_family=AF_INET;
	server.sin_port=htons(PORTER);
	server.sin_addr.s_addr=INADDR_ANY;
	//setsockopt(ret, SOL_SOCKET,SO_REUSEADDR | SO_REUSEPORT, &opt,sizeof(opt));
	ret=bind(socketfd,(struct sockaddr *)&server,sizeof(server));
	if(ret < 0)
	{
		printf("Failed to bind\n");
		exit(1);
	}
	printf("The socketfd:%d-----The ret of bind:%d\n",socketfd,ret);
	ret=listen(socketfd,5);
	if(ret < 0)
	{
		printf("Failed to listen\n");
		exit(1);
	}
	printf("The socketfd:%d-----The ret of listen:%d\n",socketfd,ret);
	client_size=sizeof(struct sockaddr);
	newsocketfd=accept(socketfd,(struct sockaddr *)&client,&client_size);
	if(newsocketfd < 0)
	{
		printf("Failed to accept\n");
		exit(1);
	}

	while(1)
	{
		printf("Client is connected\n");
		//user id checking
		ret=recv(newsocketfd,&server_data,sizeof(server_data),0);
		if(ret < 0)
		{
			printf("Failed to receive\n");
			exit(1);
		}
		ret=recv(newsocketfd,&stater,sizeof(stater),0);
		if(ret < 0)
		{
			printf("Failed to receive\n");
			exit(1);
		}
		if(stater.status == 1)
		{
			directory_check(server_data.user_id);
			printf("Direct\n");
		}
		if(stater.status == 2)
		{
			digit_count(server_data.mob_no,10);
			printf("Mobilr\n");
		}
		if(stater.status == 3)
		{
			digit_count(server_data.aadhar_no,12);
			printf("addhar\n");
		}
		if(stater.status == 4)
		{
			digit_count(server_data.passwd,8);
			printf("password\n");
		}
		if(stater.status == 5)
		{
			chdir("/home/pranavix/Desktop/Bankdatabase");
			mkdir(server_data.user_id,0700);
			chdir(server_data.user_id);
			fd=open("profile.txt",O_CREAT | O_RDWR,0664);
			fd1=open("transact.txt",O_CREAT | O_RDWR,0664);
			write(fd,&server_data,sizeof(server_data));
			close(fd);
			close(fd1);

		}
		if(stater.status == 6)
		{
			chdir("/home/pranavix/Desktop/Bankdatabase");
			chdir(server_data.user_id);
			fd=open("profile.txt",O_RDONLY);
			read(fd,&check,sizeof(check));
			if(check.passwd == server_data.passwd)
				stater.option = 10;
			else
				stater.option =9;
			close(fd);
		}
		if(stater.status == 7)
		{
			chdir("/home/pranavix/Desktop/Bankdatabase");
			chdir(server_data.user_id);
			profilefd=open("profile.txt",O_RDWR);
			transfd=open("transact.txt",O_RDWR);
			read(fd,&check,sizeof(check));
			printf("The old balance:%d\n",check.balance);
			check.balance=check.balance+server_data.balance;
			strcpy(trans.status,"CREDITED");
			trans.ind=trans.ind+1;
			trans.rem_balance=check.balance;
			trans.var.day=mod_time.tm_mday;
			trans.var.mon=mod_time.tm_mon+1;
			trans.var.year=mod_time.tm_year+1900;
			trans.var.hour=mod_time.tm_hour;
			trans.var.min=mod_time.tm_min;
			trans.var.sec=mod_time.tm_sec;
			lseek(transfd,0,SEEK_END);
			write(transfd,&trans,sizeof(transfd));
			printf("The new balance:%d\n",check.balance);
			lseek(fd,0,SEEK_SET);
			write(fd,&check,sizeof(check));
			close(profilefd);
			close(transfd);
			stater.option=11;
		}
		if(stater.status == 8)
		{

			chdir("/home/pranavix/Desktop/Bankdatabase");
			chdir(server_data.user_id);
			profilefd=open("profile.txt",O_RDWR);
			transfd=open("transact.txt",O_RDWR);
			read(fd,&check,sizeof(check));
			printf("The old balance:%d\n",check.balance);
			if(check.balance < server_data.balance)
			{
				stater.status =13;
			}
			else
			{
				check.balance=check.balance-server_data.balance;
				strcpy(trans.status,"DEBITED");
				trans.ind=trans.ind+1;
				trans.rem_balance=check.balance;
				printf("The new balance:%d\n",check.balance);
				lseek(transfd,0,SEEK_END);
				write(transfd,&trans,sizeof(transfd));
				lseek(fd,0,SEEK_SET);
				write(fd,&check,sizeof(check));
				stater.option=12;
			}
			close(profilefd);
			close(transfd);
		}
		if(stater.status == 9)
		{
			chdir("/home/pranavix/Desktop/Bankdatabase");
			chdir(server_data.user_id);
			fd=open("profile.txt",O_RDONLY);
			read(fd,&check,sizeof(check));
			stater.balan=check.balance;
			stater.option=14;
			close(fd);
		}
		if(stater.status == 10)
		{
			chdir("/home/pranavix/Desktop/Bankdatabase");
			chdir(server_data.user_id);
			profilefd=open("profile.txt",O_RDONLY);
			read(profilefd,&check,sizeof(check));
			stater.option=15;
			close(profilefd);
		}
		ret=send(newsocketfd,&stater,sizeof(stater),0);
		if(ret < 0)
		{
			printf("Failed to send\n");
			exit(1);
		}
		if(stater.status == 10)
		{
			ret=send(newsocketfd,&check,sizeof(check),0);
			if(ret < 0)
			{
				printf("Failed to send\n");
				exit(1);
			}
		}
		if(stater.status == 11)
		{
			chdir("/home/pranavix/Desktop/Bankdatabase");
			chdir(server_data.user_id);
			transfd=open("transact.txt",O_RDONLY);
			printf("The transact:%d\n",transfd);
			wret=read(profilefd,&trans,sizeof(trans));
			while(read(newsocketfd,&trans,sizeof(trans)))
			{
			}
		}

	}

}
int directory_check(char *str)
{
	DIR *d;
	printf("The directory user id:%s\n",str);
	struct dirent *dir;
	d=opendir("/home/pranavix/Desktop/Bankdatabase");
	if(d)
	{
		while((dir=readdir(d))!=NULL)
		{
			if(strcmp(str,dir->d_name)==0)
			{
				printf("Found\n");
				stater.option=1;
				break;
			}
			else
			{
				printf("Not found\n");
				stater.option=2;
			}
		}
		closedir(d);
	}
}
int digit_count(unsigned long int mob,int fix)
{
	int sum=0;
	unsigned long int temp=mob;
	while(temp!=0)
	{
		sum++;
		temp=temp/10;
	}
	printf("The sum:%d\n",sum);
	if(fix == 8)
	{
		if(sum >=8)
			stater.option=4;
		else
			stater.option=3;
	}
	else if(sum > fix)
		stater.option=3;
	else if(sum==fix)
		stater.option=4;
	else
		stater.option=3;

}




