
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ROW 5
#define COL 50
void read_input(char(*str)[1]);
void search(char(*str1)[COL],char *str2);
void sorting(char(*str)[COL]);
void display_output(char(*str)[COL]);
void stringswap(char *str1,char *str2);
//void sorting(char(*str)[COL]);
int main()
{

	char(*str)[]=(char(*)[])malloc(ROW*1*sizeof(char));

	char str1[100];
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
				//display_output(str);
				break;

			case 3:
				printf("Sorting an character array\n");
				//sorting(str);
				//display_output(str);
				break;
			case 4:
				printf("search operation\n");
		}
	}
}
void read_input(char(*str)[1])
{
	int i,j;
	for(i=0;i<1;i++)
	{
		scanf("%s",str[i]);
		j=strlen(str[i]);
		char(*str)[]=(char(*)[])realloc(str,j*sizeof(char));

	}
}





















