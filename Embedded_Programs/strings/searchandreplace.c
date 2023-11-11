#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void replaceWordInText(char *str,char *s,char *r)
{
   int i = 0, c = 0;
   int lenr = strlen(r);
   int lens = strlen(s);
   for (i = 0; str[i] != '\0'; i++) {
      if (strstr(&str[i], s) == &str[i]) {
         c++;
         i += lens - 1;
      }
   }
   char *str1 = (char *)malloc(i + c * (lenr - lens) + 1);
   i = 0;
   while (*str) {
      if (strstr(str, s) == str) {
         strcpy(&str1[i], r);
         i += lenr;
         str += lens;
      }
      else
      str1[i++] = *str++;
   }
   printf("%s\n", str1);
}
int main() {
   char str[1000];
   scanf("%[^\n]",str);
   char s[20];
   scanf("%s",s);
   char r[20];
   scanf("%s",r);
   char *result = NULL;
   printf("%s\n", str);
   replaceWordInText(str,s,r);
   return 0;
}
