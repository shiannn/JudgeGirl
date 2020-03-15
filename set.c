#include <stdio.h>
#include <stdbool.h>
#include "set.h"
 
void initializeSet(Set* set, int numberOfElement){
    set -> a = 0;
    set -> Num = numberOfElement;
    return;
}
bool intersect(Set set1, Set set2){
    if((set1.a & set2.a) == 0){
        return false;
    }
    else{
        return true;
    }
}
void addElement(Set* set, int element){
    long long int mask = ((long long int)1)<<(element-1);
    set -> a = set->a | mask;
}
void removeElement(Set* set, int element){
    long long int mask = ((long long int)1)<<(element-1);
    mask = ~mask;
    set -> a = set->a & mask;
}
void printSet(Set set){
    int fs = 0;
    for(int i=1;i<=set.Num;i++){
        int mask = ((long long int)1)<<(i-1);
        if((set.a & mask) != 0){
            if(fs == 1)printf(" ");
            printf("%d",i);
            fs = 1;
        }
    }
}