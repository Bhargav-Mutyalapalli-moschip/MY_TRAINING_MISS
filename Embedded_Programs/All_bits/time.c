#include <stdio.h>
#include <time.h>
int main () 
{
   struct tm *localtime(const time_t *timer)
   char arr[20];
   time_t rawtime;
   struct tm *info;
   time( &rawtime );
   info = localtime( &rawtime );
   void *ptr=info;
   printf("Current local time and date: %s", asctime(info));
   printf("Current local time and date: %s", (char *)ptr);
   printf("Current local time and date: %s", info);
   return(0);
   printf("The totol sec:%d\n",
}
