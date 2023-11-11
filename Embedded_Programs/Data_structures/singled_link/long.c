#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* test(char* text) {
         if(!text[0])
     return "No string found";
   char *text_pt = text;
         char *sub_start = text;
   char *start_pos;
         char *end_pos;
   int max_length = 1;
   while(*text_pt){
       start_pos = text_pt;
                  end_pos = text_pt;       while(*(end_pos+1) && *(end_pos+1) == *end_pos){
           end_pos++;
       }
       text_pt = end_pos + 1;       while(*(end_pos + 1) && (start_pos > text) && *(end_pos + 1) == *(start_pos - 1)){
           start_pos--;
           end_pos++;
       }
       if(end_pos - start_pos + 1 > max_length){
           max_length = end_pos - start_pos + 1;
           sub_start = start_pos;
       }
   }   char *result = (char *) calloc(max_length + 1, sizeof(char));
   strncpy(result, sub_start, max_length);
   return result;
}
int main() {
 //char text[50] = "abcdcsd";
 char text[50] = "abcdcsdfabbccb";
 //char text[50] = "";
 printf("Original string: %s",text);
 printf("\nLongest Palindromic Substring from the said string? %s ",test(text));
}

