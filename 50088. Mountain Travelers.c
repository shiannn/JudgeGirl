#include <stdio.h>

int dr[] = {0,0,1,-1,1,-1,-1,1};
int dc[] = {1,-1,0,0,1,-1,1,-1};
int visA[1024][1024] = {0};
int visB[1024][1024] = {0};
void travel(int map[1024][1024], int N, int M, int A_r, int A_c, int B_r, int B_c, int directionA[], int directionB[]){
    //A uphill B downhill
    visA[A_r][A_c] = 1;
    visB[B_r][B_c] = 1;
    int AstopFlag = 0, BstopFlag = 0,countA=0,countB=0;
    while(AstopFlag ==0 || BstopFlag == 0){
        int maxA = -1,maxAdir=-1,minB = 1,minBdir=-1;
        for(int i=0;i<8;i++){
            if(A_r+dr[i] < N && A_r+dr[i] >= 0 && A_c+dc[i] >= 0 && A_c+dc[i] < M){
                if(map[A_r+dr[i]][A_c+dc[i]] > map[A_r][A_c]){
                    if(map[A_r+dr[i]][A_c+dc[i]] - map[A_r][A_c] > maxA){
                        maxA = map[A_r+dr[i]][A_c+dc[i]] - map[A_r][A_c];
                        maxAdir = i;
                    }
                }    
            }
            if(B_r+dr[i] < N && B_r+dr[i] >= 0 && B_c+dc[i] >= 0 && B_c+dc[i] < M){
                if(map[B_r+dr[i]][B_c+dc[i]] < map[B_r][B_c]){
                    if(map[B_r+dr[i]][B_c+dc[i]] - map[B_r][B_c] < minB){
                        minB = map[B_r+dr[i]][B_c+dc[i]] - map[B_r][B_c];
                        minBdir = i;
                    }
                }
            }
        }
        #ifdef debug
        printf("maxAdir == %d\nminBdir == %d\n",maxAdir,minBdir);
        printf("A %d -> %d\n",map[A_r][A_c],map[A_r+dr[maxAdir]][A_c+dc[maxAdir]]);
        printf("B %d -> %d\n",map[B_r][B_c],map[B_r+dr[minBdir]][B_c+dc[minBdir]]);
        printf("A == (%d, %d) B == (%d, %d)\n",A_r,A_c,B_r,B_c);
        #endif
        if(AstopFlag ==0){
            if(maxAdir == -1){
                AstopFlag = 1;
                directionA[countA++]=-1;
            }
            else{
                directionA[countA++] = maxAdir;
                A_r = A_r+dr[maxAdir];
                A_c = A_c+dc[maxAdir];
                visA[A_r][A_c]=1;
                if(visB[A_r][A_c]==1){
                    AstopFlag = 1;
                    directionA[countA++] = -1;
                }
            }
        }
        if(BstopFlag ==0){
            if(minBdir == -1){
                BstopFlag = 1;
                directionB[countB++]=-1;
            }
            else{
                directionB[countB++] = minBdir;
                B_r = B_r+dr[minBdir];
                B_c = B_c+dc[minBdir];
                visB[B_r][B_c]=1;
                if(visA[B_r][B_c]==1){
                    BstopFlag = 1;
                    directionB[countB++] = -1;
                }
            }
        }
        if(AstopFlag == 0){
            if(visB[A_r][A_c]==1){
                AstopFlag = 1;
                directionA[countA++] = -1;
            }
        }
        #ifdef debug
        printf("A == (%d, %d) B == (%d, %d)\n",A_r,A_c,B_r,B_c);
        printf("-----\n");
        #endif
    }
}
int main(){
    int N, M;
    int map[1024][1024];
    int A_r, A_c, B_r, B_c;
    int directionA[1024], directionB[1024];
 
    scanf("%d%d", &N, &M);
 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
        }
    }
 
    scanf("%d%d%d%d", &A_r, &A_c, &B_r, &B_c);
 
    travel(map, N, M, A_r, A_c, B_r, B_c, directionA, directionB);
 
    int i = 0;
    while (directionA[i] != -1) {
        printf("%d ", directionA[i]);
        i++;
    }
    printf("-1\n");
    i = 0;
    while (directionB[i] != -1) {
        printf("%d ", directionB[i]);
        i++;
    }
    printf("-1\n");
 
    return 0;
}