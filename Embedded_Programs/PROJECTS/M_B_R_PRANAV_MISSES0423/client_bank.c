//---------------------------Client code-------------
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
#include "header.h"
#define PORT 9821
//-------Structure variables------Globally------\\
struct register_data reg;
struct communicate status;
struct transaction trans;;
int main()
{
	time_t t=time(NULL);
	struct tm pre_time=*localtime(&t);
	char buff[100];
	int ret,prog,sub_opt,temp;
	struct register_data reg;
	struct sockaddr_in client;
	int sockfd;
	sockfd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if(sockfd < 0)
	{
		printf("Failed to create and open the file\n");
		exit(1);
	}
	memset(&client,0,sizeof(client));
	client.sin_family=AF_INET;
	client.sin_port=htons(PORT);
	client.sin_addr.s_addr=inet_addr("127.0.0.1");
	ret=connect(sockfd,(struct sockaddr *)&client,sizeof(client));
	if(ret < 0)
	{
		printf("Failed to connect\n");
		exit(1);
	}
	while(1)
	{
		//printf("--------WElcome to BANK-------\n");
		printf("\t1.REGISTER\n\t2.LOGIN\n\t3.EXIT\n");
		__fpurge(stdin);
		scanf("%d",&prog);
		__fpurge(stdin);
		switch(prog)
		{
			case 3:
				printf("Successfully excuted by user\n");
				exit(0);

			case 1:
				printf("\t-----Register---\n");
				printf("username:");
				scanf("%[^\n]",reg.username);
				__fpurge(stdin);
				printf("\n");
user:                           printf("userid:");
				scanf("%[^\n]",reg.userid);
				__fpurge(stdin);
				printf("\n");
				memset(&status,0,sizeof(status));
				status.stat=1;
				ret=send(sockfd,&status,sizeof(status),0);
				if(ret < 0)
				{
					printf("Failed to receive\n");
					exit(1);
				}
				ret=send(sockfd,&reg,sizeof(reg),0);
				if(ret < 0)
				{
					printf("Failed to receive\n");
					exit(1);
				}
				ret=recv(sockfd,&status,sizeof(status),0);
				if(ret < 0)
				{
					printf("Failed to receive\n");
					exit(1);
				}
				temp=strlen(reg.userid);
				if(temp!=8)
				{
					printf("Please enter 8 digits user id:\n");
					goto user;
				}
				if(status.opt == 1)
				{
					printf("---USER ALREADY-----EXIST---\n");
					break;
				}
				printf("Gender:");
				scanf("%[^\n]",reg.gen);
				__fpurge(stdin);
				printf("\n");
				printf("----Password should be number only not characters\n");
				printf("--Ex:98745632\n");
password:		        printf("password:");
				scanf("%lu",&reg.passwd);
				__fpurge(stdin);
				printf("\n");
				memset(&status,0,sizeof(status));
				status.stat=2;
				ret=send(sockfd,&status,sizeof(status),0);
				if(ret < 0)
				{
					printf("Failed to receive\n");
					exit(1);
				}
				ret=send(sockfd,&reg,sizeof(reg),0);
				if(ret < 0)
				{
					printf("Failed to receive\n");
					exit(1);
				}
				ret=recv(sockfd,&status,sizeof(status),0);
				if(ret < 0)
				{
					printf("Failed to receive\n");
					exit(1);
				}
				if(status.opt == 6)
				{
					printf("Please enter more than or equal 8 digit user id\n");
					goto password;
				}
mobile:                         printf("mobile number:");
				scanf("%lu",&reg.mob_no);
				__fpurge(stdin);
				printf("\n");
				memset(&status,0,sizeof(status));
				status.stat=3;
				ret=send(sockfd,&status,sizeof(status),0);
				if(ret < 0)
				{
					printf("Failed to receive\n");
					exit(1);
				}
				ret=send(sockfd,&reg,sizeof(reg),0);
				if(ret < 0)
				{
					printf("Failed to receive\n");
					exit(1);
				}
				ret=recv(sockfd,&status,sizeof(status),0);
				if(ret < 0)
				{
					printf("Failed to receive\n");
					exit(1);
				}
				if(status.opt == 3)
				{
					printf("Please enter exact 10 mobile number\n");
					goto mobile;
				}
aadhar:                  	printf("aadhar number:");
				scanf("%lu",&reg.aadhar_no);
				__fpurge(stdin);
				printf("\n");
				memset(&status,0,sizeof(status));
				status.stat=4;
				ret=send(sockfd,&status,sizeof(status),0);
				if(ret < 0)
				{
					printf("Failed to receive\n");
					exit(1);
				}
				ret=send(sockfd,&reg,sizeof(reg),0);
				if(ret < 0)
				{
					printf("Failed to receive\n");
					exit(1);
				}
				ret=recv(sockfd,&status,sizeof(status),0);
				if(ret < 0)
				{
					printf("Failed to receive\n");
					exit(1);
				}
				if(status.opt == 3)
				{
					printf("Please enter exact 12 digit aadhar number\n");
					goto aadhar;
				}
				reg.acc_no=reg.mob_no+reg.aadhar_no;
				printf("-----Nominee details----\n");
				printf("nominee name:");
				scanf("%[^\n]",reg.info.nom_name);
				__fpurge(stdin);
				printf("\n");
nominee:                        printf("nominee mobile number:");
				scanf("%lu",&reg.info.nom_mob_no);
				__fpurge(stdin);
				printf("\n");
				memset(&status,0,sizeof(status));
				status.stat=5;
				ret=send(sockfd,&status,sizeof(status),0);
				if(ret < 0)
				{
					printf("Failed to receive\n");
					exit(1);
				}
				ret=send(sockfd,&reg,sizeof(reg),0);
				if(ret < 0)
				{
					printf("Failed to receive\n");
					exit(1);
				}
				ret=recv(sockfd,&status,sizeof(status),0);
				if(ret < 0)
				{
					printf("Failed to receive\n");
					exit(1);
				}
				if(status.opt == 3)
				{
					printf("Please enter exact 10 digit mob no\n");
					goto nominee;
				}
nomineeaadhar:			printf("nominee aadhar number:");
				scanf("%lu",&reg.info.nom_aadhar_no);
				__fpurge(stdin);
				printf("\n");
				memset(&status,0,sizeof(status));
				status.stat=6;
				ret=send(sockfd,&status,sizeof(status),0);
				if(ret < 0)
				{
					printf("Failed to receive\n");
					exit(1);
				}
				ret=send(sockfd,&reg,sizeof(reg),0);
				if(ret < 0)
				{
					printf("Failed to receive\n");
					exit(1);
				}
				ret=recv(sockfd,&status,sizeof(status),0);
				if(ret < 0)
				{
					printf("Failed to receive\n");
					exit(1);
				}
				if(status.opt == 6)
				{
					printf("Please enter exact 12 digit aadhar number\n");
					goto nomineeaadhar;
				}
				printf("user details\n");
				printf("Date Of Birth:");
				scanf("%u/%u/%u",&reg.date.day,&reg.date.mon,&reg.date.year);
				__fpurge(stdin);
				printf("\n");
				printf("------Address----:\n");
				printf("House no:");
				scanf("%[^\n]",reg.details.hous_no);
				__fpurge(stdin);
				printf("\n");
				printf("Area:");
				scanf("%[^\n]",reg.details.area);
				__fpurge(stdin);
				printf("\n");
				printf("Loaction:");
				scanf("%[^\n]",reg.details.location);
				__fpurge(stdin);
				printf("\n");
				printf("Pin:");
				scanf("%u",&reg.details.pin);
				__fpurge(stdin);
				printf("\n");
				printf("District:");
				scanf("%[^\n]",reg.details.district);
				__fpurge(stdin);
				printf("\n");
				reg.balance=0;
				printf("State:");
				scanf("%[^\n]",reg.details.state);
				__fpurge(stdin);
				printf("\n");
				printf("----Time----\n");
				reg.dt.day=pre_time.tm_mday;
				reg.dt.mon=pre_time.tm_mon+1;
				reg.dt.year=pre_time.tm_year+1900;
				reg.dt.hour=pre_time.tm_hour;
				reg.dt.min=pre_time.tm_min;
				reg.dt.sec=pre_time.tm_sec;
				printf("---Time also updated--\n");
				memset(&status,0,sizeof(status));
				status.stat=7;
				ret=send(sockfd,&status,sizeof(status),0);
				if(ret < 0)
				{
					printf("Failed to receive\n");
					exit(1);
				}
				ret=send(sockfd,&reg,sizeof(reg),0);
				if(ret < 0)
				{
					printf("Failed to receive\n");
					exit(1);
				}
				ret=recv(sockfd,&status,sizeof(status),0);
				if(ret < 0)
				{
					printf("Failed to receive\n");
					exit(1);
				}
				if(status.opt != 10)
				{
					printf("Unsuccessfully registered\n");
					break;
				}
				else
				{
					printf("Successfully registred\n");

				}
				break;

			case 2:
log:             		printf("Ready to login\n");
				printf("userid:");
				scanf("%[^\n]",reg.userid);
				__fpurge(stdin);
				printf("\n");
				memset(&status,0,sizeof(status));
				status.stat=8;
				ret=send(sockfd,&status,sizeof(status),0);
				if(ret < 0)
				{
					printf("Failed to receive\n");
					exit(1);
				}
				ret=send(sockfd,&reg,sizeof(reg),0);
				if(ret < 0)
				{
					printf("Failed to receive\n");
					exit(1);
				}
				ret=recv(sockfd,&status,sizeof(status),0);
				if(ret < 0)
				{
					printf("Failed to receive\n");
					exit(1);
				}
				if(status.opt == 2)
				{
					printf("User does not exist ---please register\n");
					break;
				}
passw:                                  printf("password:");
					scanf("%lu",&reg.passwd);
					__fpurge(stdin);
					printf("\n");
					memset(&status,0,sizeof(status));
					status.stat=9;
					ret=send(sockfd,&status,sizeof(status),0);
					if(ret < 0)
					{
						printf("Failed to receive\n");
						exit(1);
					}
					ret=send(sockfd,&reg,sizeof(reg),0);
					if(ret < 0)
					{
						printf("Failed to receive\n");
						exit(1);
					}
					ret=recv(sockfd,&status,sizeof(status),0);
					if(ret < 0)
					{
						printf("Failed to receive\n");
						exit(1);
					}
					if(status.opt == 12)
					{
						printf("Please entire 8 digits correct password\n");
						goto passw;
					}
					printf("-----Login suucessfully---\n");
					while(1)
					{
						printf("\t1.DEPOSIT\n\t2.WITHDRAW\n\t3.BALANCE\n\t4.TRANSACTION HISTORY\n\t5.PROFILE INFORMATION\n\t6.LOGOUT\n");
						scanf("%d",&sub_opt);
						__fpurge(stdin);
						switch(sub_opt)
						{
							case 1:
								printf("-----Ready to deposit----\n");
								printf("Enter the amount to be deposit:");
								scanf("%d",&reg.balance);
								__fpurge(stdin);
								printf("\n");
								memset(&status,0,sizeof(status));
								status.stat=10;
								ret=send(sockfd,&status,sizeof(status),0);
								if(ret < 0)
								{
									printf("Failed to receive\n");
									exit(1);
								}
								ret=send(sockfd,&reg,sizeof(reg),0);
								if(ret < 0)
								{
									printf("Failed to receive\n");
									exit(1);
								}
								ret=recv(sockfd,&status,sizeof(status),0);
								if(ret < 0)
								{
									printf("Failed to receive\n");
									exit(1);
								}
								if(status.opt != 13)
								{
									printf("Unsuccessfull deposite\n");
									break;
								}
								printf("Successfully deposite\n");
								break;

							case 2:
								printf("-----Ready to withdraw----\n");
								printf("Enter the amount to be Withdraw:");
								scanf("%d",&reg.balance);
								__fpurge(stdin);
								printf("\n");
								memset(&status,0,sizeof(status));
								status.stat=11;
								ret=send(sockfd,&status,sizeof(status),0);
								if(ret < 0)
								{
									printf("Failed to receive\n");
									exit(1);
								}
								ret=send(sockfd,&reg,sizeof(reg),0);
								if(ret < 0)
								{
									printf("Failed to receive\n");
									exit(1);
								}
								ret=recv(sockfd,&status,sizeof(status),0);
								if(ret < 0)
								{
									printf("Failed to receive\n");
									exit(1);
								}
								if(status.opt == 14)
								{
									printf("insufficient funds\n");
									break;
								}
								printf("Succesfully withdrawed\n");
								break;
							case 3:
								printf("Ready to get the balance--\n");
								memset(&status,0,sizeof(status));
								status.stat=12;
								ret=send(sockfd,&status,sizeof(status),0);
								if(ret < 0)
								{
									printf("Failed to receive\n");
									exit(1);
								}
								ret=send(sockfd,&reg,sizeof(reg),0);
								if(ret < 0)
								{
									printf("Failed to receive\n");
									exit(1);
								}
								ret=recv(sockfd,&status,sizeof(status),0);
								if(ret < 0)
								{
									printf("Failed to receive\n");
									exit(1);
								}
								if(status.opt != 16)
								{
									printf("unable to show balance\n");
									break;
								}
								reg.balance=status.stat;
								printf("The Balance amount:%d\n",reg.balance);
								break;

							case 5:
								printf("----Ready to show profile information\n");
								memset(&status,0,sizeof(status));
								status.stat=13;
								ret=send(sockfd,&status,sizeof(status),0);
								if(ret < 0)
								{
									printf("Failed to receive\n");
									exit(1);
								}
								ret=send(sockfd,&reg,sizeof(reg),0);
								if(ret < 0)
								{
									printf("Failed to receive\n");
									exit(1);
								}
								ret=recv(sockfd,&status,sizeof(status),0);
								if(ret < 0)
								{
									printf("Failed to receive\n");
									exit(1);
								}
								if(status.opt == 17)
								{
									ret=recv(sockfd,&reg,sizeof(reg),0);
									if(ret < 0)
									{
										printf("Failed to receive\n");
										exit(1);
									}
									printf("Username:%s\n",reg.username);
									printf("User id:%s\n",reg.userid);
									printf("Password:%lu\n",reg.passwd);
									printf("Account number:%lu\n",reg.acc_no);
									printf("Aadhar number:%lu\n",reg.aadhar_no);
									printf("Mobile number:%lu\n",reg.mob_no);
									printf("----Balance:%d\n",reg.balance);
								}
								else
								{
									printf("Failed to show you profile\n");
									break;
								}
								break;

							case 4:
								printf("------Ready to show the transaction history-----\n");
								memset(&status,0,sizeof(status));
								status.stat=14;
								ret=send(sockfd,&status,sizeof(status),0);
								if(ret < 0)
								{
									printf("Failed to receive\n");
									exit(1);
								}
								ret=send(sockfd,&reg,sizeof(reg),0);
								if(ret < 0)
								{
									printf("Failed to receive\n");
									exit(1);
								}
rcv:                                                            ret=recv(sockfd,&trans,sizeof(trans),0);
								if(ret < 0)
								{
									printf("Failed to reeceive\n");
									exit(1);
								}
								if(trans.index !=20)
								{
									printf("\tindex:%d\n",trans.index);
									printf("\tamount status:%s\n",trans.amount_stat);
									printf("\tremaining balance:%d\n",trans.rem_balance);
									printf("\t-%d-%d-%d : %d-%d-%d\n",trans.mod_time.day,trans.mod_time.mon,trans.mod_time.year,trans.mod_time.hour,trans.mod_time.min,trans.mod_time.sec);
								}
								if(trans.index != 20)
									goto rcv;
								break;

							case 6:
								printf("-----LOG---OUT----\n");
								printf("------Log out successfully----\n");
								goto log;







						}



					}
		}

	}
}










