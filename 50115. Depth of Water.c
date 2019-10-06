#include <stdio.h>

int main(){
    int a,b,h,c,d;
    scanf("%d%d%d%d%d",&a,&b,&h,&c,&d);
    int waterVolume = a*b*h;
    int newHeight = waterVolume/(a*b-c*d);
    printf("%d\n",newHeight);
    return 0;
}