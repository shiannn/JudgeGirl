#include <stdio.h>

typedef unsigned long long Set;
void init(Set *set);
void add(Set *set, int i);
void has(Set set, int i);
Set setUnion(Set a, Set b);
Set setIntersect(Set a, Set b);
Set setDifference(Set a, Set b);
void init(Set *set){
    *set = 0;
}
void add(Set *set, int i){
    unsigned long long int mask = (unsigned long long int)1 << i;
    *set |= mask;
}
int myHas(Set set, int i){
    unsigned long long int mask = (unsigned long long int)1 << i;
    if((set & mask) != 0)return 1;
    else return 0;
}
void has(Set set, int i){
    if(myHas(set,i)==1)printf("set has %d\n",i);
    else printf("set does not have %d\n",i);
}
Set setUnion(Set a, Set b){
    Set c;
    init(&c);
    for(int i=0;i<64;i++){
        unsigned long long int mask = (unsigned long long int)1<<i;
        if(myHas(a,i)==1 || myHas(b,i)==1){
            c |= mask;
        }
    }
    return c;
}
Set setIntersect(Set a, Set b){
    Set c;
    init(&c);
    for(int i=0;i<64;i++){
        unsigned long long int mask = (unsigned long long int)1<<i;
        if(myHas(a,i)==1 && myHas(b,i)==1){
            c |= mask;
        }
    }
    return c;
}
Set setDifference(Set a, Set b){
    Set c;
    init(&c);
    for(int i=0;i<64;i++){
        unsigned long long int mask = (unsigned long long int)1<<i;
        if((myHas(a,i)==1 && myHas(b,i)==0) || (myHas(a,i)==0 && myHas(b,i)==1)){
            c |= mask;
        }
    }
    return c;
}
int main(){
    Set a, b, c;
 
    init(&a);
    add(&a, 3);
    add(&a, 5);
    add(&a, 2);
    
    init(&b);
    add(&b, 3);
    add(&b, 7);
    add(&b, 9);
    
    c = setUnion(a, b);
    has(c, 2);
    has(c, 3);
    has(c, 5);
    has(c, 7);
    has(c, 9);
    
    c = setIntersect(a, b);
    has(c, 2);
    has(c, 3);
    has(c, 5);
    has(c, 7);
    has(c, 9);
    
    c = setDifference(a, b);
    has(c, 2);
    has(c, 3);
    has(c, 5);
    has(c, 7);
    has(c, 9);
    
    return 0;
}