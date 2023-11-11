#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<stdio_ext.h>
char copy1[100];
char copy2[100];
char* mystringcopy(char* copy2,char* copy1);
int mystringlen(char* copy3);
char* mystringrev(char* copy4);
int mystringcmp(char* copy5,char* copy6);
int main()
{
	int i,prog,l,k;
	while(1)
	{

		printf("\tMenu\n");
		printf("------------------------Select the below options--------\n");
		printf("1.String copy\n2.String length\n3.String reverse\n4.String compare\n");
		scanf("%d",&prog);
		switch(prog)
		{
			case 0:
				exit(0);


			case 1:

				printf("enter the string to copy\n");
				scanf("%s",copy1);
				char*(*copyptr)(char* copy1,char* copy2);
				copyptr=mystringcopy;
				copyptr(copy2,copy1);
				printf("%s----------%s\n",copy1,copy2);
				break;



			case 2:
				printf("Enter the value to check the length\n");
				scanf("%s",copy1);
				int (*lengthptr)(char* copy1);
				lengthptr=mystringlen;
				i=lengthptr(copy1);
				//i=mystringlen(copy1);
				printf("%d\n",i);
				break;

			case 3:
				printf("enter the value to reverse the string\n");
				scanf("%s",copy1);
				char* (*reverseptr)(char* copy1);
				reverseptr=mystringrev;
				reverseptr(copy1);
				//mystringrev(copy1);
				printf("%s\n",copy1);
				break;

			case 4:
				printf("enter the strings to compare\n");
				scanf("%s",copy1);
				__fpurge(stdin);
				scanf("%s",copy2);
				char* (*compareptr)(char*copy1,char*copy2);
				compareptr=mystringcmp;
                                k=compareptr(copy1,copy2);
				//k=mystringcmp(copy1,copy2);
				if(k==0)
					printf("same string\n");
				else
					printf("Not a same string\n");
				break;
		}














	}
}
char* mystringcopy(char* copy2,char* copy1)
{
	printf("%s----------%s\n",copy1,copy2);
	int i;
	for(i=0;copy1[i]!='\0';i++)
	{
		copy2[i]=copy1[i];
	}
	copy2[i]='\0';
	return copy2;
}
int mystringlen(char* copy3)
{
	int i,length=0;
	//printf("%d\n",i);
	for(i=0;copy3[i]!='\0';i++)
	{
		length++;
	}
	return length;
}
char* mystringrev(char* copy4)
{
	int i,k,j;
	char temp;
	if(copy4==NULL)
		return;
	k=mystringlen(copy4);
	for(i=0,k=k-1;i<=k;i++,k--)
	{
		temp=copy4[i];
		copy4[i]=copy4[k];
		copy4[k]=temp;
	}
	return copy4;
}
int mystringcmp(char* copy5,char* copy6)
{
	int i;
	if((copy5==NULL) || (copy6==NULL))
	return;
	for(i=0;((copy5[i]!='\0') || (copy6[i]!='\0'));i++)
	{
		if(copy5[i]!=copy6[i])
			return -1;
	}
	return 0;
}



	


	

			
