#include <stdio.h>

#define MAXN 1024
//#define debug
int A[MAXN][MAXN];
const int *B[MAXN][MAXN];
//record the position of 0~(N-1) in A
int position[MAXN*MAXN] = {0};

//2D array當成函式參數只有第一維度可以不管
//其餘每一個維度都必須相同
//不同的數字幾乎可以視為不同的type
//int array[20][10]
void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N){
    for(int i=0; i<N;i++){
        for(int j=0;j<N;j++){
            position[A[i][j]] = i*N + j;
        }
    }
    for(int i=0; i<N;i++){
        for(int j=0;j<N;j++){
            int pos1 = (A[i][j]+1 >= N*N)? position[0]:position[A[i][j]+1];
            int pos2n = pos1 % N;
            int pos2m = pos1 / N;
            B[i][j] = &A[pos2m][pos2n]; 
        }
    }
}
int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    constructPointerArray(A, B, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d%c", *B[i][j], j == N - 1 ? '\n' : ' ');
        }
    }
    return 0;
}