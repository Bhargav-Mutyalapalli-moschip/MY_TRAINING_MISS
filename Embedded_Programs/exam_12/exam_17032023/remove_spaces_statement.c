#include<stdio.h>
int main()
{
        char arr1[100],i,j,count=0;
        printf("enter the statement :");
        scanf("%[^\n]s",arr1);
        for(i=0,j=0;arr1[i]!='\0';i++)
        {
                if(arr1[i]==' ')
                        count++;
                if(arr1[i]!=' ')
                        count=0;
                if(count>1)
                        continue;
                arr1[j]=arr1[i];
                j++;
        }
        arr1[j]='\0';
        printf("\n\nthe string is :%s\n",arr1);
}
