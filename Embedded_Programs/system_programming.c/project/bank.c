#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<stdio_ext.h>
#include<fcntl.h>
#include<dirent.h>
struct register_data
{
	char name[200];
	char user_id[100];
	long int mob_no;
	long int aadhar_no;
	unsigned long int passwd;
};
int register_acc();
int directory_check(char *str);
int digit_count(long int mob,int fix);
void login_credition();
int main()
{
	int prog;
	while(1)
	{
		printf("1.Register\n2.Login\n3.Logout\n");
		scanf("%d",&prog);
		__fpurge(stdin);
		switch(prog)
		{
			case 1:
				printf("Register is starting\n");
				register_acc();
				break;

			case 2:
				printf("Logging\n");
				login_credition();
				break;

		}
	}
}
int register_acc()
{
	char *str;
	int ret,fd;
	struct register_data reg;
	printf("Enter the user name\n");
	scanf("%[^\n]",reg.name);
	__fpurge(stdin);
	printf("Enter the user id\n");
	scanf("%[^\n]",reg.user_id);
	__fpurge(stdin);
	ret=directory_check(reg.user_id);
	if(ret < 0)
	{
		printf("Userid is already exist\n");
		return 0;
	}
	printf("Enter the mobile number\n");
	scanf("%ld",&reg.mob_no);
	__fpurge(stdin);
	ret=digit_count(reg.mob_no,10);
	if(ret < 0)
	{
		printf("Please enter 10digits mobile number\n");
		return 0;
	}
	printf("Enter the aadhar number\n");
	scanf("%ld",&reg.aadhar_no);
	ret=digit_count(reg.aadhar_no,12);
	if(ret < 0)
	{
		printf("Please enter 12 digits mobile number\n");
		return 0;
	}

	__fpurge(stdin);
	printf("Enter the passwd\n");
	scanf("%ld",&reg.passwd);
	__fpurge(stdin);
	ret=digit_count(reg.passwd,8);
	if(ret < 0)
	{
		printf("Please enter 8 digits number\n");
		return 0;
	}

	str=reg.user_id;
	printf("The str:%s\n",str);
	fd=open(str, O_CREAT | O_RDWR ,0777);
	if(fd < 0)
	{
		printf("Failed to open\n");
		exit(1);
	}
	ret=write(fd,&reg,sizeof(reg));
	if(ret < 0)
	{
		printf("Failed to write\n");
		exit(1);
	}
	printf("The name:%s\n",reg.name);
        printf("The user id:%s\n",reg.user_id);
        printf("The out:%ld\n",reg.mob_no);
        printf("The aadhar:%ld\n",reg.aadhar_no);

	//close(fd);

}
int directory_check(char *str)
{
	DIR *d;
	struct dirent *dir;
	d=opendir(".");
	if(d)
	{
		while((dir=readdir(d))!=NULL)
		{
			if(strcmp(str,dir->d_name)==0)
			{
				printf("Found\n");
				return -1;
			}
		}
		closedir(d);
	}
	return 0;
}
int digit_count(long int mob,int fix)
{
	int sum=0;
	long int temp=mob;
	while(temp!=0)
	{
		sum++;
		temp=temp/10;
	}
	printf("The sum:%d\n",sum);
	if(fix == 8)
	{
		if(sum >=8)
		return 0;
		else
			return -1;
	}
	if(sum > fix)
	return -1;
	else if(sum==fix)
	return 0;
	else
	return -1;
	
}
void login_credition()
{
	int i,fd,ret;
	struct register_data var,check;
	printf("Enter the user id\n");
	scanf("%[^\n]",var.user_id);
	__fpurge(stdin);
	i=directory_check(var.user_id);
	if(i!=-1)
	{
		printf("we cant find this user id please register\n");
		exit(1);
	}
	printf("Enter the passwd\n");
	scanf("%lu",&var.passwd);
	__fpurge(stdin);
	ret=digit_count(var.passwd,8);
	if(ret < 0)
	{
		printf("Please enter 8 digits number\n");
		return;
	}
	fd=open(var.user_id,O_RDONLY);
	ret=read(fd,&check,sizeof(check));
	if(check.passwd != var.passwd)
	{
		printf("Please enter correct password\n");
		exit(1);
	}
	close(fd);
}




	







