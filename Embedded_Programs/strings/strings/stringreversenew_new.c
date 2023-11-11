#include<stdio.h>
void reverse_string(char str[], int i, int j)
{
    char temp;
    while(i<j)
    {
	printf("ENtered\n");
	printf("%d--------%d\n",i,j);
        temp=str[i];
        str[i]=str[j];
        str[j]=temp;
        i++;
        j--;
    }
}
int main()
{
    char str[1000];
    printf("Enter the string\n");
    scanf("%[^\n]",str);
    int i, j,mainlength;
    j=0;
    i=0;
    mainlength=strlen(str);
    //str[mainlength]='#';
    //str[mainlength+1]='\0';
    printf("%s",str);

    while(str[j])
    {
        for(j=i;str[j]&&str[j]!=' ';j++);
        reverse_string(str, i, j-1);
        i=j+1;
    }
        printf("%s ",str);
    return 0;
}
