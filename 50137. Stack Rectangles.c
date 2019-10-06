#include <stdio.h>

typedef struct{
    int width,length,index;
}rectangle;

rectangle recArray[300];

int maxNum = 0;
int maxSumIndex = 0;

void dfs(int idx, int N, int prev, int sumIndex){
    //printf("idx == %d sumIndex == %d ",idx,sumIndex); 
    if(idx > maxNum){
        maxNum = idx;
        maxSumIndex = sumIndex;
    }
    else if(idx == maxNum){
        if(sumIndex > maxSumIndex){
            maxSumIndex = sumIndex;
        }
    }
    //printf("maxNum == %d maxSumIndex == %d\n",maxNum,maxSumIndex);
    for(int i=prev+1;i<N;i++){
        if(recArray[i].width<=recArray[prev].width && recArray[i].length<=recArray[prev].length\
        ||recArray[i].width<=recArray[prev].length && recArray[i].length<=recArray[prev].width){
            dfs(idx+1, N, i, sumIndex+i);
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d%d",&recArray[i].width,&recArray[i].length),recArray[i].index = i;
    for(int i=0;i<n;i++)dfs(1,n,i,i);
    printf("%d %d\n",maxNum,maxSumIndex);
}