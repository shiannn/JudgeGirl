#include <stdio.h>
#include <string.h>

char number[10000];
int main(){
    //記住global max 和 current max
    //current max在無法connect時可能歸0重新計
    int globalMax = 0, currentMax = 0;
    int prev = -1;
    while(scanf("%s",number)!=EOF){
        int N = strlen(number);
        if(number[0] == prev){
            currentMax += N;
        }
        else{
            currentMax = N;
        }
        if(currentMax > globalMax)globalMax = currentMax;
        prev = number[N-1];
        memset(number,0,10000);
    }
    printf("%d\n",globalMax);
}