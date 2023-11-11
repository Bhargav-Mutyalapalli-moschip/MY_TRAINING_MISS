#include<stdio.h>
#include<string.h>
void reverse_str(char str[],int l,int i);
void reverse_word(char str[],int l);
int main()
{
	int l;
	int i=0;
	char str[50];
	printf("Enter the sentence\n");
	scanf("%[^\n]",str);
	l=strlen(str);
	reverse_str(str,l,i);
	reverse_word(str,l);

}

void reverse_str(char str[],int l,int i)
{
	printf("The incoming reverse:%d-------%d\n",i,l);

	int n;
	char temp;
	for(i=0,l=l-1;l>i;l--,i++)
	{
		       temp=str[i];
			str[i]=str[l];
			str[l]=temp;



	}
}
void reverse_word(char str[],int l)
{
	int count=0,i,j;
	static int k;
	printf("The incoming:%s\n",str);
	for(i=0;i<l;i++)
	{
		
		if(str[i]==' ')
		{


	}
	printf("The output string:%s\n",str);
}

		

