#include<stdio.h>
#include<stdlib.h>
int main()
{
       char ch;
       FILE *fp;
       fp=fopen("sample.txt","r");
       if(fp==NULL)
       {
	       printf("Failed to open\n");
	       exit(1);
       }
       while(1)
       {
	       ch=fgetc(fp);
	       printf("%d---",ch);
	       if(ch == EOF)
	       break;
	       printf("\t%c\n",ch);
       }
}




