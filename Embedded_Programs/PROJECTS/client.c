#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
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
}db;
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
}ad;
struct time
{
	unsigned int day;
	unsigned int mon;
	unsigned int year;
	unsigned int hr;
	unsigned int min;
	unsigned int sec;
}t;
struct profileinfo
{
	char name[100];
	char nominee[100];
	struct dob p;
	unsigned long int ac_no;
	struct time pt;
	unsigned int bal;
}pi;
struct registration
{
	signed int bal;
	char u_name[100];
	char u_id[10];
	char password[16];
	unsigned long int acc_no;
	unsigned long int adh_no;
	unsigned int mbl_no;
	char gen;
	struct dob d;
	struct nominee nm;
	struct address a;
	struct time rt;
}r;
struct sockaddr_in serv;
int sockfd;
int login();
int registration();
int count(int );
void main()
{
	int opt,ret,sopt,rv,amount=0,comm,scom;
	sockfd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	bzero(&serv,sizeof(serv));
	serv.sin_family=AF_INET;
        serv.sin_port=htons(5008);
        serv.sin_addr.s_addr=inet_addr("127.0.0.1");
	ret=connect(sockfd,(struct sockaddr *)&serv,sizeof(serv));
	if(ret<0)
	{
		printf("Failed to connect\n");
		exit(1);
	}
	while(1)
	{
		printf("Enter the option\n 0.exit\n 1.login\n 2.register\n");
		scanf("%d",&opt);
		__fpurge(stdin);
		switch(opt)
		{
			case 0:exit(0);
			case 1:comm=1; 
			       ret=send(sockfd,&comm,4,0);
			       if(ret<0)
			       {
				       printf("Failed to send\n");
				       break;
			       }
label:ret=login();
				if(ret==-1)
				{
					printf("Failed to login\n");
					goto label;
				}
				if(ret==-2)
				{
					printf("User doesnt exist please register\n");
					break;
				}

				if(ret==0)
				{
					printf("Successfully logged in\n");
login:printf("Enter the option\n 1.deposit\n 2.withdraw\n 3.balance\n 4.transaction history\n 5.profileinfo\n 6.logout\n");
					scanf("%d",&sopt);
					switch(sopt)
					{
						case 1:scom=1;
							ret=send(sockfd,&scom,4,0);
							if(ret<0)
							{
								printf("Failed to send\n");
								exit(1);
							}
						       
deposit:printf("Enter amount to be deposited\n");
							scanf("%d",&amount);
							__fpurge(stdin);
							ret=send(sockfd,&amount,4,0);
							if(ret<0)
							{
								printf("Failed to send\n");
								goto deposit;
							}
							ret=recv(sockfd,&rv,4,0);
							if(ret<0)
							{
								printf("Failed to receive\n");
								goto deposit;
							}
							printf("Deposited successfully\n");
							printf("balance:%d\n",rv);
							goto login;
							break;
						case 2: scom=2;
							ret=send(sockfd,&scom,4,0);
							if(ret<0)
							{
								printf("Failed to send\n");
								exit(1);
							}
withdraw:printf("Enter amount to be drawn\n");
	 						scanf("%d",&amount);
							__fpurge(stdin);
							ret=send(sockfd,&amount,4,0);
							if(ret<0)
							{
								printf("Failed to send\n");
								goto withdraw;
							}
							ret=recv(sockfd,&rv,4,0);
							if(ret<0)
							{
								printf("Failed to receive\n");
								goto withdraw;
							}
							if(rv==-1)
							{
								printf("Insufficient funds\n");
								goto login;
							}
							printf("Withdrawn successfully\n");
							printf("balance:%d\n",rv);
							goto login;
							break;
						case 3:scom=3;
							ret=send(sockfd,&scom,4,0);
							if(ret<0)
							{
								printf("Failed to send\n");
								exit(1);
							}
balance:ret=recv(sockfd,&amount,4,0);
						       if(ret<0)
						       {
							       printf("Failed to receive\n");
							       goto balance;
						       }
						       printf("balance:%d\n",amount);
						       goto login;
						       break;
						case 4: /*scom=4;
							ret=send(sockfd,&scom,4,0);
							if(ret<0)
							{
								printf("Failed to send\n");
								exit(1);
							}
							goto login;*/
							break;
						case 5:scom=5; 
							ret=send(sockfd,&scom,4,0);
							if(ret<0)
							{
								printf("Failed to send\n");
								exit(1);
							}
profile:ret=recv(sockfd,&pi,sizeof(pi),0);
							if(ret<0)
							{
								printf("Failed to receive\n");
								goto profile;
							}
							printf("Name:%s\n",pi.name);
							printf("Nominee name:%s\n",pi.nominee);
							printf("date of birth:%d-%d-%d\n",pi.p.date,pi.p.month,pi.p.year);
							printf("Acc.no:%ld\n",pi.ac_no);
							printf("registered time:%d-%d-%d-%d-%d-%d\n",pi.pt.day,pi.pt.mon,pi.pt.year,pi.pt.hr,pi.pt.min,pi.pt.sec);
							printf("Avail.balance:%d\n",pi.bal);
							goto login;
							break;
						case 6: 
lg:amount=0;
							ret=send(sockfd,&amount,4,0);
							if(ret<0)
							{
								printf("Failed to send\n");
								goto lg;
							}
							break;
						default: printf("Entered invalid input\n");
					}
				}
				break;
			case 2: comm=2;
			       ret=send(sockfd,&comm,4,0);
			       if(ret<0)
			       {
				       printf("Failed to send\n");
				       break;
			       }
regist:ret=registration();
				if(ret==-1)
				{
					printf("Failed to register\n");
					goto regist;
				}
				if(ret==-2)
					printf("User already exist please login\n");
				if(ret==0)
					printf("Successful registered\n");
				break;
			default: printf("Entered invalid option\n");
		}
	}
}
int login()
{
	int l=0,ret,rv;
label:printf("Enter userid:");
	scanf("%[^\n]s",lg.userid);
	__fpurge(stdin);
	printf("Enter password/pin:");
	scanf("%[^\n]s",lg.pass_pin);
	__fpurge(stdin);
	l=strlen(lg.userid);
	if(l!=8)
	{
		printf("Entered invalid userid\n");
		goto label;
	}
	l=strlen(lg.pass_pin);
	if((l<8)||(l>16))
	{
		printf("Entered invalid password/pin\n");
		goto label;
	}
	ret=send(sockfd,&lg,sizeof(lg),0);
	if(ret<0)
	{
		printf("Failed to send\n");
		return -1;
	}
	ret=recv(sockfd,&rv,4,0);
	if(ret<0)
	{
		printf("Failed to receive\n");
		return -1;
	}
	if(rv==-1)
	{
		return -2;
	}
	if(rv==-2)
	{
		printf("Password is invalid\n");
		goto label;
	}
	if(rv==0)
		return 0;
};
int registration()
{
	int ret,rv;
	time_t t=time(NULL);
        struct tm var=*localtime(&t);	
	r.bal=0;
	printf("Enter username:");
	scanf("%[^\n]s",r.u_name);
	__fpurge(stdin);
id:printf("Enter userid 8 digit:");
	scanf("%[^\n]",r.u_id);
	__fpurge(stdin);
	ret=strlen(r.u_id);
	if(ret!=8)
	{
		printf("Invalid id format\n");
		goto id;
	}
pass:printf("Enter password 8-16 letters:");
	scanf("%[^\n]s",r.password);
	__fpurge(stdin);
	ret=strlen(r.password);
	if((ret<8)||(ret>16))
	{
		printf("Invalid password format\n");
		goto pass;
	}
	printf("Enter aadhar number:");
	scanf("%ld",&r.adh_no);
	__fpurge(stdin);
mbl:printf("Enter mobile number 10 digit:");
	scanf("%d",&r.mbl_no);
	__fpurge(stdin);
	ret=count(r.mbl_no);
	if(ret!=10)
	{
		printf("Enter a valid mobile number\n");
		goto mbl;
	}
	r.acc_no=r.adh_no+r.mbl_no;
	printf("Enter gender:in this format if male-M female-f others-O:");
	scanf("%c",&r.gen);
	__fpurge(stdin);
	printf("Enter date of birth:");
	printf("In the format date-month-year\n");
	scanf("%d-%d-%hd",&r.d.date,&r.d.month,&r.d.year);
	__fpurge(stdin);
	printf("Enter nominee details:");
	printf("Enter nominee name:");
	scanf("%[^\n]s",r.nm.n_name);
	__fpurge(stdin);
mb:printf("Enter nominee mobile no:");
	scanf("%d",&r.nm.n_mbno);
	__fpurge(stdin);
	ret=count(r.nm.n_mbno);
	if(ret!=10)
	{
		printf("Enter a valid mobile number\n");
		goto mb;
	}
	printf("Enter nominee aadhar no:");
	scanf("%ld",&r.nm.n_adhno);
	__fpurge(stdin);
	printf("Enter address:");
	printf("House no:");
	scanf("%[^\n]s",r.a.h_no);
	__fpurge(stdin);
	printf("Area:");
	scanf("%[^\n]s",r.a.area);
	__fpurge(stdin);
	printf("Enter location:");
	scanf("%[^\n]s",r.a.location);
	__fpurge(stdin);
	printf("Enter district:");
	scanf("%[^\n]s",r.a.dist);
	__fpurge(stdin);
	printf("Enter state:");
	scanf("%[^\n]s",r.a.state);
	__fpurge(stdin);
	printf("Enter pin:");
	scanf("%d",&r.a.pin);
	__fpurge(stdin);
	r.rt.day=var.tm_mday;
	r.rt.mon=var.tm_mon+1;
	r.rt.year=var.tm_year+1900;
	r.rt.hr=var.tm_hour;
	r.rt.min=var.tm_min;
	r.rt.sec=var.tm_sec;
	ret=send(sockfd,&r,sizeof(r),0);
	if(ret<0)
	{
		printf("Failed to send\n");
		return -1;
	}
	ret=recv(sockfd,&rv,4,0);
	if(ret<0)
	{
		printf("Failed to receive\n");
		return -1;
	}
	if(rv==-2)
		return -2;
	if(rv==0)
		return 0;
}
int count(int n)
{
	int c=0;
	while(n!=0)
	{
		n=n/10;
		c++;
	}
	return c;
}

	



	







	


