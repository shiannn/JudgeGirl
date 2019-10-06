#include <stdio.h>
#include "nextMove.h"

int visited[100][100];
int map[110][110];
int Step[10010];
int knightR[10010];
int knightC[10010];
int StopKnights[10010];

void printMap(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j!=0)printf(" ");
            printf("%d",map[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int dy[] = {-2,-1,1,2,2,1,-1,-2};
    int dx[] = {1,2,2,1,-1,-2,-2,-1};
    int n,m,stop=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&knightR[i],&knightC[i]);
        map[knightR[i]][knightC[i]] = 10000*i + Step[i];
        visited[knightR[i]][knightC[i]] = 1;
    }
    while(stop<m){
        for(int i=1;i<=m;i++){
            if(StopKnights[i]==1)continue;
            int next = nextMove(knightR[i], knightC[i], n, visited);
            //已經不動的knight會重複加到stop
            if(next == -1){
                stop += 1;
                StopKnights[i] = 1;
                continue;
            }
            else{
                knightR[i] += dy[next];
                knightC[i] += dx[next];
                Step[i] += 1;
                map[knightR[i]][knightC[i]] = 10000*i + Step[i];
                visited[knightR[i]][knightC[i]] = 1;
            }
        }
    }
    printMap(n);
}