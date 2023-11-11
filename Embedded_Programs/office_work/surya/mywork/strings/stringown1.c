#include<stdio.h>
char copy1[100];
char copy2[100];
char* mystringcopy(char* copy2,char* copy1);
int main()
{
	printf("Enter the string to copy\n");
	scanf("%s",copy1);
	char*(*copyptr)(char* copy1,char* copy2);
	copyptr=mystringcopy;
	copyptr(copy2,copy1);
	printf("%s----------%s\n",copy1,copy2);
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
	printf("%s-------------%s\n",copy1,copy2);
	return copy2;
}
