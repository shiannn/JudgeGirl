#include <stdio.h>
#include <stdlib.h>
#define max_NM 410
#define max_lake 160010

int lake[max_lake];
int island[max_NM][max_NM];
int main()
{
    int N,M;
    scanf("%d %d",&N,&M);
    int i,j;
    for(i=1;i<=N;i++){
        for(j=1;j<=M;j++){
            scanf("%d",&island[i][j]);
        }
    }
    int L=0;
    for(i=1;i<=N;i++){
        for(j=1;j<=M;j++){
            if(island[i][j]==1){
                lake[L]=dfs(i,j,N,M);
                L++;
            }
        }
    }
    print(lake,L);
    return 0;
}
void sort(int lake[],int L){
    int i,j;
    for(i=L-1;i>=1;i--){
        for(j=0;j<=i-1;j++){
            if(lake[j]<lake[j+1]){
                int temp=lake[j];
                lake[j]=lake[j+1];
                lake[j+1]=temp;
            }
        }
    }
}
int compare(const void *a, const void *b)//這函式是 qsort 所需的比較函式
{
      int c = *(int *)a;
      int d = *(int *)b;
      if(c > d) {return -1;}               //傳回 -1 代表 a < b
      else if (c == d) {return 0;}      //傳回   0 代表 a = b
      else return 1;                          //傳回  1 代表 a>b
}
void print(int lake[],int L){
    int i;
    //printf("%d\n",L);
    //sort(lake,L);
    qsort(lake,L,sizeof(int),compare);
    for(i=0;i<L;i++){
        printf("%d\n",lake[i]);
    }
}
int dfs(int i,int j,int N,int M){
    if(i>N||i<1||j>M||j<1)return 0;
    if(island[i][j]==0){
        return 0;
    }
    else{
        island[i][j]=0;
        return (1+dfs(i+1,j,N,M)+\
            dfs(i-1,j,N,M)+\
            dfs(i,j+1,N,M)+\
            dfs(i,j-1,N,M));
    }
}
