#include <stdio.h>
#include <stdlib.h>

#define maxKnight 10010
#define maxBoard 110
//#define debugInput

struct Knight{
    int m,n,index;
};
typedef struct Knight Knight;

int dx[] = {100,1,2,2,1,-1,-2,-2,-1};
int dy[] = {100,-2,-1,1,2,2,1,-1,-2};

Knight knightArray[maxKnight];
int knightDead[maxKnight];
int Board[maxBoard][maxBoard];

int isSafe(int m,int n,int NBoard){
    //printf("NBoard==%d\n",NBoard);
    if( (m<0||m>=NBoard) || (n<0||n>=NBoard)){
        return 0;
    }
    if(Board[m][n]!=0){
        return 0;
    }
    return 1;
}
int countPmoves(int m,int n,int NBoard){
    int sum = 0;
    for(int i=1;i<=8;i++){
        if(isSafe(m+dy[i],n+dx[i],NBoard)){
            sum++;
        }
    }
    return sum;
}
int main(){
    int NBoard,MKnight;
    scanf("%d %d",&NBoard,&MKnight);
    for(int i=1;i<=MKnight;i++){
        scanf("%d %d",&knightArray[i].m,&knightArray[i].n);
        knightArray[i].index = i;
        Board[knightArray[i].m][knightArray[i].n] = 10000*i+0;
    }
    #ifdef debugInput
    for(int i=1;i<=MKnight;i++){
        printf("%d %d %d\n",knightArray[i].index,knightArray[i].m,knightArray[i].n);
    }
    #endif
    int Live = MKnight;
    int min,dir;
    int step = 1;
    int temp;
    while(Live>0){
        for(int i=1;i<=MKnight;i++){
            //decide the next move for knight[i] if he is live
            min = 10;
            dir = -1;
            if(knightDead[i]==0){
                for(int j=1;j<=8;j++){
                    if(isSafe(knightArray[i].m + dy[j],knightArray[i].n + dx[j],NBoard)){
                        //count p moves for m' n'
                        temp = countPmoves(knightArray[i].m + dy[j],knightArray[i].n + dx[j],NBoard);
                        //printf("knight==%d m==%d n==%d pmoves==%d\n",\
                        i,knightArray[i].m + dy[j],knightArray[i].n + dx[j],temp);
                        if(temp < min){
                            min = temp;
                            dir = j;
                        }
                    }
                }
                //move
                if(dir == -1){
                    knightDead[i]=1;
                    Live--;
                }
                else{
                    knightArray[i].m += dy[dir];
                    knightArray[i].n += dx[dir];
                    //update Board
                    Board[knightArray[i].m][knightArray[i].n] = 10000*i+step;
                }
            }
        }
        step++;
    }
    for(int i=0;i<NBoard;i++){
        for(int j=0;j<NBoard;j++){
            if(j!=0)printf(" ");
            printf("%d",Board[i][j]);
        }
        printf("\n");
    }
}