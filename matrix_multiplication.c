#include <stdio.h>

int A[1010][1010];
int B[1010][1010];
int AdoneRow[30010];

void matrix_multiplication(int N, int** ptrA, int M, int** ptrB, int S, int *result){
    //先重建A
    //ptr[0] 元素 ptr[1] row ptr[2] col
    for(int i=0;i<N;i++){
        int element = ptrA[0][i];
        int row = ptrA[1][i];
        int col = ptrA[2][i];
        A[row][col] = element;
    }
#ifdef debug
    for(int i=0;i<S;i++){
        for(int j=0;j<S;j++){
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
#endif
    //重建B
    for(int i=0;i<M;i++){
        int element = ptrB[0][i];
        int row = ptrB[1][i];
        int col = ptrB[2][i];
        B[row][col] = element;
    }
#ifdef debug
    for(int i=0;i<S;i++){
        for(int j=0;j<S;j++){
            printf("%d ",B[i][j]);
        }
        printf("\n");
    }
#endif
    /*
    //相乘
    for(int i=0;i<S;i++){
        for(int j=0;j<S;j++){
            int sum=0;
            for(int p = 0;p<S;p++){
                sum += A[i][p] * B[p][j];
            }
            result[i*S+j] = sum;
            //printf("%d ",result[i*S+j]);
        }
    }
    */
    //稀疏矩陣可以加速
    //A裏面的第i個的col如果和B裏面的第j個的row有一樣的值
    //兩個人就可以相成並且加諸在result中
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            int elementA = ptrA[0][i];
            int rowA = ptrA[1][i];
            int colA = ptrA[2][i];
            int elementB = ptrB[0][j];
            int rowB = ptrB[1][j];
            int colB = ptrB[2][j];
            if(colA == rowB){
                //可以乘
                int mul = elementA*elementB;
                //結果會放在 rowA colB
                result[rowA*S + colB] += mul;
            }
        }
    }
    return;
}