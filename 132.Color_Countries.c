#include <stdio.h>
#include <stdlib.h>
#define max_country 20
int adj_country[max_country][max_country];
int main()
{

    int color[max_country];
    int N,C,P;
    scanf("%d %d %d",&N,&C,&P);
    int i,a,b;
    for(i=0;i<P;i++){
        scanf("%d %d",&a,&b);
        adj_country[a][b]=1;
        adj_country[b][a]=1;
    }
    if(!dfs(0,N,C,color)){
        printf("no solution.\n");
    }

    return 0;
}
int violate(int index,int paint,int N,int color[]){
    int i;
    for(i=0;i<N;i++){
        if(index==i)continue;
        if(adj_country[index][i]==1){
            if(color[i]==paint)return 1;
        }
    }
    return 0;
}
int dfs(int index,int N,int C,int color[]){
    //print2(color,N);
    if(index==N){
        print(color,N);
        return 1;
    }
    int i;
    for(i=1;i<=C;i++){
        if(violate(index,i,N,color)==0){
            color[index]=i;
            if(dfs(index+1,N,C,color)){
                return 1;
            }
        }
    }
    color[index]=0;
    return 0;
}
void print2(int color[],int N){
    int i;
    for(i=0;i<N;i++){
        printf("%d ",color[i]);
    }
    printf("\n");
}

void print(int color[],int N){
    int i;
    for(i=0;i<N;i++){
        printf("%d\n",color[i]);
    }
}
