#include<stdio.h>
int main()
{
	int k=0,i;
	char arr[]="santar";
	arr[6]=' ';
	int p=strlen(arr);
	printf("%d\n",p);
	for(i=p-1;i>k;i--)
	{
		arr[i]=arr[i-1];
	}
	arr[k]='B';
	printf("%s",arr);

}
