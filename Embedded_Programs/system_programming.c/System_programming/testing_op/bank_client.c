#include<stdio.h>
#include<dirent.h>
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
#define PORTER 9994
char *ptr;
struct communicate stater;
int main()
{
	int i=0;
	struct transaction trans;
	int prog,sub_opt,fd;
	time_t t=time(NULL);
	struct tm var=*localtime(&t);
	struct register_data reg;
	struct sockaddr_in client;
	int socketfd,newsocketfd,ret,bret,client_size;
	char buf[100];
	socketfd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if(socketfd < 0)
	{
		printf("Failed to create and open the socket\n");
		exit(1);
	}
	memset(&client,0,sizeof(client));
	client.sin_family=AF_INET;
	client.sin_port=htons(PORTER);
	client.sin_addr.s_addr=inet_addr("127.0.0.1");
	ret=connect(socketfd,(struct sockaddr *)&client,sizeof(client));
	if(ret < 0)
	{
		printf("Failed to connect\n");
		exit(1);
	}
	while(1)
	{
		printf("---------Nice to see you Welcome to pranav bank----\n");
		printf("\n\t");
		printf("1.Login\n2.Register to banking\n3.Exit\n");
		scanf("%d",&prog);
		__fpurge(stdin);
		switch(prog)
		{
			case 1:
				printf("Let's login \n");
				printf("user id:");
				scanf("%[^\n]",reg.user_id);
				__fpurge(stdin);
				printf("\n");
				memset(&stater,0,sizeof(stater));
				ret=send(socketfd,&reg,sizeof(reg),0);
				if(ret < 0)
				{
					printf("Failed to send\n");
					exit(1);
				}
				stater.status=1;
				ret=send(socketfd,&stater,sizeof(stater),0);
				if(ret < 0)
				{
					printf("Failed to send\n");
					exit(1);
				}
				ret=recv(socketfd,&stater,sizeof(stater),0);
				printf("The starter option is:%d\n",stater.option);
				if(ret < 0)
				{
					printf("Failed to receive\n");
					exit(1);
				}
				if(stater.option != 1)
				{
					printf("USER----NOT----EXIST--\n");
					printf("---Please Register----\n");
					break;
				}
passw:                          printf("password:");
				scanf("%lu",&reg.passwd);
				__fpurge(stdin);
				printf("\n");
				memset(&stater,0,sizeof(stater));
				stater.status=4;
				ret=send(socketfd,&reg,sizeof(reg),0);
				if(ret < 0)
				{
					printf("Failed to send\n");
					exit(1);
				}
				ret=send(socketfd,&stater,sizeof(stater),0);
				if(ret < 0)
				{
					printf("Failed to send\n");
					exit(1);
				}
				ret=recv(socketfd,&stater,sizeof(stater),0);
				printf("The starter option is:%d\n",stater.option);
				if(ret < 0)
				{
					printf("Failed to receive\n");
					exit(1);
				}
				if(stater.option != 4)
				{
					printf("Please enter more than 8 digits password\n");
					goto passw;
				}
				//Pasword check
				memset(&stater,0,sizeof(stater));
				stater.status=6;
				ret=send(socketfd,&reg,sizeof(reg),0);
				if(ret < 0)
				{
					printf("Failed to send\n");
					exit(1);
				}
				ret=send(socketfd,&stater,sizeof(stater),0);
				if(ret < 0)
				{
					printf("Failed to send\n");
					exit(1);
				}
				ret=recv(socketfd,&stater,sizeof(stater),0);
				printf("The starter option is:%d\n",stater.option);
				if(ret < 0)
				{
					printf("Failed to receive\n");
					exit(1);
				}
				if(stater.option != 10)
				{
					printf("Please enter correct password\n");
					goto passw;
				}
				printf("------Login successfully\n");
				while(1)
				{
					printf("1.DEPOSITE\n2.WITHDRAW\n3.BALANCE\n4.HISTORY\n5.PROFILE INFO\n6.LOG--OUT\n");
					__fpurge(stdin);
					scanf("%d",&sub_opt);
					__fpurge(stdin);
					switch(sub_opt)
					{
						case 1:
							printf("---------Ready to deposit------\n");
							printf("Enter tha amount to be deposite\n");
							scanf("%d",&reg.balance);
							__fpurge(stdin);
							memset(&stater,0,sizeof(stater));
							stater.status=7;
							ret=send(socketfd,&reg,sizeof(reg),0);
							if(ret < 0)
							{
								printf("Failed to send\n");
								exit(1);
							}
							ret=send(socketfd,&stater,sizeof(stater),0);
							if(ret < 0)
							{
								printf("Failed to send\n");
								exit(1);
							}
							ret=recv(socketfd,&stater,sizeof(stater),0);
							printf("The starter option is:%d\n",stater.option);
							if(ret < 0)
							{
								printf("Failed to receive\n");
								exit(1);
							}
							if(stater.option != 11)
							{
								printf("Desposite is unsuccesfull\n");
								break;
							}
							printf("Deposite is successfull\n");
							break;


						case 2:
							printf("------Ready to withdraw---\n");
							printf("Enter tha amount to be withdraw:");
							scanf("%d",&reg.balance);
							__fpurge(stdin);
							printf("\n");
							memset(&stater,0,sizeof(stater));
							stater.status=8;
							ret=send(socketfd,&reg,sizeof(reg),0);
							if(ret < 0)
							{
								printf("Failed to send\n");
								exit(1);
							}
							ret=send(socketfd,&stater,sizeof(stater),0);
							if(ret < 0)
							{
								printf("Failed to send\n");
								exit(1);
							}
							ret=recv(socketfd,&stater,sizeof(stater),0);
							printf("The starter option is:%d\n",stater.option);
							if(ret < 0)
							{
								printf("Failed to receive\n");
								exit(1);
							}
							if(stater.option != 12)
							{
								printf("Insufficient funds\n");
								break;
							}
							printf("Withdraw is successfull\n");
							break;

						case 3:
							printf("-----Ready to display balance\n");
							memset(&stater,0,sizeof(stater));
							stater.status=9;
							ret=send(socketfd,&reg,sizeof(reg),0);
							if(ret < 0)
							{
								printf("Failed to send\n");
								exit(1);
							}
							ret=send(socketfd,&stater,sizeof(stater),0);
							if(ret < 0)
							{
								printf("Failed to send\n");
								exit(1);
							}
							ret=recv(socketfd,&stater,sizeof(stater),0);
							printf("The starter option is:%d\n",stater.option);
							if(ret < 0)
							{
								printf("Failed to receive\n");
								exit(1);
							}
							if(stater.option != 14)
							{
								printf("Failed to load balance\n");
								break;
							}
							printf("Balance:%d\n",stater.balan);
							break;

						case 5:
							printf("-----Ready to display profile information\n");
							memset(&stater,0,sizeof(stater));
							stater.status=10;
							ret=send(socketfd,&reg,sizeof(reg),0);
							if(ret < 0)
							{
								printf("Failed to send\n");
								exit(1);
							}
							ret=send(socketfd,&stater,sizeof(stater),0);
							if(ret < 0)
							{
								printf("Failed to send\n");
								exit(1);
							}
							ret=recv(socketfd,&stater,sizeof(stater),0);
							printf("The starter option is:%d\n",stater.option);
							if(ret < 0)
							{
								printf("Failed to receive\n");
								exit(1);
							}
							if(stater.option == 15)
							{
								printf("Receiver loop\n");
								ret=recv(socketfd,&reg,sizeof(reg),0);
								if(ret < 0)
								{
									printf("Failed to receive\n");
									exit(1);
								}
							}
							printf("\tThe name:%s\n",reg.name);
							printf("\tThe user id:%s\n",reg.user_id);
							printf("\tThe out:%lu\n",reg.mob_no);
							printf("\tThe aadhar:%lu\n",reg.aadhar_no);
							printf("\tThe passwd:%lu\n",reg.passwd);
							printf("\tBalance:%d\n",reg.balance);
							printf("\tgen:%s\n",reg.gen);
							printf("\tAcc_no:%lu\n",reg.acc_no);
							printf("\tData of birth:%d----%d---%d\n",reg.d_o_b.date,reg.d_o_b.month,reg.d_o_b.year);
							printf("\tNominee info:%s\n",reg.info.nom_name);
							printf("\tNominee nmber:%lu\n",reg.info.mob_no);
							printf("\tNominee info:%lu\n",reg.info.aadhar_no);
							printf("\tAddress:%s\n",reg.details.house_no);
							printf("\tAddress:%s\n",reg.details.area);
							printf("\tAddress:%s\n",reg.details.location);
							printf("\tAddress:%s\n",reg.details.district);
							printf("\tAddress:%s\n",reg.details.state);
							printf("\tAddress:%u\n",reg.details.pin_code);
							printf("\tThe day:%d--The mon:%d--The year%d---The hour:%d--The min:%d---The sec:%d\n",reg.dt.day,reg.dt.mon,reg.dt.year,reg.dt.hour,reg.dt.min,reg.dt.sec);
							break;

						case 4:
							printf("-------Ready to show the history----\n");
							memset(&stater,0,sizeof(stater));
							stater.status=11;
							ret=send(socketfd,&reg,sizeof(reg),0);
							if(ret < 0)
							{
								printf("Failed to send\n");
								exit(1);
							}
							ret=send(socketfd,&stater,sizeof(stater),0);
							if(ret < 0)
							{
								printf("Failed to send\n");
								exit(1);
							}
							ret=recv(socketfd,&stater,sizeof(stater),0);
							printf("The starter option is:%d\n",stater.option);
							printf("The starter option is:%d\n",stater.status);
							if(ret < 0)
							{
								printf("Failed to receive\n");
								exit(1);
							}
							ret=1;
							//while(i<ret)

							recv(socketfd,&trans,sizeof(trans),0);
							printf("AFter recieve\n");
							write(1,&trans,sizeof(trans));
							printf("the ind:%d\n",trans.ind);
							printf("the staus:%s\n",trans.status);
							printf("therem_balance:%d\n",trans.rem_balance);
							printf("the time:%d\n",trans.var.day);
							printf("the time:%d\n",trans.var.mon);
							printf("the time:%d\n",trans.var.year);
							printf("the time:%d\n",trans.var.hour);
							printf("the time:%d\n",trans.var.min);
							printf("the time:%d\n",trans.var.sec);
							i++;
							ret=trans.ind;



					}
				}




			case 2:
				printf("Let's register to my internet banking\n");
				printf("username:");
				__fpurge(stdin);
				scanf("%[^\n]",reg.name);
				__fpurge(stdin);
				printf("\n");
				printf("user id:");
				scanf("%[^\n]",reg.user_id);
				__fpurge(stdin);
				printf("\n");
				memset(&stater,0,sizeof(stater));
				ret=send(socketfd,&reg,sizeof(reg),0);
				if(ret < 0)
				{
					printf("Failed to send\n");
					exit(1);
				}
				stater.status=1;
				ret=send(socketfd,&stater,sizeof(stater),0);
				if(ret < 0)
				{
					printf("Failed to send\n");
					exit(1);
				}
				ret=recv(socketfd,&stater,sizeof(stater),0);
				printf("The starter option is:%d\n",stater.option);
				if(ret < 0)
				{
					printf("Failed to receive\n");
					exit(1);
				}
				if(stater.option != 2)
				{
					printf("USER----ALREADY----EXIST--\n");
					printf("---Please login----\n");
					break;
				}
mobile:			       printf("mobile number:");
			       scanf("%lu",&reg.mob_no);
			       __fpurge(stdin);
			       printf("\n");
			       memset(&stater,0,sizeof(stater));
			       stater.status=2;
			       ret=send(socketfd,&reg,sizeof(reg),0);
			       if(ret < 0)
			       {
				       printf("Failed to send\n");
				       exit(1);
			       }
			       ret=send(socketfd,&stater,sizeof(stater),0);
			       if(ret < 0)
			       {
				       printf("Failed to send\n");
				       exit(1);
			       }
			       ret=recv(socketfd,&stater,sizeof(stater),0);
			       printf("The starter option is:%d\n",stater.option);
			       if(ret < 0)
			       {
				       printf("Failed to receive\n");
				       exit(1);
			       }
			       if(stater.option != 4)
			       {
				       printf("Please enter Exact 10 digit mobile number\n");
				       goto mobile;
			       }
aadhar:                        printf("aadhar number:");
			       scanf("%lu",&reg.aadhar_no);
			       __fpurge(stdin);
			       printf("\n");
			       memset(&stater,0,sizeof(stater));
			       stater.status=3;
			       ret=send(socketfd,&reg,sizeof(reg),0);
			       if(ret < 0)
			       {
				       printf("Failed to send\n");
				       exit(1);
			       }
			       ret=send(socketfd,&stater,sizeof(stater),0);
			       if(ret < 0)
			       {
				       printf("Failed to send\n");
				       exit(1);
			       }
			       ret=recv(socketfd,&stater,sizeof(stater),0);
			       printf("The starter option is:%d\n",stater.option);
			       if(ret < 0)
			       {
				       printf("Failed to receive\n");
				       exit(1);
			       }
			       if(stater.option != 4)
			       {
				       printf("Please enter Exact 12 digit aadhar number\n");
				       goto aadhar;
			       }
password:			       printf("password:");
				       scanf("%lu",&reg.passwd);
				       __fpurge(stdin);
				       printf("\n");
				       memset(&stater,0,sizeof(stater));
				       stater.status=4;
				       ret=send(socketfd,&reg,sizeof(reg),0);
				       if(ret < 0)
				       {
					       printf("Failed to send\n");
					       exit(1);
				       }
				       ret=send(socketfd,&stater,sizeof(stater),0);
				       if(ret < 0)
				       {
					       printf("Failed to send\n");
					       exit(1);
				       }
				       ret=recv(socketfd,&stater,sizeof(stater),0);
				       printf("The starter option is:%d\n",stater.option);
				       if(ret < 0)
				       {
					       printf("Failed to receive\n");
					       exit(1);
				       }
				       if(stater.option != 4)
				       {
					       printf("Please enter more than 8 digits password\n");
					       goto password;
				       }
				       reg.balance=0;
				       printf("Gender:");
				       scanf("%s",reg.gen);
				       __fpurge(stdin);
				       printf("\n");
				       reg.acc_no=reg.mob_no + reg.aadhar_no;
				       printf("Date of birth-----DD/MM/YYYY---($format$)\n");
				       printf("Date of birth:");
				       scanf("%02d-%02d-%04d",&reg.d_o_b.date,&reg.d_o_b.month,&reg.d_o_b.year);
				       __fpurge(stdin);
				       printf("\n");
				       printf("nominee inforemation\n");
				       printf("nominee name:");
				       scanf("%[^\n]",reg.info.nom_name);
				       __fpurge(stdin);
				       printf("\n");
				       printf("nominee mobile number:");
				       scanf("%lu",&reg.info.mob_no);
				       __fpurge(stdin);
				       printf("\n");
				       printf("nominee aadhar number:");
				       scanf("%lu",&reg.info.aadhar_no);
				       __fpurge(stdin);
				       printf("\n");
				       printf("address details\n");
				       printf("House no:");
				       scanf("%s",reg.details.house_no);
				       __fpurge(stdin);
				       printf("\n");
				       printf("Area:");
				       scanf("%[^\n]",reg.details.area);
				       __fpurge(stdin);
				       printf("\n");
				       printf("Location:");
				       scanf("%[^\n]",reg.details.location);
				       __fpurge(stdin);
				       printf("\n");
				       printf("District:");
				       scanf("%[^\n]",reg.details.district);
				       __fpurge(stdin);
				       printf("\n");
				       printf("State:");
				       scanf("%[^\n]",reg.details.state);
				       __fpurge(stdin);
				       printf("\n");
				       printf("Pincode:");
				       scanf("%u",&reg.details.pin_code);
				       __fpurge(stdin);
				       printf("\n");
				       printf("Time also is updated\n");
				       reg.dt.day=var.tm_mday;
				       reg.dt.mon=var.tm_mon+1;
				       reg.dt.year=var.tm_year+1900;
				       reg.dt.hour=var.tm_hour;
				       reg.dt.min=var.tm_min;
				       reg.dt.sec=var.tm_sec;
				       memset(&stater,0,sizeof(stater));
				       stater.status=5;
				       ret=send(socketfd,&reg,sizeof(reg),0);
				       if(ret < 0)
				       {
					       printf("Failed to send\n");
					       exit(1);
				       }
				       ret=send(socketfd,&stater,sizeof(stater),0);
				       if(ret < 0)
				       {
					       printf("Failed to send\n");
					       exit(1);
				       }
				       ret=recv(socketfd,&stater,sizeof(stater),0);
				       printf("The starter option is:%d\n",stater.option);
				       if(ret < 0)
				       {
					       printf("Failed to receive\n");
					       exit(1);
				       }

		}



	}












}

