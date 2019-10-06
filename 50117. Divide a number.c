#include <stdio.h>

int main(){
    int k,digits,toCal,pre=0;
    scanf("%d",&k);
    int flag = 0;
    while(scanf("%d",&digits)!=EOF){
        toCal = 10*pre + digits;
        if(k <= toCal){
            printf("%d\n",toCal/k);
            flag = 1;
            pre = toCal % k;
        }
        else{
            if(flag == 1)printf("%d\n",toCal/k);
            pre = toCal;
        }
    }
    if(flag == 0){
        printf("0\n");
    }
}