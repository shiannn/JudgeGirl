#include <stdio.h>

int main(){
    int N;
    while(scanf("%d",&N)!=EOF){
        int i,max = -10001, min = 10001;
        for(i=0;i<N;i++){
            int temp;
            if(scanf("%d",&temp)==EOF)break;
            if(temp < min)min = temp;
            if(temp > max)max = temp;
        }
        if(i<N){
            //minimum
            printf("%d\n",min);
        }
        else{
            //maximum
            printf("%d\n",max);
        }
    }
}