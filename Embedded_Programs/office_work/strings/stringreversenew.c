#include<stdio.h>
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
	char temp;
	j=j-1;
	while(i<j)
	{
		printf("ENtered\n");
		printf("The inner loop:====%d--------%d\n",i,j);
		temp=str[i];
		str[i]=str[j];
		str[j]=temp;
		i++;
		j--;
	}
	printf("The i value%d\n",i);
	i=j+1;
    }
    printf("%s ",str);
    return 0;
}
