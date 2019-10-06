#include <stdio.h>

int main(){
    int a,b,c,d,e,f,g;
    scanf("%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g);
    int volumeWater = a*b*d;
    int volumeBlock;
    if(g > c)volumeBlock = e*f*c;
    else volumeBlock = e*f*g;
    int delta = volumeBlock / (a*b);
    if(d == 0){
        printf("0\n");
        return 0;
    }
    else{
        d += delta;
        if(e*f < a*b){
            if(d > c)d = c;
        }
        else if(e*f == a*b){
            if(g >= c)d = 0;
            else{
                if(d > c)d = c;
            }
        }
        printf("%d\n",d);
    }
}