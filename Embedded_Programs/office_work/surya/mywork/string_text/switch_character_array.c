#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ROW 5
#define COL 50
void read_input(char *str[]);
void search(char*str[],char *str2);
//void search(char(*str1)[COL],char *str2);
void sorting(char *str[]);
void display_output(char *str[]);
void stringswap(char *str1,char *str2);
//void sorting(char(*str)[COL]);
int main()
{

	char *str[ROW];

	char str1[20];
	int prog;
	while(1)
	{	
		printf(">>>>>>>>>>>>>>>>>>>>>Select the below options<<<<<<<<<<<<<\n");
		printf("0.Exit the program\n1.Read input\n2.Display_output\n3.Sorting the array\n4.Search the string\n");
		scanf("%d",&prog);
		switch(prog)
		{
			case 0:
				printf("Sucessfully executed\n");
				exit(0);




			case 1:
				printf("Read operation\n");
				read_input(str);
				break;

			case 2:
				printf("Display operation\n");
				display_output(str);
				break;

			case 3:
				printf("Sorting an character array\n");
				sorting(str);
				display_output(str);
				break;
			case 4:
				printf("search operation\n");
				scanf("%s",str1);
				search(str,str1);
				break;
		}

	}
}
void read_input(char *str[])
{
//	str=(char **)malloc(ROW*sizeof(char*));
	char*ptr;
	int i,j,n=0;
        for(i=0;i<ROW;i++)
	{
	        ptr=(char *)malloc(20*sizeof(char));
		scanf("%s",ptr);
		n=strlen(ptr);
		ptr=(char*)realloc(ptr,n*sizeof(char));
		if(ptr==NULL)
		{
			printf("Failed\n");
		}
		str[i]=ptr;
		printf("Addre:%p\n",str[i]);
	}

}
void display_output(char*str[])
{
	int i,j,k;
	for(i=0;i<ROW;i++)
	{
		printf("The output:%s\n",str[i]);
	}
}
void sorting(char*str[])
{
	int i=0,j,k=0,p,q,r,s,t;
	char str1[COL];
	char temp;
	int count;
	int count1;
	for(j=0;j<ROW;j++)
	{
		for(i=j+1;i<ROW;i++)
		{
			printf("i:%d\n----j:%d\n",i,j);
			if(str[j][k]>str[i][k])
			{
				stringswap(str[j],str[i]);

			}
			else if(str[j][k]==str[i][k])
			{
				count=strcmp(str[j],str[i]);
				printf("The count:%d\n",count);
				if(count>0)
					stringswap(str[j],str[i]);

			
			}
			
			
		}



	}
}
void stringswap(char *str1,char *str2)
{
	int i,j,p,q,r;
	char temp;
	for(i=0;(str1[i]!='\0' && str2[i]!='\0');i++)
	{
		temp=str1[i];
		str1[i]=str2[i];
		str2[i]=temp;
	}
	if(str2[i]!='\0')
	{
		for(p=i;str2[p]!='\0';p++)
		{

			str1[p]=str2[p];
		}
		str1[p]='\0';
		str2[i]='\0';
	}
	else if(str1[i]!='\0')
	{
		for(q=i;str1[q]!='\0';q++)
		{

			str2[q]=str1[q];
		}
		str1[i]='\0';
		str2[q]='\0';
	}
	else
		str1[i]=str2[i]='\0';

}
void search(char*str1[],char *str2)
{
	int i=0,j,k,count=0;
	for(k=0;k<ROW;k++)
	{
			count=strcmp(str1[k],str2);
			if(count!=0)
			{
				printf("String is not found at row%d\n",k);
			}
			else
				printf("String is found at row%d\n",k);
	}


}

































