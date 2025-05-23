#include <stdio.h>
#include <stdlib.h>
int get_1st_weekday(int year){

    int d;
    d=(((year-1)*365)+((year-1)/4)-((year-1)/100)+((year)/400)+1)%7;
    return d;
}
int main()
{
    system("Color 3F");
    int year, month, day, daysInMonth, weekDay=0, startingDay;
    printf("\nEnter your desired year:");
    scanf("%d", &year);

    char *months[]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int monthDay[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if((year%4==0&&year%100!=0)||year%400==0)
        monthDay[1]=29;

    startingDay=get_1st_weekday(year);

    for(month=0;month<12;month++){

        daysInMonth=monthDay[month];
        printf("\n\n------------%s------------\n",months[month]);
        printf("\n  Sun  Mon  Tue  Wed  Thurs  Fri Sat\n");

        for(weekDay=0;weekDay<startingDay;weekDay++)
            printf("      ");

        for(day=1;day<daysInMonth;day++){
            printf("%5d",day);

            if(++weekDay>6){
                printf("\n");
                weekDay=0;
            }
            startingDay=weekDay;
        }
    }

}
