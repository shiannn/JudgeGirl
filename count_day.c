#include <stdio.h>
int day_of_month[15]={
    100,31,28,31,30,31,30,31,31,30,31,30,31
};

void count_day(int year, int day, int month, int results[7]){
    // 1/1 是 day 求說 month 的每一天有幾次
    // 先算出 month 的第1天是星期幾
    // 閏年
    day_of_month[2] = 28;
    if(year % 4 == 0){
        if(year % 100 ==0){
            if(year % 400 ==0){
                day_of_month[2] = 29;   
            }
        }
        else{
            day_of_month[2] = 29;
        }
    }
    
    int month_first = day;
    for(int i=1;i<=12;i++){
        //printf("month:%d day:%d\n",i,day_of_month[i]);
        //printf("month_first == %d\n",month_first);
        if(i == month){
            for(int j=1;j<=day_of_month[i];j++){
                month_first %= 7;
                //printf("month_first == %d\n",month_first);
                results[month_first] += 1;
                month_first += 1;
                month_first %= 7;
            }
            break;
        }
        else{
            // %7
            month_first += day_of_month[i];
            month_first %= 7;
        }
    }
    return;
}