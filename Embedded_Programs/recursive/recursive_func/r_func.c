#include<stdio.h>
#include<string.h>
//char *reverse_str(char *str,int l);
void reverse_str(char *str,int k);
int i=0;
int l;
int main()
{
	char str[20];
	scanf("%s",str);
	l=strlen(str);
	printf("the string length:%d",l);
	reverse_str(str,i);
        printf("The ouput string:%s\n",str);
}
void reverse_str(char *str,int k)

{
	//printf("INNER LOOP\ni(%d)",l);
	printf("the string varying length:%d\n",l);
	char var;
	if(k<(l/2))
	{
		printf("%c-----%c\n",str[k],str[l]);
		var=str[(l-1)-k];
		str[(l-1)-k]=str[k];
		str[k]=var;
		printf("%c-----%c\n",str[k],str[l]);
		reverse_str(str,++k);
	}
	
}

