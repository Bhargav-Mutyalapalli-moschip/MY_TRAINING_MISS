#include<stdio.h>
#include<stdio_ext.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
struct dob
{
	int date;
	int month;
	int year;
};
struct register_data
{
	char user_name[500];
	char user_id[20];
	int passwd;
	unsigned long mob_no;
	unsigned aadhar_no;
	unsigned ac_no;
	struct dob dt;




};
void login_to_account(char *str);
int main()
{
	struct register_data var;
	int fd;
	unsigned long int num;
	scanf("%10lu",&num);
	printf("The num:%lu\n",num);
	/*fd=open("t.txt",O_CREAT | O_RDWR,0777);
	write(fd,&num,8);*/
	strcpy(var.user_name,"pranav");
	strcpy(var.user_id,"f123");
	var.passwd=546;
	var.mob_no=7093614005;
	printf("The out:%s\n",var.user_id);
	fd=open(var.user_id,O_CREAT | O_RDWR | O_TRUNC,0664);
	//rename("data.txt",var.user_id);
	write(fd,&var,sizeof(var));
	close(fd);





	int prog,ret;
	char str[100];
	while(1)
	{
		printf("The Menu---\n");
		printf("0.Exit\n1.Login\n2.Register\n");
		scanf("%d",&prog);
		__fpurge(stdin);
		switch(prog)
		{
			case 0:
				printf("Suucessfully executed by user\n");
				exit(0);

			case 1:
				printf("LOgin\n");
				scanf("%s",str);
				login_to_account(str);
				break;

		}
	}
		

}
void login_to_account(char *str)
{
	int fd;
	fd=open(str,O_RDWR);
	if(fd>0)
	{
		close(fd);
		printf("The file is already exist\n");
		return ;
	}



}
/*int director_check(struct register_data user)
{

	
	DIR *d;
	struct dirent *dir;
	d=opendir(".");
	if(d)
	{
		while((dir=readdir(d))!=NULL)
		{

			if(user.user_id == dir->d_name)
			{
			printf("found\n");
			return 1;
			}


			//printf("The files:%s\n",dir->d_name);
		}
		return -1;
	}
	close(d);
}*/







