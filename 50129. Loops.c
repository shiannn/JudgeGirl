#include <stdio.h>
#include <stdlib.h>
#define MAXN 1000000

int vis[MAXN] = {0};
void loops(int N, int *A, int *B[], int ans[4]){
    int maxLen = -1, minLen = 10000000, AllMax,AllMin; 
    for(int i=0;i<N;i++){
        if(vis[i]==0){
            int *ptr = B[i];
            int maxInmax = -1, minInmin = 2147483647;
            int Len = 0;
            while(ptr-A != i){
                //printf("%d\n",A[ptr-A]);
                Len++;
                if(A[ptr-A] >= maxInmax)maxInmax = A[ptr-A];
                if(A[ptr-A] <= minInmin)minInmin = A[ptr-A];
                vis[ptr-A] = 1;
                ptr = B[ptr-A];
            }
            //printf("%d\n",A[ptr-A]);
            Len++;
            if(A[ptr-A] >= maxInmax)maxInmax = A[ptr-A];
            if(A[ptr-A] <= minInmin)minInmin = A[ptr-A];
            vis[ptr-A] = 1;
            if(Len > maxLen)AllMax = maxInmax,maxLen = Len;
            else if(Len == maxLen)if(maxInmax > AllMax)AllMax = maxInmax;
            if(Len < minLen)AllMin = minInmin,minLen = Len;
            else if(Len == minLen)if(minInmin < AllMin)AllMin = minInmin;
        }
    }
    ans[0]=maxLen;
    ans[1]=minLen;
    ans[2]=AllMax;
    ans[3]=AllMin;
}
int main(){
    int N;
    int *A = (int *)malloc(sizeof(int) * MAXN);
    int **B = (int **)malloc(sizeof(int *) * MAXN);
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", A + i);
    for(int i = 0, ptr; i < N; i++){
        scanf("%d", &ptr);
        B[i] = A + ptr;
    }
    int ans[4];
    loops(N, A, B, ans);
    for(int i = 0; i < 4; i++)
        printf("%d\n", ans[i]);
    return 0;
}