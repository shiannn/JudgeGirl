#include <stdio.h>
#include <string.h>
#define DEAD 0
#define DYING 1
#define HEALTHY 2

int dy[]={0,1,1,1,0,-1,-1,-1};
int dx[]={1,1,0,-1,-1,-1,0,1};
int TransTable[3][9]={
    {0,0,0,2,0,0,0,0,0},
    {1,1,2,1,1,1,1,1,1},
    {0,0,2,2,1,1,1,1,1}
};
void game_of_cell(int grid[50][50],int outcome[50][50],int N){
    while(N>0){
        int temp[50][50]={0};
        for(int i=0;i<50;i++){
            for(int j=0;j<50;j++){
                int healthy=0;
                for(int k=0;k<8;k++){
                    int M=i+dy[k], N=j+dx[k];
                    if(!(M<50&&M>=0&&N<50&&N>=0))continue;
                    healthy += grid[M][N]/2;
                }
                temp[i][j] = TransTable[grid[i][j]][healthy];
            }
        }
        //copy to outcome
        memcpy(grid,temp,50*sizeof(temp[0]));
        N -= 1;
    }
    memcpy(outcome,grid,50*sizeof(grid[0]));
}
int main()
{
    int grid[50][50]={0},outcome[50][50]={0},N;
    scanf("%d",&N);
    for(int i=0;i<50;i++)
        for(int j=0;j<50;j++)
            scanf("%d",&grid[i][j]);
    game_of_cell(grid,outcome,N);
    for(int i=0;i<50;i++)
        for(int j=0;j<50;j++)
            printf("%d%c",outcome[i][j]," \n"[j==49]);
    return 0;
}