#include <stdio.h>
#include <stdlib.h>

int seesaw[2500];
void print(int N){
    printf("seesaw==");
    for(int i=0;i<N;i++){
        printf(" %d",seesaw[i]);
    }
    printf("\n");
}
int main(){
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&seesaw[i]);
    }

    int balance = -1;
    int swap = 0;
    while(balance == -1){
        //print(N);
        for(int i=0;i<N;i++){
            int torque = 0;
            for(int j=0;j<N;j++){
                if(j<i){
                    torque += seesaw[j]*abs(i-j);
                }
                else if(j>i){
                    torque -= seesaw[j]*abs(i-j);
                }
                else{
                    torque += 0;
                }
            }
            if(torque == 0){
                balance = 1;
                for(int j=0;j<N;j++){
                    if(j!=0)printf(" ");
                    if(j==i){
                        printf("v");
                    }
                    else{
                        printf("%d",seesaw[j]);
                    }
                }
                break;
            }
        }
        //printf("swap==%d\n",swap);
        int temp = seesaw[swap];
        seesaw[swap] = seesaw[N-1-swap];
        seesaw[N-1-swap] = temp;
        swap += 1;
    }
}