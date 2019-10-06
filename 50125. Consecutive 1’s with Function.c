#include <stdio.h>
#define MAXN 256

int main(){
    int array[MAXN][MAXN];
    int N, r, c;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &array[i][j]);
    int temp,max=0;
    //all on first row
    for(int i=0;i<N;i++){
        temp = findLength(array, N, 0, i, 1, 0);
        if(temp>max)max=temp;
    }
    //all on first column
    for(int i=0;i<N;i++){
        temp = findLength(array, N, i, 0, 0, 1);
        if(temp>max)max=temp;
    }
    //all on first row+column
    for(int i=0;i<N;i++){
        temp = findLength(array, N, i, 0, 1, 1);
        if(temp>max)max=temp;
    }
    for(int i=0;i<N;i++){
        temp = findLength(array, N, 0, i, 1, 1);
        if(temp>max)max=temp;
    }
    //all on first row last column
    for(int i=0;i<N;i++){
        temp = findLength(array, N, 0, i, 1, -1);
        if(temp>max)max=temp;
    }
    for(int i=0;i<N;i++){
        temp = findLength(array, N, i, N-1, 1, -1);
        if(temp>max)max=temp;
    }
    printf("%d\n",max);
}