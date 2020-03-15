#include <stdio.h>
#include "set.h"

Set setArray[105];
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<105;i++){
        initializeSet(&setArray[i],n);
    }
    for(int i=0;i<k;i++){
        int temp;
        scanf("%d",&temp);
        for(int j=0;j<temp;j++){
            int element;
            scanf("%d",&element);
            addElement(&setArray[i], element);
        }
    }
#ifdef debug
    for(int i=0;i<k;i++){
        printSet(setArray[i]);
    }
#endif

    Set Try;
    long long int Total = 1;//2^n
    for(int i=0;i<n;i++){
        Total *= 2;
    }
/*
    for(int i=0;i<Total;i++){
        initializeSet(&Try,n);
        //printf("i == %d\n",i);
        long long int temp;
        for(int j=0;j<n;j++){
            temp = (long long int)1 << j;
            if((i & temp) != 0)addElement(&Try, j+1);
        }
        printSet(Try);
        printf("\n");
    }
    return 0;
*/
void printBit(int n,int i){
    for(int j=n-1;j>=0;j--){
        long long int temp;
        temp = (long long int)1 << j;
        int bit = i & temp;
        if(bit != 0){
            printf("1 ");
        }
        else{
            printf("0 ");
        }
    }
}
for(int i=0;i<Total;i++){
    initializeSet(&Try,n);
    printBit(n,i);
    for(int j=0;j<=(n-1);j++){
        long long int temp;
        temp = (long long int)1 << j;
        int bit = i & temp;
        if(bit != 0){
            addElement(&Try, n-j);
        }
    }
    printf("\n");
    printSet(Try);
    printf("\n");
}

printf("--------------------------\n");
for(int i=Total-1;i>=0;i--){
    initializeSet(&Try,n);
    printBit(n,i);
    for(int j=0;j<=(n-1);j++){
        long long int temp;
        temp = (long long int)1 << j;
        int bit = i & temp;
        if(bit != 0){
            addElement(&Try, n-j);
        }
    }
    printf("\n");
    printSet(Try);
    printf("\n");
}
}