#include<stdio.h>
#define NM 5
void inttoascii()
{
	int i,temp,*ptr;
	int a[NM];
	ptr=&a;
	printf("enter the elements");
	for(i=0;i<4;i++)
	scanf("%d",&a[i]);
	for(i=0;i<4;i++)
	{
	printf("%c\n",ptr[i]+48);
	}}
void palindrome(char *ptr2)
{      int a,i,l,temp,count,stat;
	 char*ptr1;
	ptr1=mystrcpy(ptr1,ptr2);
	l=strlen(ptr2);
		for(i=0,l=l-1;i<l;i++,l--)
		{
			temp=ptr1[i];
			ptr1[i]=ptr1[l];
			ptr1[l]=temp;
		}
		stat=mystrcmp(ptr1,ptr2);
		if(stat==0)
			printf("its a palindrome");
		else
			printf("not a palindrome");
}

char* mystrcpy(char* ptr5,char* ptr6)
{
	int i;
	for(i=0;ptr6[i]!='\0';i++)
		ptr5[i]=ptr6[i];
	if(ptr5[i]=='\0')
		return ptr5;
}
int strlen(char*ptr1)
	{int count,i; 
		for(i=0;ptr1[i]!='\0';i++)
		{
			count++;
		}
		return count;
	}
int mystrcmp(int*ptr1,int*ptr2)
{int i;
	for(i=0;ptr2[i]='\0';i++)
		if(ptr1[i]!=ptr2[i])
	return 1;
		else
			return 0;
}

 void main()
{
	char arr[200],i;
	printf("enter the string");
	scanf("%s",arr);
	palindrome(arr);

}
