#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i=0;
       char ch;
       char buff[100];
       FILE *fp;
       fp=fopen("sample.txt","r");
       if(fp==NULL)
       {
	       printf("Failed to open\n");
	       exit(1);
       }
       printf("The address:%p\n",fp);
       while(1)
       {

	       ch=fscanf(fp,"%c",buff);
	       printf("%c\n",buff[i]);
	       if(ch == EOF)
	       break;
	       printf("%c",ch);
	       i++;
       }
}




