#include <stdio.h>

#define MAXN 110
#define MAXKnight 10020

struct knight{
    int m,n;
};
typedef struct knight knight;

int dy[]={-2,-1,1,2,2,1,-1,-2};
int dx[]={1,2,2,1,-1,-2,-2,-1};
int visited[MAXN][MAXN]={0};
int move[8][2] = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};

int validMoveNum(int r, int c, int n, int visited[MAXN][MAXN]){
    if(!(visited[r][c] == 0 && (0 <= r && r < n) && (0 <= c && c < n))){
        return -1;
    }
    int sum = 0;
    for(int i=0;i<8;i++){
        int M = r+dy[i];
        int N = c+dx[i];
        if(visited[M][N] == 0 && (0 <= M && M < n) && (0 <= N && N < n) ){
             sum++;
        }
    }
    return sum;
}
int nextMove(int r, int c, int n, int visited[MAXN][MAXN]){
    int min = 10;
    int next = -1;
    for(int i=0;i<8;i++){
        int M = r+dy[i];
        int N = c+dx[i];
        int num = validMoveNum(M,N,n,visited);
        if(num == -1){
            continue;
        }
        else if(num < min){
             min = num;
             next = i;
        }
    }
    return next;
}
knight knightArray[MAXKnight];
int Board[MAXN][MAXN];
int main(){
    int n, m, r, c;
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=1; i<=m; i++){
        int a,b;
        scanf("%d%d",&a,&b);
        knightArray[i].m=a;
        knightArray[i].n=b;
        visited[a][b] = 1;
        Board[a][b] = (10000*i+0);
    }
    int Live = m;
    int Step = 1;
    while(Live > 0){
        for(int i=1;i<=m;i++){
            int next = nextMove(knightArray[i].m,knightArray[i].n,n,visited);
            if(next == -1 || next == 0){
                Live--;
            }
            else{
                knightArray[i].m += dy[next];
                knightArray[i].n += dx[next];
                Board[knightArray[i].m][knightArray[i].n] = (10000*i+Step);
            }
        }
        Step++;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j!=0)printf(" ");
            printf("%d",Board[i][j]);
        }
        printf("\n");
    }
}