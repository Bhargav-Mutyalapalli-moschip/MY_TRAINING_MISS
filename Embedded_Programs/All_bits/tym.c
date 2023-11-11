#include <stdio.h>
#include <time.h>

typedef struct date Date;
typedef struct hour Hour;

struct hour{

    int hour;
    int minute;
    int second;

};

struct date{

    int day;
    int month;
    int year;
    Hour hour;

};

int main (void) {

    Date date;

    //char buff[100];
    time_t now = time(0);    
    strftime (&date, 100, "%d-%m-%Y %H:%M:%S", localtime(&now));
    printf ("%d-----%m-----%Y----%H\n", date.day,date.month,date.year,date.hour);
}
