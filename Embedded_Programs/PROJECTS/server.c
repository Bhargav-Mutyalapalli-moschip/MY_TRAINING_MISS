#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<dirent.h>
#include<time.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<sys/stat.h>
#include<arpa/inet.h>
#include<stdio_ext.h>
struct login
{
        char userid[10];
        char pass_pin[16];
}lg;
struct dob
{
	unsigned int date;
	unsigned int month;
	unsigned short int year;
}d;
struct nominee
{
	char n_name[100];
	unsigned int n_mbno;
	unsigned long int n_adhno;
}n;
struct address
{
	char h_no[50];
	char area[50];
	char location[50];
	char dist[50];
	char state[50];
	unsigned int pin;
}a;
struct time
{
	unsigned int day;
	unsigned int mon;
	unsigned int year;
	unsigned int hr;
	unsigned int min;
	unsigned int sec;
}t;
struct profile
{
	signed int balance;
	char u_name[100];
	char u_id[10];
	char password[16];
	unsigned long int acc_no;
	unsigned long int adh_no;
	unsigned int mbl_no;
	char gen;
	struct dob d;
	struct nominee n;
	struct address a;
	struct time rt;
}p;
struct profileinfo
{
        char name[100];
        char nominee[100];
        struct dob p;
        unsigned long int ac_no;
        struct time pt;
        unsigned int bal;
}pi;
struct sockaddr_in serv,client;
int sockfd,newsockfd;
void login();
void registe();
void main()
{
	int opt,ret,client_size,comm,sopt,amount,fd,n;
	DIR *d;
	ret=mkdir("/home/pranavix/Desktop/database",0777);
	if(ret<0)
	{
		printf("failed to create directory\n");
	}
	d=opendir("/home/pranavix/Desktop/database");
	if(d<0)
	{
		printf("failed to open directory\n");
		exit(1);
	}
	sockfd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	bzero(&serv,sizeof(struct sockaddr_in));
	serv.sin_family=AF_INET;
	serv.sin_port=htons(5008);
	serv.sin_addr.s_addr=INADDR_ANY;
	ret=bind(sockfd,(struct sockaddr *)&serv,sizeof(serv));
	if(ret<0)
	{
		printf("failed to bind\n");
		exit(1);
	}
	ret=listen(sockfd,5);
	if(ret<0)
	{
		printf("failed to listen\n");
		exit(1);
	}
	client_size=sizeof(client);
	newsockfd=accept(sockfd,(struct sockaddr *)&client,&client_size);
	if(newsockfd<0)
	{
		printf("Failed to accept\n");
		exit(1);
	}
	printf("Successfully connected\n");
	while(1)
	{
		ret=recv(newsockfd,&comm,4,0);
		if(ret<0)
		{
			printf("Failed to receive\n");
		}
		switch(comm)
		{
			case 1:login();
			       ret=recv(newsockfd,&sopt,4,0);
			       if(ret<0)
			       {
				       printf("Failed to receive\n");
				       exit(1);
			       }
			       switch(sopt)
			       {
				       case 1: ret=recv(newsockfd,&amount,4,0);
					       if(ret<0)
					       {
						       printf("Failed to receive\n");
						       exit(1);
					       }
						fd=open("profile.txt",O_RDWR);
						if(fd<0)
						{
						printf("Failed to open\n");
						exit(1);
						}
						ret=read(fd,&p,sizeof(p));
						if(ret<0)
						{
							printf("Failed to read\n");
							exit(1);
						}
						p.balance=amount+p.balance;
						ret=write(fd,&p,sizeof(p));
						if(ret<0)
						{
							printf("Failed to write\n");
							exit(1);
						}
						ret=send(newsockfd,&p.balance,4,0);
						if(ret<0)
						{
							printf("Failed to send\n");
							exit(1);
						}
						close(fd);
						break;
				       case 2: ret=recv(newsockfd,&amount,4,0);
					       if(ret<0)
					       {
						       printf("Failed to receive\n");
						       exit(1);
					       }
						fd=open("profile.txt",O_RDWR);
						if(fd<0)
						{
						printf("Failed to open\n");
						exit(1);
						}
						ret=read(fd,&p,sizeof(p));
						if(ret<0)
						{
							printf("Failed to read\n");
							exit(1);
						}
						if(p.balance<amount)
						{
							n=-1;
							ret=send(newsockfd,&n,4,0);
							if(ret<0)
							{
								printf("Failed to send\n");
								exit(1);
							}
						}
						else
						{
							p.balance=p.balance-amount;
							 ret=write(fd,&p,sizeof(p));
							 if(ret<0)
							 {
								 printf("Failed to write\n");
								 exit(1);
							 }
							 ret=send(newsockfd,&p.balance,4,0);
							 if(ret<0)
							 {
								 printf("Failed to send\n");
								 exit(1);
							 }
                                                }
						close(fd);
						break;
				       case 3:
						fd=open("profile.txt",O_RDWR);
						if(fd<0)
						{
						printf("Failed to open\n");
						exit(1);
						}
						ret=read(fd,&p,sizeof(p));
						if(ret<0)
						{
							printf("Failed to read\n");
							exit(1);
						}
						ret=send(newsockfd,&p.balance,4,0);
						if(ret<0)
						{
							printf("Failed to send\n");
							exit(1);
						}
						close(fd);
						break;
				       case 4: break;
				       case 5:  fd=open("profile.txt",O_RDWR);
						if(fd<0)
						{
						printf("Failed to open\n");
						exit(1);
						}
						ret=read(fd,&pi,sizeof(pi));
						if(ret<0)
						{
							printf("Failed to read\n");
							exit(1);
						}
				       		ret=send(sockfd,&pi,sizeof(pi),0);
                                                if(ret<0)
                                                {
							printf("Failed to send\n");
                                                        exit(1);
                                                }
						close(fd);
						break;
				       case 6: ret=recv(newsockfd,&n,4,0);
					       if(ret<0)
					       {
						       printf("Failed to receive\n");
						       exit(1);
					       }
					       if(n==0)
					      		chdir("/home/pranavix/Desktop/database");
					      break;
			       }
			       break;
			case 2:registe();
			break;
		}
	}
}
void login()
{
		int ret,opt,rv,fd;
		DIR *d;
//		while(1)
		{
			ret=recv(newsockfd,&lg,sizeof(lg),0);
			if(ret<0)
			{
				printf("Failed to receive\n");
				exit(1);
			}
			chdir("/home/pranavix/Desktop/database");
			printf("%s\n",lg.pass_pin);
			d=opendir(lg.userid);
			if(d==NULL)
			{
				opt=-1;
				ret=send(newsockfd,&opt,4,0);
				if(ret<0)
				{
					printf("Failed to send\n");
					exit(1);
				}
			}
			else
			{
				fd=open("profile.txt",O_RDWR);
				if(fd<0)
				{
					printf("Failed to open\n");
					exit(1);
				}
				ret=read(fd,&p,sizeof(p));
				if(ret<0)
				{
					printf("Failed to read\n");
					exit(1);
				}
				printf("%sp\n",p.password);
				close(fd);
				if(strcmp(lg.pass_pin,p.password)==0)
				{
					opt=0;
					ret=send(newsockfd,&opt,4,0);
					if(ret<0)
					{
						printf("Failed to send\n");
						exit(1);
					}
				}
				else
				{
					opt=-2;
					ret=send(newsockfd,&opt,4,0);
					if(ret<0)
					{
						printf("Failed to send\n");
						exit(1);
					}
				}
			}
		}
}
void registe()
{
	int ret,fd,rv;
	DIR *d;
	bzero(&p,sizeof(p));
	ret=recv(newsockfd,&p,sizeof(p),0);
	if(ret<0)
	{
		printf("Failed to receive\n");

	}
	printf("%s\nk",p.password);
	chdir("/home/pranavix/Desktop/database");
	d=opendir(p.u_id);	
	if(d==NULL)
	{
		printf("%s\n",p.u_id);
		fd=mkdir(p.u_id,0777);
		if(fd<0)
		{
			printf("failed to open directory\n");
			exit(1);
		}
	}
	else
	{
		ret=-2;
		ret=send(newsockfd,&ret,4,0);
		if(ret<0)
		{
			printf("Failed to send\n");
		}
	}

	chdir(p.u_id);
	fd=open("profile.txt",O_CREAT | O_RDWR | O_TRUNC,0777);
	if(fd<0)
	{
		printf("Failed to open\n");
	}
	ret=write(fd,&p,sizeof(p));
	if(ret<0)
	{
		printf("Failed to write\n");
	}
	fd=open("transact.txt",O_CREAT | O_RDWR | O_TRUNC,0777);
	if(fd<0)
	{
		printf("Failed to open\n");
	}
	rv=0;
	ret=send(newsockfd,&rv,4,0);
	if(ret<0)
	{
		printf("Failed to send\n");
	}
}

























