#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ROW 5
#define COL 10
void read_input(char(*str)[COL]);
void sorting(char(*str)[COL]);
void display_output(char(*str)[COL]);
void stringswap(char *str1,char *str2);
//void sorting(char(*str)[COL]);
int main()
{

	char str[ROW][COL];

	char str1[100]="pranav";
	char str2[100]="ram";
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
		/*	case 4:
				stringswap(str1,str2);
				printf("%s----------%s\n",str1,str2);*/
		}

	}
}
void read_input(char(*str)[COL])
{
	int i,j,k;
	for(i=0;i<ROW;i++)
	{
		scanf("%s",str[i]);
	}
}
void display_output(char(*str)[COL])
{
	int i,j,k;
	for(i=0;i<ROW;i++)
	{
		printf("%s\n",str[i]);
	}
}
void sorting(char(*str)[COL])
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
			if(str[k][j]<str[i][j])
			{
			        stringswap(str[k],str[i]);
				k++;
			}
		}
	}



		

}
void stringswap(char *str1,char *str2)
{
	int i,j,p,q,r;
	char temp;
	printf("Swaploop\n");
	printf("%s--------------%s\n",str1,str2);
	for(i=0;(str1[i]!='\0' && str2[i]!='\0');i++)
	{
		temp=str1[i];
		str1[i]=str2[i];
		str2[i]=temp;
		printf("temp:%c  -----%s\n",temp,str1);
	}
	printf("i:%d\n",i);
	r=i;
	if(str2[i]!='\0')
	{
		for(p=i;str2[p]!='\0';p++)
		{
			printf("F loop\n");

			str1[p]=str2[p];
		}
		str1[p]='\0';
		str2[i]='\0';
	}
	else if(str1[i]!='\0')
	{
	        printf("s:i:%d\n",i);
		for(q=i;str1[q]!='\0';q++,r++)
		{
			printf("S loop\n");

			str2[q]=str1[q];
			printf("%s-----------",str1);
			printf("The q:%d\n",q);
		}
		printf("I value:%d\n",i);
		str1[i]='\0';
		str2[q]='\0';
	}
	else
		str1[i]=str2[i]='\0';

	printf("The output:%s----------%s\n",str1,str2);
}
































