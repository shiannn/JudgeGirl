#include <stdio.h>

#define maxSide 110
//#define debugInput

int OldState[maxSide][maxSide];
int NewState[maxSide][maxSide];
int Live[maxSide][maxSide];

void print(int State[maxSide][maxSide],int nSide){
    int i,j;
    for(i = 0;i < nSide;i++){
        for(j = 0;j<nSide-1;j++){
            printf("%d ",State[i][j]);
        }
        printf("%d\n",State[i][nSide-1]);
    }
}
int getNew(int Old[][maxSide],int i,int j){
    int m[] = {0,-1,-1,-1,0,1,1,1};
    int n[] = {1,1,0,-1,-1,-1,0,1};
    int idx,sum=0;
    for(idx=0;idx<8;idx++){
        sum += Old[i+m[idx]][j+n[idx]];
    }
    if(Old[i][j] == 1){
        if(sum == 2 || sum == 3){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        if(sum == 3){
            return 1;
        }
        else{
            return 0;
        }
    }
    
}
void transition(int Old[][maxSide],int New[][maxSide],int nSide){
    int i,j;
    for(i=0;i<nSide;i++){
        for(j=0;j<nSide;j++){
            New[i][j] = getNew(Old,i,j);
            if(New[i][j] == 1){
                Live[i][j]++;
            }
        }
    }
}

int main(){
    int nSide,kTimes;
    scanf("%d %d",&nSide,&kTimes);
    int i,j;
    for(i = 0;i < nSide;i++){
        for(j = 0;j<nSide;j++){
            int temp;
            scanf("%d",&temp);
            OldState[i][j] = temp;
            NewState[i][j] = temp;
            Live[i][j] = temp;
        }
    }
    for(i=0;i<kTimes;i++){
        if(i%2==0){
            transition(OldState,NewState,nSide);
        }
        else{
            transition(NewState,OldState,nSide);
        }
    }
    if((i-1)%2==0){
        print(NewState,nSide);
    }
    else{
        print(OldState,nSide);
    }
    int max=0,maxR=-1,maxC=-1;
    for(i=0;i<nSide;i++){
        for(j=0;j<nSide;j++){
            if(Live[i][j]>max){
                maxR=i;
                maxC=j;
                max = Live[i][j];
            }
            else if(Live[i][j] == max){
                if(i > maxR){
                    maxR=i;
                    maxC=j;
                }
                else if(i == maxR){
                    if(j > maxC){
                        maxR=i;
                        maxC=j;
                    }
                }
            }
        }
    }
    //print(Live,nSide);
    printf("%d %d\n",maxR+1,maxC+1);
}

int main1(){
    int nSide,kTimes;
    scanf("%d %d",&nSide,&kTimes);
    int i,j;
    for(i = 0;i < nSide;i++){
        for(j = 0;j<nSide;j++){
            int temp;
            scanf("%d",&temp);
            OldState[i][j] = temp;
            NewState[i][j] = temp;
        }
    }
}