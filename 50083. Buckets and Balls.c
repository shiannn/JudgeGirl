#include <stdio.h>
#include <stdlib.h>

int main(){
    int NLimitA,MLimitB,Roperation;
    int WeightBall;
    scanf("%d %d %d",&NLimitA,&MLimitB,&Roperation);
    if(Roperation == 0){
        //first fit
        while(scanf("%d",&WeightBall)!=EOF){
            if(WeightBall<=NLimitA){
                NLimitA -= WeightBall;
            }
            else if(WeightBall <= MLimitB){
                MLimitB -= WeightBall;
            }
            printf("%d %d\n",NLimitA,MLimitB);
        }
    }
    else{
        //best fit
        while(scanf("%d",&WeightBall)!=EOF){
            //printf("weightball==%d A==%d B==%d",WeightBall,NLimitA,MLimitB);
            if(WeightBall>NLimitA && WeightBall>MLimitB){
                printf("%d %d\n",NLimitA,MLimitB);
                continue;
            }
            else if(WeightBall<=NLimitA && WeightBall>MLimitB){
                NLimitA -= WeightBall;
            }
            else if(WeightBall>NLimitA && WeightBall<=MLimitB){
                MLimitB -= WeightBall;
            }
            else if(WeightBall<=NLimitA && WeightBall<=MLimitB){
                if(MLimitB<NLimitA){
                    MLimitB -= WeightBall;
                }
                else{
                    NLimitA -= WeightBall;
                }
            }
            printf("%d %d\n",NLimitA,MLimitB);
        }
    }
    return 0;
}