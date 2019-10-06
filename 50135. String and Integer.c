#include <stdio.h>
#include <string.h>

long long int NumArray[13000];
char InputString[100010];
int main(){
    int Task;
    scanf("%d",&Task);
    int arraySize;
    if(Task == 0){//string to integerArray
        scanf("%s",InputString);
        int N = strlen(InputString);
        N+=1;
        while(N%8!=0)N++;
        for(int i=0;i<N;i+=8){
            //each charGroup in string
            long long int TodoNumber=0;
            for(int j=0;j<8;j++){
                //each char ci ci+1 ci+2 ... ci+7
                TodoNumber |= InputString[i+j];
                if(j!=7)TodoNumber <<= 8;
            }
            printf("%lld\n",TodoNumber);
        }
    }
    else if(Task == 1){//integerArray to string  
        scanf("%d",&arraySize);
        for(int i=0;i<arraySize;i++){
            scanf("%lld",&NumArray[i]);
        }
        const char unsigned Mymask = 255;
        for(int i=0;i<arraySize;i++){
            char OutputString[10]={0};
            long long int ToDo = NumArray[i];
            for(int j=7;j>=0;j--){
                OutputString[7-j] = Mymask & (ToDo >> 8*j);
            }
            printf("%s",OutputString);
        }
        printf("\n");
    }
}