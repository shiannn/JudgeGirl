#include <stdio.h>
#include <stdbool.h>

unsigned int InputArray[20010];
char CharSet[40];
int main(){
    int N;
    scanf("%s%d",CharSet,&N);
    for(int i=0;i<N;i++){
        scanf("%ud",&InputArray[i]);
    }
#ifdef debugInput
    printf("%s\n",CharSet);
    printf("%d\n",N);
    for(int i=0;i<N;i++){
        printf("%u ",InputArray[i]);
    }
    printf("\n");
#endif
    int count = 0;
    int putin = 0;
    for(int i=0;i<N;i++){
        for(int j=31;j>=0;j--){
            if((InputArray[i] & (1 << j)) > 0){
                putin = putin*2+1;
            }
            else{
                putin = putin*2;
            }
            if(count%5 == 4){
                //printf("%d ",putin);
                printf("%c",CharSet[putin]);
                putin = 0;
            }
            count += 1;
        }
    }
    printf("\n");
}