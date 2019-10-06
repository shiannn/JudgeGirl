#include <stdio.h>
#include "book.h"
#include "date.h"
 
unsigned int getImportance(struct Book book){
    unsigned int myImp = book.importance;
    unsigned int i1=100,i2=100;
    for(int i=0;i<32;i++){
        unsigned int mask= 1 << i;
        if((mask & myImp) != 0){
            if(i1==100)i1=i;
            else i2=i;
        }
    }
    unsigned int zeros = i2 - i1 - 1;
    return zeros;
}
unsigned int getDays(struct Date date_borrowed, struct Date date_returned){
    unsigned int myDay,myMonth,myYear;
    unsigned int startMonth,endMonth,startDay,endDay;
    unsigned int countDays=0;
    for(myYear=date_borrowed.year;myYear<=date_returned.year;myYear++){
        if(myYear==date_borrowed.year)startMonth = date_borrowed.month;
        else startMonth = 1;
        if(myYear==date_returned.year)endMonth = date_returned.month;
        else endMonth = 12;
        for(myMonth=startMonth;myMonth<=endMonth;myMonth++){
            if(myYear==date_borrowed.year && myMonth==date_borrowed.month)startDay = date_borrowed.day;
            else startDay = 1;
            if(myYear==date_returned.year && myMonth==date_returned.month)endDay = date_returned.day;
            else{
                if(myMonth==1||myMonth==3||myMonth==5||myMonth==7||myMonth==8||myMonth==10||myMonth==12){
                    endDay = 31;    
                }
                else if(myMonth==4||myMonth==6||myMonth==9||myMonth==11){
                    endDay = 30;
                }
                else{//Feb
                    if(myYear%4==0){
                        if(myYear%100!=0){
                            endDay=29;
                        }
                        else{
                            if(myYear%400==0){
                                endDay=29;
                            }
                            else{
                                endDay=28;
                            }
                        }
                    }
                    else{
                        endDay=28;
                    }
                }
            }
            for(myDay=startDay;myDay<=endDay;myDay++){
                //printf("%u/%u/%u\n",myYear,myMonth,myDay);
                countDays += 1;
            }    
        }    
    }
    return countDays;
}
unsigned int library_fine(struct Book book, struct Date date_borrowed, struct Date date_returned){
    //get importance
    unsigned int zeros = getImportance(book);
    //printf("zeros == %d\n",zeros);
    //get days
    unsigned int days = getDays(date_borrowed,date_returned);
    //printf("zeros==%d days==%d\n",zeros,days);
    unsigned int available;
    if(book.type == NOVEL)available=90;
    if(book.type == COMICS)available=10;
    if(book.type == MANUAL)available=100;
    if(book.type == TEXTBOOK)available=5;
    //printf("days==%u\n",days);
    unsigned int fine = 0;
    //printf("ava==%u\n",available);
    if(days > available){
        fine= (days - available)*zeros;
    }
    
    return fine;
}
 
int main(){
    struct Book book = {
        "Neon Genesis Evangelion",
        COMICS,
        "978-159-116-400-5",
        "Yoshiyuki Sadamoto",
        17
    };
    struct Date date_borrowed, date_returned;
    date_borrowed.year  = 2007;
    date_borrowed.month = 11;
    date_borrowed.day   = 14;
    date_returned.year  = 2007;
    date_returned.month = 11;
    date_returned.day   = 14;
    printf("The fine is $%d.\n", library_fine(book, date_borrowed, date_returned));
    return 0;
}