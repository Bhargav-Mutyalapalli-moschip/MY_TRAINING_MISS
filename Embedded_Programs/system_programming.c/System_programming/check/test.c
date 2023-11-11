#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
struct details
{
	int a;
	char c;
	float d;
};
struct details2
{
	int a1;
	char c1;
	float d1;
};

int main()
{
	char buff[100];
	int fd,ret;
	struct details var;
	struct details2 var1;
	var.a=10;
	var.c='a';
	var.d=123.546;
	fd=open("normal.txt",O_CREAT|O_RDWR | O_TRUNC ,0777);
	 /*write(fd,&var.a,(sizeof(int)));
	 write(fd,&var.c,(sizeof(char)));
	 write(fd,&var.d,(sizeof(float)));*/
	 write(fd,&var,sizeof(var));
	/*lseek(fd,0,SEEK_SET);
	ret=read(fd,buff,(sizeof(int)+sizeof(char)+1+sizeof(float)));
	//buff[ret]='\0';
	printf("The description:%d\n",((int *)buff)[0]);
	printf("The description:%c\n",((char *)buff)[1]);
	printf("The description:%lf\n",((float *)buff)[2]);*/
	lseek(fd,0,SEEK_SET);
	ret=read(fd,&var1,sizeof(var1));
	/*ret=read(fd,&var1,(sizeof(int)+sizeof(char)+1+sizeof(float)));*/
	printf("The description:%d\n",var1.a1);
	printf("The description:%c\n",var1.c1);
	printf("The description:%f\n",var1.d1);
	


}
	
