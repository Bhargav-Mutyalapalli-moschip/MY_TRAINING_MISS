#include<stdio.h>
int main()
{
        char arr[100];
        char str1[100];
        scanf("%[^\n]",arr);
        int i,j=0,count=0,k;
        for(i=0;arr[i]!='\0';i++)
        {
                if(arr[i]==' ')
                        count++;
		else
			count=0;
                if(count>1)
		continue;
		arr[j]=arr[i];
		j++;
                     
        }
	arr[j]='\0';
        printf("%s\n",arr);
}
