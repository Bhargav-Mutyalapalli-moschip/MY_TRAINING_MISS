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
	int i,opt=1;
	fd_set fr,fw,fe;
	struct sockaddr_in var,client;
	struct timeval tv;
	char buff[100];
	//Intialize the WSA variables
	//set of functions nothing but the environment (API's the socket programming on your laptop
	int ret,bret=0,lret,client_size,newfd;
	ret=socket(AF_PACKET,RAW_SOCKET,IPPROTO_TCP);
	if(ret < 0)
	{
		printf("Failed to open the socket\n");
		exit(1);
	}
	printf("Successfully socket is opened\n");
	printf("The socket id:%d\n",ret);
	memset(&var,0,sizeof(var));
	var.sin_family=AF_INET;
	var.sin_port=htons(PORT);
	var.sin_addr.s_addr = INADDR_ANY;
	setsockopt(ret, SOL_SOCKET,SO_REUSEADDR | SO_REUSEPORT, &opt,sizeof(opt));
	bret=bind(ret, (struct sockaddr*)&var , sizeof(struct sockaddr));
	if(bret <0)
	{
		printf("Failed to bind\n");
		exit(1);
	}
	printf("The bret:%d\n",bret);
	lret=listen(ret,5);
	if(lret < 0)
	{
		printf("Failed to listen\n");
		exit(1);
	}
	printf("The lret:%d\n",lret);
	client_size=sizeof(client);
	newfd=accept(ret,(struct sockaddr *)&client,&client_size);
	while(1)
	{
		lret=read(newfd,buff,100);
		write(1,buff,lret);
		scanf("%[^\n]",buff);
		__fpurge(stdin);
		lret=write(newfd,buff,strlen(buff));
	}
}












