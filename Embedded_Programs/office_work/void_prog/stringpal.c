
#include<stdio.h>
#include <stdlib.h>
char copy1[100];
char copy2[100];
int p,a;
char* mystringcopy(char* copy2,char* copy1);
int mystringlen(char* copy3);
char* mystringrev(char* copy4);
int mystringcmp(char* copy5,char* copy6);
char* stringcon(char* copy7,char* copy8);
int main()
{
	int i,prog,l,k;
	while(1)
	{

		printf("\tMenu\n");
		printf("------------------------Select the below options--------\n");
		printf("1.palindrome number\n2.String concatenation\n3.String reverse\n4.String compare\n");
		scanf("%d",&prog);
		switch(prog)
		{
			case 0:
				exit(0);


			case 1:

				printf("enter the string to check palindrome or not\n");
				scanf("%s",copy1);
				void*copyptr;
				copyptr=mystringcopy;
				((char*(*)(char*,char*))copyptr)(copy2,copy1);
				void *lengthptr;
				lengthptr=mystringlen;
				p=((int(*)(char*))lengthptr)(copy1);
				//p=mystringlen(copy1);
				void *reverseptr;
				reverseptr=mystringrev;
				((char*(*)(char*))reverseptr)(copy1);
				//mystringrev(copy1);
				void *compareptr;
				compareptr=mystringcmp;
				a=((char*(*)(char*,char*))compareptr)(copy1,copy2);

				//a=mystringcmp(copy1,copy2);
				if(a==0)
					printf("Palindrome ---------string\n");
				else
					printf("Not a palindrome\n");



				break;



			case 2:
				printf("Enter the value to check the string the concetami\n");
				scanf("%s",copy1);
				__fpurge(stdin);
				scanf("%s",copy2);
				stringcon(copy1,copy2);
				printf("%s",copy1);
				
				break;

			case 3:
				printf("enter the value to reverse the string\n");
				scanf("%s",copy1);
				mystringrev(copy1);
				printf("%s\n",copy1);
				break;

			case 4:
				printf("enter the strings to compare\n");
				scanf("%s",copy1);
				__fpurge(stdin);
				scanf("%s",copy2);
				k=mystringcmp(copy1,copy2);
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
	return;
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
	for(i=0,k=k-1;i<k;i++,k--)
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
	printf("%s--------%s\n",copy5,copy6);
	if((copy5==NULL) || (copy6==NULL))
	return;
	for(i=0;((copy5[i]!='\0') || (copy6[i]!='\0'));i++)
	{
		if(copy5[i]!=copy6[i])
			return -1;
	}
	return 0;
}
char* stringcon(char* copy7,char* copy8)
{
	int i,v,k=0;
	printf("%s--------%s\n",copy7,copy8);
	v=mystringlen(copy7);
	printf("%d\n",v);
	for(i=v;copy8[k]!='\0';i++)
	{
		copy7[i]=copy8[k];
		k++;
	}
	copy7[i]='\0';
	printf("inner function def:---%s\n",copy7);
	return copy7;
}


	


	

			
