#include <stdio.h>
#include <stdlib.h>

int main(){
    int Num,h1,h2;scanf("%d%d%d",&Num,&h1,&h2);
    long long cost = 0;
    cost += (h2>h1)? 3*abs(h1-h2):2*abs(h1-h2);
    for(int i=2;i<Num;i++){
        int h; scanf("%d",&h);
        if(h>h2)cost += (h2>h1)? 4*abs(h-h2):3*abs(h-h2);//uphill
        else    cost += (h2>h1)? 3*abs(h-h2):2*abs(h-h2);//downhill
        h1 = h2, h2 = h;
    }
    printf("%lld\n",cost);
}