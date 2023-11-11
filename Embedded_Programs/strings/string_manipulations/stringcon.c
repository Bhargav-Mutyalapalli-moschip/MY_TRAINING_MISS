#include<stdio.h>
int main()
{
	char main[100];
	char add[20];
	printf("enter main string\n");
	scanf("%s",main);
	printf("enter the add string\n");
	scanf("%s",add);
	int mleng,aleng;
	mleng=strlen(main);
	aleng=strlen(add);
	printf("The main string length------%d----The add string length----%d\n",mleng,aleng);
	int i,k=mleng+aleng;
	for(i=0;add[i]!='\0';i++,k--)
	{
		main[k]=add[i];
	}
	main[mleng]=' ';
	printf("After adding the string----%s\n",main);
}
