#include <stdio.h>

long long int newbelt[1048580];
void transmission(long long int belt[],int N,int T){
    //mod 64
    int Tmod64 = T % 64;
    int swap = T / 64;
    //int swap = 21;
    // swapping

    for(int i=0;i<=N-1;i++){
        newbelt[i] = belt[(i+swap)%N];
    }

    int pos_neg[1048580];
    for(int t=0;t<Tmod64;t++){
        for(int i=0;i<N;i++){
            if(newbelt[i] >= 0){
                pos_neg[i] = 0;
            }
            else if(newbelt[i] < 0){
                pos_neg[i] = 1;
            }
        }
        for(int i=0;i<N;i++){
            //printf("%lld ",belt[i]);
            newbelt[i] = (newbelt[i] << 1);
            if(i!=N-1){
                if(pos_neg[i+1]==0){
                    //be zero
                    long long int mask = ~((long long int)1);
                    newbelt[i] = newbelt[i] &  mask;
                }
                else if(pos_neg[i+1]==1){
                    long long int mask = 1;
                    newbelt[i] = newbelt[i] | mask;
                }
            }
            else{
                //the last
                if(pos_neg[0]==0){
                    //be zero
                    long long int mask = ~((long long int)1);
                    newbelt[i] = newbelt[i] &  mask;
                }
                else if(pos_neg[0]==1){
                    long long int mask = 1;
                    newbelt[i] = newbelt[i] | mask;
                }
            }
        }
    }
    for(int i=0;i<=N-1;i++){
        belt[i] = newbelt[i];
    }  
    return;
}