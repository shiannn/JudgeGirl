#include "validMoveNum.h"
int nextMove(int r, int c, int n, int visited[100][100]){
    int dy[] = {-2,-1,1,2,2,1,-1,-2};
    int dx[] = {1,2,2,1,-1,-2,-2,-1};
    int toR,toC,min=20,minI=-1;
    for(int i=0;i<8;i++){
        toR = r+dy[i];
        toC = c+dx[i];
        int Num = validMoveNum(toR,toC,n,visited);
        if(Num == -1){
            continue;
        }
        else{
            if(Num < min){
                min = Num;
                minI = i;
            }
        }
    }
    if(minI==-1){
        return -1;
    }
    else{
        return minI;
    }
}