#include <stdio.h>
 
int graph[20][20];
int current = 0,TotalMin = 2000;
int vis[20] = {0};
int visited = 1;
void dfs(int st,int N){
    if(current >= TotalMin){
        return;
    }
    if(visited == N){
        if((current + graph[st][0]) < TotalMin){
            TotalMin = current + graph[st][0];
        }
    }
    else{
        for(int i=1;i<N;i++){
            if(i == st){
                continue;
            }
            else{
                if(vis[i] == 0){
                    vis[i] = 1;
                    visited += 1;
                    current += graph[st][i];
                    dfs(i,N);
                    visited -= 1;
                    current -= graph[st][i];
                    vis[i] = 0;
                }
            }
        }
    }
}
int main(){
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&graph[i][j]);
        }
    }
#ifdef debug
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
#endif
    dfs(0,N);
    printf("%d\n",TotalMin);
}