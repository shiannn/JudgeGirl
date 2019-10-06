#include <stdio.h> 
#define ptrA 0
#define ptrB 1
//#define debug

int getSize(int* a[]){
    int i;
    for(i=0;a[i]!=NULL;i++){

    }
    return (i+1);
}
void merge(int A[], int B[], int* a[], int* b[]){
    int N = getSize(a);
    int M = getSize(b);
    int i = 0;   // index of array A
    int j = 0;  // index of array B
    int ToConnect;
    if(A[0]<B[0]){
        ToConnect = ptrA;
        i++;
    }
    else{
        ToConnect = ptrB;
        j++;
    }
    int a_idx = 0, b_idx = 0; 
    while (i<N && j<M){
        if  (A[i] < B[j]){
            //A[i] is the smallest number of remaining numbers.
            //Connect the pointer you need to do.
            if(ToConnect == ptrA){
                a[a_idx] = &A[i];
                a_idx++;
            }
            else if(ToConnect == ptrB){
                b[b_idx] = &A[i];
                b_idx++;
            }
            ToConnect = ptrA;
            i++;
        }
        else{
            //B[j] is the smallest number of remaining numbers.
            //Connect the pointer you need to do.
            if(ToConnect == ptrA){
                a[a_idx] = &B[j];
                a_idx++;
            }
            else if(ToConnect == ptrB){
                b[b_idx] = &B[j];
                b_idx++;
            }
            ToConnect = ptrB;
            j++;
        }
    }
    if (i==N){
        for (;j<M;j++){
            //complete remaining numbers in B.
            if(ToConnect == ptrA){
                a[a_idx] = &B[j];
                a_idx++;
            }
            else if(ToConnect == ptrB){
                b[b_idx] = &B[j];
                b_idx++;
            }
            ToConnect = ptrB;
        }
    }
    else if  (j==M){
        for (;i<N;i++){
            //complete remaining numbers in A.
            if(ToConnect == ptrA){
                a[a_idx] = &A[i];
                a_idx++;
            }
            else if(ToConnect == ptrB){
                b[b_idx] = &A[i];
                b_idx++;
            }
            ToConnect = ptrA;
        }
    }
    #ifdef debug
    printf("a_idx == %d\n",a_idx);
    for(int ii=0;ii<a_idx;ii++){
        printf("%d ",*(a[ii]));
    }
    printf("\n");
    printf("b_idx == %d\n",b_idx);
    for(int ii=0;ii<b_idx;ii++){
        printf("%d ",*(b[ii]));
    }
    printf("\n");
    #endif   
}
int main()
{
    int A[10], B[10];
    int *a[10], *b[10], *ans_a[10], *ans_b[10];
    int i, N, M;
 
    scanf("%d%d", &N, &M);
    for(i = 0; i < N; i++)
        scanf("%d", &A[i]);
    for(i = 0; i < M; i++)
        scanf("%d", &B[i]);
    for(i = 0; i < N-1; i++)
        a[i] = &A[i+1];
    a[N-1] = NULL;
    for(i = 0; i < M-1; i++)
        b[i] = &B[i+1];
    b[M-1] = NULL;
 
    merge(A, B, a, b);
 
    ans_a[0] = &B[0]; ans_a[1] = &A[2]; ans_a[2] = &B[1]; ans_a[3] = &B[2];
    ans_b[0] = &A[1]; ans_b[1] = &A[3]; ans_b[2] = NULL;
 
    for(i = 0; i < N; i++){
        if(a[i] != ans_a[i])
            printf("a[%d] is Wrong!\n", i);
    }
    for(i = 0; i < M; i++){
        if(b[i] != ans_b[i])
            printf("b[%d] is Wrong!\n", i);
    }
    printf("Finish!\n");
    return 0;
}