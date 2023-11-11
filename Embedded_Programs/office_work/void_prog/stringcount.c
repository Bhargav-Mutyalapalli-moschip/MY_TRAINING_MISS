#include<stdio.h>
void string_count(char*);
int main()
{
	char arr[100];
	scanf("%s",arr);
	void *countptr;
	countptr=string_count;
	((void(*)(char*))countptr)(arr);
}
void string_count(char* arr)
{

	char i,k=0,count=0,j;
	for(j=0;arr[j]!='\0';j++)
	{
		if(arr[j]==1)
			continue;
		count=0;
		for(i='0';i<='z';i++)
		{
			if(arr[j]==i)
			{
				count++;
				for(k=j+1;arr[k]!='\0';k++)
				{
					if(arr[j]==arr[k]){
						count++;
						arr[k]=1;
						


					}
				}
				printf("%c---------%d\n",i,count);
			}
		}
	}
}


