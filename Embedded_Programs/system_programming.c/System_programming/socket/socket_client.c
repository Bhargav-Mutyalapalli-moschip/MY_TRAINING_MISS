#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/socket.h>
#include<netinet/in.h>
int sret;
#define PORT 9963
int main()
{
	char buf[100]="hi";
	int i,n=100;
	fd_set fr,fw,fe;
	struct sockaddr_in var;
	struct timeval tv;
	//set of functions nothing but the environment (API's the socket programming on your laptop
	int ret,bret=0,lret,cret;
	ret=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if(ret < 0)
	{
		printf("Failed to open the socket\n");
		exit(1);
	}
	printf("Successfully socket is opened\n");
	printf("The socket id:%d\n",ret);
	memset(&(var),0,sizeof(var));
	//Intializing the environment for sockaddr structure
	var.sin_family=AF_INET;
	var.sin_port=htons(PORT);
	var.sin_addr.s_addr=inet_addr("127.0.0.1");
	//var.sin_addr.s_addr = INADDR_ANY;
	cret=connect(ret,(struct sockaddr*) &var,sizeof(var));
	if(cret < 0)
	{
		printf("Failed to connect\n");
		exit(1);
	}
	while(1)
	{
		printf("Connection is succesfull\n");
		scanf("%[^\n]",buf);
		__fpurge(stdin);
		lret=send(ret,buf,strlen(buf),0);
		lret=recv(ret,buf,100,0);
		//write(1,buf,100);
	}










}


