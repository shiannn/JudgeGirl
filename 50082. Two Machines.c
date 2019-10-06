#include <stdio.h>

int main(){
    int arrive,onA,onB;
    int Aready = 0,Bready = 0;
    while(scanf("%d%d%d",&arrive,&onA,&onB)!=EOF){
        if(arrive >= Aready)Aready = arrive + onA;
        else Aready += onA;
        if(Aready >= Bready)Bready = Aready+onB;
        else Bready = Bready+onB;
        printf("%d\n",Bready);
    }
}