#include <stdio.h>

int main(){
    double a,b,c;
    scanf("%lf%lf%lf",&a,&b,&c);
    double area = 3.1415926*c*c*3.0/4.0;
    double remain;
    if(c>b){
        remain = c-b;
        area += 3.1415926*remain*remain*1.0/4.0;
    }
    if(c>a){
        remain = c-a;
        area += 3.1415926*remain*remain*1.0/4.0;
    }
    printf("%lf\n",area);
}