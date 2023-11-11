#include<string.h>
#include<stdio.h>
int main()
{
	int count;
	char arr[20];
	printf("Enter the string\n");
	scanf("%[^\n]",arr);
	words(arr);
}
void words(char *ptr)
{
	char rep;
	int count=0,prev=1,output,l,i,j;
	l=strlen(ptr);
	//l=l-1;
	for(i=0;i<l;i++)
	{
		for(j=i+1;j<l;j++)
		{
			if(ptr[i] == ptr[j])
			{
				count++;
			
			if(count >= prev)
			
				printf("Hii\n");
				rep = ptr[i];
				output=count;
				prev=count;
			}
		}
		count=0;
	}
	printf("The %c---%d\n",rep,output);
}


